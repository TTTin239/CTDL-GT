#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<iomanip>
using namespace std;
struct Date {
	int Ngay;
	int Thang;
	int Nam;
};
struct Sach {
	int MaSach;
	char TenSach[20], TheLoai[10], TacGia[30];
	Date NamSanXuat;
	char TinhTrang[10];
};
struct DocGia{
    int MaThe;
    char TenDocGia[30], GioiTinh[15];
    Date NamSinh;
    int Tuoi;
    
};
void PrintLine(int n){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"_";
    }
    cout<<endl;
}
void PressAnyKey(){
    cout<<"\n\nBam phim bat ki de tiep tuc....";
    getch();
    system("cls");
}
int MaSachLonNhat(Sach a[], int n){
    int MaSachMax = 0;
    if(n>0){
        MaSachMax = a[0].MaSach;
        for(int i=0; i<n; i++){
            if(a[i].MaSach>MaSachMax){
                MaSachMax = a[i].MaSach;
            }
        }
    }
    return MaSachMax;
}
void NhapThongTinSach(Sach &sh,int MaSach){
    cout<<"\nNhap ten sach: ";cin.ignore(); cin.getline(sh.TenSach, 20);
    cout<<"\nNhap ten tac gia: "; cin.getline(sh.TacGia, 30);
    cout<<"\nNhap the loai: "; cin.getline(sh.TheLoai, 10);
    cout<<"\nNhap tinh trang: "; cin.getline(sh.TinhTrang, 10);
    cout<<"\nNhap ngay thang xuat ban: ";
    cout<<"\n\tNhap ngay xuat ban: "; cin>>sh.NamSanXuat.Ngay;
    cout<<"\n\tNhap thang xuat ban: "; cin>>sh.NamSanXuat.Thang;
    cout<<"\n\tNhap nam xuat ban: "; cin>>sh.NamSanXuat.Nam;
    sh.MaSach = MaSach;
}
void AddBook(Sach a[], int MaSach, int n){
    PrintLine(40);
    cout<<"\nNhap sach thu "<<n+1<<": ";
    NhapThongTinSach(a[n], MaSach);
    PrintLine(40);
}
void CapNhapThongTinSach(Sach &sh){
    cout<<"\nNhap ten sach: "; cin.ignore(); cin.getline(sh.TenSach, 20);
    cout<<"\nNhap ten tac gia: "; cin.getline(sh.TacGia, 30);
    cout<<"\nNhap the loai: "; cin.getline(sh.TheLoai, 10);
    cout<<"\nNhap tinh trang: "; cin.getline(sh.TinhTrang, 10);
    cout<<"\nNhap ngay thang xuat ban: ";
    cout<<"\n\tNhap ngay xuat ban: "; cin>>sh.NamSanXuat.Ngay;
    cout<<"\n\tNhap thang xuat ban: "; cin>>sh.NamSanXuat.Thang;
    cout<<"\n\tNhap nam xuat ban: "; cin>>sh.NamSanXuat.Nam;
}
void UpdateBook(Sach a[], int MaSach, int n){
    int found = 0;
    for(int i=0;i<n;i++){
        if(a[i].MaSach=MaSach){
            found = 1;
            PrintLine(40);
            cout<<"\nCap nhap thong tin sach co ma sach la: "<<MaSach;
            CapNhapThongTinSach(a[i]);
            PrintLine(40);
            break;
        }
    }
    if(found==0){
        cout<<"\nSach co ma sach( "<<MaSach<<" ) khong ton tai.";
    }
}
int XoaTheoMaSach(Sach a[], int MaSach, int n){
    int found = 0;
    for(int i=0; i<n; i++){
        if(a[i].MaSach == MaSach){
            found = 1;
            PrintLine(40);
            for(int j=i; j<n; j++){
                a[j] = a[j+1];
            }
            cout<<"\nDa xoa sach co ma sach la: "<<MaSach;
            PrintLine(40);
            break;
        }
    }
    if(found == 0){
        cout<<"\nSach co ma sach( "<<MaSach<<" ) khong ton tai.";
        return 0;
    }
    else{
        return 1;
    }
}
void ShowBook(Sach a[], int n){
    PrintLine(100);
    cout<<"\nSTT\tMa sach\t\tTen sach\tTac gia\t\tThe loai\tTinh trang\tNgay xuat ban"<<endl;
    for(int i=0; i<n; i++){
        cout<<"\n"<<i+1;
        cout<<"\t"<<a[i].MaSach;
        cout<<"\t\t"<<a[i].TenSach;
        cout<<"\t"<<a[i].TacGia;
        cout<<"\t"<<a[i].TheLoai;
        cout<<"\t\t"<<a[i].TinhTrang;
        cout<<"\t\t"<<a[i].NamSanXuat.Ngay<<"/"<<a[i].NamSanXuat.Thang<<"/"<<a[i].NamSanXuat.Nam;
    }
    PrintLine(100);
}
void TimKiemTheoTenSach(Sach a[], char TenSach[], int n){
    Sach ArrayFound[100];
    char Ten[20];
    int found = 0;
    for (int i=0; i<n; i++){
        strcpy(Ten, a[i].TenSach);
        if(strstr(strupr(Ten),strupr(TenSach))){
            ArrayFound[found] = a[i];
            found++;
        }
    }
    ShowBook(ArrayFound, found);
}
void SapXepTheoTenSach(Sach a[], int n){
    Sach tmp;
    char TenSach1[20];
    char TenSach2[20];
    for(int i=0; i<n;i++){
        strcpy(TenSach1, a[i].TenSach);
        for(int j=i+1;j<n;j++){
            strcpy(TenSach2, a[j].TenSach);
            if(strcmp(strupr(TenSach1), strupr(TenSach2)) > 0){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
void SapXepTheoMaSach(Sach a[], int n){
    Sach tmp;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n;j++){
            if(a[i].MaSach > a[j].MaSach){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
int DocFileSach(Sach a[], char FileName[]){
    FILE *fp;
    int i = 0;
    fp = fopen(FileName, "r");
    cout<<"\nChuan bi doc file: "; puts(FileName);
    while(fscanf(fp, "%5d%20s%30s%10s%10s%d/%d/%d\n", &a[i].MaSach, &a[i].TenSach, &a[i].TacGia, &a[i].TheLoai, &a[i].TinhTrang, &a[i].NamSanXuat.Ngay, &a[i].NamSanXuat.Thang, &a[i].NamSanXuat.Nam) != EOF){
        i++;
        cout<<"\nDoc ban ghi sach thu: "<<i;
    }
    cout<<"\nSo luong sach co san trong file la: "<<i<<endl;
    fclose(fp);
    return i;
}
void GhiFileSach(Sach a[], int n, char FileName[]){
    FILE *fp;
    fp = fopen(FileName, "w");
    for(int i=0; i<n; i++){
        fprintf(fp, "%5d%20s%30s%10s%10s%5d/%d/%d\n", a[i].MaSach, a[i].TenSach, a[i].TacGia, a[i].TheLoai, a[i].TinhTrang,  a[i].NamSanXuat.Ngay, a[i].NamSanXuat.Thang, a[i].NamSanXuat.Nam);
    }
    fclose(fp);
}

int MaTheLonNhat(DocGia b[], int m){
    int MaTheMax = 0;
    if(m>0){
        MaTheMax = b[0].MaThe;
        for(int i=0; i<m; i++){
            if(b[i].MaThe>MaTheMax){
                MaTheMax = b[i].MaThe;
            }
        }
    }
    return MaTheMax;
}
void NhapThongTinDocGia(DocGia &dg, int MaThe){
    cout<<"\nNhap ten doc gia: "; cin.ignore(); cin.getline(dg.TenDocGia, 30);
    cout<<"\nNhap gioi tinh: "; cin.getline(dg.GioiTinh, 15);
    cout<<"\nNhap tuoi: "; cin>>dg.Tuoi;
    cout<<"\nNhap ngay thang nam sinh: ";
    cout<<"\n\tNhap ngay sinh: "; cin>>dg.NamSinh.Ngay;
    cout<<"\n\tNhap thang sinh: "; cin>>dg.NamSinh.Thang;
    cout<<"\n\tNhap nam sinh: "; cin>>dg.NamSinh.Nam;
    dg.MaThe = MaThe;
}
void AddDocGia(DocGia b[], int MaThe, int m){
    PrintLine(40);
    cout<<"\nNhap doc gia thu "<<m+1<<": ";
    NhapThongTinDocGia(b[m],MaThe);
    PrintLine(40);
}
void CapNhapThongTinDocGia(DocGia &dg){
    cout<<"\nNhap ten doc gia: "; cin.ignore(); cin.getline(dg.TenDocGia, 30);
    cout<<"\nNhap gioi tinh: "; cin.getline(dg.GioiTinh, 15);
    cout<<"\nNhap tuoi: "; cin>>dg.Tuoi;
    cout<<"\nNhap ngay thang nam sinh: ";
    cout<<"\n\tNhap ngay sinh: "; cin>>dg.NamSinh.Ngay;
    cout<<"\n\tNhap thang sinh: "; cin>>dg.NamSinh.Thang;
    cout<<"\n\tNhap nam sinh: "; cin>>dg.NamSinh.Nam;
}
void UpdateDocGia(DocGia b[], int MaThe, int m){
    int found = 0;
    for(int i=0;i<m;i++){
        if(b[i].MaThe == MaThe){
            found = 1;
            PrintLine(40);
            cout<<"\nCap nhap doc gia co ma the la: "<<MaThe;
            CapNhapThongTinDocGia(b[i]);
            PrintLine(40);
            break;
        }
    }
    if(found == 0){
        cout<<"\nDoc gia co ma the( "<<MaThe<<" ) khong ton tai.";
    }
}
int XoaTheoMaThe(DocGia b[], int MaThe, int m){
    int found = 0;
    for(int i=0; i<m;i++){
        if(b[i].MaThe == MaThe){
            found = 1;
            PrintLine(40);
            for(int j=i; j<m; j++){
                b[j] = b[j+1];
            }
            cout<<"\nDa xoa doc gia co ma the la: "<<MaThe;
            PrintLine(40);
            break;
        }
    }
    if(found == 0){
        cout<<"\nDoc gia co ma the( "<<MaThe<<" ) khong ton tai.";
        return 0;
    }
    else{
        return 1;
    }
}
void ShowDocGia(DocGia b[], int m){
    PrintLine(100);
    cout<<"\nSTT\tMa the\tTen doc gia\t\tTuoi\tGioi tinh\tNgay thang nam sinh";
    for(int i=0; i<m; i++){
        cout<<"\n"<<i+1;
        cout<<"\t"<<b[i].MaThe;
        cout<<"\t"<<b[i].TenDocGia;
        cout<<"\t\t"<<b[i].Tuoi;
        cout<<"\t"<<b[i].GioiTinh;
        cout<<"\t\t"<<b[i].NamSinh.Ngay<<"/"<<b[i].NamSinh.Thang<<"/"<<b[i].NamSinh.Nam;
    }
    PrintLine(100);
}
void SearchTheoTenDocGia(DocGia b[], char TenDocGia[], int m){
    DocGia ArrayFound[100];
    char Ten[30];
    int found = 0;
    for(int i=0; i<m; i++){
        strcpy(Ten, b[i].TenDocGia);
        if(strstr(strupr(Ten), strupr(TenDocGia))){
            ArrayFound[found] = b[i];
            found++;
        }
    }
    ShowDocGia(ArrayFound, found);
}
void SapXepTheoMaThe(DocGia b[], int m){
    DocGia tmp;
    for(int i=0; i<m; i++){
        for(int j=i+1;j<m;j++){
            if(b[i].MaThe > b[j].MaThe){
                tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }
    }
}
void SapXepTheoTen(DocGia b[], int m){
    DocGia tmp;
    char TenDG1[30], TenDG2[30];
    for(int i=0; i<m; i++){
        strcpy(TenDG1, b[i].TenDocGia);
        for(int j=i+1; j<m; j++){
            strcpy(TenDG2, b[i].TenDocGia);
            if(strcmp(strupr(TenDG1),strupr(TenDG2))>0){
                tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }
    }
}
int ReadFile(DocGia b[], char FileName[]){
    FILE *fp1;
    int i=0;
    fp1 = fopen(FileName, "r");
    cout<<"\nChuan bi doc file: "; puts(FileName);
    while(fscanf(fp1, "%5d%30s%5d%15s\n", &b[i].MaThe, &b[i].TenDocGia, &b[i].Tuoi, &b[i].GioiTinh) != EOF){
        i++;
        cout<<"\nDoc ban ghi doc gia thu "<<i;
    }
    cout<<"\nSo luong doc gia co san trong file la: "<<i<<endl;
    fclose(fp1);
    return i;
}
void WriteFile(DocGia b[], int m, char FileName[]){
    FILE *fp1;
    fp1 = fopen(FileName, "w");
    for(int i=0; i<m; i++){
        fprintf(fp1, "%5d%30s%5d%15s\n", b[i].MaThe, b[i].TenDocGia, b[i].Tuoi, b[i].GioiTinh);
    }
    fclose(fp1);
}

int main(){
    Sach sh[100];
    DocGia dg[100];
    char FileName[] = "QLTV.txt";
    int slSach = 0, MSCount = 0;
    int slDG = 0, MTCount = 0;
    int key, choice1, choice2;
    slSach = DocFileSach(sh, FileName);
    MSCount = MaSachLonNhat(sh, slSach);
    slDG = ReadFile(dg, FileName);
    MTCount = MaTheLonNhat(dg,slDG);
    while (true)
    {
        cout<<"\nCHUONG TRINH QUAN LI THU VIEN\n";
        cout<<"********************MENU**************************\n";
        cout<<"**   1.  Them sach.                             **\n";
        cout<<"**   2.  Cap nhap thong tin sach boi ma sach.   **\n";
        cout<<"**   3.  Xoa sach boi Ma sach.                  **\n";
        cout<<"**   4.  Tim kiem sach theo ten sach.           **\n";
        cout<<"**   5.  Hien thi danh sach sach.               **\n";
        cout<<"**   6.  Sap xep:                               **\n";
        cout<<"**  \t6.1  Sap xep theo ten sach.             **\n";
        cout<<"**  \t6.2  Sap xep theo ma sach.              **\n";
        cout<<"**   7.  Ghi danh sach sach vao file.           **\n";
        cout<<"**   8.  Them doc gia.                          **\n";
        cout<<"**   9.  Cap nhap thong tin doc gia boi ma the. **\n";
        cout<<"**   10.  Xoa doc gia boi ma the.               **\n";
        cout<<"**   11. Tim kiem doc gia the ten cua doc gia.  **\n";
        cout<<"**   12. Hien thi danh sach doc gia.            **\n";
        cout<<"**   13. Sap xep:                               **\n";
        cout<<"**  \t13.1  Sap xep theo ten doc gia.         **\n";
        cout<<"**  \t13.2  Sap xep theo ma the.              **\n";
        cout<<"**   14. Ghi danh sach doc gia vao file.        **\n";
        cout<<"**   0.  Thoat.                                 **\n";
        cout<<"**************************************************\n";
        cout<<"\tNhap lua chon cua ban: ";
        cin>>key;
        switch (key)
        {
        case 1:
            cout<<"\n1. Them sach.";
            MSCount++;
            AddBook(sh, MSCount, slSach);
            cout<<"\nThem sach thanh cong!";
            slSach++;
            PressAnyKey();            
            break;
        case 2:
            if(slSach>0){
                int MS1;
                cout<<"\n2. Cap nhap thong tin sach.";
                cout<<"\nNhap ma sach: "; cin>>MS1;
                if(sh->MaSach == MS1){
                    UpdateBook(sh, MS1, slSach);
                }
                else{
                    cout<<"\nKhong ton tai ma sach";
                }
            }
            else{
                cout<<"\nDanh sach sach trong!";
            }
            PressAnyKey();
            break;
        case 3:
            if(slSach>0){
                int MS2;
                cout<<"\n3. Xoa sach.";
                cout<<"\nNhap ma sach: "; cin>>MS2;
                if(XoaTheoMaSach(sh, MS2, slSach) == 1){
                    printf("\nSach co ma sach( %d ) da bi xoa.", &MS2);
                    slSach--;
                }
            }
            else{
                cout<<"\nDanh sach sach trong!";
            }
            PressAnyKey();
            break;
        case 4:
            if(slSach>0){
                cout<<"\n4. Tim kiem sach theo ten sach.";
                char strTenS[20];
                cout<<"\nNhap ten sach tim kiem: "; cin.ignore(); cin.getline(strTenS, 20);
                if(sh->TenSach == strTenS){
                    TimKiemTheoTenSach(sh, strTenS, slSach);
                }
                else{
                    cout<<"\nKhong ton tai ma sach";
                }
            }
            else{
                cout<<"\nDanh sach trong!";
            }
            PressAnyKey();
            break;
        case 5:
            if(slSach>0){
                cout<<"\n5. Hien thi danh sach sach.";
                ShowBook(sh, slSach);
            }
            else{
                cout<<"\nDanh sach sach trong!";
            }
            PressAnyKey();
            break;
        case 6:
            if(slSach>0){
                cout<<"\n6. Sap xep:";
                cout<<"\nChon 1 de sap xep theo ten hoac chon 2 de sap xep theo ma sach.";
                do
                {
                    cin>>choice1;
                    if(choice1<1||choice1>2){
                        cout<<"\nVui long nhap lai!";
                    }
                } while (choice1<1||choice1>2);
                if(choice1 == 1){
                    SapXepTheoTenSach(sh, slSach);
                    ShowBook(sh, slSach);
                }
                if(choice1 == 2){
                    SapXepTheoMaSach(sh, slSach);
                    ShowBook(sh, slSach);
                }
            }
            else{
                cout<<"\nDanh sach sach trong!";
            }
            PressAnyKey();
            break;
        case 7:
            if(slSach>0){
                cout<<"\n7. Ghi danh sach sach vao file.";
                GhiFileSach(sh, slSach, FileName);
            }
            else{
                cout<<"\nDanh sach sinh vien trong!";
            }
            printf("\nGhi danh sach sach vao file %s thanh cong!", FileName);
            PressAnyKey();
            break;                 
        case 8:
            cout<<"\n8. Them doc gia.";
            MTCount++;
            AddDocGia(dg, MTCount, slDG);
            cout<<"\nThem doc gia thanh cong!";
            slDG++;
            PressAnyKey();
            break;
        case 9:
            if(slDG>0){
                int MT1;
                cout<<"\n9. Cap nhap thong tin doc gia.";
                cout<<"\n Nhap ma the: "; cin>>MT1;
                if(dg->MaThe == MT1){
                    UpdateDocGia(dg, MT1, slDG);
                }
                else{
                    cout<<"\nKhong ton tai ma the";
                }
            }
            else{
                cout<<"\nDanh sach doc gia trong!";
            }
            PressAnyKey();
            break;
        case 10:
            if(slDG>0){
                int MT2;
                cout<<"\n10. Xoa doc gia.";
                cout<<"\nNhap ma the: "; cin>>MT2;
                if(XoaTheoMaThe(dg, MT2, slDG) == 1){
                    cout<<"\nDoc gia co ma the( "<<MT2<<" ) da bi xoa.";
                    slDG--;
                }
            }
            else{
                cout<<"\nDanh sach doc gia trong!";
            }
            PressAnyKey();
            break;
        case 11:
            if(slDG>0){
                cout<<"\n11. Tim kiem doc gia theo ten.";
                char strTen[30];
                cout<<"\nNhap ten de tim kiem: "; cin.ignore(); cin.getline(strTen, 30);
                if(dg->TenDocGia == strTen){
                    SearchTheoTenDocGia(dg, strTen, slDG);
                }
                else{
                    cout<<"\nKhong ton tai ma the";
                }
            }
            else{
                cout<<"\nDanh sach doc gia trong!";
            }
            PressAnyKey();
            break;
        case 13:
            if(slDG>0){
                cout<<"\n13. Sap xep.";
                cout<<"\nChon 1 de sap xep theo ten hoac chon 2 de sap xep theo ma the.\n";
                do
                {
                    cin>>choice2;
                    if(choice2<1||choice2>2){
                        cout<<"\nVui long nhap lai!\n";
                    }
                } while (choice2<1||choice2>2);
                if(choice2 ==1){
                    SapXepTheoTen(dg, slDG);
                    ShowDocGia(dg, slDG);
                }
                if(choice2 == 2){
                    SapXepTheoMaThe(dg, slDG);
                    ShowDocGia(dg, slDG);
                }                
            }
            else{
                cout<<"\nDanh sach doc gia trong!";
            }
            PressAnyKey();
            break;
        case 12:
            if(slDG>0){
                cout<<"\n12. Hien thi danh sach doc gia.";
                ShowDocGia(dg, slDG);
            }
            else{
                cout<<"\nDanh sach doc gia trong!";
            }
            PressAnyKey();
            break;
        case 14:
            if(slDG>0){
                cout<<"\n14. Ghi danh sach doc gia vao file.";
                WriteFile(dg,slDG, FileName);
            }
            else{
                cout<<"\nDanh sach doc gia trong!";
            }
            printf("\nGhi danh sach sinh vien vao file %s thanh cong!", FileName);
            PressAnyKey();
            break;
        case 0:
            cout<<"\nBan da thoat khoi chuong trinh!!!";
            cout<<"\nHen gap lai!";
            getch();
            return 0;
        default:
            cout<<"\nKhong co chuc nang nay, vui long chon lai!";
            PressAnyKey();
            break;
        }
    }
    // return 0;
    // system("pause");
}