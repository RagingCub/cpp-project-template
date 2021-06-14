//
// Created by loup.labelle on 2020-06-25.
//

#include "sentry/sentry_logger.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "sentry_proxy_mock.hpp"

using ::testing::_;

namespace infrastructure::sentry {
class SentryLoggerTests : public ::testing::Test {
 public:
  // mocks
  std::shared_ptr<SentryProxyMock> proxy;

  SentryLoggerTests() {
    proxy = std::make_shared<SentryProxyMock>();
  }
};

TEST_F(SentryLoggerTests, whenLoggingDebug_thenIsSentToProxy) {
  EXPECT_CALL(*proxy, log_debug(_, _));
  SentryLogger logger("test", proxy);

  logger.log_debug("this is a test log");
}

TEST_F(SentryLoggerTests, whenLoggingInfo_thenIsSentToProxy) {
  EXPECT_CALL(*proxy, log_info(_, _));
  SentryLogger logger("test", proxy);

  logger.log_info("this is a test log");
}

TEST_F(SentryLoggerTests, whenLoggingWarning_thenIsSentToProxy) {
  EXPECT_CALL(*proxy, log_warning(_, _));
  SentryLogger logger("test", proxy);

  logger.log_warning("this is a test log");
}

TEST_F(SentryLoggerTests, whenLoggingError_thenIsSentToProxy) {
  EXPECT_CALL(*proxy, log_error(_, _));
  SentryLogger logger("test", proxy);

  logger.log_error("this is a test log");
}

TEST_F(SentryLoggerTests, whenLoggingFatal_thenIsSentToProxy) {
  EXPECT_CALL(*proxy, log_fatal(_, _));
  SentryLogger logger("test", proxy);

  logger.log_fatal("this is a test log");
}
}
