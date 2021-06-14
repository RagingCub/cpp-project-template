//
// Created by loup.labelle on 2020-06-25.
//

#pragma once

#include <string>

namespace domain {
class Logger {
 public:
  virtual ~Logger() = default;

  virtual void log_debug(const std::string &message) = 0;

  virtual void log_info(const std::string &message) = 0;

  virtual void log_warning(const std::string &message) = 0;

  virtual void log_error(const std::string &message) = 0;

  virtual void log_fatal(const std::string &message) = 0;
};
}
