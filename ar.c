#include <stdio.h>

long int func(long int n, long int p);
int impar(long int n);
void loop();

int main(){

	loop();
	return 0;
}

void loop(){
	long int n;
	scanf("%ld", &n);
	if (n != 0){
		printf("%ld\n", func(n,1));
		return loop();
	}
	return;
}
long int func(long int n, long int p){
	if (n == 0) return 0;
	int a = n%10;
	return a*(2+impar(a))*p + func(n/10,p+1);
}
int impar(long int n){
	return (n%2 != 0);
}
