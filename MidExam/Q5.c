#include <stdio.h>
int *func(){
	static int n;
	scanf("%d",&n);
	return &n;
}

int main(){
	int *ip;

	ip = func();
	printf("%d\n",*ip);
	return 0;
}