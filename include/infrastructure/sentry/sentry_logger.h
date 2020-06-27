//
// Created by loup.labelle on 2020-06-25.
//

#pragma once

#include <string>
#include <memory>

#include <logger.h>
#include "sentry_proxy.h"

namespace infrastructure::sentry {
    class SentryLogger : domain::Logger {
    public:
        SentryLogger(const std::string &name, std::shared_ptr<SentryProxy> proxy);

        ~SentryLogger();

        void log_debug(const std::string &message) override;

        void log_info(const std::string &message) override;

        void log_warning(const std::string &message) override;

        void log_error(const std::string &message) override;

        void log_fatal(const std::string &message) override;

    private:
        std::string name;
        std::shared_ptr<SentryProxy> proxy;
    };
}
