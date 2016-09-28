#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */

entry *findName_LinkList(char lastName[], entry *pHead)
{
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
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
/***************************************************************
entry *findName_HashTable(char lastName[])
{
    unsigned int hashPos;
    slot_unit *slot;

    hashPos = hashFunction(stringToInt(lastName));
    slot = hashTable[hashPos];

    while (slot!=NULL) {
        if (strcasecmp(lastName, slot->data->lastName) == 0)
            return slot->data;
        slot = slot->pNext;
    }
    return NULL;
}

entry *append_HashTable(char lastName[])
{
    entry *e = (entry *) malloc(sizeof(entry));
    e->pDetailInfo = NULL;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    unsigned int hashPos;
    slot_unit *newSlot;

    hashPos = hashFunction(stringToInt(lastName));
    if (hashTable[hashPos] != NULL){
        slot_unit* pslot = hashTable[hashPos];

        while(pslot->pNext != NULL)
            pslot = pslot->pNext;

        newSlot = (slot_unit *) malloc(sizeof(slot_unit));
        newSlot->pNext = NULL;
        newSlot->data = e;
        pslot->pNext = newSlot;

    }else{

        newSlot = (slot_unit *) malloc(sizeof(slot_unit));
        newSlot->pNext = NULL;
        newSlot->data = e;
        hashTable[hashPos] = newSlot;
    }

    return NULL;
}

unsigned int stringToInt(char *key)
{
    int number = 0;
    while (*key)
        number += *key++;
    return number;
}
************************************************************************/
/* execution time of append(): 16.563192 sec */
/* execution time of findName(): 0.000023 sec */
/*
unsigned int hashFunction(unsigned int key)
{
    return key & ((1<<TWO_POWER_NUM)-1);
}
*/

