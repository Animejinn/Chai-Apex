#include<iostream>

using namespace std;

int main()
{
    int p;
    int choice[3];
    int solP = 0;
    cin>>p;
    for(int i = 0; i < p; i++)
    {
        cin>>choice[1]>>choice[2]>>choice[3];
        if(choice[1]+choice[2]+choice[3] > 1)
        {
            solP++;
        }
    }
    cout<<solP;
}