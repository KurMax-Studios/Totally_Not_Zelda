#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
class Options
{
public:
	Options(void);
	~Options(void);
	void initOptions();

	void getScreenOptions();
	void getSoundOptions();
	void getControlOptions();

	void setScreenOptions();
	void setSoundOptions();
	void setControlOptions();
private:
	const char* FILENAME;
};

