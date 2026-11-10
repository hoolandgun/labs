#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(char* str)
{
	if (strlen(str) < 3)
		return 0;

	int k = 0;
	for (int i = 1; str[i + 1] != 0; i++)
		if ((str[i - 1] == 'O' && str[i] == 'G' && str[i + 1] == 'O') ||
			(str[i - 1] == 'A' && str[i] == 'G' && str[i + 1] == 'A'))
			k++;

	return k;
}

char* Change(char* str)
{
	size_t len = strlen(str);
	if (len < 3)
		return str;

	char* tmp = new char[len + 1];
	char* t = tmp;
	tmp[0] = '\0';

	size_t i = 0;
	while (i < len && str[i + 2] != 0)
	{
		if ((str[i] == 'O' && str[i + 1] == 'G' && str[i + 2] == 'O') ||
			(str[i] == 'A' && str[i + 1] == 'G' && str[i + 2] == 'A'))
		{
			strcat(t, "**");
			t += 2;
			i += 3;
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
		}
	}

	while (i < len)
	{
		*t++ = str[i++];
	}
	*t = '\0';

	strcpy(str, tmp);
	return tmp;
}
#ifndef LINK_TEST
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);

	cout << "String contained " << Count(str) << " groups of 'OGO' or 'AGA'" << endl;
	char* dest = Change(str);

	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	delete[] dest;
	return 0;
}
#endif