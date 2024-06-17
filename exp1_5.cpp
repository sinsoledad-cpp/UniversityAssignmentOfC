#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int A=0,B=0,C=0,D=0,E=0;
	FILE *fp=fopen("t5.txt","r");
	if(!fp)return -1;
	char *p=(char*)malloc(sizeof(char)*1000);
	if(!p)return 0;
	printf("id name score\n");
	while(!feof(fp))
	{
		memset(p,0,1000);
		fgets(p,1000,fp);
		printf("%s",p);
		char *t=strtok(p," ");
		t=strtok(NULL," ");
		t=strtok(NULL," ");
		if(t!=NULL)
		{
			//printf("%s",t);
			int res=0;
			//printf("%d\n",strlen(t));
			for(int i=0;i<strlen(t)-1;i++)
			{
				res=res*10+(t[i]-'0');
			}
			//printf("%d\n",res);
			if(res<0)printf("err\n");
			else if(res<60)E++;
			else if(res<70)D++;
			else if(res<80)C++;
			else if(res<90)B++;
			else if(res<=100)A++;
			else printf("err\n");	
		}		
	}
	printf("count:\n");
	printf("A: %d :",A);
	printf("B: %d :",B);		
	printf("C: %d :",C);
	printf("D: %d :",D);
	printf("E: %d \n",E);
	free(p);
	fclose(fp);
	return 0; 
}

