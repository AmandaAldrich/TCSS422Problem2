/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cpuADT.h
 * Author: wilso
 *
 * Created on October 12, 2017, 11:08 AM
 */

#ifndef CPU_H
#define CPU_H

typedef enum interrupt {
	timer, io, normal
} interrupt_type;

typedef struct cpu {
	unsigned int timer;
	PCB_p currentProcess;
	QUEUE_p readyQueue;
	QUEUE_p newProcessesQueue;
	QUEUE_p terminatedQueue;
} cpu_s;

typedef struct cpu * CPU_p;


// Functions
CPU_p createCPU();
void destroyCPU(CPU_p);

void enqueue_readyQueue(CPU_p cpu, PCB_p pcb);
PCB_p dequeue_readyQueue(CPU_p cpu);

void enqueue_terminatedQueue(CPU_p cpu, PCB_p pcb);
PCB_p dequeue_terminatedQueue(CPU_p cpu);

void enqueue_newProcessesQueue(CPU_p cpu, PCB_p pcb);
PCB_p dequeue_newProcessesQueue(CPU_p cpu);

#endif