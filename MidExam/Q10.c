# include <stdio.h>
int main() {
	char *str = "ABCDEFG";
    
  str[0] = 'z';
  str[1] = 'z';

  printf("%c %c\n",str[0],str[1]);
  
	return 0;
}