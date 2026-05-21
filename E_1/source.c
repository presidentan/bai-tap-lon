#include <stdio.h>
#include <stdlib.h>

int Nhap(float **a) {
    int n;
    printf("Nhap so phan tu n: ");
    scanf("%d", &n);
    *a = (float *)malloc((n + 1) * sizeof(float));
    if (*a == NULL) {
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        printf("a[%d] = ", i);
        scanf("%f", &(*a)[i]);
    }
    return n;
}

int MaxDuong(int n, float *a, float *max) {
    int check = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
            if (check == 0) {
                *max = a[i];
                check = 1;
            } else if (a[i] > *max) {
                *max = a[i];
            }
        }
    }
    return check;
}

int Fibo(int n, float *a) {
    if (n < 3) {
        return 0;
    }
    for (int i = 3; i <= n; i++) {
        if (a[i] != a[i - 1] + a[i - 2]) {
            return 0;
        }
    }
    return 1;
}

int Menu() {
    int chon;
    printf("\n======= MENU =======\n");
    printf("1. Nhap day\n");
    printf("2. Xuat day\n");
    printf("3. Tim max duong\n");
    printf("4. Kiem tra tinh Fibonacci\n");
    printf("5. Thoat\n");
    printf("Lua chon cua ban: ");
    scanf("%d", &chon);
    return chon;
}

void ChayChuongTrinh() {
    float *a = NULL;
    int n = 0;
    int chon;
    float max;

    do {
        chon = Menu();
        switch (chon) {
            case 1:
                if (a != NULL) {
                    free(a);
                    a = NULL;
                }
                n = Nhap(&a);
                break;
            case 2:
                if (a == NULL || n == 0) {
                    printf("Day so trong!\n");
                } else {
                    printf("Day so: ");
                    for (int i = 1; i <= n; i++) {
                        printf("%.2f ", a[i]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                if (a == NULL || n == 0) {
                    printf("Day so trong!\n");
                } else {
                    if (MaxDuong(n, a, &max)) {
                        printf("Gia tri duong lon nhat: %.2f\n", max);
                    } else {
                        printf("Khong co so duong trong day\n");
                    }
                }
                break;
            case 4:
                if (a == NULL || n == 0) {
                    printf("Day so trong!\n");
                } else {
                    if (Fibo(n, a)) {
                        printf("Day so co tinh chat Fibonacci\n");
                    } else {
                        printf("Day so khong co tinh chat Fibonacci\n");
                    }
                }
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (chon != 5);

    if (a != NULL) {
        free(a);
    }
}