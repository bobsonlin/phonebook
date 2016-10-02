#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "phonebook_opt_fgets.h"


/* FILL YOUR OWN IMPLEMENTATION HERE! */

entry *findName_LinkList(char lastName[], entry *pHead)
{
    size_t len = strlen(lastName);
    while (pHead != NULL) {
        if (strncasecmp(lastName, pHead->lastName, len) == 0 && (pHead->lastName[len] == '\n' || pHead->lastName[len] == EOF || pHead->lastName[len] == '\0')) {
            pHead->lastName[len] = '\0';
            return pHead;
        }
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append_LinkList(char lastName[], entry *e)
{
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}
