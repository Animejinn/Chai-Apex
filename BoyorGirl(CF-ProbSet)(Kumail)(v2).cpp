// 236A. Boy or Girl (CodeForces Preferred Solution with STL)

#include<bits/stdc++.h>

using namespace std;

int main()
{
    char usrName[101];
    cin >> usrName;

    set<char> uniqueChars;
    for(int i = 0; i < strlen(usrName); i++)
    {
        uniqueChars.insert(usrName[i]);
    }

    if(uniqueChars.size() % 2 == 0)
    {
        cout << "CHAT WITH HER!";
    }
    else
    {
        cout << "IGNORE HIM!";
    }
}