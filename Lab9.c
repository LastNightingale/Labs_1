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
    printf("Виберіть з чим ви будете працювати\n1.Файл\n2.Запис\n3.Вийти\n");
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
    printf("ESC щоб повернутися\nВиберіть що ви хочете зробити\n1.Створити файл\n2.Прочитати файл\n3.Видалити файл\n");
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
                printf("Натисніть ESC щоб повернутися назад, або будь-яку клавішу щоб продовжити\n");
            }
            while (getch()!=27);
            menufile();
            break;
        case '2':
            do
            {
                readrecord();
                printf("Натисніть ESC щоб повернутися назад, або будь-яку клавішу щоб продовжити\n");
            }
            while (getch()!=27);
            menufile();
            break;
        case '3':
            do
            {
                removef();
                printf("Натисніть ESC щоб повернутися назад, або будь-яку клавішу щоб продовжити\n");
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
    printf("ESC щоб повернутися\nВиберіть що ви хочете зробити\n1.Створити запис\n2.Прочитати записи\n3.Видалити запис\n4.Відсортувати записи\n5.Додати запис із сортуванням\n6.Редагувати запис\n");
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
            printf("Натисніть ESC щоб повернутися назад, або будь-яку клавішу щоб продовжити\n");
            }while (getch()!=27);
            menurecord();
            break;
        case '3':
            do{
            removerecord();
            printf("Натисніть ESC щоб повернутися назад, або будь-яку клавішу щоб продовжити\n");
            }while (getch()!=27);
            menurecord();
            break;
        case '4':
            sortrecord();
            printf("Натисніть ESC щоб повернутися назад, або будь-яку клавішу щоб продовжити\n");
            getch();
            menurecord();
            break;
        case '5':
            do{
            addsortrecord();
            printf("Натисніть ESC щоб повернутися назад, або будь-яку клавішу щоб продовжити\n");
            }while (getch()!=27);
            menurecord();
            break;
        case '6':
            do{
            editrecord();
            printf("Натисніть ESC щоб повернутися назад, або будь-яку клавішу щоб продовжити\n");
            }while (getch()!=27);
            menurecord();
        }
    }
}

void openf()
{
    FILE *fil;
    printf("Введите ім'я файлу:\n");
    char name[16];
    fgets(name,LEN,stdin);
    get_char(name);
    fflush(stdin);
    fil=fopen(name, "w");
    fprintf(fil,"%s",SIGN);
    fclose(fil);
    printf("Файл створений\n");
}

void removef()
{
    FILE *fil;
    printf ("Назва видаляємого файлу:\n");
    char name[16];
    fgets(name,LEN,stdin);
    get_char(name);
    fflush(stdin);
    fil=fopen(name,"r");
    if (fil==NULL) {printf("Файлу з таким іменем не існує\n");}
    else
    {
    fscanf(fil,"%s\n",&sig);
        if(strcmp(sig, SIGN)!=0)
        {
            printf("Файл не цієї програми.Натисніть будь-яку клавішу\n");
            fclose(fil);
            getch();
            menufile();
        }
        fclose(fil);
        printf("%s\n",name);
        v=remove(name);
         if (v!=0)
         {
             printf ("Помилка\n");
             }
   else
   {
      printf ("Файл видалено\n");
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
    printf ("Введіть ім'я файлу до якого хочете додати запис:\n");
    char name[16];
    fgets(name,LEN,stdin);
    get_char(name);
    fflush(stdin);
    fil=fopen(name, "a");
     if (fil==NULL) {printf("Файлу з такою назвою не існує\n");}
    else
    {
        fscanf(fil,"%s\n",&sig);
        //printf("%s\n",sig);
        if(strcmp(sig, SIGN)!=0)
        {
            printf("Файл не цієї програми\n");
            getch();
            menurecord();
        }

    do
    {
        region reg;
        do{
        printf("Назва:\n");
        fgets(reg.nname,16,stdin);
        get_char(reg.nname);
        fflush(stdin);
        }while(strlen(reg.nname)<2);
        printf("Площа:\n");
        do
        {
        er=scanf("%lf%c",&reg.square,&c);
        fflush(stdin);
        if (er!=2||c!=10||reg.square<=0||reg.square>1e5)
        {
            printf("Ви ввели невірні дані.Повторіть ввод, будь-ласка\n");
        }
        }
        while(er!=2||c!=10||reg.square<=0||reg.square>1e5);

        printf("Населення:\n");
        do
        {
        er=scanf("%d%c",&reg.peop,&c);
        fflush(stdin);
        if (er!=2||c!=10||reg.peop<0||reg.peop>1e5)
        {
            printf("Ви ввели невірні дані.Повторіть ввод, будь-ласка\n");
        }
        }
        while(er!=2||c!=10||reg.peop<0||reg.peop>1e5);

        fprintf(fil, "%s %lf %d\n", reg.nname, reg.square, reg.peop);
        printf("Натисніть ESC щоб повернутися назад, або будь-яку клавішу щоб продовжити\n");
    }
    while (getch()!=27);
    fclose(fil);
    }
}



void removerecord()
{
    FILE *fil;
    printf ("Введіть ім'я файлу, звідки видалити запис:\n");
    char name[16];
    fgets(name,LEN,stdin);
    get_char(name);
    fflush(stdin);
    fil=fopen(name, "r");
   if (fil==NULL) {printf("Файлу з такою назвою не існує\n");}
    else
    {   fscanf(fil,"%s\n",&sig);
        //printf("help");
        if(strcmp(sig, SIGN)!=0)
        {
            printf("Файл не цієї програми\n");
            fclose(fil);
            getch();
            menurecord();
        }
        count=getamount(fil);
        if (count==0) printf("Файл не має записів\n");
        else{
        int numb;
        do
        {
        printf("Введіть номер запису, який хочете видалити\n");
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
    printf ("Введіть ім'я файлу:\n");
    char name[16];
    fgets(name,LEN,stdin);
    get_char(name);
    fflush(stdin);
    fil=fopen(name, "r");
    if (fil==NULL) {printf("Файлу з такою назвою не існує\n");}
    else{
            fscanf(fil,"%s\n",&sig);
        if(strcmp(sig, SIGN)!= 0)
        {
            printf("Файл не цієї програми");
            fclose(fil);
            getch();
            menurecord();
        }
        count=getamount(fil);
        if (count==0) {printf("Файл пустий\n");}
        else{
        int n=0;
        fseek(fil, 4, SEEK_SET);
        region reg;
       while(fscanf(fil,"%s %lf %d\n", &reg.nname, &reg.square, &reg.peop)!=EOF)
    {
        givechar(reg.nname);
		n++;
		printf("Запис номер %d\nНазва:%s\nПлоща:%lf\nНаселення:%d\n\n", n, reg.nname, reg.square, reg.peop);
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
    printf ("Введіть ім'я файлу:\n");
    char name[16];
    fgets(name,LEN,stdin);
    get_char(name);
    fflush(stdin);
    fil=fopen(name, "r");
    if (fil==NULL) {printf("Файлу з таким іменем не існує\n");}
    else
    {
        fscanf(fil,"%s\n",&sig);
        if(strcmp(sig, SIGN)!= 0)
        {
            printf("Файл не цієї програми");
            fclose(fil);
            getch();
            menurecord();
        }
        count=getamount(fil);
        if (count==0) printf("Файл не має записів\n");
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
            printf("Виберіть за яким параметром ви хочете сортувати:\n1.Назва\n2.Площа\n3.Населення\n");
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
		printf("Виберіть як ви хочете сортувати\n1.За зростанням\n2.За спадом\n");
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
    printf ("Введіть ім'я файлу, куди додати запис:\n");
    char name[16];
    fgets(name,LEN,stdin);
    get_char(name);
    fflush(stdin);
    fil=fopen(name, "r");
    if (fil==NULL) {printf("Файлу з таким іменем не існує\n");}
    else
    {
        fscanf(fil,"%s\n",&sig);
        if(strcmp(sig, SIGN)!= 0)
        {
            printf("Файл не цієї програми");
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
		printf("Назва:\n");
        fgets(reg[l].nname,16,stdin);
        get_char(reg[l].nname);
        fflush(stdin);
        }while(strlen(reg[l].nname)<2);

        printf("Площа:\n");
        do
        {
        er=scanf("%lf",&reg[l].square);
        fflush(stdin);
        if (er!=1||reg[l].square<0||reg[l].square>1e5)
        {
            printf("Ви ввели невірні дані.Повторіть ввод, будь-ласка\n");
        }
        }
        while(er!=1||reg[l].square<0||reg[l].square>1e5);

        printf("Населення:\n");
        do
        {
        er=scanf("%d",&reg[l].peop);
        fflush(stdin);
        if (er!=1||reg[count].peop<0||reg[l].peop>1e5)
        {
            printf("Ви ввели невірні дані.Повторіть ввод, будь-ласка\n");
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
    printf ("Введіть ім'я файлу, де редагувати запис:\n");
    char name[16];
    fgets(name,LEN,stdin);
    get_char(name);
    fflush(stdin);
    fil=fopen(name, "r");
    if (fil==NULL) {printf("Файлу з таким іменем не існує\n");}
    else
    {
        fscanf(fil,"%s\n",&sig);
        if(strcmp(sig, SIGN)!= 0)
        {
            printf("Файл не цієї програми");
            fclose(fil);
            getch();
            menurecord();
        }
        count=getamount(fil);
        if (count==0) printf("Файл не має записів\n");
        else{
        printf("%d\n",count);
        int numb;
        do
        {
        printf("Введіть номер запису, який хочете редагувати\n");
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
        printf("Назва:\n");
        fgets(reg[i].nname,16,stdin);
        get_char(reg[i].nname);

        printf("Площа:\n");
        do
        {
        er=scanf("%lf%c",&reg[i].square,&c);
        fflush(stdin);
        if (er!=2||c!=10||reg[i].square<0||reg[l].square>1e5)
        {
            printf("Ви ввели невірні дані\n");
        }
        }
        while(er!=2||c!=10||reg[i].peop<0||reg[l].square>1e5);

        printf("Населення:\n");
        do
        {
        er=scanf("%d%c",&reg[i].peop,&c);
        fflush(stdin);
        if (er!=2||c!=10||reg[i].peop<0||reg[l].peop>1e5)
        {
            printf("Ви ввели невірні дані\n");
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

