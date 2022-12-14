#include <iostream>
using namespace std;
void Merge(int *a,int *b,int *c,int s,int e)
{
    int mid = (s+e)/2;
    int i=s,j=mid+1,k=s;
    while (i<=mid and j<=e)
    {
        if(b[i]<c[j])
            a[k++]=b[i++];
        else
            a[k++]=c[j++];
    }
    while(i<=mid)
    {
        a[k++]=b[i++];
    }
    while(j<=e)
    {
        a[k++]=c[j++];
    }
}

void PrintArray(int *a,int n)
{
    for (int i =0;i<n;i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}


void mergeSort(int *a,int s,int e)
{
    //base
        if(s>=e)
            return ;

    //divide
    int mid= (s+e)/2;
    int b[100],c[100];
    for(int i=s;i<=mid;i++)
    {
        b[i] = a[i]; 
    }
    for(int i=mid+1;i<=e;i++)
    {
        c[i] = a[i]; 
    }

    //sort
    mergeSort(b,s,mid);
    mergeSort(c,mid+1,e);
    //merge
    Merge(a,b,c,s,e);

}

int main() {
    int a[] = {8,2,7,4,1,3};
    int n=sizeof(a)/sizeof(n);
    PrintArray(a,n);
    mergeSort(a,0,n-1);
    PrintArray(a,n);
}
