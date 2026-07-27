#include <stdio.h>

int main()
{
    int a, b;
    float x;
    while (1 == 1)
    {
        printf("Nhap a,b: ");
        scanf("%d%d", &a, &b);
        if (a == 0)
        {
            printf("Phuong trinh vo nghiem\n");
        }
        else
        {
            x = -(float)b / a;
            printf("Phuong trinh %dx + %d = 0 co nghiem x = %.2f\n", a, b, x); // Phuong trinh ax + b = 0 co nghiem x = ...
        }
    }
    return 0;
}