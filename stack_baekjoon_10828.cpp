#include <iostream>
#include <string>
using namespace std;

class Stack {
	private:
		int arr[10000];
		int topIndex = -1;
	
	public:
		void push(int X) {
			if (topIndex < 9999) {
				arr[++topIndex] = X;
			}
		}
		
		void pop() {
			if (topIndex == -1) {
				cout << -1 << endl;
				return;  // 🚨 Segmentation Fault 방지
			}
			cout << arr[topIndex--] << endl;
		}

		void size() {
			cout << topIndex + 1 << endl;
		}

		void empty() {
			cout << (topIndex == -1 ? 1 : 0) << endl;
		}

		void top() {
			if (topIndex == -1) {
				cout << -1 << endl;
			} else {
				cout << arr[topIndex] << endl;
			}
		}
};

int main() { 
	int n;
	cin >> n;
	Stack s;

	while (n--) {  // 👌 count 변수 없이 반복
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int X;
			cin >> X;
			s.push(X);
		}
		else if (cmd == "pop") {
			s.pop();
		}
		else if (cmd == "size") {
			s.size();
		}
		else if (cmd == "empty") {
			s.empty();
		}
		else if (cmd == "top") {
			s.top();
		}
	}

	return 0;
}