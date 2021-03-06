#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#include IMPL

#define DICT_FILE "./dictionary/words.txt"

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

int main(int argc, char *argv[])
{
    FILE *fp;
#if defined(OPT_FGETS)
#else
    int i = 0;
#endif
    char line[MAX_LAST_NAME_SIZE];
    struct timespec start, end;
    double cpu_time1, cpu_time2;

    /* check file opening */
    fp = fopen(DICT_FILE, "r");
    if (fp == NULL) {
        printf("cannot open the file\n");
        return -1;
    }
    /* build the entry */
    /*
       entry *pHead, *e;
       pHead = (entry *) malloc(sizeof(entry));
       printf("size of entry : %lu bytes\n", sizeof(entry));
       e = pHead;
       e->pNext = NULL;
    */


#if defined(HASH)
    printf("size of entry : %lu bytes\n", sizeof(entry));
    hashTable *tb = createHashTable(TABLE_SIZE);
#else
    entry *pHead, *e;
    pHead = (entry *) malloc(sizeof(entry));
    printf("size of entry : %lu bytes\n", sizeof(entry));
    e = pHead;
    e->pNext = NULL;
#endif

#if defined(__GNUC__)
#if defined(HASH)
#else
    __builtin___clear_cache((char *) pHead, (char *) pHead + sizeof(entry));
#endif
#endif
    clock_gettime(CLOCK_REALTIME, &start);
    while (fgets(line, sizeof(line), fp)) {
#if defined(OPT_FGETS)

#else
        while (line[i] != '\0')
            i++;
        line[i - 1] = '\0';
        i = 0;
#endif
        /*
                while (line[i] != '\0')
                    i++;
                line[i - 1] = '\0';
                i = 0;
        */
#if defined(HASH)
        append_HashTable(line, tb);
#else
        e = append_LinkList(line, e);
#endif

    }
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start, end);

    /* close file as soon as possible */
    fclose(fp);


    /* the givn last name to find */
    char input[MAX_LAST_NAME_SIZE] = "zyxel";

#if defined(HASH)
    assert(findName_HashTable(input, tb) &&
           "Did you implement findName() in " IMPL "?");
    assert(0 == strcmp(findName_HashTable(input, tb)->lastName, "zyxel"));
#else
    e = pHead;
    assert(findName_LinkList(input, e) &&
           "Did you implement findName() in " IMPL "?");
    assert(0 == strcmp(findName_LinkList(input, e)->lastName, "zyxel"));
#endif


#if defined(__GNUC__)
//    __builtin___clear_cache((char *) pHead, (char *) pHead + sizeof(entry));
#if defined(HASH)
#else
    __builtin___clear_cache((char *) pHead, (char *) pHead + sizeof(entry));
#endif
#endif
    /* compute the execution time */
    clock_gettime(CLOCK_REALTIME, &start);

#if defined(HASH)
    findName_HashTable(input, tb);
#else
    findName_LinkList(input, e);
#endif

    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time2 = diff_in_second(start, end);

    FILE *output;
#if defined(OPT)
#if defined(HASH)
    output = fopen("opt_HASH.txt", "a");
#else
    output = fopen("opt.txt", "a");
#endif
#else
#if defined(OPT_FGETS)
    output = fopen("opt_fgets.txt", "a");
#else
    output = fopen("orig.txt", "a");
#endif
#endif
    fprintf(output, "append() findName() %lf %lf\n", cpu_time1, cpu_time2);
    fclose(output);

    printf("execution time of append() : %lf sec\n", cpu_time1);
    printf("execution time of findName() : %lf sec\n", cpu_time2);

    /*
        if (pHead->pNext) free(pHead->pNext);
        free(pHead);
    */
    return 0;
}
