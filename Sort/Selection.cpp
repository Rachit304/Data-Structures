#include <iostream>
using namespace std;
int main() {
   int a[]={14,23,27,10,35,19,42};
   int n=sizeof(a)/sizeof(int);
   for (int i=0;i<n;i++)
   {
       for(int j=i+1;j<n;j++)
       {
            if(a[j]<a[i])
            {
                swap(a[j],a[i]);
            }
       }
       cout<<a[i]<<" ";

   }

}
