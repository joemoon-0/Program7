#ifndef SJF_H
#define SJF_H

#include "PrintQueue.h"

class SJF : public printQueue {
private:
	int shortestIndex;

public:
	SJF();
	int selectJob(std::vector<jobsData>& jobsPending, std::vector<statistics>& stats, int currentTime);
	int findShortestJob(std::vector<jobsData>& jobsPending);
	void writeSummary(std::vector<statistics>& stats, int n_categories);
};

#endif // !SJF_H
