#include<stdio.h>
#include <stdlib.h>
#include<string.h>

struct node
{
  struct node *prev;
  int cc,price;
  char name[20];
  struct node *next;
}*first,*temp,*t,*p;

void create()
{
    int i,cuc,cost;
    char na[20];
    temp=(struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->next=NULL;
    printf("\nEnter Bike CC : ");
    scanf("%d",&cuc);
    printf("Enter the Bike name : ");
    scanf("%s",na);
    printf("Enter the Bike Price : ");
    scanf("%d",&cost);
    strcpy(temp->name,na);
    temp->cc=cuc;
    temp->price=cost;
}
void add()
{
if(first==NULL)
{
create();
first=temp;
t=first;
}
else
{
create();
t->next=temp;
temp->prev=t;
t=temp;
}
}

void display()
{
 p=first;
 while(p!=NULL)
 {
 printf("\nBike CC : %d",p->cc);
 printf("\nBike name : %s",p->name);
 printf("\nBike Price : %d",p->price);
 p=p->next;
 printf("\n\n");
}
 }

void del()
{
 int cuc;
 t=first;
 printf("\nEnter the Bike cc to be deleted:");
 scanf("%d",&cuc);
 while(t->next!=NULL)
        t=t->next;
 if(first->cc==cuc)
 {
  printf("\nDELETED");
  first=first->next;
  free(t);
  return;
 }
 else if(t->cc==cuc)
 {
    printf("DELETED");
    t->prev->next=NULL;
    free(t);
 }
 else
 {
 for(t=first->next;t!=NULL;t=t->next)
 {

 if(t->cc==cuc)
 {
     printf("HELLO");
  struct node *t1=t->next;
  struct node *t2=t->prev;
  printf("\nDELETED");
  t1->prev=t->prev;
  t2->next=t->next;
  free(t);
  return;
 }
 }
 }
 t=t->next;
}

void search()
{
 t=first;
 int cuc;
 printf("\nEnter the Bike CC to be searched : ");
 scanf("%d",&cuc);
 while(t!=NULL)
 {
 if(t->cc==cuc)
 {
 printf("\nThe Bike is found - NAME : %s",t->name);
 printf("\n");
 return;
 }
 t=t->next;
 }
 }


int main()
{
 int choice,n;
 first=NULL;
 while(1)
 {
printf("\n----------------BIKE DETAILS----------------\n");
printf("Press 1 to insert a bike into the list \n");
printf("Press 2 to display the entire list \n");
printf("Press 3 to search the list \n");
printf("Press 4 to delete a bike from the list \n");
printf("Press 0 to exit \n");
printf("---------------------------------------------\n");
 printf("\nEnter your Option :- ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 add();
 break;
 case 2:
 display();
 break;
 case 3:
 search();
 break;
 case 4:
 del();
 break;
 case 0:
 exit(0);
 default:
 printf("\nYou have entered a wrong choice!!");
 }
 }
return 0;
}
