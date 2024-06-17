#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char word[100][100];



int main()
{
	printf("Enter 10 English words: ");
	int n=10;
	for(int i=0;i<n;i++)
	{
		scanf("%s",word[i]);
	}
//	for(int i=0;i<n;i++)
//	{
//		printf("%s\n",word[i]);
//	}
	
	FILE *fpw=fopen("t9.txt","w");
	if(!fpw)return -1;
	char *pw=(char*)malloc(sizeof(char)*1024);	
	for(int i=0;i<n;i++)
	{
		memset(pw,0,1024);
		strcpy(pw,word[i]);
		strcat(pw,"\n");
		//printf("%s",pw);
		fputs(pw,fpw);
	}
	free(pw);
	fclose(fpw);
	
	FILE *fpr=fopen("t9.txt","r");
	if(!fpr) return -1;
	char *pr=(char*)malloc(sizeof(char)*1024);
	while(!feof(fpr))
	{
		memset(pr,0,1024);
		fgets(pr,1024,fpr);
		printf("%s",pr);
	}
	free(pr);
	fclose(fpr);

	return 0;
}
