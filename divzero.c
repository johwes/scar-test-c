/* CWE-369: Divide by zero — triggers IKOS dbz checker */
#include <stdio.h>

int divide(int a, int b) {
    return a / b;  /* b may be zero */
}

int main(void) {
    int x = 0;
    printf("%d\n", divide(10, x));
    return 0;
}
