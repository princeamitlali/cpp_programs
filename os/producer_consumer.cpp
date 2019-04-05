#include<iostream>
using namespace std;

int out = 0;
int in = 0; 
int counter = 0;
int buffer_size = 10;
int item[10];
void producer()                    //using the very common algorithm to check and insert in a queue or stack
{
	if(counter == buffer_size)
	{
		cout<<"we are full try after sometime"<<endl;
		;
	}
	else
	{
		if(counter>buffer_size)
			cout<<"there is some error in system recheck the code"<<endl;
		else
		{
			int next;
			cout<<"enter the producer item"<<endl;
			cin>>next;
			item[in] = next;
			in = (in +1)%10;
			counter++;
		}
	}

}

void consumer()                                   //using the very common algorithm to check and delete from a queue or stack  
{
	if(counter == 0)
	{
		cout<<"sorry we don't have something yet ,try after sometime"<<endl;
		;
	}
	else
	{
		if(counter>buffer_size)
			cout<<"there is some error in system recheck the code"<<endl;
		else
		{
			cout<<"here is your item  "<<item[out]<<endl;
			out = (out +1)%10;
			counter--;
		}
	}
}

int main()
{
	
	while(true)
	{
		int n =0;
		cout<<"press one if you are a producer"<<endl;
		cout<<"press 2 if you are a consumer"<<endl;
		cout<<"press 3 to quit"<<endl;
		cin>>n;
		switch(n)
		{
			case 1: producer();
					break;

			case 2: consumer();
					break;

			case 3: exit(0);

			default:
			{
				cout<<"invalid input try with a valid one"<<endl;     //ask after every process want some more
			}}
			cout<<endl<<endl<<endl;
			cout<<"do you still want to continue, press 4 for yes "<<endl;   
			cin>>n;
			if(n==4)
			{
				continue;											//to execute loop once again
			}
			else
			{ exit(0);}
			
			
		
	}

}
