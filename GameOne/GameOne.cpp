#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int MAX_ERROR = 8;
	vector<string> words;
	words.push_back("КАКАШКА");
	words.push_back("ЛАПКА"); 
	words.push_back("НОСОК"); 
	words.push_back("ДОРОГА");
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string WordGame = words[0];
	int error = 0;
	string soFar(WordGame.size(), '-');
	string used = "";//відгаданні букви
	cout << "Добро пожаловать в игру Виселица" <<endl;
	while (error < MAX_ERROR && (soFar != WordGame))
	{
		cout << "\nВ тебе залишилось " << (MAX_ERROR - error) << " спроб" << endl;
		cout << "Ти уже вводив ці букви : " << used << endl;
		cout << "Слово на даний момент: " << soFar << endl;
		char guess;
		cout << "Введи букву: ";
		cin >> guess;
		guess = toupper(guess);//перехід до верхнього регістру.
		while (used.find(guess) != string::npos)
		{
			cout << "Ти вже ввів бувку " << guess<< endl;
			cout << "Введи іншу букву: " ;
			cin >> guess;
			guess = toupper(guess);
		}
		used += guess;
		if (WordGame.find(guess) != string::npos)
		{
			cout << "Ура!" << guess << " є в слові!" << endl;
			for (int i = 0; i < WordGame.length(); i++)
			{
				if (WordGame[i] == guess)
					soFar[i] = guess;
			}
		}
		else
		{
			cout << "Упс...Букви " << guess << " немає в слові!" << endl;
			error++;
		}
		system("cls");
	}
	if (error == MAX_ERROR)
	{
		cout << "Ти повішаний!" << endl;
	}
	else
	{
		cout << "Вітаємо ти переміг!"<<endl;
	}
	cout << "Загадане слово було - " << WordGame << endl;
	system("pause");
	return 0;
}