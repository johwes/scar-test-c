#ifndef COMMON_H
#define COMMON_H

#define MAX_NAME  32
#define MAX_ITEMS  8

typedef struct {
    char name[MAX_NAME];
    int  values[MAX_ITEMS];
    int  count;
} Record;

Record *record_create(const char *name);
void    record_add(Record *r, int value);
void    record_print(Record *r);

#endif
