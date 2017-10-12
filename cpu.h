#ifndef CPU_H
#define CPU_H

typedef struct cpu * CPU_p;



// Functions
CPU_p createCPU();
void destroyCPU(CPU_p);
QUEUE_p create_processes(QUEUE_p queue, int rand_proc);
void enqueue_readyQueue(CPU_p, PCB_p pcb);
PCB_p dequeue_readyQueue();
void enqueue_terminatedQueue(CPU_p, PCB_p pcb);
PCB_p dequeue_terminatedQueue();
void enqueue_newProcessesQueue(CPU_p, PCB_p pcb);
PCB_p dequeue_newProcessesQueue();
