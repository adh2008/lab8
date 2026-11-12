
#include <iostream>
#include <string>

using namespace std;

// Перевірка наявності четвірки однакових символів
bool HasFour(const string& s)
{
    size_t pos = 0;

    while ((pos = s.find(s[pos], pos)) != string::npos)
    {
        if (pos + 3 < s.length() &&
            s[pos] == s[pos + 1] &&
            s[pos] == s[pos + 2] &&
            s[pos] == s[pos + 3])
        {
            return true;
        }

        pos++;
    }

    return false;
}

// Заміна четвірок однакових символів
string Change(string s)
{
    size_t pos = 0;

    while (pos + 3 < s.length())
    {
        if (s[pos] == s[pos + 1] &&
            s[pos] == s[pos + 2] &&
            s[pos] == s[pos + 3])
        {
            s.replace(pos, 4, "**");
            pos += 2;
        }
        else
        {
            pos++;
        }
    }

    return s;
}

int main()
{
    string str;

    cout << "Enter string: ";
    getline(cin, str);

    if (HasFour(str))
        cout << "Four identical characters exist." << endl;
    else
        cout << "Four identical characters do not exist." << endl;

    string dest = Change(str);

    cout << "Original string: " << str << endl;
    cout << "Modified string: " << dest << endl;

    return 0;
}
