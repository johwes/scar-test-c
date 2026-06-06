/* CWE-476: Null pointer dereference.
 * record_add dereferences r before checking whether the caller passed NULL.
 * IKOS nullity checker flags this.
 */
#include "common.h"

void record_add(Record *r, int value) {
    if (r->count < MAX_ITEMS) {   /* vulnerable: r is not checked for NULL */
        r->values[r->count++] = value;
    }
}
