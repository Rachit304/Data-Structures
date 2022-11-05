#include <iostream>
using namespace std;
int main() {
   int a[]={14,23,27,10,35,19,42};
   int n=sizeof(a)/sizeof(int);
   for (int i=1;i<n;i++)
   {
       int temp= a[i];
       int j=i-1;
       while (j>=0 && a[j]>temp)
       {
            a[j + 1] = a[j];
            j = j - 1;
       }
       a[j+1]=temp;

   }
   for(int i=0;i<n;i++)
   {
       cout<<a[i]<<" ";
   }

}
