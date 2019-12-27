#include "../include/configuration.h"
#include "gtest/gtest.h"

using namespace handy::common;

TEST(ConfigurationTest, BasicConfigTest){
	configuration config;
	EXPECT_TRUE(config.read("../../test/test.config"));
	std::string value = config.get_value("SAMPLE.TEST.KEY");
	EXPECT_TRUE(strcmp("VALUE", value.c_str()) == 0);

	configuration failConfig;
	EXPECT_FALSE(failConfig.read("./test.config"));
}

