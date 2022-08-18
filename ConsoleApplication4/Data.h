#ifndef _DATA_H_

#define _DATA_H_

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

#endif