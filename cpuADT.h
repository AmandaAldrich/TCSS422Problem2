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



typedef struct cpu * CPU_p;


// Functions
CPU_p createCPU();
void destroyCPU(CPU_p);

void enqueue_readyQueue(CPU_p, PCB_p pcb);
PCB_p dequeue_readyQueue();

void enqueue_terminatedQueue(CPU_p, PCB_p pcb);
PCB_p dequeue_terminatedQueue();

void enqueue_newProcessesQueue(CPU_p, PCB_p pcb);
PCB_p dequeue_newProcessesQueue();

#endif CPU_H