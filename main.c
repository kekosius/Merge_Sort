#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

void sort(int64_t*, size_t, size_t);

int main() {
    int64_t A[12] = {6, 3, 5, 1, 2, 4, 7, 11, 9, 12, 8, 10}; //type an array
    size_t len = 12; //set length
    sort(A,1, len);
    for (int i = 0; i < len; ++i) {
        printf("%" PRId64 " ", A[i]);
    }
    printf("\n");
    return 0;
}

void merge(int64_t*, size_t, size_t, size_t);

void sort(int64_t* A, size_t p, size_t r){
    size_t q;
    if (p < r) {
        q = (p+r)/2;
        sort(A,p,q);
        sort(A,q+1,r);
        merge(A,p,q,r);
    }
}

void merge(int64_t* A, size_t p, size_t q, size_t r){
    int64_t* buffer = malloc(sizeof(int64_t)*(r-p+1));
    int64_t left = p-1;
    int64_t right = q;

    for (int i = p-1; i < r; ++i) {
        if (left != -1) {
            if (right != -1) {
                if (A[right] > A[left]) {
                    buffer[i-p+1] = A[left];
                    left++;
                } else {
                    buffer[i-p+1] = A[right];
                    right++;
                }
            } else {
                buffer[i-p+1] = A[left];
                left++;
            }
        } else {
            buffer[i-p+1] = A[right];
            right++;
        }
        if (right >= r) right = -1;
        if (left >= q) left = -1;
    }

    for (int i = p-1; i < r; ++i) {
        A[i] = buffer[i-p+1];
    }

    free(buffer);
}