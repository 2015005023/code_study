#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
// 백준 1629번 문제 곱셈 문제
// 10 11 12  -> 4 

//두가지로 구현이 가능함  1. 재귀함수, 2 반복문 

//1.재귀
// 2 ^11%3 이라고 가정 할 때 A 2 B 11 C 3 -> 2^5 2^5 *2 -> 2^2*2 * 2^2*2 * 2 -> 2
/*long long  power (long long A , long long B, long long C){
if(B == 0) return 1;
	long long half = power( A, B/2 ,C);
	half = (half *  half)%C;
	
	if(B %2 ==1){
		 return (half * A )%C;
	}
	
	return half;
}*/

//2. 반복문을 통한 구현
long long  power (long long A , long long B, long long C){
long long result = 1;//2^0 = 1;

	while(B>0){
		if( B %2 ==1 ){
			
			result = (result * A)%C;
		}
		A= (A *A) %C;
		B /=2;
	}
	
	return result;
	
}

int main(){

	long long A,B,C;
	
	cin >> A >> B >>C;
	
	long long  result = power(A,B,C);
	cout << result << endl;
}

