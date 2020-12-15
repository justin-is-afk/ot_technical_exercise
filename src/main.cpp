#include "xml_to_html_test.hpp"
#include <string>
#include <gtest/gtest.h>
#include "loguru.hpp"

using namespace std;

int main(int argc, char **argv)
{
	LOG_F(INFO, "Begin XML to HTML Table testing...");
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	return 0;
}
