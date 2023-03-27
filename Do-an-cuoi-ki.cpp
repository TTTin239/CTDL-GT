#include <iostream>
#include <string.h>

using namespace std;

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
		cout<<"Ngay xuat ban: "<<ngay<<"/"<<thang<<"/"<<nam<<"\n";
	}
};


struct Sach
{
	char maSach[10]; //cap phat tinh
	char tenSach[50], theLoai[50], tacGia[30];
	Date namXuatBan;
	char tinhTrang[10];
	bool tinhTrangMuon;
	
	void nhapThongTin() {
		cout<<"Nhap ma sach: "; 
		fflush(stdin); //xoa vung nho dem
		cin.getline(maSach,10);  //de nhap toi khi gap dau
		cout<<"Nhap ten sach: ";
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
		cout<<"Ma sach: "<<maSach<<"\n";
		cout<<"Ten sach: "<<tenSach<<"\n";
		cout<<"The loai: "<<theLoai<<"\n";
		cout<<"Tac gia: "<<tacGia<<"\n";	
		namXuatBan.xuat();
		cout<<"Tinh trang sach: "<<tinhTrang<<"\n";
		cout<<"Tinh trang muon: ";
		if (tinhTrangMuon) {
			cout<<"Da muon\n";
		}
		else {
			cout<<"Chua muon\n";
		}
	}
};

int timViTriSachTheoMa(Sach *,int ,char[]);

void nhapDSSach(Sach *&dsSach, int &slSach) { //co dau & la tham chieu, nghia la khi ket thuc ham thi gia tri bien thay doi theo gia tri trong ham
	cout<<"Nhap so luong sach: "; cin>>slSach;
	dsSach = new Sach[slSach];
	for (int i=0; i<slSach; i++) {
		int vt;
		do {
			dsSach[i].nhapThongTin();
			vt = timViTriSachTheoMa(dsSach,i,dsSach[i].maSach);
			if (vt!=-1) {
				cout<<"Ma sach bi trung. Moi ban nhap lai: \n";
			}
		} while (vt!=-1);
	}
}


void xuatDSSach(Sach *dsSach, int slSach) { // khong co dau & la tham tri, nghia la khi ket thuc ham thi gia tri bien khong thay doi ma tra ve gia tri luc moi khai bao
	cout<<"DANH SACH SACH:\n";
	for (int i=0; i<slSach; i++) {
		dsSach[i].xuat();
	}
	cout<<"\n";
}

void xoaDSSach(Sach *dsSach) {
	delete [] dsSach; //xoa cap phat dong cho mang danh sach Sach, neu khong xoa thi du lieu se bi luu tren Ram cho toi khi khoi dong lai may
}

void themSach(Sach *&dsSach, int &slSach) {
	Sach sachMoi;
	int vt;
	do {
		cout<<"Nhap thong tin sach duoc them:\n"; sachMoi.nhapThongTin();
		vt = timViTriSachTheoMa(dsSach,slSach,sachMoi.maSach);
		if (vt!=-1) {
			cout<<"Ma sach bi trung. Moi ban nhap lai: \n";
		}
	} while (vt!=-1);
	
	//them sach vao ds
	slSach++;
	Sach *dsTam = new Sach[slSach];
	for (int i=0; i<slSach-1; i++) {
		dsTam[i] = dsSach[i];
	}
	dsTam[slSach-1] = sachMoi;
	
	xoaDSSach(dsSach);
	
	dsSach = new Sach[slSach];
	dsSach = dsTam;
}

int timViTriSachTheoMa(Sach *dsSach, int slSach, char maSachTim[]) {
	for (int i=0; i<slSach; i++)  {
		if (strcmp(dsSach[i].maSach,maSachTim)==0) { //strcmp=0 thi 2 chuoi bang nhau
			return i;
		}
	}
	return -1;
}

int timViTriSachTheoTen(Sach *dsSach, int slSach, char tenSachTim[]) {
	for (int i=0; i<slSach; i++)  {
		if (strcmp(dsSach[i].tenSach,tenSachTim)==0) { //strcmp=0 thi 2 chuoi bang nhau
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
		int vt;
		Sach sachMoi;
		do {
			cout<<"Nhap thong tin moi cho sach:\n";
			sachMoi.nhapThongTin();
			vt = timViTriSachTheoMa(dsSach,slSach,sachMoi.maSach);
			if (strcmp(sachMoi.maSach,dsSach[viTriSua].maSach)!=0 && vt!=-1) {
				cout<<"Ma sach bi trung. Moi ban nhap lai: \n";
			}
		} while (strcmp(sachMoi.maSach,dsSach[viTriSua].maSach)!=0 && vt!=-1);
		dsSach[viTriSua] = sachMoi;
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
			if (strcmp(dsSach[i].maSach,dsSach[j].maSach)) {
				Sach tmp = dsSach[i];
				dsSach[i] = dsSach[j];
				dsSach[j] = tmp;
			}
		}
	}
}




//////////////////3-4

struct Date_Birth
{
	int ngay_sinh;
	int thang_sinh;
	int nam_sinh;
	
	void nhap() {
		cout<<"Nhap ngay sinh: "; cin>>ngay_sinh;
		cout<<"Nhap thang sinh: "; cin>>thang_sinh;
		cout<<"Nhap nam sinh: "; cin>>nam_sinh;
	}
	
	void xuat() {
		cout<<"Ngay sinh: "<<ngay_sinh<<"/"<<thang_sinh<<"/"<<nam_sinh<<"\n";
	}
};


struct Docgia
{
	char maDocgia[10]; //cap phat tinh
	char tenDocgia[50];
	Date_Birth namSinh;
	
	void nhapThongTin() {
		cout<<"Nhap ma the: "; 
		fflush(stdin); //xoa vung nho dem
		cin.getline(maDocgia,10);  //de nhap toi khi gap dau
		cout<<"Nhap ten doc gia: ";
		cin.getline(tenDocgia,50);
		
		cout<<"Nhap ngay/thang/nam sinh:\n";
		namSinh.nhap();
		
	}
	
	void xuat() {
		cout<<"Ma doc gia: "<<maDocgia<<"\n";
		cout<<"Ten doc gia: "<<tenDocgia<<"\n";	
		namSinh.xuat();
	}
};

int timViTriDocgiaTheoMa(Docgia *,int ,char[]);

void nhapDSDocgia(Docgia *&dsDocgia, int &slDocgia) { //co dau & la tham chieu, nghia la khi ket thuc ham thi gia tri bien thay doi theo gia tri trong ham
	cout<<"Nhap so luong doc gia: "; cin>>slDocgia;
	dsDocgia = new Docgia[slDocgia];
	for (int i=0; i<slDocgia; i++) {
		int vt;
		do {
			dsDocgia[i].nhapThongTin();
			vt = timViTriDocgiaTheoMa(dsDocgia,i,dsDocgia[i].maDocgia);
			if (vt!=-1) {
				cout<<"Ma doc gia bi trung. Moi ban nhap lai: \n";
			}
		} while (vt!=-1);
	}
}


void xuatDSDocgia(Docgia *dsDocgia, int slDocgia) { // khong co dau & la tham tri, nghia la khi ket thuc ham thi gia tri bien khong thay doi ma tra ve gia tri luc moi khai bao
	cout<<"DANH SACH DOC GIA:\n";
	for (int i=0; i<slDocgia; i++) {
		dsDocgia[i].xuat();
	}
	cout<<"\n";
}

void xoaDSDocgia(Docgia *dsDocgia) {
	delete [] dsDocgia; //xoa cap phat dong cho mang danh sach Sach, neu khong xoa thi du lieu se bi luu tren Ram cho toi khi khoi dong lai may
}

void themDocgia(Docgia *&dsDocgia, int &slDocgia) {
	Docgia docgiaMoi;
	int vt;
	do {
		cout<<"Nhap thong tin doc gia duoc them:\n"; docgiaMoi.nhapThongTin();
		vt = timViTriDocgiaTheoMa(dsDocgia,slDocgia,docgiaMoi.maDocgia);
		if (vt!=-1) {
			cout<<"Ma doc gia bi trung. Moi ban nhap lai: \n";
		}
	} while (vt!=-1);
	
	//them doc gia vao ds
	slDocgia++;
	Docgia *dsTam = new Docgia[slDocgia];
	for (int i=0; i<slDocgia-1; i++) {
		dsTam[i] = dsDocgia[i];
	}
	dsTam[slDocgia-1] = docgiaMoi;
	
	xoaDSDocgia(dsDocgia);
	
	dsDocgia = new Docgia[slDocgia];
	dsDocgia = dsTam;
}

int timViTriDocgiaTheoMa(Docgia *dsDocgia, int slDocgia, char maDocgiaTim[]) {
	for (int i=0; i<slDocgia; i++)  {
		if (strcmp(dsDocgia[i].maDocgia,maDocgiaTim)==0) { //strcmp=0 thi 2 chuoi bang nhau
			return i;
		}
	}
	return -1;
}

int timViTriDocgiaTheoTen(Docgia *dsDocgia, int slDocgia, char tenDocgiaTim[]) {
	for (int i=0; i<slDocgia; i++)  {
		if (strcmp(dsDocgia[i].tenDocgia,tenDocgiaTim)==0) { //strcmp=0 thi 2 chuoi bang nhau
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
		int vt;
		Docgia docgiaMoi;
		do {
			cout<<"Nhap thong tin moi cho doc gia:\n";
			docgiaMoi.nhapThongTin();
			vt = timViTriDocgiaTheoMa(dsDocgia,slDocgia,docgiaMoi.maDocgia);
			if (strcmp(docgiaMoi.maDocgia,dsDocgia[viTriSua].maDocgia)!=0 && vt!=-1) {
				cout<<"Ma doc gia bi trung. Moi ban nhap lai: \n";
			}
		} while (strcmp(docgiaMoi.maDocgia,dsDocgia[viTriSua].maDocgia)!=0 && vt!=-1);
		dsDocgia[viTriSua] = docgiaMoi;
	}
}

void timDSDocgiaTheoMa(Docgia* dsDocgia, Docgia*& dsDocgiaTheoMa, int slDocgia, int &slDocgiaTG)   {
	char maTim[30];
	cout<<"Nhap ma can tim: "; 
	fflush(stdin);
	cin.getline(maTim,30);
	slDocgiaTG = 0;
	for (int i=0; i<slDocgia; i++) {
		if (strcmp(dsDocgia[i].maDocgia,maTim)==0) {
			slDocgiaTG++;
		}
	}
	dsDocgiaTheoMa = new Docgia[slDocgiaTG];
	int k=0;
	for (int i=0; i<slDocgia; i++) {
		if (strcmp(dsDocgia[i].maDocgia,maTim)==0) {
			dsDocgiaTheoMa[k] = dsDocgia[i];
			k++;
		}
	}
}

int main() {
	Sach* dsSach;  //cap phat dong
	int slSach=0;
	nhapDSSach(dsSach,slSach);
//	xuatDSSach(dsSach,slSach);
//	themSach(dsSach,slSach);
//	xuatDSSach(dsSach,slSach);
//	xoaSach(dsSach,slSach);
//	xuatDSSach(dsSach,slSach);
//	suaThongTinSach(dsSach,slSach);
//	xuatDSSach(dsSach,slSach);
//	
//	Sach* dsSachTheoTacGia;
//	int slSachTG;
//	timDSSachTheoTacGia(dsSach,dsSachTheoTacGia,slSach,slSachTG);
//	cout<<"Danh sach sach theo tac gia: \n";
//	xuatDSSach(dsSachTheoTacGia,slSachTG);

	sapXepDSSach(dsSach,slSach);
	xuatDSSach(dsSach,slSach);
	
	xoaDSSach(dsSach);
//	xoaDSSach(dsSachTheoTacGia);





/////////////////////3-4

Docgia* dsDocgia;  //cap phat dong
	int slDocgia;
	nhapDSDocgia(dsDocgia,slDocgia);
	xuatDSDocgia(dsDocgia,slDocgia);
	int yeucau;
	cout<<" - - - - - Danh sach cac thao tac - - - - -\n";
	cout<<"1. Tim kiem\n";
	cout<<"2. Chen\n";
	cout<<"3. Xoa\n";
	cout<<"4. Cap nhat\n";
	cout<<"5. Sap xep\n";
	cout<<"0. Ket thuc\n";
	cout<<"Moi ban chon yeu cau so: ";	cin>>yeucau;
	while (yeucau != 0) {
		if (yeucau == 1) {
			Docgia* dsDocgiaTheoMa;
			int slDocgiaTG;
			timDSDocgiaTheoMa(dsDocgia,dsDocgiaTheoMa,slDocgia,slDocgiaTG);
			cout<<"Danh sach doc gia theo ma the: \n";
			xuatDSDocgia(dsDocgiaTheoMa,slDocgiaTG);
			xoaDSDocgia(dsDocgia);
			xoaDSDocgia(dsDocgiaTheoMa);
		} else if (yeucau == 2) {
			themDocgia(dsDocgia,slDocgia);
			xuatDSDocgia(dsDocgia,slDocgia);
		} else if (yeucau == 3) {
			xoaDocgia(dsDocgia,slDocgia);
			xuatDSDocgia(dsDocgia,slDocgia);
		} else if (yeucau == 4) {
			suaThongTinDocgia(dsDocgia,slDocgia);
			xuatDSDocgia(dsDocgia,slDocgia);
		} else if (yeucau == 5) {
			cout<<"Danh sach doc gia theo ma the tang:\n";
			Docgia* tg;
			for (int i = 0; i < slDocgia; ++i) {
				Docgia* p = dsDocgia + i;
				for (int j = 0; j < slDocgia; ++j) {
					if ( strcmp(p->maDocgia,(dsDocgia+j)->maDocgia) < 0) {
						Docgia *pj = dsDocgia + j;
						tg = p;
						p = pj;
						pj = tg;
					}
				}
			}
			xuatDSDocgia(dsDocgia,slDocgia);
		} else return 0;
		char con[5];
		cout<<"Ban co muon tiep tuc (Yes/No)?\n=> Your answer: "; fflush(stdin); cin.getline(con,5);
		if (strcmp(con,"No") == 0) return 0;
		else cout<<"Moi ban chon yeu cau so: ";	cin>>yeucau;
	}
	return 0;
}
	
	
	

