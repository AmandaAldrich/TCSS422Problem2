#include <stdio.h>
#include <stdlib.h>
#include "pcb.h"

unsigned int gpid = 1;


char* getStateString(enum state_type state) {
	switch(state) {
		case new:
			return "new";
		case ready:
			return "ready";
		case running:
			return "running";
		case interrupted:
			return "interrupted";
		case waiting:
			return "waiting";
		case halted:
			return "halted";
		default:
			return "null";
	}
}
	

PCB_p construct() {
	PCB_p pcb = (PCB_p) malloc(sizeof(pcb));

	return pcb;
}

void deconstruct(PCB_p pcb) {
	free(pcb);
	printf("Object deconstructed\n");
}

void setPID(PCB_p pcb) {
	gpid++;
	pcb->pid = gpid;
	printf("%d\n", gpid);
}

void toString(PCB_p pcb) {
	printf("PCB #%d-----------------------------------------------------------------\n", pcb->pid);
	printf("PID: 0x%X, Priority: 0x%02X, State: %s\n", pcb->pid, pcb->priority, getStateString(pcb->state));

}

void toString_context(PCB_p pcb) {
	printf("PC: 0x0, IR: 0x0 PSR: 0x0, r0: 0x0 r1: 0x0 r2: 0x0 r3: 0x0 r4: 0x0 r5: 0x0, r6: 0x0, r7: 0x0\nn");
	
}

void toFile(FILE *f, PCB_p pcb) {
	fprintf(f, "\n\nPCB #%d----------------------------------------------------------------------\r\n", pcb->pid);
	fprintf(f, "\nPID: 0x%X, Priority: 0x%02X, State: %s\r\n", pcb->pid, pcb->priority, getStateString(pcb->state));
	
	fprintf(f, "PC: 0x0, IR: 0x0 PSR: 0x0, r0: 0x0 r1: 0x0 r2: 0x0 r3: 0x0 r4: 0x0 r5: 0x0, r6: 0x0, r7: 0x0\r\n");
	fprintf(f, "\r\n");
	
}

