#ifndef _PHONEBOOK_OPT_H
#define _PHONEBOOK_OPT_H

#define MAX_LAST_NAME_SIZE 16

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT_FGETS 1

typedef struct __PHONE_DETAIL_INFO {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} detail_info;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_DETAIL_INFO *pDetailInfo;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;


typedef struct __HASH_SLOT {
    entry *data;
    struct __HASH_SLOT *pNext;
} slot_unit;

//slot_unit* hashTable[MAX_HASH_TABLE_SIZE];


entry *findName_LinkList(char lastName[], entry *pHead);
entry *append_LinkList(char lastName[], entry *e);
/*
entry *findName_HashTable(char lastName[]);
entry *append_HashTable(char lastName[]);

unsigned int stringToInt(char *key);

unsigned int hashFunction(unsigned int key);
*/

#endif
