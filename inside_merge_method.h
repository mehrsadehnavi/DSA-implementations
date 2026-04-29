        int k = p, i = p, j = q + 1 ;

        while (i <= q && j <= r) {
            if (arr[i] > arr[j]) {
                temp[k++] = arr[j++];
            }
            else {
                temp[k++] = arr[i++];
            }
        }
        while (i <= q) {
            temp[k] = arr[i];
            k++;
            i++;
        }
        while (j <= r) {
            temp[k++] = arr[j++];
        }
        for (i = p; i <= r; i++) {
            arr[i] = temp[i];
        }
        