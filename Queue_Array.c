#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int queue[MAX];
int front = -1;
int rare = -1;



void enqueue();
void dequeue();
void display();
void getFront();
void getRare();


int main(){
	int choice;

	while(1){

		printf("\n---------------------------------------\n");
                printf("\n 1.Enqueue     \n");
                printf("\n 2.Dequeue   \n");
                printf("\n 3.Display    \n");
                printf("\n 4.Front    \n");
                printf("\n 5.Rare    \n");
                       
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
				getRare();
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

	if(rare==MAX-1){
		printf("Queue Overflow:\n");
	}else{
		printf("Enter the element to be inserted:\n");
        scanf("%d",&item);
        rare = rare+1;
        queue[rare] = item;
        if (front==-1)
        	front = 0;
	}
}

void dequeue(){
	int item;

	if(front==-1){
		printf("Queue Underflow:\n");
	}else{
		
        item = queue[front];
        printf("The dequeue element: %d\t\n",item);
        if (front==rare){
        	front = -1;
        	rare = -1;
        }else{
        	front = front+1;
        }
	}
}

void display(){
	if (front == -1)
	{
		printf("Queue is Empty:\n");
	}else{
		for (int i = front; i <=rare; i++)
		{
			 printf("%d\n",queue[i]);
		}
	}
}


void getFront(){
	if (front == -1)
	{
		printf("Queue is Empty:\n");
	}else{
		
		printf("The front element of the Queue is %d\n",queue[front]);
	}
}

void getRare(){
	if (front == -1)
	{
		printf("Queue is Empty:\n");
	}else{
		
		printf("The rare element of the Queue is %d\n",queue[rare]);
	}
}
