#ifndef PRINT_QUEUE_H
#define PRINT_QUEUE_H

#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include "JobsData.h"
#include "Statistics.h"


class printQueue {
protected:
	const double PAGES_PER_MINUTE = 150;		// Printing speed
	int waitTime;								// Waiting time before processing
	double serviceTime;							// Time required for a job
	
public:
	printQueue();
	int processJob(jobsData job, std::vector<statistics>& stats, int currentTime);
	virtual void writeSummary(std::vector<statistics>& stats, int n_categories) = 0;
};

#endif // !PRINT_QUEUE_H