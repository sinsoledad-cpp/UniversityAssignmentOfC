#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct Node
{
	char name[50];
	int salary;
	struct Node* next;
}SLNode;

void ListAddtion(SLNode **head)
{

	SLNode *temphead=*head;

	while(1)
	{
		int salary=0;
		char name[50];
		printf("salary: "); 
		scanf("%d",&salary);
		if(salary==0)
		{
			return;
		}
		printf("name: ");
		scanf("%s",name);
		SLNode *addnode=(SLNode*)malloc(sizeof(SLNode));
		strcpy(addnode->name,name);
		addnode->salary=salary;
		addnode->next=NULL;
		if(*head==NULL)
		{

			*head=addnode;
			temphead=addnode;
		}
		else
		{

			temphead->next=addnode;
			temphead=temphead->next;
		}
	} 

}
void ListShow(SLNode *head)
{
	printf("-----ListShow-----\n");
	SLNode *temphead=head;
	while(temphead!=NULL)
	{

		printf("%s\t\t%d\n",temphead->name,temphead->salary);
		temphead=temphead->next;
	}	
}

void count_list(SLNode *head)
{
	printf("-----count_list-----\n");
	int amount=0,sum=0,number=0;
	SLNode* temphead1=head;
	while(temphead1!=NULL)
	{
		sum+=temphead1->salary;
		amount++;
		temphead1=temphead1->next;
	}
	double average=(double)sum/amount;
	SLNode* temphead2=head;
	while(temphead2!=NULL)
	{
		if(temphead2->salary>average)
		{
			number++;
		}
		temphead2=temphead2->next;
	}
	printf("%d\t%lf\n",number,average);
} 

int main()
{
	SLNode* list=NULL;
	
	ListAddtion(&list);

	ListShow(list);
	
	count_list(list);
	
	return 0;
}
 
