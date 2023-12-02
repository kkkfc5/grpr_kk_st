#include "Commission.h"

int Commission::commCount;
int Commission::activeCommCount;

Commission::Commission() {
	progress = 0;
	commID = 0;
	clientID = 0;
	priority = 0;
	price = 0.00;
	time = 0.00;
	isFinished = false;

	commCount++;
	activeCommCount++;
}

Commission::Commission(int cl, int co, int prio, bool f, double pri, double t, int prog) {
	progress = prog;
	commID = co;
	clientID = cl;
	priority = prio;
	price = pri;
	time = t;
	isFinished = f;

	commCount++;
	activeCommCount++;
}

