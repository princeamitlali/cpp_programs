#include<stdio.h>
void left_rec(char arr[])
{
	int l=0,m=4;
	char alpha[10],beta[10];
	if(arr[l]!=arr[l+3])
	{
		printf("It is not left recursive.");
	}
	else
	{
       while(arr[m]!='|')
       {
       	alpha[l]=arr[m];
       	l++;m++;
	   }
	  alpha[l]='\0';
	   m++;
	   l=0;
	   while(arr[m]!='\0')
	   {
	   	beta[l]=arr[m];
	   	l++;
	   	m++;
	   }
	   beta[l]='\0';
	   l=0;
	printf("It is left recursive.\nThe new production rule after removing left recursion is:\n");
	printf("%c -> ",arr[l]);
	printf("%s",beta);
	printf("%c'",arr[l]);
	printf("\n%c' -> ",arr[l]);
	printf("%s",alpha);
	printf("%c'|~",arr[l]);	
	}
}
int main()
{
	char production[20];
	printf("Enter the production rule: ");
	gets(production);
	left_rec(production);
	return 0;
}

