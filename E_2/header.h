typedef struct {
    char TenSach[100];
    char TacGia[100];
    int NamXuatBan;
} Sach;
void Nhap(int *n, Sach **A);
void Xuat(int n, Sach A[]);
int DemSach(int n, Sach *a);
void ThongKe(int n, Sach *a);
int Menu(); 
void ChayChuongTrinh();