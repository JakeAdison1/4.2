#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
class Student {
	string name;
	short age;
	short course;
	string sex;
	short mark;

public:
	

	Student();
	Student(string input_name, short input_age, string input_sex, short input_course, short input_mark);
	Student(const Student& T);
	Student(Student&& T) noexcept;
	~Student();

	void getData(int& first, int& second, int& third, int& four);
	void showData();
	void input(Student& person, fstream& stud, char& ch);
	void output(Student& person, fstream& stud);
};