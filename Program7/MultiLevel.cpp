#include "MultiLevel.h"


MultiLevel::MultiLevel() : printQueue() {
	priorityPending = false;									// Initially no jobs to process
}


int MultiLevel::selectJob(std::vector<jobsData>& jobsPending, std::vector<statistics>& stats, int currentTime) {
	jobsData job;												// Job to be processed

	// STEP 1: Separate all pending jobs into priority queues
	while (jobsPending.size() > 0) {
		switch (jobsPending.front().getCategory()) {
		case 'A':
			adminQueue.push(jobsPending.front());
			break;
		case 'F':
			facultyQueue.push(jobsPending.front());
			break;
		case 'S':
			studentQueue.push(jobsPending.front());
			break;
		}
		jobsPending.erase(jobsPending.begin());					// Remove job after prioritization
		priorityPending = true;									// Job ready to be printed
	}

	// STEP 2: Assign next job to processed based on priority
	if (adminQueue.size() > 0) {								// Process admin jobs first
		job = adminQueue.front();
		adminQueue.pop();										// Remove selected job
	}
	else if (facultyQueue.size() > 0) {							// No admin jobs pending, process faculty job
		job = facultyQueue.front();
		facultyQueue.pop();										// Remove selected job
	}
	else if (studentQueue.size() > 0) {							// No admin or faculty jobs pending, process student job
		job = studentQueue.front();
		studentQueue.pop();										// Remove selected job
	}
	else {
		priorityPending = false;
	}
	
	// STEP 3: Process selected job
	return printQueue::processJob(job, stats, currentTime);		// return nextAvailableTime
}


bool MultiLevel::getPriorityPending() const {
	return priorityPending;
}

void MultiLevel::writeSummary(std::vector<statistics>& stats, int n_categories) {
	std::cout << "Starting with Multi-level queue.\n\n";

	printQueue::writeSummary(stats, n_categories);
}