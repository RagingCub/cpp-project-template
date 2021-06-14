//
// Created by loup.labelle on 2020-06-25.
//

#include "sentry/sentry_logger.h"

#include <utility>

namespace infrastructure::sentry {
SentryLogger::SentryLogger(std::string name, std::shared_ptr<SentryProxy> proxy)
    : name(std::move(name)), proxy(std::move(proxy)) {}

SentryLogger::~SentryLogger() {}

void SentryLogger::log_debug(const std::string &message) {
  proxy->log_debug(name, message);
}

void SentryLogger::log_info(const std::string &message) {
  proxy->log_info(name, message);
}

void SentryLogger::log_warning(const std::string &message) {
  proxy->log_warning(name, message);
}

void SentryLogger::log_error(const std::string &message) {
  proxy->log_error(name, message);
}

void SentryLogger::log_fatal(const std::string &message) {
  proxy->log_fatal(name, message);
}
}
