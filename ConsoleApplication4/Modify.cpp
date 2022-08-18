#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include"Data.h"
#include"Modify.h"
#include"get_input.h"
#include"printf_out.h"
int add_student(SV ds[], int& n) {
	SV sv_add;

	printf("Nhap thong tin sinh vien muon them");
	get_sv(sv_add);
	n = n + 1;
	ds[n - 1] = sv_add;
	printf("Sinh vien vua them :\n");
	printf_sv(ds[n - 1]);
	return n;
	/*ds[n] = sv_add;*/

}
int del_svbySTT(SV ds[], int& n, int stt) {

	for (int i = 0; i < n; i++) {
		if (i == stt) {
			for (int j = i; j < n; j++) {
				ds[j] = ds[j + 1];
			}
			n -= 1;
			return n;

		}
	}
}
void update_sv(SV ds[]) {
	int i;
	printf("Nhap stt cua sinh vien muon update");
	printf("stt : %d", &i);
	get_sv(ds[i]);
}