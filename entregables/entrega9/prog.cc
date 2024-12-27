#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 *
 * @PRE: An empty vector
 * @POST: A vector filled with elements
 *
 * */

void read_vector(vector<string>&v)
{
	for (int i = 0; i < v.size(); i++)
		cin >> v[i];
}

/*
 *
 * @PRE: A non empty vector, a string, and the position which we will compare the string to.
 * @POST: True if the value in the position mid is bigger than the str, false otheriwse.
 *
 * */

bool cmp_str(const vector<string>&v, const int mid, const string str)
{
	if (v[mid].size() == str.size())
		return (v[mid] >= str);
	else 
		return (v[mid].size() > str.size());
}

/*
 * @PRE: A non empty vector and a string.
 * @POST: Using binary search, returns the position where the string would be placed at.
 *
 * */

int first_position(const vector<string>&v, const string str)
{
	int start = 0, end = v.size()-1, mid;
	while (start < end)
	{
		mid = start + (end - start) / 2;
		if (cmp_str(v,mid,str))
			end = mid;
		else 
			start = mid + 1;
	}
	return (start);
}


int main() {
    int n;
    cin >> n;
	vector<string>v(n);
    read_vector(v);
	string z;
    while (cin >> z)
        cout << first_position(v, z) << endl;
}
