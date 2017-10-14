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
void pseudo_ISR(CPU_p cpu, interrupt_type state1, PCB_p pcb);
void scheduler(CPU_p cpu, interrupt_type state2, PCB_p pcb);
void dispatcher(CPU_p cpu, PCB_p pcb);

int sysStack;
int num = 0;

int main(void){
    while(num <= 30){//while(1){   //for(;;){
        int r = rand() % 6 + 1;
        int h;
        unsigned int rpc = rand() % 1000 + 3001;
        
        CPU_p cpu = createCPU();
        
        create_processes(r, cpu);
        
        for(h = 0; h < q_size(cpu->newProcessesQueue); h++){
         
            scheduler(cpu, normal, dequeue_newProcessesQueue(cpu)); 
            //printf("HEY! RIGHT HERE: %u", q_size(cpu->readyQueue));
            
        }
        
        
        PCB_p temp = dequeue_readyQueue(cpu);
        
        temp->context->pc += rpc;
        
        sysStack = temp->context->pc;
        
        //theres no type switching logic here because we are only worries about timers for now
        pseudo_ISR(cpu, timer, temp);
        
      num +=1;      
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

void pseudo_ISR(CPU_p cpu, interrupt_type state1, PCB_p pcb){
    set_state(pcb, state1);
    pcb->context->pc = sysStack;
    scheduler(cpu, state1, pcb);
    //printf("test!");
}

void scheduler(CPU_p cpu, interrupt_type state2, PCB_p pcb){
    switch(state2){
        case(timer):
            set_state(pcb, ready);
            enqueue_readyQueue(cpu, pcb);
            printf("enqueued: ");
            toString(pcb);
            context_toString(pcb);
            q_toString(cpu->readyQueue);
            dispatcher(cpu, pcb);
            break;
       case(normal):
            set_state(pcb, ready);
            enqueue_readyQueue(cpu, pcb);
            break;
        
    }
}    
    
void dispatcher(CPU_p cpu, PCB_p pcb){
    int disCounter = 0;
    set_state(pcb, ready);
    PCB_p newPcb = dequeue_readyQueue(cpu);
    set_state(newPcb, running);
    sysStack = newPcb->context->pc;
    if(disCounter == 4){ //problem somewhere in here
        toString(pcb);
        context_toString(pcb);
        printf("switching to: ");
        toString(newPcb);
        context_toString(newPcb);
        toString(newPcb);
        context_toString(newPcb);
        printf("switching to: ");
        toString(getFrontElement(cpu->readyQueue));
        context_toString(getFrontElement(cpu->readyQueue));//possibly an issue here
        q_toString(cpu->readyQueue); //possibly here
    }
    enqueue_readyQueue(cpu, pcb);
    disCounter++;
}    