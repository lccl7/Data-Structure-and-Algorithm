#include <string>

class Quote
{
public:
    Quote() = default;
    Quote(const string &book, double sales_price):
        bookNo(book), price(sales_price) { }
    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const
        { return n * price; }
    virtual ~Quote() = default;

private:
    strin bookNo;
protected:
    double price = 0.0;
};

class Bulk_quote: public Quote
{
public:
    double net_price(size_t) const override;
};

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}
