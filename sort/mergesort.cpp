#include<iostream>
using namespace std;
void merge(int arr[],int left,int middle,int right)
{
	int r1= middle-left+1;
	int r2 = right - middle;
	int arr1[r1],arr2[r2],mid = middle+1;
	int i=0,j=0,k=left;
	for (int a =0;a<r1;a++)
	{
			arr1[a]=arr[left];
			left++;
	}
	for(int b =0;b<r2;b++)
	{
		arr2[b] = arr[mid];
		mid++;
	}
	while (i<r1&&j<r2)
	{
		if (arr1[i]<=arr2[j])
		{
			arr[k]= arr1[i];
			i++;
		}
		else
		{
			arr[k]=arr2[j];
			j++;
		}
		k++;
	}
	while(i<r1)
	{
		arr[k]=arr1[i];
		i++;
		k++;
	}

	while(j<r2)
	{
		arr[k]=arr2[j];
		j++;
		k++;
	}
}
void mergesort(int arr[],int left , int right)
{ int middle;
	if(right>left)
	{
		middle = (left + right)/2;
		mergesort(arr, left , middle);
		mergesort(arr,middle+1,right);
		merge(arr,left,middle,right);
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
	mergesort(arr,0,n);
	for(int i =0;i<n;i++)
		{cout<<arr[i]<<" ";
		//{;
		}
	return 0;
}
