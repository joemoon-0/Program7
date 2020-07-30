#include "SJF.h"


SJF::SJF() : printQueue() {
	shortestIndex = 0;
}


int SJF::selectJob(std::vector<jobsData>& jobsPending, std::vector<statistics>& stats, int currentTime) {
	jobsData job;												// Job to be processed
	
	// STEP 1: Find shortest pending job
	shortestIndex = findShortestJob(jobsPending);

	// STEP 2: Assign shortest job to object and remove from pending queue
	job = jobsPending.at(shortestIndex);
	jobsPending.erase(jobsPending.begin() + shortestIndex);

	// STEP 3: Process selected job
	return printQueue::processJob(job, stats, currentTime);		// return nextAvailableTime
}


int SJF::findShortestJob(std::vector<jobsData>& jobsPending) {
	int leastPages = jobsPending.at(0).getPages();
	shortestIndex = 0;
	
	for (int i = 1; i < jobsPending.size(); i++) {
		if (jobsPending.at(i).getPages() < leastPages) {
			shortestIndex = i;
			leastPages = jobsPending.at(i).getPages();
		}
	}

	return shortestIndex;
}


void SJF::writeSummary(std::ofstream& out, std::vector<statistics>& stats, int n_categories) {
	out << "Starting with SJF queue.\n\n";

	printQueue::writeSummary(out, stats, n_categories);
}