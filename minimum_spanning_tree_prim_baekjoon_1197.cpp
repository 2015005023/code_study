#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include<climits>
#include <algorithm>
#include <functional> 
using namespace std;

vector<pair<int,int>> graph[100001];

bool visited[10001];

int prim(int start){
    priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>>> pq;
    pq.push({0,start});

    int result = 0;

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int curr = pq.top().second;

        pq.pop();
        if(visited[curr]) continue;

        visited[curr] =true;
        result += weight;

        for(auto& next : graph[curr]){

            int nextWeigth = next.first;
            int nextvertx = next.second;

            if(!visited[nextvertx]){
                pq.push({nextWeigth,nextvertx});
            }
        }
    }
    

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int v,e;

    cin >> v >> e;


    for(int i = 0 ; i<e ; i++){
        int a,b,c;
        cin >> a >>b >>c;
        
        graph[b].push_back({c,a});
        graph[a].push_back({c,b});
    }

    int result = prim(1);

    cout <<result << '\n';
    return 0;

}
