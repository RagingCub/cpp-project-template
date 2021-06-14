//
// Created by loup.labelle on 2020-06-27.
//

#include "migration/migration.h"

namespace persistence::migration {

Migration::Migration(std::string name)
    : name_(name) {}

const std::string Migration::get_name() const {
  return name_;
}
}
