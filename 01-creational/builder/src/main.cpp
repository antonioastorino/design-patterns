#include <print>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <utility>
#include "query_builder.cpp"

int main()
{
    QueryBuilder builder;

    // Fluent interface usage
    SqlQuery userQuery = builder.select({"id", "username", "email"})
                             .from("users")
                             .where("is_active = 1")
                             .limit(10)
                             .getQuery();

    userQuery.print();

    return 0;
}
