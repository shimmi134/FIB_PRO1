#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Word{
	string word;
	int count;
};

void read_vector(int n)
{
	vector<Word>v;
	string word;
	for (int i = 0; i < n; i++)
	{
		cin >> word;
		bool found = false;
		for (int j = 0; j < v.size() && !found; j++)
		{
			if (v[j].word == word)
			{
				v[j].count++;
				found = true;
			}
		}
		if (!found)
		{
			//Word wrd;
			//wrd.word = word;
			//wrd.count = 1;
			Word wrd = {word, 1};
			v.push_back(wrd);
		}
	}
	int max_count = 0;
	string most_freq_word;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].count > max_count || (v[i].count == max_count && v[i].word > most_freq_word))
		{
			most_freq_word = v[i].word;
			max_count = v[i].count;
		}
	}
	cout << most_freq_word << endl;
}


int main(void)
{
	int size;
	
	cin >> size;
	while (size != 0)
	{
		read_vector(size);
		cin >> size;
	}
}
