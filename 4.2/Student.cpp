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
	cout << "������� ���:"; cout << " "; cin >> name; cout << endl;
	do { cout << "������� �������:"; cout << " "; cin >> age; cout << endl; } while (!(age >= 14 && age <= 100));

	cout << "������� ���:"; cout << ""; cin >> sex; cout << endl;
	do { cout << "������� ����:"; cout << " "; cin >> course; cout << endl; } while (!(course >= 1 && course <= 4));
	do { cout << "������� ������� ����:"; cout << " "; cin >> mark; cout << endl; } while (!(mark >= 1 && mark <= 10));
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
	cout << "���:" << " " << name << endl << "�������:" << " " << age << endl;
	cout << "���:" << " " << sex << endl << "����:" << " " << course << endl << "������� ����:" << " " << mark << endl;
}

void Student::input(Student& person, fstream& stud, char& ch) {
	int first = 0, second = 0, third = 0, four = 0;
	do {
		cout << "������� ������ � ��������:";
		cout << endl;
		person.getData(first, second, third, four);
		stud.write(reinterpret_cast<char*>(&person), sizeof(person));
		cout << "���������� �� ����?(y/n):";
		cin >> ch;
		cout << endl;
	} while (ch == 'y');

	cout << "�������� ������� �������������������� ������� �� �����:" << endl;
	cout << "������� ����:";
	cin >> course;
	if (course == 1) {
		cout << "���-�� ������������ �� 1 �����:";
		cout << first;
	}
	if (course == 2) {
		cout << "���-�� ������������ �� 2 �����:";
		cout << second;
	}
	if (course == 3) {
		cout << "���-�� ������������ �� 3 �����:";
		cout << third;
	}
	if (course == 4) {
		cout << "���-�� ������������ �� 4 �����:";
		cout << four;
	}
	cout << endl;
}

void Student::output(Student& person, fstream& stud) {
	cout << endl;
	cout << "������ ��������� ���������:";
	cout << endl;
	while (!stud.eof()) {
		cout << "Person:" << endl;
		person.showData();
		stud.read(reinterpret_cast<char*>(&person), sizeof(person));
	}
}

