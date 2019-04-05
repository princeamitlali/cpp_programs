#include<stdio.h>
void left_fact(char arr[])
{
	int i=0,j=0,k=0;
	char common[10];
	while(arr[i]!='|')
	{
	i++;}
	i++;
	if(arr[3]!=arr[i])
	printf("Given grammer is deterministic.");
	else
	{j=3;
		while(arr[j]==arr[i])
		{
			common[k]=arr[i];
			k++;i++;j++;
		}
		common[k]='\0';
		printf("Production is non-deterministic.");
		printf("\nProduction after removing left factoring is:\n");
		printf("%c -> ",arr[0]);
		printf("%s",common);
		printf("%c'",arr[0]);
		printf("\n%c' -> ",arr[0]);
		while(arr[j]!='|')
		{
		printf("%c",arr[j]);
		j++;
		}
		printf("|");
		while(arr[i]!='\0')
		{
			printf("%c",arr[i]);
			i++;
		}
	}
}
int main()
{
	char production[10];
	printf("Enter the production rule:");
	gets(production);
	left_fact(production);
	return 0;
}
