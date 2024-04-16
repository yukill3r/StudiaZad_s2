#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Collection {
	int total_students;
	int **student_list;
};

void AddStudent(Collection &col, int* val){
	int** a = new int* [col.total_students];
	
	for (int student = 0; student < col.total_students; student++){
		a[student] = new int [col.student_list[student][0]];
	}

	for (int student = 0; student < col.total_students-1; student++){
		for (int student_grades=0; student_grades<col.student_list[student][0];student_grades++){
			a[student][student_grades] = col.student_list[student][student_grades];
		}
		a[student] = col.student_list[student];
	}

	a[col.total_students] = new int [val[0]];
	a[col.total_students] = val;

	col.student_list = a;
	col.total_students++;
}

auto GetStudentGrades(){
	int total_grades = 0;
	printf("How many grades student have?\n");
	do{
		cin >> total_grades;
	} while (!(total_grades>=0));

	total_grades++;

	int *grades = new int[total_grades];
	grades[0] = total_grades;

	for (int x=1; x<total_grades; x++){
		printf("Grade no.%i\n", x);
		do {
			cin >> grades[x];
		} while (!(grades[x]>0 && grades[x]<=5));
	}
	return grades;
}

int main(void) {
	int students_to_add = 0;
	Collection collection = { 0, NULL };

	printf("How many students you want to add\n");
	do {
		cin >> students_to_add;
	} while (!(students_to_add>=0));

	for (int student = 0; student<students_to_add;student++){
		printf("Student no.%i\n", student);

		int* grades = GetStudentGrades();
		AddStudent(collection, grades);

	}

	for (int x=0;x<collection.total_students;x++){
		for (int y=1;y<collection.student_list[x][0];y++){
			cout << collection.student_list[x][y];
		}
	}
	//for (int x=1; x<grades[x]; x++){
	//	printf("%i=%i\n",x,grades[x]);
	//}
	/*
	AddStudent(collection);
	AddStudent(collection);
	AddStudent(collection);
	int count = 0;
	for (int x = 0; x<collection.total_students;x++){
		for (int z = 0; z<5; z++){
			cout << collection.student_list[x][z];
			count++;
		}
	}
	cout << endl << count;
	*/
	delete[] collection.student_list;
	return 0;
}
