#include <iostream>
#include <vector>
#include <string>

using namespace std;
//백준21606 아침산책 

vector<vector<int>> graph;

vector<bool> visited;

vector<bool> isIndoor;



int dfs(int node ){
    visited[node] = true;
    int cnt = 0;

    for(auto& next: graph[node]){
        if(!visited[next]){
            if(isIndoor[next]){
                cnt++;
            }
            else{
                cnt+= dfs(next);
            }
        }
    }
    return cnt;


}

int main(){
    int n;
    string a;
    long long result = 0;
    cin >> n;
    cin >> a;

    graph.resize(n+1);
    visited.resize(n+1,false);
    isIndoor.resize(n+1,false);
    for(int i = 0 ; i < n ; i++){
        if(a[i]== '1') isIndoor[i+1] = true;
    }

    for(int i = 0 ; i< n-1 ; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);

        if(isIndoor[u] && isIndoor[v]){
            result +=2;

        }
    }

    for(int i = 1; i <=n ; i++){
        if(!isIndoor[i] && !visited[i]){
            int cnt = dfs(i);
            result += static_cast<long long> (cnt)*(cnt-1); 
        }
    }

    cout <<result <<'\n';
    //system("pause");
    return 0;


}