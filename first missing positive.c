typedef struct list {
    int val;
    struct list *next;
} listnode;

#define MAX 10000

int firstmiss(listnode **a, int i, bool bo[], int len);

int firstMissingPositive(int* nums, int numsSize) {
    listnode *a[MAX] = {NULL};
    int max = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= 0)
            continue;
        listnode *p = (listnode *) malloc(sizeof(listnode));
        p->next = a[nums[i] % MAX];
        p->val = nums[i];
        a[nums[i] % MAX] = p;
        if (nums[i] > max)
            max = nums[i];
    }
    
    int min = 2147483647;
    int len = max / MAX + 3;
    bool bo[len]; 
    for (int i = 0; i < MAX; i++) {
        int t = firstmiss(a, i, bo, len);
        if (min > t)
            min = t;
        if (min == i)
            break;
    }
    return min;
}

int firstmiss(listnode **a, int i, bool bo[], int len) {
    listnode *p = a[i];
    memset(bo, false, sizeof(bool) * len);
    while (p != NULL) {
        bo[p->val / MAX] = true;
        p = p->next;
    }
    int k = i > 0 ? 0 : 1;
    while (bo[k])
        k++;
    return k * MAX + i;
}