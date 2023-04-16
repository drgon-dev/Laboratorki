#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>
using namespace std;
int hashh(string a)
{
	float b = 0;
	for (int i = 0; a[i] != '\0'; i++)
	{
		b += a[i]*(-1);
	}
	b =b * 0.14;
	while (b >= 1)
		b--;
	b *= 10;
	b = (int)b;
	return b;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int count = 0,help; string hasht[10], temp;
	for (int i = 0; i < 10; i++)
		hasht[i] = "NULL";
	for (int i = 0; i < 10; i++)
	{
		cin >> temp;
		if (hasht[hashh(temp)] != "NULL")
		{
			hasht[hashh(temp)] = temp;
		}
		else
		{
			count++;
			help = hashh(temp);
			while ((hasht[help] != "NULL")&&(help!=9))
				help++;
			hasht[help] = temp;
		}
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
		cout << hasht[i] << endl;
	cout << endl << count;
	return 0;
}