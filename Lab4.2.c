#include <stdio.h>;
#include <conio.h>;
#include <math.h>;

int main()
{
    int colvo,er,er1,vibor,err;
    float array[50];
    do{
    printf("Enter the amount of elements in array(2-50)\n");
    do
        {
        er1=scanf("%d",&colvo);
        fflush(stdin);
        if (er1!=1||colvo<1||colvo>50)
        {
            printf("Error\n");
        }
        }
        while(er1!=1||colvo<1||colvo>50);

    for (int i=0;i<=colvo-1;i++)
    {
        do
        {
        printf("Enter the %d element of array(-1e10 - 1e10)\n",i+1);
        er=scanf("%f",&array[i]);
        fflush(stdin);
        if (er!=1||array[i]<-1e10||array[i]>1e10)
        {
            printf("Error\n");
        }
        }
        while(er!=1||array[i]<-1e10||array[i]>1e10);

    }


    float t;
    for(int a=0;a<colvo-1;a++)
    {
    for(int b=a+1;b<colvo;b++)
        if(array[a]>array[b])
        {
            t=array[a];
            array[a]=array[b];
            array[b]=t;
        }
    }
    do{
    printf("Enter 1 to sort in ascending order or -1 to sort in descending order\n");
    err=scanf("%d",&vibor);
    fflush(stdin);
    if (err!=1||(vibor!=1&&vibor!=-1)) printf("Error");
    }while(err!=1||(vibor!=1&&vibor!=-1));

    if (vibor==1)
    {
        for (int j=0;j<=colvo-1;j++)
    {
        printf("%e\n",array[j]);
    }

    }
    if (vibor==-1)
    {
        for (int j=colvo-1;j>=0;j--)
    {
        printf("%f\n",array[j]);
    }

    }
    printf("Press any key to continue or ESC to exit\n");
    }while (getch()!=27);
}
