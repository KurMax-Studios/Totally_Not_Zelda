#include "Options.h"


Options::Options(void):FILENAME("config.ini")
{
}


Options::~Options(void)
{
}

void Options::initOptions()
{
	std::ifstream filen(FILENAME);
	std::filebuf* inbuf=0;
	if(filen)
	inbuf  = filen.rdbuf();
	if(inbuf){
		std::cout << FILENAME << " exists continuing reading from file" << std::endl;
		filen.close();
	}
	else{
		std::cout << "File doesnt exist, creating the file:" << FILENAME << std::endl;
		filen.close();
		std::ofstream file(FILENAME);
		setupConfigFile(file);
		file.close();
	}
	

	std::string temp;
	//call only if nothing could be read from file
	
	std::ifstream file(FILENAME);
	std::string name;
	int value;

	if(!file.is_open()){
		exit(4);
	}
	while(getline(file, temp)){
		if(temp.find_first_of("=") != std::string::npos){
			int splitPoint = temp.find_first_of("=");
			name = temp.substr(0, splitPoint);
			value = stoi(temp.substr(splitPoint+1, std::string::npos));
			parceInitOptions(name, value);
		}
	}
	file.close();
}

void Options::parceInitOptions(std::string name, int value){
	if(name == "x")
		optionValues.window_x = value;
	else if(name == "y")
		optionValues.window_y = value;
	else if(name == "volume")
		optionValues.audio_volume = value;
	else if(name == "up")
		optionValues.controls_up = value;
	else if(name == "down")
		optionValues.controls_down = value;
	else if(name == "left")
		optionValues.controls_left = value;
	else if(name == "right")
		optionValues.controls_right = value;
	else if(name == "attack")
		optionValues.controls_attack = value;
	else if(name == "defend")
		optionValues.controls_defend = value;
	else
		std::cout << name << " is not found in " << FILENAME << std::endl;
	std::cout << "reading config file succeded" << std::endl;
}

void Options::setupConfigFile(std::ofstream& file){

	file << "[screen]\n";
	file << "x=800\n";
	file << "y=600\n";
	file << "[audio]\n";
	file << "volume=100\n";
	file << "[controls]\n";
	file << "up=22\n";
	file << "down=18\n";
	file << "left=3\n";
	file << "right=0\n";
	file << "attack=57\n";
	file << "defend=2\n";
	
	file.close();
}