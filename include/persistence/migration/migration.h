//
// Created by loup.labelle on 2020-06-27.
//

#pragma once

#include <string>

#include <mariadb++/connection.hpp>

namespace persistence::migration {
    class Migration {
    public:
        virtual ~Migration() = default;

        const std::string get_name() const;

        virtual void up(const mariadb::connection_ref &con) = 0;

        virtual void down(const mariadb::connection_ref &con) = 0;

    protected:
        Migration(std::string name);

    private:
        std::string name_;
    };
}
