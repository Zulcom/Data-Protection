#include <iostream>
#include <string>
#include <windows.h>


using namespace std;

int latin() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите строку:" << endl;
	string s;

	getline(cin, s); // читаем всё введёное 
	for (char current_char : s) // бежим по строке
	{
		if (current_char == ' ') // если пробел
		{
			cout << "\*Пробел\*" << endl;
			continue;
		}
		int num;
		tolower(current_char);
		num = current_char >= 'j' ? current_char - 1 : current_char; //если символ дальше "j" в алфавите, то накинем ему единицу
		num = num - 'a'; // вычитаем из номера символа номер символа а, чтобы получить счислеине от 1 до 32
		cout << num / 5 + 1 << " " << num % 5 + 1 << endl; // по специальной формуле считаем номер этого символа в строке и столбце
	}
	system("pause");
	return 0;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Латиница или кириллица?(l/c)";
	char ch;
	cin >> ch;
	cin.ignore(10, '\n');
	if (ch == 'l')
	{
		latin();
		return 0;
	}

	cout << "Озвучивать?(y/n): ";
	cin >> ch;
	bool choice = ch == 'y';
	cin.ignore(10, '\n');
	cout << "Введите строку на кириллице:" << endl;
	string s;

	getline(cin, s); // читаем всё введёное 
	for (char current_char: s) // бежим по строке
	{
		if (current_char == ' ') // если пробел
		{
			cout << "\*Пробел\*" << endl;
			if (choice) Beep(261, 2000);
			continue;
		}
		int num;
		if (current_char >= 'А' && current_char <= 'Я') current_char = current_char - 'А' + 'а'; // переводим в нижний регистр
		if (current_char > 'е') num = current_char + 1; //если символ дальше "Е" в алфавите, то накинем ему единицу
		else if (current_char == 'ё' || current_char == 'Ё') num = 'е' + 1; // если текущий символ "Ё", выдаём ему номер е+1
		else num = current_char; // иначе текущий символ между а и е, там ничего не меняется
		num = num - 'а'; // вычитаем из номера символа номер символа а, чтобы получить счислеине от 1 до 32
		cout << num / 6 + 1 << " " << num % 6 + 1 << endl; // по специальной формуле считаем номер этого символа в строке и столбце
		if (!choice) continue;
		for (int i = 0; i < num / 6 + 1; ++i) Beep(293, 1000); // пиликаем на строки
		Sleep(1 * 1000); // подождём
		for (int i = 0; i < num % 6 + 1; ++i) Beep(329, 350); // пиликаем на столбцы
		Sleep(1 * 1000); // ещё подождём
	}
	system("pause");
}
