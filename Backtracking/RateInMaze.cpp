#include <iostream>
using namespace std;
int sol[10][10]={0};
bool RateInMaze(char mz[][5],int i,int j,int n,int m)
{
    
    //Base Case
    if(i == n-1 and j== m-1)
    {
         sol[i][j]=1;
        for(i=0;i<n;i++)
        {
           
            for (j=0;j<m;j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    //Recursive Case
    sol[i][j]=1;
        //Chk Right
        if (j+1 < m and mz[i][j+1] != 'X')
        {
            bool right = RateInMaze(mz,i,j+1,n,m);
            if(right == true)
            {
                return true;
            }
        }
        //Chk Down
        if (i+1<n and mz[i+1][j] != 'X')
        {
            bool down = RateInMaze(mz,i+1,j,n,m);
            if(down == true)
            {
                return true;
           }
       }
}
int main() {
char mz[][5] = { "0000",
                  "00XX",
                  "0000",
                  "XX00"  };
int m=5,n=5;
RateInMaze(mz,0,0,m,n);
}
