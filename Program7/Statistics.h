#ifndef STATISTICS_H
#define STATISTICS_H

class statistics {
private:
	int waitTime;			// Cummulative wait time
	int jobsHandled;		// Number of jobs processed
	int maxWaitTime;		// Longest wait time

public:
	statistics();
	void jobHandled();
	void addWaitTime(int waitTime);
	void updateMaxWaitTime(int waitTime);
	int getWaitTime() const;
	int getJobsHandled() const;
	int getMaxWaitTime() const;
	void clearStats();
};

#endif // !STATISTICS_H