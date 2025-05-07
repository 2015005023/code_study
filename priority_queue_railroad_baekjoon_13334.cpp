#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> segement;

    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int a,b;
        cin >> a >> b;

        if(a>b) swap(a,b);
    segement.emplace_back(a,b);
    }

    sort(segement.begin() , segement.end() ,[](const pair<int , int > & a, const pair<int ,int> & b){
        return a.second < b.second;
    });

    int d;
    cin >> d;

    priority_queue<int, vector<int>, greater<int>> pq;
    int result = 0;

    for(const auto& p : segement){
        int start = p.first;
        int end = p.second;

        while (!pq.empty() && pq.top() < end-d)
        {
            pq.pop();
        }

        if(start >= end-d){
            pq.push(start);
        }

        result = max(result , (int)pq.size());
        
    }

    cout << result << "\n";

    return 0;
    

} 