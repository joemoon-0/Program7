#include "Statistics.h"

statistics::statistics() {
	waitTime = 0;
	jobsHandled = 0;
	maxWaitTime = 0;
}

void statistics::jobHandled() {
	jobsHandled++;
}

void statistics::addWaitTime(int waitTime) {
	this->waitTime += waitTime;
}

void statistics::updateMaxWaitTime(int waitTime) {
	maxWaitTime = waitTime;
}

int statistics::getWaitTime() const {
	return waitTime;
}

int statistics::getJobsHandled() const {
	return jobsHandled;
}

int statistics::getMaxWaitTime() const {
	return maxWaitTime;
}

void statistics::clearStats() {
	waitTime = 0;
	jobsHandled = 0;
	maxWaitTime = 0;
}