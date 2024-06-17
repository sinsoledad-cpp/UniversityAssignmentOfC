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

FILE* createfile(FILE *fp)
{
	stu *p=(stu*)malloc(sizeof(stu));
	while(1)
	{
		printf("id name score(and in ascending order of merit)(Negative grades indicate the end of the input): ");
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
		fwrite(p,sizeof(stu),1,fp);
	}
	free(p);
	return fp;
}

FILE* mergeFile(FILE* fp1, FILE* fp2,FILE* fp3)
{
	printf("-----mergeFile-----\n");
    rewind(fp1);
    rewind(fp2);
    stu temp1, temp2;
    fread(&temp1, sizeof(stu), 1, fp1);
    fread(&temp2, sizeof(stu), 1, fp2);
    while (!feof(fp1)&&!feof(fp2))
    {
        if (temp1.grade <= temp2.grade)
        {
            fwrite(&temp1, sizeof(stu), 1, fp3);
            fread(&temp1, sizeof(stu), 1, fp1);
        }
        else
        {
            fwrite(&temp2, sizeof(stu), 1, fp3);
            fread(&temp2, sizeof(stu), 1, fp2);
        }
    }
    while (!feof(fp1)) {
        fwrite(&temp1, sizeof(stu), 1, fp3);
        fread(&temp1, sizeof(stu), 1, fp1);
    }
    while (!feof(fp2)) {
        fwrite(&temp2, sizeof(stu), 1, fp3);
        fread(&temp2, sizeof(stu), 1, fp2);
    }
    return fp3;
}

void showfile(FILE *fp)
{
	printf("-----show-----\n");
	rewind(fp);
	stu temp;
	while(fread(&temp,sizeof(stu),1,fp))
	{
		printf("%d %s %d\n",temp.id,temp.name,temp.grade);
	}
}


int main()
{
	
	FILE *fp1=fopen("t11a1.dat","wb");
	FILE *fp2=fopen("t11a2.dat","wb");	
	FILE *fp3=fopen("t11a3.dat","wb");	
	if(!fp1||!fp2||!fp3)return -1;
	
	fp1=createfile(fp1);
	fp2=createfile(fp2);
	
	fclose(fp1);
  	fclose(fp2);

    fp1 = fopen("t11a1.dat", "rb");
    fp2 = fopen("t11a2.dat", "rb");
    
    fp1 = fopen("t11a1.dat", "rb");
    fp2 = fopen("t11a2.dat", "rb");

    fp3 = mergeFile(fp1, fp2, fp3);

    fclose(fp3);
    
	fp3 = fopen("t11a3.dat", "rb");
	showfile(fp3);
	
	return 0;
}
