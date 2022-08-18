#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include"Data.h"
#include"Modify.h"
#include"get_input.h"
#include"printf_out.h"
#include"File_in_out.h"
void get_File(SV ds[], int& n) {
	char tenFile[100];
	char readnewline[10];
	fgets(readnewline, sizeof(readnewline), stdin); // line nay de xoa /n khi nhap scanf 
	printf("\nNhap vao duong dan va ten file: ");
	fflush(stdin); fgets(tenFile, sizeof(tenFile), stdin); xoaXuongDong(tenFile);

	FILE* f;
	f = fopen(tenFile, "rb");
	if (f == NULL) {
		printf("\nLoi mo file de doc!");
		return;
	}
	fread(&n, sizeof(n), 1, f);
	for (int i = 0; i < n; i++) {
		fread(&ds[i], sizeof(SV), 1, f);
	}
	fclose(f);
}
void set_File(SV ds[], int n) {
	char tenFile[100];
	char readnewline[10];
	fgets(readnewline, sizeof(readnewline), stdin); // line nay de xoa /n khi nhap scanf 
	printf("\nNhap vao duong dan va ten file: ");
	fflush(stdin); fgets(tenFile, sizeof(tenFile), stdin); xoaXuongDong(tenFile);

	FILE* f;
	f = fopen(tenFile, "wb");
	if (f == NULL) {
		printf("\nLoi moi file de ghi!");
		return;
	}
	fwrite(&n, sizeof(n), 1, f);
	for (int i = 0; i < n; i++) {
		fwrite(&ds[i], sizeof(SV), 1, f);
	}
	fclose(f);

}
