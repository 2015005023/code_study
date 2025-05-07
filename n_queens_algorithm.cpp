#include <iostream>
#include <vector>
#include <cmath>
#define MAX 15

using namespace std;

int N,total =0;
int cal[MAX];

bool check(int level){//levels열 -> 행과 대각선일때는 false , 아니면 true
	   for(int i = 0 ; i< level ; i++)
		 {   // 1)열이 같은 경우 ex) (1,1) (2,1)             2)대각선이 겹치는 경우 (a,b) (x,y) = a-x = b-y ex) (1,3) (2,2) -> [1] = [1] 
			 if(cal[i] == cal[level] || abs(cal[level] - cal[i]) == level - i) return false;
		 }
    return true; // 둘다 해당 않으면  그냥 true 
	
}

void nQueen(int raw =0)
{ 
	if(raw == N) //N행까지 모두 다 돌면 횟수를 올림 
	{
		 total++;
		 return;
}
	for(int cal_num = 0; cal_num < N ; cal_num++)
	{
		 cal[raw] = cal_num;//0부터 시작하는 raw행에 cal_num의 열의 몇번째인지 넣음
		if(check(raw)){//열이 겹치거나 대각선일 경우에 -> false, 둘다 아니면 true인 primal func check 
			
			nQueen(raw+1);// check가 트루 -> 즉 대각선도 행도 겹치지 않았을 경우 다음 행으로 넘어간다. 
		}
		//예를들어 raw가 0일때는 모둔 행이 true가 될 수 있다 (0,0)부터 시작 재귀함수로 행 넘어감 -> (1.0)(안됨) ->(1.1)안됨 ->(1,2)됨 
		// (1,2)-> 재귀함수로 다음 행으로 넘어감 그러나 (0,0) (1,2)일 경우 (2,0 1 2 3) 모두 false가 떠버림  
    // 그런 경우 -> 프로그램이 종료되는것이 아닌  (1,3)으로 백트래킹이 일어남 그 이후로 (2. 0 1 2 3) 으로 진행되는 방식 
		

	}

}


	
int main() { 
	cin >> N;
	nQueen();
	
	cout << total;
return 0;
}