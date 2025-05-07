#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
//색종이 만들기 백준2630 https://www.acmicpc.net/problem/2630

int n ;
int paper[128][128];
int white = 0 , blue = 0;

bool isSameColor(int x, int y, int size){
	int color = paper[x][y];
	
	for(int i = x ; i < x+size ; i ++ ){
		for(int j = y; j<y+size ; j++){
			if(paper[i][j] != color)return false;
			
		}
	} 
	
	return true;
}


void diviepaper(int x, int y, int size){

	 if(isSameColor(x,y,size)){
		 
		 if(paper[x][y] == 0 )blue ++;
		 
		 else{ white++ ;}
		 
		 return;
	 }
	int  newsize = size/2;
	
	diviepaper(x,y,newsize);
	diviepaper(x,y+newsize , newsize);
	diviepaper(x+newsize , y, newsize);
	diviepaper(x+newsize , y+newsize , newsize);
	
	
}



int main(){
	
	cin >> n; 
	
	for(int i  = 0 ; i < n ; i++){
		 for(int j = 0 ; j < n ; j++){
			 
			 cin >> paper[i][j];
		 }
	}
	
	diviepaper(0,0,n);
	
	cout << white << endl;
	cout << blue << endl;
	
	return 0;
}

