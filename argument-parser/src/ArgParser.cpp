#include "ArgParser.hpp"

namespace System {
ArgParser::ArgParser(int argc, char const *argv[]) :m_args() {
  if (argc == 1) {
    return;
  }
  std::string keys = "";
  vecstring params;
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

vecstring ArgParser::getKeys() {
  vecstring output;
  output.reserve(m_args.size());
  for (const auto &arg: m_args) {
    output.push_back(arg.first);
  }
  return output;
}

std::string ArgParser::findFirst(std::string key) {
  if (hasKey(key)) {
    return m_args.at(key).front();
  }
  return std::string();
}

vecstring ArgParser::findParams(std::string key) {
  if (hasKey(key)) {
    return m_args.at(key);
  }
  return vecstring();
}

bool ArgParser::hasKey(std::string key) {
  m_matched = m_args.find(key) != m_args.end();
  return m_matched;
}

} // namespace System
