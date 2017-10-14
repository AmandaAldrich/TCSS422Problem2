/*
 * Jasmine Dacones and Amanda Aldrich, with code from Dat Ly (problem 1)
 * Problem 2, TCSS 422, Autumn 2017
 * 
 * Basic OS Kernel Structures (ADTs)
 * 
 * 
*/

#ifndef QUEUEADT_H
#define QUEUEADT_H

typedef struct node * NODE_p;

typedef struct queue_context * QUEUE_p;

typedef struct pcb * PCB_p;


QUEUE_p q_create(); 
int q_is_empty(QUEUE_p target_QUEUE_p);
int q_size(QUEUE_p target_QUEUE_p);
void q_enqueue(QUEUE_p target_QUEUE_p, PCB_p target_PCB);
PCB_p q_dequeue(QUEUE_p target_QUEUE_p);
PCB_p getFrontElement(QUEUE_p target_QUEUE_p);
void q_toString(QUEUE_p target_QUEUE_p);
void q_helperToString(QUEUE_p target_QUEUE_p);

#endif