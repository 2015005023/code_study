#include <iostream>
#include <queue>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n ;
    cin >> n;

    priority_queue<int , vector<int> , greater<int>> minHeap;
    priority_queue<int> maxHeap;

    for(int i = 0 ; i< n ; i++){
        int num;
        cin >> num;
/*
        if(maxHeap.empty() || num <= maxHeap.top()){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }

        if(maxHeap.size() > minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if( minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        cout << maxHeap.top() <<"\n";*/

        if(maxHeap.size() == minHeap.size()){
            maxHeap.push(num);
        }
        else if( maxHeap.size() == minHeap.size()+1){
            minHeap.push(num);
        }

        if(!maxHeap.empty() && !minHeap.empty() &&  maxHeap.top()  >=minHeap.top()){

            int tmpMax = maxHeap.top();
            int tmpMin = minHeap.top();

            maxHeap.pop();
            minHeap.pop();
            minHeap.push(tmpMax);
            maxHeap.push(tmpMin);
        }

        cout << maxHeap.top() << "\n";
    }
    return 0;

} 