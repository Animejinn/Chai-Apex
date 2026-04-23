#include<iostream>

using namespace std;

int main()
{
    int w = -1;
    while(!(1 <= w && w <= 100))
    {
        cout<<"Give the weight of the Watermelon: ";
        cin>>w;
    }
    
    
    if(w % 2 == 0)
    {
        if((w/2) % 2 == 0)
        {
            cout<<"YES";
        }
    }
    else
    {
        cout<<"NO";
    }
    return 0;

}