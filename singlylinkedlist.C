#include<stdio.h>
#include<conio.h>
struct node{
int info;
struct node *next;
};
typedef struct node Node;
Node *temp=NULL,*head=NULL,*nnode,*t1,*current;
int n,ch,data,i,pos;

void create()
{
   printf("ENter the limit:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
    nnode=(Node*)malloc(sizeof(Node));
    printf("ENter the data:");
    scanf("%d",&data);
    nnode->info=data;
    nnode->next=NULL;
    if(head==NULL)
     temp=head=nnode;
    else{
      temp->next=nnode;
      temp=nnode;
      }
   }
   }
void display()
{
int max,min,sum=0;
    printf("Linked list is: ");
    t1 = head;
    while (t1 != NULL) {
	printf("%d->", t1->info);
	t1 = t1->next;
    }
    printf("NULL\n");
    max = findMax(head);
    if (max != -1)
	printf("Max is: %d\n", max);

    min=findMin(head);
    if(min!=-1)
    printf("Min is:%d\n",min);

    sum=sumNode(head);
    if(sum!=-1)
    printf("Sum is:%d\n",sum);

}


int sumNode(Node *head){
int sum=0;
if (head == NULL) {
	printf("The list is empty\n");
	return -1;
    }
current=head;
while(current!=NULL){
sum+=current->info;
current=current->next;
}
return sum;
}




int findMax(Node *head) {
int max;
    if (head == NULL) {
	printf("The list is empty\n");
	return -1;
    }
    max = head->info;
    current = head->next;
    while (current != NULL) {
	if (current->info > max)
	    max = current->info;
	current = current->next;
    }
    return max;
}

int findMin(Node *head)
{
int min;
min=head->info;
current=head->next;
while(current!=NULL)
{
if(current->info<min)
min=current->info;
current=current->next;
}
return min;
}



void insertbegin()
{
nnode=(Node*)malloc(sizeof(Node));
 printf("Enter the data:");
 scanf("%d",&data);
 nnode->info=data;
 nnode->next=head;
 head=nnode;
 n++;
 }

void insertlast(){
nnode=(Node*)malloc(sizeof(Node));
  printf("Enter the data:");
  scanf("%d",&data);
  nnode->info=data;
  nnode->next=NULL;
  t1=head;
  while(t1->next!=NULL)
    {
     t1=t1->next;
     }
    t1->next=nnode;
  n++;
  }

void insertpos(){
int c=0;
nnode=(Node*)malloc(sizeof(Node));
 printf("Enter the data:");
  scanf("%d",&data);
  nnode->info=data;
  nnode->next=NULL;
 printf("ENter the position:");
 scanf("%d",&pos);
 if(pos==1) {
 nnode->next=head;
 head=nnode;
  }
 else{
 t1=head;
 while(c<pos-1){
 temp=t1;
  t1=t1->next;
  c++;
  }
nnode->next=t1;
temp->next=nnode;
}
n++;
}

void deletefirst(){
 if(head==NULL)
 printf("Underflow");
 temp=head;
 head=head->next;
 free(temp);
 n--;
 }

void deletelast(){
int c=0;
if(head==NULL)
printf("Underflow");
t1=head;
while(c<n-1)
{
temp=t1;
t1=t1->next;
c++;
}
temp->next=NULL;
free(t1);
n--;
}

void deletepos(){
 int c=0;
 if(head==NULL)
printf("Underflow");
printf("ENter the pos:");
scanf("%d",&pos);
t1=head;
while(c<pos-1)
{
temp=t1;
t1=t1->next;
c++;
}
temp->next=t1->next;
n--;
}

int main()
{
clrscr();
do{
printf("1.create\n 2.insert first\n 3.insert last\n 4.insert pos\n 5.delete first\n 6.delete last\n 7.delete pos\n 8.display\n 9.exit\n");
printf("Enter the choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:create(); break;
case 2:insertbegin(); break;
case 3:insertlast(); break;
case 4:insertpos(); break;
case 5:deletefirst(); break;
case 6:deletelast(); break;
case 7:deletepos(); break;
case 8:display();break;
case 9:break;
}
}
while(ch!=9);
getch();
return 0;
}



