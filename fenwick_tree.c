#include <stdio.h>
#define MAX 100
int main() {
        int n;
        int a[MAX];
        printf("How many numbers you want to enter   :   ");
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            printf("Enter number %d  :  ", i + 1);
            scanf("%d", &a[i]);
        }
        printf("\n")
        printf("-------------------------------------\n");
        for(int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("-------------------------------------\n");

    return 0;
}
