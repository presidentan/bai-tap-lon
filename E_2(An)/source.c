#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


void Nhap(int *n, Sach **A) {
    printf("Nhap so luong sach n: ");
    scanf("%d", n);
    getchar();
    *A = (Sach *)malloc((*n + 1) * sizeof(Sach));
    for (int i = 1; i <= *n; i++) {
        printf("Sach thu %d:\n", i);
        printf("- Ten sach: ");
        fgets((*A)[i].TenSach, sizeof((*A)[i].TenSach), stdin);
        (*A)[i].TenSach[strcspn((*A)[i].TenSach, "\n")] = 0;
        printf("- Tac gia: ");
        fgets((*A)[i].TacGia, sizeof((*A)[i].TacGia), stdin);
        (*A)[i].TacGia[strcspn((*A)[i].TacGia, "\n")] = 0;
        printf("- Nam xuat ban: ");
        scanf("%d", &(*A)[i].NamXuatBan);
        getchar();
    }
}

void Xuat(int n, Sach A[]) {
    printf("\n%-5s %-30s %-25s %-10s\n", "STT", "Ten Sach", "Tac Gia", "Nam XB");
    for (int i = 1; i <= n; i++) {
        printf("%-5d %-30s %-25s %-10d\n", i, A[i].TenSach, A[i].TacGia, A[i].NamXuatBan);
    }
}

int DemSach(int n, Sach *a) {
    char tg[100];
    int count = 0;
    printf("Nhap ten tac gia can dem: ");
    getchar();
    scanf("%[^\n]s", tg);
    getchar();
    for (int i = 1; i <= n; i++) {
        if (strcmp(a[i].TacGia, tg) == 0) {
            count++;
        }
    }
    return count;
}

void ThongKe(int n, Sach *a) {
    printf("\nThong ke theo nam xuat ban:\n");
    for (int i = 1; i <= n; i++) {
        int counts = 0;
        int processed = 0;
        for (int k = 1; k < i; k++) {
            if (a[i].NamXuatBan == a[k].NamXuatBan) {
                processed = 1;
                break;
            }
        }
        if (!processed) {
            for (int j = 1; j <= n; j++) {
                if (a[i].NamXuatBan == a[j].NamXuatBan) {
                    counts++;
                }
            }
            printf("%d: %d cuon\n", a[i].NamXuatBan, counts);
        }
    }
}

int Menu() {
    int chon;
    printf("\n======= MENU QUAN LY SACH =======\n");
    printf("1. Nhap n cuon sach\n");
    printf("2. Xuat n cuon sach\n");
    printf("3. Dem theo tac gia\n");
    printf("4. Thong ke\n");
    printf("5. Thoat\n");
    printf("Lua chon cua ban [1..5]: ");
    scanf("%d", &chon);
    return chon;
}

void ChayChuongTrinh() {
    Sach *A = NULL;
    int n = 0;
    int chon;
    do {
        chon = Menu();
        switch (chon) {
            case 1:
                if (A != NULL) free(A);
                Nhap(&n, &A);
                break;
            case 2:
                if (A != NULL && n > 0) Xuat(n, A);
                else printf("Danh sach trong!\n");
                break;
            case 3:
                if (A != NULL && n > 0) {
                    int d = DemSach(n, A);
                    printf("So cuon sach cua tac gia do la: %d\n", d);
                } else printf("Danh sach trong!\n");
                break;
            case 4:
                if (A != NULL && n > 0) ThongKe(n, A);
                else printf("Danh sach trong!\n");
                break;
            case 5:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (chon != 5);
    if (A != NULL) free(A);
}