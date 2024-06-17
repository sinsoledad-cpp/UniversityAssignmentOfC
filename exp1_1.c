#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct Node
{
	char name[50];
	int salary;
	struct Node* next;
}SLNode;

void ListInititate(SLNode **head)
{
	*head=(SLNode*)malloc(sizeof(SLNode));
	(*head)->next=NULL;
	(*head)->salary=-1;	
}

void ListAddtion(SLNode *head)
{

	SLNode *temphead=head;
	while(temphead->next!=NULL)
	{
		temphead=temphead->next;
	}

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
		
		temphead->next=addnode;
		temphead=temphead->next;
	}
}
void ListShow(SLNode *head)
{
	SLNode *temphead=head->next;
	do
	{
		printf("%s\t\t%d\n",temphead->name,temphead->salary);
		temphead=temphead->next;
	}while(temphead!=NULL);
	
}
void max_list(SLNode *head)
{
	printf("-----max_list-----\n");
	int maxsalary=0;
	SLNode *temphead1=head->next;
	SLNode *temphead2=head->next;
	while(temphead1!=NULL)
	{
		if(maxsalary<temphead1->salary)
		{
			maxsalary=temphead1->salary;
		}
		temphead1=temphead1->next;
	}
	while(temphead2!=NULL)
	{
		if(temphead2->salary==maxsalary)
		{
			printf("%s\t\t%d\n",temphead2->name,temphead2->salary);
		}
		temphead2=temphead2->next;
	}
}
int main()
{
	SLNode* list=NULL;
	ListInititate(&list);
	ListAddtion(list);
	ListShow(list);
	
	max_list(list);
	return 0;
}
