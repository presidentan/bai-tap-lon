void nhapDayDiem(Diem3D** mangDiem, int* n) {
    printf("Nhập số lượng điểm n: ");
    scanf("%d", n);
    
    *mangDiem = (Diem3D*)realloc(*mangDiem, (*n) * sizeof(Diem3D));
    if (*mangDiem == NULL && *n > 0) {
        printf("Lỗi cấp phát bộ nhớ!\n");
        return;
    }
    
    for (int i = 0; i < *n; i++) {
        printf("Nhập tọa độ điểm thứ %d (x y z): ", i + 1);
        scanf("%f %f %f", &(*mangDiem)[i].x, &(*mangDiem)[i].y, &(*mangDiem)[i].z);
    }
    printf("Đã nhập thành công dãy %d điểm.\n", *n);
}

void inDayDiem(Diem3D* mangDiem, int n) {
    if (n == 0 || mangDiem == NULL) {
        printf("Dãy điểm hiện đang trống!\n");
        return;
    }
    printf("\n--- Danh sách %d tọa độ hiện tại ---\n", n);
    for (int i = 0; i < n; i++) {
        printf("Điểm %d: (%.2f, %.2f, %.2f)\n", i + 1, mangDiem[i].x, mangDiem[i].y, mangDiem[i].z);
    }
}

void xuatFileVanBan(Diem3D* mangDiem, int n) {
    if (n == 0 || mangDiem == NULL) {
        printf("Mảng trống, không có dữ liệu để ghi vào file!\n");
        return;
    }

    FILE* f = fopen("output.txt", "w");
    if (f == NULL) {
        printf("Lỗi! Không thể tạo hoặc mở file để ghi.\n");
        return;
    }
    
    fprintf(f, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(f, "%.2f %.2f %.2f\n", mangDiem[i].x, mangDiem[i].y, mangDiem[i].z);
    }
    
    fclose(f);
    printf("Đã xuất file văn bản thành công!\n");
}

void nhapFileVanBan(Diem3D** mangDiem, int* n) {    
    FILE* f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("Lỗi! Không thể mở file để đọc.\n");
        return;
    }
    
    if (fscanf(f, "%d", n) != 1) {
        printf("File không đúng cấu trúc!\n");
        fclose(f);
        return;
    }
    
    *mangDiem = (Diem3D*)realloc(*mangDiem, (*n) * sizeof(Diem3D));
    
    for (int i = 0; i < *n; i++) {
        fscanf(f, "%f %f %f", &(*mangDiem)[i].x, &(*mangDiem)[i].y, &(*mangDiem)[i].z);
    }
    
    fclose(f);
    printf("Đã đọc file văn bản thành công. Tìm thấy %d điểm.\n", *n);
}

void xuatFileNhiPhan(Diem3D* mangDiem, int n) {
    if (n == 0 || mangDiem == NULL) {
        printf("Mảng trống, không có dữ liệu để ghi vào file!\n");
        return;
    }
    
    FILE* f = fopen("output.bin", "wb");
    if (f == NULL) {
        printf("Lỗi! Không thể mở file.\n");
        return;
    }
    
    fwrite(&n, sizeof(int), 1, f);
    fwrite(mangDiem, sizeof(Diem3D), n, f);
    
    fclose(f);
    printf("Đã xuất file nhị phân thành công!\n");
}

void nhapFileNhiPhan(Diem3D** mangDiem, int* n) {
    FILE* f = fopen("input.bin", "rb");
    if (f == NULL) {
        printf("Lỗi! Không thể mở file.\n");
        return;
    }
    
    if (fread(n, sizeof(int), 1, f) != 1) {
        printf("Lỗi đọc file hoặc file trống.\n");
        fclose(f);
        return;
    }
    
    *mangDiem = (Diem3D*)realloc(*mangDiem, (*n) * sizeof(Diem3D));
    
    fread(*mangDiem, sizeof(Diem3D), *n, f);
    
    fclose(f);
    printf("Đã đọc file nhị phân thành công. Tìm thấy %d điểm.\n", *n);
}

void menu() {
    Diem3D* mangDiem = NULL;
    int n = 0;              
    int chon;
    
    do {
        printf("\n=================== MENU TỌA ĐỘ 3D ===================\n");
        printf("1. Nhập dãy n tọa độ từ bàn phím\n");
        printf("2. In dãy tọa độ hiện tại ra màn hình\n");
        printf("3. Xuất dãy tọa độ ra file VĂN BẢN (.txt)\n");
        printf("4. Nhập dãy tọa độ từ file VĂN BẢN (.txt)\n");
        printf("5. Xuất dãy tọa độ ra file NHỊ PHÂN (.bin)\n");
        printf("6. Nhập dãy tọa độ từ file NHỊ PHÂN (.bin)\n");
        printf("0. Thoát chương trình\n");
        printf("Chọn chức năng (0-6): ");
        scanf("%d", &chon);
        
        switch (chon) {
            case 1: nhapDayDiem(&mangDiem, &n); break;
            case 2: inDayDiem(mangDiem, n); break;
            case 3: xuatFileVanBan(mangDiem, n); break;
            case 4: nhapFileVanBan(&mangDiem, &n); break;
            case 5: xuatFileNhiPhan(mangDiem, n); break;
            case 6: nhapFileNhiPhan(&mangDiem, &n); break;
            case 0: 
                free(mangDiem);
                printf("Đã giải phóng bộ nhớ. Tạm biệt!\n");
                break;
            default: 
                printf("Lựa chọn không hợp lệ. Vui lòng chọn lại!\n");
        }
    } while (chon != 0);
}
