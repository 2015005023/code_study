#include <iostream>
#include <stack>
#include <vector>
#include<queue>
using namespace std;

int main( ){

	int n;
	cin >> n;

	queue<int> que;
	for(int i = 0 ; i < n ; i++){

		que.push(i+1);

	} 
	while (que.size() > 1)
	{
		que.pop();
		que.push(que.front());
		que.pop();
	}
	
	cout << que.front() << endl; 
	


}
