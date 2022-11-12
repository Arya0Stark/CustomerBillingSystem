#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"server.h"
int main()
	{
	  int n1;int i;
	  char ch;
	  
	  printf("   CUSTOMER BILLING SYSTEM:\n");
	
	  printf("===============================\n");
	  printf("\n1:    to add account on list\n");
	  printf("2:    to search customer account\n");
	  printf("3.    to display bill\n");
	  printf("4:    exit\n");
	  printf("\n================================\n");
	  do{
	       printf("\nselect what do you want to do?");
	       ch=getchar();
	  }while(ch<='0' || ch>'4');
	  switch(ch){
		case '1':
			
			printf("\nhow many customer accounts?\n");
			scanf("%d",&n1);
			for(i=0;i<n1;i++){
				input();
				
				writefile();
			}
			main();
			break;
		case '2':
			search();
			ch=getchar();
			main();
			break;
		case '3':
		
			pay();
			main();
			break;
		case '4':
			exit(1);
			break;
	}
	  
 }