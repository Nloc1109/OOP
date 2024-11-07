#include "BenhVien.h"

void ConNguoi::Nhap() {
    cin.ignore();
    cout << "\nNhap Ho va Ten: ";
    getline(cin, hoTen);
    do {
        cout << "\nNhap gioi tinh (Nam/Nu): ";
        getline(cin, gioiTinh);
        if (gioiTinh != "Nam" && gioiTinh != "Nu" && gioiTinh != "nam" && gioiTinh != "nu")
            cout << "Gioi tinh khong hop le. Vui long nhap lai (Nam/Nu).\n";
        if (gioiTinh == "nam")
            gioiTinh = "Nam";
        if (gioiTinh == "nu")
            gioiTinh = "Nu";
    } while (gioiTinh != "Nam" && gioiTinh != "Nu" && gioiTinh != "nam" && gioiTinh != "nu");

    cout << "\nNhap ngay sinh (nam/thang/ngay): \n";
    do {
        cout << "Nhap nam: ";
        cin >> namSinh.nam;
        if (namSinh.nam > 2025 || namSinh.nam < 1)
            cout << "Nam khong duoc lon hon 2025 hoac nho hon 1! (1-2025)" << endl;
    } while (namSinh.nam > 2025 || namSinh.nam < 1);

    do {
        cout << "Nhap thang: ";
        cin >> namSinh.thang;
        if (namSinh.thang < 1 || namSinh.thang > 12)
            cout << "Thang chi trong khoang tu (1-12)!" << endl;
    } while (namSinh.thang < 1 || namSinh.thang > 12);

    if (namSinh.thang == 1 || namSinh.thang == 3 || namSinh.thang == 5 || namSinh.thang == 7 ||
        namSinh.thang == 8 || namSinh.thang == 10 || namSinh.thang == 12) {
        do {
            cout << "Nhap ngay: ";
            cin >> namSinh.ngay;
            if (namSinh.ngay < 1 || namSinh.ngay > 31)
                cout << "Thang nay chi co tu (1-31) ngay!" << endl;
        } while (namSinh.ngay < 1 || namSinh.ngay > 31);
    }
    else if (namSinh.thang == 4 || namSinh.thang == 6 || namSinh.thang == 9 || namSinh.thang == 11) {
        do {
            cout << "Nhap ngay: ";
            cin >> namSinh.ngay;
            if (namSinh.ngay < 1 || namSinh.ngay > 30)
                cout << "Thang nay chi co toi da 30 ngay!" << endl;
        } while (namSinh.ngay < 1 || namSinh.ngay > 30);
    }
    else {
        bool isNamNhuan = false;
        if ((namSinh.nam % 4 == 0 && namSinh.nam % 100 != 0) || (namSinh.nam % 400 == 0)) {
            isNamNhuan = true;
        }

        if (isNamNhuan) {
            do {
                cout << "Nhap ngay: ";
                cin >> namSinh.ngay;
                if (namSinh.ngay < 1 || namSinh.ngay > 29)
                    cout << "Thang 2 nam " << namSinh.nam << " chi co toi da 29 ngay!" << endl;
            } while (namSinh.ngay < 1 || namSinh.ngay > 29);
        }
        else {
            do {
                cout << "Nhap ngay: ";
                cin >> namSinh.ngay;
                if (namSinh.ngay < 1 || namSinh.ngay > 28)
                    cout << "Thang 2 nam " << namSinh.nam << " chi co toi da 28 ngay!" << endl;
            } while (namSinh.ngay < 1 || namSinh.ngay > 28);
        }
    }

    cout << "Nhap dia chi thuong tru: ";
    cin.ignore();
    getline(cin, diaChi);
}

void ConNguoi::Hienthithongtin() {
    cout << "Ho va ten: " << hoTen << endl;
    cout << "Gioi tinh: " << gioiTinh << endl;
    cout << "Nam sinh: " << namSinh.ngay << "/" << namSinh.thang << "/" << namSinh.nam << endl;
    cout << "Dia chi: " << diaChi << endl;
}

int BenhNhan::maBN = 1;

// Them ham kiemTraGiuong, themGiuong va xoaGiuong
set<tuple<int, int, int, string>> BenhNhan::danhSachGiuong;

bool BenhNhan::kiemTraGiuong(const PhongNam& phongNam) {
    return danhSachGiuong.find(make_tuple(phongNam.tang, phongNam.phong, phongNam.giuong, phongNam.toa)) != danhSachGiuong.end();
}

void BenhNhan::themGiuong(const PhongNam& phongNam) {
    danhSachGiuong.insert(make_tuple(phongNam.tang, phongNam.phong, phongNam.giuong, phongNam.toa));
}

void BenhNhan::xoaGiuong(const PhongNam& phongNam) {
    tuple<int, int, int, string> key = make_tuple(phongNam.tang, phongNam.phong, phongNam.giuong, phongNam.toa);
    danhSachGiuong.erase(key);
}

void BenhNhan::NhapBN() {
    ConNguoi::Nhap();
    cout << "\nNhap nghe nghiep hien tai cua Benh Nhan: ";
    getline(cin, ngheNghiep);
    int choice;
    do {
        cout << "Chon khoa: \n1. Khoa San\n2. Khoa Tai Mui Hong\n3. Khoa Cap Cuu\n4. Khoa Noi\n5. Khoa Tim Mach\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();
        if (choice < 1 || choice > 5) {
            cout << "Hay chon khoa Benh Nhan phu hop (1-5). Vui long nhap lai! Xin Cam On!\n";
        }
    } while (choice < 1 || choice > 5);
    switch (choice) {
    case 1:
        khoa = "Khoa San";
        cout << "Nhap Can Benh cua Benh Nhan: ";
        getline(cin, canBenh);
        phongNam.toa = "A";
        break;
    case 2:
        khoa = "Khoa Tai Mui Hong";
        cout << "Nhap Can Benh cua Benh Nhan: ";
        getline(cin, canBenh);
        phongNam.toa = "B";
        break;
    case 3:
        khoa = "Khoa Cap Cuu";
        cout << "Nhap Can Benh cua Benh Nhan: ";
        getline(cin, canBenh);
        phongNam.toa = "C";
        break;
    case 4:
        khoa = "Khoa Noi";
        cout << "Nhap Can Benh cua Benh Nhan: ";
        getline(cin, canBenh);
        phongNam.toa = "D";
        break;
    case 5:
        khoa = "Khoa Tim Mach";
        cout << "Nhap Can Benh cua Benh Nhan: ";
        getline(cin, canBenh);
        phongNam.toa = "E";
        break;
    }

    do {
        cout << "Nhap Tang phong nam(1-30): ";
        cin >> phongNam.tang;
        if (phongNam.tang < 1 || phongNam.tang > 30) {
            cout << "So Tang chi trong khoang (1-30). Vui long nhap lai cho hop le! Xin Cam On!\n";
        }
    } while (phongNam.tang < 1 || phongNam.tang > 30);
    do {
        cout << "Nhap Phong Nam(1-60): ";
        cin >> phongNam.phong;
        if (phongNam.phong < 1 || phongNam.phong > 60) {
            cout << "So Phong Nam chi trong khoang (1-60). Vui long nhap lai cho hop le! Xin Cam On!\n";
        }
    } while (phongNam.phong < 1 || phongNam.phong > 60);
    do {
        cout << "Nhap Giuong Nam(1-30): ";
        cin >> phongNam.giuong;
        if (phongNam.giuong < 1 || phongNam.giuong > 30) {
            cout << "So Giuong chi trong khoang (1-30). Vui long nhap lai cho hop le! Xin Cam On!\n";
        }
    } while (phongNam.giuong < 1 || phongNam.giuong > 30);

    //Kiem tra phong nam bi trung lap
    while (this->kiemTraGiuong(phongNam)) {
        cout << "Giuong da duoc su dung, vui long nhap lai thong tin giuong:\n";

        do {
            cout << "Nhap Tang phong nam(1-30): ";
            cin >> phongNam.tang;
            if (phongNam.tang < 1 || phongNam.tang > 30) {
                cout << "So Tang chi trong khoang (1-30). Vui long nhap lai cho hop le! Xin Cam On!\n";
            }
        } while (phongNam.tang < 1 || phongNam.tang > 30);

        do {
            cout << "Nhap Phong Nam(1-60): ";
            cin >> phongNam.phong;
            if (phongNam.phong < 1 || phongNam.phong > 60) {
                cout << "So Phong Nam chi trong khoang (1-60). Vui long nhap lai cho hop le! Xin Cam On!\n";
            }
        } while (phongNam.phong < 1 || phongNam.phong > 60);

        do {
            cout << "Nhap Giuong Nam(1-30): ";
            cin >> phongNam.giuong;
            if (phongNam.giuong < 1 || phongNam.giuong > 30) {
                cout << "So Giuong chi trong khoang (1-30). Vui long nhap lai cho hop le! Xin Cam On!\n";
            }
        } while (phongNam.giuong < 1 || phongNam.giuong > 30);
    }

    themGiuong(phongNam);

    cout << "Nhap vien phi: "; cin >> vienPhi;
}


void BenhNhan::HienthithongtinBN() {
    cout << left << "| " << setw(18) << hoTen
        << "| " << setw(11) << gioiTinh
        << "| " << setw(2) << namSinh.ngay << "/"
        << setw(2) << namSinh.thang << "/"
        << setw(7) << namSinh.nam;
    cout << "| " << setw(18) << diaChi
        << "| " << setw(8) << ms
        << "| " << setw(14) << ngheNghiep
        << "| " << setw(18) << khoa
        << "| " << setw(13) << canBenh
        << "| " << setw(2) << phongNam.giuong << "/"
        << setw(2) << phongNam.phong << "/"
        << setw(2) << phongNam.tang << "/"
        << setw(4) << phongNam.toa
        << "| " << setw(14) << vienPhi << " |";
}

int DoiNgu::maDN = 1;

void DoiNgu::NhapDN() {
    ConNguoi::Nhap();
    int choice;
    do {
        cout << "chon Trinh Do: \n";
        cout << "1. Y Ta\n";
        cout << "2. Dieu Duong\n";
        cout << "3. Bac Si\n";
        cout << "4. Pho Khoa\n";
        cout << "5. Truong Khoa\n";
        cout << "6. Pho Vien Truong\n";
        cout << "7. Vien Truong\n";
        cout << "8. Pho Giam Doc\n";
        cout << "9. Giam Doc\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;
        if (choice < 1 || choice > 9) {
            cout << "Hay lua chon cho phu hop voi Trinh Do (1-9). Vui long nhap lai! Xin Cam On!\n";
        }
    } while (choice < 1 || choice > 9);
    switch (choice) {
    case 1:
        trinhDo = "Y ta";
        luong = 6000;
        break;
    case 2:
        trinhDo = "Dieu Duong";
        luong = 8000;
        break;
    case 3:
        trinhDo = "Bac Si";
        luong = 10000;
        break;
    case 4:
        trinhDo = "Pho Khoa";
        luong = 13000;
        break;
    case 5:
        trinhDo = "Truong Khoa";
        luong = 15000;
        break;
    case 6:
        trinhDo = "Pho Vien Truong";
        luong = 20000;
        break;
    case 7:
        trinhDo = "Vien Truong";
        luong = 25000;
        break;
    case 8:
        trinhDo = "Pho Giam Doc";
        luong = 30000;
        break;
    case 9:
        trinhDo = "Giam Doc";
        luong = 35000;
        break;
    }
    int choice1;
    do {
        cout << "Chon khoa dieu tri: \n1. Khoa San\n2. Khoa Tai Mui Hong\n3. Khoa Cap Cuu\n4. Khoa Noi\n5. Khoa Tim Mach\n";
        cout << "Nhap lua chon: ";
        cin >> choice1;
        if (choice1 < 1 || choice1 > 5) {
            cout << "Hay chon khoa dieu tri phu hop (1-5). Vui long nhap lai! Xin Cam On!\n";
        }
    } while (choice1 < 1 || choice1 > 5);
    switch (choice1) {
    case 1:
        khoaDieuTri = "Khoa San";
        phongKham.toa = "A1";
        break;
    case 2:
        khoaDieuTri = "Khoa Tai Mui Hong";
        phongKham.toa = "B1";
        break;
    case 3:
        khoaDieuTri = "Khoa Cap Cuu";
        phongKham.toa = "C1";
        break;
    case 4:
        khoaDieuTri = "Khoa Noi";
        phongKham.toa = "D1";
        break;
    case 5:
        khoaDieuTri = "Khoa Tim Mach";
        phongKham.toa = "E1";
        break;
    }
    do {
        cout << "Nhap Tang phong nam(1-3): ";
        cin >> phongKham.tang;
        if (phongKham.tang < 1 || phongKham.tang > 3) {
            cout << "So Tang chi trong khoang (1-3). Vui long nhap lai cho hop le! Xin Cam On!\n";
        }
    } while (phongKham.tang < 1 || phongKham.tang > 3);
    do {
        cout << "Nhap Phong Kham(1-60): ";
        cin >> phongKham.phong;
        if (phongKham.phong < 1 || phongKham.phong > 60) {
            cout << "So Phong Kham chi trong khoang (1-60). Vui long nhap lai cho hop le! Xin Cam On!\n";
        }
    } while (phongKham.phong < 1 || phongKham.phong > 60);
    
    int choice2;
    do {
        cout << "Ca lam: \n";
        cout << "1. Ca_Sang\n";
        cout << "2. Ca_Chieu\n";
        cout << "3. Ca_Toi\n";
        cout << "Lua chon ca lam: ";
        cin >> choice2;
        if (choice2 < 1 || choice2 > 3) {
            cout << "Chi co 3 ca trong 1 ngay. Vui Long chon (1-3)! Xin Cam On!\n";
        }
    } while (choice2 < 1 || choice2 > 3);
    switch (choice2) {
    case 1:
        caLam = "Ca_Sang";
        break;
    case 2:
        caLam = "Ca_Chieu";
        break;
    case 3:
        caLam = "Ca_Toi";
        break;
    }
}

void DoiNgu::HienthithongtinDN() {
    cout << left << "| " << setw(20) << hoTen
        << "| " << setw(11) << gioiTinh
        << "| " << setw(2) << namSinh.ngay << "/"
        << setw(2) << namSinh.thang << "/"
        << setw(8) << namSinh.nam;
    cout << "| " << setw(12) << diaChi
        << "| " << setw(9) << ms
        << "| " << setw(19) << trinhDo
        << "| " << setw(19) << khoaDieuTri
        << "| " << setw(7) << luong
        << "| " << setw(19) << caLam
        << "| " << setw(2) << phongKham.phong << "/"
        << setw(2) << phongKham.tang << "/"
        << setw(2) << phongKham.toa << " |";
}

void QLBV::ThemBN() {
    if (countBN < 100) {
        benhNhans[countBN] = new BenhNhan();
        benhNhans[countBN]->NhapBN();
        countBN++;
        cout << "\nThem Benh Nhan thanh cong!" << endl;
    }
    else {
        cout << "\nDa day danh sach Benh Nhan!" << endl;
    }
}

string layTenCuoi(const string& hoTen) {
    // tim khoang trang cuoi cung 
    size_t pos = hoTen.find_last_of(' '); //pos luu vi tri tim thay, npos ko tim thay
    if (pos == string::npos) {	// ko co khoang trang thi tra ve chuoi
        return hoTen;
    }
    return hoTen.substr(pos + 1); // tim thay khoang trang va ki tu dau tien cua chu cuoi
}

void QLBV::sapXephoTen() {
    cout << "Chon danh sach ban muon sap xep theo Ten" << endl;
    cout << "1. Danh sach Benh Nhan" << endl;
    cout << "2. Danh sach Doi Ngu" << endl;
    cout << "Nhap lua chon: ";
    int choice;
    cin >> choice;

    switch (choice) {
    case 1: {
        if (countBN == 0) {
            cout << "Danh sach benh nhan trong. Khong can sap xep!" << endl;
            return;
        }
        if (countBN < 2) {
            cout << "Danh sach co 1 benh nhan. Khong can sap xep!" << endl;
            return;
        }

        for (int i = 0; i < countBN - 1; i++) {
            for (int j = i + 1; j < countBN; j++) {
                if (layTenCuoi(benhNhans[i]->getHoTen()) > layTenCuoi(benhNhans[j]->getHoTen())) {
                    swap(benhNhans[i], benhNhans[j]);
                }
            }
        }
        cout << "+" << string(160, '-') << "+" << endl;
        cout << "|" << string(70, ' ') << "Danh sach benh nhan" << string(71, ' ') << "|" << endl;
        cout << "+" << string(160, '-') << "+" << endl;
        cout << left << setw(20) << "| Ho va Ten"
            << setw(13) << "| Gioi Tinh"
            << setw(15) << "| Nam Sinh"
            << setw(20) << "| Dia Chi"
            << setw(10) << "| Ma So"
            << setw(16) << "| Nghe Nghiep"
            << setw(20) << "| Khoa"
            << setw(15) << "| Can Benh"
            << setw(15) << "| Phong nam"
            << setw(16) << "| Vien Phi" << " |" << endl;
        cout << "+" << string(160, '-') << "+" << endl;
        for (int i = 0; i < countBN; i++) {
            benhNhans[i]->HienthithongtinBN();
            cout << endl;
        }
        cout << "+" << string(160, '-') << "+" << endl;
        break;
    }
    case 2: {
        if (countDN == 0) {
            cout << "Danh sach Bac si trong. Khong can sap xep!" << endl;
            return;
        }
        if (countDN < 2) {
            cout << "Danh sach co 1 bac si. Khong can sap xep!" << endl;
            return;
        }

        for (int i = 0; i < countDN - 1; i++) {
            for (int j = i + 1; j < countDN; j++) {
                if (layTenCuoi(doiNgus[i]->getHoTen()) > layTenCuoi(doiNgus[j]->getHoTen())) {
                    swap(doiNgus[i], doiNgus[j]);
                }
            }
        }
        cout << "+" << string(160, '-') << "+" << endl;
        cout << "|" << string(72, ' ') << "Danh sach bac si" << string(72, ' ') << "|" << endl;
        cout << "+" << string(160, '-') << "+" << endl;
        cout << left << "| " << setw(20) << "Ho va Ten"
            << setw(13) << "| Gioi Tinh"
            << setw(15) << "| Nam Sinh"
            << setw(14) << "| Dia Chi"
            << setw(10) << "| Ma So"
            << setw(20) << "| Trinh Do"
            << setw(20) << "| Khoa Dieu Tri"
            << setw(12) << "| Luong"
            << setw(20) << "| Ca Lam"
            << setw(14) << "| Phong Kham" << " |" << endl;
        cout << "+" << string(160, '-') << "+" << endl;

        for (int i = 0; i < countDN; i++) {
            doiNgus[i]->HienthithongtinDN();
            cout << endl;
        }
        cout << "+" << string(160, '-') << "+" << endl;
        break;
    }
    default:
        cout << "Lua chon khong hop le." << endl;
        break;
    }
}

void QLBV::timKiemTen(string x) {
    int choice;
    cout << "\n1.Tim kiem Benh Nhan" << endl;
    cout << "2.Tim kiem Bac si" << endl;
    cout << "Nhap lua chon: ";
    cin >> choice;
    switch (choice) {
    case 1: {
        if (countBN == 0) {
            cout << "Danh sach dang trong khong the tim kiem!" << endl;
        }
        else {
            bool timThay = false;
            cout << "+" << string(160, '-') << "+" << endl;
            cout << "|" << string(70, ' ') << "Danh sach benh nhan" << string(71, ' ') << "|" << endl;
            cout << "+" << string(160, '-') << "+" << endl;
            cout << left << setw(20) << "| Ho va Ten"
                << setw(13) << "| Gioi Tinh"
                << setw(15) << "| Nam Sinh"
                << setw(20) << "| Dia Chi"
                << setw(10) << "| Ma So"
                << setw(16) << "| Nghe Nghiep"
                << setw(20) << "| Khoa"
                << setw(15) << "| Can Benh"
                << setw(15) << "| Phong nam"
                << setw(16) << "| Vien Phi" << " |" << endl;
            cout << "+" << string(160, '-') << "+" << endl;
            for (int i = 0; i < countBN; i++) {
                if (benhNhans[i]->getHoTen() == x) {
                    benhNhans[i]->HienthithongtinBN();
                    cout << endl;
                    timThay = true;
                }
            }
            if (!timThay) {
                cout << "| khong tim thay Ten ban muon tim kiem!" << string(122, ' ') << "|" << endl;
                cout << "+" << string(160, '-') << "+" << endl;
            }
            else {
                cout << "+" << string(160, '-') << "+" << endl;
            }
        }
        break;
    }
    case 2: {
        if (countDN == 0) {
            cout << "Danh sach dang trong khong the tim kiem!" << endl;
        }
        else {
            bool timThay = false;
            cout << "+" << string(160, '-') << "+" << endl;
            cout << "|" << string(72, ' ') << "Danh sach bac si" << string(72, ' ') << "|" << endl;
            cout << "+" << string(160, '-') << "+" << endl;
            cout << left << "| " << setw(20) << "Ho va Ten"
                << setw(13) << "| Gioi Tinh"
                << setw(15) << "| Nam Sinh"
                << setw(14) << "| Dia Chi"
                << setw(10) << "| Ma So"
                << setw(20) << "| Trinh Do"
                << setw(20) << "| Khoa Dieu Tri"
                << setw(12) << "| Luong"
                << setw(20) << "| Ca Lam"
                << setw(14) << "| Phong Kham" << " |" << endl;
            cout << "+" << string(160, '-') << "+" << endl;

            for (int i = 0; i < countDN; i++) {
                if (doiNgus[i]->getHoTen() == x) {
                    doiNgus[i]->HienthithongtinDN();
                    cout << endl;
                    timThay = true;
                }
            }
            if (!timThay) {
                cout << "| khong tim thay Ten ban muon tim kiem!" << string(122, ' ') << "|" << endl;
                cout << "+" << string(160, '-') << "+" << endl;
            }
            else {
                cout << "+" << string(160, '-') << "+" << endl;
            }
        }
        break;
    }
    }
}
void QLBV::ThemDN() {
    if (countDN < 100) {
        doiNgus[countDN] = new DoiNgu();
        doiNgus[countDN]->NhapDN();
        countDN++;
        cout << "Them Doi Ngu thanh cong!" << endl;
    }
    else {
        cout << "Da day danh sach Doi Ngu!" << endl;
    }
}

void QLBV::XuatDS() {
    int dem = 0;
    int choice;
    cout << "Xuat danh sach:\n1. Danh sach Benh Nhan\n2. Danh sach Doi Ngu\n3. Cac danh sach\n";
    cout << "Nhap lua chon: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        cout << "+" << string(160, '-') << "+" << endl;
        cout << "|" << string(70, ' ') << "Danh sach benh nhan" << string(71, ' ') << "|" << endl;
        cout << "+" << string(160, '-') << "+" << endl;
        cout << left << setw(20) << "| Ho va Ten"
            << setw(13) << "| Gioi Tinh"
            << setw(15) << "| Nam Sinh"
            << setw(20) << "| Dia Chi"
            << setw(10) << "| Ma So"
            << setw(16) << "| Nghe Nghiep"
            << setw(20) << "| Khoa"
            << setw(15) << "| Can Benh"
            << setw(15) << "| Phong nam"
            << setw(16) << "| Vien Phi" << " |" << endl;
        cout << "+" << string(160, '-') << "+" << endl;

        for (int i = 0; i < countBN; i++) {
            benhNhans[i]->HienthithongtinBN();
            cout << endl;
            dem++;
        }
        if (dem != 0) {
            cout << "+" << string(160, '-') << "+" << endl;
        }
        cout << "| Tong so luong benh Nhan: " << dem << string(133, ' ') << "|" << endl;
        cout << "+" << string(160, '-') << "+" << endl;
        break;
    }
    case 2: {
        cout << "+" << string(160, '-') << "+" << endl;
        cout << "|" << string(72, ' ') << "Danh sach bac si" << string(72, ' ') << "|" << endl;
        cout << "+" << string(160, '-') << "+" << endl;
        cout << left << "| " << setw(20) << "Ho va Ten"
            << setw(13) << "| Gioi Tinh"
            << setw(15) << "| Nam Sinh"
            << setw(14) << "| Dia Chi"
            << setw(10) << "| Ma So"
            << setw(20) << "| Trinh Do"
            << setw(20) << "| Khoa Dieu Tri"
            << setw(12) << "| Luong"
            << setw(20) << "| Ca Lam"
            << setw(14) << "| Phong Kham" << " |" << endl;
        cout << "+" << string(160, '-') << "+" << endl;

        for (int i = 0; i < countDN; i++) {
            doiNgus[i]->HienthithongtinDN();
            cout << endl;
            dem++;
        }
        if (dem != 0) {
            cout << "+" << string(160, '-') << "+" << endl;
        }
        cout << "| Tong so luong Bac si: " << dem << string(136, ' ') << "|" << endl;
        cout << "+" << string(160, '-') << "+" << endl;
        break;
    }
    case 3: {
        // danh sach benh nhan
        cout << "+" << string(160, '-') << "+" << endl;
        cout << "|" << string(70, ' ') << "Danh sach benh nhan" << string(71, ' ') << "|" << endl;
        cout << "+" << string(160, '-') << "+" << endl;
        cout << left << setw(20) << "| Ho va Ten"
            << setw(13) << "| Gioi Tinh"
            << setw(15) << "| Nam Sinh"
            << setw(20) << "| Dia Chi"
            << setw(10) << "| Ma So"
            << setw(16) << "| Nghe Nghiep"
            << setw(20) << "| Khoa"
            << setw(15) << "| Can Benh"
            << setw(15) << "| Phong nam"
            << setw(16) << "| Vien Phi" << " |" << endl;
        cout << "+" << string(160, '-') << "+" << endl;

        for (int i = 0; i < countBN; i++) {
            benhNhans[i]->HienthithongtinBN();
            cout << endl;
            dem++;
        }
        if (dem != 0) {
            cout << "+" << string(160, '-') << "+" << endl;
        }
        cout << "| Tong so luong benh Nhan: " << dem << string(133, ' ') << "|" << endl;
        cout << "+" << string(160, '-') << "+" << endl;

        // danh sach bac si
        cout << "+" << string(160, '-') << "+" << endl;
        cout << "|" << string(72, ' ') << "Danh sach bac si" << string(72, ' ') << "|" << endl;
        cout << "+" << string(160, '-') << "+" << endl;
        cout << left << "| " << setw(20) << "Ho va Ten"
            << setw(13) << "| Gioi Tinh"
            << setw(15) << "| Nam Sinh"
            << setw(14) << "| Dia Chi"
            << setw(10) << "| Ma So"
            << setw(20) << "| Trinh Do"
            << setw(20) << "| Khoa Dieu Tri"
            << setw(12) << "| Luong"
            << setw(20) << "| Ca Lam"
            << setw(14) << "| Phong Kham" << " |" << endl;
        cout << "+" << string(160, '-') << "+" << endl;

        for (int i = 0; i < countDN; i++) {
            doiNgus[i]->HienthithongtinDN();
            cout << endl;
            dem++;
        }
        if (dem != 0) {
            cout << "+" << string(160, '-') << "+" << endl;
        }
        cout << "| Tong so luong Bac si: " << dem << string(136, ' ') << "|" << endl;
        cout << "+" << string(160, '-') << "+" << endl;
        break;
    }
    default:
        cout << "Lua chon khong hop le." << endl;
        break;
    }
}

// them ham xoa moi
void QLBV::xoaBenhNhan(string x) {
    if (countBN == 0) {
        cout << "\nDanh sach benh nhan trong. Khong can xoa!" << endl;
        return;
    }
    bool check = false;
    char choice;
    cout << "\nBan co muon xoa benh nhan mang ma so " << x << " khoi danh sach khong(y/n): ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        for (int i = 0; i < countBN; i++) {
            if (benhNhans[i]->getMaSo() == x) {
                benhNhans[i]->xoaGiuong(benhNhans[i]->getPhongNam());
                delete benhNhans[i];
                for (int j = i; j < countBN; j++) {
                    benhNhans[j] = benhNhans[j + 1];
                }
                countBN--;
                check = true;
                cout << "\nDa xoa benh nhan mang ma so " << x << "Khoi danh sach!" << endl;
                return;
            }
        }
    }
    else {
        cout << "\nKhong xoa benh nhan!" << endl;
        return;
    }
    if (!check) {
        cout << "\nKhong tim thay benh nhan mang ma so: " << x << endl;
    }
}

void QLBV::xoaDoiNgu(string x) {
    if (countDN == 0) {
        cout << "\nDanh sach bac si trong. Khong can xoa!" << endl;
        return;
    }
    bool check = false;
    char choice;
    cout << "\nBan co muon xoa bac si mang ma so " << x << " khoi danh sach khong(y/n): ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        for (int i = 0; i < countDN; i++) {
            if (doiNgus[i]->getMaSo() == x) {
                delete doiNgus[i];
                for (int j = i; j < countDN; j++) {
                    doiNgus[j] = doiNgus[j + 1];
                }
                countDN--;
                check = true;
                cout << "\nDa xoa Bac si mang ma so " << x << "Khoi danh sach!" << endl;
                return;
            }
        }
    }
    else {
        cout << "\nKhong xoa bac si!" <<endl;
        return;
    }
    if (!check) {
        cout << "\nKhong tim thay bac si mang ma so: " << x << endl;
    }
}

double QLBV::tongVienPhi() {
    double tongTien = 0;
    if (countBN == 0) {
        return 0;
    }
    for (int i = 0; i < countBN; i++) {
        tongTien += benhNhans[i]->getVienPhi();
    }
    return tongTien;
}

// Quan ly Kho thuoc

int Thuoc::ma = 1;

void Thuoc::nhapThuoc() {
    cin.ignore();
    cout << "\nNhap ten thuoc: ";
    getline(cin, tenThuoc);
    cout << "Nhap so luong: ";
    cin >> soLuong;
    cout << "Nhap don gia: ";
    cin >> donGia;
}

void Thuoc::hienThiThongTinThuoc() {
    cout << left << "| " << setw(20) << tenThuoc
        << "| " << setw(10) << maThuoc
        << "| " << setw(10) << soLuong
        << "| " << setw(10) << donGia 
        << "| " << setw(18) << soLuongBan << " |" << endl;
}

void QLBV::themThuoc() {
    if (countThuoc < 100) {
        Thuoc* thuocMoi = new Thuoc();
        thuocMoi->nhapThuoc();
        for (int i = 0; i < countThuoc; i++) {
            if (thuoc[i]->getTenThuoc() == thuocMoi->getTenThuoc()) {
                int soLuongMoi = thuoc[i]->getSoLuong() + thuocMoi->getSoLuong();
                thuoc[i]->setSoLuong(soLuongMoi);
                cout << "\nThuoc da ton tai, da cap nhat so luong trong kho!" << endl;
                delete thuocMoi;
                return;
            }
        }
        thuoc[countThuoc] = thuocMoi;
        countThuoc++;
        cout << "\nDa them thuoc vao kho!" << endl;
    }
    else {
        cout << "\nKho thuoc da day!" << endl;
    }
}

double QLBV::tinhGiaTriKhoThuoc() {
    double tongTien = 0.0;
    if (countThuoc < 1) {
        return 0;
    }
    else {
        for (int i = 0; i < countThuoc; i++) {
            tongTien += thuoc[i]->getDonGia() * thuoc[i]->getSoLuong();
        }
    }
    return tongTien;
}

void QLBV::xuatDanhSachThuoc() {
    cout << "+" << string(78, '-') << "+" << endl;
    cout << "|" << string(27, ' ') << "Danh sach thuoc sap het" << string(28, ' ') << "|" << endl;
    cout << "+" << string(78, '-') << "+" << endl;
    cout << left << setw(22) << "| Ten thuoc"
        << setw(12) << "| Ma thuoc"
        << setw(12) << "| So luong"
        << setw(12) << "| Don gia"
        << setw(20) << "| So Luong Da Ban" << " |" << endl;
    cout << "+" << string(78, '-') << "+" << endl;
    for (int i = 0; i < countThuoc; i++) {
        thuoc[i]->hienThiThongTinThuoc();
    }
    cout << "+" << string(78, '-') << "+" << endl;
    cout << "| Tong gia tri kho thuoc: " << string(39, ' ') << left << setw(14) << tinhGiaTriKhoThuoc() << "|" << endl;
    cout << "+" << string(78, '-') << "+" << endl;
}

void QLBV::timThuoc(string ten) {
    if (countThuoc == 0) {
        cout << "\nKho thuoc dang rong!" << endl;
        return;
    }
    else {
        for (int i = 0; i < countThuoc; i++) {
            if (ten == thuoc[i]->getTenThuoc()) {
                cout << "+" << string(78, '-') << "+" << endl;
                cout << "|" << string(27, ' ') << "Danh sach thuoc sap het" << string(28, ' ') << "|" << endl;
                cout << "+" << string(78, '-') << "+" << endl;
                cout << left << setw(22) << "| Ten thuoc"
                    << setw(12) << "| Ma thuoc"
                    << setw(12) << "| So luong"
                    << setw(12) << "| Don gia"
                    << setw(20) << "| So Luong Da Ban" << " |" << endl;
                cout << "+" << string(78, '-') << "+" << endl;
                thuoc[i]->hienThiThongTinThuoc();
                cout << "+" << string(78, '-') << "+" << endl;
                return;
            }
        }
    }
    cout << "\nKhong tim thay thuoc can tim!" << endl;
}

void QLBV::hienThiThuocSapHet() {
    bool check = false;
    cout << "+" << string(78, '-') << "+" << endl;
    cout << "|" << string(27, ' ') << "Danh sach thuoc sap het" << string(28, ' ') << "|" << endl;
    cout << "+" << string(78, '-') << "+" << endl;
    cout << left << setw(22) << "| Ten thuoc"
        << setw(12) << "| Ma thuoc"
        << setw(12) << "| So luong"
        << setw(12) << "| Don gia"
        << setw(20) << "| So Luong Da Ban" << " |" << endl;
    cout << "+" << string(78, '-') << "+" << endl;
    for (int i = 0; i < countThuoc; i++) {
        if (thuoc[i]->getSoLuong() < 50) {
            thuoc[i]->hienThiThongTinThuoc();
            check = true;
        }
    }
    if (countThuoc == 0) {
        cout << "| Kho Thuoc Rong!" << string(62, ' ') << "|" << endl;
        cout << "+" << string(78, '-') << "+" << endl;
        cout << "| Kien nghi: Nhap them thuoc vao kho!" << string(42, ' ') << "|" << endl;
        cout << "+" << string(78, '-') << "+" << endl;
        return;
    }
    if (!check) {
        cout << "| Danh Sach Rong!" << string(62, ' ') << "|" << endl;
        cout << "+" << string(78, '-') << "+" << endl;
        cout << "| Kien nghi: Khong co kien nghi!" << string(47, ' ') << "|" << endl;
        cout << "+" << string(78, '-') << "+" << endl;
    }
    else {
        cout << "+" << string(78, '-') << "+" << endl;
        cout << "| Kien nghi: Nhap them thuoc vao kho!" << string(42, ' ') << "|" << endl;
        cout << "+" << string(78, '-') << "+" << endl;
    }
}

void QLBV::nhapLuongThuocDaBan() {
    string ten;
    int soLuongDaBan;
    bool check = false;
    cin.ignore();
    cout << "\nNhap ten thuoc can ban: ";
    getline(cin, ten);
    cout << "Nhap so luong ban: ";
    cin >> soLuongDaBan;
    for (int i = 0; i < countThuoc; i++) {
        if (thuoc[i]->getTenThuoc() == ten) {
            check = true;
            if (thuoc[i]->getSoLuong() < soLuongDaBan) {
                cout << "Nhap so Lieu khong dung. Moi nhap lai so luong ban: ";
                do {
                    cin >> soLuongDaBan;
                    if (thuoc[i]->getSoLuong() < soLuongDaBan) {
                        cout << "Nhap so Lieu khong dung. Moi nhap lai so luong ban: ";
                    }
                } while (thuoc[i]->getSoLuong() > soLuongDaBan);
            }
            int soLuongBanMoi = thuoc[i]->getSoLuongBan() + soLuongDaBan;
            int soluongMoi = thuoc[i]->getSoLuong() - soLuongDaBan;
            thuoc[i]->setSoLuongBan(soLuongBanMoi);
            thuoc[i]->setSoLuong(soluongMoi);
        }
    }
    if (!check) {
        cout << "Thuoc " << ten << " khong co trong kho!" << endl;
    }
    else {
        cout << BLUE << "Thanh cong!" << RESET << endl;
    }
}

double QLBV::doanhThuKhoThuoc() {
    double tongTien = 0;
    if (countThuoc == 0) {
        return 0;
    }
    for (int i = 0; i < countThuoc; i++) {
        tongTien += thuoc[i]->getDonGia() * thuoc[i]->getSoLuongBan();
    }
    return tongTien;
}


void QLBV::quanLyKhoThuoc() {
    int choice;
    string ten;
    do {
        cout << GREEN;
        cout << "+-------------------------------------+" << endl;
        cout << "|          Quan Ly Kho Thuoc          |" << endl;
        cout << "+-------------------------------------+" << endl;
        cout << "| 1. Nhap them thuoc vao kho          |" << endl;
        cout << "| 2. Hien thi danh sach thuoc         |" << endl;
        cout << "| 3. Tim kiem thuoc trong kho         |" << endl;
        cout << "| 4. Hien thi cac loai thuoc sap het  |" << endl;
        cout << "| 5. Nhap so luong thuoc de ban       |" << endl;
        cout << "| 6. Quay lai trang chinh             |" << endl;
        cout << "+-------------------------------------+" << RESET << endl;
        cout << "Nhap lua chon: ";
        do {
            cin >> choice;
            if (choice < 1 || choice > 6) {
                cout << RED << "Lua chon khong hop le! Moi ban nhap lai(1->5): " << RESET;
            }
        } while (choice < 1 || choice > 6);

        switch (choice) {
        case 1:
            themThuoc();
            system("pause");
            system("CLS");
            break;
        case 2:
            xuatDanhSachThuoc();
            system("pause");
            system("CLS");
            break;
        case 3:
            cin.ignore();
            getline(cin, ten);
            timThuoc(ten);
            system("pause");
            system("CLS");
            break;
        case 4:
            hienThiThuocSapHet();
            system("pause");
            system("CLS");
            break;
        case 5:
            nhapLuongThuocDaBan();
            system("pause");
            system("CLS");
        case 6:
            system("CLS");
            break;
        }

    } while (choice != 5);
}

void QLBV::xuatDoanhThuBenhVien() {
    double tongTien = tongVienPhi() + doanhThuKhoThuoc();
    cout << "+" << string(58, '-') << "+" << endl;
    cout << "|" << string(19, ' ') << "Doanh thu benh vien" << string(20, ' ') << "|" << endl;
    cout << "+" << string(58, '-') << "+" << endl;
    cout << left << setw(43) << "| Vien phi: " << setw(15) << tongVienPhi() << " |" << endl;
    cout << "+" << string(58, '-') << "+" << endl;
    cout << left << setw(43) << "| Doanh thu kho thuoc: " << setw(15) << doanhThuKhoThuoc() << " |" << endl;
    cout << "+" << string(58, '-') << "+" << endl;
    cout << left << setw(43) << "| Tong : " << setw(15) << tongTien << " |" << endl;
    cout << "+" << string(58, '-') << "+" << endl;
}