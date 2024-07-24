#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
class Config
{
public:
	Config();
	~Config();

	void loadFromFIle(std::string path);
	void copyConfig(Config config);

	int getWidth();
	int getHeigth();
	int getThreads();
	int getaspectRatioX();
	int getaspectRatioY();

	void setWidth(int num);
	void setHeigth(int num);
	void setThreads(int num);
	void setaspectRatioX(int num);
	void setaspectRatioY(int num);
private:
	int width;
	int heigth;
	int aspectRatioX;
	int aspectRatioY;
	int threads;
};

