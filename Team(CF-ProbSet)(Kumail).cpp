#include<iostream>

using namespace std;

int main()
{
    int p;
    short choice[3];
    short solP = 0;
    cin>>p;
    for(int i = 0; i < p; i++)
    {
        cin>>choice[0]>>choice[1]>>choice[2];
        if(choice[0]+choice[1]+choice[2] > 1)
        {
            solP++;
        }
    }
    cout<<solP;
}