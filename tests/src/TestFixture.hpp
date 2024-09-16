#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include <gtest/gtest.h>

namespace sw::test
{
    class TestFixture : public ::testing::Test
    {
    public:
        std::string tempLogFileName = "temp_logs.txt";

        void TearDown() override
        {
            remove(tempLogFileName.c_str());
        }

        void runTest(std::string const &testCaseName)
        {
            std::string ExpectedResultPath = EXPECTED_RESULTS_DIR + testCaseName;

            std::string command = EXECUTABLE_PATH + std::string{" "} +
                                  TEST_CASES_DIR + testCaseName + std::string{" 2>&1 | tee "} +
                                  tempLogFileName;

            std::system(command.c_str());

            EXPECT_TRUE(compareFiles(tempLogFileName, ExpectedResultPath));
        }

        bool compareFiles(const std::string &filePath1, const std::string &filePath2)
        {
            std::ifstream file1(filePath1);
            std::ifstream file2(filePath2);

            if (!file1.is_open() || !file2.is_open())
            {
                std::cout << "Failed to open one of the files" << std::endl;
                return false;
            }

            std::string line1, line2;
            int lineNumber = 1;

            while (std::getline(file1, line1) && std::getline(file2, line2))
            {
                if (line1 != line2)
                {
                    std::cout << "Failed to compare! Lines:" << std::endl;
                    std::cout << "RHS Line: " << line1 << std::endl;
                    std::cout << "LHS Line: " << line2 << std::endl;
                    return false;
                }
                lineNumber++;
            }

            file1.close();
            file2.close();

            return true;
        }
    };
}
