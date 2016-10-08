void printLots(list<Object> L, list<int> P)
{
	int start = 1;
	typename list<Object>:: const_iterator Liter;
	typename list<int>:: const_iterator Piter;
	Liter = L.begin();
	Piter = P.begin();
	
	for(;Liter != L.end() && Piter != P.end(); Piter++)
	{
		while(start < *Piter && Liter != L.end())
		{
			start++;
			Liter++;
		}
		if(Liter != L.end())
			cout << *Liter << '\t';
	}
}
