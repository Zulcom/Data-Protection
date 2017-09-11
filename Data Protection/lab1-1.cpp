#include <iostream>
#include <string>
#include <windows.h>


using namespace std;

int latin() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "������� ������:" << endl;
	string s;

	getline(cin, s); // ������ �� ������� 
	for (char current_char : s) // ����� �� ������
	{
		if (current_char == ' ') // ���� ������
		{
			cout << "\*������\*" << endl;
			continue;
		}
		int num;
		tolower(current_char);
		num = current_char >= 'j' ? current_char - 1 : current_char; //���� ������ ������ "j" � ��������, �� ������� ��� �������
		num = num - 'a'; // �������� �� ������ ������� ����� ������� �, ����� �������� ��������� �� 1 �� 32
		cout << num / 5 + 1 << " " << num % 5 + 1 << endl; // �� ����������� ������� ������� ����� ����� ������� � ������ � �������
	}
	system("pause");
	return 0;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "�������� ��� ���������?(l/c)";
	char ch;
	cin >> ch;
	cin.ignore(10, '\n');
	if (ch == 'l')
	{
		latin();
		return 0;
	}

	cout << "����������?(y/n): ";
	cin >> ch;
	bool choice = ch == 'y';
	cin.ignore(10, '\n');
	cout << "������� ������ �� ���������:" << endl;
	string s;

	getline(cin, s); // ������ �� ������� 
	for (char current_char: s) // ����� �� ������
	{
		if (current_char == ' ') // ���� ������
		{
			cout << "\*������\*" << endl;
			if (choice) Beep(261, 2000);
			continue;
		}
		int num;
		if (current_char >= '�' && current_char <= '�') current_char = current_char - '�' + '�'; // ��������� � ������ �������
		if (current_char > '�') num = current_char + 1; //���� ������ ������ "�" � ��������, �� ������� ��� �������
		else if (current_char == '�' || current_char == '�') num = '�' + 1; // ���� ������� ������ "�", ����� ��� ����� �+1
		else num = current_char; // ����� ������� ������ ����� � � �, ��� ������ �� ��������
		num = num - '�'; // �������� �� ������ ������� ����� ������� �, ����� �������� ��������� �� 1 �� 32
		cout << num / 6 + 1 << " " << num % 6 + 1 << endl; // �� ����������� ������� ������� ����� ����� ������� � ������ � �������
		if (!choice) continue;
		for (int i = 0; i < num / 6 + 1; ++i) Beep(293, 1000); // �������� �� ������
		Sleep(1 * 1000); // �������
		for (int i = 0; i < num % 6 + 1; ++i) Beep(329, 350); // �������� �� �������
		Sleep(1 * 1000); // ��� �������
	}
	system("pause");
}
