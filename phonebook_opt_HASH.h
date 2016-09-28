#ifndef _PHONEBOOK_OPT_HASH_H
#define _PHONEBOOK_OPT_HASH_H

#define MAX_LAST_NAME_SIZE 16
#define TABLE_SIZE 42737

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1
#define HASH 1

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

typedef struct __PHONE_BOOK_HASH {
    entry **list;
} hashTable;

/*
entry *findName_LinkList(char lastName[], entry *pHead);
entry *append_LinkList(char lastName[], entry *e);
*/

entry *findName_HashTable(char lastName[], hashTable *tb);
void append_HashTable(char lastName[], hashTable *tb);
hashTable *createHashTable(int tablesize);
unsigned int hash(char *str);


#endif