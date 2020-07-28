/***
* Joe Moon
* jmn5y@mail.umkc.edu
* CS 201R Summer 2020
* Program 7 - Discrete-Time Simulation
*
* NOTES:
* 
***/

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

#include "JobsData.h"
#include "Statistics.h"
#include "FIFO.h"
#include "SJF.h"
#include "MultiLevel.h"

int main() {
	// CONSTANT VARIABLES
	const int JOB_MINUTES = 480;			// Hours of operation: 9AM to 5 PM
	const int N_SIMULATIONS = 3;			// 1-FIFO, 2-SJF, 3-PRIORITY Simulations
	const int PRINT_CATEGORIES = 3;			// Administration, Faculty, Student
	
	// STREAM VARIABLES
	std::ifstream in;
	std::ofstream out;
	std::string file1 = "data.txt";			// Input data file
	std::string file2 = "output.txt";		// Output summary file

	// PRINTER VARIABLES
	std::queue<jobsData> inputData;			// All jobs, including those not yet arrived
	std::vector<jobsData> jobsPending;		// Jobs that have arrived but not yet handled
	jobsData job;							// Object for print job being read/processed
	bool jobsRemain = true;
	int currentTime = 0;					// Current time on printer
	int jobWaitTime;						// Wait time for a job
	int nextAvailableTime = 0;				// Clock tick when printer will be available for next job

	/* Vector for statistical data from print simulations
	INDEXING: 0-Administration, 1-Faculty, 2-Students */
	std::vector<statistics> jobStats(PRINT_CATEGORIES);	
	
	// SIMULATION OBJECTS
	FIFO jobFIFO;							// FIFO job being processed
	SJF jobSJF;								// SJF job bring processed
	MultiLevel jobMultiLevel;				// Multi-Level job being processed


	for (int simulation = 0; simulation < N_SIMULATIONS; simulation++) {
		// STEP 1: Open and check input file
		in.open(file1);
		if (!in.is_open()) {
			std::cout << "Could not open file: " << file1 << std::endl;
		}
		else {
			// STEP 1A: Read print data file into inputData queue
			while (job.ReadData(in)) {
				inputData.push(job);
			}
		}
		in.close();


		// STEP 2: If printer available, process a job from pending queue
		while (jobsRemain) {
			// STEP 2A: Check that jobs exist, otherwise discontinue printing
			if (inputData.size() == 0 && jobsPending.size() == 0 && !jobMultiLevel.getPriorityPending()) {
				// (No more jobs to be read) && (No jobs pending) && (No jobs waiting in priority queues (Multi-Level SIM))
				jobsRemain = false;
			}
			else {
				// STEP 2B: Check for all new jobs at currentTime.  Add to jobsPending queue.
				while ((inputData.size() > 0) && (inputData.front().getArrivalTime() == currentTime)) {
					jobsPending.push_back(inputData.front());
					inputData.pop();
				}

				// STEP 2C: Process next job based on printer availability
				if ((currentTime >= nextAvailableTime) && 
					(jobsPending.size() > 0 || jobMultiLevel.getPriorityPending())) {			
					// (Printer available) && (Jobs in queue OR Jobs in priority queue (Multi-Level SIM))
										
					switch (simulation) {
					case 0:			/*** FIFO SIMULATION ***/
						nextAvailableTime = jobFIFO.selectJob(jobsPending, jobStats, currentTime);
						break;
					case 1:			/*** SJF SIMULATION ***/
						nextAvailableTime = jobSJF.selectJob(jobsPending, jobStats, currentTime);
						break;
					case 2:			/*** PRIORITY SIMULATION ***/
						nextAvailableTime = jobMultiLevel.selectJob(jobsPending, jobStats, currentTime);
						break;
					}
				}
			}
			currentTime++;
		}
	
		// STEP 3: Output summary statistics to file
		switch (simulation) {
		case 0:
			jobFIFO.writeSummary(jobStats, PRINT_CATEGORIES);
			break;
		case 1:
			jobSJF.writeSummary(jobStats, PRINT_CATEGORIES);
			break;
		case 2:
			jobMultiLevel.writeSummary(jobStats, PRINT_CATEGORIES);
			break;
		}

		// Reset parameters for next simulation
		currentTime = 0;		
		jobsRemain = true;
		nextAvailableTime = 0;
	}

	return 0;
}