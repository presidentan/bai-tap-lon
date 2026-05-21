typedef struct {
    char tenHang[50];
    int soLuong;
    char loaiHang[30];
} HangHoa;
void nhapDanhSach(HangHoa *ds, int n);
void xuatFileVanBan(char *filename, HangHoa *ds, int n);
int tinhTongSoLuong(HangHoa *ds, int n);
void timKiemTenHang(HangHoa *ds, int n, char *tenTim);
void sapXepVaXuatFileNhiPhan(char *filename, HangHoa *ds, int n);
void ChayChuongTrinh();