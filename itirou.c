#include <stdio.h>


#define MAP_SIZE 10

typedef struct {
    int x;
    int y;
    int hasKey;
} Player;

void drawMap(int map[MAP_SIZE][MAP_SIZE], Player p) {
    
    printf("\n========== 脱出迷路10x10 ==========\n");
    printf(" [P]:自分  [K]:鍵  [D]:扉  [G]:ゴール  [#]:壁\n");
    printf(" 状態: %s\n", p.hasKey ? "【鍵を所持！】" : "  鍵を探せ ");
    printf("-----------------------------------\n");

    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            if (x == p.x && y == p.y) printf("P ");
            else if (map[y][x] == 1) printf("# ");
            else if (map[y][x] == 2) printf("G ");
            else if (map[y][x] == 3) printf("K ");
            else if (map[y][x] == 4) printf("D ");
            else printf(". ");
        }
        printf("\n");
    }
}

void movePlayer(int map[MAP_SIZE][MAP_SIZE], Player *p, char input) {
    int nX = p->x, nY = p->y;

    if (input == 'w') nY--;
    else if (input == 's') nY++;
    else if (input == 'a') nX--;
    else if (input == 'd') nX++;

    if (nX < 0 || nX >= MAP_SIZE || nY < 0 || nY >= MAP_SIZE) return;

    int target = map[nY][nX];
    if (target == 1) {
        printf("\a"); 
    } else if (target == 4 && p->hasKey == 0) {
        printf("\n>> 扉が閉まっている！鍵が必要だ。\n");
    } else {
        p->x = nX; p->y = nY;
        if (target == 3) {
            printf("\n>> 鍵を手に入れた！扉が開けられるぞ。\n");
            p->hasKey = 1;
            map[p->y][p->x] = 0;
        } else if (target == 4) {
            printf("\n>> 鍵を使って扉を開放した！\n");
            map[p->y][p->x] = 0;
        }
    }
}

int main() {
    // スタート地点を左下に設定
    Player p = {0, 9, 0}; 

    // 10x10の本格迷路データ (0:道, 1:壁, 2:ゴール, 3:鍵, 4:扉)
    int map[MAP_SIZE][MAP_SIZE] = {
        {2, 0, 1, 0, 0, 0, 0, 1, 3, 0}, // 左上にG、右上にK
        {1, 0, 1, 0, 1, 1, 0, 1, 1, 0},
        {1, 4, 1, 0, 0, 1, 0, 0, 0, 0}, // (1,2)に扉D
        {1, 0, 1, 1, 0, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 1, 1, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 0}  // 左下(0,9)からスタート
    };

    while (1) {
        drawMap(map, p);

        if (map[p.y][p.x] == 2) {
            printf("\n==============================\n");
            printf("  CONGRATULATIONS! 脱出成功！\n");
            printf("==============================\n");
            break;
        }

        printf("移動 (w:上, s:下, a:左, d:右): ");
        char input;
        scanf(" %c", &input);
        movePlayer(map, &p, input);
    }

    return 0;
}


