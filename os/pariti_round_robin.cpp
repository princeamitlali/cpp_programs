#include<iostream>
using namespace std;


void bubblesort(int item[][4],int n,int feature) //program for bubble sort by recursive method it work on substract rule similar to divide and conquer rule
{int pass = n,swap=0;		//the bubble sort function run n times
	for(int i =0;i<pass;i++)    //this is the for loop to compare and swap the values if the next is smaller i do in such a manner because i sort the array from right hand side
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
		bubblesort(item, n-1,feature);
}

void first_come_first_serve_with_priority(int item[][4],int n)  //sorting with respect to arrival time and priority
{
	
	bubblesort(item,n,3);
	bubblesort(item,n,1);
	
}

void round_robin(int item[][4],int num,int n,int inc)  //applying round robin on the whole selected system
{
	int time_quantum;
	cout<<"enter time_quantum";
	cin>>time_quantum;
	int time_elapsed = item[n][1];  // time elapsed i s equal to arrival time of first sorted process in case the arrival time is not zero
	
	int check = 0;
	
	{
	jump:	for(int i=0;i < num;i++)
		{ int print =0;
			if(item[i][1]<=time_elapsed){
			if(item[i][2]<= time_quantum&& item[i][2]>0)  // if burst time is less than the time quantum only run for left time
			{
				print = item[i][2];                // as burst time is zero the process will no longer execute so increase check to keep track
				item[i][2] = 0;
				check++;
				time_elapsed += print;
				for(int j =0;j<print;j++)
					cout<<" _ ";
			cout<<item[i][0]<<"("<<time_elapsed<<")";

			}
			else
			if(item[i][2]> time_quantum&& item[i][2]>0)  //if burst time is greater run for burst time
			{
				print = time_quantum;
				time_elapsed+= print;
				item[i][2]= item[i][2] - time_quantum;
				for(int j =0;j<print;j++)
					cout<<" _ ";
				cout<<item[i][0]<<"("<<time_elapsed<<")";
			}
			}
			
			
			
		}
		if(check<inc+1) // if all process execute the check reach to inc if not start loop once again
		 goto jump;
		
	}

}
int re =0;
int check_priority(int item[][4], int n)    // if round robin mix with priority scheduling it is for checj\kin wether two process has same
{
	if(item[n][1]==item[n+1][1]&&item[n][3]==item[n][3])  //arrival time and priority 
	{
		re++;
		check_priority(item,n+1);  // if there are more than two with same arrival time and priority
	}
	
	return re;
}

void round_robin_with_priority(int item[][4],int n)  //the round robin will execute only for same priority and arrival
{
	int time_elapsed = item[0][1];
	cout<<"start"<<endl;
	cout<<"("<<time_elapsed<<") ";
	for(int i = 0 ; i < n ; i++)
	{
		int inc;
		inc = check_priority(item,i);

		if(inc>0)
		{
			round_robin(item,n,i,inc);      //round robin for selected processes
			i = i + inc;
		}
		else
		{
		time_elapsed += item[i][2];
		for(int j = 0 ; j <item[i][2]; j++)
			{cout<<" _ ";}
		cout<<item[i][0]<<"("<<time_elapsed<<") ";
		}
	}
	cout<<"\nend"<<endl;

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
		{cout<<item[i][0]<<"\t"<<item[i][1]<<"\t"<<item[i][2]<<"\t"<<item[i][3]<<endl;}
	first_come_first_serve_with_priority(item,n);
	round_robin_with_priority(item,n);
	cout<<"\nend"<<endl;


	
	
	}
