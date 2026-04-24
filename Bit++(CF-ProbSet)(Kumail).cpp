#include<iostream>

using namespace std;

int main()
{
    int n;
    string opX[150];
    int xVal = 0;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>opX[i];
        if(opX[i] == "++X" || opX[i] == "X++")
        {
            xVal++;
        }
        else if(opX[i] == "--X" || opX[i] == "X--")
        {
            xVal--;
        }
    }
    cout<<xVal;
    return 0;
}