#include <iostream>
#include <deque>
#include <set>
#include <vector>
#include <queue>
#include <functional> 

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin >> n;

    int count = n;

    priority_queue<int> pq;

    while (count--)
    {
        int input;
        cin >> input;

        if(input == 0){
            if(pq.empty()){
                cout << "0\n";
            }
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }

        pq.push(input);
    }
    

}