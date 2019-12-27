#ifndef JAVAISH_CONFIGURATION_H
#define JAVAISH_CONFIGURATION_H

#include <stddef.h>
#include <map>
#include <string>

namespace handy
{
	namespace common {
		class configuration
		{
		public:
			bool read(const char* location);

			std::string get_value(const char* subject);

		private:
			const static size_t maximum_line_length;
			const static std::string blank;
			const static std::string dot;
			const static std::string equals;
			const static std::string comment;

			std::map<std::string, std::string> config_collection;

		};
	}
}

#endif