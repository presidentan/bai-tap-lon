#include <stdio.h>
#include <stdlib.h>

float** capPhat(int n, int m) {
    float **a = (float**)malloc(n * sizeof(float*));
    for (int i = 0; i < n; i++) {
        a[i] = (float*)malloc(m * sizeof(float));
    }
    return a;
}

void giaiPhong(float **a, int n) {
    for (int i = 0; i < n; i++) free(a[i]);
    free(a);
}

void nhapTuBanPhim(float ***a, int *n, int *m) {
    printf("Nhập số dòng n và số cột m: ");
    scanf("%d %d", n, m);
    *a = capPhat(*n, *m);
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &(*a)[i][j]);
        }
    }
}

void nhapTuFileVB(char *filename, float ***a, int *n, int *m) {
    FILE *f = fopen(filename, "r");
    if (!f) { printf("Lỗi mở file!\n"); return; }
    fscanf(f, "%d %d", n, m);
    *a = capPhat(*n, *m);
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            fscanf(f, "%f", &(*a)[i][j]);
        }
    }
    fclose(f);
}

void xuatRaFileVB(char *filename, float **a, int n, int m) {
    FILE *f = fopen(filename, "w");
    fprintf(f, "%d %d\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(f, "%.2f ", a[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
    printf("Đã xuất ra file văn bản: %s\n", filename);
}

void ghiRaFileNP(char *filename, float **a, int n, int m) {
    FILE *f = fopen(filename, "wb");
    fwrite(&n, sizeof(int), 1, f);
    fwrite(&m, sizeof(int), 1, f);
    for (int i = 0; i < n; i++) {
        fwrite(a[i], sizeof(float), m, f);
    }
    fclose(f);
    printf("Đã ghi ra file nhị phân: %s\n", filename);
}

void docTuFileNP(char *filename, float ***a, int *n, int *m) {
    FILE *f = fopen(filename, "rb");
    if (!f) { printf("Lỗi mở file nhị phân!\n"); return; }
    fread(n, sizeof(int), 1, f);
    fread(m, sizeof(int), 1, f);
    *a = capPhat(*n, *m);
    for (int i = 0; i < *n; i++) {
        fread((*a)[i], sizeof(float), *m, f);
    }
    fclose(f);
    printf("Đã đọc từ file nhị phân thành công.\n");
}

void inMaTran(float **a, int n, int m) {
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) printf("%.2f\t", a[i][j]);
        printf("\n");
    }
}

void ChayChuongTrinh() {
    float **A = NULL;
    int n, m;

    nhapTuBanPhim(&A, &n, &m);
    nhapTuFileVB("matran.inp", &A, &n, &m);
    xuatRaFileVB("matran.txt", A, n, m);
    ghiRaFileNP("matran.bin", A, n, m);
    giaiPhong(A, n);

    float **B = NULL;
    int r, c;
    docTuFileNP("matran.bin", &B, &r, &c);
    printf("\nMa trận đọc từ file nhị phân:\n");
    inMaTran(B, r, c);
    
    giaiPhong(B, r);
}

