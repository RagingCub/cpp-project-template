//
// Created by loup.labelle on 2020-06-27.
//

#include "migration-executor.h"

#include <iostream>
#include <vector>

#include <mariadb++/account.hpp>
#include <mariadb++/connection.hpp>
#include "migration/migration.h"
#include "migration/2020-06-27_initial-create.hpp"

namespace persistence {

    class MigrationExecutor::MigrationExecutorImpl {
    public:
        MigrationExecutorImpl(
                const std::string &hostname, const std::string &username, const std::string &password,
                const std::string &schema, int port) {
            auto acc = mariadb::account::create(hostname, username, password, schema, port);
            connection_ = mariadb::connection::create(acc);

            migrations_.push_back(std::make_unique<migration::Migration20200627_InitialCreate>());
        }

        void upgrade() const {
            std::string current_version = get_current_version();
            apply_migrations(current_version);
        }

    private:
        mariadb::connection_ref connection_;
        std::vector<std::unique_ptr<migration::Migration>> migrations_;

        std::string get_current_version() const {
            auto stmt = connection_->create_statement(
                    "SELECT LAST_VALUE(MigrationId)\n"
                    "    OVER (ORDER BY MigrationId)\n"
                    "FROM application._migrations;");
            mariadb::result_set_ref result = stmt->query();
            if (result->row_count() == 0) return "0000-00-00_no-migrations";
            result->next();
            return result->get_string(0);
        }

        void apply_migrations(std::string from_version) const {
            for (const auto &i : migrations_) {
                auto *migration = i.get();
                if (from_version >= migration->get_name()) {
                    std::cout << "skipping migration: " << migration->get_name() << std::endl;
                    continue;
                }
                std::cout << "applying migration: " << migration->get_name() << std::endl;
                migration->up(connection_);
            }
        }
    };

    MigrationExecutor::MigrationExecutor(
            const std::string &hostname, const std::string &username, const std::string &password,
            const std::string &schema, int port) {
        pImpl = std::make_unique<MigrationExecutorImpl>(hostname, username, password, schema, port);
    }

    MigrationExecutor::~MigrationExecutor() = default;

    void MigrationExecutor::upgrade() const {
        pImpl->upgrade();
    }
}
