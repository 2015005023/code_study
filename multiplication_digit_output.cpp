#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a,b;
    
    cin>> a>>b; 
    
    int bDigit1,bDigit2, bDigit3 ;
    bDigit1 = b%10;
    bDigit2 = (b/10)%10;
    bDigit3 = b/100;
    
    cout << a * bDigit1 << endl;
        cout << a * bDigit2 << endl;
        cout << a * bDigit3 << endl;
        cout << (a * bDigit1)+(a * bDigit2* 10)+(a * bDigit3 *100) << endl;
    
 return 0;   
}