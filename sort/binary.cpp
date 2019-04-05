#include<iostream>
using namespace std;
int binary_search(int arr[],int search, int left ,int right)  
{ if(left<right){                                           //checking if item to search remains
	int middle = (left+(right-1))/2;                        //divide in two half to get mid point
	if (arr[middle]== search)
	{
		return middle;
	} 

		if(arr[middle]<search)                                //search in first half
		{
			
			return binary_search(arr,search,middle+1,right);   //recursively call binary search
		}
		if(arr[middle]>search)                                  //search in second half
		{
			
			return binary_search(arr,search,left,middle-1);
		}
	}
	return -1;
}

int main()
{
	int n,search;
	
	cout<<"enter number of terms"<<endl;
	cin>>n;
	int arr[n];
	for(int i =0;i<n;i++)
		cin>>arr[i];
	cout<<"enter element to search"<<endl;
	cin>>search;
	int ans;
	ans = binary_search(arr,search ,0,n);
	if(ans == -1)
	{
		cout<<"sorry the number is not present in the array"<<endl;
	}
	else
	{
		cout<<"index of "<<search<<" is "<<ans+1;
		}
		return 0;
}
