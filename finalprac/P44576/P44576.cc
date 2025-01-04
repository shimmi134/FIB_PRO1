#include <vector>
#include <iostream>
using namespace std;


struct Student {
    int idn;
    string name;
};


struct Mark {
    int idn;
    string subj;     // subject
    string sch;     // school
    double mark;
};


void read_students(vector<Student>& students) {
    int m;
    cin >> m;
    students = vector<Student>(m);
    for (int i = 0; i < m; ++i) cin >> students[i].idn >> students[i].name;
}


void read_marks(vector<Mark>& marks) {
    int n;
    cin >> n;
    marks = vector<Mark>(n);
    for (int i = 0; i < n; ++i) {
        cin >> marks[i].idn >> marks[i].subj >> marks[i].sch >> marks[i].mark;
    }
}

void five_spaces(void)
{
	cout << "     ";
}

double print_grades(Student st, Mark mk, bool g)
{
	if (not g)
		cout << st.idn << " " << st.name << endl; 
	five_spaces();
	cout << mk.subj << " " << mk.sch << " " << mk.mark << endl;
	return (mk.mark);
}


int main() {
    cout.setf(ios::fixed);      //Set the the format of doubles
    cout.precision(2);          // to write the marks

    vector<Student> students;
    vector<Mark> marks;
    read_students(students);
    read_marks(marks);
	for (int i = 0; i < students.size(); i++)
	{
		bool gotin = false;
		double avg = 0, count = 0;
		for (int j = 0; j < marks.size(); j++)
		{

			if (students[i].idn == marks[j].idn)
			{
				avg = avg + print_grades(students[i], marks[j], gotin);
				count++;
				gotin = true;
			}
		}
		if (gotin)
		{
			five_spaces();
			cout << "average: " << avg / count << endl;
			cout << endl;
		}
	}

}
