#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 30

struct bike
{
int cc,cost;
char bikeName[MAX];
struct bike *next;
};

struct bike* insert(struct bike *front, int cuc, char name[], int price)
{
struct bike *newnode;

newnode = (struct bike*) malloc(sizeof(struct bike));
newnode->cc = cuc;
strcpy(newnode->bikeName, name);
newnode->cost = price;

if (newnode == NULL)
{
printf("\nAllocation failed\n");
exit(2);
}
else if(front==NULL)
{
    front=newnode;
    newnode->next=front;
}
else
{
  struct bike *temp = front;
  while(temp->next!= NULL && temp->next!=front)
  {
    temp = temp -> next;
  }
temp -> next = newnode;
newnode -> next = front;
}
return(front);
}
void printNode(struct bike *p)
{
printf("\nBike Details...\n");
printf("\nBike CC : %d", p->cc);
printf("\nName : %s", p->bikeName);
printf("\nPrice On Road : %d\n", p->cost);
printf("-------------------------------------\n");
}

struct bike* deleteNode(struct bike *front, int cuc)
{
struct bike *ptr;
struct bike *bptr;

if (front->cc == cuc)
{
ptr = front;
printf("\nNode deleted:");
printNode(front);
front = front->next;
free(ptr);
return(front);
}

for(ptr=front->next, bptr=front; ptr!=front; ptr=ptr->next, bptr=bptr->next)
{
if (ptr->cc == cuc)
{
printf("\nNode deleted:");
printNode(ptr);
bptr->next = ptr->next;
free(ptr);
return(front);
}
}

printf("\nBike of %d cc is not found ", cuc);
return(front);
}

void search(struct bike *front, int key)
{
struct bike *ptr;

for (ptr = front->next; ptr != front; ptr = ptr -> next)
{
if (ptr->cc == key)
{
printf("\nBike found:");
printNode(ptr);
return;
}
}
printf("\nBike of %d cc is not found ", key);
}

void display(struct bike *front)
{
struct bike *ptr;

for (ptr = front; ptr->next!= front; ptr = ptr->next)
{
printNode(ptr);
}
}

void menu()
{
printf("----------------BIKE DETAILS----------------\n");
printf("Press 1 to insert a bike into the list \n");
printf("Press 2 to delete a bike from the list \n");
printf("Press 3 to display the entire list \n");
printf("Press 4 to search the list \n");
printf("Press 5 to exit \n");
printf("---------------------------------------------\n");
}

int option()
{
int choice;

printf("\nEnter your choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
case 2:
case 3:
case 4:
case 5: return(choice);
default : printf("\nInvalid choice.");
}
return choice;
}

int main()
{
struct bike *linkList;
char name[21];
char choice;
int cc,price;

linkList = NULL;

printf("\nWelcome to Bike Database using singly linked list\n");
menu();
do {
choice = option();
switch(choice)
{
case 1: printf("\nEnter the Bike CC : ");
scanf("%d", &cc);

printf("Enter the Bike name : ");
scanf("%s",&name);

printf("Enter the Bike Cost : ");
scanf("%d",&price);

linkList = insert(linkList, cc, name, price);
break;

case 2: printf("\n\nEnter the bike CC to be deleted: ");
scanf("%d", &cc);

linkList = deleteNode(linkList, cc);
break;


case 3: if (linkList == NULL)
{
printf("\nList empty.");
break;
}
display(linkList);
break;

case 4: printf("\n\nEnter the bike CC to be searched: ");
scanf("%d", &cc);
search(linkList, cc);
break;

case 5: break;
}
} while (choice != 5);
return 0;
}























