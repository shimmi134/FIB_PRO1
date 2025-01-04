#include <iostream>
#include <vector>

using namespace std;

struct player{
	int level;
	string name;
};

void read_vector(vector<player>& v)
{
	int nivell;
	string nom;
	for (int i = 0; i < v.size(); i++)
	{
		cin >> nom >> nivell;
		v[i].name = nom;
		v[i].level = nivell;
	}
}


vector<player> get_results (const vector<player>p1, const vector<player>p2)
{
	vector <player> pr = p1;
	for (int i = 0; i < p1.size(); i++)
	{
		pr[i].level = 0;
		for (int j = 0; j < p1.size(); j++)
		{
			if (p1[i].level > p2[j].level)
				pr[i].level += 2;
			else if (p1[i].level == p2[j].level)
				pr[i].level += 1;
		}
	}
	return (pr);
}

void print_vector(const vector<player>p)
{
	for (int i = 0; i < p.size(); i++)
	{
		cout << p[i].name << " " << p[i].level;
		if (i != p.size()-1)
			cout << " ";
	}
	cout << endl;
}

int main(void)
{
	int n;
	while (cin >> n)
	{
		vector<player> p1(n);
		vector<player> p2(n);
		read_vector(p1);
		read_vector(p2);
		vector<player> p1r = get_results(p1, p2);
		vector<player> p2r = get_results(p2, p1);
		print_vector(p1r);
		print_vector(p2r);
		cout << endl;
	}
}
