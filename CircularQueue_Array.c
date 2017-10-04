#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;



void enqueue();
void dequeue();
void display();
void getFront();
void getRear();


int main(){
	int choice;

	while(1){
		printf("\n---------------------------------------\n");
                printf("\n 1.Enqueue     \n");
                printf("\n 2.Dequeue   \n");
                printf("\n 3.Display    \n");
                printf("\n 4.Front    \n");
                printf("\n 5.Rear    \n");
                       
                printf("\n 8.Exit       \n");
        printf("\n---------------------------------------\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		printf("\n---------------------------------------\n");

		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				getFront();
				break;
			case 5:
				getRear();
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



void enqueue(){
	int item;

	if((front==0 && rear==MAX-1)||(rear==front-1)){
		printf("CircularQueue Overflow:\n");
	}else{
		printf("Enter the element to be inserted:\n");
        scanf("%d",&item);

        if (front==-1)//insert 1st element
        {
        	front = rear = 0;
        	queue[rear] = item;
        }else if(rear == MAX-1 && front!=0){
        	rear = 0;
        	queue[rear] = item;
        }else{
        	rear = rear+1;
        	queue[rear] = item;
        }
	}
}

void dequeue(){
	int item;

	if(front==-1){
		printf("CircularQueue Underflow:\n");
	}else{
		
        item = queue[front];
        printf("The dequeue element: %d\t\n",item);
        if (front==rear){
        	front = -1;
        	rear = -1;
        }else if(front == MAX-1){
        	front = 0;
        }else{
        	front = front+1;
        }
	}
}

void display(){
	if (front == -1)
	{
		printf("CircularQueue is Empty:\n");
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
	if (front == -1)
	{
		printf("CircularQueue is Empty:\n");
	}else{
		
		printf("The front element of the CircularQueue is %d\n",queue[front]);
	}
}

void getRear(){
	if (front == -1)
	{
		printf("CircularQueue is Empty:\n");
	}else{
		
		printf("The rear element of the CircularQueue is %d\n",queue[rear]);
	}
}
