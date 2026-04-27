#include<bits/stdc++.h>

using namespace std;

int main()
{
    char word[1000];
    cin>>word;
    if(int('a') <= int(word[0]) && int(word[0]) <= int('z'))
    {
        word[0] = char(word[0]-32);
        cout<<word;
    }
    else
    {
        cout<<word;
    }
}