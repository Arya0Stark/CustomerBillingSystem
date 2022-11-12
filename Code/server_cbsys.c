#include<stdio.h>
#include<stdlib.h>
#include<string.h>


 struct date{
	   int month;
	   int day;                
	   int year;
	   };

struct account {
	long int number;
	long int phnum;

	char name[100];
	char street[100];
	char city[100];
	
	float oldbal;
	float newbal;
	float pay;
	struct date lastpayment;
  }customer;
 int tl,sl,ts;



void input()
	{
	  FILE *fp=fopen("s.dat","rb");
	  fseek (fp,0,SEEK_END);
	  tl=ftell(fp);
	  sl=sizeof(customer);
	  ts=tl/sl;
	  fseek(fp,(ts-1)*sl,SEEK_SET);
	  fread(&customer,sizeof(customer),1,fp);
	  printf("\ncustomer account no:%ld\n",++customer.number);
	 
	  
	  printf("\n       Name:");
	  scanf("%s",customer.name);
	  printf("\n       mobile no:");
	  scanf("%ld",&customer.phnum);
	  printf("         Street:");
	  scanf("%s",customer.street);
	  printf("         City:");
	  scanf("%s",customer.city);
	  printf("         Previous balance:");
	  scanf("%f",&customer.oldbal);
	  printf("         Current payment:");
	  scanf("%f",&customer.pay);
	  printf("         Payment date(mm/dd/yyyy):");
	  scanf("%d/%d/%d",&customer.lastpayment.month,&customer.lastpayment.day,&customer.lastpayment.year);
	  if(customer.oldbal)
		{
			if(customer.oldbal>customer.pay)
				customer.newbal= customer.oldbal - customer.pay;
			else
				customer.newbal= 0;
		}
		else
			customer.newbal=0;

	  fclose(fp);
   }




void writefile()
   {
	  FILE *fp;
	  fp=fopen("s.dat","ab");
	  fwrite(&customer,sizeof(customer),1,fp);
	  fclose(fp);
	  return;
   }

void output()
	 {
	   printf("\n\n    Customer no    :%ld\n",customer.number);
	   printf("    Name 	   :%s\n",customer.name);
	   printf("    Mobile no      :%ld\n",customer.phnum);
	
	   printf("    Street         :%s\n",customer.street);
	   printf("    City           :%s\n",customer.city);
	   printf("    Old balance    :%f\n",customer.oldbal);
	   printf("    Current payment:%f\n",customer.pay);
	   printf("    New balance    :%f\n",customer.newbal);
	   printf("    Payment date   :%d/%d/%d\n\n",customer.lastpayment.month,customer.lastpayment.day,customer.lastpayment.year);
	 
	  
	    
	      return;
	   }

int search()
   {
	 char nam[100];
	 int n,i,m=1;
	 FILE *fp;
	 fp=fopen("s.dat","rb");
     
	fseek(fp,0,SEEK_END);
	tl=ftell(fp);
	sl=sizeof(customer);
	ts=tl/sl;
	fseek(fp,(ts-1)*sl,SEEK_SET);
	fread(&customer,sizeof(customer),1,fp);
	n=customer.number;

		printf("\nenter the name:");
		scanf("%s",nam);
		fseek(fp,0,SEEK_SET);
		for(i=1;i<=n;i++)
		{
			 fread(&customer,sizeof(customer),1,fp);
			 if(strcmp(customer.name,nam)==0)
			 {
				output();
				m=0;
				break;
			  }
		}
			if(m!=0)
			{
				printf("\ndoesn't exist. try again. \n");
			}
				
		fclose(fp);
	    
	    return m;
	 }

void pay()
{
	int n;int i; float p=0; float bal; 
	int q;double pr; char it[20];
	int x;
	x=search();	 
	switch(x)
	{
 	case 0:
 		{
		printf("enter number of  items purchased: \n");
		scanf("%d",&n);
		double pri[n]; int qu[n]; double tot[n];
		char items[100];
		for( i=0;i<n;i++)
		{	
			printf("Enter item %d:\n", i+1);
			scanf("%s",it);
			printf("Enter price:\n");
			scanf("%lf",&pr);
			printf("Enter quantity:\n");
			scanf("%d",&q);
		
			items[i]= it[0];
			pri[i]=pr;
			qu[i]=q;
			//tot[i]=pr*q;
			//p+=tot[i];
		}
		int ch;
		do
		{
		
			printf("\ndo you want to edit or delete items? enter 1 for yes and 0 for no\n");
			scanf("%d",&ch);
		
			if(ch==1)
			{
			int e,j,d, newq; double newpr; 
			printf("enter item number:\n");
			scanf("%d",&j);
			printf("choose the option\n 1. Edit\n 2. Delete \n");
			scanf("%d",&e);
			switch(e)
			{
				case 1:
					
					printf("edit 1. price or 2. quantity?\n");
					scanf("%d", &e);
					if(e==1)
					{
						printf("enter new price:\n");
						scanf("%lf",&newpr);
						pri[j-1]= newpr;
						}
					else
					{	printf("enter new quantity:\n");
						scanf("%d",&newq);
						qu[j-1]=newq;}
					break;
				
				case 2:
					for(int i=0;i<n;i++)
					{
						if(i==(j-1))
						{
							items[i]=items[i+1];
							qu[i]=0;
							pri[i]=pri[i+1];
						}
					}
					break;

			}
			}

		}while(ch==1);

	
		for(i=0;i<n;i++)
		{
		tot[i]=pri[i]*qu[i];
		p+=tot[i];
		}
		printf("enter balance (0 if none):\n");
		scanf("%f", &bal);
		float disc;
		printf("enter discount to be applied if any. enter 0 if none:\n");
		scanf("%f",&disc);
		printf("------------------------------------------------------------------------------------------------------\n");
		printf("Item\tPrice\tQuantity\tTotal Price\n");
		for( i=0;i<n;i++)
		{
		printf("%c\t%lf\t%d\t%lf\n",items[i],pri[i],qu[i],tot[i]);
		}
		printf("\t\t\t\t PREVIOUS BALANCE= %f", bal);
		printf("\t\t\t\t DISCOUNT= %f", disc);
		printf("\t\t\t\t GST= 5 \n");
		p= (p - p*(disc/100));
		p=(1.05*p);
		p+=bal;
		printf("The TOTAL AMOUNT to pay inclusive of tax= %.2f\n",p);
		printf("-----------------------------------------------------------------------------------------------------\n");
		break;
		}

	case 1:
		break;
	}
}
















