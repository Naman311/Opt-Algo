#include<iostream>

using namespace std;

int partition(int arr[],int low, int high)
{
    int pi=high,temp;
    int l=low,r=high-1;
    while(l!=r)
    {
        if(arr[l]<=arr[pi])
        {
            l++;
        }
        else if(arr[r]>=arr[pi])
        {
            r--;
        }
        else
        {
            temp=arr[l];
            arr[l]=arr[r];
            arr[r]=temp;
        }
    }
    if(arr[l]>arr[pi])
    {
        temp=arr[pi];
        arr[pi]=arr[l];
        arr[l]=temp;
        pi=l;
    }
    else if(arr[l]<arr[pi])
    {
        temp=arr[pi];
        arr[pi]=arr[l+1];
        arr[l+1]=temp;
        pi=l+1;
    }
    return(pi);
}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);

        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
