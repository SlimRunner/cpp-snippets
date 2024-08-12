#include <iostream>

/*
In VSCode edit configuration (C/C++) in either UI or JSON
to add the necessary file to allow headers from other folders.
*/

#include "ArgParser.hpp"

int main(int argc, char const *argv[]) {
  System::ArgParser sysArgs(argc, argv);
  for (auto const &flag: sysArgs) {
    std::cout << "<" << flag.first << ">";
    std::cout << " with " << flag.second.size();
    std::cout << " arguments" << "\n";
    for (auto const &arg: flag.second) {
      std::cout << "    ";
      std::cout << arg << "\n";
    }
  }
  std::cout << "\nsuccessful exit\n";
  return 0;
}
