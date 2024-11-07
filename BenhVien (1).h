#pragma once
#include <iostream> 
#include <string>
#include <iomanip>
#include <limits>
#include <sstream>
#include <set>
#include <tuple>
using namespace std;

const string RED = "\033[31m";
const string BLUE = "\033[34m";
const string CYAN = "\033[36m";
const string GREEN = "\033[32m";
const string RESET = "\033[0m";

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

public:
	ConNguoi(string hoTen = "", string gioiTinh = "", NTN namSinh = { 0, 0, 0 }, string diaChi = "") {
		this->hoTen = hoTen;
		this->gioiTinh = gioiTinh;
		this->namSinh = namSinh;
		this->diaChi = diaChi;
	}
	virtual ~ConNguoi() {}
	virtual void Nhap();
	virtual void Hienthithongtin();
	string getHoTen() {
		return hoTen;
	}
};

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
	string ms;
	static int maBN;
	static set<tuple<int, int, int, string>> danhSachGiuong;

public:
	BenhNhan(string hoTen = "", string gioiTinh = "", NTN namSinh = { 0, 0, 0 }, string diaChi = "", string ms = "",
		string ngheNghiep = "", string khoa = "", string canBenh = "", PhongNam phongNam = { 0, 0, 0, "" }, float vienPhi = 0.0)
		: ConNguoi(hoTen, gioiTinh, namSinh, diaChi) {
		this->ngheNghiep = ngheNghiep;
		this->khoa = khoa;
		this->canBenh = canBenh;
		this->phongNam = phongNam;
		this->vienPhi = vienPhi;
		std::stringstream ss;
		ss << maBN;
		this->ms = "BN" + ss.str();
		maBN++;
	}
	void NhapBN();
	void HienthithongtinBN();
	string getMaSo() {
		return ms;
	}
	PhongNam getPhongNam() {
		return phongNam;
	}
	float getVienPhi() const { return vienPhi; }
	bool kiemTraGiuong(const PhongNam& phongNam);
	void themGiuong(const PhongNam& phongNam);
	void xoaGiuong(const PhongNam& phongNam);
};

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
	string ms;
	static int maDN;
public:
	DoiNgu(string hoTen = "", string gioiTinh = "", NTN namSinh = { 0, 0, 0 }, string diaChi = "", string ms = "",
		string trinhDo = "", string khoaDieuTri = "", PhongKham phongKham = { 0, 0, "" }, float luong = 0.0, string caLam = "")
		: ConNguoi(hoTen, gioiTinh, namSinh, diaChi) {
		this->trinhDo = trinhDo;
		this->khoaDieuTri = khoaDieuTri;
		this->phongKham = phongKham;
		this->luong = luong;
		this->caLam = caLam;
		std::stringstream ss;
		ss << maDN;
		this->ms = "DN" + ss.str();
		maDN++;
	}
	void NhapDN();
	void HienthithongtinDN();
	string getMaSo() {
		return ms;
	}
};

class Thuoc {
private:
	string tenThuoc;
	string maThuoc;
	int soLuong;
	float donGia;
	static int ma;
	int soLuongBan;
public:
	Thuoc(string tenThuoc = "", string maThuoc = "", int soLuong = 0, float donGia = 0.0, int soLuongBan = 0) {
		this->tenThuoc = tenThuoc;
		this->maThuoc = maThuoc;
		this->soLuong = soLuong;
		this->soLuongBan = soLuongBan;
		std::stringstream ss;
		ss << ma;
		this->maThuoc = "T" + ss.str();
		ma++;
		this->donGia = donGia;
	}
	string getMaThuoc() const { return maThuoc; }
	string getTenThuoc() const { return tenThuoc; }
	void setSoLuong(int soLuong) { this->soLuong = soLuong; }
	int getSoLuong() const { return soLuong; }
	double getDonGia() const { return donGia; }
	int getSoLuongBan() const { return soLuongBan; }
	void setSoLuongBan(int soLuongBan) { this->soLuongBan = soLuongBan; }
	void nhapThuoc();
	void hienThiThongTinThuoc();

};

class QLBV {
private:
	BenhNhan* benhNhans[100];
	DoiNgu* doiNgus[100];
	Thuoc* thuoc[100];
	int countThuoc;
	int countBN;
	int countDN;
public:
	QLBV() {
		countBN = 0;
		countDN = 0;
		countThuoc = 0;
	}
	void ThemBN();
	void ThemDN();
	void XuatDS();
	void sapXephoTen();
	void timKiemTen(string x);
	void xoaBenhNhan(string x);
	double tongVienPhi();
	void xoaDoiNgu(string x);
	void themThuoc();
	void xuatDanhSachThuoc();
	void timThuoc(string ten);
	double tinhGiaTriKhoThuoc();
	void nhapLuongThuocDaBan();
	void hienThiThuocSapHet();
	double doanhThuKhoThuoc();
	void quanLyKhoThuoc();
	void xuatDoanhThuBenhVien();
};
