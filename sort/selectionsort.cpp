#include<iostream>
using namespace std;
void selectionsort(int arr[],int n)
{int pass = n,max = -99999,j=-1;
	for(int i =0;i<pass;i++)
	{
		if(arr[i]>max)
		{
			max = arr[i];
			j=i;
			
		}}
			arr[j]=arr[n-1];
			arr[n-1]= max;

	//min=9999;
	
	if(!(n==1))
	
		selectionsort(arr, n-1);
}
int main()
{
	int n;
	int arr[20];
	cout<<"enter number of terms"<<endl;
	cin>>n;
	for(int i =0;i<n;i++)
		cin>>arr[i];
	selectionsort(arr,n);
	for(int i =0;i<n;i++)
		{cout<<arr[i]<<" ";
		}
	return 0;
}
