#include "PrintQueue.h"

printQueue::printQueue() {
	waitTime = 0;
	serviceTime = 0;
}


int printQueue::processJob(jobsData job, std::vector<statistics>& stats, int currentTime) {
	serviceTime = round((job.getPages() / PAGES_PER_MINUTE) + 2.0);
	waitTime = currentTime - job.getArrivalTime();

	switch(job.getCategory()) {
	case 'A':
		stats.at(0).jobHandled();									// Increment jobsHandled counter
		stats.at(0).addWaitTime(waitTime);							// Add wait time to total
				
		if (waitTime > stats.at(0).getMaxWaitTime()) {
			stats.at(0).updateMaxWaitTime(waitTime);				// Update maxWaitTime
		}
		break;
	case 'F':
		stats.at(1).jobHandled();									// Increment jobsHandled counter
		stats.at(1).addWaitTime(waitTime);							// Add wait time to total

		if (waitTime > stats.at(1).getMaxWaitTime()) {
			stats.at(1).updateMaxWaitTime(waitTime);				// Update maxWaitTime
		}
		break;
	case 'S':
		stats.at(2).jobHandled();									// Increment jobsHandled counter
		stats.at(2).addWaitTime(waitTime);							// Add wait time to total

		if (waitTime > stats.at(2).getMaxWaitTime()) {
			stats.at(2).updateMaxWaitTime(waitTime);				// Update maxWaitTime
		}
		break;
	}

	return (currentTime + serviceTime);								// nextAvailableTime
}

void printQueue::writeSummary(std::vector<statistics>& stats, int n_categories) {
	int totalJobs = 0;												// Overall statistics variable
	int totalWait = 0;												// Overall statistics variable
	
	std::cout << "Summary:\n";
		
	for (int i = 0; i < n_categories; i++) {
		totalJobs += stats.at(i).getJobsHandled();
		totalWait += stats.at(i).getWaitTime();

		switch (i) {
		case 0:
			std::cout << "Administrators:\n";
			break;
		case 1:
			std::cout << "Faculty:\n";
			break;
		case 2:
			std::cout << "Students:\n";
			break;
		}

		std::cout << stats.at(i).getJobsHandled() << " jobs handled." << std::endl;
		std::cout << "Maximum wait: " << stats.at(i).getMaxWaitTime() << " minutes." << std::endl;
		std::cout << "Total waiting time: " << stats.at(i).getWaitTime() << " minutes." << std::endl;
		std::cout << "Average waiting time: " << (stats.at(i).getWaitTime() * 1.0 / stats.at(i).getJobsHandled())
			<< " minutes.\n" << std::endl;

		stats.at(i).clearStats();
	}

	std::cout << "Overall:\n";
	std::cout << totalJobs << " jobs handled." << std::endl;
	std::cout << "Total waiting time: " << totalWait << " minutes." << std::endl;
	std::cout << "Average waiting time: " << (totalWait * 1.0 / totalJobs) << " minutes.\n\n" << std::endl;
	std::cout << "================================================" << std::endl;
}