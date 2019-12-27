#include <configuration.h>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
using namespace handy::common;

const size_t configuration::maximum_line_length = 5000;
const string configuration::blank = " ";
const string configuration::dot = ".";
const string configuration::equals = "=";
const string configuration::comment = "#";



std::string configuration::get_value(const char * key)
{
	return config_collection[key];
}

bool configuration::read(const char * location)
{
	bool returnValue = false;
  
	config_collection.clear();
  
	//char contentsChar[configuration::maximum_line_length + 1];
	//string contents = "";
	//string key = "";
	//string value = "";
	//bool done = false;
	//int bytesRead = 0;
  
	ifstream myfile(location);

	if (myfile.is_open())
	{
		string contents;
		while (getline(myfile, contents)) {
			// get rid of comments
			string::size_type position = contents.find(configuration::comment, 0);
			if (position != string::npos)
			{
				contents = contents.substr(0, position);
			}

			position = contents.find(configuration::equals, 0);
			if (position != string::npos)
			{
				string key = contents.substr(0, position);
				string value = contents.substr(position + 1);

				// remove leading white space
				string::size_type firstNonBlankPosition = key.find_first_not_of(configuration::blank);
				if (firstNonBlankPosition != string::npos)
				{
					key = key.substr(firstNonBlankPosition);
				}
				else
				{
					/// no nonblank characters found in key
					continue;
				}

				// remove trailing white space
				firstNonBlankPosition = key.find_last_not_of(configuration::blank);
				if (firstNonBlankPosition != string::npos)
				{
					key = key.substr(0, firstNonBlankPosition + 1);
				}
				else
				{
					/// no nonblank characters found in key
					continue;
				}

				// remove leading white space
				firstNonBlankPosition = value.find_first_not_of(configuration::blank);
				if (firstNonBlankPosition != string::npos)
				{
					value = value.substr(firstNonBlankPosition);
				}
				else
				{
					/// no nonblank characters found in value
				}

				// remove trailing white space
				firstNonBlankPosition = value.find_last_not_of(configuration::blank);
				if (firstNonBlankPosition != string::npos)
				{
					value = value.substr(0, firstNonBlankPosition + 1);
				}
				else
				{
					/// no nonblank characters found in value
				}

				config_collection[key] = value;
			}
			else
			{
				/// no equals character found in key
				continue;
			}
		}
		returnValue = true;
	}
	

	return returnValue;
}


