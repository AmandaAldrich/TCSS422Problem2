/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <stdlib.h>
#include <stdio.h>
#include <pcbADT.h>
#include <queueADT.h>

typedef struct cpu {
	unsigned int timer;
	PCB_p currentProcess;
	QUEUE_p readyQueue;
	QUEUE_p newProcessesQueue;
	QUEUE_p terminatedQueue;
} cpu_s;


typedef enum interrupt {
	timer, io
} interrupt_type;



CPU_p createCPU() {
	CPU_p cpu = malloc(sizeof(cpu));
	cpu->timer = 0;
	cpu->readyQueue = q_create();
	cpu->newProcessesQueue = q_create();
	cpu->terminatedQueue = q_create();
	return cpu;
}


void destroyCPU(CPU_p cpu) {
	free(cpu);
}


void enqueue_readyQueue(CPU_p, PCB_p pcb) {
    q_enqueue(CPU_p->readyQueue, pcb);
}


PCB_p dequeue_readyQueue() {
    return q_dequeue(CPU_p->readyQueue);
}

void enqueue_terminatedQueue(CPU_p, PCB_p pcb) {
    q_enqueue(CPU_p->terminatedQueue, pcb);
}

PCB_p dequeue_terminatedQueue() {
    return q_dequeue(CPU_p->terminatedQueue);
}

void enqueue_newProcessesQueue(CPU_p, PCB_p pcb) {
	q_enqueue(CPU_p->newProcessesQueue, pcb);
}

PCB_p dequeue_newProcessesQueue() {
    return q_dequeue(CPU_p->newProcessesQueue, pcb);
}