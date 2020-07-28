#ifndef JOBS_DATA_H
#define JOBS_DATA_H

#include <fstream>

class jobsData {
private:
	int arrivalTime;		// A clock tick between 0 - 480 minutes
	char category;			// (A)dmin, (F)aculty, or (S)tudent
	int pages;				// Job size
	bool jobComplete;		// Marker for job completion

public:
	jobsData();
	void setArrivalTime(int arrivalTime);
	void setCategory(char category);
	void setPages(int pages);
	void markComplete();
	int getArrivalTime() const;
	char getCategory() const;
	int getPages() const;
	bool getJobStatus() const;
	bool ReadData(std::istream& in);
};

#endif // !JOBS_DATA_H