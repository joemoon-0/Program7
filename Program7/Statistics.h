#ifndef STATISTICS_H
#define STATISTICS_H

class statistics {
private:
	int waitTime;			// Cummulative wait time
	int jobsHandled;		// Number of jobs processed
	int maxWaitTime;		// Longest wait time

public:
	statistics();
	/**
	* PRE: None.
	* POST: Initializes private data members.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	void jobHandled();
	/**
	* PRE: None.
	* POST: Increments jobsHandled by one.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	void addWaitTime(int waitTime);
	/**
	* PRE: None.
	* POST: Adds waitTime to existing total.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	void updateMaxWaitTime(int waitTime);
	/**
	* PRE: None.
	* POST: Reassigns maxWaitTime with new maxWaitTime.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	int getWaitTime() const;
	/**
	* PRE: None.
	* POST: None.
	* RETURNS: waitTime data member.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	int getJobsHandled() const;
	/**
	* PRE: None.
	* POST: None.
	* RETURNS: jobsHandled data member.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	int getMaxWaitTime() const;
	/**
	* PRE: None.
	* POST: None.
	* RETURNS: maxWaitTime data member.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	void clearStats();
	/**
	* PRE: None.
	* POST: Resets private data members to initial values.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/
};

#endif // !STATISTICS_H