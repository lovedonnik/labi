/*
Индивидуальное творческое задание
Вариант 1:

Отчет:
Перечислить услуги, предоставленные указанному клиенту в заданном диапазоне времени ( с…   по  …)

Параметры:
ФИО клиента, дата начала диапазона, дата конца диапазона

*/

#include <iostream>
#include <ctime>
#include <fstream>я
#include <Windows.h>

void Rez();
using namespace std;
const int a = 500;

struct clients
{
	char people[a];//ФИО - char[] массив символов
	int64_t number;//номер телефона
	char conn[a];//дата
	char disconn[a];//дата
	int64_t duty;//задолжность
	int64_t credite;//кредит
}clients[10]{};

struct info
{
	int64_t phone;//номер телефона
	int64_t Pcode;//код
	int64_t Pday;//день
	int64_t Pmonth;//месяц
	int64_t Pyear;//год
	char Ptime[a];//время
	int64_t Punit;//время использования
} info[10]{};

struct services
{
	char service[a];//название
	int64_t code;//код
	int64_t cost;//тариф
	char data[a];//интервал
} services[10]{};

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	FILE* first;
	if (fopen_s(&first, "clients.txt", "r") == 0) {
		for (int i = 0; i < 10; i++) {
			fscanf_s(first,
				// %500[^,] - Прочитать как строку максимум 500 символов до ,
				// %d - Прочитать целое число
				"%500[^,], %d, %500[^,], %500[^,], %d, %d \n",
				clients[i].people, a,
				&clients[i].number,
				clients[i].conn, a,
				clients[i].disconn, a,
				&clients[i].duty,
				&clients[i].credite
			);
		}
		fclose(first);
	}
	else {
		cout << "Отсутствуют данные о клиентах." << endl;
		return -1;
	}
	FILE* second;
	if (fopen_s(&second, "info.txt", "r") == 0) {
		for (int i = 0; i < 10; i++) {
			fscanf_s(second, "%d, %d, %d.%d.%d %500[^,], %d \n",
				&info[i].phone,
				&info[i].Pcode,
				&info[i].Pday,
				&info[i].Pmonth,
				&info[i].Pyear,
				info[i].Ptime, a,
				&info[i].Punit
			);
		}
		fclose(second);
	}
	else {
		cout << "Отсутствуют используемые услуги." << endl;
		return -2;
	}
	FILE* third;
	if (fopen_s(&third, "services.txt", "r") == 0) {
		for (int i = 0; i < 10; i++) {
			fscanf_s(third,
				"%500[^,], %d, %d, %500[^\n] \n",
				services[i].service, a,
				&services[i].code,
				&services[i].cost,
				services[i].data, a
			);
		}
		fclose(third);
	}
	else {
		cout << "Отсутствует информация об услугах." << endl;
		return -3;
	}
	Rez(); // Вызывает выполнение функции Rez
	return 0;
}

/*
	ФИО клиента,
	дата начала диапазона,
	дата конца диапазона
*/
void Rez()
{
	FILE* param;
	fopen_s(&param, "param.txt", "r");
	char fio[a];
	int64_t num;
	fscanf_s(
		param,
		"%500[^\n]\n",
		fio, a
	);
	for (int i = 0; i < 10; i++) {
		if (strcmp(clients[i].people, fio) == 0) {
			num = clients[i].number;
			break;
		}
	}
	time_t tt = time(0);
	tm b[2];
	for (int i = 0; i < 2; i++) {
		localtime_s(&b[i], &tt);
		fscanf_s(
			param,
			"%d.%d.%d\n",
			&b[i].tm_mday,
			&b[i].tm_mon,
			&b[i].tm_year
		);
		b[i].tm_year = b[i].tm_year - 1900;
		b[i].tm_mon = b[i].tm_mon - 1;
	}

	time_t begin_u = mktime(&b[0]);
	time_t end_u = mktime(&b[1]);
	tm tr;
	time_t r;
	localtime_s(&tr, &tt);
	ofstream fout("Report.txt");
	// Прохождение по списку услуг
	for (int i = 0; i < 10; i++) {
		// Прохождение по списку использованных услуг
		bool t = false;
		for (int j = 0; j < 10; j++) {
			if (info[j].phone == num && info[j].Pcode == services[i].code) {
				tr.tm_year = info[j].Pyear - 1900;
				tr.tm_mon = info[j].Pmonth - 1;
				tr.tm_mday = info[j].Pday;
				r = mktime(&tr);
				if (begin_u <= r && r <= end_u) {
					t = true;
					break;
				}
			}
		}
		if (t) {
			fout << services[i].service << '\n';
		}
	}
	fout.close();
	fclose(param);
}