#include<iostream>
using namespace std;

int linearSearch(int a[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int a[], int low,int high,int key)
{
    if(low<=high)
    {
        int mid=low + (high-low)/2;
        if(a[mid] == key)
        {
            return mid; 
        }
        else if(a[mid]>key)
        {
            return binarySearch(a,low,mid-1,key);
        }
        else
        {
            return binarySearch(a,mid+1,high,key);
        }
    }
    return -1;
}

int main()
{
    int n,key,ch,index;

    cout<<"Enter size of array : "<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter elements of array : "<<endl;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter search key : "<<endl;
    cin>>key;

    cout<<"Menu"<<endl;
    cout<<"1.Linear Search"<<endl;
    cout<<"2.Binary Search"<<endl;
    cout<<"Enter your choice : "<<endl;
    cin>>ch;
    switch(ch){
        case 1: index = linearSearch(a,n,key);
        if(index==-1){
            cout<<"Key not found"<<endl;
        }
        else {
            cout<<"Key found at position "<<index+1<<endl;
        }
        break;
        
        case 2: index = binarySearch(a,0,n-1,key);
        if(index==-1){
            cout<<"Key not found"<<endl;
        }
        else {
            cout<<"Key found at position "<<index+1<<endl;
        }
        break;

        default:
        cout<<"Invalid choice"<<endl;
    }
    return 0;
}
