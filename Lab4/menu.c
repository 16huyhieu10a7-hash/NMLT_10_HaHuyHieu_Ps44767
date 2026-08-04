#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void YeuCau1();
void YeuCau2();
int main()
{
    system("chcp 65001");
    int chon,x;
    // Tạo menu
    do
    {
        printf("+---------------------------------------------------+\n");
        printf("|          MENU CHƯƠNG TRÌNH LAB 4                  |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Tính trung bình tổng các số chia hết cho 2     |\n");
        printf("| 2. Kiểm tra Số nguyên tố                          |\n");
        printf("| 3. Kiểm tra Số chính phương                       |\n");
        printf("| 4. Thoát chương trình                             |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Xin mời chọn chức năng (1-4): ");
        scanf("%d", &chon);
        switch (chon)
        {
        case 1:
            YeuCau1();
            break;
        case 2:
            printf("Ban da chon Kiểm tra Số nguyên tố\n");
            // thế nào là SNT: số có 2 ước là 1 và chính nó
            YeuCau2();
            break;
        case 3:
            printf("Ban da chon Kiểm tra Số chính phương\n");
            //4=2x2 9=3x3 16=4x4 Tìm sqrt(x) có phải là số nguyên hay không?
            printf("Nhap x: ");
            scanf("%d", &x);
            // for (int i = 2; i < x; i++)
            // {
            //     if (i * i == x)
            //     {
            //         printf("Số %d là số chính phương\n", x);
            //         goto ketThuc3;
            //     }
            // }
            if(sqrt(x) == (int)sqrt(x))
                printf("Số %d là số chính phương\n", x);
            else
                printf("Số %d không phải là số chính phương\n", x);
            break;
        case 4:
            printf("Ban da chon Thoát chương trình\n");
            break;
        default:
            printf("Bạn hãy chọn chức năng từ 1-4\n");
            break;
        }
    } while (chon != 4);
    // chon = 1,2,3. chon=4 thoat

    return 0;
}

void YeuCau1()
{
    int min, max, tong, bienDem;
    printf("Ban da chon tính trung bình tổng các số chia hết cho 2\n");
    printf("Nhập hai số min, max: ");
    scanf("%d%d", &min, &max);
    if (min > max)
    {
        int temp = min;
        min = max;
        max = temp;
    }
    tong = 0;
    bienDem = 0;
    for (int i = min; i <= max; i++)
    {
        
        if (i % 2 == 0)
        {
            tong += i;
            bienDem++;
        }
    }
    if (bienDem == 0)
    {
        printf("Khong có số chẵn từ %d đến %d\n", min, max);
    }
    else
    {
        printf("Trung bình cộng các số chẵn từ %d đến %d là: %.2f tong = %d, dem = %d\n", min, max, (float)tong / bienDem, tong, bienDem);
    }
}

void YeuCau2()
{
    int x;
    printf("Nhap x: ");
    scanf("%d", &x);
    if (x < 2)
    {
        printf("Số %d không phải là SNT\n", x);
    }
    else
    {
        for (int i = 2; i < x; i++)
        {
            if (x % i == 0)
            {
                printf("Số %d không phải là SNT\n", x);
                goto ketThuc2;
            }
        }
        printf("Số %d là SNT\n", x);
    }
ketThuc2:
}