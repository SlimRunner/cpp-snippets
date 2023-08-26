#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

int main(int argc, char const *argv[])
{
  std::ifstream fs("lines.txt");
  std::stringstream ss;
  std::string s;
  ss << "12 4\n69 420\n";
  int foo;
  while (std::getline(fs, s))
  {
    std::cout << "line: " << s << std::endl;
  }
  
  // ss >> foo;
  // std::cout << foo * foo << std::endl;
  // ss >> foo;
  // std::cout << foo * foo << std::endl;
  return 0;
}
