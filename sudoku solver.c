typedef struct coord {
    int x;
    int y;
} coord;

bool search(char **board, coord *a, int n, bool **bo, bool **bocol, bool **borow, int sum) {
    if (n == sum)
        return true;
    int i = a[n].x;
    int j = a[n].y;
    int t = i / 3 * 3 + j / 3;
    for (int k = 1; k <= 9; k++) {
        if (bocol[j][k] && borow[i][k] && bo[t][k]) {
            bocol[j][k] = borow[i][k] = bo[t][k] = false;
            board[i][j] = k + '0';
            if (search(board, a, n + 1, bo, bocol, borow, sum))
                return true;
            bocol[j][k] = borow[i][k] = bo[t][k] = true;
        }
    }
    return false;
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
    bool bocol[9][10], borow[9][10], bo[9][10];
    for (int i = 0; i < 9; i++)
        for (int j = 1; j <= 9; j++)
            bocol[i][j] = borow[i][j] = bo[i][j] = true;
    coord a[90];
    int sum = 0;
    for (int i = 0; i < 9; i++) 
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                a[sum].x = i;
                a[sum++].y = j;
            }
            else {
                int num = board[i][j] - '0';
                int t = i / 3 * 3 + j / 3;
                bocol[j][num] = borow[i][num] = bo[t][num] = false;
            }
        }
    search(board, a, 0, bo, bocol, borow, sum);
}