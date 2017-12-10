void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

bool check(int *col, int k) {
    for (int i = 0; i < k; i++)
        for (int j = i + 1; j <= k; j++)
            if (col[j] - col[i] == j - i || col[j] - col[i] == i - j)
                return false;
    return true;
}

void dfs(int *col, int k, int *returnSize, int n) {
    if (k == n - 1) {
        if (!check(col, k))
            return;
        
        *returnSize = *returnSize + 1;
        return;
    }
    for (int i = k; i < n; i++) {
        swap(col + i, col + k);
        if (check(col, k))
            dfs(col, k + 1, returnSize, n);
        swap(col + i, col + k);
    }
}

int totalNQueens(int n) {
    int col[n];
    for (int i = 0; i < n; i++)
        col[i] = i;
    int returnSize = 0;
    dfs(col, 0, &returnSize, n);
    return returnSize;
}
