#include"Data.h"
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void sort_bydtl(SV ds[], int n) {
	for (int i = 0; i < n; i++) {
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
void sort_byddv(SV ds[], int n) {
	for (int i = 0; i < n; i++) {
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
void sort_byname(SV ds[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(_strupr(ds[i].ten), _strupr(ds[j].ten)) > 0) {
				SV temp;
				temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
}