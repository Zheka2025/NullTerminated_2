#include<iostream>
#include<windows.h>
using namespace std;

void InputLine(char str[], const int n);
int StrLen(char str[]);
void UpperCase(char str[]); //Переводит строку в верхний регистр.
void LowerCase(char str[]); //Переводит строку в нижний регистр.
void Capitalize(char str[]); // Первую букву каждого слова в предложении делает заглавной.
void Shrink(char str[]); // Удаляет лишние пробелы между слов в предложении.
void RemoveSpaces(char str[]); // Удаляяет все пробелы в предложенни.
bool isPalindrome(char str[]); // Опрудиляет, является ли строка полиндромом.
void srink_to_fit(char str[]); // Удаляет лишние байты после конца строки. (требуется переопредиление памяти).
bool is_number(char str[]); // Опредуляет, является ли строка числом.

void main()
{
	setlocale(LC_ALL, "rus");
	////char str[] = { 'H', 'e', 'l', 'l', 'o', '\0'};
	//char msg[] = "Hello";
	//cout << sizeof(msg) << endl;
	//cout << msg << endl;

	const int n = 256;
	char str[n] = {};
	cout << "Введите строку: ";
	//cin >> str;
	InputLine(str, n);
	cout << str << endl;
	/*cout << StrLen(str) << endl;
	UpperCase(str);
	cout << str << endl;
	LowerCase(str);
	cout << str << endl;
	Capitalize(str);
	cout << str << endl;
	Shrink(str);
	cout << str << endl;
	RemoveSpaces(str);
	cout << str << endl;*/
	cout << "Проверка на полиндром: " << endl;
	cout << isPalindrome(str) << endl;
	cout << str << endl;
	cout << "Проверка на число: " << endl;
	cout << is_number(str) << endl;
	cout << str << endl;
}

void InputLine(char str[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866);
}

int StrLen(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void UpperCase(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z' ||
			str[i] >= 'а' && str[i] <= 'я'
			)
			str[i] -= 32;
	}
}

void LowerCase(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' ||
			str[i] >= 'А' && str[i] <= 'Я'
			)
			str[i] += 32;
	}
}

void Capitalize(char str[])
{
	if (str[0] >= 'a' && str[0] <= 'z' ||
		str[0] >= 'а' && str[0] <= 'я'
		)
		str[0] -= 32;
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z' ||
			str[i] >= 'а' && str[i] <= 'я'
			) && str[i - 1] == ' '
			)
			str[i] -= 32;
	}
}

void Shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}

void RemoveSpaces(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i] == ' ')
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}

void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}

bool isPalindrome(char str[])
{
	int n = StrLen(str);
	char* buffer = new char[n + 1]{};
	for (int i = 0; str[i]; i++)buffer[i] = str[i];
	LowerCase(buffer);
	RemoveSpaces(buffer);
	n = StrLen(buffer);
	cout << buffer << endl;
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			return false;
		}
	}
	return true;
}

bool is_number(char str[])
{
	int n = StrLen(str);
	char* buffer = new char[n + 1]{};
	for (int i = 0; i < n; i++)buffer[i] = str[i];
	RemoveSpaces(buffer);
	cout << buffer << endl;
	//remove_symbol(buffer, '.');
	auto is_digit = [](char symbol)->bool {return symbol >= '0' && symbol <= '9' ? true : false; };
	bool contain_point = false;
	for (int i = buffer[0] == '+' || buffer[0] == '-' ? 1 : 0; buffer[i]; i++)
	{
		if ((buffer[i] == '.' || buffer[i] == ',') && is_digit(buffer[i - 1]) && is_digit(buffer[i + 1]) && !contain_point)
		{
			contain_point = true;
			continue;
		}
		//if (buffer[i] < '0' || buffer[i] > '9')	return false;
		if (!is_digit(buffer[i]))
			return false;
	}
	return true;
}

