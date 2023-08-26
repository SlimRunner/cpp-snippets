#pragma once

#include <map>
#include <string>
#include <vector>

namespace System {
using vecstring = std::vector<std::string>;
using argmap = std::map<std::string, vecstring>;

class ArgParser {
private:
  argmap m_args;
  bool m_matched;

public:
  ArgParser(/* args */) = delete;

  ArgParser(int argc, char const *argv[]);

  vecstring getKeys();

  std::string findFirst(std::string key);

  vecstring findParams(std::string key);

  bool hasKey(std::string key);

  /**
   * @brief Determines the result of last search performed
   * 
   * @return true if last search succeeded
   * @return false if last search failed
   */
  inline bool found() { return m_matched; };
};

} // namespace System
