#include <iostream>
using namespace std;

int main() {
    int a, b, v;
    cin >> a >> b >> v;
    
    int day, remain;
    
    remain = v-a;
    
    day = remain/(a-b);
    
    if(remain % (a-b) != 0)
    {
      day ++; 
        }
    
    cout << day+1 << endl;
}


