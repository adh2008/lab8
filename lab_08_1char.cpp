
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

// Перевірка наявності четвірки однакових символів
bool HasFour(const char* s)
{
    int len = strlen(s);

    for (int i = 0; i + 3 < len; i++)
    {
        if (strncmp(s + i, s + i + 1, 3) == 0)
            return true;
    }

    return false;
}

// Заміна четвірок однакових символів
void Change(const char* s, char* result)
{
    int len = strlen(s);
    int i = 0;

    result[0] = '\0';

    while (i < len)
    {
        if (i + 3 < len &&
            strncmp(s + i, s + i + 1, 3) == 0)
        {
            strcat(result, "**");
            i += 4;
        }
        else
        {
            char temp[2] = { s[i], '\0' };
            strcat(result, temp);
            i++;
        }
    }
}

int main()
{
    char str[101];
    char result[101];

    cout << "Enter string: ";
    cin.getline(str, 101);

    if (HasFour(str))
        cout << "Four identical characters exist." << endl;
    else
        cout << "Four identical characters do not exist." << endl;

    Change(str, result);

    cout << "Original string: " << str << endl;
    cout << "Modified string: " << result << endl;

    return 0;
}
