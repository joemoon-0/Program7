#ifndef FIFO_H
#define FIFO_H

#include <queue>
#include "PrintQueue.h"
//#include "JobsData.h"

class FIFO : public printQueue {
private:


public:
	FIFO();
	int processJob(jobsData job, std::vector<statistics>& stats, int currentTime);
	void writeSummary(std::vector<statistics>& stats);
};

#endif // !FIFO_H