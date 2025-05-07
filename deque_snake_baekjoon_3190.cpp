#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int n,k,l;

vector<vector<int>> board;

vector<pair<int , char>> moves;

deque<pair<int,int>> snake;
int dx[4]{ 0 ,1, 0 ,-1};
int dy[4]{1,0,-1,0};



int turn(int direction , char ch ){ // 0 east , 1,south , 2 west, 3 norht

	if(ch == 'L'){
		direction = (direction+3)%4;
	}
	else{
		direction = (direction+1)%4;
	}

	return direction;

}
int simulate(){
	int x= 0,y= 0;
	int direction = 0;
	int time = 0;
	int moveIndex = 0;

	snake.push_back({x,y});
	board[x][y] = 2;


	while (true)
	{ 
		int nx = x+ dx[direction];
		int ny = y + dy[direction];

		if(nx >=0 && nx < n && ny >=0 && ny< n && board[nx][ny] != 2 ){
			if(board[nx][ny] == 0){
				pair<int , int> tail = snake.back();
				snake.pop_back();
				board[tail.first][tail.second]= 0;
			}

			snake.push_front({nx,ny});
			board[nx][ny] = 2;

		}else{
			time++;
			break;
		}

		x = nx;
		y = ny; 
		time ++;

		if(moveIndex < l && moves[moveIndex].first == time){
			direction = turn(direction, moves[moveIndex].second);
		moveIndex++;
		}
	}
	

	return time;
}

int main( ){
	cin >> n;
	board.resize(n,vector<int> (n,0));

	cin >> k;

	for(int i = 0 ; i< k ; i++){
		int j , h;

		cin >> j >> h;

		board[j-1][h-1] = 1;
	}
	
	cin >> l;

	moves.resize(l);
	for(int i = 0 ; i< l ; i++){
		cin >> moves[i].first >> moves[i].second;
	}

	cout << simulate() << endl;
return  0;
}