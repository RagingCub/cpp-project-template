//
// Created by loup.labelle on 2020-06-27.
//

#include "migration/migration.h"

namespace persistence::migration {
class Migration20200627_InitialCreate : public Migration {
 public:
  Migration20200627_InitialCreate() : Migration("2020-06-27_InitialCreate") {}

  void up(const mariadb::connection_ref &con) override {
    mariadb::statement_ref stmt = con->create_statement(
        "CREATE OR REPLACE TABLE application._migrations\n"
        "(\n"
        "    MigrationId      VARCHAR(150) PRIMARY KEY,\n"
        "    CreationUsername VARCHAR(255),\n"
        "    CreationDateTime DATETIME\n"
        ");");
    stmt->execute();

    stmt = con->create_statement(
        "INSERT INTO application._migrations\n"
        "    (MigrationId, CreationUsername, CreationDateTime)\n"
        "VALUES (?, ?, ?);");
    stmt->set_string(0, get_name());
    stmt->set_string(1, con->account()->user_name());
    stmt->set_date_time(2, mariadb::date_time::now_utc());
    stmt->insert();
  }

  void down(const mariadb::connection_ref &con) override {

  }
};
}
