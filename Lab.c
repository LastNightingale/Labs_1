#include <stdio.h>;
#include <conio.h>;

roman(int i,int j,char c)//������� ��� ������ �������
{ while (i>=j)
  {  putchar(c);//����� ��������� �������
     i=i-j;
  }
return(i);
}

main(){
printf("Enter number from 1 to 3999\n");
int a;
 scanf("%d",&a); //���� �����
 if (a>3999||a<=0) {   //�������� �� ����������
    printf("Error");
    getch();
    return 0;
 }
   a=roman(a,1000,'M');
   a=roman(a,500,'D');
   a=roman(a,100,'C');
   a=roman(a,50,'L');
   a=roman(a,10,'X');
   a=roman(a,5,'V');
   a=roman(a,1,'I');
   getch();
return 0;
}
