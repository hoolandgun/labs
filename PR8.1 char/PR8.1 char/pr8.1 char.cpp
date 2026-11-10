#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(char* s)
{
	int k = 0, pos = 0;
	char* t;

	while ((t = strstr(s + pos, "OGO")) || (t = strstr(s + pos, "AGA")))
	{
		char* t1 = strstr(s + pos, "OGO");
		char* t2 = strstr(s + pos, "AGA");

		if (t1 && t2)
			t = (t1 < t2) ? t1 : t2;
		else if (t1)
			t = t1;
		else
			t = t2;

		pos = t - s + 1; 
		k++;
	}
	return k;
}

char* Change(char* s)
{
	char* t = new char[strlen(s) + 1];
	char* p;
	int pos1 = 0, pos2 = 0;
	*t = 0;

	while ((p = strstr(s + pos1, "OGO")) || (p = strstr(s + pos1, "AGA")))
	{
		char* p1 = strstr(s + pos1, "OGO");
		char* p2 = strstr(s + pos1, "AGA");

		if (p1 && p2)
			p = (p1 < p2) ? p1 : p2;
		else if (p1)
			p = p1;
		else
			p = p2;

		pos2 = p - s;
		strncat(t, s + pos1, pos2 - pos1);
		strcat(t, "**"); 
		pos1 = pos2 + 3; 
	}

	strcat(t, s + pos1); 
	strcpy(s, t);        
	return t;
}

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);

	cout << "String contained " << Count(str) << " groups of 'OGO' or 'AGA'" << endl;

	char* dest = Change(str);

	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

	return 0;
}