//Задание.Написать программу, которая записывает с клавиатуры в файл структуру согласно выданному варианту задания.В качестве разделителя полей структуры использовать символ табуляции.В программе реализовать :
//а) дополнение существующего массива структур новыми структурами;
//б) поиск структуры с заданным значением выбранного элемента;
//в) вывод на экран содержимого массива структур;
//г) упорядочение массива структур по заданному полю(элементу), например государство по численности.
//2. «Покупатель»: фамилия, имя, отчество, город, улица, номер дома, номер квартиры, номер кредитной карточки, код покупки.

#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

struct Buyer
{
	char surname[20];
	char name[20];
	char patronymic[30];
	char city[20];
	char street[20];
	int house;
	int flat;
	int creditCard;
	int code;
};

void addBuyer(Buyer* buyer, int& count)
{
	cout << "Enter surname: ";
	cin >> buyer[count].surname;
	cout << "Enter name: ";
	cin >> buyer[count].name;
	cout << "Enter e-mail: ";
	cin >> buyer[count].patronymic;
	cout << "Enter city: ";
	cin >> buyer[count].city;
	cout << "Enter street: ";
	cin >> buyer[count].street;
	cout << "Enter house: ";
	cin >> buyer[count].house;
	cout << "Enter flat: ";
	cin >> buyer[count].flat;
	cout << "Enter credit card: ";
	cin >> buyer[count].creditCard;
	cout << "Enter code: ";
	cin >> buyer[count].code;
	count++;
}

void printBuyer(Buyer* buyer, int& count)
{
	for (int i = 0; i < count; i++)
	{
		cout << endl << "Surname: " << buyer[i].surname << endl;
		cout << "Name: " << buyer[i].name << endl;
		cout << "Patronymic: " << buyer[i].patronymic << endl;
		cout << "City: " << buyer[i].city << endl;
		cout << "Street: " << buyer[i].street << endl;
		cout << "House: " << buyer[i].house << endl;
		cout << "Flat: " << buyer[i].flat << endl;
		cout << "Credit card: " << buyer[i].creditCard << endl;
		cout << "Code: " << buyer[i].code << endl;
		cout << endl;
	}
}

void searchBuyer(Buyer* buyer, int& count)
{
	char surname[20];
	cout << "Enter surname: ";
	cin >> surname;
	for (int i = 0; i < count; i++)
	{
		if (strcmp(buyer[i].surname, surname) == 0)
		{
			cout << "Surname: " << buyer[i].surname << endl;
			cout << "Name: " << buyer[i].name << endl;
			cout << "Patronymic: " << buyer[i].patronymic << endl;
			cout << "City: " << buyer[i].city << endl;
			cout << "Street: " << buyer[i].street << endl;
			cout << "House: " << buyer[i].house << endl;
			cout << "Flat: " << buyer[i].flat << endl;
			cout << "Credit card: " << buyer[i].creditCard << endl;
			cout << "Code: " << buyer[i].code << endl;
		}
	}
}

void sortBuyer(Buyer* buyer, int& count)
{
	Buyer temp;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (buyer[j].code > buyer[j + 1].code)
			{
				temp = buyer[j];
				buyer[j] = buyer[j + 1];
				buyer[j + 1] = temp;
			}
		}
	}
}

void saveBuyer(Buyer* buyer, int& count)
{
	ofstream fout("Buyer.txt");
	for (int i = 0; i < count; i++)
	{
		fout << "Surname: " << buyer[i].surname << endl;
		fout << "Name: " << buyer[i].name << endl;
		fout << "Patronymic: " << buyer[i].patronymic << endl;
		fout << "City: " << buyer[i].city << endl;
		fout << "Street: " << buyer[i].street << endl;
		fout << "House: " << buyer[i].house << endl;
		fout << "Flat: " << buyer[i].flat << endl;
		fout << "Credit card: " << buyer[i].creditCard << endl;
		fout << "Code: " << buyer[i].code << endl;
	}
	fout.close();
}

void loadBuyer(Buyer* buyer, int& count)
{
	ifstream fin("Buyer.txt");
	for (int i = 0; i < count; i++)
	{
		fin >> buyer[i].surname;
		fin >> buyer[i].name;
		fin >> buyer[i].patronymic;
		fin >> buyer[i].city;
		fin >> buyer[i].street;
		fin >> buyer[i].house;
		fin >> buyer[i].flat;
		fin >> buyer[i].creditCard;
		fin >> buyer[i].code;
	}
	fin.close();
}

int main()
{
	Buyer* buyer = new Buyer[100];
	int count = 0;
	int choice;
	do
	{
		cout << "1. Add buyer" << endl;
		cout << "2. Print buyer" << endl;
		cout << "3. Search buyer" << endl;
		cout << "4. Sort buyer" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			addBuyer(buyer, count);
			break;
		case 2:
			printBuyer(buyer, count);
			break;
		case 3:
			searchBuyer(buyer, count);
			break;
		case 4:
			sortBuyer(buyer, count);
			break;
		}
		system("pause");
		system("cls");
	} while (choice != 5);
	return 0;
}

