/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <stdio.h>
#include <stdlib.h>
#include "pcbADT.h"
#include "queueADT.h"
#include "cpuADT.h"


void create_processes(int rand_proc, CPU_p cpu);
void pseudo_ISR(CPU_p cpu, PCB_p pcb);
void scheduler(CPU_p cpu, interrupt_type state2, PCB_p pcb);
void dispatcher(CPU_p cpu, PCB_p pcb);

int sysStack;
int num = 0;
int switchCount = 1;

int main(void){
    while(num <= 30){//while(1){   //for(;;){
        int r = rand() % 6 + 1;
        int h;
        unsigned int rpc = rand() % 1000 + 3001;
        
        CPU_p cpu = createCPU();
        
        create_processes(r, cpu);
		
		printf("SIZE NEW PROCESSES: %d\n", q_size(cpu->newProcessesQueue));
        
        for(h = 0; h < q_size(cpu->newProcessesQueue); h++){
         
			// call ISR instead of scheduler
            scheduler(cpu, normal, dequeue_newProcessesQueue(cpu)); 
            //printf("HEY! RIGHT HERE: %u", q_size(cpu->readyQueue));
            
        }
        
        
        PCB_p temp = dequeue_readyQueue(cpu);
        
        temp->context->pc += rpc;
        
        sysStack = temp->context->pc;
        
        //theres no type switching logic here because we are only worries about timers for now
        pseudo_ISR(cpu, temp);
        
      num +=1; 
	  switchCount++;
	
    }
}

void create_processes(int rand_proc, CPU_p cpu) {
	
	for (int n = 0; n < rand_proc; n++) {
            int rid = rand() % 50; //just gives a random PID for debugging
        
		// hard-coded parameters for now
		PCB_p pcb = create(0, 10);
                set_pid(pcb, rid);
                set_state(pcb, ready);
               
                enqueue_newProcessesQueue(cpu, pcb);
                //printf("hey!! HEY!!");
                //q_toString(cpu->newProcessesQueue);
                
	}
}

void pseudo_ISR(CPU_p cpu, PCB_p pcb){
    set_state(pcb, interrupted);
    pcb->context->pc = sysStack;
    scheduler(cpu, timer, pcb);
    //printf("test!");
}

void scheduler(CPU_p cpu, interrupt_type state2, PCB_p pcb){
    switch(state2){
        case(timer):
            set_state(pcb, ready);
            enqueue_readyQueue(cpu, pcb);
            printf("-------------------start_of_run-------------------\nenqueued: ");
            toString(pcb);
            context_toString(pcb);
            q_toString(cpu->readyQueue);
            dispatcher(cpu, pcb);
            break;
       case(normal):
            set_state(pcb, ready);
            enqueue_readyQueue(cpu, pcb);
            dispatcher(cpu, pcb);
            break;
        
    }
}    
    
// may not need to pass pcb
void dispatcher(CPU_p cpu, PCB_p pcb){
	
	// int disCounter = 0;
	PCB_p oldProcess = cpu->currentProcess;
	PCB_p newProcess = getFrontElement(cpu->readyQueue);
	
	if(switchCount % 4 == 0) {
    // if(disCounter == 4){ //problem somewhere in here
		printf("Running Process: ");
        toString(oldProcess);
        context_toString(oldProcess);
        printf("Switching to: ");
        toString(newProcess);
        context_toString(newProcess);

        // toString(getFrontElement(cpu->readyQueue));
        // context_toString(getFrontElement(cpu->readyQueue));//possibly an issue here
        q_toString(cpu->readyQueue); // possibly here
    }
	
	// need to save state of current process into its PCB (PC value)
	// somewhere here
	
	// Dequeues the next waiting process
	cpu->currentProcess = dequeue_readyQueue(cpu);
    
	// Changes its state to Running
    set_state(cpu->currentProcess, running);
	
	// Copy PCB->PC value to sysStack to replace
	// the PC of the interrupted process
	sysStack = newProcess->context->pc;
	
	

	// this needs to enqueue oldProcess (I think?), but
	// it gives seg fault error when done so.
    enqueue_readyQueue(cpu, pcb);
    // disCounter++;
}    