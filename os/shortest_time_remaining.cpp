#include <iostream>
using namespace std;
void bubblesort(int item[][3],int n,int feature) //program for bubble sort by recursive method it work on substract rule similar to divide and conquer rule
{int pass = n,swap=0;		//the bubble sort function run n times
	for(int i =0;i<pass;i++)    //this is the for loop to compare and swap the values if the next is smaller i do in such a manner because i sort the array from right hand side
	{							//this will run n times for one call of bubblesort and bubblesort called n times so in total it run n*n times
		if(item[i][feature]>item[i+1][feature])	//this is for compare and swap if has a constant time complexity
		{	
			int temp1,temp2,temp3;
		temp1=item[i][0];
		temp2=item[i][1];
		temp3=item[i][2];
		item[i][0]=item[i+1][0];  
		item[i][1]=item[i+1][1]; 
		item[i][2]=item[i+1][2];  
		item[i+1][0]= temp1;
		item[i+1][1]= temp2;
		item[i+1][2]= temp3;
			swap++;
		}
	}
	if(!(swap==0||n==1))
		bubblesort(item, n-1,feature);
}

void sortest_job_first(int item[][3],int n)
{
	bubblesort(item,n,1);
	bubblesort(item,n,2);
	int time_elapsed = item[0][1];
	cout<<"start"<<endl;
	cout<<"("<<time_elapsed<<") ";
	for(int i = 0 ; i < n ; i++)
	{
		time_elapsed += item[i][2];
		for(int j = 0 ; j <item[i][2]; j++)
			{cout<<" _ ";}
		cout<<item[i][0]<<"("<<time_elapsed<<") ";
	}
	cout<<"\nend"<<endl;
}

int main()
{
	int n;
	cout<<"enter number of process"<<endl;
	cin>>n;
	int item [n][3];
	for(int i =0;i <n;i++)
	{
		int enter;
		cout<<"enter process id for  "<<i+1<<endl;
		cin>>enter;
		item[i][0]= enter;
		cout<<"enter arrival time for process  "<<i+1<<endl;
		cin>>enter;
		item[i][1]= enter;
		cout<<"enter burst time for process  "<<i+1<<endl;
		cin>>enter;
		item[i][2]= enter;

	}for(int i = 0 ; i < n ; i++)
		{cout<<item[i][0]<<"\t"<<item[i][1]<<"\t"<<item[i][2]<<"\t"<<endl;}
	sortest_job_first(item,n);
	//first_come_first_serve_with_priority(item,n);
	cout<<"\nend"<<endl;


	
	cout<<"process a_time b_time priority"<<endl;
	for(int i = 0 ; i < n ; i++)
		{cout<<item[i][0]<<"\t"<<item[i][1]<<"\t"<<item[i][2]<<"\t"<<endl;}
	}
