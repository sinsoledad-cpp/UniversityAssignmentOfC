#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *fp=fopen("t8.txt","w");
	if(!fp)return -1;
	char *p=(char*)malloc(sizeof(char)*1024);
	char *s=(char*)malloc(sizeof(char)*1024);
	if(!p)return 0;
	while(1)
	{
		memset(p,0,1024);
		memset(s,0,1024);
		printf("id name score(Negative grades indicate the end of the input): ");
		scanf("%[^\n]s",p);
		//printf("%s",p); 
		getchar();
		//strcpy(s,p);
		strcat(p,"\n");
		strcpy(s,p);
		char *t=strtok(s," ");
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
			if(res<0)break;
		}
		fputs(p,fp);
	}	
	free(p);
	free(s);
	fclose(fp);
	
	
	FILE *fpr=fopen("t8.txt","r");
	if(!fpr)return -1;
	char *pc=(char*)malloc(sizeof(char)*1024);
	if(!pc)return -1;
	while(!feof(fp))
	{
		memset(pc,0,1024);
		fgets(pc,1024,fpr);
		printf("%s",pc);
	}
	free(pc);
	fclose(fpr);
	return 0;
 } 
