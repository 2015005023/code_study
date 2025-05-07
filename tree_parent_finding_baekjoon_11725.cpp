#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include<climits>
#include <algorithm>
#include <functional> 
using namespace std;

vector<vector<int>>graph;
vector<bool> visited;

int parent[100001];
void dfs(int start){
visited[start] = true;

for(auto& next  : graph[start]){
    if(!visited[next]){
        parent[next] = start;
        dfs(next);
    }
}


}

void bfs(int start)
{
    queue<int> q;

    visited[start] = true;

    q.push(start);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(auto& next : graph[curr]){
            if(!visited[next]){
                visited[next] =true;
                parent[next] = curr;
                q.push(next);
            }
        }

    }
    


}

int main(){
    int n;
    cin >> n;

    graph.resize(n+1);
    visited.resize(n+1,false);

    for(int i = 0 ; i< n -1 ; i++){
        int a ,b;
        cin >> a >>b;
        graph[b].push_back(a);
        graph[a].push_back(b);

    }

    bfs(1);//dfs 모두 유효하다 
    for(int i =2 ; i <=n ; i++){
        cout << parent[i] <<'\n';

    }

    return 0;
}