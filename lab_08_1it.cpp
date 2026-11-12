
#include <iostream>
#include <string>

using namespace std;

// Перевірка наявності четвірки однакових символів
bool HasFour(const string& s)
{
    for (int i = 0; i + 3 < s.length(); i++)
    {
        if (s[i] == s[i + 1] &&
            s[i] == s[i + 2] &&
            s[i] == s[i + 3])
        {
            return true;
        }
    }

    return false;
}

// Заміна четвірок однакових символів
string Change(string s)
{
    string result;
    int i = 0;

    while (i < s.length())
    {
        if (i + 3 < s.length() &&
            s[i] == s[i + 1] &&
            s[i] == s[i + 2] &&
            s[i] == s[i + 3])
        {
            result += "**";
            i += 4;
        }
        else
        {
            result += s[i];
            i++;
        }
    }

    return result;
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

    cout << "Modified string: " << Change(str) << endl;

    return 0;
}
