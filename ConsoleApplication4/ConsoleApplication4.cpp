#include <stdio.h>
#include "string.h"
#include "time.h"
#include "conio.h"
#include <stdlib.h>

struct date {
	int ngay;
	int thang;
	int nam;
};
struct SinhVien {
	date ngaysinh;
	float diemdv;
	float dtl;
	char ten[50];
	char gioitinh[20];
	char quequan[100];

};
typedef SinhVien SV;
void nhapSinhVien(SV &sv);
void xoaXuongDong(char x[]);
void inSinhVien(SV sv);
int searchbyname(SV ds[], int n, char ten[]);
void nhapdanhsachsv(SV ds[], int& n);
void capNhatSinhVien(SV &sv);

//////////////////////////
void xoaXuongDong(char x[]) {
	size_t len = strlen(x);
	if (x[len - 1] == '\n') {
		x[len - 1] = '\0';
	}
}

void nhapSinhVien(SV& sv) {
	
	printf("\nTen: "); 
	fflush(stdin);
	fgets(sv.ten, sizeof(sv.ten), stdin); /*scanf("%s", sv.gioitinh);*/xoaXuongDong(sv.ten);
	printf("\nGioi tinh: ");fflush(stdin); fgets(sv.gioitinh, sizeof(sv.gioitinh), stdin); /*scanf("%s", sv.gioitinh);*/xoaXuongDong(sv.gioitinh);
	printf("\nQue Quan: "); fflush(stdin); fgets(sv.quequan, sizeof(sv.quequan), stdin);xoaXuongDong(sv.quequan);

	printf("\nNgay sinh: "); scanf("%d%d%d", &sv.ngaysinh.ngay, &sv.ngaysinh.thang, &sv.ngaysinh.nam);
	printf("\nDiem dv: "); scanf("%f", &sv.diemdv);
	printf("\nDiem tl: "); scanf("%f", &sv.dtl);
}
void inSinhVien(SV sv) {
	printf(" %20s \t %10s \t %2d/%d/%d \t %6.2f \t %6.2f \t %10s",  sv.ten, sv.gioitinh, sv.ngaysinh.ngay, sv.ngaysinh.thang, sv.ngaysinh.nam, sv.diemdv, sv.dtl,sv.quequan);
}
int searchbyname(SV ds[], int n, char ten[])
{
	for (int i = 0; i < n; i++) {
		if (strstr(ds[i].ten, ten)) {
			return 1;
		}
	}
	return 0;
}
void nhapdanhsachsv(SV ds[], int& n) {
	do {
		printf("\nNhap vao n:");
		scanf("%d", &n); fflush(stdin);
		
	} while (n <= 0);
	for (int i = 0; i < n; i++) {
		printf("Nhap vao sinh vien thu %d:\n ", i);
		nhapSinhVien(ds[i]);
	}
}
void capNhatSinhVien(SV& sv) {
	nhapSinhVien(sv);
}
void xuatDanhSachSinhVien(SV ds[], int n) {
	printf("%15s \t %10s \t %10s \t %10s \t %6s \t %6s \t %10s", "Ten", "Gioi Tinh", "Ngay Sinh", "Diem dv", "Diem tl", "Que Quan");
	printf("\n");
	for (int i = 0; i < n; i++) {
		inSinhVien(ds[i]);
		printf("\n");
	}
}
int main() {
	SV sv1, arr[10];
	int n = 10; int i;
	for (i = 0; i < n; i++) {
		nhapSinhVien(arr[i]);
	}
	/*nhapSinhVien(sv1);*/
	printf("%15s \t %10s \t %10s \t %10s \t %6s \t %6s \t %10s", "Ten", "Gioi Tinh", "Ngay Sinh", "Diem dv", "Diem tl", "Que Quan");
	for (i = 0; i < n; i++) {
		inSinhVien(arr[i]);

		/*inSinhVien(sv1);*/
		/*SV ds[100];
		int n;
		nhapdanhsachsv(ds, n);
		char name[] = "Alo";
		searchbyname(ds,n, name);*/
	}

}
