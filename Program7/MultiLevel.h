#ifndef MULTI_LEVEL_H
#define MULTI_LEVEL_H

#include "PrintQueue.h"

class MultiLevel : public printQueue {
private:


public:
	MultiLevel();
	int selectJob(std::vector<jobsData>& jobsPending, std::vector<statistics>& stats, int currentTime);
	void writeSummary(std::vector<statistics>& stats, int n_categories);
};

#endif // !FIFO_H
