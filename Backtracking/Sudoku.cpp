//Sudoku Puzzles
//N=9 total rows-col
//Row-col 1-9 unique numbers
//boxes = root(N)*root(N) ke N boxes

#include <iostream>
using namespace std;
bool SafeToPut(int board[][9],int i,int j,int n,int number)
{
    //rows and column
    for(int k=0;k<n;k++)
    {
        if(board[i][k] == number || board[k][j] == number)
            return false;
    }
    //boxes

    n=n/3;
    int seg1 = (i/3)*n;
    int seg2 = (j/3)*n;
    for(int k=seg1;k<seg1+n;k++)
    {
        for(int l=seg2;l<seg2+n;l++)
        {
             if(board[k][l] == number)
                return false;
        }
    }

    return true;
}


bool SudokuSolver(int board[][9],int i,int j,int n)
{
    //base
    if(i == n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<"  ";
            }
        cout<<endl;
        }
    return true;
    }

    //recursive
    if(j == n)
        return SudokuSolver(board,i+1,0,n);

    if (board[i][j] != 0)
        return SudokuSolver(board,i,j+1,n);


    for(int number=0;number<=n;number++)
    {
        if(SafeToPut(board,i,j,n,number))
        {
            //if it is safe to put a number than place it 
            board[i][j] = number;
            //and ask recursion to solve remaining..
            bool SolveHua = SudokuSolver(board,i,j+1,n);
            if(SolveHua)
                return true;
        }
        board[i][j] = 0;
    }
    return false;
}



int main() {
int mat[9][9]=     {{5,3,0,0,7,0,0,0,0},
                    {6,0,0,1,9,5,0,0,0},
                    {0,9,8,0,0,0,0,6,0},
                    {8,0,0,0,6,0,0,0,3},
                    {4,0,0,8,0,3,0,0,1},
                    {7,0,0,0,2,0,0,0,6},
                    {0,6,0,0,0,0,2,8,0},
                    {0,0,0,4,1,9,0,0,5},
                    {0,0,0,0,8,0,0,7,9}};
    
    SudokuSolver(mat,0,0,9);
    
}
