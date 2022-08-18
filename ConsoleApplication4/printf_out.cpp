#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include"Data.h"
#include"printf_out.h"
void printf_sv(SV sv) {
	printf(" %20s \t %10s \t %2d/%d/%d \t %6.2f \t %6.2f \t %10s", sv.ten, sv.gioitinh, sv.ngaysinh.ngay, sv.ngaysinh.thang, sv.ngaysinh.nam, sv.diemdv, sv.dtl, sv.quequan);
}
void printf_listsv(SV ds[], int n) {
	printf("%15s \t %10s \t %10s \t %10s \t %6s \t %6s \t ", "Ten", "Gioi Tinh", "Ngay Sinh", "Diem dv", "Diem tl", "Que Quan");
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf_sv(ds[i]);
		printf("\n");
	}
}