#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

vector<string> splitString(string line)	//returns a vector with the words of the string
{
	vector<string> words;
	stringstream isstring(line);//ifstream pentru stringuri
	string word;
	while (isstring >> word)
	{							//while we have words we add them at the end of the vector- words
		words.push_back(word);
	}
	return words;
}

string toLower(string str)
{
	int l = str.length();
	for (int i = 0; i < l; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
	}
	return str;
}

class CompareWords 
{
public:
	bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) 
	{
		if (p1.second == p2.second) {
			return p1.first > p2.first;
		}
		return p1.second < p2.second;
	}
};

int main()
{
	ifstream file("input.txt");

	string line;
	map<string, int> wordCount;

	while (getline(file, line))
	{
		vector<string> words = splitString(line);
		
		for (auto it = words.begin(); it != words.end(); ++it) 
		{
			string word = toLower(*it);
			word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());//erases all punctuation characters found
			wordCount[word]++;//adds the word to the map
		}
	}
	file.close();

	priority_queue<pair<string, int>, vector<pair<string, int>>, CompareWords> pq;

	for (map<string, int>::iterator it = wordCount.begin(); it != wordCount.end(); it++)
	{
		pq.push(*it);	//*it gets the value of that object
	}

	//print the words in order
	while (!pq.empty()) 
	{
		pair<string, int> entry = pq.top();
		cout << entry.first << ": " << entry.second << endl;
		pq.pop();
	}

	return 0;
}