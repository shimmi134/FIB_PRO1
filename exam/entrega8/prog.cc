#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Fruit {
     string name;
     int amount;
};

/*
 * @PRE: An ordered vector named fruits and a tuple named Fruit.
 *
 * @POST: Modifica el vector fruits, afegint un nou element al vector
 * en cas que no es trobava abans, o suma les quantitats que hi ha 
 * de un element que ja era a fruits
 *
 * */

void add_fruit(vector<Fruit>& fruits, const Fruit& fruit)
{

	if (fruits.size() == 0)
		fruits.push_back(fruit);
	else
	{
		int j = 0;
		bool notSeen = true;
		while (notSeen && j < fruits.size())
		{
			if (fruit.name == fruits[j].name)
			{
				notSeen = false;
				fruits[j].amount += fruit.amount;
			}
			j++;
		}
		if (notSeen)
		{
			fruits.push_back(fruit);
			int i = fruits.size()-1;
			bool done = true;
			while (i > 0 && done)
			{
				if (fruits[i].name < fruits[i-1].name)
					swap(fruits[i],fruits[i-1]);
				else
					done = false;
				i--;
			}
		}
	}
}

int main() {
     vector<Fruit> fruits;
     Fruit f;
     while (cin >> f.name >> f.amount) {
          add_fruit(fruits, f);
     }
     for (int i = 0; i < fruits.size(); i++) {
          cout << fruits[i].name << ' ' << fruits[i].amount << endl;
     }
     return 0;
}
