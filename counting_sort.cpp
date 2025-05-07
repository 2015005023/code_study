//카운팅 소트후 바로 정렬만 

/*
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int MAX_VALUE = 10000;
	int n ;
	
	cin >> n;
	
	vector<int> a(n);
	vector<int> count(MAX_VALUE);
	for(int i = 0 ; i< n ; i++)
	{
		cin >> a[i]; //  5 7 1 3 2
	 count[a[i]]++; // 0 2 1 1 0 1 0 1
	}
	
	for(int i = 0 ; i < MAX_VALUE ; i++)
	{
		 while(count[i]>0)
		 {
			 cout<< i << '\n';
			 count[i]--;
			 
		 }
		
	}

	
return 0;
}//stable함 떨어짐 대신 간편하게 짤수가 있음 n번이상 시행되니까 n+k;

#include <iostream>
#include <vector>

using namespace std;
//카운팅 소트후 바로 정렬만 
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int MAX_VALUE = 10000;
	int n ;
	
	cin >> n;
	
	vector<int> a(n);
	vector<int> count(MAX_VALUE+1,0);
	vector<int> countSum(MAX_VALUE+1,0);
	vector<int> sorted(n);
	for( int i =0 ; i <n ; i++)
	{
		 cin >> a[i]; // 5 2 3 2 1
		
		 count[a[i]]++; // 0 1 2 1 0 1
	}
	countSum[0] = count[0];// 0 1 3 4 4 5 
	for(int i = 1 ; i <=MAX_VALUE ; i++)
	{
		countSum[i] = countSum[i-1] + count[i];

	}
	
	for( int i = n-1 ; i >=0 ; i--)
	{
		sorted[countSum[a[i]]-1] = a[i];
		countSum[a[i]]--;
		
	}
	
	for( const auto& num : sorted)
	{
		cout << num << '\n';

	}
return 0;
}

 