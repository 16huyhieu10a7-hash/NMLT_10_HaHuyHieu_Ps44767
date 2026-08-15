```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Khai bao ham
void demNguyenAmPhuAm();
void dangNhap();
void sapXepChuoi();
void doiThapPhanSangNhiPhan();

int main() {
    int chon;

    do {
        printf("\n========== MENU LAB 7 ==========\n");
        printf("1. Dem nguyen am va phu am\n");
        printf("2. Dang nhap he thong\n");
        printf("3. Sap xep chuoi theo Alphabet\n");
        printf("4. Doi thap phan sang nhi phan\n");
        printf("5. Thoat\n");
        printf("================================\n");

        printf("Nhap lua chon: ");
        scanf("%d", &chon);
        getchar();

        switch (chon) {
            case 1:
                demNguyenAmPhuAm();
                break;

            case 2:
                dangNhap();
                break;

            case 3:
                sapXepChuoi();
                break;

            case 4:
                doiThapPhanSangNhiPhan();
                break;

            case 5:
                printf("Da thoat chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong dung!\n");
        }

    } while (chon != 5);

    return 0;
}


// ================= CHUC NANG 1 =================
void demNguyenAmPhuAm() {
    char chuoi[100];
    int nguyenAm = 0;
    int phuAm = 0;
    int i;

    printf("\n--- DEM NGUYEN AM VA PHU AM ---\n");

    printf("Nhap chuoi: ");
    fgets(chuoi, sizeof(chuoi), stdin);

    // Xoa dau Enter
    chuoi[strcspn(chuoi, "\n")] = '\0';

    for (i = 0; chuoi[i] != '\0'; i++) {

        char c = tolower(chuoi[i]);

        if (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u') {

            nguyenAm++;
        }
        else if (isalpha(c)) {
            phuAm++;
        }
    }

    printf("So nguyen am: %d\n", nguyenAm);
    printf("So phu am: %d\n", phuAm);
}


// ================= CHUC NANG 2 =================
void dangNhap() {
    char username[50];
    char password[50];

    char taiKhoanDung[] = "admin";
    char matKhauDung[] = "123456";

    printf("\n--- DANG NHAP HE THONG ---\n");

    printf("Nhap username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Nhap password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    if (strcmp(username, taiKhoanDung) == 0 &&
        strcmp(password, matKhauDung) == 0) {

        printf("Dang nhap thanh cong!\n");
    }
    else {
        printf("Sai username hoac password!\n");
    }
}


// ================= CHUC NANG 3 =================
void sapXepChuoi() {
    char danhSach[5][50];
    char tam[50];
    int i, j;

    printf("\n--- SAP XEP CHUOI ---\n");

    // Nhap 5 chuoi
    for (i = 0; i < 5; i++) {
        printf("Nhap chuoi thu %d: ", i + 1);

        fgets(danhSach[i], sizeof(danhSach[i]), stdin);

        danhSach[i][strcspn(danhSach[i], "\n")] = '\0';
    }

    // Sap xep tang dan
    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 5; j++) {

            if (strcmp(danhSach[i], danhSach[j]) > 0) {

                strcpy(tam, danhSach[i]);
                strcpy(danhSach[i], danhSach[j]);
                strcpy(danhSach[j], tam);
            }
        }
    }

    printf("\nDanh sach sau khi sap xep:\n");

    for (i = 0; i < 5; i++) {
        printf("%s\n", danhSach[i]);
    }
}


// ================= CHUC NANG 4 =================
void doiThapPhanSangNhiPhan() {
    int n;
    int i = 0;
    char ketQua[50];

    printf("\n--- DOI THAP PHAN SANG NHI PHAN ---\n");

    printf("Nhap so nguyen duong: ");
    scanf("%d", &n);
    getchar();

    if (n == 0) {
        printf("So nhi phan la: 0\n");
        return;
    }

    // Lay tung phan du khi chia cho 2
    while (n > 0) {
        ketQua[i] = n % 2 + '0';

        n = n / 2;

        i++;
    }

    ketQua[i] = '\0';

    // Dao nguoc chuoi
    int dau = 0;
    int cuoi = i - 1;

    while (dau < cuoi) {
        char tam;

        tam = ketQua[dau];
        ketQua[dau] = ketQua[cuoi];
        ketQua[cuoi] = tam;

        dau++;
        cuoi--;
    }

    printf("So nhi phan la: %s\n", ketQua);
}

