        int low = 0;
        int high = n - 1;
        T* temp = new T[n];

        for (int m = 1; m <= high - low; m *= 2)
        {
            for (int i = low; i < high; i += 2 * m)
            {
                int p = i;
                int q = min(i + m - 1, high);
                int r = min(i + 2 * m - 1, high);
                merge(data, temp, p, q ,r);
            }
        }