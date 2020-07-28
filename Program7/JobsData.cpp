#include "jobsData.h"

jobsData::jobsData() {
	arrivalTime = 0;
	category = ' ';
	pages = 0;
	jobComplete = false;
}

void jobsData::setArrivalTime(int arrivalTime) {
	this->arrivalTime = arrivalTime;
}

void jobsData::setCategory(char category) {
	this->category = category;
}

void jobsData::setPages(int pages) {
	this->pages = pages;
}

void jobsData::markComplete() {
	jobComplete = true;
}

int jobsData::getArrivalTime() const {
	return arrivalTime;
}

char jobsData::getCategory() const {
	return category;
}

int jobsData::getPages() const {
	return pages;
}

bool jobsData::getJobStatus() const {
	return jobComplete;
}

bool jobsData::ReadData(std::istream& in) {
	int time;
	char jobType;
	int size;

	in >> time;
	in >> jobType;
	in >> size;

	setArrivalTime(time);
	setCategory(jobType);
	setPages(size);

	return in.good();
}