#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional> 
using namespace std;


vector<vector<int>> graph;
vector<bool> visited;

int n,m,v;



void reset_visited(vector<bool>& visited){

  fill(visited.begin() , visited.end() , false);
}


void dfs(int v) {

//recursive, stack 
stack<int> st;

st.push(v);

while (!st.empty())
{
    int curr = st.top();

    st.pop();
    if(visited[curr]) continue;

    visited[curr] = true;
    cout << curr << ' ';

    vector<int> tmp = graph[curr];

    sort(tmp.rbegin() , tmp.rend());

    for(int next : tmp){
        if(!visited[next]){
            st.push(next);
        }
    }
}


}




void bfs(int v) {

    queue<int> q;
    visited[v] = true;
    q.push(v);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << ' ';

        for(int next : graph[curr]){
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }

    }
    


 

}

int main() {

    cin >>n >> m >> v;

    graph.resize(n+1);
    visited.resize(n+1);

    for(int i=  0 ; i < m ; i++){
        int a,b;
        cin >> a>> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= n ; i++){
        sort(graph[i].begin() , graph[i].end());
    }

    dfs(v);


    reset_visited(visited);
    cout << '\n';

    bfs(v);

    return 0;

}
