#include <stdio.h>
#include <stdlib.h>

#include "../src/noyau.h"

void aff (void) {
	affic_queue();
	affic_file();
	printf("\n");
}

int main (void) {
	printf("init\n");
	file_init();
	aff();
	printf("suivant\n");
	printf("ret = %d\n", suivant());
	aff();
	printf("ajoute 5, 2, 4\n");
	ajoute(5);
	ajoute(2);
	ajoute(4);
	aff();
	printf("suivant\n");
	printf("ret = %d\n", suivant());
	aff();
	printf("suivant\n");
	printf("ret = %d\n", suivant());
	aff();
	printf("retire 0\n");
	retire(0);
	aff();
	printf("retire 2\n");
	retire(2);
	aff();
	printf("retire 5\n");
	retire(5);
	aff();
	printf("ajoute 1\n");
	ajoute(1);
	aff();
	return 0;
}
