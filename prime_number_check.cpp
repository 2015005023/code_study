#include <iostream>
#include <string>
#include <vector>
#include <cstdio> 
#include <cmath> 

using namespace std;

bool isPrime(int num)
{
	 if(num <=1)return false;
	 if(num== 2) return true;
	 if(num%2 ==0) return false;
	 
	for(int i = 3 ; i<= sqrt(num) ; i +=2)
	{
        if (num % i == 0) return false;
		
	 }
	
	return true;

}
int main() {
    
    int n;
    
    cin>>n;
    
    int cnt = 0 ;
    for(int i=0; i<n; i++)
    {
         int input_num;
         cin>>input_num;
        if(isPrime(input_num)) cnt++;
 
    }
    
    cout << cnt << endl;

	
}