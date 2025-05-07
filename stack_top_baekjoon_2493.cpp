#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main( ){

	int n;
	cin >> n;

	vector<int> height(n);
	vector<int> result(n,0);

	stack<pair<int,int>> st;

	for(int i = 0 ; i< n ; i++){

		cin >> height[i];

		while (!st.empty() && st.top().first < height[i])
		{
			st.pop();

		}
		if(!st.empty()){
			result[i] = st.top().second +1;
		}

		st.push({height[i] ,i});
	}

		
	for(int num : result){
		cout << num << " " ;
	}
	
/*
	cout << endl;


	while (!st.empty())
	{
		cout <<"[" << " " << st.top().first << " " << st.top().second << " ]" << endl;

		st.pop();

	}*/
	return 0;
	}
