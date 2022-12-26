#include <iostream>
#include <bitset>
#include <climits>

using namespace std;

int main ()
{
    setlocale(LC_ALL, "Rus");
    string str;
    cout << "Введите число: ";
    cin >> str;
    if (str.length() == 8) {

        cout << "Конечное число: ";
        cout << str[0] << str[3] << str[2] << str[1] << str[6] << str[7] << str[4] << str[5];
        
    }
    else {
        cout << "Ваше число содержит больше или меньше 4 байт.";
    }


}