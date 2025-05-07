#include <iostream>
#include <unordered_map>
using namespace std;


unordered_map<char ,pair<char ,char>> tree;

void preOrder(char node){
    if(node =='.') return;

    cout << node;
    preOrder(tree[node].first);
    preOrder(tree[node].second);

}


void inOrder(char node){
    if(node =='.') return;
    inOrder(tree[node].first);
    cout << node;
    inOrder(tree[node].second);
    
}


void postOrder(char node){
    if(node =='.') return;

    postOrder(tree[node].first);
    postOrder(tree[node].second);
    cout << node;



    
}

int main(){

    int n;
    cin >> n;

    for(int i = 0 ; i< n ; i++){
        char node, left ,right;

        cin >> node >> left >>right ;
        tree[node].first = left;
        tree[node].second = right; 
    }

    preOrder('A');
    cout << '\n';
    inOrder('A');
    cout << '\n';
    postOrder('A');
    cout << '\n';


    return 0;



} 