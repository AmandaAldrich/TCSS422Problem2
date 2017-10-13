/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <stdlib.h>
#include <stdio.h>
#include "pcbADT.h"
#include "queueADT.h"
#include "cpuADT.h"



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


void enqueue_readyQueue(CPU_p cpu, PCB_p pcb) {
    q_enqueue(cpu->readyQueue, pcb);
}


PCB_p dequeue_readyQueue(CPU_p cpu) {
    return q_dequeue(cpu->readyQueue);
}

void enqueue_terminatedQueue(CPU_p cpu, PCB_p pcb) {
    q_enqueue(cpu->terminatedQueue, pcb);
}

PCB_p dequeue_terminatedQueue(CPU_p cpu) {
    return q_dequeue(cpu->terminatedQueue);
}

void enqueue_newProcessesQueue(CPU_p cpu, PCB_p pcb) {
	q_enqueue(cpu->newProcessesQueue, pcb);
}

PCB_p dequeue_newProcessesQueue(CPU_p cpu) {
    return q_dequeue(cpu->newProcessesQueue);
}