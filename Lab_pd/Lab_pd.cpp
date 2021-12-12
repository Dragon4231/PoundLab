#include <iostream>
#include "Score.h"
#include <vector>
#include <list>;
#include <fstream>

using namespace std;

int main()
{
	int operation, position;
	position = 0;
	Score temp(0, 0, 0);
	vector<Score> allScore;
	ifstream ifile;
	ifile.open("Base.txt");
	if (!(ifile.peek() == EOF)) {
		Score in;
		while ( ifile.read((char*)&in , sizeof(Score)) ) {
			allScore.push_back(in);
			position++;
		}
	}
	ofstream ofile;
	ofile.open("Base.txt", fstream::out);
	int pound = 0, shilling = 0;
	double penny = 0;
	int action;
	bool a = false;
	setlocale(LC_ALL, "ru");
	while (true) {
		cout << "Консольное меню: " << endl;
		cout << "Введите '1' для создания нового денежного счёта." << endl;
		cout << "Введите '2' для редактирования денежного счёта." << endl;
		cout << "Введите '3' для проведение операции со счётами." << endl;
		cout << "Введите '4' для информации о существующих счетах." << endl;
		cout << "Введите '5' для выхода из консольного приложения." << endl;
		cout << "=================================================" << endl;
		cin >> operation;
		switch (operation)
		{
		case 1:
			system("cls");
			cout << "Введите количество денег на счету(Фунты, шиллинги(>20), пенсы(>12)) :" << endl;
			try {
				cin >> pound;
				cin >> shilling;
				cin >> penny;
				Score score(pound, shilling , penny);
				allScore.push_back(score);
				cout << "Счёт " << position << " успешно создан" << endl;
				position++;
			}
			catch(exception e){
				cout << e.what();
				exit(0);
			}
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			if (allScore.empty()) {
				cout << "Счета ещё не созданы." << endl;
				system("pause");
				system("cls");
				break;
			}
			cout << "Доступные счета :" << endl;
			for (int i = 0; i < allScore.size(); i++) {
				cout << "№" << i << " ";
			}
			cout << endl;
			cout << "Выберите номер счёта" << endl;
			int number;
			cin >> number;
			if (number < 0 || number >= allScore.size()) {
				cout << "Таких счётов не существует." << endl;
				system("pause");
				system("cls");
				break;
			}
			cout << "Нажмите '1' для удаления счёта" << endl;
			cout << "Нажмите '2' для изменения счёта" << endl;
			cin >> action;
			if (action == 1) {
				allScore.erase(allScore.begin() + number);
			}
			else if (action == 2) {
				cout << "Введите количество денег на счету(Фунты, шиллинги(>20), пенсы(>12) ):" << endl;
				cin >> pound;
				cin >> shilling;
				cin >> penny;
				try {
					allScore[number].setdPound(pound);
					allScore[number].setShilling(shilling);
					allScore[number].setPenny(penny);
				}
				catch (exception e) {
					cout << e.what();
					exit(0);
				}
				cout << "Успешно изменено." << endl;
			}
			else {
				cout << "Выбрано неверное действие." << endl;
			}
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			if (allScore.empty()) {
				cout << "Счета ещё не созданы." << endl;
				system("pause");
				system("cls");
				break;
			}
			cout << "Введите два существующих счёта(номера)." << endl;
			int firstScore, secondScore;
			cin >> firstScore;
			cin >> secondScore;
			if (firstScore < 0 || secondScore < 0 || firstScore >= allScore.size() || secondScore >= allScore.size()) {
				cout << "Таких счётов не существует." << endl;
				system("pause");
				system("cls");
				break;
			}
			cout << "Возможные операции со счётом/счетами." << endl;
			cout << "Операции (1) + , (2) - , (3) унарный - , (4) += , (5) -=, (6) > , (7) < , (8) >=, (9) <= , (10) == , (11) != )." << endl;
			cin >> action;
			switch (action) {
			case 1:
				temp = allScore[firstScore] + allScore[secondScore];
				cout << "Операция выполнена успешно" << endl;
				temp.PrintInfo();
				break;
			case 2:
				try {
					temp = allScore[firstScore] - allScore[secondScore];
				}
				catch (exception e) {
					cout << e.what();
					exit(0);
				}
				cout << "Операция выполнена успешно" << endl;
				temp.PrintInfo();
				break;
			case 3:
				try {
					temp = -allScore[firstScore];
					temp.PrintInfo();
				}
				catch (exception e) {
					cout << e.what();
					exit(0);
				}
				break;
			case 4:
				allScore[firstScore] += allScore[secondScore];
				cout << "Операция выполнена успешно" << endl;
				allScore[firstScore].PrintInfo();
				break;
			case 5:
				try {
					allScore[firstScore] -= allScore[secondScore];
				}
				catch (exception e) {
					cout << e.what();
					exit(0);
				}
				cout << "Операция выполнена успешно" << endl;
				allScore[firstScore].PrintInfo();
				break;
			case 6:
				a = allScore[firstScore] > allScore[secondScore];
				cout << "Результат - " << a << endl;
				break;
			case 7:
				a = allScore[firstScore] < allScore[secondScore];
				cout << "Результат - " << a << endl;
				break;
			case 8:
				a = allScore[firstScore] >= allScore[secondScore];
				cout << "Результат - " << a << endl;
				break;
			case 9:
				a = allScore[firstScore] <= allScore[secondScore];
				cout << "Результат - " << a << endl;
				break;
			case 10:
				a = allScore[firstScore] == allScore[secondScore];
				cout << "Результат - " << a << endl;
				break;
			case 11:
				a = allScore[firstScore] != allScore[secondScore];
				cout << "Результат - " << a << endl;
				break;
			default:
				cout << "Такой операции не существует." << endl;
				break;
			}
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			if (allScore.empty()) {
				cout << "Счета ещё не созданы." << endl;
				system("pause");
				system("cls");
				break;
			}
			for (int i = 0; i < allScore.size(); i++) {
				cout << "Счёт №" << i << " : ";
				allScore[i].PrintInfo();
			}
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			cout << "Работа приложения завершена.";
			if (!allScore.empty()) {
				for (int i = 0; i < allScore.size(); i++) {
					ofile.write((char*)&allScore[i], sizeof(Score));
				}
			}
			ifile.close();
			ofile.close();
			exit(0);
			break;
		default:
			system("cls");
			cout << "Повторите, введена неверная цифра." << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}


