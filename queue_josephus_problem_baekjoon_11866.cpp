#include <iostream>
#include <stack>
#include <vector>
#include<queue>
using namespace std;

int main( ){

	int n , k;

	cin >> n>> k;

	queue<int> que;
	vector<int> result;
	for(int i = 0 ; i< n ; i++){
		que.push(i+1);
	}

	while (!que.empty())
	{
		/* code */
	
	
	for(int i = 0 ; i < k-1 ; i++){
que.push(que.front());
		que.pop();
	}
	result.push_back(que.front());

	que.pop();


	}

	cout << "<";

	for(int i = 0 ; i< n ; i++){
		if(i == 0 ){
			 cout<< result[i];
		}
		else{
			cout << ", "<<result[i];
		}
	}

	cout << ">";
	return 0;

	}
