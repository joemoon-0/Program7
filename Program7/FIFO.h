#ifndef FIFO_H
#define FIFO_H

#include "PrintQueue.h"

class FIFO : public printQueue {
private:


public:
	FIFO();
	int selectJob(std::vector<jobsData>& jobsPending, std::vector<statistics>& stats, int currentTime);
	void writeSummary(std::vector<statistics>& stats, int n_categories);
};

#endif // !FIFO_H