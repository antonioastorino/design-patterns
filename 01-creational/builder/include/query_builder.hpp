class SqlQuery
{
public:
    void setBase(std::string_view query);
    void addPart(std::string_view part);
    void print() const;

private:
    std::string __fullQuery;
};

class QueryBuilder
{
public:
    QueryBuilder();
    QueryBuilder& select(const std::vector<std::string_view>& columns);
    QueryBuilder& from(std::string_view table);
    QueryBuilder& where(std::string_view condition);
    QueryBuilder& limit(int count);
    SqlQuery getQuery();

private:
    void __reset();
    std::unique_ptr<SqlQuery> __product;
};
