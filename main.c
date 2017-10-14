/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "pcbADT.h"
#include "queueADT.h"

QUEUE_p newProcessQ;
QUEUE_p readyQ;
QUEUE_p interruptedQ;
QUEUE_p blockedQ;
QUEUE_p termintatedQ;

PCB_p runningProcess;

int sysStack;
int n = 0;
int hasSwitched = 0;

typedef enum schedulerDecision{
    timer, io, normal} schedulerDecision_type;

void createProcesses();
void scheduler(schedulerDecision_type state);
void dispatcher();
void pseudo_ISR();

int init(){
newProcessQ = q_create();
readyQ = q_create();
interruptedQ = q_create();
blockedQ = q_create();
termintatedQ = q_create();
}

int main(void){
    init();
    while(n < 10){
        
        hasSwitched = 0;
        
        printf("%i\n", n);
        
        createProcesses();
    
        scheduler(normal);
    
        sysStack = get_pc(runningProcess); 
    
        pseudo_ISR();
        
                
        n++;
    }
}

void createProcesses(){
    int r = rand() % 5 + 1;
    int i;
    for(i = 0; i < r; i++){
        PCB_p name = create(i, i);
        set_state(name, new);
        q_enqueue(newProcessQ, name);
    }
}

void scheduler(schedulerDecision_type state){
    switch(state){
        
        case (normal):
            while(q_size(newProcessQ) != 0){
                printf("enqueued: ");
                toString(getFrontElement(newProcessQ));
                q_enqueue(readyQ, q_dequeue(newProcessQ));
                //q_toString(readyQ);
            }
            dispatcher();
            break;
        case (timer):
            set_state(runningProcess, ready);
            q_enqueue(readyQ, runningProcess);
            dispatcher();
            break;
    }
}

void dispatcher(){
    
    int rpc = rand() % 4000 + 3000; //fix this 
    if(n % 4 == 0 && hasSwitched != 1){
        toString(runningProcess);
        printf("switching to: \n");
    }
    runningProcess = q_dequeue(readyQ);
    if(n % 4 == 0 && hasSwitched != 1){
        toString(runningProcess);
        printf("\n");
        toString(runningProcess);
        printf("new ready: \n");
        toString(getFrontElement(readyQ));
        q_toString(readyQ);
    }
    set_state(runningProcess, running);
    set_pc(runningProcess, rpc);
    
    hasSwitched = 1;
    
}

void pseudo_ISR(){
    set_state(runningProcess, interrupted);
    set_pc(runningProcess, sysStack);
    scheduler(timer);
}