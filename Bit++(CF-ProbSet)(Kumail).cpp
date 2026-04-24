#include<iostream>

using namespace std;

int main()
{
    int n;
    string opX[100];
    int xVal = 0;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>opX[i];
        if(opX[i] == "++x" || opX[i] == "x++")
        {
            xVal++;
        }
        else if(opX[i] == "--x" || opX[i] == "x--")
        {
            xVal--;
        }
    }
    cout<<xVal;
}