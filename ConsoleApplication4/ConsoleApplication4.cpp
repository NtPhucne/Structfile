#include <stdio.h>
#include <string.h>
#include <conio.h>
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
///
void nhapSinhVien(SV& sv);
void xoaXuongDong(char x[]);
void inSinhVien(SV sv);
void nhapdanhsachsv(SV ds[], int& n);
void capNhatSinhVien(SV& sv);
int add_student(SV ds[], int& n);
void getany();
void xuatDanhSachSinhVien(SV ds[], int n);

void sapXepDanhSachSinhVienTheoTen(SV ds[], int n);
int searchbyname(SV ds[], int n, char ten[]);
void sapXepDanhSachSinhVienTheodtl(SV ds[], int n);
void sapXepDanhSachSinhVienTheoddv(SV ds[], int n);
void searchbypoint(SV ds[], int n, float diem);
int searchbysex(SV ds[], int n, char gioitinh[]);
int xoaSinhVienTheostt(SV ds[], int& n, int stt);
void set_File(SV ds[], int n);
void get_File(SV ds[], int& n);
//////////////////////////
void xoaXuongDong(char x[]) {
	size_t len = strlen(x);
	if (x[len - 1] == '\n') {
		x[len - 1] = '\0';
	}
}

void nhapSinhVien(SV& sv) {
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
void inSinhVien(SV sv) {
	printf(" %20s \t %10s \t %2d/%d/%d \t %6.2f \t %6.2f \t %10s", sv.ten, sv.gioitinh, sv.ngaysinh.ngay, sv.ngaysinh.thang, sv.ngaysinh.nam, sv.diemdv, sv.dtl, sv.quequan);
}
int searchbyname(SV ds[], int n, char ten[])
{
	for (int i = 0; i < n; i++) {
		if (strstr(ds[i].ten, ten)) {
			printf("Sinh vien can tim la: \n");
			inSinhVien(ds[i]);
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
void capNhatSinhVien(SV ds[]) {
	int i;
	printf("Nhap stt cua sinh vien muon update");
	printf("stt : %d", &i);
	nhapSinhVien(ds[i]);
}
void xuatDanhSachSinhVien(SV ds[], int n) {
	printf("%15s \t %10s \t %10s \t %10s \t %6s \t %6s \t %10s", "Ten", "Gioi Tinh", "Ngay Sinh", "Diem dv", "Diem tl", "Que Quan");
	printf("\n");
	for (int i = 0; i < n; i++) {
		inSinhVien(ds[i]);
		printf("\n");
	}
}

int searchbysex(SV ds[], int n, char gioitinh[])
{
	for (int i = 0; i < n; i++) {
		if (strstr(ds[i].gioitinh, gioitinh)) {
			printf("Sinh vien can tim la: \n");
			inSinhVien(ds[i]);
		}
	}
	return 0;
}
void sapXepDanhSachSinhVienTheodtl(SV ds[], int n) {
	for (int i = 0; i < n ; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ds[i].dtl > ds[j].dtl) {
				SV temp;
				temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
}
void sapXepDanhSachSinhVienTheoddv(SV ds[], int n) {
	for (int i = 0; i < n ; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ds[i].diemdv > ds[j].diemdv) {
				SV temp;
				temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
}
void sapXepDanhSachSinhVienTheoTen(SV ds[], int n) {
	SV tmp;
	char tenSV1[30];
	char tenSV2[30];
	for (int i = 0; i < n; i++) {
		strcpy(tenSV1, a[i].ten);
		for (int j = i + 1; j < n; j++) {
			strcpy(tenSV2, a[j].ten);
			if (strcmp(strupr(tenSV1), strupr(tenSV2)) > 0) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}
void searchbypoint(SV ds[], int n, float diem) {

	for (int i = 0; i < n; i++) {
		if (ds[i].diemdv >= diem) {
			printf("Sinh vien can tim la: \n");
			inSinhVien(ds[i]);
		}
	}
}
void getany() {
	printf("\nNhap cai gi do di cuc cung ");
	_getch();
}
int xoaSinhVienTheostt(SV ds[], int& n, int stt) {
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
int add_student(SV ds[], int& n) {
	SV sv_add;

	printf("Nhap thong tin sinh vien muon them");
	nhapSinhVien(sv_add);
	n = n + 1;
	ds[n - 1] = sv_add;
	return n;
	/*ds[n] = sv_add;*/

}

int main() {
	//printf("%15s \t %10s \t %10s \t %10s \t %6s \t %6s \t %10s", "Ten", "Gioi Tinh", "Ngay Sinh", "Diem dv", "Diem tl", "Que Quan");
	SV ds[100]; int n; float diem; int chon;

	/*do {
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
		printf("\n0- Thoat\n");
		scanf("%d", &chon);
		switch (chon) {
		case 1:
			printf("Nhap so luong sinh vien");
			nhapdanhsachsv(ds, n);

			break;
		case 2:
			xuatDanhSachSinhVien(ds, n);
			break;
		case 3:
			printf("\nDanh sach theo Dtl\n");
			printf("Nhap diem san`");
			scanf("%d", &diem);
			searchbypoint(ds, n, diem);

			break;
		case 4:
			char tensv[20];
			char readnewline[10];
			fgets(readnewline, sizeof(readnewline), stdin);
			printf("\nNhap ten sinh vien can tim: "); fflush(stdin); fgets(tensv, sizeof(tensv), stdin); xoaXuongDong(tensv);
			searchbyname(ds, n, tensv);
			break;
		case 5:
			int stt;
			printf("\nNhap stt can xoa"); scanf("%d", &stt);
			xoaSinhVienTheostt(ds, n, stt);
			printf("\nDanh sach sau khi xoa\n");
			xuatDanhSachSinhVien(ds, n);

			break;
		case 6:
			add_student(ds, n);

			break;
		case 7:
			sapXepDanhSachSinhVienTheoddv(ds, n);
			printf("Danh sach sau khi xep la\n");
			xuatDanhSachSinhVien(ds, n);
			break;
		case 8:
			sapXepDanhSachSinhVienTheodtl(ds, n);
			printf("Danh sach sau khi xep la\n");
			xuatDanhSachSinhVien(ds, n);

			break;
		case 9:
			sapXepDanhSachSinhVienTheoTen(ds, n);
			printf("Danh sach sau khi xep la\n");
			xuatDanhSachSinhVien(ds, n);

			break;
		case 10:
			get_File(ds, n);

			break;
		case 11:
			set_File(ds, n);

			break;
		case 0:
			break;



		}
	} while (chon != 0);
	*/
	nhapdanhsachsv(ds, n);
	xuatDanhSachSinhVien(ds, n);
	sapXepDanhSachSinhVienTheoTen(ds, n);
	printf("Danh sach sau khi xep la\n");
	xuatDanhSachSinhVien(ds, n);
}
