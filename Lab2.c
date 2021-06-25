#include <stdio.h>;
#include <conio.h>;
#include <math.h>;
#include <stdlib.h>;

int main()
{
float a,b,c;
do {
setlocale(LC_ID,"Rus");
system("cls"); //очистить экран
printf("Enter sides of the triangle\n");
int off=scanf("%f%f%f", &a, &b, &c);//ввод
if (a+b<=c|| b+c<=a || a+c<=b||off!=3||a<=0||b<=0||c<=0)//проверка на треугольник и на корректность данных
 {
 printf("It isn't a triangle\nPress any key to begin");
 }
else
{
float p,pp,ha,hb,hc,ma,mb,mc,ba,bb,bc;
p=(a+b+c);//периметр
pp=p/2;//полупериметр
double s=sqrt(pp*(pp-a)*(pp-b)*(pp-c));//площадь
ha=2*s/a;
hb=2*s/b;
hc=2*s/c;
ma=sqrt(2*b*b+2*c*c-a*a)/2;
mb=sqrt(2*a*a+2*c*c-b*b)/2;;
mc=sqrt(2*b*b+2*a*a-c*c)/2;;
ba=2*(sqrt(b*c*pp*(pp-a)))/(b+c);
bb=2*(sqrt(a*c*pp*(pp-b)))/(a+c);
bc=2*(sqrt(b*a*pp*(pp-c)))/(b+a);
printf("Area of triangle:""%f\n",s);
printf("Perimeter of triangle:""%f\n",p);
printf("Height to a:""%f\n",ha);
printf("Height to b:""%f\n",hb);
printf("Height to c:""%f\n",hc);
printf("Median to a:""%f\n",ma);
printf("Median to b:""%f\n",mb);
printf("Median to c:""%f\n",mc);
printf("Bisector to a:""%f\n",ba);
printf("Bisector to b:""%f\n",bb);
printf("Bisector to c:""%f\n",bc);
printf("Press any key to restart or ESC to exit");
}
} while (getch()!=27);
return 0;
}

