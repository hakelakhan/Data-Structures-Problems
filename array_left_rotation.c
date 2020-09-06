#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int* rotateLeft(int* a, int n, int d);
int main(){
    int n; 
    int k; 
    scanf("%d %d",&n,&k);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }
    a = rotateLeft(a, n, k);
    for(int a_i = 0; a_i < n; a_i++){
       printf("%d ",a[a_i]);
    }
    
    return 0;
}
int* rotateLeft(int* a, int n, int d) {
    int* tmp = (int*)malloc(sizeof(int) * d);
    for(int i = 0; i < d; i++) {
        tmp[i] = a[i];
    }
    for(int i = 0; i < n -d; i++) {
        a[i] = a[i + d];
    }
    for(int i = n - d, j = 0; i < n; i++, j++) {
        a[i] = tmp[j];
    }
    free(tmp);
    return a;
}