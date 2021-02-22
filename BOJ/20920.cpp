#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int d[100000] = {};

typedef struct
{
    int count;
    string str;
} STR;
STR strtmp[100001];

int cmp(string s1, string s2)
{
    return s1 < s2;
}

int cmp2(STR str1, STR str2)
{
    if (str1.count > str2.count)
        return 1;
    else if (str1.count < str2.count)
        return 0;
    else
    {
        if (str1.str.length() > str2.str.length())
            return 1;
        else if (str1.str.length() == str2.str.length())
            return str1.str < str2.str;
        else
            return 0;
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str[100001];
    int n, m, count = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        if (tmp.length() >= m)
            str[count++] = tmp;
    }
    sort(str, str + count, cmp);
    int count2 = 0;
    strtmp[0].str = str[0];
    strtmp[0].count = 1;
    for (int i = 0; i < count; i++)
    {
        if (i + 1 < count && strtmp[count2].str == str[i] && str[i] == str[i + 1])
            strtmp[count2].count++;
        else
        {
            strtmp[++count2].str = str[i + 1];
            strtmp[count2].count = 1;
        }
    }
    sort(strtmp, strtmp + count2, cmp2);
    for (int i = 0; i <= count2; i++)
        cout << strtmp[i].str << "\n";
}