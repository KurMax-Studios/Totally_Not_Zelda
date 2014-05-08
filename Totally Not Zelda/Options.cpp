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
		m_optionValues.window_x = value;
	else if(name == "y")
		m_optionValues.window_y = value;
	else if(name == "volume")
		m_optionValues.audio_volume = value;
	else if(name == "up")
		m_optionValues.controls_up = value;
	else if(name == "down")
		m_optionValues.controls_down = value;
	else if(name == "left")
		m_optionValues.controls_left = value;
	else if(name == "right")
		m_optionValues.controls_right = value;
	else if(name == "sprint")
		m_optionValues.controls_sprint = value;
	else if(name == "attack")
		m_optionValues.controls_attack = value;
	else if(name == "defend")
		m_optionValues.controls_defend = value;
	else
		std::cout << name << " is not found in " << FILENAME << std::endl;
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
	file << "left=0\n";
	file << "right=3\n";
	file << "attack=57\n";
	file << "sprint=38\n";
	file << "defend=2\n";
	
	file.close();
}
//Send a name of the value you want
int Options::getOption(optionNames option){
	switch (option)
	{
	case Options::SCREEN_X:
		return m_optionValues.window_x;
		break;
	case Options::SCREEN_Y:
		return m_optionValues.window_y;
		break;
	case Options::VOLUME:
		return m_optionValues.audio_volume;
		break;
	case Options::CONTROLS_UP:
		return m_optionValues.controls_up;
		break;
	case Options::CONTROLS_DOWN:
		return m_optionValues.controls_down;
		break;
	case Options::CONTROLS_LEFT:
		return m_optionValues.controls_left;
		break;
	case Options::CONTROLS_RIGHT:
		return m_optionValues.controls_right;
		break;
	case Options::CONTROLS_SPRINT:
		return m_optionValues.controls_sprint;
		break;
	case Options::CONTROLS_ATTACK:
		return m_optionValues.controls_attack;
		break;
	case Options::CONTROLS_DEFEND:
		return m_optionValues.controls_defend;
		break;
	default:
		std::cout << "non-exsisting name for option" << std::endl;
		exit(5);
		break;
	}
}
//TODO fix this so it works and saves the new file only when save is pressed.
void Options::setOption(optionNames option, int KeyCode){
	switch (option)
	{
	case Options::SCREEN_X:
		m_optionValues.window_x = KeyCode;
		break;
	case Options::SCREEN_Y:
		m_optionValues.window_y = KeyCode;
		break;
	case Options::VOLUME:
		m_optionValues.audio_volume = KeyCode;
		break;
	case Options::CONTROLS_UP:
		m_optionValues.controls_up = KeyCode;
		break;
	case Options::CONTROLS_DOWN:
		m_optionValues.controls_down = KeyCode;
		break;
	case Options::CONTROLS_LEFT:
		m_optionValues.controls_left = KeyCode;
		break;
	case Options::CONTROLS_RIGHT:
		m_optionValues.controls_right = KeyCode;
		break;
	case Options::CONTROLS_SPRINT:
		m_optionValues.controls_sprint = KeyCode;
		break;
	case Options::CONTROLS_ATTACK:
		m_optionValues.controls_attack = KeyCode;
		break;
	case Options::CONTROLS_DEFEND:
		m_optionValues.controls_defend = KeyCode;
		break;
	default:
		std::cout << "non-exsisting name for option" << std::endl;
		exit(5);
		break;
	}
	saveOption(option, KeyCode);
}

void Options::saveOption(optionNames option, int KeyCode){
	std::fstream file(FILENAME);
	if(!file.is_open()){
		std::cout << "Could not save changes to " << FILENAME << std::endl;
		exit(6);
	}
	std::vector<std::string> temp;
	temp.resize(100);
	std::vector<std::string> name;
	name.resize(100);
	int i=0;
	while(getline(file, temp[i])){
			if(temp[i].find_first_of("=") != std::string::npos){
				int splitPoint = temp[i].find_first_of("=");
				name[i] = temp[i].substr(0, splitPoint);
				i++;
			}
		}
	file.close();
	temp.resize(i);
	name.resize(i);
	temp[option] = name[option] + "=" + std::to_string(KeyCode);
	//Having problems with overwriting by using fstream, reopening it instead using ofstream
	//type switch vector temp to a list to inseart headers like [screen], [audio] and [controls]
	std::list<std::string> tempList(temp.begin(), temp.end());
	tempList.push_front("[screen]");
	std::list<std::string>::iterator it;
	for(it = tempList.begin();it != tempList.end();it++){
		if(((std::string)*it).find("volume")==0){
			tempList.insert(it, "[audio]");
		}
		if(((std::string)*it).find("up")==0){
			tempList.insert(it, "[controls]");
		}
	}
	std::ofstream writeFile(FILENAME);
	if(!writeFile.is_open()){
		std::cout << "Could not load file:" << FILENAME << std::endl;
		exit(7);
	}
	it = tempList.begin();
	i=0;
	for(it = tempList.begin();it != tempList.end();it++){
		writeFile << *it << std::endl;
		i++;
	}
	writeFile.close();
}