#include <iostream>
using namespace std;

void Permutation(char *a,int i)
{
    //base 
    if(a[i] == '\0')
    {
        cout << a <<endl;
        return;
    }

    //recursive
    for(int j=i;a[j]!='\0';j++)
    {
        swap(a[i],a[j]);
        Permutation(a,i+1);
        swap(a[i],a[j]);
    }
}

void Permutation1(char *a,int i ,int j)
{
    //base 
    if(a[i] == '\0')
    {
        cout << a <<endl;
        return;
    }

    //recursive

    if(a[j] !='\0')
    {
        swap(a[i],a[j]);
        Permutation1(a,i+1,j+1);
        swap(a[i],a[j]);
    }
    else
        Permutation1(a,i+1,i);

}


int main() {
  char a[] = "abc";
  Permutation(a,0);
  cout<<"Using Pure Recursion"<<endl;
 // Permutation1(a,0,0);  Not working
}
