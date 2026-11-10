#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Рекурсивна функція підрахунку (з передачею i=1, як у методичці)
int Count(char* str, int i)
{
	if (strlen(str) < 3)
		return 0;

	if (str[i + 1] != 0)
	{
		if ((str[i - 1] == 'O' && str[i] == 'G' && str[i + 1] == 'O') ||
			(str[i - 1] == 'A' && str[i] == 'G' && str[i + 1] == 'A'))
			return 1 + Count(str, i + 1);
		else
			return Count(str, i + 1);
	}
	else
		return 0;
}

// Рекурсивна функція заміни
char* Change(char* dest, const char* str, char* t, int i)
{
	if (str[i + 2] != 0)
	{
		if ((str[i] == 'O' && str[i + 1] == 'G' && str[i + 2] == 'O') ||
			(str[i] == 'A' && str[i + 1] == 'G' && str[i + 2] == 'A'))
		{
			strcat(t, "**");
			return Change(dest, str, t + 2, i + 3);
		}
		else
		{
			*t = str[i];
			*(t + 1) = '\0';
			return Change(dest, str, t + 1, i + 1);
		}
	}
	else
	{
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
}

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);

	cout << "String contained " << Count(str, 1) << " groups of 'AGA' or 'OGO'" << endl;

	char* dest1 = new char[151];
	dest1[0] = '\0';

	char* dest2 = Change(dest1, str, dest1, 0);

	cout << "Modified string (param) : " << dest1 << endl;
	cout << "Modified string (result): " << dest2 << endl;

	return 0;
}