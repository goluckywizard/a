#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap (char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void next_purmutation (char *P, int count)
{
    int is_all = 1;
    for (int i = 1; i < count; ++i)
    {
        if (P[i] > P[i - 1])
            is_all = 0;
    }
    if (is_all == 1)
    {
        exit(0);
    }

    int l = 1, j = 0;
    for (int i = 0; i < count - 1; ++i)
    {
        if (P[i] < P[i + 1])
            j = i;
    }
    for (int i = j + 1; i < count; ++i)
    {
        if (P[i] > P[j])
            l = i;
    }

    swap(&P[l], &P[j]);
    for (int i = j + 1; i < (count + (j + 1)) / 2; ++i)
    {
        swap(&P[i], &P[count - i + j]);
    }
    if (P[0] != '0') {
        printf("%s\n", P);
    }
    else {
        printf("%s\n", &P[1]);
    }
}

void npa (char *P, int n)
{
    int count = 0;
    while (P[count] != 0)
    {
        count++;
    }
    for (int i = 0; i < n; ++i)
    {
        next_purmutation(P, count);
    }
}


int main() {
    int nums[10] = {0};
    int n, k;
    scanf("%d", &n);
    k = n;
    if (k < 0) {
        k = -k;
    }
    while (k > 0) {
        nums[k % 10]++;
        k /= 10;
    }
    int amount_nums = 0;
    for (int i = 0; i < 10; ++i) {
        if (nums[i] > 0) {
            amount_nums++;
        }
    }
    char *num = (char*)malloc((amount_nums + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < 10; ++i) {
        if (nums[i] > 0) {
            num[j] = i + '0';
            j++;
        }
    }
    num[j] = 0;
    int permutation_amount = 1;
    for (int i = 1; i <= amount_nums; ++i) {
        permutation_amount *= i;
    }
    if (num[0] != '0') {
        printf("%s\n", num);
    }
    else {
        printf("%s\n", &num[1]);
    }
    npa(num, permutation_amount);
    return 0;
}
