#include <stdio.h>;
#include <conio.h>;
#include <math.h>;
int main()
{
double x1,x2,e,costab,cospro,om,di,x,n,dx,xprob;
int er1,er2,er3,er4;
do{
    do
        {
        printf("Enter X1\n");
        er1=scanf("%lf",&x1);
        fflush(stdin);
        if (er1!=1)
        {
            printf("Error\n");
        }
        }
        while(er1!=1);


        do
        {
        printf("Enter X2>X1\n");
        er2=scanf("%lf",&x2);
        fflush(stdin);
        if (er2!=1||x2<x1)
        {
            printf("Error\n");
        }
        }
        while(er2!=1||x2<x1);


        do
        {
        printf("Enter dx\n");
        er3=scanf("%lf",&dx);
        fflush(stdin);
        if (er3!=1||dx<=0)
        {
            printf("Error\n");
        }
        }
        while(er3!=1||dx<=0);


        do
        {
        printf("Enter e(1e-5 - 0.1)\n");
        er4=scanf("%lf",&e);
        fflush(stdin);
        if (er4!=1||e<1e-5||e>0.2)
        {
            printf("Error\n");
        }
        }
        while(er4!=1||e<1e-5||e>0.2);
do
{
    costab=cos(x1*M_PI/180);
    om=n=cospro=1;
    do
    {
        om*=-pow((x1*M_PI/180),2)/(2*n*(2*n-1));
        cospro=cospro+om;
        n++;
    }
    while(fabs(om)>=e);
    di=costab-cospro;
    printf("x=%lf | cos(tabl)=%lf | cos(program)=%lf | difference=%lf |\n", x1,costab,cospro,di);
    if (fabs(x1-x2)< 0.00001 || fabs(x1-x2)==0)
    {
        x1=x2;
    }
    x1=x1+dx;
}
while(x1<=x2);
printf("Press any key to continue or ESC to exit\n");
}while (getch()!=27);
return 0;
}
