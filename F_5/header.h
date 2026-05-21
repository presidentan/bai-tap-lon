typedef struct {
    float x;
    float y;
    float z;
} Diem3D;
void nhapDayDiem(Diem3D** mangDiem, int* n);
void inDayDiem(Diem3D* mangDiem, int n);
void xuatFileVanBan(Diem3D* mangDiem, int n);
void nhapFileVanBan(Diem3D** mangDiem, int* n);
void xuatFileNhiPhan(Diem3D* mangDiem, int n);
void nhapFileNhiPhan(Diem3D** mangDiem, int* n);
void menu();
