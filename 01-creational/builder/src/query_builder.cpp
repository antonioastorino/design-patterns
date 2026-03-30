#include "../include/query_builder.hpp"

void SqlQuery::setBase(std::string_view query)
{
    this->__fullQuery = query;
}

void SqlQuery::addPart(std::string_view part)
{
    this->__fullQuery += " " + std::string(part);
}

void SqlQuery::print() const
{
    std::cout << "Executing: " << this->__fullQuery << ";" << std::endl;
}

QueryBuilder::QueryBuilder()
{
    this->__reset();
}

QueryBuilder& QueryBuilder::select(const std::vector<std::string_view>& columns)
{
    std::string query = "SELECT ";
    size_t i          = 0;
    for (; i < columns.size() - 1; ++i)
    {
        query += columns[i];
        query += ", ";
    }
    query += columns[i];
    this->__product->setBase(query);
    return *this;
}

QueryBuilder& QueryBuilder::from(std::string_view table)
{
    this->__product->addPart("FROM " + std::string(table));
    return *this;
}

QueryBuilder& QueryBuilder::where(std::string_view condition)
{
    this->__product->addPart("WHERE " + std::string(condition));
    return *this;
}

QueryBuilder& QueryBuilder::limit(int count)
{
    this->__product->addPart("LIMIT " + std::to_string(count));
    return *this;
}

SqlQuery QueryBuilder::getQuery()
{
    SqlQuery result = std::move(*(this->__product));
    this->__reset();
    return result;
}

void QueryBuilder::__reset()
{
    this->__product = std::make_unique<SqlQuery>();
}
