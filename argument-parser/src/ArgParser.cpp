#include "ArgParser.hpp"

namespace System {
ArgParser::ArgParser(int argc, char const *argv[]) :m_args() {
  if (argc <= 0) {
    return;
  }
  std::string keys = "";
  vecstring params = {{argv[0]}};
  for (int i = 1; i < argc; ++i) {
    if (argv[i][0] == '-') {
      m_args.emplace(keys, params);
      params.clear();
      keys = std::string(argv[i]);
    } else {
      params.push_back(std::string(argv[i]));
    }
  }
  m_args.emplace(keys, params);
}

std::string ArgParser::findFirst(std::string flag) const {
  if (hasFlag(flag)) {
    return m_args.at(flag).front();
  }
  return std::string();
}

bool ArgParser::findFirst(std::string flag, std::string &out) const {
  out = findFirst(flag);
  return hasFlag(flag);
}

vecstring ArgParser::findParams(std::string flag) const {
  if (hasFlag(flag)) {
    return m_args.at(flag);
  }
  return vecstring();
}

bool ArgParser::findParams(std::string flag, vecstring &out) const {
  out = findParams(flag);
  return hasFlag(flag);
}

bool ArgParser::hasFlag(std::string flag) const {
  return m_args.find(flag) != m_args.end();
}

argmap::const_iterator ArgParser::begin() const {
  return m_args.begin();
}

argmap::const_iterator ArgParser::end() const {
  return m_args.end();
}

} // namespace System