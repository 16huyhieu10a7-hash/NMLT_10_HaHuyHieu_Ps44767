#include <stdio.h>

/* ==================== NGUYÊN MẪU HÀM ==================== */
void tinhTrungBinhCong(int a[], int n);
void timMaxMin(int a[], int n);
void sapXepGiamDan(int a[], int n);
void maTranBinhPhuong(int row, int col);
void locSoLeMaTran(int row, int col);

/* ==================== HÀM MAIN - KHUNG MENU ==================== */
int main() {
    int choice;

    do {
        printf("\n+--------------------------------------+\n");
        printf("|        MENU CHUONG TRINH LAB 6       |\n");
        printf("+--------------------------------------+\n");
        printf("| 1. Tinh trung binh tong so chia het cho 3 va 5 |\n");
        printf("| 2. Tim gia tri Lon nhat va Nho nhat trong Mang |\n");
        printf("| 3. Sap xep Mang theo thu tu Giam dan          |\n");
        printf("| 4. Ma tran binh phuong (Mang 2 chieu)         |\n");
        printf("| 5. Loc va xuat vi tri cac So le trong Ma tran |\n");
        printf("| 6. Thoat chuong trinh                         |\n");
        printf("+--------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int n;
                printf("Nhap so phan tu n: ");
                scanf("%d", &n);
                int a[n];
                tinhTrungBinhCong(a, n);
                break;
            }
            case 2: {
                int n;
                printf("Nhap so phan tu n: ");
                scanf("%d", &n);
                int a[n];
                timMaxMin(a, n);
                break;
            }
            case 3: {
                int n;
                printf("Nhap so phan tu n: ");
                scanf("%d", &n);
                int a[n];
                sapXepGiamDan(a, n);
                break;
            }
            case 4: {
                int row, col;
                printf("Nhap so hang: ");
                scanf("%d", &row);
                printf("Nhap so cot: ");
                scanf("%d", &col);
                maTranBinhPhuong(row, col);
                break;
            }
            case 5: {
                int row, col;
                printf("Nhap so hang: ");
                scanf("%d", &row);
                printf("Nhap so cot: ");
                scanf("%d", &col);
                locSoLeMaTran(row, col);
                break;
            }
            case 6:
                printf("Thoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon tu 1 den 6.\n");
        }
    } while (choice != 6);

    return 0;
}

/* ==================== CHỨC NĂNG 1 ==================== */
void tinhTrungBinhCong(int a[], int n) {
    int i, count = 0;
    float Tong = 0, TrungBinh;

    printf("Nhap %d phan tu cua mang:\n", n);
    for (i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) {
        if (a[i] % 3 == 0 && a[i] % 5 == 0) {
            Tong += a[i];
            count++;
        }
    }

    if (count == 0) {
        printf("Khong co so nao thoa man (chia het cho ca 3 va 5)!\n");
    } else {
        TrungBinh = Tong / count;
        printf("Trung binh tong cac so chia het cho 3 va 5 = %.2f\n", TrungBinh);
    }
}

/* ==================== CHỨC NĂNG 2 ==================== */
void timMaxMin(int a[], int n) {
    int i, max, min;

    printf("Nhap %d phan tu cua mang:\n", n);
    for (i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    max = min = a[0];
    for (i = 1; i < n; i++) {
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }

    printf("Gia tri lon nhat = %d\n", max);
    printf("Gia tri nho nhat = %d\n", min);
}

/* ==================== CHỨC NĂNG 3 ==================== */
void sapXepGiamDan(int a[], int n) {
    int i, j, temp;

    printf("Nhap %d phan tu cua mang:\n", n);
    for (i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    /* Bubble sort giam dan */
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("Mang sau khi sap xep giam dan:\n");
    for (i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
}

/* ==================== CHỨC NĂNG 4 ==================== */
void maTranBinhPhuong(int row, int col) {
    int i, j;
    int a[row][col];

    printf("Nhap ma tran %d x %d:\n", row, col);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Ma tran binh phuong:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d\t", a[i][j] * a[i][j]);
        }
        printf("\n");
    }
}

/* ==================== CHỨC NĂNG 5 ==================== */
void locSoLeMaTran(int row, int col) {
    int i, j;
    int a[row][col];
    int coSoLe = 0;

    printf("Nhap ma tran %d x %d:\n", row, col);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Vi tri cac so le trong ma tran:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (a[i][j] % 2 != 0) {
                printf("a[%d][%d] = %d\n", i, j, a[i][j]);
                coSoLe = 1;
            }
        }
    }

    if (!coSoLe) {
        printf("Khong co so le nao trong ma tran!\n");
    }
}