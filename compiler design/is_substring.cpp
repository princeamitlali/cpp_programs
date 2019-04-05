#include<stdio.h>
#include<string.h>
int main()
{
	char first[100],second[100];
	int fi,se,i,j,found=0;
	printf("Enter first string\n");
	gets(first);
	printf("enter the second string\n");
	gets(second);
	fi = strlen(first);
	se = strlen(second);
	if(se>fi)
	{
		printf("not possible");
	}
	else
	{
		for(i = 0 ; i < fi;i++)
		{
			for(j = 0; j < se ; j++)
			{
				if(first[i+j] != second[j])
				{
					found++;
					break;
				}
			}
		}
		
	}
	if(i ==found)
	{
		printf("not found");
	}
	else
	{
		printf("found");
	}
	return 0;
}
