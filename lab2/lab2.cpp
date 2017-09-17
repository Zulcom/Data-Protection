#include <iostream>
#include <string>
#include <cctype>
#include <clocale>

using namespace std;

#define alphabetSize 26
#define startFrom 'A'

void fillAlphabet(char alphabet[alphabetSize][alphabetSize])
{
	char t = startFrom + alphabetSize;
	for(char a = startFrom; a < t; a++)
	{
		alphabet[0][(int) a - 65] = a;
	}
	for(int i = 1; i < alphabetSize; i++)
	{
		for(int j = 0; j < alphabetSize; j++)
		{
			if(i + j >= alphabetSize)
			{
				int overflow = (i + j) - alphabetSize;
				alphabet[i][j] = alphabet[0][overflow];
			}
			else
			{
				alphabet[i][j] = alphabet[0][i + j];
			}
		}
	}
}

void showAlphabet(char alphabet[alphabetSize][alphabetSize])
{
	cout << endl;
	cout << ' ' << ' ';
	for(int i = 0; i < alphabetSize; i++)
	{
		cout << alphabet[0][i] << ' ';
	}
	cout << endl;

	for(int i = 0; i < alphabetSize; i++)
	{
		cout << alphabet[0][i] << ' ';
		for(int j = 0; j < alphabetSize; j++)
		{
			cout << alphabet[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

string cypherMsg1(string msg, int cypher)
{
	int msgSize = msg.size(), cypher1 = cypher;
	for(int i = 0; i < msgSize; i++)
	{
		if(cypher1 % 10 != 0)
		{
			msg[i] = (int) msg[i] + (cypher1 % 10);
			cypher1 /= 10;
		}
		else
		{
			cypher1 = cypher;
			msg[i] = (int) msg[i] + (cypher1 % 10);
		}
		cypher1 /= 10;
	}
	return msg;
}

string cypherMsg2(string msg1, string msg2, char alphabet[alphabetSize][alphabetSize])
{
	int msgSize1 = msg1.size(), msgSize2 = msg2.size(), j = 0, k, t, y;
	for(int i = 0; i < msgSize2; i++)
	{
		t = (int) toupper(msg1[j]);
		y = (int) toupper(msg2[i]);
		k = (t + y) % alphabetSize;
		msg2[i] = alphabet[0][k];
		if(msgSize1 - 1 == j)
		{
			j = 0;
		}
		else
		{
			j++;
		}
	}
	return msg2;
}

string deCypherMsg2(string msg1, string msg2, char alphabet[alphabetSize][alphabetSize])
{
	int msgSize1 = msg1.size(), msgSize2 = msg2.size(), j = 0, k, t, y;
	for(int i = 0; i < msgSize2; i++)
	{
		t = (int) toupper(msg1[j]);
		y = (int) toupper(msg2[i]);
		k = (y - t + alphabetSize) % alphabetSize;
		msg2[i] = alphabet[0][k];
		if(msgSize1 - 1 == j)
		{
			j = 0;
		}
		else
		{
			j++;
		}
	}
	return msg2;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char alphabet[alphabetSize][alphabetSize];
	string msg1, msg2;
	int cypher;
	cout << "Введите ключ, сообщение и сдвиг: ";
	while(!(cin >> msg1 >> msg2 >> cypher))
	{
		cin.ignore();
		cin.clear();
		cout << "Wrong input, try again: ";
	}
	fillAlphabet(alphabet);
	showAlphabet(alphabet);
	msg1 = cypherMsg1(msg1, cypher);
	cout << endl << "Закодированный ключ: " << msg1 << endl;
	msg2 = cypherMsg2(msg1, msg2, alphabet);
	cout << endl << "Закодированное сообщение: " << msg2 << endl;
	msg2 = deCypherMsg2(msg1, msg2, alphabet);
	cout << endl << "Раскодированное сообщение: " << msg2 << endl;
	system("pause");
	return 0;
}
