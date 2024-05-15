#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;
int main() { 
	setlocale(LC_ALL, "RU");
	int course;
	short mark;
	char ch;

	Student person;
	fstream stud;
	stud.open("students.txt", ios::in | ios::out | ios::app | ios::binary);
	while (!stud.is_open()) {
		cout << "Ошибка 1";
		return 1;
	}
	cout << "Обычный ввод:\n";
	person.input(person, stud, ch);
	stud.seekg(0);//читаем данные о первом студенте
	stud.read(reinterpret_cast<char*>(&person), sizeof(person));
	person.output(person, stud);//читаем данные о следующих студентах
	cout << endl;
	cout << endl;
	stud.close();
	remove("students.txt");

	cout << "------------------" << endl << "------------------" << endl << "------------------" << endl << "------------------" << endl;
	cout << "Использование конструкторов:\n";
	Student A;
	Student B("Sasha", 14, "male", 2, 3);
	Student C(A);
	Student Z;
	Student D = move(Z);
	fstream constr;
	constr.open("constructor.txt", ios::in | ios::out | ios::app | ios::binary);
	while (!constr.is_open()) {
		cout << "Ошибка 2";
		return 2;
	}
	
	constr.write(reinterpret_cast<char*>(&A), sizeof(A));
	constr.write(reinterpret_cast<char*>(&B), sizeof(B));
	constr.write(reinterpret_cast<char*>(&C), sizeof(C));
	constr.write(reinterpret_cast<char*>(&D), sizeof(D));
	constr.seekg(0);//читаем данные о первом студенте
	constr.read(reinterpret_cast<char*>(&A), sizeof(A));
	constr.read(reinterpret_cast<char*>(&B), sizeof(B));
	constr.read(reinterpret_cast<char*>(&C), sizeof(C));
	constr.read(reinterpret_cast<char*>(&D), sizeof(D));
	cout << "Конструктор без параметров:\n";
	A.showData();
	cout << "Конструктор с параметрами:\n";
	B.showData();
	cout << "Конструктор копирования:\n";
	C.showData();
	cout << "Конструктор перемещения:\n";
	D.showData();
	cout << endl;
	cout << endl;
	constr.close();
	remove("constructor.txt");
	
}
