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

int main() {
	// CONSTANT VARIABLES
	const int JOB_MINUTES = 480;			// Hours of operation: 9AM to 5 PM
	const int N_SIMULATIONS = 3;			// 1-FIFO, 2-SJF, 3-PRIORITY Simulations
	
	// STREAM VARIABLES
	std::ifstream in;
	std::ofstream out;
	std::string file1 = "data.txt";			// Input data file
	std::string file2 = "output.txt";		// Output summary file

	// PRINTER VARIABLES
	std::queue<jobsData> inputData;			// All jobs, including those not yet arrived
	std::queue<jobsData> jobsPending;		// Jobs that have arrived but not yet handled
	jobsData job;							// Object for print job being read/processed
	std::vector<statistics> jobStats(3);	/* Vector for statistical data from print process
											   INDEXING: 0-Administration, 1-Faculty, 2-Students */
	
	bool jobRemain = true;
	int currentTime = 0;					// Current time on printer
	int jobWaitTime;						// Wait time for a job
	int nextAvailableTime = 0;				// Clock tick when printer will be available for next job

	FIFO jobFIFO;							// FIFO job being processed

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


		// STEP 2: Process each minute
		while (jobRemain) {

			// STEP 2A: Check for all new jobs at currentTime.  Add to jobsPending queue.
			while ((inputData.size() > 0) && (inputData.front().getArrivalTime() == currentTime)) {
				jobsPending.push(inputData.front());
				inputData.pop();
			}

			// STEP 2B: Process next job based on printer availability
			if ((currentTime >= nextAvailableTime) && jobsPending.size() > 0) {			// Printer is available && job in queue
				switch (simulation) {
				case 0:			/*** FIFO SIMULATION ***/
					nextAvailableTime = jobFIFO.processJob(jobsPending.front(), jobStats, currentTime);
					jobsPending.pop();			// Remove processed job	
					break;
				case 1:			/*** SJF SIMULATION ***/

					break;
				case 2:			/*** PRIORITY SIMULATION ***/

					break;
				}
			}

			if (inputData.size() == 0 && jobsPending.size() == 0) {
				jobRemain = false;
			}

			currentTime++;
		}
		currentTime = 0;		// Reset currentTime for next simulation
		//jobRemain = true;
		// FIXME: Reset statistics
	}
	// STEP 3: Check front of input data for any new jobs

	// STEP 4: If jobs exist, add to 'jobs pending' queue and remove from data queue

	// STEP 5: If printer available, process a job from pending queue

	// STEP 6: Report summary statistics
	jobFIFO.writeSummary(jobStats);

	return 0;
}