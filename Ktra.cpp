// Ktra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<cmath>

using namespace std;

struct PhanSo {
	float Tu;
	float Mau;
};

void NhapPhanSo(PhanSo &ps) {
	cout << "Nhap tu so: ";
	cin >> ps.Tu;
	cout << "Nhap mau so: ";
	cin >> ps.Mau;
}
void XuatPhanSo(PhanSo& ps) {
	cout << ps.Tu << "/" << ps.Mau ;
}
void Nhap(PhanSo pso[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan so thu " << i + 1 << " : " << endl;
		NhapPhanSo(pso[i]);
	}
}
void Xuat(PhanSo pso[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "\nPhan so thu " << i + 1 << " la: " << endl;
		XuatPhanSo(pso[i]);
	}
}
void SapXepTangDan(PhanSo pso[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (pso[i].Tu/pso[i].Mau > pso[j].Tu/pso[j].Mau) {
				swap(pso[i], pso[j]);
			}
		}
	}
	cout << "\nDanh sach phan so sau khi sap xep la: " << endl;
	for (int i = 0; i < n; i++) {
		XuatPhanSo(pso[i]);
		cout << "\t";
	}
}
PhanSo Max(PhanSo pso[], int n) {
	float c, b;
	PhanSo max = pso[0];
	for (int i = 0; i < n; i++) {
		c = max.Tu * pso[i].Mau;
		b = max.Mau * pso[i].Tu;
		if (c < b) {
			max = pso[i];
		}
	}
	XuatPhanSo(max);
	return max;
}
bool Search(PhanSo pso[], int n, PhanSo x) {
	for (int i = 0; i < n; i++) {
		if (pso[i].Tu / pso[i].Mau == x.Tu / x.Mau) {
			return 1;
		}
		return 0;
	}
}
int main() {
	PhanSo pso[100], x;
	int n;
	cout << "Nhap so luong phan so: ";
	cin >> n;
	Nhap(pso, n);
	Xuat(pso, n);
	SapXepTangDan(pso, n);
	cout << "\nPhan So lon nhat trong mang la: ";
	Max(pso, n);
	cout << endl;
	cout << "Nhap phan so can tim: ";
	NhapPhanSo(x);
	bool Ktra = Search(pso, n, x);
	if (Ktra == true) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
	system("pause");
}