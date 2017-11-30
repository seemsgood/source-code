/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
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

void dfs(int *col, int k, char ***ans, int *returnSize, int n) {
    if (k == n - 1) {
        if (!check(col, k))
            return;
        ans[*returnSize] = (char **) malloc(n * sizeof(char *));
        for (int i = 0; i < n; i++) {
            ans[*returnSize][i] = (char *) malloc(n * sizeof(char));
            for (int j = 0; j < n; j++)
                if (j == col[i])
                    ans[*returnSize][i][j] = 'Q';
                else
                    ans[*returnSize][i][j] = '.';
        }
        *returnSize = *returnSize + 1;
        return;
    }
    for (int i = k; i < n; i++) {
        swap(col + i, col + k);
        if (check(col, k))
            dfs(col, k + 1, ans, returnSize, n);
        swap(col + i, col + k);
    }
}

char*** solveNQueens(int n, int* returnSize) {
    int col[n];
    for (int i = 0; i < n; i++)
        col[i] = i;
    *returnSize = 0;
    int m = 1;
    for (int i = 2; i <= n; i++)
        m *= i;
    char ***ans = (char ***) malloc(m * sizeof(char **));
    dfs(col, 0, ans, returnSize, n);
    return ans;
}