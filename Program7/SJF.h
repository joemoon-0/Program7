#ifndef SJF_H
#define SJF_H

#include "PrintQueue.h"

class SJF : public printQueue {
private:
	int shortestIndex;

public:
	SJF();
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
	* POST: Selects job with least pages from vector and removes it.
	* RETURNS: nextAvailableTime when printer will be able to take a job.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	int findShortestJob(std::vector<jobsData>& jobsPending);
	/**
	* PRE: jobsPending vector populated.
	* POST: Searches vector for jobsData object with least pages.
	* RETURNS: Index of jobsData object with least pages.
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

#endif // !SJF_H
