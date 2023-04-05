//
// Created by Sabbrumm on 11.10.2022.
//

#include <windows.h>
#include <conio.h>
#include <stdio.h>

#define KEY_ESC 27
#define KEY_CONTROL 224
#define KEY_BACKSPACE 8
#define KEY_ENTER 13

int width = 0;
int height = 0;
int cant = 0;
int massive[12][12] = {};

void print_spiral(){
    for (int i = 0; i<width; i++){
        for (int j = 0; j<height; j++){
            printf("%3d ", massive[i][j]);
        }
        printf("\n");
    }
}
void null_massive(){
    for (int i = 0; i<12; i++){
        for (int j = 0; j<12; j++){
            massive[i][j]=0;
        }
    }
}
void generate_left_center(){
    null_massive();
    int startcol = 0;
    int startrow = 0;
    int endcol = height-1;
    int endrow = width-1;
    int filler = 1;


    while(startcol <= endcol && startrow<=endrow && filler<=width*height){
        if (filler<=width*height){
            for (int i = startcol; i<=endcol; i++) {
                massive[startrow][i] = filler;
                filler++;
            }
            startrow++;
        }

        if (filler<=width*height){
            for (int j = startrow; j<=endrow; j++) {
                massive[j][endcol] = filler;
                filler++;
            }
            endcol--;
        }

        if (filler<=width*height){
            for (int k = endcol; k>=startcol; k--) {
                massive[endrow][k] = filler;
                filler++;
            }
            endrow--;
        }

        if (filler<=width*height){
            for (int l = endrow; l>=startrow; l--){
                massive[l][startcol] = filler;
                filler++;
            }
            startcol++;
        }
    }
    print_spiral();
}
void generate_right_center(){
    null_massive();
    int startcol = 0;
    int startrow = 0;
    int endcol = height-1;
    int endrow = width-1;
    int filler = 1;


    while(startcol <= endcol && startrow<=endrow && filler<=width*height){
        if (filler<=width*height){
            for (int i = endcol; i>=startcol; i--) {
                massive[startrow][i] = filler;
                filler++;
            }
            startrow++;
        }

        if (filler<=width*height){
            for (int j = startrow; j<=endrow; j++) {
                massive[j][startcol] = filler;
                filler++;
            }
            startcol++;
        }

        if (filler<=width*height){
            for (int k = startcol; k<=endcol; k++) {
                massive[endrow][k] = filler;
                filler++;
            }
            endrow--;
        }

        if (filler<=width*height){
            for (int l = endrow; l>=startrow; l--){
                massive[l][endcol] = filler;
                filler++;
            }
            endcol--;
        }
    }
    print_spiral();
}
void generate_center_left(){
    null_massive();
    int startcol = 0;
    int startrow = 0;
    int endcol = height-1;
    int endrow = width-1;
    int filler = 1;


    while(startcol <= endcol && startrow<=endrow && filler<=width*height){
        if (filler<=width*height){
            for (int i = startcol; i<=endcol; i++) {
                massive[startrow][i] = filler;
                filler++;
            }
            startrow++;
        }

        if (filler<=width*height){
            for (int j = startrow; j<=endrow; j++) {
                massive[j][endcol] = filler;
                filler++;
            }
            endcol--;
        }

        if (filler<=width*height){
            for (int k = endcol; k>=startcol; k--) {
                massive[endrow][k] = filler;
                filler++;
            }
            endrow--;
        }

        if (filler<=width*height){
            for (int l = endrow; l>=startrow; l--){
                massive[l][startcol] = filler;
                filler++;
            }
            startcol++;
        }
    }

    for (int i = 0; i<width; i++){
        for (int j = 0; j<height; j++){
            massive[i][j] = massive[i][j] = abs(massive[i][j]-(width*height+1));
        }
    }
    print_spiral();
}
void generate_center_right(){
    null_massive();
    int startcol = 0;
    int startrow = 0;
    int endcol = height-1;
    int endrow = width-1;
    int filler = 1;


    while(startcol <= endcol && startrow<=endrow && filler<=width*height){
        if (filler<=width*height){
            for (int i = endcol; i>=startcol; i--) {
                massive[startrow][i] = filler;
                filler++;
            }
            startrow++;
        }

        if (filler<=width*height){
            for (int j = startrow; j<=endrow; j++) {
                massive[j][startcol] = filler;
                filler++;
            }
            startcol++;
        }

        if (filler<=width*height){
            for (int k = startcol; k<=endcol; k++) {
                massive[endrow][k] = filler;
                filler++;
            }
            endrow--;
        }

        if (filler<=width*height){
            for (int l = endrow; l>=startrow; l--){
                massive[l][endcol] = filler;
                filler++;
            }
            endcol--;
        }
    }
    for (int i = 0; i<width; i++){
        for (int j = 0; j<height; j++){
            massive[i][j] = massive[i][j] = abs(massive[i][j]-(width*height+1));
        }
    }
    print_spiral();
}
void attention(int cou){
    if (cou == 1){
        printf("Высота может быть введена только от 1 до 12");
    }

    if (cou == 2){
        printf("Длина может быть введена только от 1 до 12");
    }

    if (cou == 7){
        printf("Выйти из программы");
    }

}
void arrow(int expression){
    if (expression) {
        printf(" <--\n");
    }
    else {
        printf("\n");
    }
}
void UI(int cou){
    printf("СПИРАЛЬКА C-NOVA\n\n");


    printf("1. Ввод высоты:   %d", width);
    arrow(cou==1);

    printf("2. Ввод длины:    %d", height);
    arrow(cou==2);

    printf("3. С левого верхнего края в центр");
    arrow(cou==3);

    printf("4. С правого верхнего края в центр");
    arrow(cou==4);

    printf("5. Из центра в правый верхний край");
    arrow(cou==5);

    printf("6. Из центра в левый верхний край");
    arrow(cou==6);

    printf("7. Выход (Кнопка ESC)");
    arrow(cou==7);

    printf("\n\n");

    if (cou >= 3 && cou <=6){
        if (cant == 0){
            if (cou==3){
                generate_left_center();
            }
            if (cou==4){
                generate_right_center();
            }
            if (cou==5){
                generate_center_right();
            }
            if (cou==6){
                generate_center_left();
            }
        }

        else {
            printf("Вы ввели неверные параметры");
        }
    }
    else {
        attention(cou);
    }

}
void check_input(){
    if (height>0 && height<14 && width>0 && width<13){
        cant = 0;
    }
    else{
        cant = 1;
    }
}

int main(){
    int cou = 1;

    SetConsoleOutputCP(CP_UTF8);

    while (1){
        system("cls");

        check_input();

        UI(cou);

        long inp = _getch();

        if (inp==KEY_ESC){
            break;
        }

        if (inp==KEY_CONTROL){
            long inp2 = _getch();
            if (inp2 == 80){
                cou+=1;
                if (cou==8){
                    cou=1;
                }
            }
            if (inp2 == 72){
                cou-=1;
                if (cou==0){
                    cou=7;
                }
            }

        }

        if (inp == KEY_BACKSPACE){
            if (cou==1){
                width = width/10;
            }
            if (cou==2){
                height = height/10;
            }
        }

        if (inp == KEY_ENTER){
            if (cou==7){
                break;
            }
        }

        if (inp >=48 && inp<=57){
            int num = inp-48;
            if (cou==1){
                if (width==0){
                    width = num;
                }
                else if (width==1 && num<=2){
                    width = width*10+num;
                }
            }
            if (cou==2){
                if (height==0){
                    height = num;
                }
                else if (height==1 && num<=2){
                    height = height*10+num;
                }
            }
        }
    }

}



