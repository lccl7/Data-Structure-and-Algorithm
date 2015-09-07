void elimDups(vector<string>& words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.earse(end_unique, words.end());
}

void biggis(vector<string>& words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(),
            [](const string& a, const string& b)
            { return a.size() < b.size(); });
    auto wc = find_if(words.begin(), words.end(),
            [sz](const string& a)
            { return a.size() >= sz; });
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "words", "s")
        << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(),
            [](const string& s) { cout << s << " "; });
    cout << endl;
}
