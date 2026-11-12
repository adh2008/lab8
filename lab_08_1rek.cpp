
#include <iostream>
#include <string>

using namespace std;

// Рекурсивна перевірка наявності четвірки
bool HasFour(const string& s, int i)
{
    if (i + 3 >= s.length())
        return false;

    if (s[i] == s[i + 1] &&
        s[i] == s[i + 2] &&
        s[i] == s[i + 3])
    {
        return true;
    }

    return HasFour(s, i + 1);
}

// Рекурсивна заміна четвірок
string Change(const string& s, int i)
{
    if (i >= s.length())
        return "";

    if (i + 3 < s.length() &&
        s[i] == s[i + 1] &&
        s[i] == s[i + 2] &&
        s[i] == s[i + 3])
    {
        return "**" + Change(s, i + 4);
    }

    return s[i] + Change(s, i + 1);
}

int main()
{
    string str;

    cout << "Enter string: ";
    getline(cin, str);

    if (HasFour(str, 0))
        cout << "Four identical characters exist." << endl;
    else
        cout << "Four identical characters do not exist." << endl;

    cout << "Modified string: " << Change(str, 0) << endl;

    return 0;
}
