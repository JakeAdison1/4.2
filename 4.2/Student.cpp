#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;


Student::Student() {
	name = "Dan"; age = 18; sex = { "male" }; course = 1; mark = 4;
}

Student::Student(string input_name, short input_age, string input_sex, short input_course, short input_mark){
	name = input_name; age = input_age; sex = input_sex; course = input_course; mark = input_mark;
}
Student::Student(const Student& T) {
	name = T.name; age = T.age; sex = T.sex; course = T.course; mark = T.mark;
}

Student::Student(Student&& T) noexcept {
	name = T.name;
	T.name = "";
	age = T.age; T.age = 0;
	sex = T.sex; 
	T.sex = "";
	course = T.course; T.course = 0;
	mark = T.mark; T.mark = 0;
}
Student::~Student() {
	cout << "Destructor is working";
}


void Student::getData(int& first, int& second, int& third, int& four) {
	cout << "Введите ФИО:"; cout << " "; cin >> name; cout << endl;
	do { cout << "Введите возраст:"; cout << " "; cin >> age; cout << endl; } while (!(age >= 14 && age <= 100));

	cout << "Введите пол:"; cout << ""; cin >> sex; cout << endl;
	do { cout << "Введите курс:"; cout << " "; cin >> course; cout << endl; } while (!(course >= 1 && course <= 4));
	do { cout << "Введите средний балл:"; cout << " "; cin >> mark; cout << endl; } while (!(mark >= 1 && mark <= 10));
	if (course == 1 && mark < 4) {
		first++;
	}


	if (course == 2 && mark < 4) {
		second++;
	}


	if (course == 3 && mark < 4) {
		third++;
	}


	if (course == 4 && mark < 4) {
		four++;
	}
}

void Student::showData() {
	cout << "ФИО:" << " " << name << endl << "Возраст:" << " " << age << endl;
	cout << "Пол:" << " " << sex << endl << "Курс:" << " " << course << endl << "Средний балл:" << " " << mark << endl;
}

void Student::input(Student& person, fstream& stud, char& ch) {
	int first = 0, second = 0, third = 0, four = 0;
	do {
		cout << "Введите данные о студенте:";
		cout << endl;
		person.getData(first, second, third, four);
		stud.write(reinterpret_cast<char*>(&person), sizeof(person));
		cout << "Продолжить ли ввод?(y/n):";
		cin >> ch;
		cout << endl;
	} while (ch == 'y');

	cout << "Студенты имеющие неудовлетворительные отметки по курсу:" << endl;
	cout << "Введите курс:";
	cin >> course;
	if (course == 1) {
		cout << "Кол-во неуспевающих на 1 курсе:";
		cout << first;
	}
	if (course == 2) {
		cout << "Кол-во неуспевающих на 2 курсе:";
		cout << second;
	}
	if (course == 3) {
		cout << "Кол-во неуспевающих на 3 курсе:";
		cout << third;
	}
	if (course == 4) {
		cout << "Кол-во неуспевающих на 4 курсе:";
		cout << four;
	}
	cout << endl;
}

void Student::output(Student& person, fstream& stud) {
	cout << endl;
	cout << "Список введенных студентов:";
	cout << endl;
	while (!stud.eof()) {
		cout << "Person:" << endl;
		person.showData();
		stud.read(reinterpret_cast<char*>(&person), sizeof(person));
	}
}

