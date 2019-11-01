#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
	int num[3],dig2[10],digit,i=0,power,arm;
	char ans='y';
	while(ans=='y')
	{
		clrscr();
		digit=0,power=0,arm=0;
		printf("\nARMSTRONG CHECK");
		printf("\n\nEnter a number (less than 32767) : ");
		scanf("%d",&num[0]);
		//check=arm_check(num[0]);
		if(num[0]>=0 && num[0]<=32766)
		{
			num[1]=num[0];
			num[2]=num[1];
			for(i=0;i<=num[0];i++)
			{
				if(num[0]/10!=0)
				{
					digit++;
				}
				num[0]=num[0]/10;
			}
			digit++;
			printf("\nNo. of digits in %d is : %d\n",num[2],digit);
			for(i=0;i<digit;i++)
			{
				num[0]=num[1]%10;
				num[1]=num[1]/10;
				power=pow(num[0],digit);
				arm+=power;
				dig2[i]=power;
				printf("\n\nDigit %d = %d",i+1,num[0]);
				printf("\t-- After raising to the power %d = %d",digit,power);
			}
			if(arm==num[2])
			{
				printf("\n\nAdding ");
				for(i=0;i<digit-1;i++)
				{
					printf("%d + ",dig2[i]);
				}
				printf("%d = %d = Entered value(%d)",dig2[digit-1],arm,num[2]);
				printf("\n\n\nTherefore, %d is ARMSTRONG",num[2]);
			}
			else
			{
				printf("\n\nAdding ");
				for(i=0;i<digit-1;i++)
				{
					printf("%d + ",dig2[i]);
				}
				printf("%d = %d != %d (Entered value)",dig2[digit-1],arm,num[2]);
				printf("\n\n\nTherefore, %d is NOT ARMSTRONG",num[2]);
			}
		}
		else
		{
			printf("\n\nThe number you entered is out of scope.");
			getch();
		}
		printf("\n\nWant to enter again(y/n) : ");
		scanf("%s",&ans);
	}
	return 0;
}