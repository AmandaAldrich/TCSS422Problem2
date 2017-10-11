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
void q_toString(QUEUE_p target_QUEUE_p);
void q_helperToString(QUEUE_p target_QUEUE_p);

#endif