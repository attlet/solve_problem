#include<stdio.h>


int main() {
	int n, num,count = 0,i;
	int start = 666;
	int check;
	scanf("%d", &n);

	
	for (i = 666; count != n ; i++) {
		num = i;
		check = 0;
		
		while (num > 0) {
			if (num % 1000 == 666) {
				check = 1;
				break;
			}
			num /= 10;
		}
		if (check) count++;
	   
	}
	printf("%d", i-1);
	
}
