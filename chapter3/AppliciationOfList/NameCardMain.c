#include<stdio.h>
#include<stdlib.h>
#include"ArrayList.h"
#include"NameCard.h"

int main() {
    List list;
    ListInit(&list);
    NameCard* pcard;

    pcard = MakeNameCard("김두익", "010-6361-8230");
    LInsert(&list, pcard);

    pcard = MakeNameCard("박은주", "010-5550-2758");
    LInsert(&list, pcard);

    pcard = MakeNameCard("김정국", "010-3289-8230");
    LInsert(&list, pcard);

    if(LFirst(&list, &pcard)) {
        if(!NameCompare(pcard, "김정국")) {
            ShowNameCardInfo(pcard);
        }
        while(LNext(&list, &pcard)) {
            if(!NameCompare(pcard, "김정국")) {
                ShowNameCardInfo(pcard);
            }
        }
    }
    if(LFirst(&list, &pcard)) {
        if(!NameCompare(pcard, "김두익")) {
            ChangePhoneNum(&pcard, "+86 32-6251-1921");
        }
        while(LNext(&list, &pcard)) {
            if(!NameCompare(pcard, "김두익")) {
                ChangePhoneNum(&pcard, "+86 32-6251-1921");
            }
        }
    }
    if(LFirst(&list, &pcard)) {
        if(!NameCompare(pcard, "박은주")) {
            LRemove(&pcard);
        }
        while(LNext(&list, &pcard)) {
            if(!NameCompare(pcard, "박은주")) {
                LRemove(&pcard);
            }
        }
    }
    if(LFirst(&list, &pcard)) {
        ShowNameCardInfo(pcard);
        while(LNext(&list, &pcard)) {
            ShowNameCardInfo(pcard);
        }
    }
    return 0;
}