#include <stdio.h>;
#include <conio.h>;
#include <stdlib.h>;
#include <math.h>;
#include <malloc.h>;
#include <Windows.h>;
#include <string.h>;
#define SIGN "SIGN"
#define LEN 16
void menu();
char choseone,chosetwo,sym;
void menufile();
int i;
int count;
char c;
int er;
char sig[5];
int v;
typedef struct
    {
        char nname[16];
        double square;
        int peop;
    } region;


int main()
{
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    menu();

}


void menu()
{
    system("cls");
    printf("������� � ��� �� ������ ���������\n1.����\n2.�����\n3.�����\n");
    do
    {
        sym=getch();
    }
    while(sym<'1'||sym>'3');
    system("cls");
    switch(sym)
    {
    case '3':
        return 0;
    case '1':
    menufile();
    break;
    case '2':
    menurecord();
    break;

    }
}


void menufile()
{
    system("cls");
    printf("ESC ��� �����������\n������� �� �� ������ �������\n1.�������� ����\n2.��������� ����\n3.�������� ����\n");
        do
    {
        choseone=getch();
    }
    while((choseone<'1'||choseone>'3')&&choseone!=27);
    system("cls");
    if (choseone==27) menu();
    else
    {
        switch(choseone)
        {
        case '1':
            do
            {
                openf();
                printf("�������� ESC ��� ����������� �����, ��� ����-��� ������ ��� ����������\n");
            }
            while (getch()!=27);
            menufile();
            break;
        case '2':
            do
            {
                readrecord();
                printf("�������� ESC ��� ����������� �����, ��� ����-��� ������ ��� ����������\n");
            }
            while (getch()!=27);
            menufile();
            break;
        case '3':
            do
            {
                removef();
                printf("�������� ESC ��� ����������� �����, ��� ����-��� ������ ��� ����������\n");
            }
            while (getch()!=27);
            menufile();
            break;
        }
    }
}


void menurecord()
{
    system("cls");
    printf("ESC ��� �����������\n������� �� �� ������ �������\n1.�������� �����\n2.��������� ������\n3.�������� �����\n4.³���������� ������\n5.������ ����� �� �����������\n6.���������� �����\n");
        do
    {
        chosetwo=getch();
    }
    while((chosetwo<'1'||chosetwo>'6')&&chosetwo!=27);
    system("cls");
    if (chosetwo==27) menu();
    else
    {
        switch(chosetwo)
        {
        case '1':
            addrecord();
            menurecord();
            break;
        case '2':
            do{
            readrecord();
            printf("�������� ESC ��� ����������� �����, ��� ����-��� ������ ��� ����������\n");
            }while (getch()!=27);
            menurecord();
            break;
        case '3':
            do{
            removerecord();
            printf("�������� ESC ��� ����������� �����, ��� ����-��� ������ ��� ����������\n");
            }while (getch()!=27);
            menurecord();
            break;
        case '4':
            sortrecord();
            printf("�������� ESC ��� ����������� �����, ��� ����-��� ������ ��� ����������\n");
            getch();
            menurecord();
            break;
        case '5':
            do{
            addsortrecord();
            printf("�������� ESC ��� ����������� �����, ��� ����-��� ������ ��� ����������\n");
            }while (getch()!=27);
            menurecord();
            break;
        case '6':
            do{
            editrecord();
            printf("�������� ESC ��� ����������� �����, ��� ����-��� ������ ��� ����������\n");
            }while (getch()!=27);
            menurecord();
        }
    }
}

void openf()
{
    FILE *fil;
    printf("������� ��'� �����:\n");
    char name[16];
    fgets(name,LEN,stdin);
    get_char(name);
    fflush(stdin);
    fil=fopen(name, "w");
    fprintf(fil,"%s",SIGN);
    fclose(fil);
    printf("���� ���������\n");
}

void removef()
{
    FILE *fil;
    printf ("����� ����������� �����:\n");
    char name[16];
    fgets(name,LEN,stdin);
    get_char(name);
    fflush(stdin);
    fil=fopen(name,"r");
    if (fil==NULL) {printf("����� � ����� ������ �� ����\n");}
    else
    {
    fscanf(fil,"%s\n",&sig);
        if(strcmp(sig, SIGN)!=0)
        {
            printf("���� �� ���� ��������.�������� ����-��� ������\n");
            fclose(fil);
            getch();
            menufile();
        }
        fclose(fil);
        printf("%s\n",name);
        v=remove(name);
         if (v!=0)
         {
             printf ("�������\n");
             }
   else
   {
      printf ("���� ��������\n");
   }
    }
}


void get_char(char *name)
{

    for (int i=0;i<strlen(name);i++)
    {
        if (name[i]==' ') name [i]='_';

        if (name[i]=='\n') name[i]='\0';
    }
}

void addrecord()
{
    FILE *fil;
    printf ("������ ��'� ����� �� ����� ������ ������ �����:\n");
    char name[16];
    fgets(name,LEN,stdin);
    get_char(name);
    fflush(stdin);
    fil=fopen(name, "a");
     if (fil==NULL) {printf("����� � ����� ������ �� ����\n");}
    else
    {
        fscanf(fil,"%s\n",&sig);
        //printf("%s\n",sig);
        if(strcmp(sig, SIGN)!=0)
        {
            printf("���� �� ���� ��������\n");
            getch();
            menurecord();
        }

    do
    {
        region reg;
        do{
        printf("�����:\n");
        fgets(reg.nname,16,stdin);
        get_char(reg.nname);
        fflush(stdin);
        }while(strlen(reg.nname)<2);
        printf("�����:\n");
        do
        {
        er=scanf("%lf%c",&reg.square,&c);
        fflush(stdin);
        if (er!=2||c!=10||reg.square<=0||reg.square>1e5)
        {
            printf("�� ����� ����� ���.�������� ����, ����-�����\n");
        }
        }
        while(er!=2||c!=10||reg.square<=0||reg.square>1e5);

        printf("���������:\n");
        do
        {
        er=scanf("%d%c",&reg.peop,&c);
        fflush(stdin);
        if (er!=2||c!=10||reg.peop<0||reg.peop>1e5)
        {
            printf("�� ����� ����� ���.�������� ����, ����-�����\n");
        }
        }
        while(er!=2||c!=10||reg.peop<0||reg.peop>1e5);

        fprintf(fil, "%s %lf %d\n", reg.nname, reg.square, reg.peop);
        printf("�������� ESC ��� ����������� �����, ��� ����-��� ������ ��� ����������\n");
    }
    while (getch()!=27);
    fclose(fil);
    }
}



void removerecord()
{
    FILE *fil;
    printf ("������ ��'� �����, ����� �������� �����:\n");
    char name[16];
    fgets(name,LEN,stdin);
    get_char(name);
    fflush(stdin);
    fil=fopen(name, "r");
   if (fil==NULL) {printf("����� � ����� ������ �� ����\n");}
    else
    {   fscanf(fil,"%s\n",&sig);
        //printf("help");
        if(strcmp(sig, SIGN)!=0)
        {
            printf("���� �� ���� ��������\n");
            fclose(fil);
            getch();
            menurecord();
        }
        count=getamount(fil);
        if (count==0) printf("���� �� �� ������\n");
        else{
        int numb;
        do
        {
        printf("������ ����� ������, ���� ������ ��������\n");
        er=scanf("%d%c",&numb,&c);
        fflush(stdin);
        if (er!=2||c!=10||numb<=0||numb>count)
        {
            printf("Error\n");
        }
        }
        while (er!=2||c!=10||numb<=0||numb>count);
        region reg[count];
        fseek(fil, 4, SEEK_SET);
        int l=0;
        while(!feof(fil)){
            l++;
			fscanf(fil, "%s %lf %d\n", reg[l-1].nname, &reg[l-1].square, &reg[l-1].peop);
		}
		fclose(fil);
		fil=fopen(name, "w");
		fprintf(fil,"%s\n",SIGN);
		for(int i=0;i<count;i++){
			if(i!=numb-1)
				fprintf(fil, "%s %lf %d\n", reg[i].nname, reg[i].square, reg[i].peop);
		}
		fclose(fil);
    }
    }
}

void readrecord()
{
    FILE *fil;
    printf ("������ ��'� �����:\n");
    char name[16];
    fgets(name,LEN,stdin);
    get_char(name);
    fflush(stdin);
    fil=fopen(name, "r");
    if (fil==NULL) {printf("����� � ����� ������ �� ����\n");}
    else{
            fscanf(fil,"%s\n",&sig);
        if(strcmp(sig, SIGN)!= 0)
        {
            printf("���� �� ���� ��������");
            fclose(fil);
            getch();
            menurecord();
        }
        count=getamount(fil);
        if (count==0) {printf("���� ������\n");}
        else{
        int n=0;
        fseek(fil, 4, SEEK_SET);
        region reg;
       while(fscanf(fil,"%s %lf %d\n", &reg.nname, &reg.square, &reg.peop)!=EOF)
    {
        givechar(reg.nname);
		n++;
		printf("����� ����� %d\n�����:%s\n�����:%lf\n���������:%d\n\n", n, reg.nname, reg.square, reg.peop);
    }
    }
    }
    fclose(fil);

}


int getamount(FILE *fil)
{
    int k;
    k=0;
    //fscanf("%s",&sig);
    while(!feof(fil))
    {
		k++;
		region reg;
		fscanf(fil,"%s %lf %d\n", &reg.nname, &reg.square, &reg.peop);
		//printf("%d\t%s11\t%lf\t%d\n", k, reg.nname, reg.square, reg.peop);
	}
	return k;
}


void sortrecord()
{
    FILE *fil;
    printf ("������ ��'� �����:\n");
    char name[16];
    fgets(name,LEN,stdin);
    get_char(name);
    fflush(stdin);
    fil=fopen(name, "r");
    if (fil==NULL) {printf("����� � ����� ������ �� ����\n");}
    else
    {
        fscanf(fil,"%s\n",&sig);
        if(strcmp(sig, SIGN)!= 0)
        {
            printf("���� �� ���� ��������");
            fclose(fil);
            getch();
            menurecord();
        }
        count=getamount(fil);
        if (count==0) printf("���� �� �� ������\n");
        else
        {
            region reg[count];
            fseek(fil, 4, SEEK_SET);
        int l=0;
        while(!feof(fil)){
            l++;
			fscanf(fil, "%s %lf %d\n", &reg[l-1].nname, &reg[l-1].square, &reg[l-1].peop);
			//printf("%s %lf %d\n",reg[l-1].nname, reg[l-1].square, reg[l-1].peop);
		}
            char s;
            printf("������� �� ���� ���������� �� ������ ���������:\n1.�����\n2.�����\n3.���������\n");
               do
               {
                   s=getch();
               }
               while (s<'1'||s>'3');
               switch (s)
               {
               case '1':
                for (int i=0;i<count-1;i++)
                {
                    for(int j=i+1;j<count;j++)
                    {
                    if (strcmp(reg[i].nname,reg[j].nname)<0)
                    {
                       swap(&reg[i].nname,&reg[j].nname);
                       double b;
                       int c;
                       b=reg[i].square;
                       reg[i].square=reg[j].square;
                       reg[j].square=b;
                       c=reg[i].peop;
                       reg[i].peop=reg[j].peop;
                       reg[j].peop=c;
                    }
                    }
                }
                break;
               case '2':
                for (int i=0;i<count-1;i++)
                {
                    for(int j=i+1;j<count;j++)
                    {
                    if (reg[i].square>reg[j].square)
                    {
                        swap(&reg[i].nname,&reg[j].nname);
                       double b;
                       int c;
                       b=reg[i].square;
                       reg[i].square=reg[j].square;
                       reg[j].square=b;
                       c=reg[i].peop;
                       reg[i].peop=reg[j].peop;
                       reg[j].peop=c;
                    }
                    }
                }
                break;
                case '3':
                  for (int i=0;i<count-1;i++)
                {
                    for(int j=i+1;j<count;j++)
                    {
                    if (reg[i].peop>reg[j].peop)
                    {
                        swap(&reg[i].nname,&reg[j].nname);
                       double b;
                       int c;
                       b=reg[i].square;
                       reg[i].square=reg[j].square;
                       reg[j].square=b;
                       c=reg[i].peop;
                       reg[i].peop=reg[j].peop;
                       reg[j].peop=c;
                    }
                    }
                }
                break;
               }
        fclose(fil);
		fil=fopen(name, "w");
		fprintf(fil,"%s\n",SIGN);
		printf("������� �� �� ������ ���������\n1.�� ����������\n2.�� ������\n");
		char sy;
		do
        {
            sy=getch();
        }
        while(sy<'1'||sy>'2');
        //fseek(fil, 0, SEEK_SET);
        switch(sy)
            {
            case '1':
            for(int i=0;i<count;i++){
				fprintf(fil,"%s %lf %d\n", reg[i].nname, reg[i].square, reg[i].peop);
		}
		break;
       case '2':
            for(int i=count-1;i>=0;i--)
        {
                fprintf(fil,"%s %lf %d\n", reg[i].nname, reg[i].square, reg[i].peop);
		}
		break;
        }
        fclose(fil);
        fil=fopen("Choose","w");
        fprintf(fil,"%c %c",s,sy);
        fclose(fil);
        }
		}
    }

void swap(char **nname, char **nnamee)
{
    char *a;
    a=*nname;
    *nname=*nnamee;
    *nnamee=a;
}

void addsortrecord()
{
    FILE *fil;
    printf ("������ ��'� �����, ���� ������ �����:\n");
    char name[16];
    fgets(name,LEN,stdin);
    get_char(name);
    fflush(stdin);
    fil=fopen(name, "r");
    if (fil==NULL) {printf("����� � ����� ������ �� ����\n");}
    else
    {
        fscanf(fil,"%s\n",&sig);
        if(strcmp(sig, SIGN)!= 0)
        {
            printf("���� �� ���� ��������");
            fclose(fil);
            getch();
            menurecord();
        }
        count=getamount(fil);
        region reg[count+1];
        fseek(fil, 4, SEEK_SET);
        int l=0;
        while(!feof(fil)){
            l++;
			fscanf(fil, "%s %lf %d\n", &reg[l-1].nname, &reg[l-1].square, &reg[l-1].peop);
		}
		do{
		printf("�����:\n");
        fgets(reg[l].nname,16,stdin);
        get_char(reg[l].nname);
        fflush(stdin);
        }while(strlen(reg[l].nname)<2);

        printf("�����:\n");
        do
        {
        er=scanf("%lf",&reg[l].square);
        fflush(stdin);
        if (er!=1||reg[l].square<0||reg[l].square>1e5)
        {
            printf("�� ����� ����� ���.�������� ����, ����-�����\n");
        }
        }
        while(er!=1||reg[l].square<0||reg[l].square>1e5);

        printf("���������:\n");
        do
        {
        er=scanf("%d",&reg[l].peop);
        fflush(stdin);
        if (er!=1||reg[count].peop<0||reg[l].peop>1e5)
        {
            printf("�� ����� ����� ���.�������� ����, ����-�����\n");
        }
        }
        while(er!=1||reg[count].peop<0||reg[l].peop>1e5);
		fclose(fil);
		char s,sy;
		fil=fopen("Choose","r");
		fscanf(fil,"%c %c",&s,&sy);
		fclose(fil);
		fil=fopen(name, "w");
		fprintf(fil,"%s\n",SIGN);
        count=count+1;
		switch (s)
               {
               case '1':
                for (int i=0;i<count-1;i++)
                {
                    for(int j=i+1;j<count;j++)
                    {
                    if (strcmp(reg[i].nname,reg[j].nname)<0)
                    {
                       swap(&reg[i].nname,&reg[j].nname);
                       double b;
                       int c;
                       b=reg[i].square;
                       reg[i].square=reg[j].square;
                       reg[j].square=b;
                       c=reg[i].peop;
                       reg[i].peop=reg[j].peop;
                       reg[j].peop=c;
                    }
                    }
                }
                break;
               case '2':
                for (int i=0;i<count-1;i++)
                {
                    for(int j=i+1;j<count;j++)
                    {
                    if (reg[i].square>reg[j].square)
                    {
                        swap(&reg[i].nname,&reg[j].nname);
                       double b;
                       int c;
                       b=reg[i].square;
                       reg[i].square=reg[j].square;
                       reg[j].square=b;
                       c=reg[i].peop;
                       reg[i].peop=reg[j].peop;
                       reg[j].peop=c;
                    }
                    }
                }
                break;
                case '3':
                  for (int i=0;i<count-1;i++)
                {
                    for(int j=i+1;j<count;j++)
                    {
                    if (reg[i].peop>reg[j].peop)
                    {
                        swap(&reg[i].nname,&reg[j].nname);
                       double b;
                       int c;
                       b=reg[i].square;
                       reg[i].square=reg[j].square;
                       reg[j].square=b;
                       c=reg[i].peop;
                       reg[i].peop=reg[j].peop;
                       reg[j].peop=c;
                    }
                    }
                }
                break;
               }
        switch(sy)
            {
            case '1':
            for(int i=0;i<count;i++){
				fprintf(fil,"%s %lf %d\n", reg[i].nname, reg[i].square, reg[i].peop);
		}
		break;
       case '2':
            for(int i=count-1;i>=0;i--)
        {
                fprintf(fil,"%s %lf %d\n", reg[i].nname, reg[i].square, reg[i].peop);
		}
		break;
        }
        fclose(fil);
}
}

void editrecord()
{
    FILE *fil;
    printf ("������ ��'� �����, �� ���������� �����:\n");
    char name[16];
    fgets(name,LEN,stdin);
    get_char(name);
    fflush(stdin);
    fil=fopen(name, "r");
    if (fil==NULL) {printf("����� � ����� ������ �� ����\n");}
    else
    {
        fscanf(fil,"%s\n",&sig);
        if(strcmp(sig, SIGN)!= 0)
        {
            printf("���� �� ���� ��������");
            fclose(fil);
            getch();
            menurecord();
        }
        count=getamount(fil);
        if (count==0) printf("���� �� �� ������\n");
        else{
        printf("%d\n",count);
        int numb;
        do
        {
        printf("������ ����� ������, ���� ������ ����������\n");
        er=scanf("%d%c",&numb,&c);
        fflush(stdin);
        if (er!=2||c!=10||numb<=0||numb>count)
        {
            printf("Error\n");
        }
        }
        while (er!=2||c!=10||numb<=0||numb>count);
        region reg[count];
        fseek(fil, 4, SEEK_SET);
        int l=0;
        while(!feof(fil)){
            l++;
			fscanf(fil, "%s %lf %d\n", reg[l-1].nname, &reg[l-1].square, &reg[l-1].peop);
		}
		fclose(fil);
		fil=fopen(name, "w");
		fprintf(fil,"%s\n",SIGN);
		for(int i=0;i<count;i++){
        if(i==numb-1){
        printf("�����:\n");
        fgets(reg[i].nname,16,stdin);
        get_char(reg[i].nname);

        printf("�����:\n");
        do
        {
        er=scanf("%lf%c",&reg[i].square,&c);
        fflush(stdin);
        if (er!=2||c!=10||reg[i].square<0||reg[l].square>1e5)
        {
            printf("�� ����� ����� ���\n");
        }
        }
        while(er!=2||c!=10||reg[i].peop<0||reg[l].square>1e5);

        printf("���������:\n");
        do
        {
        er=scanf("%d%c",&reg[i].peop,&c);
        fflush(stdin);
        if (er!=2||c!=10||reg[i].peop<0||reg[l].peop>1e5)
        {
            printf("�� ����� ����� ���\n");
        }
        }
        while(er!=2||c!=10||reg[i].peop<0||reg[l].peop>1e5);
        }
		fprintf(fil, "%s %lf %d\n", reg[i].nname, reg[i].square, reg[i].peop);
    }
    fclose(fil);
    }
}
}


void givechar(char *name)
{
    for (int i=0;i<strlen(name);i++)
    {
        if (name[i]=='_') name [i]=' ';
    }
}

