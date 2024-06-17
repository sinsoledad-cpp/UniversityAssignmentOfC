#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int arr1=0,arr2=0,arr3=0,arr4=0,arr5=0;
	FILE *fp=fopen("t6.txt","r");
	if(!fp)return -1;
	char *p=(char*)malloc(sizeof(char)*1000);
	if(!p)return 0;
	while(!feof(fp))
	{
		memset(p,0,1000);
		fgets(p,1000,fp);
		printf("%s",p);
		arr1++;
		//printf("%d\n",strlen(p));
		for(int i=0;i<strlen(p)-1;i++)
		{
			if(p[i]>='A'&&p[i]<='Z')arr2++;
			else if(p[i]>='a'&&p[i]<='z')arr3++;
			else if(p[i]>='0'&&p[i]<='9')arr4++;
			else arr5++;
		}
	}
	
	printf("\nrow %d \n",arr1);
	printf("upper case %d \n",arr2);
	printf("lower case %d \n",arr3);
	printf("number %d \n",arr4);
	printf("other characters %d \n",arr5);
	fclose(fp);
	return 0;
}
