/***
* Joe Moon
* jmn5y@mail.umkc.edu
* CS 201R Summer 2020
* Program 7 - Discrete-Time Simulation
*
* NOTES ON PROGRAM 7:
*	This program simulates the printing processes for FIFO, SJF, and PRIORITY scenarios.
*	> See PROGRAM7RESULTSDISCUSSION.DOCX for analysis
*
*	** PROGRAM7.CPP **
*	> Print jobs are initially read from file and stored within the "inputData" queue.
*	> Print jobs are moved from the "inputData" queue into a "jobsPending" vector as they arrive by
*		"currentTime" which is the printer's clock.
		(Vector is used to allow for random access when removing the shortest job in SJF.)
*	> If printer is available, "jobsPending" vector is passed into "selectJob" function which chooses
*		an appropriate job object (based on the simulation scenario) to process. Returns when the
*		nextAvailableTime will be for the printer's next job.
*	> Each simulation's statistical data is held in "vector<statistics> jobStats" which is cleared once printed.
*	
*	** FIFO.h, SJF.h, MultiLevel.h **
*	> Each scenario's class has its own "selectJob" function which chooses a job object that is
*		passed by reference from the "jobsPending" vector.
*	> Once the job object has been selected, that object is passed to the "processJob" function within
*		the abstract class PrintQueue.
*		NOTE: "selectJob" receives the entire "jobPending" vector while "processJob" only receives an object.
*	> Statistical data is outputted to file by the "writeSummary" function which is a pure virtual function.
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
	bool jobsRemain = true;					// Condition to continue printing processing
	int currentTime = 0;					// Current time on printer
	int nextAvailableTime = 0;				// Clock tick when printer will be available for next job

	/* Vector for statistical data from print simulations
	INDEXING: 0-Administration, 1-Faculty, 2-Students */
	std::vector<statistics> jobStats(PRINT_CATEGORIES);

	// SIMULATION OBJECTS
	FIFO jobFIFO;							// FIFO job being processed
	SJF jobSJF;								// SJF job bring processed
	MultiLevel jobMultiLevel;				// Multi-Level job being processed

	// STEP 1: Open and check output file
	out.open(file2);
	if (!out.is_open()) {
		std::cout << "Could not open file: " << file2 << std::endl;
	}
	else {
		for (int simulation = 0; simulation < N_SIMULATIONS; simulation++) {
			// STEP 2: Open and check input file
			in.open(file1);
			if (!in.is_open()) {
				std::cout << "Could not open file: " << file1 << std::endl;
			}
			else {
				// STEP 2A: Read data file into inputData queue
				while (job.ReadData(in)) {
					inputData.push(job);
				}
			}
			in.close();

			// STEP 3: Process print jobs based on simulation scenario
			while (jobsRemain) {
				// STEP 3A: Check that jobs exist, otherwise discontinue printing
				if (inputData.size() == 0 && jobsPending.size() == 0 && !jobMultiLevel.getPriorityPending()) {
					// (No more jobs to be read) && (No jobs pending) && (No jobs waiting in priority queues (Multi-Level SIM))
					jobsRemain = false;
				}
				else {
					// STEP 3B: Check for all new jobs at currentTime and add them to jobsPending queue.
					while ((inputData.size() > 0) && (inputData.front().getArrivalTime() == currentTime)) {
						jobsPending.push_back(inputData.front());
						inputData.pop();
					}

					// STEP 3C: Process pending job if printer is available
					if ((currentTime >= nextAvailableTime) && (jobsPending.size() > 0 || jobMultiLevel.getPriorityPending())) {
						// (Printer available) && ((Jobs in queue) OR (Jobs in priority queue (Multi-Level SIM)))

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

			// STEP 4: Output summary statistics to file
			switch (simulation) {
			case 0:
				jobFIFO.writeSummary(out, jobStats, PRINT_CATEGORIES);
				break;
			case 1:
				jobSJF.writeSummary(out, jobStats, PRINT_CATEGORIES);
				break;
			case 2:
				jobMultiLevel.writeSummary(out, jobStats, PRINT_CATEGORIES);
				break;
			}

			// STEP 5: Reset printer parameters for next simulation
			currentTime = 0;
			jobsRemain = true;
			nextAvailableTime = 0;
		}
	}
	out.close();

	return 0;
}