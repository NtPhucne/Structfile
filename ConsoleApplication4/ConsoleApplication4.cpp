#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include"Data.h"
#include"get_input.h"
#include"Sort.h"
#include"Modify.h"
#include"printf_out.h"
#include"File_in_out.h"
#include"Search.h"
void getany();

//////////////////////////





void getany() {
	printf("\nNhap cai gi do di cuc cung ");
	_getch();
}




int main() {
	//printf("%15s \t %10s \t %10s \t %10s \t %6s \t %6s \t %10s", "Ten", "Gioi Tinh", "Ngay Sinh", "Diem dv", "Diem tl", "Que Quan");
	SV ds[100]; int n; float diem; int chon; char readnewline[10];

	do {
		printf("\nMENU:");
		printf("\n1- Nhap danh sach sinh vien");
		printf("\n2- Xuat danh sach sinh vien");
		printf("\n3- Tim theo diem san`");
		printf("\n4- Tim sinh vien theo ten");
		printf("\n5- Xoa sinh vien theo Stt");
		printf("\n6- Them sinh vien vao danh sach");
		printf("\n7- Sap xep sinh vien theo ddv");
		printf("\n8- Sap xep sinh vien theo dtl");
		printf("\n9- Sap xep sinh vien theo ten");
		printf("\n10- Lay thong tin sinh vien tu file");
		printf("\n11- Luu thong tin sinh vien vao file");
		printf("\n12- UpdateSv");
		printf("\n0- Thoat\n");
		scanf("%d", &chon);
		switch (chon) {
		case 1:
			printf("Nhap so luong sinh vien");
			get_listsv(ds, n);

			break;
		case 2:
			printf_listsv(ds, n);
			break;
		case 3:
			printf("\nDanh sach theo Dtl\n");
			printf("Nhap diem san`");
			scanf("%d", &diem);
			search_bypoint(ds, n, diem);

			break;
		case 4:
			char tensv[20];
			char readnewline[10];
			fgets(readnewline, sizeof(readnewline), stdin);
			printf("\nNhap ten sinh vien can tim: "); fflush(stdin); fgets(tensv, sizeof(tensv), stdin); xoaXuongDong(tensv);
			search_byname(ds, n, tensv);
			break;
		case 5:
			int stt;
			printf("\nNhap stt can xoa"); scanf("%d", &stt);
			fgets(readnewline, sizeof(readnewline), stdin);
			del_svbySTT(ds, n, stt);
			printf("\nDanh sach sau khi xoa\n");
			printf_listsv(ds, n);
			break;
		case 6:
			add_student(ds, n);
			break;
		case 7:
			sort_byddv(ds, n);
			printf("Danh sach sau khi xep la\n");
			printf_listsv(ds, n);
			break;
		case 8:
			sort_bydtl(ds, n);
			printf("Danh sach sau khi xep la\n");
			printf_listsv(ds, n);

			break;
		case 9:
			sort_byname(ds, n);
			printf("Danh sach sau khi xep la\n");
			printf_listsv(ds, n);

			break;
		case 10:
			get_File(ds, n);

			break;
		case 11:
			set_File(ds, n);

			break;
		case 12:
			update_sv(ds);
		case 0:
			break;



		}
	} while (chon != 0);
	
	
}
