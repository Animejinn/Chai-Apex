#include<iostream>

using namespace std;

int main()
{
    short p;
    short choice[3];
    short solP = 0;
    cin>>p;
    for(short i = 0; i < p; i++)
    {
        cin>>choice[1]>>choice[2]>>choice[3];
        if(choice[1]+choice[2]+choice[3] > 1)
        {
            solP++;
        }
    }
    cout<<solP;
}