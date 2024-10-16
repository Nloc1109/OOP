#include <iostream>
#include <iomanip> // Thu vi?n d? can ch?nh d?u ra
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <limits> // Ð? xóa các giá tr? nh?p sai

using namespace std;

// L?p B?nh nhân
class BenhNhan {
private:
    string maBN; // Mã b?nh nhân
    string ten;
    int tuoi;
    string diaChi;
    string benh;
    string khoa;
    BenhNhan* next;

public:
    BenhNhan(int ma, string t, int age, string addr, string b, string k) 
        : ten(t), tuoi(age), diaChi(addr), benh(b), khoa(k), next(NULL) {
            std::stringstream ss;
            ss << ma; // Chuy?n d?i s? thành chu?i
            maBN = "BN" + ss.str(); 
        }

    string getMaBN() { return maBN; }
    string getTen() { return ten; }
    int getTuoi() { return tuoi; }
    string getDiaChi() { return diaChi; }
    string getBenh() { return benh; }
    string getKhoa() { return khoa; }
    BenhNhan* getNext() { return next; }
    void setNext(BenhNhan* bn) { next = bn; }

    void hienThiThongTin() {
        cout << left << setw(10) << maBN
             << setw(20) << ten
             << setw(10) << tuoi
             << setw(20) << diaChi
             << setw(15) << khoa
             << setw(20) << benh << endl;
    }
};

// L?p Bác si
class BacSi {
private:
    string maBS; // Mã bác si
    string ten;
    int tuoi;
    string khoa;
    BacSi* next;

public:
    BacSi(int ma, string t, int age, string department) 
        : ten(t), tuoi(age), khoa(department), next(NULL) {
             std::stringstream ss;
            ss << ma; // Chuy?n d?i s? thành chu?i
            maBS = "BS" + ss.str();
        }

    string getMaBS() { return maBS; }
    string getTen() { return ten; }
    int getTuoi() { return tuoi; }
    string getKhoa() { return khoa; }
    BacSi* getNext() { return next; }
    void setNext(BacSi* bs) { next = bs; }

    void hienThiThongTin() {
        cout << left << setw(10) << maBS
             << setw(20) << ten
             << setw(10) << tuoi
             << setw(15) << khoa << endl;
    }
};

// L?p qu?n lý danh sách b?nh nhân
class QuanLyBenhNhan {
private:
    BenhNhan* head;

public:
    QuanLyBenhNhan() : head(NULL) {}

    void themBenhNhan(int ma, string ten, int tuoi, string diaChi, string benh, string khoa) {
        BenhNhan* bn = new BenhNhan(ma, ten, tuoi, diaChi, benh, khoa);
        if (head == NULL) {
            head = bn;
        } else {
            BenhNhan* temp = head;
            while (temp->getNext() != NULL) {
                temp = temp->getNext();
            }
            temp->setNext(bn);
        }
    }

    void hienThiDanhSachBenhNhan() {
        BenhNhan* temp = head;
        // In tiêu d? b?ng
        cout << left << setw(10) << "Ma BN" 
             << setw(20) << "Ten" 
             << setw(10) << "Tuoi" 
             << setw(20) << "Dia Chi" 
             << setw(15) << "Khoa" 
             << setw(20) << "Benh" << endl;
        cout << string(95, '-') << endl;

        while (temp != NULL) {
            temp->hienThiThongTin();
            temp = temp->getNext();
        }
    }
};

// L?p qu?n lý danh sách bác si
class QuanLyBacSi {
private:
    BacSi* head;

public:
    QuanLyBacSi() : head(NULL) {}

    void themBacSi(int ma, string ten, int tuoi, string khoa) {
        BacSi* bs = new BacSi(ma, ten, tuoi, khoa);
        if (head == NULL) {
            head = bs;
        } else {
            BacSi* temp = head;
            while (temp->getNext() != NULL) {
                temp = temp->getNext();
            }
            temp->setNext(bs);
        }
    }

    void hienThiDanhSachBacSi() {
        BacSi* temp = head;
        // In tiêu d? b?ng
        cout << left << setw(10) << "Ma BS" 
             << setw(20) << "Ten" 
             << setw(10) << "Tuoi" 
             << setw(15) << "Khoa" << endl;
        cout << string(55, '-') << endl;

        while (temp != NULL) {
            temp->hienThiThongTin();
            temp = temp->getNext();
        }
    }

    // Ki?m tra khoa có t?n t?i hay không
    bool khoaTonTai(string khoa) {
        BacSi* temp = head;
        while (temp != NULL) {
            if (temp->getKhoa() == khoa) {
                return true;
            }
            temp = temp->getNext();
        }
        return false;
    }
};

int main() {
    QuanLyBenhNhan qlBN;
    QuanLyBacSi qlBS;

    // Thêm danh sách các khoa và bác si m?u
    qlBS.themBacSi(1, "Dr. Le Van C", 40, "Noi khoa");
    qlBS.themBacSi(2, "Dr. Pham Thi D", 35, "Nhi khoa");
    qlBS.themBacSi(3, "Dr. Tran Van E", 50, "Da lieu");
    qlBS.themBacSi(4, "Dr. Nguyen Thi F", 45, "Tim mach");
    qlBS.themBacSi(5, "Dr. Hoang Van G", 38, "Tai mui hong");

	cout << "Cac khoa trong benh vien: \n";
    cout << "1. Noi khoa\n";
    cout << "2. Nhi khoa\n";
    cout << "3. Da lieu\n";
    cout << "4. Tim mach\n";
    cout << "5. Tai mui hong\n";
    int maBN;
    string tenBN, diaChi, benh, khoa;
    int tuoiBN;

    // Nh?p thông tin b?nh nhân t? ngu?i dùng
    cout << "Nhap ma benh nhan: ";
    cin >> maBN;
    cin.ignore();  // Xóa b? ký t? xu?ng dòng sau khi nh?p s?

    do {
        cout << "Nhap ten benh nhan: ";
        getline(cin, tenBN);
        if (tenBN.empty()) {
            cout << "Ten khong duoc de trong. Vui long nhap lai.\n";
        }
    } while (tenBN.empty());

    do {
        cout << "Nhap tuoi benh nhan (0 - 120): ";
        cin >> tuoiBN;
        if (cin.fail() || tuoiBN < 0 || tuoiBN > 120) {
            cout << "Tuoi khong hop le. Vui long nhap lai.\n";
            cin.clear(); // Xóa l?i
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa b? giá tr? không h?p l?
        }
    } while (tuoiBN < 0 || tuoiBN > 120);

    cin.ignore(); // Xóa b? ký t? xu?ng dòng sau khi nh?p s?

    do {
        cout << "Nhap dia chi benh nhan: ";
        getline(cin, diaChi);
        if (diaChi.empty()) {
            cout << "Dia chi khong duoc de trong. Vui long nhap lai.\n";
        }
    } while (diaChi.empty());

    // Cho ngu?i dùng ch?n khoa
    do {
        cout << "Chon khoa (Nhap ten khoa): ";
        getline(cin, khoa);
        if (!qlBS.khoaTonTai(khoa)) {
            cout << "Khoa khong ton tai. Vui long nhap lai.\n";
        }
    } while (!qlBS.khoaTonTai(khoa));

    // Nh?p b?nh c?a b?nh nhân
    cout << "Nhap benh: ";
    getline(cin, benh);

    // Thêm b?nh nhân vào danh sách
    qlBN.themBenhNhan(maBN, tenBN, tuoiBN, diaChi, benh, khoa);

    // Hi?n th? danh sách b?nh nhân và bác si theo d?nh d?ng b?ng
    cout << "\nDanh sach Benh Nhan:" << endl;
    qlBN.hienThiDanhSachBenhNhan();

    cout << "\nDanh sach Bac Si:" << endl;
    qlBS.hienThiDanhSachBacSi();

    return 0;
}
