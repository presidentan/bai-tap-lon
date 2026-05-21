#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

NhanVien* docFileInput(int* n) {
    FILE* f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("Loi! Khong the mo tep input.txt de doc.\n");
        *n = 0;
        return NULL;
    }

    NhanVien* ds = NULL;
    int count = 0;

    while (!feof(f)) {
        int temp_mnv;
        if (fscanf(f, "%d\n", &temp_mnv) != 1) {
            break;
        }

        count++;
        ds = (NhanVien*)realloc(ds, count * sizeof(NhanVien));
        ds[count - 1].mnv = temp_mnv;

        fscanf(f, "%[^(](%c)\n", ds[count - 1].hoTen, &ds[count - 1].phong);
        
        int len = strlen(ds[count - 1].hoTen);
        while (len > 0 && (ds[count - 1].hoTen[len - 1] == ' ' || ds[count - 1].hoTen[len - 1] == '\t')) {
            ds[count - 1].hoTen[len - 1] = '\0';
            len--;
        }

        fscanf(f, "%ld\n", &ds[count - 1].luong);
    }

    fclose(f);
    *n = count;
    return ds;
}

void inDanhSach(FILE* stream, NhanVien* ds, int n) {
    fprintf(stream, "\n================= DANH SACH NHAN VIEN =================\n");
    fprintf(stream, "%-7s | %-25s | %-5s | %-12s\n", "MNV", "Ho va Ten", "Phong", "Luong (VND)");
    fprintf(stream, "--------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        fprintf(stream, "%-7d | %-25s | %-5c | %-12ld\n", ds[i].mnv, ds[i].hoTen, ds[i].phong, ds[i].luong);
    }
}

void inLuongCaoNhat(FILE* stream, NhanVien* ds, int n) {
    if (n == 0 || ds == NULL) return;

    long maxLuong = ds[0].luong;
    for (int i = 1; i < n; i++) {
        if (ds[i].luong > maxLuong) {
            maxLuong = ds[i].luong;
        }
    }

    fprintf(stream, "\n============= NHAN VIEN CO LUONG CAO NHAT =============\n");
    fprintf(stream, "Muc luong cao nhat: %ld VND\n", maxLuong);
    fprintf(stream, "%-7s | %-25s | %-5s\n", "MNV", "Ho va Ten", "Phong");
    fprintf(stream, "--------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        if (ds[i].luong == maxLuong) {
            fprintf(stream, "%-7d | %-25s | %-5c\n", ds[i].mnv, ds[i].hoTen, ds[i].phong);
        }
    }
}

void demNhanVienTheoPhong(FILE* stream, NhanVien* ds, int n) {
    int demA = 0, demB = 0, demC = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].phong == 'A' || ds[i].phong == 'a') demA++;
        else if (ds[i].phong == 'B' || ds[i].phong == 'b') demB++;
        else if (ds[i].phong == 'C' || ds[i].phong == 'c') demC++;
    }

    fprintf(stream, "\n================ THONG KE THEO PHONG ================\n");
    fprintf(stream, "So nhan vien phong A: %d\n", demA);
    fprintf(stream, "So nhan vien phong B: %d\n", demB);
    fprintf(stream, "So nhan vien phong C: %d\n", demC);
}

void xuatDuLieu(NhanVien* ds, int n) {
    if (n == 0 || ds == NULL) {
        printf("Khong co du lieu nhan vien de xu ly.\n");
        return;
    }

    printf("\n>>> DANG HIEN THI KET QUA RA MAN HINH <<<\n");
    inDanhSach(stdout, ds, n);
    inLuongCaoNhat(stdout, ds, n);
    demNhanVienTheoPhong(stdout, ds, n);

    FILE* fOut = fopen("output.txt", "w");
    if (fOut == NULL) {
        printf("\nLoi! Khong the tao tep output.txt de luu ket qua.\n");
        return;
    }

    inDanhSach(fOut, ds, n);
    inLuongCaoNhat(fOut, ds, n);
    demNhanVienTheoPhong(fOut, ds, n);

    fclose(fOut);
    printf("\nDa luu toan bo ket qua tren vao tep 'output.txt' thanh cong!\n");
}

void chayChuongTrinh() {
    int n = 0;
    NhanVien* dsNhanVien = docFileInput(&n);
    
    if (dsNhanVien != NULL) {
        xuatDuLieu(dsNhanVien, n);
        free(dsNhanVien);
    }
}