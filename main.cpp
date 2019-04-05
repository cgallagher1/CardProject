#include <iostream>
using namespace std;

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

int main()
{
    cout << "Hello World!!!" << endl;

    Catch::Session().run();

    return 0;
}
