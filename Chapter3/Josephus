void Josephus(int M, int N)
{
	list<int> lN;
	for(int i = 1; i <= N; ++i)
		lN.push_back(i);
	list<int>::iterator iter = lN.begin();
	int nleft = N;
	int m = M % N;
	for(int i = 0; i < lN.size(); ++i)
	{
		nleft = lN.size();
		if(m <= nleft/2)
		{
			for(int j = 0; j < m; ++j)
			{
				iter++;
				if(iter == lN.end())
					iter = lN.begin();
			}
		}
		else
		{
			for(int j = 0; j < m; ++j)
			{
				if(iter == lN.begin())
					iter = --lN.end();
				else
					iter--;
			}
		}
		cout << *iter << " ";
		iter = lN.erase(iter);
		if(iter == lN.end())
			iter = lN.begin();
	}
}
