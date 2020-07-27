#ifndef PRINT_QUEUE_H
#define PRINT_QUEUE_H

#include <iostream>
#include <math.h>
#include <queue>
#include "JobsData.h"
#include "Statistics.h"


class printQueue {
protected:
	const double PAGES_PER_MINUTE = 150.0;		// Printing speed

	int waitTime;								// Waiting time before processing
	double serviceTime;							// Time required for a job
	int totalJobs;
	int totalWait;
	
public:
	printQueue();
	virtual int processJob(jobsData job, std::vector<statistics>& stats, int currentTime) = 0;
	virtual void writeSummary(std::vector<statistics>& stats) = 0;
};

#endif // !PRINT_QUEUE_H