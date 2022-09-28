# - // Ввод
    int mas[N], last[N], sum[N];
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> mas[i];
        
        last[i] = mas[i] % 10;

        sum[i] = 0;
        int x = mas[i];
        while (x > 0)
        {
            sum[i] += x % 10;
            x /= 10;
        }
    }
