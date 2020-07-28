#ifndef MULTI_LEVEL_H
#define MULTI_LEVEL_H

#include "PrintQueue.h"

class MultiLevel : public printQueue {
private:
	std::queue<jobsData> adminQueue;
	std::queue<jobsData> facultyQueue;
	std::queue<jobsData> studentQueue;
	bool priorityPending;

public:
	MultiLevel();
	int selectJob(std::vector<jobsData>& jobsPending, std::vector<statistics>& stats, int currentTime);
	bool getPriorityPending() const;
	void writeSummary(std::vector<statistics>& stats, int n_categories);
};

#endif // !FIFO_H
