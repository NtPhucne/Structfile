#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include"Data.h"
#include"Modify.h"
#include"get_input.h"
#include"printf_out.h"
#include"Search.h"
void search_byname(SV ds[], int n, char ten[])
{
	for (int i = 0; i < n; i++) {
		if (strstr(ds[i].ten, ten)) {
			printf("Sinh vien can tim la: \n");
			printf_sv(ds[i]);
			printf("\n");
		}

	}

}



int search_bysex(SV ds[], int n, char gioitinh[])
{
	for (int i = 0; i < n; i++) {
		if (strstr(ds[i].gioitinh, gioitinh)) {
			printf("Sinh vien can tim la: \n");
			printf_sv(ds[i]);
		}
	}
	return 0;
}

void search_bypoint(SV ds[], int n, float diem) {

	for (int i = 0; i < n; i++) {
		if (ds[i].diemdv >= diem) {
			printf("Sinh vien can tim la: \n");
			printf_sv(ds[i]);
		}
	}
}