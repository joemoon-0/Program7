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
	/**
	* PRE: None.
	* POST: Initializes private data members.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	int selectJob(std::vector<jobsData>& jobsPending, std::vector<statistics>& stats, int currentTime);
	/**
	* PRE: jobsPending vector populated.
	* POST: Selects job first based on category (A, F, S) then FIFO method.
	* RETURNS: nextAvailableTime when printer will be able to take a job.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	bool getPriorityPending() const;
	/**
	* PRE: None.
	* POST: Toggles status of any jobs pending within priority queues.
	* RETURNS: Boolean on jobs within any priority queue.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	void writeSummary(std::ofstream& out, std::vector<statistics>& stats, int n_categories);
	/**
	* PRE: Output stream opened.
	* POST: Outputs statistical summary based on simulation scenario.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/
};

#endif // !FIFO_H
