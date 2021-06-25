#include <stdio.h>;
#include <math.h>;
#include <conio.h>;


int main()
{
    float x,e,y,yk,om;
    int er1,er2,er3,k,usl1,usl2,chot;
    do
    {
        y=om=1.0;
        usl1=usl2=1;

        do
        {
        printf("Enter X\n");
        er1=scanf("%f",&x);
        fflush(stdin);
        if (er1!=1)
        {
            fflush(stdin);
            printf("Error\n");
        }
        }
        while(er1!=1);


        do
        {
        printf("Enter K(only integer)\n");
        er2=scanf("%d",&k);
        fflush(stdin);
        if (er2!=1||k==0)
        {
            printf("Error\n");
        }
        }
        while(er2!=1||k==0);


        do
        {
        printf("Enter E(from 1e-5 to 1)\n");
        er3=scanf("%f",&e);
        fflush(stdin);
        if (er3!=1||e<1e-5||e>1)
        {
            printf("Error\n");
        }
        }
        while(er3!=1||e<1e-5||e>1);


        chot=k%2;
        if(k>0)
        {
            if ((chot==0)&&(x<0))
            {
                usl1=0;
            }
        }
        if(k<0)
        {
            if ((chot==0)&&(x<=0)||(chot!=0&&x==0))
            {
                usl2=0;
            }
        }


        if(usl2==0||usl1==0)
        {
            printf("Incorrect data\nEnter your numbers again\n");
            continue;
        }
        else{
            if (x==0) y=0;
        else{

        do
        {
            om=(x/pow(y,(k-1))-y)*1.0/k;
            y+=om;
        }
        while(fabs(om)>=e);
        }
        printf("Result=%f\nEnter ESC to exit or any key to continue\n",y);
        }

    }while(getch()!=27);
    return 0;
}
