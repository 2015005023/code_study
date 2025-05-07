#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include<climits>
#include <algorithm>
#include <functional> 
using namespace std;



void postOrder(vector<int>& preOrder , int& index, int bound){

    if(index >= preOrder.size() || preOrder[index]> bound) return;

    int root = preOrder[index++];

    postOrder(preOrder, index,  root);
    postOrder(preOrder,index, bound);

    cout << root << '\n';

}

int main(){
    int val;

    vector<int> preOrder;
    while (cin >> val)
    {
        preOrder.push_back(val);
    }

    int index = 0;
    postOrder(preOrder,index, INT_MAX);

    return 0;
    
    
    
}
