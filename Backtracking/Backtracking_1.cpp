#include <iostream>
using namespace std;
void Permutations(char *a,int i)
{
    //base case
    if(a[i]=='\0')
    {
        cout<<a<<endl;
        return;
    }

    //Recursive Case
    for(int j = i; a[j] != '\0'; j++ )
    {
        swap(a[j],a[i]);
        Permutations(a,i+1);
        swap(a[j],a[i]); //backtracking
    }


}
int main() {
  char a[] = "abc";
  Permutations(a,0);
}
