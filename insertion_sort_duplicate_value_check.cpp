#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 삽입 정렬을 이용해 정렬하는 함수
void insertionSort (vector<string>& words) {// 5 2 3 1 4 -> 2 5 3 1 4  2 3 5 1 4 ->  1 2 3 5 4 ->  1 2 3 4 5
	
	for(int i = 1; i < words.size() ; i++)
	{
		string key = words[i];
		int j = i-1;
		
		for(j; j >=0 &&(words[j].length() > key.length()  || (words[j].length() == key.length() && words[j] > key)); j--)
		{
			words[j+1] = words[j];
		}

		words[j+1] = key;
	}

	
}
// 중복을 제거하는 함수
void removeDuplicates(vector<string>& words)
{
	vector<string> uniquewords;
	
	for(const auto& word : words)
	{
		if(find(uniquewords.begin() , uniquewords.end() ,word) == uniquewords.end()){
			
			uniquewords.push_back(word);
		}
		
	}

	words = uniquewords;
}

int main() {
	int n;
	cin >> n;
	
	vector<string> words(n);
	for(int i =0; i < n ; i++){
		cin >> words[i];
	}
	removeDuplicates(words);
	
	insertionSort(words);
	
	for(int i =0 ; i<n ;i++)
	{
		cout << words[i] << endl ;

}

	return 0;
	
}
