#include <iostream>
#include <vector>
using namespace std;

using namespace std;

struct Student {
  int idn;
  string name;
  double mark;        // The mark is a value between 0 and 10, or -1 that represents NP
  bool repeater;
};

void information(const vector<Student>& stu, double& min, double& max, double& avg){
  min = -1;
  max = -1;
  avg = -1;
  int repeaters = 0;

  int size = int(stu.size());

  for(int i = 0; i < size; ++i){
    if (!stu[i].repeater and stu[i].mark >= 0){
      if (min == -1){
        min = stu[i].mark;
        max = stu[i].mark;
        avg = stu[i].mark;
      } else {
        if(stu[i].mark < min) min = stu[i].mark;
        if(stu[i].mark > max) max = stu[i].mark;
        avg += stu[i].mark;
      }
    } else {
      ++repeaters;
    }
  }

  if (avg != -1) avg = avg / (size - repeaters);
}
/*
int main()
{

    { // vigilar el tipus Estudiant

        struct Estudiant_cntrl {
            int dni;
            string nom;
            double nota;
            bool repetidor;
        };

        Student ru;
        Estudiant_cntrl rc;

        // diagnostics en temps de compilacio
        ru.idn = rc.dni;
        ru.name = rc.nom;
        ru.mark = rc.nota;
        rc.repetidor = ru.repeater;

        // diagnostics en temps d'execucio
        if (sizeof(ru) != sizeof(rc))
            throw string("It seems that 'Student' is not well defined");
        if (typeid(ru.idn) != typeid(rc.dni))
            throw string("It seems that 'Student.idn' is not well defined");
        if (typeid(ru.name) != typeid(rc.nom))
            throw string("It seems that 'Student.name' is not well defined");
        if (typeid(ru.mark) != typeid(rc.nota))
            throw string("It seems that 'Student.mark' is not well defined");
        if (typeid(ru.repeater) != typeid(rc.repetidor))
            throw string("It seems that 'Student.repeater' is not well defined");
    }

    cout.setf(ios::fixed);
    cout.precision(4);

    int n;
    while (cin >> n) {
        vector<Student> es(n);
        for (int i = 0; i < n; ++i) {
            cin >> es[i].mark >> es[i].repeater;
        }
        double min, max, avg;
        information(es, min, max, avg);
        cout << min << " " << max << " " << avg << endl;
    }
    return 0;
}*/
