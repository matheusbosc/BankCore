/// @author Matheus Boscariol
/// @date 3/4/26
/// @note Licensed under GNU AGPL License
/// @details Structure for account info

#include <stdlib.h>
#include <string>

class Account {
    std::string id;
    std::string userId;
    int64_t balanceCents;
public:
    Account(std::string _id, std::string _userId, int64_t _balanceCents) {
        id = _id;
        userId = _userId;
        balanceCents = _balanceCents;
    }
};