#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



void merge(vector<int>& arr, int left, int mid,  int right)// 4 5 7
{
	int n1 = mid - left +1;
	int n2 = right - mid;

	vector<int> leftArray(n1);
	vector<int> rightArray(n2);
	
	for(int i = 0 ; i < n1 ; i++)
	{
	leftArray[i] = arr[left+i];
		

	}
	for(int i= 0 ; i < n2 ;i++)
	{
		rightArray[i] = arr[mid +1+i];

	}
	int  i = 0, j= 0,k = left;//4321 34 12
	while(i < n1 && j < n2)
	{
		 if(leftArray[i] <= rightArray[j])
		 {
			 arr[k] = leftArray[i];
			 i++;
		 }else{
			 arr[k] = rightArray[j];
			 j++;
			 
		 }
	k++;
	}


while(i<n1){
	arr[k] = leftArray[i];
	i++;
		k++;
}
while(j<n2){
	arr[k] = rightArray[j];
	j++;
		k++;
	}
}


void mergeSort(vector<int>& arr,int left, int right)
{
	if(left <right)
	{
		int mid = left + (right-left)/2;
		
		
		
		mergeSort(arr,left, mid);
		mergeSort(arr,mid+1,right);
		
		merge(arr, left, mid ,right);
		
	}
	
}

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for( int i = 0 ; i < n ; i++)
	{
		cin>>arr[i];

	}
	mergeSort(arr,0,n-1);
	
		for( int i = 0 ; i < n ; i++)
	{
		cout << arr[i] <<endl;
	}
	
}