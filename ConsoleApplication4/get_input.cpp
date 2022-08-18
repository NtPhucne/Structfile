#include"get_input.h"
#include <stdlib.h>
#include<string.h>
#include<stdio.h>
void get_sv(SV& sv) {
	char readnewline[10];
	fgets(readnewline, sizeof(readnewline), stdin); // line nay de xoa /n khi nhap scanf 
	printf("\nTen: "); fflush(stdin); fgets(sv.ten, sizeof(sv.ten), stdin); /*scanf("%s", sv.gioitinh);*/xoaXuongDong(sv.ten);
	printf("\nGioi tinh: "); fflush(stdin); fgets(sv.gioitinh, sizeof(sv.gioitinh), stdin); /*scanf("%s", sv.gioitinh);*/xoaXuongDong(sv.gioitinh);
	printf("\nQue Quan: "); fflush(stdin); fgets(sv.quequan, sizeof(sv.quequan), stdin); xoaXuongDong(sv.quequan);

	printf("\nNgay sinh: "); scanf("%d%d%d", &sv.ngaysinh.ngay, &sv.ngaysinh.thang, &sv.ngaysinh.nam);
	printf("\nDiem dv: "); scanf("%f", &sv.diemdv);
	printf("\nDiem tl: "); scanf("%f", &sv.dtl);
	//char readnewline[10];
	//fgets(readnewline, sizeof(readnewline), stdin); // line nay de xoa /n khi nhap scanf 

}
void get_listsv(SV ds[], int& n) {
	do {
		printf("\nNhap vao n:");
		scanf("%d", &n); fflush(stdin);

	} while (n <= 0);
	for (int i = 0; i < n; i++) {
		printf("Nhap vao sinh vien thu %d:\n ", i);
		get_sv(ds[i]);
	}
}

void xoaXuongDong(char x[]) {
	size_t len = strlen(x);
	if (x[len - 1] == '\n') {
		x[len - 1] = '\0';
	}
}