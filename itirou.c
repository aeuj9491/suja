#include <stdio.h>
#define MAP_SIZE 5


int main(){
    int px = 0;
    int py=4;
    char input;
    int haskey;
    int map[MAP_SIZE][MAP_SIZE]={
        {0, 0, 0, 1, 2},
        {1, 1, 0, 1, 4},
        {3, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };


    while(1){
        printf("\n--- 脱出迷路 ---\n");
        for(int y = 0; y<MAP_SIZE; y++){
            for(int x = 0; x<MAP_SIZE; x++){
                if(x==px && y==py){
                    printf("P");
                }else if(map[y][x] == 1){
                    printf("#");
                }else if(map[y][x] == 2){
                    printf("G");
                }else if(map[y][x] == 3){
                    printf("K");
                }else if(map[y][x] == 4){
                    printf("D");
                }else{
                    printf(".");
                }
            }
            printf("\n");

        }

        printf("移動 (w:上, s:下, a:左, d:右): \n");
        scanf(" %c", &input);
        int nextX = px;
        int nextY = py;

        if(input == 'w')nextY--;
        else if(input == 's')nextY++;
        else if(input == 'a')nextX--;
        else if(input =='d')nextX++;

        if(nextX>=0 && nextX<MAP_SIZE && nextY>=0 && nextY<MAP_SIZE){
            if(map[nextY][nextX] != 1){
                px = nextX;
                py = nextY;
            }else{
                printf("壁があって進めません！\n");
            }

        }else{
            printf("画面の外には出られません！");
        }
        
        if (map[py][px] == 2) {
            printf("\nおめでとう！ゴールに到達しました！\n");
            break; // これでwhileループ（ゲーム）を抜ける
        }
        
    }    
        
    return 0;

}


