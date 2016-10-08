int fastPower(int a, int b, int n)
{
    if(a == 1 || n == 0) return 1 % b;
    int x = fastPower(a, b, n / 2);
    x = x * x % b;
    if(n % 2 == 1)
        return x = x * a % b;
    return x;
}
