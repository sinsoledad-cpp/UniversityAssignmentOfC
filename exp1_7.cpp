#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp1=fopen("t7a1.txt","r");
	FILE *fp2=fopen("t7a2.txt","r");
	if(!fp1)return -1;
	if(!fp2)return -1;
	int row=0,col=-1;
	bool flag=0;
	char *p1=(char*)malloc(sizeof(char)*1000);
	char *p2=(char*)malloc(sizeof(char)*1000);
	while(!feof(fp1)||!feof(fp2))
	{
		memset(p1,0,1000);
		fgets(p1,1000,fp1);
		memset(p2,0,1000);
		fgets(p2,1000,fp2);
		row++;
		int mymax=strlen(p1)<strlen(p2)?strlen(p1):strlen(p2);		
		for(int i=0;i<mymax-1;i++)
		{
			if(p1[i]!=p2[i])
			{
				col=i+1;
				flag=1;
				break;
			}			
		}
		if(flag)break;		
		if(strlen(p1)!=strlen(p2))
		{
			col=mymax;
			flag=1;
			break;
		}		
	}
	if(flag)
	{
		printf("NO row:%d  col:%d\n",row,col);
	}
	else
	{
		printf("YES\n");
	}
	return 0;
}
