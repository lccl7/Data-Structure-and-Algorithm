int posfix(string &str)
{
	stack<int> s;
	int a, b;
	char c;
	
	for(int i = 0; i < str.size(); ++i)
	{
		c = str[i];
		if(c-'0' >= 0 && c-'0' <= 9)
		{
			s.push(c-'0');
		}
		else
		{
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			switch(c)
			{
				case '+':
					{
						s.push(a+b);
						break;
					}
				case '*':
					{
						s.push(a*b);
						break;
					}
			}
		}
	}
	return s.top();
}
