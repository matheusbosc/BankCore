/// @author Matheus Boscariol
/// @date 3/4/26
/// @note Licensed under GNU AGPL License

#pragma once

#include <optional>

#include "Account.h"
#include "AccountRepository.h"
#include "drogon/HttpAppFramework.h"

// ACCOUNT SYSTEM

std::optional<Account> l_create_account(Account &account);

std::optional<Account> l_get_account(std::string account_id);
std::optional<std::vector<Account>> l_get_accounts(std::string user_id, int limit);

int l_delete_account(std::string account_id);
