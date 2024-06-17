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
void combine(SLNode **list1,SLNode **list2,SLNode **result)
{
	printf("-----combine-----\n");
	SLNode *temphead1=*list1,*temphead2=*list2,*tempresult=NULL;
	while(temphead1!=NULL&&temphead2!=NULL)
	{
		if(temphead1->salary<temphead2->salary)
		{
			if(tempresult==NULL)
			{
				tempresult=temphead1;
				*result=tempresult;
			}
			else
			{
				tempresult->next=temphead1;
				tempresult=tempresult->next;
			}
			temphead1=temphead1->next;
		}
		else
		{
			if(tempresult==NULL)
			{
				tempresult=temphead2;
				*result=tempresult;
			}
			else
			{
				tempresult->next=temphead2;
				tempresult=tempresult->next;
			}
			temphead2=temphead2->next;
		}
		
	}
	while(temphead1!=NULL)
	{
		tempresult->next=temphead1;
		temphead1=temphead1->next;
		tempresult=tempresult->next;
	}
	while(temphead2!=NULL)
	{
		tempresult->next=temphead2;
		temphead2=temphead2->next;
		tempresult=tempresult->next;
	}	
	*list1=NULL;
	*list2=NULL;
	tempresult->next=NULL;	
}


int main()
{
	SLNode	*list1=NULL,*list2=NULL;
	
	ListAddtion(&list1);
	ListAddtion(&list2);
	printf("-----list1-----\n");
	ListShow(list1);
	printf("-----list2-----\n");
	ListShow(list2);
	SLNode *list3=NULL;
	combine(&list1,&list2,&list3);
	ListShow(list3);
	
	return 0;
}
 
