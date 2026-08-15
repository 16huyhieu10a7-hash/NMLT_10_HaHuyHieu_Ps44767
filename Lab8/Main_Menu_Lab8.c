```c
#include <stdio.h>
#include <string.h>

// Tao cau truc Sinh Vien
struct SinhVien {
    char mssv[50];
    char ten[50];
    char nganh[50];
    float diem;
};

// Khai bao ham
void nhapSinhVien(struct SinhVien ds[], int *n);
void sapXep(struct SinhVien ds[], int n);
void timSinhVien(struct SinhVien ds[], int n);
void hocBong(struct SinhVien ds[], int n);

int main() {
    struct SinhVien ds[100];
    int n = 0;
    int chon;

    do {
        printf("\n========== QUAN LY SINH VIEN - LAB 8 ==========\n");
        printf("1. Nhap va xuat danh sach sinh vien\n");
        printf("2. Sap xep sinh vien theo diem tang dan\n");
        printf("3. Tim sinh vien theo MSSV\n");
        printf("4. Xuat sinh vien dat hoc bong\n");
        printf("5. Thoat\n");
        printf("===============================================\n");

        printf("Nhap lua chon: ");
        scanf("%d", &chon);
        getchar();

        switch (chon) {

            case 1:
                nhapSinhVien(ds, &n);
                break;

            case 2:
                if (n == 0) {
                    printf("Chua co sinh vien!\n");
                } else {
                    sapXep(ds, n);
                }
                break;

            case 3:
                if (n == 0) {
                    printf("Chua co sinh vien!\n");
                } else {
                    timSinhVien(ds, n);
                }
                break;

            case 4:
                if (n == 0) {
                    printf("Chua co sinh vien!\n");
                } else {
                    hocBong(ds, n);
                }
                break;

            case 5:
                printf("Da thoat chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (chon != 5);

    return 0;
}


// ================= NHAP VA XUAT =================
void nhapSinhVien(struct SinhVien ds[], int *n) {

    int i;

    printf("\n--- NHAP DANH SACH SINH VIEN ---\n");

    printf("Nhap so luong sinh vien: ");
    scanf("%d", n);
    getchar();

    if (*n <= 0 || *n > 100) {
        printf("So luong sinh vien khong hop le!\n");
        *n = 0;
        return;
    }

    for (i = 0; i < *n; i++) {

        printf("\nSinh vien thu %d\n", i + 1);

        printf("Nhap MSSV: ");
        fgets(ds[i].mssv, 50, stdin);
        ds[i].mssv[strcspn(ds[i].mssv, "\n")] = '\0';

        printf("Nhap ho ten: ");
        fgets(ds[i].ten, 50, stdin);
        ds[i].ten[strcspn(ds[i].ten, "\n")] = '\0';

        printf("Nhap nganh hoc: ");
        fgets(ds[i].nganh, 50, stdin);
        ds[i].nganh[strcspn(ds[i].nganh, "\n")] = '\0';

        printf("Nhap diem trung binh: ");
        scanf("%f", &ds[i].diem);
        getchar();
    }

    printf("\n========== DANH SACH SINH VIEN ==========\n");

    printf("%-15s %-25s %-20s %-10s\n",
           "MSSV", "Ho ten", "Nganh", "Diem");

    printf("---------------------------------------------------------------\n");

    for (i = 0; i < *n; i++) {

        printf("%-15s %-25s %-20s %-10.2f\n",
               ds[i].mssv,
               ds[i].ten,
               ds[i].nganh,
               ds[i].diem);
    }
}


// ================= SAP XEP =================
void sapXep(struct SinhVien ds[], int n) {

    int i, j;
    struct SinhVien tam;

    printf("\n--- SAP XEP THEO DIEM TANG DAN ---\n");

    for (i = 0; i < n - 1; i++) {

        for (j = i + 1; j < n; j++) {

            if (ds[i].diem > ds[j].diem) {

                tam = ds[i];
                ds[i] = ds[j];
                ds[j] = tam;
            }
        }
    }

    printf("\nDanh sach sau khi sap xep:\n");

    printf("%-15s %-25s %-20s %-10s\n",
           "MSSV", "Ho ten", "Nganh", "Diem");

    printf("---------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {

        printf("%-15s %-25s %-20s %-10.2f\n",
               ds[i].mssv,
               ds[i].ten,
               ds[i].nganh,
               ds[i].diem);
    }
}


// ================= TIM KIEM =================
void timSinhVien(struct SinhVien ds[], int n) {

    char maCanTim[50];
    int i;
    int timThay = 0;

    printf("\n--- TIM SINH VIEN THEO MSSV ---\n");

    printf("Nhap MSSV can tim: ");
    fgets(maCanTim, 50, stdin);

    maCanTim[strcspn(maCanTim, "\n")] = '\0';

    for (i = 0; i < n; i++) {

        if (strcmp(ds[i].mssv, maCanTim) == 0) {

            printf("\nSinh vien can tim:\n");

            printf("MSSV  : %s\n", ds[i].mssv);
            printf("Ho ten: %s\n", ds[i].ten);
            printf("Nganh : %s\n", ds[i].nganh);
            printf("Diem  : %.2f\n", ds[i].diem);

            timThay = 1;

            break;
        }
    }

    if (timThay == 0) {
        printf("Khong tim thay sinh vien!\n");
    }
}


// ================= HOC BONG =================
void hocBong(struct SinhVien ds[], int n) {

    int i;
    int dem = 0;

    printf("\n--- SINH VIEN DAT HOC BONG ---\n");

    printf("%-15s %-25s %-20s %-10s\n",
           "MSSV", "Ho ten", "Nganh", "Diem");

    printf("---------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {

        if (ds[i].diem >= 8.0) {

            printf("%-15s %-25s %-20s %-10.2f\n",
                   ds[i].mssv,
                   ds[i].ten,
                   ds[i].nganh,
                   ds[i].diem);

            dem++;
        }
    }

    if (dem == 0) {
        printf("Khong co sinh vien dat hoc bong!\n");
    } else {
        printf("\nCo %d sinh vien dat hoc bong.\n", dem);
    }
}
```
