#include <stdio.h>
#define max 5

int queue[max];
int front = -1;
int rear = -1;

void insert(){
    int value;
    printf("Enter the value to insert: ");
    scanf("%d", &value);
    if((rear + 1) % max == front){
        printf("Queue is full\n");
    } else {
        if(front == -1) front = 0;
        rear = (rear + 1) % max;
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}

void deletion(){
    if(front == -1){
        printf("Queue is empty\n");
    } else {
        printf("Deleted %d\n", queue[front]);
        if(front == rear){
            front = rear = -1;
        } else {
            front = (front + 1) % max;
        }
    }
}

void display(){
    if(front == -1){
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        int i = front;
        while(i != rear){
            printf("%d ", queue[i]);
            i = (i + 1) % max;
        }
        printf("%d\n", queue[rear]);
    }
}

int main(){ 
    int choice;
	printf("Welcome!");
	printf("\n1.Insert");
	printf("\n2.Deletion");
	printf("\n3.Display");
	printf("\n4.Exit");
	
	do{
		printf("\nKindly enter your choice: ");
	    scanf("%d",&choice);
	
		switch(choice){
		case 1:
			insert();
			break;
		case 2:
			deletion();
			break;
		case 3:
			display();
			break;
		case 4:
			printf("Terminating, Thankyou!");
			break;
		default:
			printf("Invalid choice");
			break;
	    }
	}while(choice!=4);
	return 0;
}