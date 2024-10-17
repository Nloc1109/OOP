#include <iostream> 
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

struct NTN {
    int ngay;
    int thang;
    int nam;
};

class ConNguoi {
protected:
    string hoTen;
    string gioiTinh;
    NTN namSinh;
    string diaChi;
    string ms;

public:
    ConNguoi(string hoTen = "", string gioiTinh = "", NTN namSinh = {0, 0, 0	}, string diaChi = "", string ms = "") {
        this->hoTen = hoTen;
        this->gioiTinh = gioiTinh;
        this->namSinh = namSinh;
        this->diaChi = diaChi;
        this->ms = ms;
    }
    virtual ~ConNguoi() {}
    virtual void Nhap();
    virtual void Hienthithongtin();
};

void ConNguoi::Nhap() {
    fflush(stdin); 
    cout << "Nhap Ho va Ten: ";
    getline(cin, hoTen); 
    do {
        cout << "\nNhap gioi tinh (Nam/Nu): ";
        getline(cin, gioiTinh);
        if (gioiTinh != "Nam" && gioiTinh != "Nu" &&  gioiTinh != "nam" && gioiTinh != "nu")
            cout << "Gioi tinh khong hop le. Vui long nhap lai (Nam/Nu).\n";
		if(gioiTinh == "nam")
			gioiTinh = "Nam";
		if(gioiTinh == "nu")
			gioiTinh = "Nu";
    } while (gioiTinh != "Nam" && gioiTinh != "Nu" &&  gioiTinh != "nam" && gioiTinh != "nu");

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
    } else if (namSinh.thang == 4 || namSinh.thang == 6 || namSinh.thang == 9 || namSinh.thang == 11) {
        do {
            cout << "Nhap ngay: ";
            cin >> namSinh.ngay;
            if (namSinh.ngay < 1 || namSinh.ngay > 30)
                cout << "Thang nay chi co toi da 30 ngay!" << endl;
        } while (namSinh.ngay < 1 || namSinh.ngay > 30);
    } else {
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
        } else {
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

    int loaiMS;
    do {
        cout << "Chon ma so (1: Benh_Nhan, 2: Doi_Ngu, 3: Hau_Can): ";
        cin >> loaiMS;
        cin.clear(); // Lam sach trang thai loi neu co 
        cin.sync(); // Dong bo hoa bo nho dem 
        if (loaiMS < 1 || loaiMS > 3) {
            cout << "Hay chon cho dung chuc nang (1-3)! Vui long chon lai!\n";
        }
    } while (loaiMS < 1 || loaiMS > 3);

    switch (loaiMS) {
        case 1:
            ms = "BN";
            break;
        case 2:
            ms = "DN";
            break;
        case 3:
            ms = "HC";
            break;  
    }
    cout << "Nhap ma so: ";
    string msThem;
    getline(cin, msThem);
    ms += msThem;
}

void ConNguoi::Hienthithongtin() {
    cout << "Ho va ten: " << hoTen << endl;
    cout << "Gioi tinh: " << gioiTinh << endl;
    cout << "Nam sinh: " << namSinh.ngay << "/" << namSinh.thang << "/" << namSinh.nam << endl;
    cout << "Dia chi: " << diaChi << endl;
    cout << "Ma so: " << ms << endl;
}

struct PhongNam {
    int giuong;
    int phong;
    int tang;
    string toa;
};

class BenhNhan : public ConNguoi {
private:
    string ngheNghiep;
    string khoa;
    string canBenh;
    PhongNam phongNam;
    float vienPhi;

public:
    BenhNhan(string hoTen = "", string gioiTinh = "", NTN namSinh = {0, 0, 0}, string diaChi = "", string ms = "", 
             string ngheNghiep = "", string khoa = "", string canBenh = "", PhongNam phongNam = {0, 0, 0, ""}, float vienPhi = 0.0)
        : ConNguoi(hoTen, gioiTinh, namSinh, diaChi, ms) { 
        this->ngheNghiep = ngheNghiep;
        this->khoa = khoa;
        this->canBenh = canBenh;
        this->phongNam = phongNam;
        this->vienPhi = vienPhi;
    }
    void NhapBN();
    void HienthithongtinBN();
};

void BenhNhan::NhapBN() {
    ConNguoi::Nhap();
    cout << "Nhap nghe nghiep hien tai cua Benh Nhan: "; 
    getline(cin, ngheNghiep);
    int choice;
    do {
        cout << "Chon khoa: \n1. Khoa San\n2. Khoa Tai Mui Hong\n3. Khoa Cap Cuu\n4. Khoa Noi\n5. Khoa Nhi\n";
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
            khoa = "Khoa Nhi";
            cout << "Nhap Can Benh cua Benh Nhan: "; 
            getline(cin, canBenh);
            phongNam.toa = "E";
            break;
    }
    
	do{ 
        cout << "Nhap Tang phong nam(1-30): ";
        cin >> phongNam.tang;
        if(phongNam.tang < 1 || phongNam.tang > 30){
            cout << "So Tang chi trong khoang (1-30). Vui long nhap lai cho hop le! Xin Cam On!\n";
        }
    }while(phongNam.tang < 1 || phongNam.tang > 30);
    do{
        cout << "Nhap Phong Nam(1-60): ";
        cin >> phongNam.phong;
        if(phongNam.phong < 1 || phongNam.phong > 60){
            cout << "So Phong Nam chi trong khoang (1-60). Vui long nhap lai cho hop le! Xin Cam On!\n";
        }
    }while(phongNam.phong < 1 || phongNam.phong > 60);
    do{
        cout << "Nhap Giuong Nam(1-30): ";
        cin >> phongNam.giuong;
        if(phongNam.giuong < 1 || phongNam.giuong > 30){
            cout << "So Giuong chi trong khoang (1-30). Vui long nhap lai cho hop le! Xin Cam On!\n";
        }
    }while(phongNam.giuong < 1 || phongNam.giuong > 30);
    cout<<"Nhap vien phi: ";cin>>vienPhi;
}


void BenhNhan::HienthithongtinBN() {
    cout << left << setw(20) << hoTen 
         << "|" << setw(11) << gioiTinh 
         << "|" <<setw(2) << namSinh.ngay <<"/"
         << setw(2) << namSinh.thang<<"/"
         << setw(8) << namSinh.nam;
    cout << "|" <<setw(19) <<diaChi 
         << "|" <<setw(9) << ms 
         << "|" <<setw(13) << ngheNghiep 
         << "|" <<setw(19) << khoa 
         << "|" <<setw(14) << canBenh 
         << "|" <<setw(2) << phongNam.giuong<<"/"
         << setw(2) << phongNam.phong<<"/"
         << setw(2) << phongNam.tang <<"/"
         << setw(5) << phongNam.toa 
         << "|" <<setw(7) <<vienPhi;
}

struct PhongKham {
    int phong; 
    int tang;
    string toa;
};

class DoiNgu : public ConNguoi {
private:
    string trinhDo;
    string khoaDieuTri;
    PhongKham phongKham;
    float luong;
    string caLam;

public:
    DoiNgu(string hoTen = "", string gioiTinh = "", NTN namSinh = {0, 0, 0}, string diaChi = "", string ms = "", 
           string trinhDo = "", string khoaDieuTri = "", PhongKham phongKham = {0, 0, ""}, float luong = 0.0, string caLam = "")
        : ConNguoi(hoTen, gioiTinh, namSinh, diaChi, ms) { 
        this->trinhDo = trinhDo;
        this->khoaDieuTri = khoaDieuTri;
        this->phongKham = phongKham;
        this->luong = luong;
        this->caLam = caLam;
    }
    void NhapDN();
    void HienthithongtinDN();
};

void DoiNgu::NhapDN() {
    ConNguoi::Nhap();
    int choice;
    do{
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
        if(choice < 1 || choice > 9){
            cout << "Hay lua chon cho phu hop voi Trinh Do (1-9). Vui long nhap lai! Xin Cam On!\n";
        }
    }while(choice < 1 || choice > 9);
    switch(choice){
        case 1:
            trinhDo = "Y ta";
            break;
        case 2:
            trinhDo = "Dieu Duong";
            break;
        case 3:
            trinhDo = "Bac Si";
            break;
        case 4:
            trinhDo = "Pho Khoa";
            break;
        case 5:
            trinhDo = "Truong Khoa";
            break;
        case 6:
            trinhDo = "Pho Vien Truong";
            break;
        case 7:
            trinhDo = "Vien Truong";
            break;
        case 8:
            trinhDo = "Pho Giam Doc";
            break;
        case 9:
            trinhDo = "Giam Doc";
            break;
    }
    int choice1; 
    do{
        cout << "Chon khoa dieu tri: \n1. Khoa San\n2. Khoa Tai Mui Hong\n3. Khoa Cap Cuu\n4. Khoa Noi\n5. Khoa Nhi\n";
        cout << "Nhap lua chon: ";
        cin >> choice1;
        if(choice1 < 1 || choice1 > 5){
            cout << "Hay chon khoa dieu tri phu hop (1-5). Vui long nhap lai! Xin Cam On!\n";
        }
    }while(choice1 < 1 || choice1 > 5);
    switch(choice1){
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
            khoaDieuTri = "Khoa Nhi";
            phongKham.toa = "E1";
            break;
    }
    do{ 
        cout << "Nhap Tang phong nam(1-3): ";
        cin >> phongKham.tang;
        if(phongKham.tang < 1 || phongKham.tang > 3){
            cout << "So Tang chi trong khoang (1-3). Vui long nhap lai cho hop le! Xin Cam On!\n";
        }
    }while(phongKham.tang < 1 || phongKham.tang > 3);
    do{
        cout << "Nhap Phong Kham(1-60): ";
        cin >> phongKham.phong;
        if(phongKham.phong < 1 || phongKham.phong > 60){
            cout << "So Phong Kham chi trong khoang (1-60). Vui long nhap lai cho hop le! Xin Cam On!\n";
        }
    }while(phongKham.phong < 1 || phongKham.phong > 60);
    cout << "Nhap Luong: "; 
    cin >> luong;
    int choice2;
    do{
        cout << "Ca lam: \n";
        cout << "1. Ca_Sang\n";
        cout << "2. Ca_Chieu\n";
        cout << "3. Ca_Toi\n";
        cout << "4. Ca_Sang & Ca_Chieu\n";
        cout << "5. Ca_Sang & Ca_Toi\n";
        cout << "6. Ca_Chieu & Ca_Toi\n";
        cout << "Lua chon ca lam: "; 
        cin >> choice2;
        if(choice2 < 1 || choice2 > 6){
            cout << "Chi co 6 ca trong 1 ngay. Vui Long chon (1-6)! Xin Cam On!\n";
        }
    }while(choice2 < 1 || choice2 > 6);
    switch(choice2){
        case 1:
            caLam = "Ca_Sang";
            break;
        case 2:
            caLam = "Ca_Chieu";
            break;
        case 3:
            caLam = "Ca_Toi";
            break;
        case 4:
            caLam = "Ca_Sang&Ca_Chieu";
            break;
        case 5:
            caLam = "Ca_Sang&Ca_Toi";
            break;
        case 6:
            caLam = "Ca_Chieu&Ca_Toi";
            break;
    }
}

void DoiNgu::HienthithongtinDN() {
    cout << left << setw(20) << hoTen 
         << "|" << setw(11) << gioiTinh 
         << "|" <<setw(2) << namSinh.ngay <<"/"
         << setw(2) << namSinh.thang<<"/"
         << setw(8) << namSinh.nam;
    cout << "|" <<setw(12) <<diaChi 
         << "|" <<setw(9) << ms 
         << "|" <<setw(19) << trinhDo
         << "|" <<setw(19) << khoaDieuTri
         << "|" <<setw(7) << luong
         << "|" <<setw(19) << caLam
         << "|" <<setw(2) << phongKham.phong<<"/"
         << setw(2) << phongKham.tang<<"/"
         << setw(2) << phongKham.toa;
}


class QLBV {
private:
    BenhNhan* benhNhans[100];
    DoiNgu* doiNgus[100];
    int countBN;
    int countDN;

public:
    QLBV() {
        countBN = 0;
        countDN = 0;
    }
    void ThemBN();
    void ThemDN();
    void XuatDS();
};

void QLBV::ThemBN() {
    if (countBN < 100) {
        benhNhans[countBN] = new BenhNhan();
        benhNhans[countBN]->NhapBN();
        countBN++;
        cout << "Them Benh Nhan thanh cong!" << endl;
    } else {
        cout << "Da day danh sach Benh Nhan!" << endl;
    }
}

void QLBV::ThemDN() {
    if (countDN < 100) {
        doiNgus[countDN] = new DoiNgu();
        doiNgus[countDN]->NhapDN();
        countDN++;
        cout << "Them Doi Ngu thanh cong!" << endl;
    } else {
        cout << "Da day danh sach Doi Ngu!" << endl;
    }
}

void QLBV::XuatDS() {
    int choice;
    cout << "Xuat danh sach:\n1. Danh sach Benh Nhan\n2. Danh sach Doi Ngu\n3. Cac danh sach\n";
    cout << "Nhap lua chon: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "\n=== Danh Sach Benh Nhan ===\n";
            cout << left << setw(20) << "Ho va Ten" 
                 << setw(12) << "|Gioi Tinh" 
                 << setw(15) << "|Nam Sinh" 
                 << setw(20) << "|Dia Chi" 
                 << setw(10) << "|Ma So" 
                 << setw(14) << "|Nghe Nghiep" 
                 << setw(20) << "|Khoa" 
                 << setw(15) << "|Can Benh" 
                 << setw(15) << "|Phong nam" 
                 << setw(7) << "|Vien Phi" << endl;
            cout << string(155, '-') << endl;

            for (int i = 0; i < countBN; i++) {
                benhNhans[i]->HienthithongtinBN();
                cout << endl;
            }
            break;
        }
        case 2: {
            cout << "\n=== Danh Sach Doi Ngu ===\n";
            cout << left << setw(20) << "Ho va Ten" 
                 << setw(12) << "|Gioi Tinh" 
                 << setw(15) << "|Nam Sinh" 
                 << setw(13) << "|Dia Chi" 
                 << setw(10) << "|Ma So" 
                 << setw(20) << "|Trinh Do" 
                 << setw(20) << "|Khoa Dieu Tri" 
                 << setw(8) << "|Luong" 
                 << setw(20) << "|Ca Lam"
                 << setw(13) << "|Phong Kham"<<endl;
            cout << string(155, '-') << endl;

            for (int i = 0; i < countDN; i++) {
                doiNgus[i]->HienthithongtinDN();
                cout << endl;
            }
            break;
        }
        case 3: {
            cout << "\n=== Danh Sach Benh Nhan ===\n";
            cout << left << setw(20) << "Ho va Ten" 
                 << setw(12) << "|Gioi Tinh" 
                 << setw(15) << "|Nam Sinh" 
                 << setw(20) << "|Dia Chi" 
                 << setw(10) << "|Ma So" 
                 << setw(14) << "|Nghe Nghiep" 
                 << setw(20) << "|Khoa" 
                 << setw(15) << "|Can Benh" 
                 << setw(15) << "|Phong nam" 
                 << setw(7) << "|Vien Phi" << endl;
            cout << string(155, '-') << endl;

            for (int i = 0; i < countBN; i++) {
                benhNhans[i]->HienthithongtinBN();
                cout << endl;
            }

            cout << "\n=== Danh Sach Doi Ngu ===\n";
            cout << left << setw(20) << "Ho va Ten" 
                 << setw(12) << "|Gioi Tinh" 
                 << setw(15) << "|Nam Sinh" 
                 << setw(13) << "|Dia Chi" 
                 << setw(10) << "|Ma So" 
                 << setw(20) << "|Trinh Do" 
                 << setw(20) << "|Khoa Dieu Tri" 
                 << setw(8) << "|Luong" 
                 << setw(20) << "|Ca Lam"
                 << setw(13) << "|Phong Kham"<<endl;
            cout << string(155, '-') << endl;

            for (int i = 0; i < countDN; i++) {
                doiNgus[i]->HienthithongtinDN();
                cout << endl;
            }
            break;
        }
        default:
            cout << "Lua chon khong hop le." << endl;
            break;
    }
}

int main() {
    QLBV qlbv;
    int choice;
    do {
        cout << "=== Quan Ly Benh Vien ===\n";
        cout << "1. Them Benh Nhan\n";
        cout << "2. Them Doi Ngu\n";
        cout << "3. Xuat Danh Sach\n";
        cout << "4. Thoat\n";
        cout << "Nhap lua chon: ";
        do{
        	cin >> choice;
        	if(choice < 1 || choice > 4)
        		cout << "Chuc nang tu (1->4). Hay nhap lai!\n";
		}while(choice < 1 || choice > 4);

        switch (choice) {
            case 1:
                qlbv.ThemBN();
                break;
            case 2:
                qlbv.ThemDN();
                break;
            case 3:
                qlbv.XuatDS();
                break;
            case 4:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai!" << endl;
        }
    } while (choice != 4);

    return 0;
}

