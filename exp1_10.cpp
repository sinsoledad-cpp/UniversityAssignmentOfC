#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct Student 
{
	int id;
	char name[50];
	int grade;
}stu;


int main()
{
	FILE* fp1 = fopen("t10.dat", "wb");
	if(!fp1)return -1;
	stu *p=(stu*)malloc(sizeof(stu));
	if(!p)return -1;
	while(1)
	{
		printf("id name score(Negative grades indicate the end of the input): ");
		int id;
		char name[50];
		int score;
		scanf("%d %s %d",&id,name,&score);
		if(score==-1)break;
		//printf("%d %s %d\n",id,name,score);
		p->id=id;
		strcpy(p->name,name);
		p->grade=score;
		//printf("%d %s %d\n",p->id,p->name,p->grade);
		fwrite(p,sizeof(stu),1,fp1);
	}
	free(p);
	fclose(fp1);
	
	FILE *fpc=fopen("t10.dat","rb");
	if(!fpc)return -1;
	stu ss[100];
	if(!ss)return -1;
	int n=0;
	while(!feof(fpc))
	{
		fread(&ss[n],sizeof(stu),1,fpc);
		n++;
	}
	for(int i=0;i<n-1;i++)
	{
		printf("%d %s %d\n",ss[i].id,ss[i].name,ss[i].grade);
	}
	fclose(fpc);
	return 0;
}
