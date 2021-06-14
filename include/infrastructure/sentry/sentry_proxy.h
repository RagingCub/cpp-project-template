//
// Created by loup.labelle on 2020-06-25.
//

#pragma once

#include <string>

namespace infrastructure::sentry {
class SentryProxy {
 public:
  SentryProxy();

  virtual ~SentryProxy();

  virtual void log_debug(const std::string &logger, const std::string &message) const;

  virtual void log_info(const std::string &logger, const std::string &message) const;

  virtual void log_warning(const std::string &logger, const std::string &message) const;

  virtual void log_error(const std::string &logger, const std::string &message) const;

  virtual void log_fatal(const std::string &logger, const std::string &message) const;
};
}
