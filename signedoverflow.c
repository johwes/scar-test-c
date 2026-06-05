/* CWE-190: Signed integer overflow — triggers IKOS sio checker */
#include <stdio.h>
#include <limits.h>

int main(void) {
    int a = INT_MAX;
    int b = a + 1;  /* signed overflow is undefined behaviour in C */
    printf("%d\n", b);
    return 0;
}
