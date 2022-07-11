#pragma once
#include <string>

enum medtype {VIDEO, AUDIO, FRAME};

struct Media
{
	std::string path;
	std::string name;
	std::string directory;
	std::string format;
	medtype type;
	bool propertyApplied = false;
	Media(std::string name, std::string path, medtype type) : name(name), 
															  path(path.substr(1, path.length() - 2)), 
															  type(type)
	{
		int pos = 0;
		for (auto it = path.rbegin(); it != path.rend(); it++)
		{
			if (*it == '\\' || *it == '/')
			{
				break;
			}
			pos++;
		}
		directory = path.substr(0, path.length() - pos);
		directory.erase(0, 1);
		format = path.substr(path.rfind('.') + 1);
		format.erase(format.size()-1);
	}
	Media() {}
};