/*
#include <iostream>
#include <string>
#include <vector>
#include <cstdio> 

using namespace std;

int main()
{ 
	string line;
	getline(cin, line);
	
	int count = 0;
	bool inward = false;
	
	for(int i = 0 ; i< line.length() ; i++)//hello wold
	{
		 if(line[i] != ' ')
		 { 
			  if(!inward)
				{
					count ++;
					inward = true;
				}

		  }else{ 
				  inward = false;
				}
		
	 }
	cout << count << endl;
	
	return 0;
}

*/

//split구현을 통한 갯수 세기 
#include <iostream>
#include <string>
#include <vector>
#include <cstdio> 

using namespace std;

vector<string> split(const string& str, char delimiter)
{
	vector<string> tokens;
	string token;
	
	for(char c: str)
	{
		 if(c == delimiter)
		 {
			 if(!token.empty()){
				 
				 tokens.push_back(token);
				 token.clear();
			 }

		 }else {
			 token +=c;
		 }

	}

if(!token.empty())
{
 tokens.push_back(token);
}
	return tokens;
}

int main() {
	
  string line;
	getline(cin,line);
	

	int count = 0;
	vector<string> words = split(line, ' ');


count = words.size();
	
	cout << count << endl;
	
	return 0;
}

