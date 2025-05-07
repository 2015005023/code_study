


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;
typedef pair<int , int > Point;
vector<Point> points;

long long directSq(const Point& a, const Point& b){//유클리드 거리 계산식 
	
	long long dx = b.first - a.first ;
	long long dy= b.second - a.second;
	
	return dx * dx + dy * dy;
	
	
}


long long closestPair ( int left ,int right){
	if(left == right )return LLONG_MAX;
	if(right - left == 1) return directSq(points[left] , points[right]);
	
	int mid = left+ (right - left)/2; // 중앙값 구하는 공식
	long long d = min(closestPair(left,mid), closestPair(mid+1 , right));
	
	
	vector<Point> strip;
	
	long long midX = points[mid].first;
	
	for(int i = left ; i <= right ; i++){
		long long dx = points[i].first - midX;
		if(dx * dx  < d){
			 strip.push_back(points[i]);
		}
	}
	
	sort(strip.begin() , strip.end(), [](const Point& a,const Point& b){
		return a.second < b.second;
	});
	
	int sz = strip.size();
	for(int i = 0 ; i< sz ; i++){
		 for(int j = i+1 ; i <sz && (strip[i].second - strip[j].second) * (strip[i].second - strip[j].second) <d ; j++){
			 
			 d = min( d , directSq(strip[i] , strip[j]));
		 }
	}
	
	return d;
}



int main(){ 
	int n;
	cin >>  n ;
	 
	points.resize(n);
	for(int i = 0 ; i< n ; i++){
		cin >> points[i].first >> points[i].second;
	}
	
	sort(points.begin() , points.end() ,[](Point& a, Point& b){
		 return a.first < b.first;
	});

	cout << closestPair(0, n-1)<< endl;
	return 0;
}
