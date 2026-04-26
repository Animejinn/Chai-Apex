// 236A. Boy or Girl (OverEngineered Solution without STL)

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int marked[27];
    char usrName[101];
    int unChar = 0;
    cin>>usrName;

    for(int i = 0; i <= strlen(usrName); i++)
    {
        if(int('a') <= int(usrName[i]) && int(usrName[i]) <= int('z'))
        {
            for(int k = 0; k <= 27 && i >= 1; k++)
            {
                if(usrName[i] == char(marked[k]))
                {
                    unChar--;
                }
            }
            for(int j = 97; j <= int('z'); j++)
            {
                if(usrName[i] == char(j))
                {
                    for(int l = 0; 0 < i-l && l < 27; l++)
                    {
                        if(marked[i-l] != char(j))
                        {
                            marked[i] = j;
                        }
                    }
                    unChar++;
                }
            }
        }
    }
    if(unChar % 2 == 0)
    {
        cout<<"CHAT WITH HER!";
    }
    else
    {
        cout<<"IGNORE HIM!";
    }
}