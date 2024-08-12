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

public:
  ArgParser(/* args */) = delete;

  ArgParser(int argc, char const *argv[]);

  /// @brief get value of first argument of given flag
  /// @param flag argument flag to search for
  /// @return string of frist argument
  std::string findFirst(std::string flag) const;

  bool findFirst(std::string flag, std::string & out) const;

  /// @brief get list of arguments of given flag
  /// @param flag argument flag to search for
  /// @return vector of arguments
  vecstring findParams(std::string flag) const;

  bool findParams(std::string flag, vecstring & out) const;

  /// @brief determines if provided value exists as an argument flag
  /// @param flag argument flag to search for
  /// @return true if key was found, false otherwise
  bool hasFlag(std::string flag) const;

  /// @brief determines if underlying list is empty
  /// @return true if list is empty, false otherwise
  inline bool empty() const { return m_args.empty(); }

  argmap::const_iterator begin() const;

  argmap::const_iterator end() const;
};

} // namespace System