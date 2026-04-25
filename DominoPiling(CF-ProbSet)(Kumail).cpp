#include<iostream>

using namespace std;

int main()
{
    int m = 0, n = 0;
    int d = 0;
    cin>>m>>n;
    int mn = m*n;
    if(m <= n && n <= 16)
    {
        while(mn > 1)
        {
            mn-=2;
            d++;
        }
        cout<<d;
    }
}