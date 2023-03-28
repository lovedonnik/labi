#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

const int MAX = 1000;
char stack[MAX];
char str[MAX];
int tos = 0;

void push(int i) { // Затолкать элемент в стек
	setlocale(LC_ALL, "Rus");
	if (tos >= MAX) {
		cout << "Стек полон" << endl;
		return;
	}
	stack[tos] = i;
	tos++;
}

int pop(void) {
	tos--;
	if (tos < 0) {
		cout << "Стек пуст." << endl;
		return 0;
	}
	return stack[tos];
}

int Priority(char b) {
	int pr = 0;
	if (b == '(') { pr = 0; }
	else if (b == ')') { pr = 1; }
	else if (b == '+' || b == '-') { pr = 2; }
	else if (b == '*' || b == '/') { pr = 3; }
	return pr;
}

void main_func(FILE* read, FILE* write, int& pr1, int& pr2, char& help)
{
	while (!feof(read))
	{
		fgets(str, 999, read);
		int size = strlen(str);

		for (int i = 0; i < size; ++i)
		{
			if (str[i] == '\n')
			{
				while (tos > 0)
				{
					fprintf(write, "%c", pop());
				}
				fprintf(write, "\n");
			}
			else if (str[i] != '(' && str[i] != ')' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')
				fprintf(write, "%c", str[i]);

			else
			{
				if (tos == 0)
				{
					pr2 = Priority(str[i]);
					push(str[i]);
				}
				else
				{
					pr2 = Priority(str[tos - 1]);
					pr1 = Priority(str[i]);


					if (str[i] == '(')
					{
						push(str[i]);
					}
					else if (str[i] == ')')
					{
						while ((help = pop()) != '(')
							fprintf(write, "%c", help);
					}

					else {

						if (pr1 < pr2)
							push(str[i]);

						else {
							while (pr1 <= Priority(stack[tos - 1]) && tos > 0)
								fprintf(write, "%c", pop());

							push(str[i]);
						}
					}
				}
			}
		}
	}
}

int main() {



	FILE* read;
	errno_t err = fopen_s(&read, "input.txt", "r");
	if (err != 0)
	{
		cout << "Не удалось открыть файл для чтения. \n" << err;
		return 1; // выход из программы с кодом ошибки
	}

	FILE* write;
	err = fopen_s(&write, "out.txt", "w");
	if (err != 0)
	{
		cout << "Не удалось открыть файл для записи \n" << err;
		fclose(read); // закрытие файла, открытого на чтение
		return 1; // выход из программы с кодом ошибки
	}

	// код для чтения данных из файла и записи в другой файл

	

	int pr1, pr2;
	char help;


	main_func(read, write, pr1,pr2, help);

	fclose(read); // закрытие файла, открытого на чтение
	fclose(write); // закрытие файла, открытого на запись

	return 0;
}

