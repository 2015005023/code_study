#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 백준14888
int n;
vector<int> c;
int cn[4];
vector<int> a;

int maxResult= -1e9;
int minResult = 1e9;


void f(int fn){
    if(fn == n-1){
        int num = a[0];
        for(int i = 1 ; i<n;i++){
            if(c[i-1] == 0) num+= a[i];
            else if(c[i-1] == 1 ) num -=a[i];
            else if(c[i-1] == 2 ) num *= a[i];
            else if(c[i-1] == 3 ){
                if(num <0){
                    num = -(-num/a[i]);
                }else{
                    num /= a[i];
                }
            } 
        }

        maxResult = max(maxResult,num);
        minResult = min(minResult,num);
        return;
    }

    for(int i = 0 ; i<4; i ++){
        if(cn[i] >0){
            c[fn]= i;
            cn[i]--;
            f(fn+1);
            cn[i]++;

        }
    }



}

int main(){
    cin >> n;
    c.resize(n-1);
    a.resize(n);

    for(int i = 0 ; i< n ; i++) cin>>a[i];

    for(int i =0 ; i< 4; i++) cin>>cn[i];

    f(0);

    cout << maxResult <<'\n';
    cout << minResult <<'\n';

    //system("pause");
    return 0;
}

