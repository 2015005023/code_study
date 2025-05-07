#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
//전선망 깔기  53 / 1 2 4 8 9  -> 3

bool Determine(vector<int> & X ,int T , int K ){
	long long count = 0;
	for(size_t i = 0 ; i < X.size() ; i++){
		if(X[i] <=T){//10 <=12 
			count += (T-X[i]); // 12- 10 
		}
	}
	
	return count <= K;
}

int main(){
	
	
int N , K;

cin >> N >> K ;

vector<int> TeamScore(N);
	for(int i = 0 ; i < N ; i++){
	cin >> TeamScore[i];
	}
	sort(TeamScore.begin() , TeamScore.end());
	
	int low = TeamScore[0] , high = TeamScore[N-1]+K;
	
	int result = 0;
	
	while(low <= high){
		int mid = low + (high-low)/2;
		
		if(Determine(TeamScore , mid , K) ){
			
			result = mid;
			low = mid+1;
		}else{
			
			high = mid-1;
		}
	}
	
	
	cout << result << endl;
	
	return 0 ;
	
}