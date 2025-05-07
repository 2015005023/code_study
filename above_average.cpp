#include <iostream>
#include <string>
#include <cstdio> 
using namespace std;

int main() {
    int num;
    
    cin >> num;
	
	while(num --)
	{
		 int n;
		 cin >> n;
		int score[n];
		int sum = 0;
		for(int i = 0 ; i<n ; i++)
		{
			cin >>score[i];
			sum +=score[i];
		}
		int average = (double)sum / n;
	
		 int count =0 ;
			for(int i = 0 ; i<n ; i++)
	 		{
				 if(score[i]>average)
				 {
          count +=1;
				  }
			  }
	 double percent = (double)count / n * 100;
		  printf("%.3f%%\n",percent);
	
		
		
	}
    
}