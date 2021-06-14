#include <iostream>

#include <libintl.h>
#include "config.h"

int main() {
  setlocale(LC_ALL, "");
  std::string binded = bindtextdomain(GETTEXT_PACKAGE, PACKAGE_LOCALEDIR);
  std::string codeset = bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
  std::string text_domain = textdomain(GETTEXT_PACKAGE);

  std::cout << gettext("Hello, World!") << std::endl;

  return 0;
}
