#include<iostream>

using namespace std;


struct node{
    int value;
    node* next = nullptr;
};

void addNode(node* root, int num){
    if (root == nullptr){
        root = new node;
        root->value = num;
    }else{
        node* current = root;
        while (current->next != nullptr){
            current = current->next;
        }
        current->next = new node;
        current = current -> next;
        current->value = num;
    }
}

void printNode(node* root){
    node* current = root;
    while (current != nullptr){
        cout << current->value << endl;
        current = current->next;
    }
}

int main(){
    node* root = new node;
    root->value = 0;
    addNode(root, 1);
    addNode(root, 2);
    printNode(root);
}
