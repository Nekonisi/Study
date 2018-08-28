#pragma once

typedef struct{
	char name[16];
	char kind[32];
	union {
		double time;
		int rank;
	} record;
}DATA, *LPDATA;