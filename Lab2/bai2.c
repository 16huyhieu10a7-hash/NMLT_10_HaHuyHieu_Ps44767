#include <stdio.h>

int main() {
    float toan, ly, hoa, dtb;

    printf("Nhap diem Toan: ");
    scanf("%f", &toan);

    printf("Nhap diem Ly: ");
    scanf("%f", &ly);

    printf("Nhap diem Hoa: ");
    scanf("%f", &hoa);

    dtb = (toan * 3 + ly * 2 + hoa) / 6.0;

    printf("\nDiem trung binh = %.2f\n", dtb);

    return 0;
}