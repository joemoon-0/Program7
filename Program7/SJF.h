#ifndef SJF_H
#define SJF_H

#include "PrintQueue.h"

class SJF : public printQueue {
private:


public:
	SJF();
	int selectJob(std::vector<jobsData>& jobsPending, std::vector<statistics>& stats, int currentTime);
	void writeSummary(std::vector<statistics>& stats, int n_categories);
};

#endif // !SJF_H
