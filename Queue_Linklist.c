#include <stdio.h>
#include <stdlib.h>



struct Node{
	int data;
	struct Node *next;
};


void enqueue();
void dequeue();
void display();
void getFront();
void getRear();


struct Node *front = NULL;
struct Node *rear = NULL;


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

	struct Node *p = (struct Node *)malloc(sizeof(struct Node));

	if (p==NULL)
    {
    	printf("\nOut of Memory Space:\n");
    }else{
    	printf("Enter the element to be inserted:\n");
    	scanf("%d",&item);
    	p->data = item;
    	p->next = NULL;

    	if (front==NULL)
       	 	front = p;
       	else
       		rear->next = p;

       	rear = p;	

    }  	
}

void dequeue(){
	int item;
	struct Node *p;

	if(front==NULL){
		printf("Queue Underflow:\n");
	}else{
		p = front;
        item = front->data;
        printf("The dequeue element: %d\t\n",item);
        if (front==rear){
        	front = NULL;
        	rear = NULL;
        	free(p);
        }else{
        	front = front->next;
        	free(p);
        }
	}
}

void display(){
	struct Node *p;
	if (front == NULL)
	{
		printf("Queue is Empty:\n");
	}else{
		p = front;
		while(p!=NULL){
			printf("%d\n",p->data);
			p = p->next;
		}
	}
}


void getFront(){
	if (front == NULL)
	{
		printf("Queue is Empty:\n");
	}else{
		
		printf("The front element of the Queue is %d\n",front->data);
	}
}

void getRear(){
	if (front == NULL)
	{
		printf("Queue is Empty:\n");
	}else{
		
		printf("The rear element of the Queue is %d\n",rear->data);
	}
}