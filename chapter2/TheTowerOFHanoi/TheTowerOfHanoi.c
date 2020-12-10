#include <stdio.h>
int count = 0;
void moveCount(int num, char from, char by, char to) {
    if(num == 1) {
        count++;
    }
    else {
        count++;
        moveCount(num - 1, from, to, by);
        return moveCount(num - 1, by, from, to);
    }
}

void HanoiTowerMove(int num, char from, char by, char to) {
    if(num == 1) {
        printf("%c %c\n", from, to);
    }
    else {
        HanoiTowerMove(num - 1, from, to, by);
        printf("%c %c\n", from, to);
        return HanoiTowerMove(num - 1, by, from, to);
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    moveCount(n, '1', '2', '3');
    printf("%d\n", count);
    HanoiTowerMove(n, '1', '2', '3');

    return 0;
}