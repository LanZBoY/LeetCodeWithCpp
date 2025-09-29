#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
#include <vector>

using namespace std;

struct GraphNode
{
    int value;
    GraphNode *left;
    GraphNode *right;
    GraphNode() : value(0), left(nullptr), right(nullptr) {};
    GraphNode(int data) : value(data), left(nullptr), right(nullptr) {};
    GraphNode(int data, GraphNode *left, GraphNode *right) : value(data), left(left), right(right) {};
};

GraphNode *insertNode(GraphNode *root, queue<GraphNode *> &q, int value)
{
    GraphNode *node = nullptr;
    if (value)
    {
        node = new GraphNode(value);
    }
    if (root == nullptr)
        root = node;
    else if (q.front()->left == nullptr)
        q.front()->left = node;
    else
    {
        q.front()->right = node;
        q.pop();
    }
    if (node)
    {
        q.push(node);
    }
    return root;
}

GraphNode *vector2tree(vector<int> datas)
{
    GraphNode *root = nullptr;
    queue<GraphNode *> q;
    for (int i = 0; i < datas.size(); i++)
    {
        root = insertNode(root, q, datas[i]);
    }
    return root;
}

vector<int> getLevelOrderVector(GraphNode *root)
{
    vector<int> reuslt;
    if (root == nullptr)
        return reuslt;
    queue<GraphNode *> q;
    q.push(root);
    while (!q.empty())
    {
        if (q.front()->left != nullptr)
            q.push(q.front()->left);
        if (q.front()->right != nullptr)
            q.push(q.front()->right);

        reuslt.push_back(q.front()->value);

        q.pop();
    }
    return reuslt;
}

vector<int> getPreOrderVector(GraphNode *root)
{
    /*
        父節點再拜訪左右子節點
    */
    vector<int> reuslt;
    if (root == nullptr)
        return reuslt;
    stack<GraphNode *> s;
    s.push(root);
    while (!s.empty())
    {
        GraphNode *node = s.top();
        s.pop();
        reuslt.push_back(node->value);
        if (node->right)
            s.push(node->right);
        if (node->left)
            s.push(node->left);
    }
    return reuslt;
}

vector<int> getInOrderVector(GraphNode *root)
{
    /*
        會先拜訪左子節點，再拜訪父節點，最後拜訪右子節點(左、中、右)
    */
    vector<int> reuslt;
    if (root == nullptr)
        return reuslt;
    stack<GraphNode *> s;
    GraphNode *current = root;
    while (current || !s.empty())
    {
        if (current == nullptr)
        {
            current = s.top();
            reuslt.push_back(current->value);
            s.pop();
            if (current->right)
            {
                current = current->right;
            }
            else
            {
                current = nullptr;
            }
        }
        else
        {
            s.push(current);
            current = current->left;
        }
    }
    return reuslt;
}

int kthSmallest(GraphNode *root, int k)
{
    GraphNode *current = root;
    stack<GraphNode *> s;
    do
    {
        if (!current)
        {
            current = s.top();
            s.pop();
            k--;
            if (!k)
            {
                return current->value;
            }
            current = current->right;
            continue;
        }
        s.push(current);
        current = current->left;
    } while ((current || !s.empty()) && k);
    return 0;
}

vector<int> getPostOrderVector(GraphNode *root)
{
    /*
        需先拜訪左右子節點，最後拜訪父節點 (左、右、中)
        作法先將父、右、左依序放入Stack中並設定父節點的左右節點指標為nullptr
        當pop出的節點如果沒有左右兩個節點，代表左右節點已經拜訪過的所以可以拜訪父節點
    */
    vector<int> res;
    if (root == nullptr)
        return res;
    stack<GraphNode *> s;
    GraphNode *current;
    s.push(root);
    while (!s.empty())
    {
        current = s.top();
        if (!(current->left && current->right))
        {
            res.push_back(current->value);
            s.pop();
        }
        if (current->right)
        {
            s.push(current->right);
            current->right = nullptr;
        }
        if (current->left)
        {
            s.push(current->left);
            current->left = nullptr;
        }
    }
    return res;
}

int getIndex(vector<int> vec, int value)
{
    auto it = find(vec.begin(), vec.end(), value);
    if (it != vec.end())
    {
        return it - vec.begin();
    }
    return -1;
}

GraphNode *buildTree(vector<int> &preorder, vector<int> inorder)
{
    static int preIndex = 0;
    GraphNode *node = new GraphNode(preorder[preIndex++]);
    if (inorder.size() == 1)
    {
        return node;
    }
    int inIndex = getIndex(inorder, node->value);

    node->left = buildTree(preorder, vector<int>(inorder.begin(), inorder.begin() + inIndex));

    node->right = buildTree(preorder, vector<int>(inorder.begin() + inIndex + 1, inorder.end()));

    return node;
}

GraphNode *buildTree_O_1(vector<int> &preorder, vector<int> &inorder)
{
    GraphNode *root = nullptr;
    stack<GraphNode *> node_stack;
    set<GraphNode *> node_set;
    for (int pre = 0, in = 0; pre < preorder.size();)
    {
        GraphNode *current = nullptr;
        do
        {
            current = new GraphNode(preorder[pre]);
            if (root == nullptr)
            {
                root = current;
            }
            if (!node_stack.empty())
            {
                if (node_set.find(node_stack.top()) == node_set.end())
                {
                    node_stack.top()->left = current;
                }
                else
                {
                    node_set.erase(node_stack.top());
                    node_stack.top()->right = current;
                    node_stack.pop();
                }
            }
            node_stack.push(current);
        } while (preorder[pre++] != inorder[in]);

        current == nullptr;
        while (!node_stack.empty() && node_stack.top()->value == inorder[in])
        {
            current = node_stack.top();
            node_stack.pop();
            in++;
        }

        if (current != nullptr)
        {
            node_set.insert(current);
            node_stack.push(current);
        }
    }
    return root;
}

void printVector(vector<int> vec)
{
    cout << '[';

    for (int i = 0; i < vec.size() - 1; i++)
    {
        cout << vec[i] << ", ";
    }
    cout << vec[vec.size() - 1] << ']' << endl;
}

int main()
{
    // vector<int> datas = {3,1,4,NULL,2};
    // int index = getIndex(datas, 1);
    // Node* root = vector2tree(datas);
    int index = kthSmallest(new GraphNode(3, new GraphNode(1, nullptr, new GraphNode(2)), new GraphNode(4)), 1);
    index = kthSmallest(new GraphNode(5, new GraphNode(3, new GraphNode(2, new GraphNode(1, nullptr, nullptr), nullptr), new GraphNode(4)), new GraphNode(6)), 6);
    // vector<int> preorder = getPreOrderVector(root);
    // vector<int> inorder = getInOrderVector(root);
    // printVector(preorder);
    // printVector(inorder);
    return 0;
}