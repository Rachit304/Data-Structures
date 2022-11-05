#include <iostream>
using namespace std;

bool PlaceKarnaSafeHai(int board[][10],int i,int j,int n)
{
    //chk horizontally and vertically
    for(int k=0;k<n;k++)
    {
        if(board[i][k] || board[k][j])
            return false;
    }

    int x=i,y=j;
    //for upper right diagonal
    while (i>=0 && j<n)
    {
        if(board[i][j])
            return false;
        i--;
        j++;
    }
    i=x,j=y;
    //for upper left diagonal
    while (i>=0 && j>=0)
    {
        if(board[i][j])
            return false;
        i--;
        j--;
    }

    return true;
}


bool N_Queen(int board[][10],int i,int n)
{
//base
    if(i == n)
    {
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(board[i][j])
                    cout<<"Q"<<" ";
               else
                    cout<<"_"<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }
//recursivve
    for (int j=0 ;j<n; j++)
    {
        if(PlaceKarnaSafeHai(board,i,j,n) == true)
        {
            board[i][j] = 1;

            bool BaatBani = N_Queen(board,i+1,n);
            if(BaatBani == true)
                return true;

        //if baat nhi bai toh i,j se hataoo and nxt cell pr call karo
            board[i][j] = 0;
        }
        
    }
     return false;

}

int main() {

int n;
int board[10][10] = {};
cin>>n;
N_Queen(board,0,n);

  
}
