#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

int sttMaSach=0;
int sttMaDocGia=0;

struct Date
{
	int ngay;
	int thang;
	int nam;
	
	void nhap() {
		cout<<"Nhap ngay: "; cin>>ngay;
		cout<<"Nhap thang: "; cin>>thang;
		cout<<"Nhap nam: "; cin>>nam;
	}
	
	void xuat() {
		cout<<"  Ngay xuat ban: "<<ngay<<"/"<<thang<<"/"<<nam<<"\n";
	}
	
	void xuatNgayMuon() {
		cout<<"  Ngay muon: "<<ngay<<"/"<<thang<<"/"<<nam<<"\n";
	}
	
	void xuatNgaySinh() {
		cout<<"  Ngay thang nam sinh: "<<ngay<<"/"<<thang<<"/"<<nam<<"\n";
	}
};


struct Sach
{
	char maSach[10]; 
	char tenSach[50], theLoai[50], tacGia[30];
	Date namXuatBan;
	char tinhTrang[10];
	bool tinhTrangMuon;
	int soLuotMuon=0;
	char tenNguoiMuon[50];
	Date ngayMuon;
	
	void nhapThongTin() {
		sttMaSach++;
		string st = "MS" + to_string(sttMaSach);
		strcpy(maSach,st.c_str());
		cout<<"Nhap ten sach: ";
		fflush(stdin);
		cin.getline(tenSach,50);
		cout<<"Nhap the loai: ";
		cin.getline(theLoai,50);
		cout<<"Nhap tac gia: ";
		cin.getline(tacGia,30);
		
		cout<<"Nhap nam xuat ban:\n";
		namXuatBan.nhap();
		
		cout<<"Nhap tinh trang sach: ";
		fflush(stdin);
		cin.getline(tinhTrang,10);
		tinhTrangMuon=false;
		
	}
	
	void xuat() {
		cout<<" +Ma sach: "<<maSach<<"\n";
		cout<<"  Ten sach: "<<tenSach<<"\n";
		cout<<"  The loai: "<<theLoai<<"\n";
		cout<<"  Tac gia: "<<tacGia<<"\n";	
		namXuatBan.xuat();
		cout<<"  Tinh trang sach: "<<tinhTrang<<"\n";
		cout<<"  Tinh trang muon: ";
		if (tinhTrangMuon) {
			cout<<"Da muon\n";
			cout<<"  Nguoi muon: "<<tenNguoiMuon<<"\n";
			ngayMuon.xuatNgayMuon();
		}
		else {
			cout<<"Chua muon\n";
		}
		cout<<"  So luot muon: "<<soLuotMuon<<"\n";
		cout<<"\n";
	}
};

void xuatDSSach(Sach *dsSach, int slSach) { 
	cout<<"DANH SACH SACH:\n";
	for (int i=0; i<slSach; i++) {
		dsSach[i].xuat();
	}
}

void xoaDSSach(Sach *&dsSach) {
	delete [] dsSach;
}

void themSach(Sach *&dsSach, int &slSach) {
	Sach sachMoi;
	int vt;
	cout<<"Nhap thong tin sach duoc them:\n"; 
	sachMoi.nhapThongTin();
	
	slSach++;
	Sach *dsTam = new Sach[slSach];
	for (int i=0; i<slSach-1; i++) {
		dsTam[i] = dsSach[i];
	}
	dsTam[slSach-1] = sachMoi;
	
	xoaDSSach(dsSach);
	
	dsSach = new Sach[slSach];
	for (int i=0; i<slSach; i++) {
		dsSach[i] = dsTam[i];
	}
	
	delete [] dsTam;
	
	cout<<"\nThem sach thanh cong!\n";
}

int timViTriSachTheoMa(Sach *dsSach, int slSach, char maSachTim[]) {
	for (int i=0; i<slSach; i++)  {
		if (strcmp(dsSach[i].maSach,maSachTim)==0) { 
			return i;
		}
	}
	return -1;
}

int timViTriSachTheoTen(Sach *dsSach, int slSach, char tenSachTim[]) {
	for (int i=0; i<slSach; i++)  {
		if (strcmp(dsSach[i].tenSach,tenSachTim)==0) { 
			return i;
		}
	}
	return -1;
}

void xoaSach(Sach *&dsSach, int &slSach){
	char maSachTim[10];
	cout<<"Nhap ma sach can xoa: "; 
	fflush(stdin);
	cin.getline(maSachTim,10);
	int viTriXoa = timViTriSachTheoMa(dsSach,slSach,maSachTim);
	if (viTriXoa==-1) {
		cout<<"Ma sach khong ton tai.\n";
	}
	else {
		slSach--;
		for (int i=viTriXoa; i<slSach; i++) {
			dsSach[i] = dsSach[i+1];
		}
		cout<<"\nXoa sach thanh cong!\n";
	}
} 

void suaThongTinSach(Sach *&dsSach, int &slSach){
	char maSachTim[10];
	cout<<"Nhap ma sach can sua thong tin: "; 
	fflush(stdin);
	cin.getline(maSachTim,10);
	int viTriSua = timViTriSachTheoMa(dsSach,slSach,maSachTim);
	if (viTriSua==-1) {
		cout<<"Ma sach khong ton tai.\n";
	}
	else {
		cout<<"Nhap thong tin moi cho sach:\n";
		cout<<"Nhap ten sach: ";
		fflush(stdin);
		cin.getline(dsSach[viTriSua].tenSach,50);
		cout<<"Nhap the loai: ";
		cin.getline(dsSach[viTriSua].theLoai,50);
		cout<<"Nhap tac gia: ";
		cin.getline(dsSach[viTriSua].tacGia,30);
		cout<<"Nhap nam xuat ban:\n";
		dsSach[viTriSua].namXuatBan.nhap();
		cout<<"Nhap tinh trang sach: ";
		fflush(stdin);
		cin.getline(dsSach[viTriSua].tinhTrang,10);
		
		cout<<"\nCap nhat thong tin sach thanh cong!\n";
	}
	
}

void timDSSachTheoTacGia(Sach* dsSach, Sach*& dsSachTheoTacGia, int slSach, int &slSachTG)   {
	char tacGiaTim[30];
	cout<<"Nhap tac gia can tim: "; 
	fflush(stdin);
	cin.getline(tacGiaTim,30);
	slSachTG = 0;
	for (int i=0; i<slSach; i++) {
		if (strcmp(dsSach[i].tacGia,tacGiaTim)==0) {
			slSachTG++;
		}
	}
	dsSachTheoTacGia = new Sach[slSachTG];
	int k=0;
	for (int i=0; i<slSach; i++) {
		if (strcmp(dsSach[i].tacGia,tacGiaTim)==0) {
			dsSachTheoTacGia[k] = dsSach[i];
			k++;
		}
	}
}

void sapXepDSSach(Sach* &dsSach, int &slSach) {
	for (int i=0; i<slSach-1; i++) {
		for (int j=i+1; j<slSach; j++) {
			if (strcmp(dsSach[i].maSach,dsSach[j].maSach)>0) {
				Sach tmp = dsSach[i];
				dsSach[i] = dsSach[j];
				dsSach[j] = tmp;
			}
		}
	}
}

struct Docgia
{
	char maDocgia[10];
	char tenDocgia[50];
	Date namSinh;
	Sach dsSachDangMuon[10];
	int slSachDangMuon=0;
	
	void nhapThongTin() {
		sttMaDocGia++;
		string st = "MDG" + to_string(sttMaDocGia);
		strcpy(maDocgia,st.c_str());
		cout<<"Nhap ten doc gia: ";
		fflush(stdin);
		cin.getline(tenDocgia,50);
		
		cout<<"Nhap ngay/thang/nam sinh:\n";
		namSinh.nhap();
		
	}
	
	void xuat() {
		cout<<" +Ma doc gia: "<<maDocgia<<"\n";
		cout<<"  Ten doc gia: "<<tenDocgia<<"\n";	
		namSinh.xuatNgaySinh();
		cout<<"\n";
	}
};

void xuatDSDocgia(Docgia *dsDocgia, int slDocgia) { 
	cout<<"DANH SACH DOC GIA:\n";
	for (int i=0; i<slDocgia; i++) {
		dsDocgia[i].xuat();
	}
	cout<<"\n";
}

void xoaDSDocgia(Docgia *&dsDocgia) {
	delete [] dsDocgia; 
}

void themDocgia(Docgia *&dsDocgia, int &slDocgia) {
	Docgia docgiaMoi;
	cout<<"Nhap thong tin doc gia duoc them:\n"; 
	docgiaMoi.nhapThongTin();
	
	slDocgia++;
	Docgia *dsTam = new Docgia[slDocgia];
	for (int i=0; i<slDocgia-1; i++) {
		dsTam[i] = dsDocgia[i];
	}
	dsTam[slDocgia-1] = docgiaMoi;
	
	xoaDSDocgia(dsDocgia);
	
	dsDocgia = new Docgia[slDocgia];
	
	for (int i=0; i<slDocgia; i++) {
		dsDocgia[i] = dsTam[i];
	}
	delete [] dsTam;
	
	cout<<"\nThem doc gia thanh cong!\n";
}

int timViTriDocgiaTheoMa(Docgia *dsDocgia, int slDocgia, char maDocgiaTim[]) {
	for (int i=0; i<slDocgia; i++)  {
		if (strcmp(dsDocgia[i].maDocgia,maDocgiaTim)==0) { 
			return i;
		}
	}
	return -1;
}

int timViTriDocgiaTheoTen(Docgia *dsDocgia, int slDocgia, char tenDocgiaTim[]) {
	for (int i=0; i<slDocgia; i++)  {
		if (strcmp(dsDocgia[i].tenDocgia,tenDocgiaTim)==0) { 
			return i;
		}
	}
	return -1;
}

void xoaDocgia(Docgia *&dsDocgia, int &slDocgia){
	char maDocgiaTim[10];
	cout<<"Nhap ma doc gia can xoa: "; 
	fflush(stdin);
	cin.getline(maDocgiaTim,10);
	int viTriXoa = timViTriDocgiaTheoMa(dsDocgia,slDocgia,maDocgiaTim);
	if (viTriXoa==-1) {
		cout<<"Ma doc gia khong ton tai.\n";
	}
	else {
		slDocgia--;
		for (int i=viTriXoa; i<slDocgia; i++) {
			dsDocgia[i] = dsDocgia[i+1];
		}
		cout<<"\nXoa doc gia thanh cong!\n";
	}
} 

void suaThongTinDocgia(Docgia *&dsDocgia, int &slDocgia){
	char maDocgiaTim[10];
	cout<<"Nhap ma doc gia can sua thong tin: "; 
	fflush(stdin);
	cin.getline(maDocgiaTim,10);
	int viTriSua = timViTriDocgiaTheoMa(dsDocgia,slDocgia,maDocgiaTim);
	if (viTriSua==-1) {
		cout<<"Ma doc gia khong ton tai.\n";
	}
	else {
		cout<<"Nhap thong tin moi cho doc gia:\n";
		cout<<"Nhap ten doc gia: ";
		fflush(stdin);
		cin.getline(dsDocgia[viTriSua].tenDocgia,50);
		cout<<"Nhap ngay/thang/nam sinh:\n";
		dsDocgia[viTriSua].namSinh.nhap();
		
		cout<<"\nCap nhat thong tin doc gia thanh cong!\n";
	}
}

void sapXepDSDocGia(Docgia* &dsDocGia, int &slDocGia) {
	for (int i=0; i<slDocGia-1; i++) {
		for (int j=i+1; j<slDocGia; j++) {
			if (strcmp(dsDocGia[i].tenDocgia,dsDocGia[j].tenDocgia)>0) {
				Docgia tmp = dsDocGia[i];
				dsDocGia[i] = dsDocGia[j];
				dsDocGia[j] = tmp;
			}
		}
	}
}

void PressAnyKey(){
    cout<<"\n\nBam phim bat ki de tiep tuc....";
    getch();
    system("cls");
}

void timKiemSach(Sach* dsSach, int slSach) {
	int key=0;
	cout<<"********************MENU***************************\n";
    cout<<"**   1.  Tim theo ma sach.                       **\n";
    cout<<"**   2.  Tim theo ten sach.                      **\n";
    cout<<"**   3.  Tim theo ten tac gia.                   **\n";
    cout<<"***************************************************\n";
    cout<<"Nhap lua chon cua ban: ";
    cin>>key;
    while (key<1 || key>3) {
    	cout<<"Chi co lua chon tu 1-3. Moi ban nhap lai: ";
    	cin>>key;
	}
	switch (key) {
		case 1: {
			system("cls");
			char maSachTim[10];
			cout<<"Moi ban nhap ma sach can tim: ";
			fflush(stdin);
			cin.getline(maSachTim,10);
			int vtSach = timViTriSachTheoMa(dsSach,slSach,maSachTim);
			if (vtSach==-1) {
				cout<<"Ma sach tren khong ton tai trong danh sach.\n";
			}
			else {
				cout<<"Thong tin sach can tim:\n";
				dsSach[vtSach].xuat();
			}
			PressAnyKey();
			break;
		}
		case 2: {
			system("cls");
			char tenSachTim[50];
			cout<<"Moi ban nhap ten sach can tim: ";
			fflush(stdin);
			cin.getline(tenSachTim,50);
			int vtSach = timViTriSachTheoTen(dsSach,slSach,tenSachTim);
			if (vtSach==-1) {
				cout<<"Ten sach tren khong ton tai trong danh sach.\n";
			}
			else {
				cout<<"Thong tin sach can tim:\n";
				dsSach[vtSach].xuat();
			}
			PressAnyKey();
			break;
		}
		case 3: {
			system("cls");
			Sach* dsSachTheoTG;
			int slSachTheoTG=0;
			timDSSachTheoTacGia(dsSach,dsSachTheoTG,slSach,slSachTheoTG);
			if (slSachTheoTG==0) {
				cout<<"Tac gia tren khong co trong danh sach.\n";
			}
			else {
				cout<<"Danh sach sach duoc viet boi tac gia tren:\n";
				xuatDSSach(dsSachTheoTG,slSachTheoTG);
			}
			delete [] dsSachTheoTG;
			PressAnyKey();
			break;
		}
	}
}

void timKiemDocGia(Docgia* dsDocGia,int slDocGia) {
	int key=0;
	cout<<"********************MENU***************************\n";
    cout<<"**   1.  Tim theo ma the.                        **\n";
    cout<<"**   2.  Tim theo ten doc gia.                   **\n";
    cout<<"***************************************************\n";
    cout<<"Nhap lua chon cua ban: ";
    cin>>key;
    while (key<1 || key>2) {
    	cout<<"Chi co lua chon tu 1-2. Moi ban nhap lai: ";
    	cin>>key;
	}
	switch (key) {
		case 1: {
			system("cls");
			char maDocGiaTim[10];
			cout<<"Moi ban nhap ma doc gia can tim: ";
			fflush(stdin);
			cin.getline(maDocGiaTim,10);
			int vtDocGia = timViTriDocgiaTheoMa(dsDocGia,slDocGia,maDocGiaTim);
			if (vtDocGia==-1) {
				cout<<"Ma doc gia tren khong ton tai trong danh sach.\n";
			}
			else {
				cout<<"Thong tin doc gia can tim:\n";
				dsDocGia[vtDocGia].xuat();
			}
			PressAnyKey();
			break;
		}
		case 2: {
			system("cls");
			char tenDocGiaTim[50];
			cout<<"Moi ban nhap ten doc gia can tim: ";
			fflush(stdin);
			cin.getline(tenDocGiaTim,50);
			int vtDocGia = timViTriDocgiaTheoTen(dsDocGia,slDocGia,tenDocGiaTim);
			if (vtDocGia==-1) {
				cout<<"Ten doc gia tren khong ton tai trong danh sach.\n";
			}
			else {
				cout<<"Thong tin doc gia can tim:\n";
				dsDocGia[vtDocGia].xuat();
			}
			PressAnyKey();
			break;
		}
	}
}

void muonSach(Sach* &dsSach, int slSach, Docgia* &dsDocGia, int slDocGia) {
	char maThe[10],maSachMuon[10];
	int vtDocGia,vtSach;
	
	cout<<"Nhap ma the doc gia: ";
	fflush(stdin);
	cin.getline(maThe,10);
	vtDocGia = timViTriDocgiaTheoMa(dsDocGia,slDocGia,maThe);
	if (vtDocGia==-1) {
		cout<<"Ma the khong ton tai trong danh sach.\n";
		return;
	}
	
	cout<<"Nhap ma sach muon: ";
	fflush(stdin);
	cin.getline(maSachMuon,10);
	vtSach = timViTriSachTheoMa(dsSach,slSach,maSachMuon);
	if (vtSach==-1) {
		cout<<"Ma sach khong ton tai trong danh sach.\n";
		return;
	}
	if (dsSach[vtSach].tinhTrangMuon==true) {
		cout<<"Sach da duoc muon!!";
		return;
	}
	
	cout<<"Nhap ngay muon:\n";
	dsSach[vtSach].ngayMuon.nhap();
	
	dsSach[vtSach].tinhTrangMuon = true;
	dsSach[vtSach].soLuotMuon++;
	strcpy(dsSach[vtSach].tenNguoiMuon,dsDocGia[vtDocGia].tenDocgia);
	
	dsDocGia[vtDocGia].dsSachDangMuon[dsDocGia[vtDocGia].slSachDangMuon] = dsSach[vtSach];
	dsDocGia[vtDocGia].slSachDangMuon++;
	cout<<"\nMuon sach thanh cong!\n";
}

void traSach(Sach* &dsSach, int slSach, Docgia* &dsDocGia, int slDocGia) {
	char maThe[10],maSachMuon[10];
	int vtDocGia,vtSach;
	
	cout<<"Nhap ma the doc gia: ";
	fflush(stdin);
	cin.getline(maThe,10);
	vtDocGia = timViTriDocgiaTheoMa(dsDocGia,slDocGia,maThe);
	if (vtDocGia==-1) {
		cout<<"Ma the khong ton tai trong danh sach.\n";
		return;
	}
	
	cout<<"Nhap ma sach muon: ";
	fflush(stdin);
	cin.getline(maSachMuon,10);
	vtSach = timViTriSachTheoMa(dsSach,slSach,maSachMuon);
	if (vtSach==-1) {
		cout<<"Ma sach khong ton tai trong danh sach.\n";
		return;
	}
	
	int vt=-1;
	for (int i=0; i<dsDocGia[vtDocGia].slSachDangMuon; i++) {
		if (strcmp(dsDocGia[vtDocGia].dsSachDangMuon[i].maSach,maSachMuon)==0) {
			vt=i;
			break;
		}
	}
	
	if (vt==-1) {
		cout<<"Ma sach khong ton tai trong danh sach cac sach doc gia "
  			<<dsDocGia[vtDocGia].tenDocgia<<" dang muon";
        return;
	}
	
	dsDocGia[vtDocGia].slSachDangMuon--;
	for (int i=0; i<dsDocGia[vtDocGia].slSachDangMuon; i++) {
		dsDocGia[vtDocGia].dsSachDangMuon[i] = dsDocGia[vtDocGia].dsSachDangMuon[i+1];
	}
	dsSach[vtSach].tinhTrangMuon=false;
	
	cout<<"\nTra sach thanh cong!\n";
}

void lietKeDanhSachDangMuon(Docgia* dsDocGia, int slDocGia) {
	char maThe[10];
	int vtDocGia;
	
	cout<<"Nhap ma the doc gia: ";
	fflush(stdin);
	cin.getline(maThe,10);
	vtDocGia = timViTriDocgiaTheoMa(dsDocGia,slDocGia,maThe);
	if (vtDocGia==-1) {
		cout<<"Ma the khong ton tai trong danh sach.\n";
		return;
	}
	
	if (dsDocGia[vtDocGia].slSachDangMuon==0) {
		cout<<"Doc gia chua muon quyen sach nao.\n";
		return;
	}
	
	cout<<"Tong so sach doc gia dang muon: "<<dsDocGia[vtDocGia].slSachDangMuon<<"\n";
	xuatDSSach(dsDocGia[vtDocGia].dsSachDangMuon,dsDocGia[vtDocGia].slSachDangMuon);
	
}

void xuatDSTop10Sach(Sach* dsSach, int slSach) {
	for (int i=0; i<slSach-1; i++) {
		for (int j=i+1; j<slSach; j++) {
			if (dsSach[i].soLuotMuon<dsSach[j].soLuotMuon) {
				Sach tmp = dsSach[i];
				dsSach[i] = dsSach[j];
				dsSach[j] = tmp;
			}
		}
	}
	
	int n = slSach>=10 ? 10 : slSach;
	for (int i=0; i<n; i++) {
		cout<<"Top "<<i+1<<":\n";
		dsSach[i].xuat();
	}
}

void ghiFileSach(Sach* dsSach, int slSach) {
	fstream f;
	f.open("DS_Sach.txt", ios::out | ios::binary);
	f.write((char *)&sttMaSach,sizeof(int));
	f.write((char *)&slSach,sizeof(int));
	f.write((char *)dsSach,sizeof(Sach)*slSach);
	f.close();
}

void docFileSach(Sach* &dsSach, int &slSach) {
	fstream f;
	f.open("DS_Sach.txt", ios::in | ios::binary);
	f.read((char *)&sttMaSach,sizeof(int));
	f.read((char *)&slSach,sizeof(int));
	f.read((char *)dsSach,sizeof(Sach)*slSach);
	f.close();
}

void ghiFileDocGia(Docgia* dsDocGia, int slDocGia) {
	fstream f;
	f.open("DS_DocGia.txt", ios::out | ios::binary);
	f.write((char *) &sttMaDocGia,sizeof(int));
	f.write((char *) &slDocGia,sizeof(int));
	f.write((char *) dsDocGia,sizeof(Docgia)*slDocGia);
	f.close();
}

void docFileDocGia(Docgia* &dsDocGia, int &slDocGia, Sach* dsSach, int slSach) {
	fstream f;
	f.open("DS_DocGia.txt", ios::in | ios::binary);
	f.read((char *) &sttMaDocGia, sizeof(int));
	f.read((char *) &slDocGia, sizeof(int));
	f.read((char *) dsDocGia, sizeof(Docgia)*slDocGia);
	f.close();
}

int main() {
	int slSach=0;
	Sach* dsSach = new Sach[100];
	int slDocGia=0;
	Docgia* dsDocGia = new Docgia[100];
	int key=0;
	
	docFileSach(dsSach,slSach);
	docFileDocGia(dsDocGia,slDocGia,dsSach,slSach);
	
	while (true)
    {
    	system("cls");
        cout<<"\nCHUONG TRINH QUAN LI THU VIEN\n";
        cout<<"********************MENU***************************\n";
        cout<<"**   1.  Them sach.                              **\n";
        cout<<"**   2.  Cap nhat thong tin sach boi ma sach.    **\n";
        cout<<"**   3.  Xoa sach boi Ma sach.                   **\n";
        cout<<"**   4.  Tim kiem sach.                          **\n";
        cout<<"**   5.  Hien thi danh sach sach.                **\n";
        cout<<"**   6.  Sap xep danh sach sach theo ma sach     **\n";
        cout<<"**   7.  Them doc gia.                           **\n";
        cout<<"**   8.  Cap nhat thong tin doc gia boi ma the.  **\n";
        cout<<"**   9.  Xoa doc gia boi ma the.                 **\n";
        cout<<"**   10. Tim kiem doc gia                        **\n";
        cout<<"**   11. Hien thi danh sach doc gia.             **\n";
        cout<<"**   12. Sap xep doc gia theo ten.               **\n";
        cout<<"**   13. Muon sach.                              **\n";
		cout<<"**   14. Tra sach.                               **\n";
		cout<<"**   15. Liet ke DS cac sach doc gia dang muon.  **\n";
		cout<<"**   16. Xuat top 10 sach duoc muon nhieu nhat.  **\n";
		cout<<"**   0.  Thoat.                                  **\n";
        cout<<"***************************************************\n";
        cout<<"\tNhap lua chon cua ban: ";
        cin>>key;
        switch (key)
        {
        case 1: {
        	system("cls");
        	cout<<"1. Them sach.\n";
        	themSach(dsSach,slSach);
        	ghiFileSach(dsSach,slSach);
        	PressAnyKey();
			break;
		}
        case 2:{
        	system("cls");
        	if (slSach==0) {
				cout<<"Danh sach sach trong!";
				PressAnyKey();
				break;
			}
        	cout<<"2. Cap nhat thong tin sach boi ma sach.\n";
        	suaThongTinSach(dsSach,slSach);
        	ghiFileSach(dsSach,slSach);
        	PressAnyKey();
			break;
		}
        case 3:{
        	system("cls");
        	if (slSach==0) {
				cout<<"Danh sach sach trong!";
				PressAnyKey();
				break;
			}
        	cout<<"3. Xoa sach boi Ma sach.\n";
        	xoaSach(dsSach,slSach);
        	ghiFileSach(dsSach,slSach);
        	PressAnyKey();
			break;
		}
        case 4:{
        	system("cls");
        	if (slSach==0) {
				cout<<"Danh sach sach trong!";
				PressAnyKey();
				break;
			}
        	cout<<"4. Tim kiem sach.\n";
        	timKiemSach(dsSach,slSach);
			break;
		}
        case 5:
        	system("cls");
            if(slSach>0){
                cout<<"5. Hien thi danh sach sach.\n";
                xuatDSSach(dsSach,slSach);
            }
            else{
                cout<<"Danh sach sach trong!\n";
            }
            PressAnyKey();
            break;
        case 6:{
        	system("cls");
        	if(slSach>0){
            	system("cls");
            	if (slSach==0) {
            		cout<<"Danh sach sach trong!";
            		break;
				}
                cout<<"6. Sap xep danh sach sach theo ten.\n";
                sapXepDSSach(dsSach,slSach);
                xuatDSSach(dsSach,slSach);
            }
            else{
                cout<<"\nDanh sach doc gia trong!";
            }
        	ghiFileSach(dsSach,slSach);
            PressAnyKey();
            break;
		}                 
        case 7:{
        	system("cls");
        	cout<<"7. Them doc gia.\n";
        	themDocgia(dsDocGia,slDocGia);
        	ghiFileDocGia(dsDocGia,slDocGia);
        	PressAnyKey();
			break;
		}
        case 8:{
        	system("cls");
        	if (slDocGia==0) {
				cout<<"Danh sach doc gia trong!";
				PressAnyKey();
				break;
			}
        	cout<<"8. Cap nhat thong tin doc gia boi ma the.\n";
        	suaThongTinDocgia(dsDocGia,slDocGia);
        	ghiFileDocGia(dsDocGia,slDocGia);
        	PressAnyKey();
			break;
		}
        case 9:{
        	system("cls");
        	if (slDocGia==0) {
				cout<<"Danh sach doc gia trong!";
				PressAnyKey();
				break;
			}
        	cout<<"Xoa doc gia boi ma the.\n";
        	xoaDocgia(dsDocGia,slDocGia);
        	ghiFileDocGia(dsDocGia,slDocGia);
			break;
		}
        case 10:{
        	system("cls");
        	if (slDocGia==0) {
				cout<<"Danh sach doc gia trong!";
				PressAnyKey();
				break;
			}
        	cout<<"10. Tim kiem doc gia.\n";
        	timKiemDocGia(dsDocGia,slDocGia);
			break;
		}
		case 11: {
			system("cls");
			if (slDocGia==0) {
				cout<<"Danh sach doc gia trong!";
				PressAnyKey();
				break;
			}
			cout<<"11. Hien thi danh sach doc gia.\n";
			xuatDSDocgia(dsDocGia,slDocGia);
			PressAnyKey();
			break;
		}
        case 12:{
            if(slDocGia>0){
            	system("cls");
                cout<<"12. Sap xep doc gia theo ten.\n";
                sapXepDSDocGia(dsDocGia,slDocGia);
                xuatDSDocgia(dsDocGia,slDocGia);
        		ghiFileDocGia(dsDocGia,slDocGia);
            }
            else{
                cout<<"\nDanh sach doc gia trong!";
            }
            PressAnyKey();
			break;
		}
		case 13: {
			system("cls");
			if (slSach==0) {
				cout<<"Danh sach sach trong!";
				PressAnyKey();
				break;
			}
			if (slDocGia==0) {
				cout<<"Danh sach doc gia trong!";
				PressAnyKey();
				break;
			}
			cout<<"13. Muon sach.\n";
			muonSach(dsSach,slSach,dsDocGia,slDocGia);
        	ghiFileSach(dsSach,slSach);
        	ghiFileDocGia(dsDocGia,slDocGia);
			PressAnyKey();
			break;
		}
		case 14:{
			system("cls");
			if (slSach==0) {
				cout<<"Danh sach sach trong!";
				PressAnyKey();
				break;
			}
			if (slDocGia==0) {
				cout<<"Danh sach doc gia trong!";
				PressAnyKey();
				break;
			}
			cout<<"14. Tra sach.\n";
			traSach(dsSach,slSach,dsDocGia,slDocGia);
        	ghiFileSach(dsSach,slSach);
        	ghiFileDocGia(dsDocGia,slDocGia);
			PressAnyKey();
			break;
		}
		case 15:{
			system("cls");
			if (slDocGia==0) {
				cout<<"Danh sach doc gia trong!";
				PressAnyKey();
				break;
			}
			cout<<"15. Liet ke danh sach cac sach ma 1 doc gia dang muon.\n";
			lietKeDanhSachDangMuon(dsDocGia,slDocGia);
			PressAnyKey();
			break;
		}
		case 16:{
			system("cls");
			if (slSach==0) {
				cout<<"Danh sach sach trong!";
				PressAnyKey();
				break;
			}
			cout<<"16. Xuat top 10 sach duoc muon nhieu nhat.\n";
			xuatDSTop10Sach(dsSach,slSach);
			PressAnyKey();
			break;
		}
        case 0:
            cout<<"\nBan da thoat khoi chuong trinh!!!";
            cout<<"\nHen gap lai!";
            return 0;
        default:
            cout<<"\nKhong co chuc nang nay, vui long chon lai!";
            PressAnyKey();
            break;
        }
	}
	
	xoaDSSach(dsSach);
	xoaDSDocgia(dsDocGia);
	return 0;
}
	
	
	

