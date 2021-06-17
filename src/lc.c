#include <lc.h>

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int min(int a, int b) {
	if (a < b) return a;
	else return b;
}

int abs(int i) {
	return (i < 0) ? -i : i;
}
/*
double pow(double c, int p) {
	double in = c;

	// algorightm might fail on these
	// algorithm
	if(p == 1) return c;
	if(p == 0) return 1;
	if(p == -1) return 0-c;

	for(int i; i < abs(p); i++) {
		if(in > 1) c*=c;
		if(in < 0) c/=c;
	}

	return c;
}

void kitoa(int32_t i, char* str) {

	//char str[11];

	for (uint8_t i = 0; i < 10; i++) {
		str[i] = '0';
	}

	if (i < 0) str[0] = '-';

	uint8_t pos = 0;
	while (abs(i) >= 1) {
		uint8_t digit = i % 10;
		i /= 10;
		str[10 - pos] = digit + 48;
		pos++;
	}

	//char* truncated_str = truncate_leading_zeros(str, 11);

	//return truncated_str;
}
*/