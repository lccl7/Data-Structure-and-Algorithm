class Stack
{
private:
    stack<int> s;
    stack<int> m;

public:
   void  push(int &x)
   {
       s.push(x);
       if(m.empty() || m.top() > x)
           m.push(x);
   }
   void  pop()
   {
       int x;
       if(!s.empty())
       {
           x = s.top();
           s.pop();
       }
       if(x == m.top())
           m.pop();
   }
   int&  findMin()
   {
       return m.top();
   }
   bool empty()
   {
       return s.empty();
   }
};
