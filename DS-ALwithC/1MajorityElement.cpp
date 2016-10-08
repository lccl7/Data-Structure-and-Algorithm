//The majority element

 #include <iostream>
 #include <cstdlib>
 #include <vector>
 using namespace std;

 int Partition(int a[], int start, int end)
 {
     int privot = a[start];
     while(start < end)
     {
         while(a[end] >= privot && end > start)
             --end;
         a[start] = a[end];

         while(a[start] <= privot && start < end)
             ++start;
         a[end] = a[start];
     }
     a[start] = privot;
     return start;
 }

 bool CheckMoreThanHalf(int a[], int len,  int result)
 {
     int count = 0;
     for(int i = 0; i < len; ++i)
         if(result == a[i])
             count++;
     if(count >= len/2)
         return true;
     return false;
 }

 int MoreThanHalf(int a[], int len, int start, int end)
 {
     if(len == 0)
         return -1;

     int index = Partition(a, start, end);
     int middle = len/2;
     while(index != middle)
     {
         if(index > middle)
             index = Partition(a, start, index-1);
         else
             index = Partition(a, index+1, end);
     }
     int result = a[middle];
     if(!CheckMoreThanHalf(a,len, result))
         return -1;
     return a[middle];
 }
 int main()
 {
     int a[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
     int len = sizeof(a)/sizeof(int);
     int half = MoreThanHalf(a, len, 0, len-1);
     cout << half << endl;
     return 0;
 }
