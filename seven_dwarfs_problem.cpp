#include <iostream>
#include <algorithm>
#define Max_number 9
using namespace std;

int main() {
	
	int dwarfs[Max_number], sum =0;
	
	
	for(int i = 0 ; i< Max_number ; i++){
		
		cin >> dwarfs[i];
		sum += dwarfs[i];
	}
	for(int i = 0 ; i< Max_number ; i++){

	 for(int j = i+1 ; j< Max_number ; j++){
		
		 if(sum - dwarfs[i] - dwarfs[j] == 100){
			 
			 dwarfs[i] = -1;
			 dwarfs[j] = -1;
			 
			 sort(dwarfs , dwarfs+9);
			 
			 for(int k =2 ; k<Max_number ; k++){
				 
				 cout << dwarfs[k] << endl; 
			 }
			 
			 return 0; 
		 }
		 

	 }
				 
		
		
	}
	return 0;
}



