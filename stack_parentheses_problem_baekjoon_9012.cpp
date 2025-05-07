#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <climits>
using namespace std;
//BackJoon 9012 -> 괄호 문제 (VPS 확인 문제)

// 프로그램의 진입점
int main(){
    int n;  // 테스트 케이스의 수
    cin >> n;  // 사용자로부터 테스트 케이스의 수를 입력받음

    // 각 테스트 케이스에 대해 반복
    while (n--)
    {
        string input;  // 괄호 문자열을 저장할 변수
        cin >> input;  // 사용자로부터 괄호 문자열을 입력받음

        stack<char> s;  // 여는 괄호 '(', 닫는 괄호 ')'를 관리할 스택
        bool isValid = true;  // 괄호 문자열의 유효성 검사 여부를 추적하는 변수

        // 입력된 괄호 문자열을 하나씩 순차적으로 확인
        for( char ch: input){
            // 여는 괄호 '('가 나오면 스택에 추가
            if(ch == '('){
                s.push(ch);  // '('는 스택에 넣어서 나중에 짝을 맞추기 위해 보관
            }
            // 닫는 괄호 ')'가 나오면
            else if(ch == ')'){
                // 스택이 비어있다면 짝이 맞지 않으므로, 유효하지 않다고 판단
                if(s.empty()){
                    isValid = false;  // 유효하지 않으므로 플래그를 false로 설정
                    break;  // 더 이상 체크할 필요가 없으므로 루프를 종료
                }
                // 닫는 괄호가 나오면 스택에서 하나를 제거하여 짝을 맞춤
                s.pop();  // 짝을 맞춘 여는 괄호는 스택에서 제거
            }
        }

        // 문자열을 다 확인한 후
        // 만약 스택이 비어 있고 isValid가 true이면 괄호가 잘 짝지어진 것
        if(isValid && s.empty()){
            cout<< "YES" << endl;  // 유효한 괄호 문자열이므로 "YES" 출력
        }else{
            cout << "NO" << endl;  // 유효하지 않은 괄호 문자열이므로 "NO" 출력
        }

    }
    return 0;  // 프로그램 종료
}
