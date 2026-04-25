#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    short arrln[5][5];
    short ipos, jpos;
    short chk = 0;
    short turns = 0;
    for(short i = 0; i < 5; i++)
    {
        cin>>arrln[i][0]>>arrln[i][1]>>arrln[i][2]>>arrln[i][3]>>arrln[i][4];
        if(arrln[i][0]+arrln[i][1]+arrln[i][2]+arrln[i][3]+arrln[i][4] == 1)
        {
            chk++;
            for(int j = 0; j < 5; j++)
            {
                if(arrln[i][j] == 1)
                {
                    ipos = i;
                    jpos = j;
                }
            }
        }
    }
    if(0 < chk && chk < 2)
    {
        while(arrln[2][2]==0)
        {
            short temp;
            if(0 <= ipos && ipos < 2)
            {
                temp = arrln[ipos][jpos];
                arrln[ipos][jpos] = arrln[ipos+1][jpos];
                arrln[ipos+1][jpos] = temp;
                ipos++;
                turns++;
            }
            else if(ipos == 2)
            {
                if(jpos != 2)
                {
                    if(0 <= jpos && jpos < 2)
                    {
                        temp = arrln[ipos][jpos];
                        arrln[ipos][jpos] = arrln[ipos][jpos+1];
                        arrln[ipos][jpos+1] = temp;
                        jpos++; 
                        turns++;
                    }
                    else if(2 < jpos && jpos < 5)
                    {
                        temp = arrln[ipos][jpos];
                        arrln[ipos][jpos] = arrln[ipos][jpos-1];
                        arrln[ipos][jpos-1] = temp;
                        jpos--;
                        turns++;
                    }
                }
            }
            else if(2 < ipos && ipos < 5)
            {
                temp = arrln[ipos][jpos];
                arrln[ipos][jpos] = arrln[ipos-1][jpos];
                arrln[ipos-1][jpos] = temp;
                ipos--;
                turns++;
            }
        }
    }
    cout<<turns;
}