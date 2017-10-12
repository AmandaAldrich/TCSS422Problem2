#include <stdlib.h>
#include <stdio.h>
#include <pcbADT.h>
#include <queueADT.h>

typedef struct cpu {
	unsigned int timer;
	PCB_p currentProcess;
	Queue_p readyQueue;
	Queue_p newProcessesQueue;
	Queue_p terminatedQueue;
} cpu_s;


typedef enum interrupt {
	timer, io;
} interrupt_type;



CPU_p createCPU() {
	CPU_p cpu = malloc(sizeof(cpu));
	cpu->timer = 0;
	cpu->readyQueue = q_create();
	cpu->newProcessesQueue = q_create();
	cpu->terminatedQueue = q_create();
	return cpu;
}

Queue create_processes(Queue_p queue, int rand_proc) {
	
	for (int n = 0; n < rand_proc; n++) {
		// hard-coded parameters for now
		PCB_p pcb = create("new", 10);
	}
}

void destroyCPU(CPU_p cpu) {
	free(cpu);
}


void enqueue_readyQueue(CPU_p, PCB_p pcb) {
	
}


PCB_p dequeue_readyQueue() {
	
}

void enqueue_terminatedQueue(CPU_p, PCB_p pcb) {
	
}

PCB_p dequeue_terminatedQueue() {
	
}

void enqueue_newProcessesQueue(CPU_p, PCB_p pcb) {
	
}

PCB_p dequeue_newProcessesQueue() {
	
}