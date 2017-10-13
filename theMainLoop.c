/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "pcbADT.h"
#include "queueADT.h"
#include "cpuADT.h"

#include <stdlib.h>
#include <stdio.h>


void create_processes(int rand_proc, CPU_p cpu);
void pseudo_ISR(interrupt_type state1, PCB_p pcb);
void scheduler(CPU_p cpu, interrupt_type state2, PCB_p pcb);
void dispatcher(CPU_p cpu, PCB_p pcb);

int sysStack;

int main(void){
    while(1){   //for(;;){
        int r = rand() % 6 + 1;
        unsigned int rpc = rand() % 4000 + 3000;
        
        CPU_p cpu = createCPU();
        
        create_processes(r, cpu);
        
        PCB_p temp = dequeue_newProcessesQueue();
        temp->context->pc += rpc;
        sysStack = temp->context->pc;
        
        //theres no type switching logic here because we are only worries about timers for now
        pseudo_ISR(timer, temp);
        
            
    }
}

void create_processes(int rand_proc, CPU_p cpu) {
	
	for (int n = 0; n < rand_proc; n++) {
            int rid = rand() % 50; //just gives a random PID for debugging
        
		// hard-coded parameters for now
		PCB_p pcb = create(0, 10);
                set_pid(pcb, rid);
                set_state(pcb, ready);
				// TODO: fix logic of this
                // enqueue_newProcessesQueue(CPU_p->newProcessesQueue, pcb);
				enqueue_newProcessesQueue(cpu, pcb);
	}
}

void pseudo_ISR(interrupt_type state1, PCB_p pcb){
    set_state(pcb, state1);
    pcb->context->pc = sysStack;
    
    
}

void scheduler(CPU_p cpu, interrupt_type state2, PCB_p pcb){
    switch(state2){
        case(timer):
            dispatcher(cpu, pcb);
            break;
            //this is where I/O could go
    }
}    
    
void dispatcher(CPU_p cpu, PCB_p pcb){
    pcb->state = ready;
    enqueue_readyQueue(cpu, pcb);
	PCB_p newPcb = dequeue_readyQueue();
	newPcb->state = running;
	// sysStack = newPcb->pc;
    
    //I'm really confused about whats supposed to happen here
}    