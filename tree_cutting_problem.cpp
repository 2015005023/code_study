//나무 자르기 문제 백준 2805

#include <iostream>
#include <algorithm>
#define Max_number 9
#include <climits>
using namespace std;

long long AmountofTrees(vector<int>& trees , int height){

//total이 trees 함수의 인덱스에 있는 값들을 보고 크면 비교해서 전부 더해주고 넘기는것. 
	long long total=0;
	for(int tree: trees){
		if(tree >= height){
			
			total +=(tree - height); 
		}
	}
	
	return total;
}


int main(){
	int n , m;
	
	cin >> n >> m;
	
	
	vector<int> trees(n);
	
	for(int i = 0 ; i < n ; i++){
		cin >> trees[i];
	}
	
	int low = 0 , high = *max_element(trees.begin(), trees.end());// max_element()함수는  위치 주소값을리턴하기때문에 *로 넣어줘야한다. 
	
	int result = 0;
	
	while(low <=high){
		int mid = low + (high - low)/2; // 중간값 0 100 -> 50 이런느낌 overflow방지 
		
		long long woods = AmountofTrees(trees, mid);// 큰 수이기때문에 ll으로 
		
		if(woods >= m){ // binary search tree 절반씩 감소시켜가면서 중간값을 기준으로 mid값이 원하는 값보다 작으면 low = mid+1 크면 high =mid-1; 이런식

			result = mid;
			low = mid+1;
		}else{
			high = mid-1;
		}
	}
	
	cout << result << endl;
	
	
return 0;
	
}