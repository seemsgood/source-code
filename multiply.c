#define M 1000
char* multiply(char* num1, char* num2) {
    int l1 = strlen(num1);
    int l2 = strlen(num2);
    int a[100] = {0};
    int b[100] = {0};
    int c[100] = {0};
    int len;
    int x[3] = {100, 1, 10};
    convert(num1, a, l1, &len, x);
    l1 = len + 1;
    convert(num2, b, l2, &len, x);
    l2 = len + 1;
    
    for (int i = 0; i < l1; i++)
        for (int j = 0; j < l2; j++)
            c[i + j] += a[i] * b[j];
    for (int i = 0; i < l1 + l2; i++) {
        c[i + 1] += c[i] / M;
        c[i] %= M;
    }
    len = l1 + l2;
    while (c[len - 1] == 0 && len > 1)
        len--;
    
    char *ans = (char *) malloc(300 * sizeof(char));
    int l = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < 3; j++) {
            ans[l] = c[i] % 10 + '0';
            c[i] /= 10;
            l++;
        }
    }
    do {
        ans[l] = c[len - 1] % 10 + '0';
        c[len - 1] /= 10;
        l++;
    } while (c[len - 1] > 0);
    int i = 0;
    int j = l - 1;
    char t;
    while (i < j) {
        t = ans[i];
        ans[i] = ans[j];
        ans[j] = t;
        i++;
        j--;
    }
    ans[l] = '\0';
    return ans;
}

void convert(char *num, int *a, int l, int *len, int *x) {
    *len = 0;
    for (int i = 1; i <= l; i++) {
        a[*len] += (num[l - i] -'0') * x[i % 3];
        if (i % 3 == 0 && i < l) 
            *len = *len + 1;
    }
}