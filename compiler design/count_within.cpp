#include<stdio.h>
#include<conio.h>
int main()
{
	char str[9999];
	printf("Enter your string\n");
	gets(str);
	int count = 0,line = 0,ch=0;
	for(int i = 0;str[i]!='\0';i++)
	{
		if(str[i]==' '&& str[i+1]!= ' ')
		{
			count++;
		}
		if(str[i]=='.' || str[i]=='?')
		{
			line++;
		}
		ch++;
	}
	printf("number of space are %d\n",count);
	printf("number of words are %d\n",count+line);
	printf("number of line are %d\n", line);
	printf("number of character %d",ch-(count+line));
	
}
