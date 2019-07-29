#include "common/common/regex.h"

namespace Envoy {
namespace Regex {

std::regex Utility::parseRegex(const std::string& regex, std::regex::flag_type flags) {
  // TODO(zuercher): In the future, PGV (https://github.com/lyft/protoc-gen-validate) annotations
  // may allow us to remove this in favor of direct validation of regular expressions.
  try {
    return std::regex(regex, flags);
  } catch (const std::regex_error& e) {
    throw EnvoyException(fmt::format("Invalid regex '{}': {}", regex, e.what()));
  }
}

}
}
