#include <stdio.h>

/* ===================== FUNCTION PROTOTYPES ===================== */
int findMax(int a, int b, int c);
int checkYear(int year);
void swap(int *a, int *b);
void checkTriangle(float a, float b, float c);

/* ===================== MAIN - MENU FRAMEWORK ===================== */
int main() {
    int choice;

    do {
        printf("\n+------------------------------------------+\n");
        printf("|         MENU CHUONG TRINH LAB.5          |\n");
        printf("+------------------------------------------+\n");
        printf("| 1. Tim gia tri lon nhat trong 3 so       |\n");
        printf("| 2. Kiem tra Nam nhuan                    |\n");
        printf("| 3. Hoan vi 2 so (Su dung Con tro)        |\n");
        printf("| 4. Kiem tra & Phan loai Tam giac         |\n");
        printf("| 5. Thoat chuong trinh                    |\n");
        printf("+------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int x, y, z, maxVal;
                printf("\n--- Chuc nang 1: Tim gia tri lon nhat trong 3 so ---\n");
                printf("Nhap 3 so nguyen: ");
                scanf("%d %d %d", &x, &y, &z);
                maxVal = findMax(x, y, z);
                printf("Gia tri lon nhat la: %d\n", maxVal);
                break;
            }
            case 2: {
                int year;
                printf("\n--- Chuc nang 2: Kiem tra Nam nhuan ---\n");
                printf("Nhap nam can kiem tra: ");
                scanf("%d", &year);
                if (checkYear(year)) {
                    printf("Nam %d la Nam nhuan.\n", year);
                } else {
                    printf("Nam %d khong phai Nam nhuan.\n", year);
                }
                break;
            }
            case 3: {
                int a, b;
                printf("\n--- Chuc nang 3: Hoan vi 2 so (Con tro) ---\n");
                printf("Nhap gia tri a: ");
                scanf("%d", &a);
                printf("Nhap gia tri b: ");
                scanf("%d", &b);
                printf("Truoc khi hoan vi: a = %d, b = %d\n", a, b);
                swap(&a, &b);
                printf("Sau khi hoan vi:   a = %d, b = %d\n", a, b);
                break;
            }
            case 4: {
                float a, b, c;
                printf("\n--- Chuc nang 4: Kiem tra & Phan loai Tam giac ---\n");
                printf("Nhap 3 canh tam giac (a b c): ");
                scanf("%f %f %f", &a, &b, &c);
                checkTriangle(a, b, c);
                break;
            }
            case 5:
                printf("\nThoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("\nLua chon khong hop le! Vui long chon tu 1 den 5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

/* ===================== FUNCTION IMPLEMENTATIONS ===================== */

/* Chuc nang 1: Tim gia tri lon nhat trong 3 so */
int findMax(int a, int b, int c) {
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

/* Chuc nang 2: Kiem tra Nam nhuan */
int checkYear(int year) {
    /* Nam nhuan: chia het cho 400, hoac chia het cho 4 nhung khong chia het cho 100 */
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        return 1; /* True */
    }
    return 0; /* False */
}

/* Chuc nang 3: Hoan vi 2 so su dung con tro (Pass-by-reference) */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Chuc nang 4: Kiem tra & Phan loai Tam giac */
void checkTriangle(float a, float b, float c) {
    /* Dieu kien tao thanh tam giac: a + b > c && a + c > b && b + c > a (va 3 canh > 0) */
    if (a <= 0 || b <= 0 || c <= 0 || !(a + b > c && a + c > b && b + c > a)) {
        printf("Day khong phai la 3 canh cua mot tam giac.\n");
        return;
    }

    /* Phan loai tam giac */
    int isEquilateral = (a == b && b == c);
    int isIsosceles   = (a == b || b == c || a == c);
    int isRight       = (a*a + b*b == c*c) || (a*a + c*c == b*b) || (b*b + c*c == a*a);

    if (isEquilateral) {
        printf("Tam giac deu.\n");
    } else if (isRight && isIsosceles) {
        printf("Tam giac vuong can.\n");
    } else if (isRight) {
        printf("Tam giac vuong.\n");
    } else if (isIsosceles) {
        printf("Tam giac can.\n");
    } else {
        printf("Tam giac thuong.\n");
    }
}