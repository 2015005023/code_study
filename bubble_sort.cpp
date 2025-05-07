#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int&  a, int& b)
{
	
	int temp;
	temp = a;
  a= b;
	b= temp;
	
}

void bubbleSort(vector<int>& arr)
{
	int n= arr.size();
	
	for(int i = 0 ; i < n-1; i ++)
	{
		 for(int j = 0 ; j<n-i-1; j++)
		 { 
			if(arr[j]> arr[j+1])
					{ 
						 swap(arr[j], arr[j+1]);

					}
 
		 }

	}
	 

}

int main()
{ 
	int n;
	cin >> n;
	
	vector<int> numbers(n);
	
	for(int i = 0 ; i < n ; i++)
	{
		cin >> numbers[i];
	}
  bubbleSort(numbers);
	
	for(int num : numbers)
	{ 
		 cout << num << endl;
		
	}
	
}