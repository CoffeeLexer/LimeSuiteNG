#ifdef TESTING

#include "limesuiteng/config.h"
#include <gtest/gtest.h>

LIME_API int run_testing_framework(int argc, char **argv);

int main(int argc, char **argv)
{
    //run_testing_framework(argc, argv);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif // TESTING