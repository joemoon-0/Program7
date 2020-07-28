#include "FIFO.h"


FIFO::FIFO() : printQueue() {

}


int FIFO::selectJob(std::vector<jobsData>& jobsPending, std::vector<statistics>& stats, int currentTime) {
	jobsData job = jobsPending.front();							// Process first available job
	jobsPending.erase(jobsPending.begin());						// Remove processed job
	return printQueue::processJob(job, stats, currentTime);		// return nextAvailableTime
}

void FIFO::writeSummary(std::vector<statistics>& stats, int simulations) {
	std::cout << "Starting with FIFO queue.\n\n";

	printQueue::writeSummary(stats, simulations);
}