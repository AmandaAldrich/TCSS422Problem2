
/*
 * Dat Ly and Amanda Aldrich
 * Problem 1, TCSS 422, Autumn 2017
 * 
 * Basic OS Kernel Structures (ADTs)
 * 
 * A separate driver was include for each ADT, please be aware that each driver 
 * must be run separately of each other, or they will throw an error about 
 * sharing main methods. 
 * 
 * There si commented code that directs the output to a text file automatically
 * however you may also wish to use redirection in the console window. Text files
 * are already included for reading. 
*/
#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"
#include "pcbADT.h"

//simple counter for console output
int j = 0;

//each node holds the pointer to the pcb and the pointer to the next node
typedef struct node {
	PCB_p pcbPtr;
	struct node * NODE_next;
} NODE_s;

//keeps track of information about the queue
typedef struct queue_context {
	NODE_p NODE_front;
	NODE_p NODE_rear;
	unsigned int size; 

} QUEUE_s; 

//creates the queue
QUEUE_p q_create() {

        //assigns memory space and makes sure no stray data is involved
	QUEUE_p queuePtr = malloc (sizeof (QUEUE_s));
	if (queuePtr != NULL) {
		queuePtr->NODE_front = NULL;
		queuePtr->NODE_rear = NULL;
		queuePtr->size = 0;
	}
	return queuePtr;
}

//checks if the queue is empty
// 1 mean queue is empty, 0 otherwise 
int q_is_empty(QUEUE_p target_QUEUE_p) {
	if ((target_QUEUE_p->NODE_front == NULL) && (target_QUEUE_p->NODE_rear == NULL)) {
		return 1; 
	}
	return 0;
}

//returns the size of the queue, how many nodes there are
int q_size(QUEUE_p target_QUEUE_p) {
	return target_QUEUE_p->size;
}

//adds a node to the end of the queue
void q_enqueue(QUEUE_p target_QUEUE_p, PCB_p target_PCB) {
        
        //allocates memory
	NODE_p temp = malloc(sizeof (NODE_s));
        
        //makes sure its not an empty node
	if (temp != NULL) {
		temp->pcbPtr = target_PCB;
                
                //assigns to end of queue unless its the first node to be enqueued
		if (target_QUEUE_p->size == 0) {
			temp->NODE_next = target_QUEUE_p->NODE_front;
			target_QUEUE_p->NODE_front = temp;
			target_QUEUE_p->NODE_rear = target_QUEUE_p->NODE_front;
		} else {
			target_QUEUE_p->NODE_rear->NODE_next = temp;
			target_QUEUE_p->NODE_rear = target_QUEUE_p->NODE_rear->NODE_next;
			target_QUEUE_p->NODE_rear->NODE_next = NULL;
		}
	}
        
        //increases queue size
	(target_QUEUE_p->size)++;
}

//takes a node off the front of the queue
PCB_p q_dequeue(QUEUE_p target_QUEUE_p) {  
        
        //makes sure you have a node to dequeue
	if (target_QUEUE_p->size == 0) {
		printf("\n Error: Trying to display elements from empty queue");
		return NULL;
	} else {
		PCB_p returnPCB = target_QUEUE_p->NODE_front->pcbPtr;
		NODE_p temp = target_QUEUE_p->NODE_front; 
		target_QUEUE_p->NODE_front = target_QUEUE_p->NODE_front->NODE_next;
		free(temp);
		(target_QUEUE_p->size)--;
                j++;
		return returnPCB;
	}
}

//front element method
PCB_p getFrontElement(QUEUE_p target_QUEUE_p){
    return target_QUEUE_p->NODE_front->pcbPtr;
}

//produces console output with pertinent information
void q_toString(QUEUE_p target_QUEUE_p) {

	if(target_QUEUE_p->size > 0) {
		NODE_p curr = target_QUEUE_p->NODE_front;
		int i = 1 + j;
		printf("Q:Count=%u : P%i-", target_QUEUE_p->size, i);   
		while(curr->NODE_next != NULL) { 
			curr = curr->NODE_next;
			++i;
			printf(">P%i-", i);
		}
		printf("* : ");
		toString(curr->pcbPtr);
		printf("end_of_run");
		printf("\n");
	} else {
		printf("Empty Queue\n");
	}

}

//helps organize the output information
void q_helperToString(QUEUE_p target_QUEUE_p) {

	if (q_size(target_QUEUE_p) > 0) {
		NODE_p curr = target_QUEUE_p->NODE_front;
		printf("P%u-", curr->pcbPtr->pid);
		while(curr->NODE_next != NULL) { 
			curr = curr->NODE_next;
			printf(">P%u-", curr->pcbPtr->pid);
		}
		printf("*\n");
	} else {
		printf("Empty Queue\n");
	}
}


