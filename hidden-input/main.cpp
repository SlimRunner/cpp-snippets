#include <iostream>
#include <sstream>
#include <string>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

char getHiddenChar() {
#ifdef _WIN32
  return _getch();
#else
  struct termios oldt, newt;
  char ch;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return ch;
#endif
}

std::string getHiddenString(std::string prompt) {
  std::stringstream userInput;
  std::cout << prompt;
  char charInput;
  do {
    charInput = getHiddenChar();
    userInput << charInput;
  } while (charInput != '\n');
  return userInput.str();
}

int main() {
  std::string userInput = getHiddenString("Enter a string: ");
  std::cout << "\nYou entered: " << userInput << std::endl;
  return 0;
}
