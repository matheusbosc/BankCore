/// @author Matheus Boscariol
/// @date 3/4/26
/// @note Licensed under GNU AGPL License
/// @details Configure Drogon, load config, and run server.

#include "drogon/HttpAppFramework.h"

int main() {
    drogon::app()
            .addListener("0.0.0.0", 8080)
            .run();
}
