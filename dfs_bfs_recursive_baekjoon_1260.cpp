#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


vector<vector<int>> graph;

vector<bool> visited;

int n,m, v;


void reset_visited(vector<bool>& visited){

    fill(visited.begin() , visited.end() , false);
}
void dfs(int v) {

    visited[v] = true;

    cout << v << ' ';

    for(int  next : graph[v]){
        if(!visited[next]){
            dfs(next);
        }
    }


}


void bfs(int v ) {

    queue<int> q;

    visited[v] = true;

    q.push(v);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr <<' ';
        for(int next : graph[curr]){

            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
    

    

}

int main() {
    cin >> n >> m >> v;


    graph.resize(n+1);
    visited.resize(n+1,false);

    for(int i = 0 ; i< m ; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);//"양방향 간선 "
    }

    for(int i = 1 ; i <= n ; i++){

        sort(graph[i].begin() , graph[i].end() ); //"정점 번호 적은 것 부터 방문 "
    }

    dfs(v);

    cout << '\n';

    reset_visited(visited);

    bfs(v);

    return 0;
}
