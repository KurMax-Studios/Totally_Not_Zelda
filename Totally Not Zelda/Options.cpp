#include "Options.h"


Options::Options(void):FILENAME("config.ini")
{
}


Options::~Options(void)
{
}

void Options::initOptions()
{
	int numbers;
	std::string temp;
	std::fstream file;
	file.open(FILENAME);
	if(!file.is_open())
		exit(3);
	int i=0;
	while(getline(file, temp)){
		if(temp.find_first_of("=")){
			i++;
			
		}
		std::cout << temp << " " << i << std::endl;
		std::cout << temp.find("=") << std::endl;
	}
	
	
}