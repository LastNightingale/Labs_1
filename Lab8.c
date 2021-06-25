#include <stdio.h>;
#include <conio.h>;
#include <stdlib.h>;
#include <math.h>;

typedef struct
    {
        double s,f;
    } complex;

double entering();
double R1, R2, C, L, fmn, fmx, df, f0, a, b, c, d,w,R;

int s=0,er;
char ch,symb;


int main()
{
    complex comp;


do{
printf("Choose a circuit: from 1 to 4\n");
do
{
    symb=getch();
}
while(symb<'1'||symb>'4');

if(symb=='1'||symb=='2')
{
    printf("Enter R\n");
    R=entering();
}
else
{
    printf("Enter R1\n");
    R1=entering();
    printf("Enter R2\n");
    R2=entering();
}

printf("Enter L\n");
L=entering();
printf("Enter C\n");
C=entering();
printf("Enter Fmin\n");
fmn=entering();
printf("Enter Fmax\n");
fmx=entering();
printf("Enter df\n");
df=entering();
f0=1/(2*M_PI*sqrt(L*C));
printf("f0= %lf\n",f0);

for(;fmn<=fmx;fmn=fmn+df){
w=2*M_PI*fmn;
switch(symb){
case '1':
    a=L/C;
    b=-R/(w*C);
    c=R;
    d=w*L-1/(w*C);
    break;
case '2':
    a=L/C;
    b=R/(w*C);
    c=R;
    d=w*L-1/(w*C);
    break;
case '3':
    a=R1*R2;
    b=R1*(w*L-1/(w*C));
    c=R1+R2;
    d=w*L-1/(w*C);
    break;
case '4':
    a=R1*R2+L/C;
    b=w*L*R1-R2/(w*C);
    c=R1+R2;
    d=w*L-1/(w*C);
    break;
}
comp.f = (a*c + b*d)/(c*c + d*d);
comp.s = (b*c - a*d)/(c*c + d*d);
printf("f= %lf\tZ= %e + i*%lf\n", fmn,comp.f, comp.s );}

printf("Press any key to continue or ESC to exit\n");
}while(getch()!=27);
return 0;
}

double entering(double k)
{
    char c;
    int er;
    do
        {
        er=scanf("%lf%c",&k,&c);
        fflush(stdin);
        if (er!=2||c!=10||k<0)
        {
            printf("Error\n");
        }
        }
        while(er!=2||c!=10||k<0);
        return k;
}





