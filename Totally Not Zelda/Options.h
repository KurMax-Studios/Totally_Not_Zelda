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
	
	enum optionNames{SCREEN_X,SCREEN_Y,
		VOLUME,
		CONTROLS_UP,CONTROLS_DOWN,CONTROLS_LEFT,CONTROLS_RIGHT,CONTROLS_SPRINT,CONTROLS_ATTACK,CONTROLS_DEFEND
	};

	int getOption(optionNames option);

	void setOption();
	
private:
	struct config
	{
		int window_x, window_y, 
			audio_volume, 
			controls_up, controls_down, controls_left, controls_right, controls_sprint,controls_attack, controls_defend;
	};
	
	const char* FILENAME;
	config m_optionValues;
};

