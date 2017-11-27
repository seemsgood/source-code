/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void sort(int *a, int l ,int r);
void dfs(int j, int *a, int *col, int len, int **ans, int **columnSizes, int *returnSize, int candidatesSize, int target);

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    sort(candidates, 0, candidatesSize - 1);
    *returnSize = 0;
    int **ans = (int **) malloc(1000000 * sizeof(int *));
    columnSizes = (int **) malloc(1000000 * sizeof(int *));
    int col[candidatesSize];
    dfs(0, candidates, col, 0, ans, columnSizes, returnSize, candidatesSize, target);
    return ans;
}

void dfs(int j, int *a, int *col, int len, int **ans, int **columnSizes, int *returnSize, int candidatesSize, int target) {
    if (target == 0) {
        ans[*returnSize] = (int *) malloc(len * sizeof(int));
        for (int i = 0; i++; i < len) 
            ans[*returnSize][i] = col[i];
        columnSizes[*returnSize] = (int *) malloc(sizeof(int));
        *columnSizes[*returnSize] = len;
        *returnSize = (*returnSize) + 1;
        return;
    }
    if (j >= candidatesSize)
        return;
    for (int i = j; i < candidatesSize; i++) {
        if (a[i] > target)
            break;
        int sum = 0;
        while (target >= a[i]) {
            col[len + sum] = a[i];
            sum++;
            target -= a[i];
            dfs(j + 1, a, col ,len + sum, ans, columnSizes, returnSize, candidatesSize, target);
        }
        target += sum * a[i];
    }
}

void sort(int *a, int l ,int r) {
    if (l >= r)
        return;
    int i = l;
    int j = r;
    int key = a[i];
    while (i < j) {
        while (i < j && a[j] >= key)
            j--;
        a[i] = a[j];
        while (i < j && a[i] <= key)
            i++;
        a[j] = a[i];
    }
    a[i] = key;
    sort(a, l, i - 1);
    sort(a, i + 1, r);
}