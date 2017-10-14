/*
 * Jasmine Dacones and Amanda Aldrich, with code from Dat Ly (problem 1)
 * Problem 2, TCSS 422, Autumn 2017
 * 
 * Basic OS Kernel Structures (ADTs)
 * 
 * 
*/

#ifndef PBCADT_H
#define PBCADT_H

typedef struct cpu_context {     // CPU state for the LC-3 processor     
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
} CPU_context_s;     // _s means this is a structure definition 

typedef CPU_context_s * CPU_context_p; // _p means that this is a pointer to a structure 
 
enum state_type {new, ready, running, interrupted, waiting, halted}; 
 
typedef struct pcb {     // Process control block     
    unsigned int pid;    // process identification     
    enum state_type state;    // process state (running, waiting, etc.)     
    unsigned int parent; // parent process pid     
    unsigned char priority; // 0 is highest – 15 is lowest.     
    unsigned char * mem; // start of process in memory     
    unsigned int size;   // number of bytes in process     
    unsigned char channel_no; // which I/O device or service Q     
    // if process is blocked, which queue it is in     
    CPU_context_p context; // set of cpu registers     
    
    // other items to be added as needed. 

} PCB_s; 
 
typedef PCB_s * PCB_p;

PCB_p create(unsigned char processPriority, unsigned int processSize);
void destroy(PCB_p target_PCB_p); //parameter requires pass in the pointer 

int get_pid(PCB_p target_PCB_p);
void set_pid(PCB_p target_PCB_p, int new_id);

enum state_type get_state(PCB_p target_PCB_p);
void set_state(PCB_p target_PCB_p, enum state_type new_state);

int get_parent(PCB_p target_PCB_p);

char get_priority(PCB_p target_PCB_p);
void set_priority(PCB_p target_PCB_p, int new_priority);

char* get_mem(PCB_p target_PCB_p);
void set_mem(PCB_p target_PCB_p);

int get_size(PCB_p target_PCB_p);

char get_channel_no(PCB_p target_PCB_p);

int get_pc(PCB_p target_PCB_p);
void set_pc(PCB_p target_PCB_p, unsigned int new_pc);

int get_ir(PCB_p target_PCB_p);
void set_ir(PCB_p target_PCB_p, unsigned int new_ir);

int get_psr(PCB_p target_PCB_p);
void set_psr(PCB_p target_PCB_p, unsigned int new_psr);

int get_r0(PCB_p target_PCB_p);
void set_r0(PCB_p target_PCB_p, unsigned int new_r0);

int get_r1(PCB_p target_PCB_p);
void set_r1(PCB_p target_PCB_p, unsigned int new_r1);

int get_r2(PCB_p target_PCB_p);
void set_r2(PCB_p target_PCB_p, unsigned int new_r2);

int get_r3(PCB_p target_PCB_p);
void set_r3(PCB_p target_PCB_p, unsigned int new_r3);

int get_r4(PCB_p target_PCB_p);
void set_r4(PCB_p target_PCB_p, unsigned int new_r4);

int get_r5(PCB_p target_PCB_p);
void set_r5(PCB_p target_PCB_p, unsigned int new_r5);

int get_r6(PCB_p target_PCB_p);
void set_r6(PCB_p target_PCB_p, unsigned int new_r6);

int get_r7(PCB_p target_PCB_p);
void set_r7(PCB_p target_PCB_p, unsigned int new_r7);

void toString(PCB_p target_PCB_p);
void context_toString(PCB_p target_PCB_p);


#endif