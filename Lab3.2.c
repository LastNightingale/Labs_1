#include <stdio.h>;
#include <math.h>;
#include <locale.h>;

int y,m,d,v,n,res,dan,yearr,monthh,v,n,dan=1;

int main()
{
do {
yearr=monthh=1;
printf("Enter date using '.'\n");
scanf("%d.%d.%d", &d, &m, &y);
if ((y%100!=0&&y%4==0)||(y%100==0&&y%400==0))
    {
        v=1;
    }
    else {
        v=0;
    }

    if (m>2)
    {
        n=0;
    }
    if (m<=2&&v==1)
    {
        n=1;
    }
    if (m<=2&&v==0)
    {
        n=2;
    }


    switch (m)
{
case 1:
case 3:
case 4:
case 7:
case 8:
case 10:
case 12: if (d>31)
{
    dan=0;
}
case 2: if((v==1&&d>29)||(v==0&&d>28))
{
    dan=0;
}
case 5:
case 6:
case 9:
case 11: if (d>30)
{
    dan=0;
}
}


if (d<1||m<1||y<1000||dan==0||m>12||y>9999)//вывести ошибку
{
    printf("Error\nPress any key to continue or ESC to exit\n\n");
}
else
{

yearr=trunc(365.25*y);
monthh=trunc(30.56*m);
res=(yearr+monthh+d+n)%7;
switch(res)
{
case 0:
    printf("Monday\n");
    break;
case 1:
    printf("Tuesday\n");
    break;
case 2:
    printf("Wednesday\n");
    break;
case 3:
    printf("Thursday\n");
    break;
case 4:
    printf("Friday\n");
    break;
case 5:
    printf("Saturday\n");
    break;
case 6:
    printf("Sunday\n");
    break;
}
printf("Press any key to continue or ESC to exit\n\n");
}
}
while (getch()!=27);
return 0;
}
