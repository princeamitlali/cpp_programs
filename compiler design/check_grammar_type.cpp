#include<iostream>
using namespace std;
#include<string.h>
int result ;
int len_x,len_y,i,x,y;

void regular( char* grammar )
{
	bool side;
	bool flag = false;
	if(grammar[y+1] >= 'A' && grammar[y+1] <= 'Z')
	{
		flag = true;
		side = true;	
	}
	
	if(grammar[y + len_y] >= 'A' && grammar[y + len_y] <= 'Z')
	{
		flag = true;
		side = false;
		
	}
	
	if(flag)
	{
		if(side)
		{
			::result = 4;
		}
		else
		{
			::result = 5;
		}
	}
	
}

void context_free( char* grammar)
{
	int count = 0;
	bool flag = false;	
	if(len_x == 1)
	{
		for(i=0;i<x;i++)
	{
		if((grammar[i] >= 'A' && grammar[i] <= 'Z'))  
		{
			::result = 3;
			flag = true;
			count++;
		}
		if (grammar[i] >= 'a' && grammar[i] <= 'z')
		{
			flag = true;
		}
    }
	}
	
	if(( flag ) &&  count < 2)
    {
    	regular( grammar );
	}
}

void context_sensitive( char* grammar )
{
	bool flag = false;
	if((len_x <= len_y) && grammar[y+1])
	{
		::result=2;
		flag = true;
	}
	if( flag )
    {
    	context_free( grammar );
	}
}

void Recursive_enumerable(char* grammar)
{
	bool flag = false;
	for(i=0;i<x;i++)
	{
		if(grammar[i] >= 'A' && grammar[i] <= 'Z') 
		{
			::result = 1;
			flag = true;
			break;
		}
    }
    
    if( flag )
    {
    	context_sensitive( grammar );
	}
}

int main()
{
	int count;
	char grammar[100];
	cout<<"enter the grammar rule\n";
	cin>>grammar;
	for(i=0;i<strlen(grammar);i++)
	{
		if(grammar[i]=='-' && grammar[i+1] == '>')
		{
			::len_x= i;
			::x = i;
			::y= i+1;
			::len_y=(strlen(grammar)-i)-2;
			
			break;
		}
		count++;
	}
	
	Recursive_enumerable(grammar);
	switch (result)
	{
		case 1:{cout<<"it is a recursively enumerable grammar";
			break;
		}
		
		case 2:{cout<<"it is a context sensitive grammar";
			break;
		} 
		
		case 3:{cout<<"it is a context free grammar";
			break;
		} 
		case 4: {cout<<"it is a left linear grammar";
			break;
		}
		
		case 5: {cout<<"it is a right linear grammar";
			break;
		}
		
		default: "sorry it is not a valid grammar";
	}
	if( !result)
	{
		cout<<"sorry it is a invalid grammar";
	}
}
