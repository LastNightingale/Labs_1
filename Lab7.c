#include <stdio.h>;
#include <conio.h>;
#include <stdlib.h>;
#include <math.h>;

double fun1(double x, double t)
{
    return(cos(t / x) - 2 * sin(1 / x) + (1 / x));
}
double fun2(double x, double t)
{
    return(sin(log(x)) - cos(log(x)) + t * log(x));
}
double entering();
double (*fun)(double,double);
char s,met;
double a1,a2,eps,t,x,delta,dy,dx,temp;
int main()
{
    do
    {
printf("Choose equation\n1 - cos(t/x)-2*sin(1/x)+1/x=0\n2 - sin(lnx)+cos(lnx)+t*lnx=0\n");
do
s=getch();
while (s<'1'||s>'2');

if (s=='1') fun=fun1;
if (s=='2') fun=fun2;

printf("Choose method\n1 - Hald-division method\n2 - Newton method\n");
do
met=getch();
while (met<'1'||met>'2');

do{
printf("Enter a1(from -10 to 10,a1!=0)\n");
a1=entering();
if (a1<-10||a1>10||a1==0) printf("Try again!\n");
}while(a1<-10||a1>10||a1==0);


do{
printf("Enter a2(from -10 to 10,a2-a1<=2,a2>a1,a2!=0)\n");
a2=entering();
if (a2<-10||a2>10||(a2-a1)>2||a2<a1||a2==0) printf("Try again!\n");
}while(a2<-10||a2>10||(a2-a1)>2||a2<a1||a2==0);

printf("Enter t\n");
t=entering();

do{
printf("Enter epsilon(from 1e-6 to 1e-1)\n");
eps=entering();
if (eps<1e-6||eps>1) printf("Try again!\n");
}while(eps<1e-6||eps>1);

if (met=='1')
{
    do
    {
        x=(a1+a2)/2;
        temp=fun(x,t)*fun(a1,t);
        if (temp>0) a1=x;
        else a2=x;
    }
    while((fabs(a2-a1))>eps);
}
if (met=='2')
{
    x=a2;
    do
    {
        dy=(fun(x+0.099,t)+fun(x,t))/0.099;
        dx=fun(x,t);
        delta=dx/dy;
        x=x-delta;

    }
    while(fabs(delta)>eps);
}
if (x<a1||x>a2||fabs(fun(x,t))>0.001) printf("It is wrong data\n");
else printf("x= %lf\n",x);
printf("Press any key to continue or ESC to exit\n");
    }
    while (getch()!=27);


}




double entering(double k)
{
    char c;
    int er;
    do
        {
        er=scanf("%lf%c",&k,&c);
        fflush(stdin);
        if (er!=2||c!=10)
        {
            printf("Error\nPlease enter again\n");
        }
        }
        while(er!=2||c!=10);
        return k;
}
