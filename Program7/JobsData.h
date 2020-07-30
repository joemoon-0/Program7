#ifndef JOBS_DATA_H
#define JOBS_DATA_H

#include <fstream>

class jobsData {
private:
	int arrivalTime;		// A clock tick between 0 - 480 minutes
	char category;			// (A)dmin, (F)aculty, or (S)tudent
	int pages;				// Job size

public:
	jobsData();
	/**
	* PRE: None.
	* POST: Initializes private data members.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	void setArrivalTime(int arrivalTime);
	/**
	* PRE: arrivalTime read from job object.
	* POST: Assigns arrivalTime to private data member.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	void setCategory(char category);
	/**
	* PRE: category read from job object.
	* POST: Assigns category to private data member.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	void setPages(int pages);
	/**
	* PRE: pages read from job object.
	* POST: Assigns pages to private data member.
	* RETURNS: None.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/
	
	int getArrivalTime() const;
	/**
	* PRE: None.
	* POST: None.
	* RETURNS: arrivalTime of job object.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	char getCategory() const;
	/**
	* PRE: None.
	* POST: None.
	* RETURNS: category of job object.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	int getPages() const;
	/**
	* PRE: None.
	* POST: None.
	* RETURNS: pages of job object.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/

	bool ReadData(std::istream& in);
	/**
	* PRE: Input stream opened.
	* POST: Assigns values to private data members from data file.
	* RETURNS: Boolean on successful read.
	* I/O, USER INTERACTION: None.
	* EXCEPTIONS OR ERROR CONDITIONS: None.
	**/
};

#endif // !JOBS_DATA_H