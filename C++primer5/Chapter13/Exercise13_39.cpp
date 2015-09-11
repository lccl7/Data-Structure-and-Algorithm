class StrVec
{
public:
    StrVec(): element(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    ~StrVec();
    void push_back(const string&);
    size_t size() const { return first_free - element; }
    size_t capacity const { return cap - element; }
    string *begin() const { return element; }
    string *end() const { return first_free; }
    void reserve(size_t n)
    {
        if(capacity() >= n)
            return;
        alloc.allocate(n)
    }
    void resize(size_t n, const string &s)
    {
        if(n > size())
        {
            if(n > capacity()) reserve(n * 2);
            for(size_t i = size(); i != n; i++)
                alloc.construct(first_free++, s);
        }
        else if(n < size())
        {
            while(first_free != element + n)
                alloc.destroy(--first_free);
        }
    }
    void resize(size_t n) { }

private:
    static allocator<string> alloc;
    void chk_n_alloc()
        { if(size() == capacity())  reallocate(); }
    pair<string, string> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();
    string *element;
    string *first_free;
    string *cap;
}
