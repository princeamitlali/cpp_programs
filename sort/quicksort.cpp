#include<iostream>
using namespace std;
int partition(int arr[],int left,int right)
{
	int j;
	j = right;
	int value = arr[left];
	int r = left;
	for(int i = left+1;i< right+1;i++)
	{
		if (arr[i]<value)
		{
			arr[r] = arr[i];
			arr[i] = value;
			r++;
		}
		else
		{
			int temp;
			
			if(j<i){break;}
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			j--;
			i--;
			}
	}
	return r;
}
void quicksort(int arr[],int left , int right)
{ 
	if(left<right)
	{
		int middle = partition(arr,left,right);
		quicksort(arr,left,middle);
		quicksort(arr,middle+1,right);
	}
}

int main()
{
	int n;
	
	cout<<"enter number of terms"<<endl;
	cin>>n;
	int arr[n];
	//stop = n;
	for(int i =0;i<n;i++)
		cin>>arr[i];
	quicksort(arr,0,n);
	for(int i =0;i<n;i++)
		{cout<<arr[i]<<" ";
		//{;
		}
	return 0;
}
