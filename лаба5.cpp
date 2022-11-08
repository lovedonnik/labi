#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	string s;
	while (getline(fin, s)) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				if (s[i + 1] == 'a' || s[i + 1] == 'e' || s[i + 1] == 'i' || s[i + 1] == 'o' || s[i + 1] == 'u' || s[i + 1] == 'y' || s[i + 1] == 'A' || s[i + 1] == 'E' || s[i + 1] == 'I' || s[i + 1] == 'O' || s[i + 1] == 'U' || s[i + 1] == 'Y') {
					int j = i + 1;
					while (s[j] != ' ' && j < s.length()) {
						fout << s[j];
						j++;
					}
					fout << endl;
				}
			}
		}
	}
	return 0;
	
	fin.close();
	fout.close();
	echo "# labi" >> README.md
		git init
		git add README.md
		git commit - m "first commit"
		git branch - M main
		git remote add origin https ://github.com/lovedonnik/labi.git
	git push - u origin main
}
