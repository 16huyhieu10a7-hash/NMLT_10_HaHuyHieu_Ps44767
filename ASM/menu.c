#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// khai bao ham
void chuc_nang_1();
void chuc_nang_2();
void chuc_nang_3();
void chuc_nang_4();
void chuc_nang_5();
void chuc_nang_6();
void chuc_nang_7();
void chuc_nang_8();
void chuc_nang_9();
void chuc_nang_10();

// ==================== MENU CHINH ====================
int main() {
    int chon;
    while (1) {
        printf("\n=======================================================\n");
        printf("          CHUONG TRINH ASM 1 - NHAP MON LAP TRINH\n");
        printf("=======================================================\n");
        printf("1. Kiem tra so nguyen / nguyen to / chinh phuong\n");
        printf("2. Uoc chung lon nhat & Boi chung nho nhat\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien theo bac\n");
        printf("5. Doi tien theo menh gia\n");
        printf("6. Tinh lai suat vay tra gop 12 thang\n");
        printf("7. Vay tien mua xe (500 trieu)\n");
        printf("8. Quan ly & sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT (2/15)\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat chuong trinh\n");
        printf("=======================================================\n");
        printf("Moi ban chon chuc nang (0-10): ");

        if (scanf("%d", &chon) != 1) {
            printf("Lua chon khong hop le!\n");
            while(getchar() != '\n');
            continue;
        }

        switch (chon) {
            case 1: chuc_nang_1(); break;
            case 2: chuc_nang_2(); break;
            case 3: chuc_nang_3(); break;
            case 4: chuc_nang_4(); break;
            case 5: chuc_nang_5(); break;
            case 6: chuc_nang_6(); break;
            case 7: chuc_nang_7(); break;
            case 8: chuc_nang_8(); break;
            case 9: chuc_nang_9(); break;
            case 10: chuc_nang_10(); break;
            case 0:
                printf("\nCam on ban da su dung chuong trinh. Tam biet!\n");
                return 0;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }
    }
    return 0;
}

// ==================== CHUC NANG 1 ====================
void chuc_nang_1() {
    double x;
    printf("\n=== Chuc nang 1: Kiem tra so nguyen ===\n");
    printf("Nhap so x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Nhap khong hop le!\n");
        while(getchar() != '\n');
        printf("\nNhan Enter de quay ve menu...");
        getchar();
        return;
    }

    // kiem tra xem co phai so nguyen khong
    int laSoNguyen = (x == (int)x);
    printf("So %.2f co phai la so nguyen? -> %s\n", x, laSoNguyen ? "Co" : "Khong");

    if (!laSoNguyen) {
        printf("Vi khong phai so nguyen nen khong kiem tra tiep.\n");
        printf("\nNhan Enter de quay ve menu...");
        getchar(); getchar();
        return;
    }

    int n = (int)x;

    // kiem tra so nguyen to
    int laNguyenTo = 1;
    if (n < 2) {
        laNguyenTo = 0;
    } else {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                laNguyenTo = 0;
                break;
            }
        }
    }
    printf("So %d co phai la so nguyen to? -> %s\n", n, laNguyenTo ? "Co" : "Khong");

    // kiem tra so chinh phuong
    int canBac2 = (int)sqrt(n);
    int laChinhPhuong = (canBac2 * canBac2 == n);
    printf("So %d co phai la so chinh phuong? -> %s\n", n, laChinhPhuong ? "Co" : "Khong");

    printf("\nNhan Enter de quay ve menu...");
    getchar(); getchar();
}

// ==================== CHUC NANG 2 ====================
void chuc_nang_2() {
    int x, y;
    printf("\n=== Chuc nang 2: UCLN & BCNN ===\n");
    printf("Nhap so nguyen x: ");
    if (scanf("%d", &x) != 1) {
        printf("Nhap sai!\n");
        while(getchar() != '\n');
        printf("\nNhan Enter de quay ve menu...");
        getchar();
        return;
    }
    printf("Nhap so nguyen y: ");
    if (scanf("%d", &y) != 1) {
        printf("Nhap sai!\n");
        while(getchar() != '\n');
        printf("\nNhan Enter de quay ve menu...");
        getchar();
        return;
    }

    // tim UCLN bang thuat toan Euclid
    int a = abs(x);
    int b = abs(y);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int ucln = a;

    // BCNN = tich 2 so / UCLN
    int bcnn = 0;
    if (ucln != 0) {
        bcnn = abs(x * y) / ucln;
    }

    printf("Uoc so chung lon nhat cua %d va %d la: %d\n", x, y, ucln);
    printf("Boi so chung nho nhat cua %d va %d la: %d\n", x, y, bcnn);

    printf("\nNhan Enter de quay ve menu...");
    getchar(); getchar();
}

// ==================== CHUC NANG 3 ====================
void chuc_nang_3() {
    double gioBatDau, gioKetThuc;
    printf("\n=== Chuc nang 3: Tinh tien Karaoke ===\n");
    printf("Quan hoat dong tu 12h den 23h\n");
    printf("Nhap gio bat dau (vd: 14.5): ");
    if (scanf("%lf", &gioBatDau) != 1) {
        printf("Nhap sai!\n");
        while(getchar() != '\n');
        printf("\nNhan Enter de quay ve menu...");
        getchar();
        return;
    }
    printf("Nhap gio ket thuc (vd: 18): ");
    if (scanf("%lf", &gioKetThuc) != 1) {
        printf("Nhap sai!\n");
        while(getchar() != '\n');
        printf("\nNhan Enter de quay ve menu...");
        getchar();
        return;
    }

    // kiem tra gio hop le
    if (gioBatDau < 12 || gioKetThuc > 23 || gioKetThuc <= gioBatDau) {
        printf("Gio khong hop le! Quan chi mo tu 12h den 23h\n");
        printf("\nNhan Enter de quay ve menu...");
        getchar(); getchar();
        return;
    }

    double soGio = gioKetThuc - gioBatDau;
    double tienPhaiTra;

    // 3 gio dau 150000, tu gio thu 4 tang 30%
    if (soGio <= 3) {
        tienPhaiTra = soGio * 150000;
    } else {
        tienPhaiTra = 3 * 150000 + (soGio - 3) * 150000 * 1.3;
    }

    printf("So tien can thanh toan: %.0f VND\n", tienPhaiTra);
    printf("\nNhan Enter de quay ve menu...");
    getchar(); getchar();
}

// ==================== CHUC NANG 4 ====================
void chuc_nang_4() {
    double soKwh;
    printf("\n=== Chuc nang 4: Tinh tien dien ===\n");
    printf("Nhap so kWh su dung: ");
    if (scanf("%lf", &soKwh) != 1) {
        printf("Nhap sai!\n");
        while(getchar() != '\n');
        printf("\nNhan Enter de quay ve menu...");
        getchar();
        return;
    }

    if (soKwh < 0) {
        printf("So kWh khong hop le!\n");
        printf("\nNhan Enter de quay ve menu...");
        getchar(); getchar();
        return;
    }

    double tien = 0;
    double conLai = soKwh;

    // bac 1: 0-50
    if (conLai > 0) {
        double bac1 = (conLai > 50) ? 50 : conLai;
        tien = tien + bac1 * 1678;
        conLai = conLai - bac1;
    }
    // bac 2: 51-100
    if (conLai > 0) {
        double bac2 = (conLai > 50) ? 50 : conLai;
        tien = tien + bac2 * 1734;
        conLai = conLai - bac2;
    }
    // bac 3: 101-200
    if (conLai > 0) {
        double bac3 = (conLai > 100) ? 100 : conLai;
        tien = tien + bac3 * 2014;
        conLai = conLai - bac3;
    }
    // bac 4: 201-300
    if (conLai > 0) {
        double bac4 = (conLai > 100) ? 100 : conLai;
        tien = tien + bac4 * 2536;
        conLai = conLai - bac4;
    }
    // bac 5: 301-400
    if (conLai > 0) {
        double bac5 = (conLai > 100) ? 100 : conLai;
        tien = tien + bac5 * 2834;
        conLai = conLai - bac5;
    }
    // bac 6: tren 400
    if (conLai > 0) {
        tien = tien + conLai * 2927;
    }

    printf("So tien phai tra: %.0f VND\n", tien);
    printf("\nNhan Enter de quay ve menu...");
    getchar(); getchar();
}

// ==================== CHUC NANG 5 ====================
void chuc_nang_5() {
    int soTien;
    int menhGia[9] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    printf("\n=== Chuc nang 5: Doi tien ===\n");
    printf("Nhap so tien can doi: ");
    if (scanf("%d", &soTien) != 1) {
        printf("Nhap sai!\n");
        while(getchar() != '\n');
        printf("\nNhan Enter de quay ve menu...");
        getchar();
        return;
    }

    if (soTien <= 0) {
        printf("So tien khong hop le!\n");
        printf("\nNhan Enter de quay ve menu...");
        getchar(); getchar();
        return;
    }

    printf("Doi %d thanh:\n", soTien);
    for (int i = 0; i < 9; i++) {
        int soTo = soTien / menhGia[i];
        if (soTo > 0) {
            printf("  %d to %d\n", soTo, menhGia[i]);
            soTien = soTien % menhGia[i];
        }
    }
    printf("\nNhan Enter de quay ve menu...");
    getchar(); getchar();
}

// ==================== CHUC NANG 6 ====================
void chuc_nang_6() {
    double tienVay;
    printf("\n=== Chuc nang 6: Tinh lai suat vay tra gop ===\n");
    printf("Nhap so tien muon vay (VND): ");
    if (scanf("%lf", &tienVay) != 1) {
        printf("Nhap sai!\n");
        while(getchar() != '\n');
        printf("\nNhan Enter de quay ve menu...");
        getchar();
        return;
    }

    double laiSuat = 0.05; // 5% moi thang
    int kyHan = 12;
    double gocMoiThang = tienVay / kyHan;

    printf("\n%-8s%-15s%-15s%-18s%s\n", "Ky han", "Lai phai tra", "Goc phai tra", "So tien phai tra", "So tien con lai");
    printf("----------------------------------------------------------------------\n");

    double conLai = tienVay;
    for (int i = 1; i <= kyHan; i++) {
        double lai = conLai * laiSuat;
        double phaiTra = lai + gocMoiThang;
        conLai = conLai - gocMoiThang;
        if (conLai < 0) conLai = 0;

        printf("%-8d%12.0f%15.0f%18.0f%15.0f\n", i, lai, gocMoiThang, phaiTra, conLai);
    }
    printf("\nNhan Enter de quay ve menu...");
    getchar(); getchar();
}

// ==================== CHUC NANG 7 ====================
void chuc_nang_7() {
    double phanTramVay;
    printf("\n=== Chuc nang 7: Vay tien mua xe ===\n");
    printf("Gia xe: 500.000.000 VND\n");
    printf("Thoi han: 24 thang | Lai suat nam: 7.2%%\n");
    printf("Nhap %% vay toi da (vd: 80): ");
    if (scanf("%lf", &phanTramVay) != 1) {
        printf("Nhap sai!\n");
        while(getchar() != '\n');
        printf("\nNhan Enter de quay ve menu...");
        getchar();
        return;
    }

    if (phanTramVay <= 0 || phanTramVay > 100) {
        printf("Phan tram khong hop le!\n");
        printf("\nNhan Enter de quay ve menu...");
        getchar(); getchar();
        return;
    }

    double giaXe = 500000000;
    double tienTraTruoc = giaXe * (100 - phanTramVay) / 100;
    double tienVay = giaXe * phanTramVay / 100;

    double laiThang = 0.072 / 12; // lai suat thang
    int soThang = 24;
    double tienHangThang;

    // cong thuc tra gop deu
    if (laiThang == 0) {
        tienHangThang = tienVay / soThang;
    } else {
        tienHangThang = tienVay * (laiThang * pow(1 + laiThang, soThang)) / (pow(1 + laiThang, soThang) - 1);
    }

    printf("\nSo tien tra truoc: %.0f VND\n", tienTraTruoc);
    printf("So tien phai tra hang thang: %.0f VND\n", tienHangThang);
    printf("Tong tien phai tra: %.0f VND\n", tienHangThang * soThang);

    printf("\nNhan Enter de quay ve menu...");
    getchar(); getchar();
}

// ==================== CHUC NANG 8 ====================
void chuc_nang_8() {
    int n;
    printf("\n=== Chuc nang 8: Sap xep thong tin sinh vien ===\n");
    printf("Nhap so luong sinh vien: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Nhap sai!\n");
        while(getchar() != '\n');
        printf("\nNhan Enter de quay ve menu...");
        getchar();
        return;
    }
    getchar(); // xoa bo dem

    char tenSV[100][50];
    double diemSV[100];

    for (int i = 0; i < n; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("  Ho ten: ");
        fgets(tenSV[i], 50, stdin);
        tenSV[i][strcspn(tenSV[i], "\n")] = 0; // xoa ky tu xuong dong

        printf("  Diem: ");
        if (scanf("%lf", &diemSV[i]) != 1) {
            printf("Diem khong hop le!\n");
            while(getchar() != '\n');
            printf("\nNhan Enter de quay ve menu...");
            getchar();
            return;
        }
        getchar();
    }

    // sap xep giam dan theo diem (noi bot)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (diemSV[i] < diemSV[j]) {
                // doi cho diem
                double tempDiem = diemSV[i];
                diemSV[i] = diemSV[j];
                diemSV[j] = tempDiem;

                // doi cho ten
                char tempTen[50];
                strcpy(tempTen, tenSV[i]);
                strcpy(tenSV[i], tenSV[j]);
                strcpy(tenSV[j], tempTen);
            }
        }
    }

    printf("\n=== DANH SACH SINH VIEN (da sap xep) ===\n");
    printf("%-5s%-25s%-10s%s\n", "STT", "Ho ten", "Diem", "Hoc luc");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        char *hocLuc;
        if (diemSV[i] >= 9.0) hocLuc = "Xuat sac";
        else if (diemSV[i] >= 8.0) hocLuc = "Gioi";
        else if (diemSV[i] >= 6.5) hocLuc = "Kha";
        else if (diemSV[i] >= 5.0) hocLuc = "Trung binh";
        else hocLuc = "Yeu";

        printf("%-5d%-25s%-10.1f%s\n", i + 1, tenSV[i], diemSV[i], hocLuc);
    }
    printf("\nNhan Enter de quay ve menu...");
    getchar();
}

// ==================== CHUC NANG 9 ====================
void chuc_nang_9() {
    int so1, so2;
    printf("\n=== Chuc nang 9: Game FPOLY-LOTT (2/15) ===\n");
    printf("Nhap 2 so tu 01 den 15:\n");
    printf("So thu nhat: ");
    if (scanf("%d", &so1) != 1) {
        printf("Nhap sai!\n");
        while(getchar() != '\n');
        printf("\nNhan Enter de quay ve menu...");
        getchar();
        return;
    }
    printf("So thu hai: ");
    if (scanf("%d", &so2) != 1) {
        printf("Nhap sai!\n");
        while(getchar() != '\n');
        printf("\nNhan Enter de quay ve menu...");
        getchar();
        return;
    }

    // kiem tra hop le
    if (so1 < 1 || so1 > 15 || so2 < 1 || so2 > 15) {
        printf("So phai nam trong khoang 01 - 15!\n");
        printf("\nNhan Enter de quay ve menu...");
        getchar(); getchar();
        return;
    }
    if (so1 == so2) {
        printf("Hai so khong duoc trung nhau!\n");
        printf("\nNhan Enter de quay ve menu...");
        getchar(); getchar();
        return;
    }

    // sinh 2 so ngau nhien tu 1 den 15 (khac nhau)
    srand(time(NULL));
    int random1 = rand() % 15 + 1;
    int random2;
    do {
        random2 = rand() % 15 + 1;
    } while (random2 == random1);

    printf("\nHe thong quay so: %02d - %02d\n", random1, random2);
    printf("Ban chon: %02d - %02d\n", so1, so2);

    // dem so trung
    int soTrung = 0;
    if (so1 == random1 || so1 == random2) soTrung++;
    if (so2 == random1 || so2 == random2) soTrung++;

    // hien thi ket qua
    if (soTrung == 0) {
        printf("Chuc ban may man lan sau!\n");
    } else if (soTrung == 1) {
        printf("Chuc mung ban da trung giai nhi!\n");
    } else {
        printf("Chuc mung ban da trung giai nhat!\n");
    }

    printf("\nNhan Enter de quay ve menu...");
    getchar(); getchar();
}

// ==================== CHUC NANG 10 ====================
void chuc_nang_10() {
    int tu1, mau1, tu2, mau2;
    printf("\n=== Chuc nang 10: Tinh toan phan so ===\n");

    printf("Nhap phan so thu nhat:\n");
    printf("  Tu so: ");
    if (scanf("%d", &tu1) != 1) {
        printf("Nhap sai!\n");
        while(getchar() != '\n');
        printf("\nNhan Enter de quay ve menu...");
        getchar();
        return;
    }
    printf("  Mau so: ");
    if (scanf("%d", &mau1) != 1 || mau1 == 0) {
        printf("Mau so khong hop le (khac 0)!\n");
        while(getchar() != '\n');
        printf("\nNhan Enter de quay ve menu...");
        getchar();
        return;
    }

    printf("Nhap phan so thu hai:\n");
    printf("  Tu so: ");
    if (scanf("%d", &tu2) != 1) {
        printf("Nhap sai!\n");
        while(getchar() != '\n');
        printf("\nNhan Enter de quay ve menu...");
        getchar();
        return;
    }
    printf("  Mau so: ");
    if (scanf("%d", &mau2) != 1 || mau2 == 0) {
        printf("Mau so khong hop le (khac 0)!\n");
        while(getchar() != '\n');
        printf("\nNhan Enter de quay ve menu...");
        getchar();
        return;
    }

    printf("\nPhan so 1: %d/%d\n", tu1, mau1);
    printf("Phan so 2: %d/%d\n", tu2, mau2);

    // tinh tong
    int tuTong = tu1 * mau2 + tu2 * mau1;
    int mauTong = mau1 * mau2;
    printf("Tong: %d/%d\n", tuTong, mauTong);

    // tinh hieu
    int tuHieu = tu1 * mau2 - tu2 * mau1;
    int mauHieu = mau1 * mau2;
    printf("Hieu: %d/%d\n", tuHieu, mauHieu);

    // tinh tich
    int tuTich = tu1 * tu2;
    int mauTich = mau1 * mau2;
    printf("Tich: %d/%d\n", tuTich, mauTich);

    // tinh thuong
    if (tu2 == 0) {
        printf("Thuong: khong the chia cho 0!\n");
    } else {
        int tuThuong = tu1 * mau2;
        int mauThuong = mau1 * tu2;
        printf("Thuong: %d/%d\n", tuThuong, mauThuong);
    }

    printf("\nNhan Enter de quay ve menu...");
    getchar(); getchar();
}