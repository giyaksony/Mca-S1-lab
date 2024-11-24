#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
int info;
struct node *next;
};
typedef struct node Node;
Node *temp=NULL,*top=NULL,*nnode;
int c,sum,min,max;
void push(){
nnode=(Node*)malloc(sizeof(Node));
printf("Enter:");
scanf("%d",&nnode->info);
nnode->next=top;
top=nnode;
printf("Inserted\n");
c++;
}

void pop(){
if(top==NULL)   {
printf("Empty");
return;}
temp=top;
top=top->next;
free(top);
c--;
 }

int calSum() {
    temp = top;
    sum = 0;
    while (temp != NULL) {
        sum += temp->info;
        temp = temp->next;
    }
    return sum;
}

int findMax() {
    if (top == NULL) {
	printf("Stack is empty\n");
	return -1;
    }
    temp = top;
    max = temp->info;
    while (temp != NULL) {
	if (temp->info > max) {
	    max = temp->info;
	}
	temp = temp->next;
    }
    return max;
}


int findMin() {
    if (top == NULL) {
	printf("Stack is empty\n");
	return -1;
    }
    temp = top;
    min = temp->info;
    while (temp != NULL) {
        if (temp->info < min) {
            min = temp->info;
        }
        temp = temp->next;
    }
    return min;
}






void display(){
if(top==NULL)   {
printf("Empty");
return;}
printf("List is:");
temp=top;
while(temp!=NULL){
printf("%d->",temp->info);
temp=temp->next;
}
printf("NULL");
printf("\n");
printf("Count is:%d",c);
sum=calSum();
printf("Sum is:%d\t",sum);
printf("Avg is:%f\t",(float)sum/c);
printf("Min is:%d\t",findMin());
printf("Max is:%d\t",findMax());
}

 void main()
 {
 int ch,n;
 printf("Enter the limit:");
 scanf("%d",&n);
 printf("1.push\n 2.pop\n 3.Display\n 4.Exit\n");
 do{
 printf("enter the choice:");
 scanf("%d",&ch);
 switch(ch){
 case 1:push(); break;
  case 2:pop(); break;
   case 3:display(); break;
   case 4:break;
  } }while(ch!=4);

   getch();
   }