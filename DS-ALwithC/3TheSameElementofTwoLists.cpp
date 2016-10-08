void common(list<Object> L1, list<Object> L2)
{
	typename list<Object>:: const_iterator iter1 = L1.begin(); 
	typename list<Object>::	const_iterator iter2 = L2.begin();
	
	while(iter1 != L1.end() && iter2 != L2.end())
	{
		while(*iter1 < *iter2 && iter1 != L1.end())
		{
			iter1++;
		}
		while(*iter2 < *iter1 && iter2 != L2.end())
		{
			iter2++;
		}
		if(iter1 != L1.end() && iter2 != L2.end() && *iter1 == *iter2)
		{
			cout << *iter1 << endl;
			++iter1;
			++iter2;
		}
	}
}
