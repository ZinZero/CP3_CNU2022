#include <stdio.h>

void func(char w, int x, double y, char *z){

    w = 'z';
    printf("%c %d %f %s\n", w, x, y, z);
}


void main(){
		char c;
		int n1 = 50;
		double d = 77.777;
		char *str = "C Programming";

		func(c, n1, d, str);

}