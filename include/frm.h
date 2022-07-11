#pragma once
#include "Media.h"
#include <vector>
#include <filesystem>

namespace frm
{
	static std::vector<Media> medias;
	
	static struct options
	{
		bool reencode = true;
		bool overwrite = true;
		bool debug = false;
		bool global_output = false;
		std::string global_output_path = "";
	} options;

	inline static bool findByPath(std::string path)
	{
		for (auto media : medias)
		{
			if (media.path == path)
			{
				return true;
			}
		}
		return false;
	}

	inline static bool findByName(std::string name)
	{
		for (auto media : medias)
		{
			if (media.name == name)
			{
				return true;
			}
		}
		return false;
	}

	inline static Media findByName(std::string name, bool& found, int& idx)
	{
		int currId = 0;
		for (auto media : medias)
		{
			if (media.name == name)
			{
				found = true;
				idx = currId;
				return media;
			}
			currId++;
		}
		found = false;
		idx = -1;
		// This is a way of returning nothing, maybe use structured bindings instead
		Media m;
		return m;
	}
}