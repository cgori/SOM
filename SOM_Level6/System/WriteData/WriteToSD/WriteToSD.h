/*
 * WriteToSD.h
 *
 *  Created on: 3 Mar 2020
 *      Author: cmpimard
 */

#ifndef SYSTEM_WRITEDATA_WRITETOSD_WRITETOSD_H_
#define SYSTEM_WRITEDATA_WRITETOSD_WRITETOSD_H_
#include <vector>

class WriteToSD {
public:
	WriteToSD();
	virtual ~WriteToSD();
	std::vector<float> setWriting();
	void SDIntialization();
	void prepareSDFile();
	bool WritingSD(std::vector<float>,std::vector<float>);

private:
	std::vector<float> writing;
};

#endif /* SYSTEM_WRITEDATA_WRITETOSD_WRITETOSD_H_ */
