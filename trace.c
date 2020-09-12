#include <stdio.h> 

#define WRITE 0
int main() {
	FILE *f = fopen("seqw.ascii", "w");
	for (int i = 0; i < 100; ++i) {
		int time, device, lpn, len, op;
		time = i;
		device = 0;
		lpn = i * 8;
		len = 8; //sector:
		op = WRITE;
		fprintf(f, "%d,%d,%d,%d,%d\n", time, device, lpn, len, op);
	}
	fclose(f);
}
