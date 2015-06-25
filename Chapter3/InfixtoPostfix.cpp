void in2post(string &str)
{
	stack<char> s;
	for(int i = 0; i < str.length(); ++i)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			cout << str[i];
		else
			if(str[i] == ')')
			{
				while(!s.empty() && s.top() != '(')
				{
					cout << s.top();
					s.pop();
				}
				if(s.top() == '(')
				{
					s.pop();
				}
			}
		else
		{
			switch(str[i])
			{
				case '(': s.push(str[i]); break;
				case '^':
				{
					while(!s.empty() && (s.top() != '(' || s.top() != '^'))
					{
						cout << s.top();
						s.pop();
					}
					s.push(str[i]);
					break;
				}
				case '*':
				case '/':
				{
					while(!s.empty() && s.top() != '(' && s.top() != '+' && s.top() != '-')
					{
						cout << s.top();
						s.pop();
					}
					s.push(str[i]);
					break;
				}
				case '+':
				case '-':
				{
					while(!s.empty() && s.top() != '(')
					{
						cout << s.top();
						s.pop();
					}
					s.push(str[i]);
					break;
				}
			}
		}
	}
	while(!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;
}
