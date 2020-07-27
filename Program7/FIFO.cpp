#include "FIFO.h"

#include <iostream>

FIFO::FIFO() : printQueue() {

}


int FIFO::processJob(jobsData job, std::vector<statistics>& stats, int currentTime) {
	return printQueue::processJob(job, stats, currentTime);
}

void FIFO::writeSummary(std::vector<statistics>& stats) {
	std::cout << "Starting with FIFO queue.\n\n";

	printQueue::writeSummary(stats);
}