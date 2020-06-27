//
// Created by loup.labelle on 2020-06-26.
//

#pragma once

#include <sentry/sentry_proxy.h>

namespace infrastructure::sentry {
    class SentryProxyMock : public SentryProxy {
    public:
        SentryProxyMock() : SentryProxy() {}

        ~SentryProxyMock() override = default;

        MOCK_METHOD(void, log_debug, (const std::string &logger, const std::string &message), (const, override));

        MOCK_METHOD(void, log_info, (const std::string &logger, const std::string &message), (const, override));

        MOCK_METHOD(void, log_warning, (const std::string &logger, const std::string &message), (const, override));

        MOCK_METHOD(void, log_error, (const std::string &logger, const std::string &message), (const, override));

        MOCK_METHOD(void, log_fatal, (const std::string &logger, const std::string &message), (const, override));
    };
}
