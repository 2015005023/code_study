#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include<climits>
#include <algorithm>
#include <functional> 
using namespace std;

struct Edge
{
    int u , v;
    int weight;
    bool operator<(Edge& other){
        return weight < other.weight;
    }
};

int parent[100001];


int find(int x){
if (parent[x]==x )
{
    return x;
}

return parent[x] = find(parent[x]);
}

void unionSet(int x, int y){
    x= find(x);
    y= find(y);

    if(x != y) parent[y] =x;
}


int main(){

    int v, e;
    cin >> v >>e;
    vector<Edge> edges;
    for(int i = 0 ; i < e ; i++){
        int a,b,c;
        cin >> a >> b >>c;
        edges.push_back({a,b,c});
    }

    for(int i = 1 ; i<=v ; i++){
        parent[i] = i;
    }

    sort(edges.begin() , edges.end());

    int mst_result = 0;

    for(Edge& e : edges){
        if(find(e.u) != find(e.v)){
            unionSet(e.u , e.v);
            mst_result +=e.weight; 
        }
    }

    cout << mst_result << '\n';
    return 0;
    
}
