#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=2;i<=sqrt(n);i++)
    {
        if(arr[i]!=-1)
        {
            arr[i]=i;
        }
        for(int j=i+1;j<=n+1;j++)
        {
            if(arr[j]==-1)
            {
                continue;
            }
            else if(j%i==0)
            {
                arr[j]=-1;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(arr[i]!=-1)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}
