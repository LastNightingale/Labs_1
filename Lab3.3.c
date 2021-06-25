#include <stdio.h>;
#include <conio.h>;
#include <math.h>;
int main()
{
    float a,b,c,y1,y2,y3,x1,x2,x3,p,q,d;
do
{ int er1,er2,er3;
    do
        {
        printf("Enter A\n");
        er1=scanf("%f",&a);
        if (er1!=1)
        {
            fflush(stdin);
            printf("Error\n");
        }
        }
        while(er1!=1);
        do
        {
        printf("Enter B\n");
        er2=scanf("%f",&b);
        if (er2!=1)
        {
            fflush(stdin);
            printf("Error\n");
        }
        }
        while(er2!=1);
        do
        {
        printf("Enter C\n");
        er3=scanf("%f",&c);
        if (er3!=1)
        {
            fflush(stdin);
            printf("Error\n");
        }
        }
        while(er3!=1);

p= b-(powf(a,2)/3);
q=((2*powf(a,3))/27-((a*b))/3+c);
d=powf(p,3)/27+powf(q,2)/4;
if (d==0)
    {
        if (a==0&&b==0&&c==0) x1=x2=x3=0;
        else{
        y1=3*q/p;
        y3=y2=-1*3*q/(2*p);
        x1=y1-(a/3);
        x2=x3=y2-(a/3);
        }
        printf("%f\n", x1);
        printf("%f\n", x2);
        printf("%f\n", x3);

    }
if (d<0)
    {
        float r=sqrt(-1*pow(p,3)/27);
        float fi=acos(-1*q/(2*r));
        y1=2*fabsf(cbrtf(r))*cos(fi/3);
        y2=2*fabsf(cbrtf(r))*cos((fi+2*M_PI)/3.);
        y3=2*fabsf(cbrtf(r))*cos((fi+4*M_PI)/3.);
        x1=y1-(a/3);
        x2=y2-(a/3);
        x3=y3-(a/3);
        printf("%f\n", x1);
        printf("%f\n", x2);
        printf("%f\n", x3);
    }
if (d>0)
    {
        float ut=-q/2+sqrt(d);
        float u=(ut>0)?( powf(ut,1/3.)):(powf(fabs(ut),1/3.)*-1);
        float v=-1*p/(3*u);
        y1=u+v;
        y2=-1*y1/2;
        y3=sqrt(3)*(u-v)/2;
        x1=y1-(a/3);
        x2=y2-(a/3);
        printf("%f\n", x1);
        printf("%f+i*%f\n", x2, y3);
        printf("%f-i*%f\n", x2, y3);
    }
    printf("Press any key to continue or ESC to exit\n\n");
}
while (getch()!=27);
return 0;
}
