#ifndef FIFO_H
#define FIFO_H

#include "PrintQueue.h"

class FIFO : public printQueue {
private:


public:
	FIFO();
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
	* POST: Selects job at front of vector and removes it.
	* RETURNS: nextAvailableTime when printer will be able to take a job.
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