/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "pcbADT.h"



void create_processes(int rand_proc);

int sysStack;

int main(void){
    while(1){   //for(;;){
        int r = rand() % 6 + 1;
        unsigned int rpc = rand() % 4000 + 3000;
        
        CPU_p cpu = createCPU();
        
        create_processes(r);
        
        PCB_p temp = dequeue_newProcessesQueue();
        temp->context->pc += rpc;
        sysStack = temp->context->pc;
        
        //theres no type switching logic here because we are only worries about timers for now
        pseudo_ISR(interrupt timer, temp);
        
            
    }
}

void create_processes(int rand_proc) {
	
	for (int n = 0; n < rand_proc; n++) {
            int rid = rand() % 50; //just gives a random PID for debugging
        
		// hard-coded parameters for now
		PCB_p pcb = create(0, 10);
                set_pid(pcb, rid);
                set_state(pcb, state_type ready);
               
                enqueue_newProcessesQueue(CPU_p->newProcessesQueue, pcb);
	}
}

void pseudo_ISR(enum interrupt timer, PCB_p pcb){
    set_state(pcb, state_type interrupted);
    pcb->context->pc = sysStack;
    
    
}

void scheduler(enum interrupt timer, PCB_p pcb){
    switch(interrupt){
        case(timer):
            dispatcher(pcb);
            break;
            //this is where I/O could go
    }
}    
    
void dispatcher(PCB_p pcb){
    pcb->state = state_type ready;
    enqueue_readyQueue(cpu, pcb);
    
    //I'm really confused about whats supposed to happen here
}    