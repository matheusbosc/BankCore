/// @author Matheus Boscariol
/// @date 3/4/26
/// @note Licensed under GNU AGPL License
/// @details Configure Drogon, load config, and run server.
///
/// NOTE:
/// Functions beginning with l_ are logic and found in system classes
/// Functions beginning with s_ interact with Postgres and are found in repository classes.
/// Other functions are usually controller classes which interact the with HTTP server.

#include "drogon/HttpAppFramework.h"

int main() {
    drogon::app()
            .loadConfigFile("config.json")
            .run();
}
