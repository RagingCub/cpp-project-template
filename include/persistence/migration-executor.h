//
// Created by loup.labelle on 2020-06-27.
//

#pragma once

#include <memory>

namespace persistence {
    class MigrationExecutor {
    public:
        MigrationExecutor(
                const std::string &hostname, const std::string &username, const std::string &password,
                const std::string &schema, int port = 3306);

        ~MigrationExecutor();

        void upgrade() const;

    private:
        class MigrationExecutorImpl;

        std::unique_ptr<MigrationExecutorImpl> pImpl;
    };
}
