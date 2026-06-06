/* CWE-121: Stack-based buffer overflow via strcpy.
 * record_create copies the caller-supplied name into a fixed MAX_NAME-byte
 * field without bounding the copy — a long name overflows the struct member.
 * IKOS does not model string lengths; the LLM scan catches this.
 */
#include <string.h>
#include "common.h"

static Record g_record;

Record *record_create(const char *name) {
    strcpy(g_record.name, name);   /* vulnerable: no length check */
    g_record.count = 0;
    return &g_record;
}
