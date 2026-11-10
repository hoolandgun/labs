#include <iostream>
#include <string>

using namespace std;

int Count(const string s)
{
    int k = 0;
    size_t pos = 0;

    while (true)
    {
        size_t posOGO = s.find("OGO", pos);
        size_t posAGA = s.find("AGA", pos);

        if (posOGO == string::npos && posAGA == string::npos)
            break;

        if (posOGO != string::npos && (posAGA == string::npos || posOGO < posAGA))
            pos = posOGO;
        else
            pos = posAGA;

        k++;
        pos++;
    }
    return k;
}

string Change(string& s)
{
    size_t pos = 0;
    while (true)
    {
        size_t posOGO = s.find("OGO", pos);
        size_t posAGA = s.find("AGA", pos);

        if (posOGO == string::npos && posAGA == string::npos)
            break;

        if (posOGO != string::npos && (posAGA == string::npos || posOGO < posAGA))
            pos = posOGO;
        else
            pos = posAGA;

        s.replace(pos, 3, "**");
        pos += 2; 
    }
    return s;
}

int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    cout << "String contained " << Count(str) << " groups of 'OGO' or 'AGA'" << endl;

    string dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}