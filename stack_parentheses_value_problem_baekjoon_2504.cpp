
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <climits>
using namespace std;
//백준 2504번 괄호의 값 문제 


int main(){

    string input;
    stack<char> st;

    cin >> input;

    int tmp = 1 ,result = 0;

    for(int i= 0 ; i< input.size(); i++){
        char ch = input[i];

        if(ch == '('){
            st.push(ch);
            tmp *=2;
        }
        else if(ch == '['){
            st.push(ch);
            tmp *=3;
        }
        else if(ch == ')'){

            if(st.empty() || st.top() != '('){
                cout << "0\n";
            }

            if(input[i-1] == '('){
				result +=tmp; 
            }

			st.pop();
			tmp /=2;

        }else if(ch == ']'){
			if(st.empty() || st.top() != '['){
				cout << "0\n";
				return 0;
			}

			if(input[i-1] == '['){
				result +=tmp;
			}
			st.pop();
			tmp /=3;
		}
    }

	if(!st.empty()){
		cout << "0\n";
	}
	else{
		cout << result << endl;
	}
}