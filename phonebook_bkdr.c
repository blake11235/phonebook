#include <stdlib.h>
#include "phonebook_bkdr.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */

// BKDR Hash Function
int BKDR_hash(char *str)
{
    int seed = 26;
    long long hash = 0;

    while (*str)
        hash = hash * seed + (*str++);
    return hash % HASH_TABLE_SIZE;
}

entry *findName(char lastname[], entry **pHead)
{
    entry *e = pHead[BKDR_hash(lastname)];

    e->pNext = NULL;
    while (e != NULL) {
        if (strcasecmp(lastname, e->lastName) == 0)
            return e;
        e = e->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry **e)
{
    entry *new = (entry *) malloc(sizeof(entry));
    new->pNext = e[BKDR_hash(lastName)];
    e[BKDR_hash(lastName)] = new;
    strcpy(new->lastName, lastName);
    /*while(e[BKDR_hash(lastName)] != NULL){
    printf("%s ", e[BKDR_hash(lastName)]->lastName);
    e[BKDR_hash(lastName)] = e[BKDR_hash(lastName)]->pNext;
    }*/
    return e;
}
