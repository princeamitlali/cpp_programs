#include<iostream>
using namespace std;
void bubblesort(int arr[],int n)
{int pass = n,temp,swap=0;
	for(int i =0;i<pass;i++)
	{
		if(arr[i]>arr[i+1])
		{
			temp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]= temp;
			swap++;
		}
	}
	if(!(swap==0||n==1))
		bubblesort(arr, n-1);
}

int main()
{
	int n;
	int arr[20];
	cout<<"enter number of terms"<<endl;
	cin>>n;
	for(int i =0;i<n;i++)
		cin>>arr[i];
	bubblesort(arr,n);
	for(int i =0;i<n;i++)
		cout<<arr[i]<<" ";

}
