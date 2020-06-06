#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<process.h>
int main_exit;
void menu();
void option();
void dam();
int choice;
struct date
{
	int month,day,year;
};
struct date dob[10]  ;
struct account
{
	char name[15];
	int accno,age;
	char address[25];
	double phone;
	double dep,with,total;
};
struct account acc[10];
void newacc();
void display();
void transact();
void modify();
void new();
void page();
int l=0,j,i,w=0,v=0,n,r=0,t=0,k,g,s=0,e,h,z;double f,ph;double amt;
char x[10],u[10][20],p[10][8],q[8],m[8],ch[15];
FILE *b,*d,*bnew,*dnew,*a,*o,*ne,*vi;
void main()
{clrscr();
option();
}
void option()
{
while(1)
{clrscr();

		printf("\t\t**************BANKING MANAGEMENT FOR CUSTOMER**************\n\n");
	printf("7.NEW USER THEN CREATE NEW ACCOUNT\n");
	printf("8.LOG IN TO BANKING MANAGEMENT\n");
	printf("9.EXIT\n");
	printf("ENTER YOUR CHOICE:-");
	scanf("%d",&n);
if(n==9)
return 0;
switch(n)
{
case 7: new();
break;
case 8:
 page();
break;
case 9:
	exit(1);
	break;
}getch();


}
}void new()
{FILE *b,*bnew,*c,*cnew;
clrscr();
 t=0;
b=fopen("b.txt","r");

while((u[1][1]=getc(b))!=EOF)
t++;
fclose(b);
if(t==0)
{
b=fopen("b.txt","w");
printf("\nUSERNAME:-");
scanf("%s",u[0]);
fflush(stdin);
fprintf(b,"%s\n",u[0]);
fclose(b);
d=fopen("d.txt","w");
abc:
printf("\nPASSWORD:-");
scanf("%s",p[0]);
printf("\nREENTER PASSWORD:-");
scanf("%s",q);
g=0;
for(i=0;q[i]!='\0';i++)
g++;
for(i=0;q[i]!='\0';i++)
if(p[0][i]==q[i])
l++;
if(l==g)
{
fprintf(d,"%s",p[0]);k=0;
printf("\n\t\tUSER ID CREATED SUCCESFULLY\n");
printf("\t\tTHANKYOU");
fclose(d);
printf("\n\n\t\tPRESS 11 AND ENTER TO GO TO LOG IN PAGE\n");
scanf("%d",&main_exit);

if(main_exit==11)
option(); }
else
{
printf("\n\t\tPASSWORD IS WRONG");
clrscr();
goto abc;}}

else if(t>0)
{
v=0;
bnew=fopen("bnew.txt","w");
b=fopen("b.txt","r");
 i=0;
while(fscanf(b,"%s",u[i])!=EOF)
i++;
uvw:
printf("\nUSERNAME:-");
scanf("%s",u[i]);
for(j=0;j<i;j++){
if(u[i]==u[j])
{v++;break;}}
if(v>0){
printf("\n\t\tUSER NAME ALREADY IN USE\n")   ;
goto uvw;
}
else if(v==0)
{ for(j=0;j<=i;j++)
fprintf(bnew,"%s\n",u[j]);k=j;
fclose(b);
fclose(bnew);
remove("b.txt");
rename("bnew.txt","b.txt");
d=fopen("d.txt","r");
dnew=fopen("dnew.txt","w");
i=0;
while(fscanf(d,"%s",p[i])!=EOF)
i++;

pqr:
printf("\nPASSWORD:-");
scanf("%s",&p[i]);
printf("\n REENTER PASSWORD:-");
scanf("%s",q);
 v=0;g=0;
for(k=0;q[k]!='\0';k++) g++;for(k=0;q[k]!='\0';k++)
if(q[k]==p[i][k])
v++;
if(v==g)
{for(j=0;j<=i;j++)
fprintf(dnew,"%s\n",p[j]);

fclose(d);
fclose(dnew);
remove("d.txt");
rename("dnew.txt","d.txt");
printf("\n\t\tUSER ID CREATED SUCCESSFULLY");
printf("\n\t\t\t\tTHANKYOU");

	printf("\n\n\t\tPRESS 11 AND ENTER TO GO TO LOG IN PAGE\n");
	scanf("%d",&main_exit);
	if(main_exit==11)
	option();
	}}

else{
printf("\nPASSWORD IS INCORRECT");
clrscr();
goto pqr;
}
} }

void page(){
bokachoda:
{clrscr();
 s=0;
printf("\nUSERNAME:-");
scanf("%s",x);
fflush(stdin);
printf("\nPASSWORD-");
scanf("%s",m);
t=0;
for(i=0;x[i]!='\0';i++)
t++;
b=fopen("b.txt","r");
i=0;
while(fscanf(b,"%s",u[i])!=EOF)
i++;
for(z=0;z<10;z++)
{s=0;
	for(j=0;x[j]!='\0';j++)
	{
	if(x[j]!=u[z][j])
	break;
	else
	s++;   }
	if(s==t)
	{
	k=z;
	break;}
	else
	continue;
}
fclose(b);
g=0;
for(i=0;m[i]!='\0';i++)
g++;
d=fopen("d.txt","r");
i=0;
while(fscanf(d,"%s",p[i])!=EOF)
i++;
for(z=0;z<10;z++)
{r=0;
for(j=0;m[j]!='\0';j++)
{
if(m[j]!=p[z][j])
break;
else
r++;}
if(r==g)

break;
else
continue;
}
}fclose(d);
if(s==t&&r==g)
{

menu();
}
else
w++;
if(w!=3&&w!=0)
goto bokachoda;
else if(w>0&&w<=3)
{
printf("\n\n\t\tSESSION EXPIRED");
exit(0);
}}

void menu()
{
	clrscr();
	while(1)
	{
	clrscr();
printf("\n\t\t******WELCOME TO BANKING MANAGEMENT MAIN PAGE******\n\n");
printf("\t\t\t1.CREATE NEW ACCOUNT\n");
printf("\t\t\t2.DISPLAY ACCOUNT\n");
printf("\t\t\t3.TRANSACTION\n");
printf("\t\t\t4.MODIFY ACCOUNT\n");
printf("\t\t\t5.LOG OUT\n");
scanf("%d",&choice);
if(choice==5)
return 0;
switch(choice)
{
	case 1:
		newacc();
		break;
		case 2:
			display();
			break;
			case 3:
				transact ();
				break;
					case 4:
						modify();
						break;
					case 5:
						option();
						break;
}
}
}
void newacc()
{
	clrscr();
	e=1895;
	a=fopen("record.txt","r");
	ne=fopen("newr.txt","w");
	i=0;
	while(fscanf(a,"%d %s %d %d %d %d %s %lf %lf %lf %lf",&acc[i].accno,acc[i].name,&dob[i].day,&dob[i].month,&dob[i].year,&acc[i].age,acc[i].address,&acc[i].phone,&acc[i].total,&acc[i].with,&acc[i].dep)!=EOF)
	i++;
	printf("\n\t\t\t**********NEW ACCOUNT**********");
	printf("\nNAME:-");
	scanf("%s",acc[i].name);
	fflush(stdin);
	printf("\nONLY DATE OF BIRTH:-");
	scanf("%d",&dob[i].day);
	printf("\nONLY MONTH OF BIRTH:-");
	scanf("%d",&dob[i].month);
	printf("\nONLY YEAR OF BIRTH:-");
	scanf("%d",&dob[i].year);
	printf("\nAGE:-");
	scanf("%d",&acc[i].age);
	fflush(stdin);
	printf("\nADDRESS:-");
	scanf("%s",acc[i].address);
	fflush(stdin);
	printf("\nPHONE NUMBER:-");
	scanf("%lf",&acc[i].phone);
	printf("\nENTER MINIMUM AMOUNT WHICH SHOULD GRETTER THAN 1000 TO CREATE NEW ACCOUNT:-");
	scanf("%lf",&f);
	getch();
	if(f>=1000){
	acc[i].total=f;
	acc[i].dep=f;
	acc[i].with=000.00;
		for(j=0;j<=i;j++)
		{ acc[j].accno=e+j;
	fprintf(ne,"%d %s %d %d %d %d %s %lf %lf %lf %lf\n",acc[j].accno,acc[j].name,dob[j].day,dob[j].month,dob[j].year,acc[j].age,acc[j].address,acc[j].phone,acc[j].total,acc[j].dep,acc[j].with);
}
	printf("\nYOUR ACCOUNT NO IS=%d",acc[i].accno);
	fclose(a);
	fclose(ne);
	remove("record.txt");
	rename("newr.txt","record.txt");
	printf("\n\t\t\tACCOUNT CREATED SUCCESFULLY\n");
	getch();
	
}
	else{
		printf("\n\t\tAmount is not sufficiant");
		clrscr();
		printf("\n\n\t\tPRESS 10 TO GO TO MENU PAGE\n ");
	scanf("%d",&main_exit);
	if(main_exit==10)
	menu();
		
}

	printf("\n\n\t\tPRESS 10 TO GO TO MENU PAGE\n");
	scanf("%d",main_exit);
	if(main_exit==10)
	menu();
}
void display()
{
	clrscr();
	 i=0;

	vi=fopen("record.txt","r");
	printf("\n\t\t\t**********ACCOUNT DETAILS PAGE**********");
	printf("\nENTER ACCOUNT NO:-");
	scanf("%d",&e);
	t=0;j=0;
	while(fscanf(vi,"%d %s %d %d %d %d %s %lf %lf %lf %lf",&acc[j].accno,acc[j].name,&dob[j].day,&dob[j].month,&dob[j].year,&acc[j].age,acc[j].address,&acc[j].phone,&acc[j].total,&acc[j].dep,&acc[j].with)!=EOF)
j++;
for(i=0;i<=j;i++)
{

	if(e==acc[i].accno)
	{
		clrscr();
		printf("\nACCOUNT NO:\t\t%d",acc[i].accno);
		printf("\nNAME OF ACCOUNT HOLDER:\t\t%s",acc[i].name);
		printf("\nDATE OF BIRTH:\t\t%d.%d.%d",dob[i].day,dob[i].month,dob[i].year);
		printf("\nAGE:\t\t%d",acc[i].age);
		printf("\nADDRES:\t\t%s",acc[i].address);
		printf("\nPHONE NUMBER:\t\t%lf",acc[i].phone);
		printf("\nTOTAL BALANCE:\t\t%lf",acc[i].total);
		printf("\nLAST DEPOSITED MONEY:\t\t%lf",acc[i].dep);
		printf("\nLAST WITHDRAW MONEY:\t\t%lf",acc[i].with);
		getch();
		t++;
		getch();
		fclose(vi);
		break;
	}
	
	}
	if(t==0)
	printf("\n\n\t\tSORRY NO RECORDS FOUND");
fclose(vi);

	printf("\n\n\t\tPRESS 10 TO GO TO MENU PAGE ");
	scanf("%d",main_exit);
	if(main_exit==10)
	dam();
}
void modify()
{
	clrscr();
	t=0;
	o=fopen("record.txt","r");
	ne=fopen("newr.txt","w");
	printf("\n\t\t\t**********ACCOUNT ID MODIFY PAGE**********");
	printf("\nENTER ACCOUNT NO:-");
	scanf("%d",&e);
	j=0;
	while(fscanf(o,"%d %s %d %d %d %d %s %lf %lf %lf %lf",&acc[j].accno,acc[j].name,&dob[j].day,&dob[j].month,&dob[j].year,&acc[j].age,acc[j].address,&acc[j].phone,&acc[j].total,&acc[j].dep,&acc[j].with)!=EOF)
j++;
for(i=0;i<j;i++)
{
	
if(e==acc[i].accno)
	{
		clrscr();
		t++;
		printf("\nWHICH INFORMATION YOU WANT TO MODIFY \n1.ADDRESS\n2.PHONE NUMBER");
		scanf("%d",&h);
		if(h==1)
		{
			printf("\nENTER NEW ADDRESS:-");
			scanf("%s",acc[i].address);
                        printf("\n\t\t\tACCOUNT MODIFIED");
	}
		else if(h==2)
		{
		printf("\nENTER NEW PHONE NUMBER:-");
		scanf("%lf",&ph);
		acc[i].phone=ph;
	        printf("\n\t\t\tACCOUNT MODIFIED");
			
	}	
	
	else
	printf("\nINVALID");
	break;
}	
	}
	for(i=0;i<j;i++)
	fprintf(ne,"%d %s %d %d %d %d %s %lf %lf %lf %lf\n",acc[i].accno,acc[i].name,dob[i].day,dob[i].month,dob[i].year,acc[i].age,acc[i].address,acc[i].phone,acc[i].total,acc[i].dep,acc[i].with);

	fclose(o);
	fclose(ne);
	remove("record.txt");
	rename("newr.txt","record.txt");

	if(t==0)
	printf("\n\n\t\tRECORD NOT FOUND");
	printf("\n\n\t\tPRESS 10 TO GO TO MENU PAGE");
	scanf("%d",&main_exit);
	if(main_exit==10)
	menu();

}
void transact()
{
	clrscr();
	t=0;
	o=fopen("record.txt","r");
	ne=fopen("newr.txt","w");
	printf("\n\t\t\t**********TRANSACTION PAGE*********");
	printf("\nENTER ACCOUNT NO:-");
	scanf("%d",&e);
	i=0;
	j=0;
	while(fscanf(o,"%d %s %d %d %d %d %s %lf %lf %lf %lf",&acc[j].accno,acc[j].name,&dob[j].day,&dob[j].month,&dob[j].year,&acc[j].age,acc[j].address,&acc[j].phone,&acc[j].total,&acc[j].dep,&acc[j].with)!=EOF)
j++;
for(i=0;i<j;i++)
{
	if(e==acc[i].accno)
	{
		t++;
		printf("\n1.WITHDRAW MONEY");
		printf("\n2.DEPOSITE MONEY");
		printf("\nWHICH TRANSACTION YOU WANT TO PERFORM ENTER CHOICE");
		scanf("%d",&h);
		if(h==1)
		{
			printf("\n\nENTER AMOUNT WHICH YOU WANT TO WITHDRAW:-");
			scanf("%lf",&amt);
			if(amt<acc[i].total)
			{
				acc[i].with=amt;
				acc[i].total=acc[i].total-acc[i].with;
					printf("\n\n\t\tWITHDRAWLED SUCCESFULLY");
					getch();
						}
						else
						{
							printf("\nACCES DENIED");
							}
		}
		else
		{
			printf("\n\nENTER AMOUNT WHICH YOU WANT TO DEPOSITE:-");
			scanf("%lf",&amt);
			acc[i].dep=amt;
			acc[i].total=acc[i].total+acc[i].dep;
		    printf("\n\n\t\tDEPOSITTED SUCCESFULLY");
	getch();
		}
		break;
 }
 }
 for(i=0;i<j;i++)
 fprintf(ne,"%d %s %d %d %d %d %s %lf %lf %lf %lf\n",acc[i].accno,acc[i].name,dob[i].day,dob[i].month,dob[i].year,acc[i].age,acc[i].address,acc[i].phone,acc[i].total,acc[i].dep,acc[i].with);

	 fclose(o);
	fclose(ne);
	remove("record.txt");
	rename("newr.txt","record.txt");

	if(t==0)
	{
		printf("\nRECORD NOT FOUND");
		printf("\n\n\tPRESS 10 TO GO TO MENU PAGE");
				scanf("%d",&main_exit);
	if(main_exit==10)
	menu();
	}
}
void dam()
{
menu();
}

