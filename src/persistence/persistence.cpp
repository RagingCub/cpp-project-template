//
// Created by loup.labelle on 2020-06-27.
//

#include <cstdlib>

#include "migration_executor.h"

int main() {
  auto hostname = std::getenv("PERSISTENCE_HOSTNAME");
  auto username = std::getenv("PERSISTENCE_USER");
  auto password = std::getenv("PERSISTENCE_PASSWORD");

  const persistence::MigrationExecutor executor(hostname, username, password, "application");

  executor.upgrade();
}
