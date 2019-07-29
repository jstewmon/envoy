#pragma once

#include <memory>
#include <regex>

namespace Envoy {
namespace Regex {

/**
 * fixfix
 */
class Engine {
public:
  virtual ~Engine() = default;
};

using EnginePtr = std::unique_ptr<Engine>;

/**
 * fixfix
 */
class Matcher {
public:
  Matcher(const envoy::type::matcher::SafeRegexMatcher& matcher);

private:
  EnginePtr engine_;
};

/**
 * Utilities for constructing regular expressions.
 */
class Utility {
public:
  /**
   * Constructs a std::regex, converting any std::regex_error exception into an EnvoyException.
   * @param regex std::string containing the regular expression to parse.
   * @param flags std::regex::flag_type containing parser flags. Defaults to std::regex::optimize.
   * @return std::regex constructed from regex and flags.
   * @throw EnvoyException if the regex string is invalid.
   */
  static std::regex parseRegex(const std::string& regex,
                               std::regex::flag_type flags = std::regex::optimize);
};

}
}
