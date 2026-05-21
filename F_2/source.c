#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void nhapDanhSach(HangHoa *ds, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nNhập thông tin hàng hóa thứ %d:\n", i + 1);
        
        printf("Tên hàng: ");
        getchar(); 
        scanf("%[^\n]s", ds[i].tenHang);

        printf("Số lượng: ");
        scanf("%d", &ds[i].soLuong);

        printf("Loại hàng: ");
        getchar(); 
        scanf("%[^\n]s", ds[i].loaiHang);
    }
}

void xuatFileVanBan(char *filename, HangHoa *ds, int n) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) return;
    fprintf(f, "%-20s %-10s %-20s\n", "Tên Hàng", "Số Lượng", "Loại Hàng");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%-20s %-10d %-20s\n", ds[i].tenHang, ds[i].soLuong, ds[i].loaiHang);
    }
    fclose(f);
}

int tinhTongSoLuong(HangHoa *ds, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].soLuong;
    }
    return tong;
}

void timKiemTenHang(HangHoa *ds, int n, char *tenTim) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].tenHang, tenTim) == 0) {
            printf("Tìm thấy: %s | SL: %d | Loại: %s\n", 
                    ds[i].tenHang, ds[i].soLuong, ds[i].loaiHang);
            found = 1;
        }
    }
    if (!found) printf("Không tìm thấy hàng hóa: %s\n", tenTim);
}

void sapXepVaXuatFileNhiPhan(char *filename, HangHoa *ds, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(ds[i].tenHang, ds[j].tenHang) > 0) {
                HangHoa temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    FILE *f = fopen(filename, "wb");
    if (f != NULL) {
        fwrite(ds, sizeof(HangHoa), n, f);
        fclose(f);
    }
}

void ChayChuongTrinh() {
    int n;
    printf("Nhập số lượng n: ");
    scanf("%d", &n);

    HangHoa *ds = (HangHoa*)malloc(n * sizeof(HangHoa));
    if (ds == NULL) return;

    nhapDanhSach(ds, n);
    xuatFileVanBan("danhsach.txt", ds, n);

    printf("\nTổng số lượng: %d\n", tinhTongSoLuong(ds, n));

    char tenTim[50];
    printf("\nNhập tên cần tìm: ");
    getchar(); 
    scanf("%[^\n]s", tenTim);
    timKiemTenHang(ds, n, tenTim);

    sapXepVaXuatFileNhiPhan("danhsach.bin", ds, n);

    free(ds);
}