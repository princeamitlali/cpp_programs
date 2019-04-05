#include<iostream>
using namespace std;
int stop = 0;
void insertionsort(int arr[],int pass)
{
	int value = arr[pass];
	int i = pass;
	while(value < arr[i-1] && i >0)
	{
		arr[i] = arr[i-1];
		i--;
	}
	arr[i] = value;
	if (pass<stop)
	{
		insertionsort(arr,pass+1);
	}

}
int main()
{
	int n;
	
	cout<<"enter number of terms"<<endl;
	cin>>n;
	int arr[n];
	stop = n;
	for(int i =0;i<n;i++)
		cin>>arr[i];
	insertionsort(arr,1);
	for(int i =0;i<n;i++)
		{cout<<arr[i]<<" ";
		//{;
		}
	return 0;
}
