#include <iostream>
using namespace std;
void bankers_algorithm(int process[][10000],int res,int n)//process[][1000] here we can take 5000 resource in total
{
	int check = 0;   // it is for check how many process executed
	int change = 0;     // to check if any process change its state
	int checker[res];   //the minimum available r5esouse to check next process will execute or not
	for(int i = 0 ; i <res;i++)
		checker[i] = process[0][i+1] ;  // loading the resource of first process as available
	jump :for(int i = 0;i<n;i++)        //for loop run for every process
	{
		int rise = 0;          //rise if the variable that will increase if any resource has available greater than or equal to the max
		change =0;              // change is for the change in a full run of process
		for(int j = 0 ; j < res;j++)   // this for loop we run for every resource check the available to the max requirement
		{
			if(checker[j]==process[i][j+res+1])
				rise++;
		}
		if(rise == res)  //if available resourcs are equal to or greater than requirement rise will equal to resources and the process will execute
		{
			for(int j = 0 ; j < res;j++)
			{
				checker[j] += process[i][j+1]; //then the allocated resources will available to others
				check++;
				change ++;
			}
		}
	}
	if(check<n){  // it will check if all process will execute if all process are not execute it statrt the loop once again

		if(change>0)   //if loop execute for a full time and no process change means there is no chance of process to execute
		goto jump;
	}
	if(check==n)               // if all process execute it is safe
		cout<<"safe";
	else
		cout<<"unsafe";    // otherwise unsafe
}


int main()                                 //simple program to take input
{
	cout<<"enter number of processes";
	int n ;
	cin>>n;
	cout<<"enter number of resources";
	int res;
	cin>> res;
	int tot;
	tot=2*res;
	tot = tot +1;

	int process[n][10000];

	for(int i =0; i<n; i++)
	{ int value;

		cout<<"enter process id"<<endl;
		cin >> value;
		process[i][0] = value;
		for(int j =1;j<=res;j++){
		cout<<"enter available resourse "<<j<<endl;
		cin>>value;
		process[i][j]= value;
		cout<<"enter required resourse "<<j<<endl;
		cin>>value;
		process[i][j+res]= value;
	}
	}
	cout<<"id\tavl\treq"<<endl;       //for showing available resources
	cout<<"p";
	for(int j= 1 ; j<tot;j++)
	{ int pri;
		if(j>res)
		pri = j-res;
		else 
		pri = j;
		
		cout<<"    "<<pri;
		
	}
	cout<<endl;

	for(int i = 0;i<n;i++)
	{
		for(int j= 0 ; j<tot;j++)
			cout<<process[i][j]<<"    ";
		cout<<endl;
	}
	bankers_algorithm(process,res,n);
}
