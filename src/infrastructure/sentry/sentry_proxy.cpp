//
// Created by loup.labelle on 2020-06-26.
//

#include "sentry/sentry_proxy.h"

#include <sentry.h>

namespace infrastructure::sentry {
SentryProxy::SentryProxy() {
  sentry_options_t *options = sentry_options_new();
  sentry_init(options);
}

SentryProxy::~SentryProxy() {
  sentry_shutdown();
}

void SentryProxy::log_debug(const std::string &logger, const std::string &message) const {
  sentry_capture_event(sentry_value_new_message_event(SENTRY_LEVEL_DEBUG, logger.c_str(), message.c_str()));
}

void SentryProxy::log_info(const std::string &logger, const std::string &message) const {
  sentry_capture_event(sentry_value_new_message_event(SENTRY_LEVEL_INFO, logger.c_str(), message.c_str()));
}

void SentryProxy::log_warning(const std::string &logger, const std::string &message) const {
  sentry_capture_event(sentry_value_new_message_event(SENTRY_LEVEL_WARNING, logger.c_str(), message.c_str()));
}

void SentryProxy::log_error(const std::string &logger, const std::string &message) const {
  sentry_capture_event(sentry_value_new_message_event(SENTRY_LEVEL_ERROR, logger.c_str(), message.c_str()));
}

void SentryProxy::log_fatal(const std::string &logger, const std::string &message) const {
  sentry_capture_event(sentry_value_new_message_event(SENTRY_LEVEL_FATAL, logger.c_str(), message.c_str()));
}
}
