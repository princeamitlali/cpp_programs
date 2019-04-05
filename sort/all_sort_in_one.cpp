#include<iostream>
using namespace std;
void bubblesort(int arr[],int n) //program for bubble sort by recursive method it work on substract rule similar to divide and conquer rule
{int pass = n,temp,swap=0;		//the bubble sort function run n times
	for(int i =0;i<pass;i++)    //this is the for loop to compare and swap the values if the next is smaller i do in such a manner because i sort the array from right hand side
	{							//this will run n times for one call of bubblesort and bubblesort called n times so in total it run n*n times
		if(arr[i]>arr[i+1])	//this is for compare and swap if has a constant time complexity
		{					// so for bubble sort my time complexity is n*n 
			temp=arr[i];
			arr[i]=arr[i+1];  
			arr[i+1]= temp;
			swap++;
		}
	}
	if(!(swap==0||n==1))
		bubblesort(arr, n-1);
}

void selectionsort(int arr[],int n) //program for selection sort
{int pass = n,max = -99999,j=-1;    //unlikely chosing minimum number and and put that at first position i chose the maximum and put that at last
	for(int i =0;i<pass;i++)		//i do so because i sort it from right to left
	{								//the selection sort is called n times 
		if(arr[i]>max)				// the inner for loop is also called n times in first call of selectionsort
		{							//all other statment has a constant time complexity
			max = arr[i];			//results in total complexity of n*n
			j=i;
			
		}}							// here i do actually choose the maximum and swap it with the last element 
			arr[j]=arr[n-1];		//next time when the loop run it runs n-1 times because we exclude the last term
			arr[n-1]= max;			// so loop run as n + (n-1) .... +1= (n*(n-1))/2 == order of n*n

	//min=9999;
	
	if(!(n==1))
	
		selectionsort(arr, n-1);
}

int stop = 0;						// here i declare a global variable as in this case i do sorting from left to right so need something to stop the recursive calling
void insertionsort(int arr[],int pass)	// insertionsort is called
{										// insertion sort is called n times one for each member
	int value = arr[pass];				//this is an example of inner sorting we divide the array into two sub part sorted and unsorted
	int i = pass;
	while(value < arr[i-1] && i >0)  //in this we insert value in a array
	{								//this block execute on the sorted part
		arr[i] = arr[i-1];			// we move from right to left in sorted array if the element of array has a value greater than the comparing value we shift that one index up
		i--;
	}
	arr[i] = value;					// if we got a equal or less than value we place the element there as a vacant space is created when element with higher values shift
	if (pass<stop)					// the inner loop run maximum of m times where m is the element in the sorted array so for worst case
	{								// loops run as 1 +2 3+........+n = (n*(n-1))/2  thus time complexity is O(n*n)
		insertionsort(arr,pass+1);
	}

}

void merge(int arr[],int left,int middle,int right) // this function is for merging two array here i can simply us insertion sort also
{
	int r1= middle-left+1;							// in order to merge two array first we need to create them
	int r2 = right - middle;
	int arr1[r1],arr2[r2],mid = middle+1;			// varaible array are create the size of array are determined by substracting lower bound from upar bound
	int i=0,j=0,k=left;
	for (int a =0;a<r1;a++)							// if there are n element in array the time complexity of this for loop is n/2
	{
			arr1[a]=arr[left];
			left++;
	}
	for(int b =0;b<r2;b++)   // same for this for loop n/2
	{
		arr2[b] = arr[mid];
		mid++;
	}
	while (i<r1&&j<r2)				// here we compare elements one by one this is called two way transversing we compare the elements of the two arrays and the minimum of them get place in the fimal array
	{
		if (arr1[i]<=arr2[j])		//this is the case when both arrays has some values
		{
			arr[k]= arr1[i];		//this while loop can maximum excuted to n-1 times if the total number of element in array is n
			i++;
		}
		else
		{
			arr[k]=arr2[j];
			j++;
		}
		k++;
	}
	while(i<r1)  //in only the first arrray has element left while the second become empty
	{
		arr[k]=arr1[i];
		i++;
		k++;
	}

	while(j<r2) /// if only second array has element first become empty
	{
		arr[k]=arr2[j];
		j++;
		k++;             // so the time complexity for this is n/2  +   n/2     + n  = O(n)
	}
}
void mergesort(int arr[],int left , int right)  // calling merge sort 
{ int middle;									// this is based of divide and conqueror method so first we find a middle element alang which we can divide it
	if(right>left)
	{
		middle = (left + right)/2;
		mergesort(arr, left , middle);			//calling merge sort recursively  and each time element reduces to half		
		mergesort(arr,middle+1,right);			// such type of recursive function has time complexity of logn
		merge(arr,left,middle,right);
	}											// thus logn for spliting and n for merging makes toatal time complexity n(logn)

}


int partition(int arr[],int left,int right)  // this is the partion function for the quick sort in quick sort as like merge sort we divide the array
{	
	int j;
	j = right;										// but the division need not to be equal it depends on the pivot point 
	int value = arr[left];					//in partition we move the elemennts less than the pivot to the left where equal toor greater than to right
	int r = left;
	for(int i = left+1;i< right;i++)		// the complexity depends on the size of the array if the array need to partioned has n element the time complexity
	{										// that only depends on the for loop is equal to n if n is the number of element in array
		if (arr[i]<value)
		{
			arr[r] = arr[i];				// we furthr need to divide the array to two sub array depending on pivot point so it need to return a pivot point as return statment
			arr[i] = value;
			r++;
		}	
		else
		{
			int temp;
			
			if(j<i)
				{
					break;
				}
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			j--;
			i--;
		}
	}								//quick sort has a variety of time complexity as the divided array may have diffrent size
	return r;								// so we only calculate the time complexity for best case and worst case
}											// best case is then the array is divided into two equal size array then quick sort behave like merge
void quicksort(int arr[],int left , int right)// sort and the complexity will be same as merge sort i.e n(logn)  n for partitioning and logn for dividing into sub array
{ 
	if(left<right)								// in worst case the item is already sorted in such a case we get only one array of n-1 element if the ancestor array has n element
	{
		int middle = partition(arr,left,right); // time complexity for this in n
		quicksort(arr,left,middle);             // in best case these has time complexity of logn
		quicksort(arr,middle+1,right);			// in worst case these has time complexity of n-1 as like selection sort 
	}											// leading to time complexity of n(logn) in best case where O(n*n) in worst case
}

int binary_search(int arr[],int search, int left ,int right)  // binary search is a search method based of divide and conquer rule
{ if(left<right){											//as binary searching is only done of a sorted array so if our array is unsorted we need to sort it by any of the above methods
	int middle = (left+(right-1))/2;						// in order to divide the array into two half we need to find the middle term
	if (arr[middle]== search)								// once when the middle term is found we check the presence of searched element at that point 
	{														// if found return the index of the middle
		return middle;
	} 														//else we check the searched number is grater than or smaller to the middle term if greater than search in right subarray
															// IF SMALLER search in left sub array
		if(arr[middle]<search)								// once the element is found return its index or print the 
		{													//if all array searched and element not found return a message
			
			return binary_search(arr,search,middle+1,right);
		}
		if(arr[middle]>search)
		{
			
			return binary_search(arr,search,left,middle-1);
		}
	}
	return -1;
}


int main()
{
	int n,choice,ch;
	int arr[20];
	cout<<"enter number of terms"<<endl;
	cin>>n;
	stop = n;
	cout<<"enter the unsorted string"<<endl;
	for(int i =0;i<n;i++)
		cin>>arr[i];
	cout<<"your unsorted array is as"<<endl;
	for(int i =0;i<n;i++)
		{cout<<arr[i]<<" ";
		}
	cout<<endl;
	cout<<"select 1 for bubble sort"<<endl;
	cout<<"select 2 for selection sort"<<endl;
	cout<<"select 3 for insertion sort"<<endl;
	cout<<"select 4 for merge sort"<<endl;
	cout<<"select 5 for quick sort"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1: bubblesort(arr,n);
		break;
		case 2: selectionsort(arr,n);
		break;
		case 3: insertionsort(arr,1);
		break;
		case 4: mergesort(arr,0,n);
		break;
		case 5: quicksort(arr,0,n);
		break;
		default: cout<<"please enter a valid choice"<<endl;
	} 
	cout<<"sorted array is as"<<endl;
	for(int i =0;i<n;i++)
		{cout<<arr[i]<<" ";
		}
		cout<<endl;
	cout<<"your array is now sorted if you want to search presence of any number in it press 1 or to exit press 2"<<endl;
	cin>>ch;
	if(ch==1)
	{
		int search,ans;
		cout<<"enter the number to search "<<endl;
		cin>>search;
		ans = binary_search(arr,search ,0,n);
	//cout<<ans;
	if(ans == -1)
	{
		cout<<"sorry the number is not present in the array"<<endl;
	}
	else
	{
		cout<<"index of "<<search<<" is "<<ans+1;
		}

	}
	if(ch==2)
	{
		exit(0);
	}

	cout<<"the array has "<<n<<" elements if you want to search by ranking please provide the rank or else press 0 to exit"<<endl;
	int aaaa;
	cin>>aaaa;
	if(aaaa==0)
	{
			exit(0);
	}
	if(aaaa<1||aaaa>n)
	{
		cout<<"invalid input out of bound"<<endl;
	}
	else
	{
			cout<<arr[aaaa-1];
	}
	return 0;
}
