#include <stdio.h>;
#include <conio.h>;
#include <stdlib.h>;
#include <math.h>;
#include <malloc.h>;

int main()
{
    double **matrixa, *matrixb, *x, *xp, eps, delta,sum;
    int n,er;
    char c;
    do{
        do
        {
        printf("Enter amount of elements\n");
        er=scanf("%d%c",&n,&c);
        fflush(stdin);
        if (er!=2||n<1||c!=10)
        {
            printf("Error\n");
        }
        }
        while(er!=2||n<1||c!=10);
    matrixa = (double **) calloc (n, sizeof (double *));

    for (int i=0; i<n; i++)
        matrixa[i] = (double *) calloc (n, sizeof (double));

    matrixb = (double **) calloc (n, sizeof (double *));
    x = (double **) calloc (n, sizeof (double *));
    xp = (double **) calloc (n, sizeof (double *));


    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)
    {
        do
        {
        printf("Koef[%d][%d]:",i+1,j+1);
        er=scanf("%lf%c",&matrixa[i][j],&c);
        fflush(stdin);
        if (er!=2||c!=10)
        {
            printf("Error\n");
        }
        }
        while(er!=2||c!=10);
    }

    sum=0;
    for(int k=0;k<n;k++){
				if(i!=k)
					sum+=matrixa[i][k];
			}
			if(fabs(matrixa[i][i])<=fabs(sum)){
				printf("Koef(%d,%d) must be bigger than sum"
					   " of any other koef in the line\nPlease enter the line again\n", i+1, i+1);
				i--;
			}
    }

    printf("Enter the free elements: \n");
		for(int i=0;i<n;i++){
        do{
        printf("Element[%d]:",i+1);
        er=scanf("%lf%c",&matrixb[i],&c);
        fflush(stdin);
        if (er!=2||c!=10)
        {
            printf("Error\n");
        }
        }while(er!=2||c!=10);
		}

		do
        {
        printf("Enter eps(1e-4 - 0.1)\n");
        er=scanf("%lf%c",&eps,&c);
        fflush(stdin);
        if (er!=2||eps<1e-5||eps>0.2||c!=10)
        {
            printf("Error\n");
        }
        }
        while(er!=2||eps<1e-5||eps>0.2||c!=10);

		do{
			for(int i=0;i<n;i++){
				xp[i]=0;

				delta = 0;

				for(int j=0;j<n;j++){
					if(i!=j)
						xp[i]+=matrixa[i][j]*x[j];
				}

				xp[i] = (matrixb[i]-xp[i])/matrixa[i][i];

				if(fabs(x[i] - xp[i]) > delta)
					delta = fabs(x[i] - xp[i]);

				x[i] = xp[i];
			}
		}while(delta>=eps);

		for(int i=0;i<n;i++)
			free(matrixa[i]);
		free(matrixa);
		free(matrixb);
		free(xp);

		printf("\nSolutions of the system:\n");
		for (int i = 0;i<n;i++)
			printf("x[%d] = %lf\n",i+1,x[i]);

		free(x);
    printf("Press any key to continue or ESC to exit\n");
    }while(getch()!=27);
    return 0;
}
