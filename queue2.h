#ifndef QUEUE2_H
#define QUEUE2_H

#include "pcb.h"

typedef struct node {
	PCB_p pcb;
	struct node *next;
} node_s;

typedef node_s * node_p;

typedef struct queue {
	node_p head;
	node_p end;
	int size;
} queue_s;

typedef queue_s * queue_p;

// Functions
queue_p create();
int q_isEmpty(queue_p queue);
void q_enqueue(queue_p queue, PCB_p pcb);
void q_dequeue(queue_p queue);
void destroy(queue_p queue);
void q_toString(queue_p queue, PCB_p pcb);

void writeQueue(queue_p queue, FILE *f); 
#endif

