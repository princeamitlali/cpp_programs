#include<stdio.h>
int main()
{
	char str[20];
	int i,j,count=0,k,m;
	printf("enter the unique string : ");
	gets(str);
	printf("Suffixes are  \n");
	for(i=0;str[i]!='\0';i++)
	{count++;
		for(j=i;str[j]!='\0';j++)
		{
			printf("%c",str[j]);
		}
		printf("\n");
	}
	printf("Prefixes are \n");
	for(i=0;str[i]!='\0';i++)
	{
		for(j=0;str[j]!='\0'&&j<=i;j++)
		{
			printf("%c",str[j]);
		}
		printf("\n");
	}
	printf("\nSubstring : \n");
	for(i=0;str[i]!='\0';i++)
	{
		for(j=i;str[j]!='\0';j++)
		{m=0;
			k=count;
			while(k>=0&&m<=j-i)
			{
				printf("%c",str[i+m]);
				k--;
				m++;
			}
			printf("\n");
		}
	}
}
	
