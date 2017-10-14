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

#include "pcbADT.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//creates the Process Control Block
PCB_p create(unsigned char processPriority, unsigned int processSize) {

	PCB_p proc_p = malloc(sizeof (PCB_s));
	enum state_type initialState = new;
	if (proc_p != NULL) {
		proc_p->pid = 0; // Need to figure out a way to auto generate pid currently
		// hard-coded number 
		proc_p->state = initialState; 
		proc_p->parent = 10; // Hardcoded number for Problem 1
		proc_p->priority = processPriority;
		proc_p->mem = 0;// Unknown for Problem 1 
		proc_p->size = processSize; 
		proc_p->channel_no = 0; // Unknown for Problem 1
		proc_p->context = malloc(sizeof (CPU_context_s)); 

   		proc_p->context->ir = 0;
                proc_p->context->pc = 0;
                proc_p->context->psr = 0;
                proc_p->context->r0 = 0;
                proc_p->context->r1 = 0;
                proc_p->context->r2 = 0;
                proc_p->context->r3 = 0;
                proc_p->context->r4 = 0;
                proc_p->context->r5 = 0;
                proc_p->context->r6 = 0;
		proc_p->context->r7 = 0;
	}
	return proc_p;
}

//destroys the Process Control Block
void destroy(PCB_p target_PCB_p) {
	free(target_PCB_p->context);
	free(target_PCB_p);
}

//returns the value associated with the PID
int get_pid(PCB_p target_PCB_p){
	if (target_PCB_p != NULL )
		return target_PCB_p->pid;
	else {
		printf("Invalid pointer.");
		return 1;
	}
}

//sets the PID
void set_pid(PCB_p target_PCB_p, int new_id) {
	if (target_PCB_p != NULL)
		target_PCB_p->pid = new_id;
	else 
		printf("Invalid pointer.");
}

//Returns the state of the process
enum state_type get_state(PCB_p target_PCB_p) {
	if (target_PCB_p != NULL)
		return target_PCB_p->state;
	return 1;
}

//sets the state of the process
void set_state(PCB_p target_PCB_p, enum state_type new_state) {
	if (target_PCB_p != NULL)
		target_PCB_p->state = new_state;
}

//returns the parent process ID
int get_parent(PCB_p target_PCB_p){
	if (target_PCB_p != NULL)
		return target_PCB_p->parent;
	return 1;
}

//returns the priority level of the process
char get_priority(PCB_p target_PCB_p) {
	if (target_PCB_p != NULL)
		return target_PCB_p->priority;
	return 1;
}

//sets the priority level of the process
void set_priority(PCB_p target_PCB_p, int new_priority){
    if(new_priority < 16 && new_priority >= 0){
        target_PCB_p->priority = new_priority;
    }
    else{
        target_PCB_p->priority = 0;
    }
}

//returns the memory location of the pcb
char* get_mem(PCB_p target_PCB_p) {
	return target_PCB_p->mem;
}

//currently not required, will allow for change of memory address
void set_mem(PCB_p target_PCB_p);

//returns the size of the process
int get_size(PCB_p target_PCB_p) {
	if (target_PCB_p != NULL)
		return target_PCB_p->size;
	return 1;
}

//returns the channel number, assoc. with I/O
char get_channel_no(PCB_p target_PCB_p) {
	if (target_PCB_p != NULL)
		return target_PCB_p->channel_no;
	return 1;
}
//returns the PC, saved in the context of the PCB
int get_pc(PCB_p target_PCB_p) {
	if (target_PCB_p != NULL)
		return target_PCB_p->context->pc;
	return 1;
}

//sets the PC
void set_pc(PCB_p target_PCB_p, unsigned int new_pc) {
	if (target_PCB_p != NULL)
		target_PCB_p->context->pc = new_pc;
}

//returns the IR, saved in the context of the PCB
int get_ir(PCB_p target_PCB_p) {
	if (target_PCB_p != NULL)
		return target_PCB_p->context->ir;
	return 1;
}

//sets the IR
void set_ir(PCB_p target_PCB_p, unsigned int new_ir) {
	if (target_PCB_p != NULL)
		target_PCB_p->context->ir = new_ir;
}

//returns the PSR, saved in the context of the PCB
int get_psr(PCB_p target_PCB_p) {
	if (target_PCB_p != NULL)
		return target_PCB_p->context->psr;
	return 1;
}

//sets the psr
void set_psr(PCB_p target_PCB_p, unsigned int new_psr){
	if (target_PCB_p != NULL)
		target_PCB_p->context->psr = new_psr;
}

//returns the r0, saved in the context of the PCB
int get_r0(PCB_p target_PCB_p) {
	if (target_PCB_p != NULL)
		return target_PCB_p->context->r0;
	return 1;
}

//sets the r0
void set_r0(PCB_p target_PCB_p, unsigned int new_r0){
	if (target_PCB_p != NULL)
		target_PCB_p->context->r0 = new_r0;
}

//returns the r1, saved in the context of the PCB
int get_r1(PCB_p target_PCB_p) {
	if (target_PCB_p != NULL)
		return target_PCB_p->context->r1;
	return 1;
}

//este the r1
void set_r1(PCB_p target_PCB_p, unsigned int new_r1){
	if (target_PCB_p != NULL)
		target_PCB_p->context->r1 = new_r1;
}

//returns the r2, saved in the context of the PCB
int get_r2(PCB_p target_PCB_p) {
	if (target_PCB_p != NULL)
		return target_PCB_p->context->r2;
	return 1;
}

//sets the r2
void set_r2(PCB_p target_PCB_p, unsigned int new_r2){
	if (target_PCB_p != NULL)
		target_PCB_p->context->r2 = new_r2;
}

//returns the r3, saved in the context of the PCB
int get_r3(PCB_p target_PCB_p) {
	if (target_PCB_p != NULL)
		return target_PCB_p->context->r3;
	return 1;
}

//sets the r3
void set_r3(PCB_p target_PCB_p, unsigned int new_r3){
	if (target_PCB_p != NULL)
		target_PCB_p->context->r3 = new_r3;
}

//returns the r4, saved in the context of the PCB
int get_r4(PCB_p target_PCB_p) {
	if (target_PCB_p != NULL)
		return target_PCB_p->context->r4;
	return 1;
}

//sets the r4
void set_r4(PCB_p target_PCB_p, unsigned int new_r4){
	if (target_PCB_p != NULL)
		target_PCB_p->context->r4 = new_r4;
}

//returns the r5, saved in the context of the PCB
int get_r5(PCB_p target_PCB_p) {
	if (target_PCB_p != NULL)
		return target_PCB_p->context->r5;
	return 1;
}

//sets the r5
void set_r5(PCB_p target_PCB_p, unsigned int new_r5){
	if (target_PCB_p != NULL)
		target_PCB_p->context->r5 = new_r5;
}

//returns the r6, saved in the context of the PCB
int get_r6(PCB_p target_PCB_p) {
	if (target_PCB_p != NULL)
		return target_PCB_p->context->r6;
	return 1;
}

//sets the r6
void set_r6(PCB_p target_PCB_p, unsigned int new_r6){
	if (target_PCB_p != NULL)
		target_PCB_p->context->r6 = new_r6;
}

//returns the r7, saved in the context of the PCB
int get_r7(PCB_p target_PCB_p) {
	if (target_PCB_p != NULL)
		return target_PCB_p->context->r7;
	return 1;
}

//sets the r7
void set_r7(PCB_p target_PCB_p, unsigned int new_r7){
	if (target_PCB_p != NULL)
		target_PCB_p->context->r7 = new_r7;
}

//this method produces output to the console
void toString(PCB_p target_PCB_p) {
	if (target_PCB_p != NULL) {
		printf("content: PID: 0x%x, state: %i, ", target_PCB_p->pid, target_PCB_p->state);
		printf("parent: 0x%x, priority: %u, ", target_PCB_p->parent, (unsigned int) target_PCB_p->priority);
		printf("start memory: , size: %u, ", target_PCB_p->size);
		printf("channel_no: %c", (unsigned int) target_PCB_p->channel_no);
                printf("\n");
		// Missing char mem
	} else 
		printf("Invalid Pointer");
}

//this method produces output to the console
void context_toString(PCB_p target_PCB_p) {
    if (target_PCB_p != NULL) {
		printf("ir: %u, pc: %u, psr: %u \n", target_PCB_p->context->ir, target_PCB_p->context->pc, target_PCB_p->context->psr);
		printf("r0: %u, r1: %u, r2: %u, r3: %u \n", target_PCB_p->context->r0, target_PCB_p->context->r1, target_PCB_p->context->r2, target_PCB_p->context->r3);
		printf("r4: %u, r5: %u, r6: %u, r7: %u \n", target_PCB_p->context->r4, target_PCB_p->context->r5, target_PCB_p->context->r6, target_PCB_p->context->r7);
		printf("\n");
	} else 
		printf("Invalid Pointer");
	
}