#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>

typedef struct {
    int mnv;
    char hoTen[50];
    char phong;
    long luong;
} NhanVien;

NhanVien* docFileInput(int* n);
void inDanhSach(FILE* stream, NhanVien* ds, int n);
void inLuongCaoNhat(FILE* stream, NhanVien* ds, int n);
void demNhanVienTheoPhong(FILE* stream, NhanVien* ds, int n);
void xuatDuLieu(NhanVien* ds, int n);
void chayChuongTrinh();

#endif