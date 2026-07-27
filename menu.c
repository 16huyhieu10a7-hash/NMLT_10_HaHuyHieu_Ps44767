#include <stdio.h>
#include <math.h>

void hocLuc();
void giaiPT();
void tienDien();
int main()
{
    int chon;
    do
    {
        printf("+-------------------------------+\n");
        printf("|       MENU CHUONG TRINH LAB 3 |\n");
        printf("+-------------------------------+\n");
        printf("| 0. Thoat chuong trinh.        |\n");
        printf("| 1. Tinh hoc luc sinh vien     |\n");
        printf("| 2. Giai phuong trinh bac 2    |\n");
        printf("| 3. Tinh tien dien             |\n");
        printf("+-------------------------------+\n");
        printf("Ban hay chon chuc nang (0 - 3): ");
        scanf("%d", &chon); // chon :2
        switch (chon)
        {
        case 0:
            printf("Ban da chon chuc nang: 0. Thoat chuong trinh.\n");
            // thêm các lệnh
            break;
        case 1:
            printf("Ban da chon chuc nang: 1. Tinh hoc luc sinh vien.\n");
            hocLuc();
            break;
        case 2:
            printf("Ban da chon chuc nang: 2. Giai phuong trinh bac 2.\n");
            giaiPT();
            break;
        case 3:
            printf("Ban da chon chuc nang: 3. Tinh tien dien.\n");
            tienDien();
            break;
        default:
            printf("Ban phai chon chuc nang 0 - 3\n");
            break;
        }
    } while (chon != 0);

    return 0;
}          
void hocLuc()
{
    float diem;

    printf("Nhap diem (0 - 10): ");
    scanf("%f", &diem);

    if (diem < 0 || diem > 10)
    {
        printf("Diem khong hop le!\n");
    }
    else if (diem >= 9)
    {
        printf("Hoc luc: Xuat sac\n");
    }
    else if (diem >= 8)
    {
        printf("Hoc luc: Gioi\n");
    }
    else if (diem >= 6.5)
    {
        printf("Hoc luc: Kha\n");
    }
    else if (diem >= 5)
    {
        printf("Hoc luc: Trung binh\n");
    }
    else if (diem >= 3.5)
    {
        printf("Hoc luc: Yeu\n");
    }
    else
    {
        printf("Hoc luc: Kem\n");
    }
}
#include <math.h>

void giaiPT()
{
    printf("DA VAO HAM GIAI PT\n");

    float a, b, c;
    float delta, x1, x2;

    printf("Nhap a: ");
    scanf("%f", &a);

    printf("Nhap b: ");
    scanf("%f", &b);

    printf("Nhap c: ");
    scanf("%f", &c);

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                printf("Phuong trinh vo so nghiem\n");
            else
                printf("Phuong trinh vo nghiem\n");
        }
        else
        {
            x1 = -c / b;
            printf("Phuong trinh bac nhat, nghiem x = %.2f\n", x1);
        }
    }
    else
    {
        delta = b * b - 4 * a * c;

        if (delta < 0)
        {
            printf("Phuong trinh vo nghiem\n");
        }
        else if (delta == 0)
        {
            x1 = -b / (2 * a);
            printf("Phuong trinh co nghiem kep x = %.2f\n", x1);
        }
        else
        {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);

            printf("x1 = %.2f\n", x1);
            printf("x2 = %.2f\n", x2);
        }
    }
}
void tienDien()
{
    int soDien;
    float tien;

    printf("Nhap so dien tieu thu: ");
    scanf("%d", &soDien);

    if (soDien <= 50)
    {
        tien = soDien * 1678;
    }
    else if (soDien <= 100)
    {
        tien = 50 * 1678 + (soDien - 50) * 1734;
    }
    else
    {
        tien = 50 * 1678 + 50 * 1734 + (soDien - 100) * 2014;
    }

    printf("Tien dien phai tra: %.0f VND\n", tien);
}