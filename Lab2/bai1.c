#include <stdio.h>
#define PI 3.14159
int main(){
    int dai,rong,r;
    printf("Nhap chieu dai: ");
    scanf("%d",&dai);
    printf("Nhap chieu rong: ");
    scanf("%d",&rong);

    printf("Dai: %d\nRong: %d\nChu vi: %d\nDien tich: %d\n",dai,rong,(dai + rong)*2,dai*rong);

    printf("Nhap ban kinh hinh tron: ");
    scanf("%d",&r);
    float cv = r*2*PI;
    float dt = r*r*PI;
    printf("Ban kinh: %d\nChu vi: %.2f\nDien tich: %.2f\n",r,cv,dt);
    return 0;
}
