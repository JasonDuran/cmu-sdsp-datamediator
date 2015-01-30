//============================================================================
// Name        : CMU-SDSP-DATAMEDIATOR.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("Hello World!!!");
	int bvv =0;
	for(int cnt=0;cnt<100;cnt++){
		if(cnt > 1) cnt++;
		if(bvv > 1) bvv++;
		bvv++;
		if(bvv < 50) bvv++;
		if(bvv < 50) bvv=bvv-1;
		if(bvv > 10) bvv++;
		if(bvv < 50) bvv++;
		if(bvv < 50) bvv=bvv-1;
		if(bvv > 10) bvv++;
		if(bvv < 50) bvv++;
		if(bvv < 50) bvv=bvv-1;
		if(bvv > 10) bvv++;
	}
	return EXIT_SUCCESS;
}
