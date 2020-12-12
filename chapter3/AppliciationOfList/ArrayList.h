#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#include "NameCard.h"

#define TRUE    1
#define FALSE   0

#define List_LEN    100
typedef NameCard* LData;

typedef struct __ArrayList {
    LData arr[List_LEN];
    int numOfData;
    int curPosition;
} ArrayList;

typedef ArrayList List;

void ListInit(List* plist) {
    plist->numOfData = 0;
    plist->curPosition = -1;
}
void LInsert(List* plist, LData data) {
    if(plist->numOfData >= List_LEN) {
        return;
    }
    plist->arr[plist->numOfData] = data;
    plist->numOfData++;
}

int LFirst(List* plist, LData* pdata) {
    if(plist->numOfData == 0) return FALSE;
    plist->curPosition = 0;
    *pdata = plist->arr[0];
    return TRUE;
}
int LNext(List* plist, LData* pdata) {
    if(plist->curPosition >= plist->numOfData - 1) return FALSE;
    plist->curPosition++;
    *pdata = plist->arr[plist->curPosition];
    return TRUE;
}

LData LRemove(List* plist) {
    LData temp = plist->arr[plist->curPosition];
    for(int i = plist->curPosition; i < plist->numOfData; i++) {
        plist->arr[i] = plist->arr[i + 1];
    }
    plist->numOfData--;
    plist->curPosition--;
    return temp;
}
int LCount(List* plist) {
    return plist->numOfData;
}

#endif