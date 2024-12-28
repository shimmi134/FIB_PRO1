#include <iostream>

using namespace std;

struct Clock {
        int h;      // hours (0<=h<24)
        int m;      // minutes (0<=m<60)
        int s;      // seconds (0<=s<60)
};

Clock midnight(void)
{
	Clock c;
	c.h = 0;
	c.m = 0;
	c.s = 0;
	return (c);
}

Clock midnight();
void increase(Clock& r);
void print(const Clock& r);

void increase(Clock& r)
{
	r.s++;
	if (r.s >= 60)
	{
		r.m++;
		r.s = 0;
	}
	if (r.m >= 60)
	{
		r.h++;
		r.m = 0;
	}
	if (r.h >= 24)
		r.h=0;

}

void print(const Clock& r)
{
	cout << r.h /10 << r.h % 10;
	cout << ':' << r.m /10 << r.m % 10;
	cout << ':' << r.s /10 << r.s % 10 << endl;
}


int main()
{
    Clock r = midnight();
    for (int i = 0; i <= 25 * 60 * 60; ++i) {
        print(r);
        increase(r);
    }
    return 0;
}

