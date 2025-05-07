#include <iostream>



void printInvertedPyramid(int n, int current =1)
{
	if(n<current) return;
	
	cout << string(current-1,' ');
	
	cout << string(2*(n-current)+1,'*')<<endl;
	
	printInvertedPyramid(n,current+1);

}
int main() {
    int n;
	  cout<< "Enter the number of levels : ";
		cin>> n;
	  printInvertedPyramid(n);
}
	