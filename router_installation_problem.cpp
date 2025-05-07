//https://www.acmicpc.net/problem/2110 백준2110번 문제 


#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


bool calDistance(vector<int>& house ,int distance, int C){

int count =1 ;
	int first_position = house[0];
	
	for(size_t i =1 ; i < house.size() ; i++){
		if(house[i]-first_position >= distance){
			count++;
			first_position = house[i];
			
		}
	}
	
	return count >= C;
}



int main() {

	int N, C;
	
	cin >> N >> C;
	
	vector<int> house(N);
	for(int i = 0 ; i < N ; i++){
		
		cin >> house[i];
	}
	
	sort(house.begin(), house.end());
	
	int low = 1; 
	int high = house[N-1] - house[0]; //최대 길이 
	
	int result= 0;
	while(low <= high){
		int mid = low + (high-low)/2;
		
		if(calDistance(house , mid , C)){
			
			result = mid;
			low= mid+1;
		}else{
			high = mid-1;
		}
		

		
	}
		
		cout << result << endl;
		
		return 0;
}