#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

mpz_t a,s,N;
unsigned long  i,k,b,n;

void P(mpz_t p , unsigned long m , mpz_t x){
mpz_t p0,p1;
unsigned long l;

mpz_set_ui(p,4);
mpz_init_set_ui(p0,2);
mpz_init_set(p1,x);
l=2;

while(l<=m)
{
mpz_mul(p,x,p1);
mpz_sub(p,p,p0);
mpz_set(p0,p1);
mpz_set(p1,p);
l=l+1;
}

}

int main(void)
{

mpz_t r,r1,r2;

printf("Enter the coefficient :");
scanf("%lu",&k);
printf("Enter the base :");
scanf("%lu",&b);
printf("Enter the exponent :");
scanf("%lu",&n);

mpz_init(r);
mpz_init(r1);
mpz_init(r2);
mpz_init(a);

mpz_set_ui(a,4);
P(r1,b/2,a);
P(r2,k*b/2,r1);
mpz_init_set(s,r2);

mpz_init(N);
mpz_ui_pow_ui(N,b,n);
mpz_mul_ui(N,N,k);
mpz_sub_ui(N,N,1);

for (i = 1; i <= n-2; i++)
{
P(r,b,s);
mpz_mod(s,r,N);
}
mpz_clear(N);
if(mpz_cmp_ui(s,0)==0)
{
printf("%lu*%lu^%lu-1 is prime\n" , k,b,n);
}
else
{
printf("%lu*%lu^%lu-1 is composite\n" , k,b,n); 
}
mpz_clear(s);
return 0;
}