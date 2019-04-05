#include <iostream>
using namespace std;

void bubblesort(int item[][4],int start ,int n,int feature) //program for bubble sort by recursive method it work on substract rule similar to divide and conquer rule
{int pass = n,swap=0;		//the bubble sort function run n times
	for(int i =start;i<pass;i++)    //this is the for loop to compare and swap the values if the next is smaller i do in such a manner because i sort the array from right hand side
	{							//this will run n times for one call of bubblesort and bubblesort called n times so in total it run n*n times
		if(item[i][feature]>item[i+1][feature])	//this is for compare and swap if has a constant time complexity
		{	
			int temp1,temp2,temp3,temp4;
		temp1=item[i][0];
		temp2=item[i][1];
		temp3=item[i][2];
		temp4=item[i][3];
		item[i][0]=item[i+1][0];  
		item[i][1]=item[i+1][1]; 
		item[i][2]=item[i+1][2]; 
		item[i][3]=item[i+1][3]; 
		item[i+1][0]= temp1;
		item[i+1][1]= temp2;
		item[i+1][2]= temp3;
		item[i+1][3]= temp4;
			swap++;
		}
	}
	if(!(swap==0||n==1))
		bubblesort(item,start, n-1,feature);
}


void first_come_first_serve_with_priority(int item[][4],int n)  //first serve first come together with priority
{
	
	bubblesort(item,0,n,3);    
	bubblesort(item,0,n,1);
}

void shortest_time_remaining(int item[][4] ,int n)
{ int time =0,print;
	bubblesort(item,0,n,2);
	time = item[0][1];
	for(int i =0 ; i<n-1;i++)
	{ print = 0;
		if(item[i][2]>0){
		if((time + item[i][2])<=item[i+1][1])
		{
			print = item[i][2];
			time += print;
			for(int j =0 ; j<print;j++)
				cout<<" _ ";
			cout<<i<<"("<<time<<")";
			item[i][2]-= print;
		 //bubblesort(item,i,n,2);
			//continue;
		}
		else
		{
			print = item[i+1][1] - item[i][1];
			item[i][2]-= print;
			for(int j =0 ; j<print;j++)
				cout<<" _ ";
			cout<<i<<"("<<time<<")";
			bubblesort(item,i,n,2);
			i--;
			//continue;
		}
	}
	}
	for(int j =0 ; j<item[n-1][2];j++)
				cout<<" _ ";
			cout<<item[n-1][0]<<"("<<time<<")";

}

int main()
{
	int n;
	cout<<"enter number of process"<<endl;
	cin>>n;
	int item [n][4];
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
		cout<<"enter priority for process  "<<i+1<<endl;
		cin>>enter;
		item[i][3]= enter;

	}
	cout<<"process a_time b_time priority"<<endl;
	for(int i = 0 ; i < n ; i++)
		{cout<<item[i][0]<<"\t"<<item[i][1]<<"\t"<<item[i][2]<<"\t"<<item[i][3]<<endl;
	}
	first_come_first_serve_with_priority(item,n);

	shortest_time_remaining(item,n);
	
}
