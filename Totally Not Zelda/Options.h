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
	void setupConfigFile(std::ofstream& file);
	void parceInitOptions(std::string name, int value);

	void getScreenOptions();
	void getSoundOptions();
	void getControlOptions();

	void setScreenOptions();
	void setSoundOptions();
	void setControlOptions();
private:
	struct config
	{
		int window_x, window_y, 
			audio_volume, 
			controls_up, controls_down, controls_left, controls_right, controls_attack, controls_defend;
	};
	
	const char* FILENAME;
	config optionValues;
};

