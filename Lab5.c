#include <stdio.h>;
#include <conio.h>;
#include <string.h>;

int main()
{
    int amount,er;
    char *c;
    do{
        do
        {
        printf("Enter amount of elements\n");
        er=scanf("%d",&amount);
        fflush(stdin);
        if (er!=1||amount<2)
        {
            printf("Error\n");
        }
        }
        while(er!=1||amount<2);

        char list[amount][64];
        char *addr[amount];

        for (int i=0;i<amount;i++)
        {
            printf("Enter element %d (<=64 symbols)\n",i+1);
            fgets(list[i],64,stdin);
            fflush(stdin);
        }
        for(int i=0; i<amount; i++) addr[i]=list[i];



        for(int a=0;a<amount-1;a++)
        {
        for(int b=a+1;b<amount;b++)
        {
        if(strcmp(addr[a],addr[b])>0)
        //swap(&addr[a],&addr[b]);
        {
            c=addr[a];
            addr[a]=addr[b];
            addr[b]=c;
        }
        }
        }
        printf("Sorted elements:\n");
        for (int i=0;i<amount;i++)
        {
            printf("%s",addr[i]);
        }
        printf("\nPress any key to continue or ESC to exit\n");
        }while(getch()!=27);
        return 0;
}
