// 112A. Petya and Strings 

#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char word1[101];
    char word2[101];    
    int diff = 0;
    cin>>word1;
    cin>>word2;

    if(strlen(word1) <= 100 && strlen(word2) <= 100)
    {
        for(int i = 0; i < strlen(word1); i++)
        {
            if(int(word1[i]) < 97)
            {
                word1[i] += 32;
            }
            if(int(word2[i]) < 97)
            {
                word2[i] += 32;
            }
            if(int(word1[i]) > int(word2[i]))
            {
                diff++;
                break;
            }
            else if(int(word1[i]) < int(word2[i]))
            {
                diff--;
                break;
            }
        }
    }
    cout<<diff;
}