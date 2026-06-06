/* CWE-369: Divide by zero.
 * record_print computes the average of stored values but divides by
 * r->count without guarding against count == 0.
 * IKOS dbz checker flags this.
 */
#include <stdio.h>
#include "common.h"

void record_print(Record *r) {
    if (r == NULL) return;
    printf("Name: %s\n", r->name);
    int sum = 0;
    for (int i = 0; i < r->count; i++) {
        sum += r->values[i];
    }
    printf("Average: %d\n", sum / r->count);   /* vulnerable: divide by zero if count == 0 */
}
