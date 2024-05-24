#include "Config.h"

Config::Config()
{

}

Config::~Config()
{

}

void Config::loadFromFIle(std::string path)
{
	std::ifstream config(path);
	std::string buf;
	if (config.is_open())
	{
		config >> buf;
		width = std::stoi(buf);
		config >> buf;
		heigth = std::stoi(buf);
		config >> buf;
		aspectRatioX = std::stoi(buf);
		config >> buf;
		aspectRatioY = std::stoi(buf);
		config >> buf;
		threads = std::stoi(buf);
	}
	else
	{
		width = 100;
		heigth = 100;
		aspectRatioX = 1;
		aspectRatioY = 1;
		threads = 1;
	}
	config.close();
}

void Config::copyConfig(Config config)
{
	width = config.getWidth();
	heigth = config.getHeigth();
	threads = config.getThreads();
	aspectRatioX = config.getaspectRatioX();
	aspectRatioY = config.getaspectRatioY();
}

//getters
int Config::getWidth()
{
	return width;
}

int Config::getHeigth()
{
	return heigth;
}

int Config::getaspectRatioX()
{
	return aspectRatioX;
}

int Config::getaspectRatioY()
{
	return aspectRatioY;
}

int Config::getThreads()
{
	return threads;
}

//setters
void Config::setWidth(int num)
{
	width = num;
}

void Config::setHeigth(int num)
{
	heigth = num;
}

void Config::setaspectRatioX(int num)
{
	aspectRatioX = num;
}

void Config::setaspectRatioY(int num)
{
	aspectRatioY = num;
}

void Config::setThreads(int num)
{
	threads = num;
}