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
void del_list(SLNode **head,int del)
{
	printf("-----del_list-----\n");
	SLNode *temphead1=*head,*temphead2=NULL;
	while(temphead1!=NULL)
	{
		if(temphead1->salary==del&&temphead2==NULL)
		{
			(*head)=(*head)->next;
			free(temphead1);
			temphead1=(*head);
		}
		else if(temphead1->salary==del)
		{
			temphead2->next=temphead1->next;
			free(temphead1);
			temphead1=temphead2->next;
		}
		else
		{
			temphead2=temphead1;
			temphead1=temphead1->next;
		}
	}
}
int main()
{
	SLNode* list=NULL;
	
	ListAddtion(&list);

	ListShow(list);
	int s;
	scanf("%d",&s);
	del_list(&list,s);
	
	ListShow(list);
	
	return 0;
}
 
