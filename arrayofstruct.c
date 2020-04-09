#include<stdio.h>
struct bikes
{
	char name[100],brand[100];
	int cc,price,power,torque,weight;
}r15,rtr1604v,d400,int650;

void display(struct bikes bike);
int main()
{
	int choice;
	struct bikes r15={"YZF-R15 V3","YAMAHA",155,140000,20,15,142};
	struct bikes rtr1604v={"APACHE RTR 160 4V","TVS",160,99000,16,14,147};
	struct bikes d400={"DOMINAR 400","BAJAJ",400,172000,40,35,190};
	struct bikes int650={"INTERCEPTOR 650","ROYAL ENFIELD",650,225000,48,52,210};
	printf("\n1.%s",r15.name);
	printf("\n2.%s",rtr1604v.name);
	printf("\n3.%s",d400.name);
	printf("\n4.%s\n",int650.name);
	printf("\nEnter Your Choice : ");
	scanf("%d",&choice);
	switch(choice)
		{
			case 1:
				display(r15);
				break;
			case 2:
				display(rtr1604v);
				break;
			case 3:
				display(d400);
				break;
			case 4:
				display(int650);
				break;
		}
}
void display(struct bikes model)
{
	printf("\nNAME : %s\n",model.name);
	printf("BRAND : %s\n",model.brand);
	printf("DISPLACEMENT : %dcc\n",model.cc);
	printf("POWER : %d HP\n",model.power);
	printf("TORQUE : %d Nm\n",model.torque);
	printf("WEIGHT : %d KGs\n",model.weight);
	printf("PRICE : RS.%d\n",model.price);
}





















	
