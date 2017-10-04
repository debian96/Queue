#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = 0;


bool isFull();
bool isEmpty();
void insertFront();
void insertRear();
void deleteFront();
void deleteRear();
void display();
void getFront();
void getrear();


int main(){
	int choice;

	while(1){

		printf("\n---------------------------------------\n");
                printf("\n 1.Insert Front     \n");
                printf("\n 2.Insert Rear   \n");
                printf("\n 3.Delete Front   \n");
                printf("\n 4.Delete Rear   \n");
                printf("\n 5.Display    \n");
                printf("\n 6.Front    \n");
                printf("\n 7.rear    \n");
                       
                printf("\n 8.Exit       \n");
        printf("\n---------------------------------------\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		printf("\n---------------------------------------\n");

		switch(choice)
		{
			case 1:
				insertFront();
				break;
			case 2:
				insertRear();
				break;
			case 3:
				deleteFront();
				break;
			case 4:
				deleteRear();
				break;
			case 5:
				display();
				break;
			case 6:
				getFront();
				break;
			case 7:
				getrear();
				break;
			case 8:
			    exit(0);
                break;          
            default:
                printf("\n Wrong Choice:\n");
                break;
		}
	}
}

bool isFull(){
	return ((front == 0 && rear == MAX-1)||(rear == front-1));
}

bool isEmpty(){
	return (front == -1);
}

void insertFront(){
	int item;

	if(isFull()){
		printf("Dequeue Overflow:\n");
	}else{
		printf("Enter the element to be inserted front:\n");
        scanf("%d",&item);

        if (front==-1)//insert 1st element
        {
        	front = rear = 0;
        	queue[front] = item;
        }else if(front==0){
        	front = MAX-1;
        	queue[front] = item;
        }else{
        	front = front-1;
        	queue[front] = item;
        }
	}
}


void insertRear(){
	int item;

	
	if(isFull()){
		printf("Dequeue Overflow:\n");
	}else{
		printf("Enter the element to be inserted rear:\n");
        scanf("%d",&item);


        if (front==-1)//insert 1st element
        {
        	front = rear = 0;
        	queue[rear] = item;
        }else if(rear==MAX-1){
        	rear=0;
        	queue[rear] = item;
        }else{
        	rear = rear+1;
        	queue[rear] = item;
        }
	}
}

void deleteFront(){
	int item;

	if(isEmpty()){
		printf("Dequeue Underflow:\n");
	}else{
		item = queue[front];
        printf("The dequeue element from front: %d\t\n",item);
        if (front==rear)//insert 1st element
        {       	
        	front = rear = -1;       	
        }else if(front==MAX-1){
        	front=0;
        }else{
        	front = front+1;
        }
	}
}

void deleteRear(){
	int item;

	if(isEmpty()){
		printf("Dequeue Underflow:\n");
	}else{
		item = queue[rear];
        printf("The dequeue element from rear: %d\t\n",item);
        if (front==rear)//insert 1st element
        {       	
        	front = rear = -1;       	
        }else if(rear==0){
        	rear=MAX-1;
        }else{
        	rear = rear-1;
        }
	}
}




void display(){
	if (isEmpty())
	{
		printf("Dequeue is Empty:\n");
	}else if(rear>front){
		for (int i = front; i <=rear; i++)
		{
			 printf("%d\n",queue[i]);
		}
	}else if(rear==front){
		printf("%d\n",queue[rear]);
	}else{
		for (int i = front; i <MAX; i++)
		{
			 printf("%d\n",queue[i]);
		}
		for (int i = 0; i <=rear; i++)
		{
			 printf("%d\n",queue[i]);
		}
	}
}


void getFront(){
	if (isEmpty())
	{
		printf("Dequeue is Empty:\n");
	}else{
		
		printf("The front element of the Dequeue is %d\n",queue[front]);
	}
}

void getrear(){
	if (isEmpty())
	{
		printf("Dequeue is Empty:\n");
	}else{
		
		printf("The rear element of the Dequeue is %d\n",queue[rear]);
	}
}
