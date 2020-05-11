#include<stdio.h>
#include<stdlib.h>

struct _retire_info
{int month;
  double contribution,rate_of_return;
};
typedef struct _retire_info retire_info;

double compute(double i, double r, double c)
{i=i*r+c;
  return i;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired)
{int n,rn,i;
  int  m,rm;
  double balance=initial;
  n=(int)startAge/12;
  m =(int) (((float)startAge/12 - n)*12);
  for(i=1;i<=working.month;i++)
    {printf("Age %3d month %2d you have $%.2lf\n",n,m,balance);
      balance+=compute(balance,working.rate_of_return,working.contribution);
	m++;
      if(m>11)
	{m=0;
	  n++;
	  initial=balance;}}
  rm=m;
  rn=n;
  initial = initial +(initial*0.01*12);
  for (i=1;i<=retired.month;i++)
    {printf("Age %3d month %2d you have $%.2lf\n",rn,rm,balance);
    balance+=compute(balance,retired.rate_of_return,retired.contribution);
	rm++;
      if(rm>11)
	{rm=0;
	  rn++;
	  initial=balance;}}
}

int main()
{retire_info working1, retired1;
  int startAge1;
  double initial1;
  working1.month = 489;
  working1.contribution = 1000;
  working1.rate_of_return = 0.045/12;
  retired1.month = 384;
  retired1.contribution = -4000;
  retired1.rate_of_return = 0.01/12;
  startAge1 = 327;
  initial1 = 21345;
  retirement(startAge1,initial1,working1,retired1);
  return 0;
}
