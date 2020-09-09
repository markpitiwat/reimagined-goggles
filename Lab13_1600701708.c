/*****************************************************************	**/
/* AUTHOR	    :	Pitiwat Sathaporntaweewat    	*/
/* ID		    :	1-60-07-0170-8	*/
/* SECTION	    :	1451	*/
/* Std. No.     :	21	*/
/* COURSE	    :	CS310 Computer Programming                      	*/
/* INSTRUCTOR   :	A.Sirinthorn Cheyasak                           	*/
/* TUTOR	    :	A.Sirinthorn Cheyasak                           	*/
/* DATE    	    :	November 20, 2017	*/
/* LAB NUMBER   :	13	*/
/* DESCRIPTION  :	This program is use function to calculate the answer with num1,num2 and operate */
/*               	by keybord or textfile							*/
/*****************************************************************	*/
#include<stdio.h>
void menu()
{
	printf("==================================================\n");
	printf("+  List of menu                                  +\n");
	printf("+  1.Calculator (get integers from keybord)      +\n");
	printf("+  2.Calculator (get integers from integer file) +\n");
	printf("+  3.Exit program                                +\n");
	printf("==================================================\n");
}
int calculate(int num1,int num2,char ope)
{
	int ans;
	if(ope=='+')
	{
		ans=num1+num2;
		return(ans);
	}
	else if(ope=='-')
	{
		ans=num1-num2;
		return(ans);
	}
	else if(ope=='*')
	{
		ans=num1*num2;
		return(ans);
	}
	else if(ope=='/')
	{
		ans=num1/num2;
		return(ans);
	}
	else if(ope=='%')
	{
		ans=num1%num2;
		return(ans);
	}
}//function

int main()//main
{
	int select,num1=0,num2=0,ans=0,count=0,i=0;
	char ope;
	FILE *inf;
	inf=fopen("list.txt","r");
	menu();
	while(select!=3)
	{
	printf("\nPlease select menu: ");
	scanf("%d",&select);
		if(select==1)//start select1
		{
		printf("Enter number 1: ");
		scanf("%d",&num1);
		printf("Enter number 2: ");
		scanf("%d",&num2);
		printf("Enter an operator(+,-,*,/,%): ");
		scanf(" %c",&ope);
		ans=calculate(num1,num2,ope);
		printf("the answer is %d",ans);
		}//end select1
		
		else if(select==2)//start select2
		{
			printf("\nList of all transactions\n");
			printf("========================\n");
			fscanf(inf,"%d%c%d",&num1,&ope,&num2);
			while(!feof(inf))
			{
				i++;
				printf("Transaction#%d: Num1=%d,Num2=%d\n",i,num1,num2);
				ans=calculate(num1,num2,ope);
				printf("The answer is %d\n",ans);
			fscanf(inf,"%d%c%d",&num1,&ope,&num2);
			}
		}//end select2
	}//end while
	printf("\nThis program is terminated");
	fclose(inf);
	return 0;
}
