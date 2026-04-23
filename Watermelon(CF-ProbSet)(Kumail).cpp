#include<iostream>

using namespace std;

void evenMelon(int div)
{
    int evenchk = div/2;
    if(evenchk % 2 == 0)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }

}

int main()
{
    int w = -1;
    while(!(1 <= w && w <= 100))
    {
        cout<<"Give the weight of the Watermelon: ";
        cin>>w;
    }
    evenMelon(w);

    return 0;

}
