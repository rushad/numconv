#include <iostream>

#include "gtest/gtest.h"

GTEST_API_ int main(int argc, char **argv) 
{
  setlocale(LC_ALL, "RUS");
  //setlocale(LC_ALL, "ru_RU.utf8");
  //_setmode(_fileno(stdout), _O_U16TEXT);
  //SetConsoleOutputCP(CP_UTF8);

  if((argc == 2) && (std::string(argv[1]) == "--gtest"))
  {
    std::cout << "Running main() from gtest_main.cc" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }

  return 0;
}
