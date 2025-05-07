#include <iostream>
using namspace std;
/*
void printPyramid(int n, int current = 1 )
{
	 if (n<current)return;
	
	 cout<< string(n-current,' ');
	 cout<< string(2*current-1,'*') <<endl;

	 printPyramid(n,current+1);
	 
}

int main() {
    int n;
	  cout<< "Enter the number of levels : ";
		cin>> n;
	  printPyramid(n);
}*