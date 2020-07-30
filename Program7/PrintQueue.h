#ifndef PRINT_QUEUE_H
#define PRINT_QUEUE_H

#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include "JobsData.h"
#include "Statistics.h"


class printQueue {
private:
	const double PAGES_PER_MINUTE = 150;		// Printing speed
	int waitTime;								// Waiting time before processing
	double serviceTime;							// Time required for a job
	
public:
	printQueue();
	/**
	* PRE: None.
	* POST: Initializes private data members.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	int processJob(jobsData job, std::vector<statistics>& stats, int currentTime);
	/**
	* PRE: job object selected for processing based on simulation scenario.
	* POST: Updates statistical data for selected job.
	* RETURNS: nextAvailableTime when printer will be able to take a job.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	virtual void writeSummary(std::ofstream& out, std::vector<statistics>& stats, int n_categories) = 0;
	/**
	* PRE: Output stream opened.
	* POST: Outputs statistical summary based on simulation scenario.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/
};

#endif // !PRINT_QUEUE_H