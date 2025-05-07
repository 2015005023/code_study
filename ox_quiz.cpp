#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    
    cin >> t;
	
	 while(t--)
	 {
		 string s; 
		  cin >> s;
		 
		 int score = 0 ;
		 int consecutive = 0;
		 for(char c: s)
		 { 
			  if(c == 'O')
				{ consecutive ++;
				 score += consecutive;
				
				  }else{ consecutive = 0;}

		 
		  }
		cout << score << endl;
		 
	 }
	return 0;
}