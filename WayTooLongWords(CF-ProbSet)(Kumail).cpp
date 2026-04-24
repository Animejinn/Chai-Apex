//77A. Way Too Long Words

#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n;
    int size;
    string word[100];
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>word[i];
    }
    for(int i = 0; i < n; i++)
    {
        size = word[i].length();
        if(size > 10)
        {
            cout<<word[i][0]<<size-2<<word[i][size-1]<<endl;
        }
        else
        {
            cout<<word[i];
        }
    }
    return 0;
}