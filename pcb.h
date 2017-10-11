#include <stdio.h>
#ifndef PCB_H
#define PCB_H

typedef struct cpu_context {     
	// CPU state for the LC-3 processor     
	unsigned int pc;     
	unsigned int ir;     
	unsigned int psr;     
	unsigned int r0;     
	unsigned int r1;     
	unsigned int r2;     
	unsigned int r3;     
	unsigned int r4;     
	unsigned int r5;     
	unsigned int r6;     
	unsigned int r7; 
} CPU_context_s; 

typedef CPU_context_s * CPU_context_p;

typedef enum state_type {
	new, ready, running, interrupted, waiting, halted
} State;

typedef struct pcb {
	unsigned int pid;    // process identification  
	State state;
	unsigned int parent; // parent process pid     
	unsigned char priority; // 0 is highest – 15 is lowest.     
	unsigned char * mem; // start of process in memory     
	unsigned int size;   // number of bytes in process     
	unsigned char channel_no; // which I/O device or service Q     
	// if process is blocked, which queue it is in     
	CPU_context_p context; 
} PCB_s;

typedef PCB_s * PCB_p;

// Functions
PCB_p construct();
void deconstruct(PCB_p pcb);
void toString(PCB_p pcb);
void toString_context(PCB_p pcb);
void setPID(PCB_p pcb);
void toFile(FILE *f, PCB_p);

#endif
