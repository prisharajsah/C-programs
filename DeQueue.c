#include <stdio.h>
#define max 5

int dequeue[max];
int front = -1;
int rear = -1;

void insert_rear(){
    int value;
    printf("Enter the value to insert at rear: ");
    scanf("%d", &value);
    if((rear + 1) % max == front){
        printf("Queue is full\n");
    } else {
        if(front == -1) front = 0;
        rear = (rear + 1) % max;
        dequeue[rear] = value;
        printf("Inserted %d at rear\n", value);
    }
}

void insert_front(){
    int value;
    printf("Enter the value to insert at front: ");
    scanf("%d", &value);
    if((rear + 1) % max == front){
        printf("Queue is full\n");
    } else {
        if(front == -1){
            front = rear = 0;                
        } else {
            front = (front - 1 + max) % max;  
        }
        dequeue[front] = value;
        printf("Inserted %d at front\n", value);
    }
}

void delete_front(){
    if(front == -1){
        printf("Dequeue is empty\n");
    } else {
        printf("Deleted %d from front\n", dequeue[front]);
        if(front == rear){
            front = rear = -1;
        } else {
            front = (front + 1) % max;
        }
    }
}

void delete_rear(){
    if(rear == -1){
        printf("Dequeue is empty\n");
    } else {
        printf("Deleted %d from rear\n", dequeue[rear]);
        if(front == rear){
            front = rear = -1;
        } else {
            rear = (rear - 1 + max) % max;
        }
    }
}

void display(){
    if(front == -1){
        printf("Dequeue is empty\n");
    } else {
        printf("Dequeue elements: ");
        int i = front;
        while(1){
            printf("%d ", dequeue[i]);
            if(i == rear){
                break;
            }
            i = (i + 1) % max;
        }
        printf("\n");
    }
}

int main(){
    int choice;

    printf("Welcome!");
    printf("\n1.Insert with rear");
	printf("\n2.Insert with front");
	printf("\n3.Delete using front");
	printf("\n4.Delete using rear");
    printf("\n5.Display");
    printf("\n6.Exit");
	
	do{
		printf("\nKindly enter your choice: ");
	    scanf("%d",&choice);
	
		switch(choice){
		case 1:
			insert_rear();
			break;
		case 2:
			insert_front();
			break;
		case 3:
			delete_front();
			break;
		case 4:
			delete_rear();
			break;
        case 5:            
			display();
			break;
        case 6:
            printf("Terminating, Thank you!");  
            break;
		default:
			printf("Invalid choice");
			break;
	    }
	}while(choice!=6);
	return 0;
}
