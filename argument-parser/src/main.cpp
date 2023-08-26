#include <iostream>

/*
In VSCode edit configuration (C/C++) in either UI or JSON
to add the necessary file to allow headers from other folders.
*/

#include "ArgParser.hpp"

int main(int argc, char const *argv[]) {
  System::ArgParser sysArgs(argc, argv);
  for (const auto &flag: sysArgs.getKeys()) {
    std::cout << flag << "\n";
  }
  std::cout << "\nsuccessful exit\n";
  return 0;
}
