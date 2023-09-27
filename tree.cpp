#include<iostream>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<vector>

using namespace std;

struct Node
{
    int value;
    Node* left;
    Node* right;
    Node(): value(0), left(nullptr), right(nullptr){};
    Node(int data): value(data), left(nullptr), right(nullptr){};
    Node(int data, Node* left, Node* right): value(data), left(left), right(right){};
};

Node* insertNode(Node* root, queue<Node*> &q, int value){
    Node* node = nullptr;
    if(value){
        node = new Node(value);
    }
    if(root == nullptr) root = node;
    else if(q.front() -> left == nullptr) q.front() -> left = node;
    else {
        q.front() -> right = node;
        q.pop();
    }
    if(node){
        q.push(node);
    }
    return root;
}

Node* vector2tree(vector<int> datas){
    Node* root = nullptr;
    queue<Node*> q;
    for(int i = 0; i < datas.size(); i++){
        root = insertNode(root, q, datas[i]);
    }
    return root;
}

vector<int> getLevelOrderVector(Node* root){
    vector<int> reuslt;
    if(root == nullptr) return reuslt;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        if(q.front() -> left != nullptr) q.push(q.front() -> left);
        if(q.front() -> right != nullptr) q.push(q.front() -> right);
        
        reuslt.push_back(q.front() -> value);
        
        q.pop();
    }
    return reuslt;
}

vector<int> getPreOrderVector(Node* root){
    /*
        父節點再拜訪左右子節點
    */
    vector<int> reuslt;
    if(root == nullptr) return reuslt;
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* node = s.top();
        s.pop();
        reuslt.push_back(node -> value);
        if(node -> right) s.push(node -> right);
        if(node -> left) s.push(node -> left);
    }
    return reuslt;
}

vector<int> getInOrderVector(Node* root){
    /*
        會先拜訪左子節點，再拜訪父節點，最後拜訪右子節點(左、中、右)
    */
    vector<int> reuslt;
    if(root == nullptr) return reuslt;
    stack<Node*> s;
    Node* current = root;
    while(current || !s.empty()){
        if(current == nullptr){
            current = s.top();
            reuslt.push_back(current -> value);
            s.pop();
            if(current -> right){
                current = current -> right;
            }else{
                current = nullptr;
            }
        }else{
            s.push(current);
            current = current -> left;
        }
    }
    return reuslt;
}

int kthSmallest(Node* root, int k){
    Node* current = root;
    stack<Node*> s;
    do{
        if(!current){
            current = s.top();
            s.pop();
            k--;
            if(!k){
                return current -> value;
            }
            current = current -> right;
            continue;
        }
        s.push(current);
        current = current -> left;
    }while((current || !s.empty()) && k);
    return 0;
}

vector<int> getPostOrderVector(Node* root){
    /*
        需先拜訪左右子節點，最後拜訪父節點 (左、右、中)
        作法先將父、右、左依序放入Stack中並設定父節點的左右節點指標為nullptr
        當pop出的節點如果沒有左右兩個節點，代表左右節點已經拜訪過的所以可以拜訪父節點
    */
    vector<int> res;
    if(root == nullptr) return res;
    stack<Node*> s;
    Node* current;
    s.push(root);
    while(!s.empty()){
        current = s.top();
        if(!(current -> left && current -> right)){
            res.push_back(current -> value);
            s.pop();

        }
        if(current -> right){
            s.push(current -> right);
            current -> right = nullptr;
        }
        if(current -> left){
            s.push(current -> left);
            current -> left = nullptr;
        }
    }
    return res;
}

int getIndex(vector<int> vec, int value){
    auto it = find(vec.begin(), vec.end(), value);
    if(it != vec.end()){
        return it - vec.begin();
    }
    return -1;
}

Node* buildTree(vector<int> &preorder, vector<int> inorder){
    static int preIndex = 0;
    Node* node = new Node(preorder[preIndex++]);
    if(inorder.size() == 1){
        return node;
    }
    int inIndex = getIndex(inorder, node -> value);

    node -> left = buildTree(preorder, vector<int>(inorder.begin(), inorder.begin() + inIndex));

    node -> right = buildTree(preorder, vector<int>(inorder.begin() + inIndex + 1, inorder.end()));

    return node;
}

Node* buildTree_O_1(vector<int> &preorder, vector<int> &inorder){
    Node* root = nullptr;
    stack<Node*> node_stack;
    set<Node*> node_set;
    for(int pre = 0, in = 0; pre < preorder.size();){
        Node* current = nullptr;
        do{
            current = new Node(preorder[pre]);
            if(root == nullptr){
                root = current;
            }
            if(!node_stack.empty()){
                if(node_set.find(node_stack.top()) == node_set.end()){
                    node_stack.top() -> left = current;
                }else{
                    node_set.erase(node_stack.top());
                    node_stack.top() -> right = current;
                    node_stack.pop();
                }
            }
            node_stack.push(current);
        }while(preorder[pre++] != inorder[in]);

        current == nullptr;
        while(!node_stack.empty() && node_stack.top() -> value == inorder[in]){
            current = node_stack.top();
            node_stack.pop();
            in++;
        }

        if(current != nullptr){
            node_set.insert(current);
            node_stack.push(current);
        }
    }
    return root;
}

void printVector(vector<int> vec){
    cout << '[';

    for(int i = 0; i < vec.size() - 1; i++){
        cout << vec[i] << ", ";

    }
    cout << vec[vec.size() - 1] << ']' << endl;
}

int main(){
    // vector<int> datas = {3,1,4,NULL,2};
    // int index = getIndex(datas, 1);
    // Node* root = vector2tree(datas);
    int index = kthSmallest(new Node(3, new Node(1, nullptr, new Node(2)), new Node(4)), 1);
    index = kthSmallest(new Node(5, new Node(3, new Node(2, new Node(1, nullptr, nullptr), nullptr), new Node(4)), new Node(6)), 6);
    // vector<int> preorder = getPreOrderVector(root);
    // vector<int> inorder = getInOrderVector(root);
    // printVector(preorder);
    // printVector(inorder);
    return 0;
}