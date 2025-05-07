#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include<climits>
#include <algorithm>
#include <functional> 
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v) , left(nullptr), right(nullptr){}
};

void postOrder(Node* root){
    if(!root) return;

    postOrder(root->left);
    postOrder(root->right);

    cout << root->val << '\n';

}

Node* insert(Node* root , int val){
    if(!root) return new Node(val);
    if(val <root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);

    return root;
}

int main(){

    vector<int> preNode;
    int val;

    while (cin >> val)
    {
        preNode.push_back(val);
    }

    Node* root = nullptr;
    for( int num : preNode){
        
        root = insert(root, num);
    }

    postOrder(root);

    return 0;
    
}
