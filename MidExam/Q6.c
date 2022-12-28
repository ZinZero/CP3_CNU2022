#include <stdio.h>
int main(){
	char carr[3] = {'A','B','C'};
	char *cp = carr;

	printf("%c %c %c", carr[0],carr[1],carr[2]);
	printf("%c %c %c", *(carr),*(carr+1),*(carr+2));
	printf("%c %c %c", cp[0],cp[1],cp[2]);
	printf("%c %c %c", *cp,*(cp+1),*(cp+2));
}