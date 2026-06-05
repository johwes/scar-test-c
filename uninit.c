/* CWE-457: Use of uninitialized variable — triggers IKOS uva checker */
#include <stdio.h>

int main(void) {
    int x;
    printf("%d\n", x);  /* x is never assigned before read */
    return 0;
}
