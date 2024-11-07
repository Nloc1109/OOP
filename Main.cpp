#include "BenhVien.h"

int main() {
    QLBV qlbv;
    int choice;
    string x;
    string maSoXoa;
    do {
        do {
            cout << CYAN;
            cout << "+-------------------------------------+\n";
            cout << "|          QUAN LY BENH VIEN          |\n";
            cout << "+-------------------------------------+\n";
            cout << "| 1. Them Benh Nhan                   |\n";
            cout << "| 2. Them Doi Ngu                     |\n";
            cout << "| 3. Xuat Danh Sach                   |\n";
            cout << "| 4. Sap xep danh sach theo Ten       |\n";
            cout << "| 5. Tim kiem theo Ten                |\n";
            cout << "| 6. Xoa benh nhan theo ma so         |\n";
            cout << "| 7. Xoa Doi ngu theo ma so           |\n";
            cout << "| 8. Quan ly kho thuoc                |\n";
            cout << "| 9. Hien thi doanh thu benh vien     |\n";
            cout << "| 0. Thoat                            |\n";
            cout << "+-------------------------------------+\n" << RESET;
            cout << "Nhap lua chon: ";
            cin >> choice;
            if (choice < 0 || choice > 9)
                cout << RED << "Lua chon khong hop le. Hay nhap lai!(0->9)\n" << RESET;
        } while (choice < 0 || choice > 9);

        switch (choice) {
        case 1:
            qlbv.ThemBN();
            system("pause");
            system("CLS");
            break;
        case 2:
            qlbv.ThemDN();
            system("pause");
            system("CLS");
            break;
        case 3:
            qlbv.XuatDS();
            system("pause");
            system("CLS");
            break;
        case 4:
            qlbv.sapXephoTen();
            system("pause");
            system("CLS");
            break;
        case 5:
            cout << "Nhap vao ten ban muon tim (Luu y nhap ro ca ho va ten de tim kiem): ";
            cin.ignore();
            getline(cin, x);
            qlbv.timKiemTen(x);
            system("pause");
            system("CLS");
            break;
        case 6:
            cout << "Nhap ma so cua benh nhan can xoa: ";
            cin.ignore();
            getline(cin, maSoXoa);
            qlbv.xoaBenhNhan(maSoXoa);
            system("pause");
            system("CLS");
            break;
        case 7:
            cout << "Nhap ma so cua bac si can xoa: ";
            cin.ignore();
            getline(cin, maSoXoa);
            qlbv.xoaDoiNgu(maSoXoa);
            system("pause");
            system("CLS");
            break;
        case 8:
            system("CLS");
            qlbv.quanLyKhoThuoc();
            break;
        case 9:
            qlbv.xuatDoanhThuBenhVien();
            system("pause");
            system("CLS");
        case 0:
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai!" << endl;
        }
    } while (choice != 0);

    return 0;
}
