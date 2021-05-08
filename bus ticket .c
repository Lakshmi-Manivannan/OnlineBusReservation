#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32
				//structure for storing username and password in file//
struct user
{
	char usr[10];
	char pss[10];
	int code;
};
				//end of structure for storing username and password in file//
				//structure for storing bus data//
struct bus_data
{
	char sou[20];//source_place=sou,destination_place=dest,bus_code=bc,bus_fare=fare//
	char dest[20];
	char bc[10];
	int  fare;
};
				//structure for storing username and password from file to linked list//
struct user_check
{
	char usr[10];
	char pss[10];
	int code;
	struct user *next1;
};
typedef struct user_check node1;
node1 *head1=NULL,*start1,*new1,*end1;
				//end of structure for storing username and password from file to linked list//
struct busdata_check
{
	char sou[20];
	char dest[20];
	char bc[10];
	int  fare;
	char brd1[20];
	char brd2[20];
	char brd3[20];
	char drp1[20];
	char drp2[20];
	char drp3[20];
	struct busdata *next2;
};
typedef struct busdata_check node2;
node2 *head2=NULL,*start2,*new2,*end2,*prev2=NULL;
						//displaying seats structure
struct bookticket
{
	char bc[10];
	int fare;
	int no_tic;
	int count;
	int b_tic;
	int a[30];
	struct bookticket *next3;
};
typedef struct bookticket node3;
node3 *head3=NULL,*start3,*new3,*end3,*prev3=NULL;
char sou[20],dest[20],code[10],brd1[20],brd2[20],brd3[20],drp1[20],drp2[20],drp3[20];
int fare;				
char usr[20],pwd[20];
FILE *fp1;
FILE *fp2;
FILE *fp3;
FILE *fp4;
void add();
void view();
void dropping_point(int);
void boarding_point(int);
void usercheck();
void new_user();
void del();
void delet();
void check1();
void ticket();
void book();
void cancel();
					//start of main program//
void main()
{
	int ch,i,k=1;
	char ch1,pwd[20],usr[20];
	char pss[20];
	printf("\t\t\t\t\t\t----------------WELCOME TO HORIZONITE BUS RESERVATION SYSTEM----------------\t\t\t\t\t\t\n");
	select_1 : printf("\n1.Admin\n2.User\n3.New user\n4.Exit\n");
	printf("Enter : \n");
	scanf("%d",&ch);
	switch(ch) 
	{
		case 1 :select_2 : printf("Enter password : \n");
				 scanf("%s",&pss);
				 if(strcmp(pss,"admin")==0)//password=admin
				 {
				 	 printf("\n1.Add bus data\n2.Delete bus data\n3.View booking details\n4.Exit\n");
				 	 printf("Enter : ");
				 	 scanf("%d",&ch);
			  	 	 switch(ch)
						{
						case 1 : add();
								 goto select_1;
								 break;
						case 2 : del();
								 goto select_1;
								 break;
						case 3 : view();
								 goto select_1;
				 				 break;
				 		case 4 : goto select_1;
				 				 break;
						default : printf("Please check your option\n");
								 goto select_2;
						}
				 }
				 else
				 {
				 	printf("Enter correct password\n");
				 	goto select_2;
				 }
				 break;
		case 2 : usercheck();
				 select_4 : printf("Enter username : ");
				 scanf("%s",&usr);
				 printf("Enter password : ");
				 //scanf("%s",&pwd);
				 i=0;
				 while(k>0)
					{
						ch1=getch();
						if(ch1==ENTER)
						{
							pwd[i]='\0';
							break;
						}
						else if(ch1==BKSP)
						{
							if(i>0)
							{
								i--;
								printf("\b \b");
							}
						}
						else if(ch1==TAB||ch1==SPACE)
							continue;
						else
						{
							pwd[i]=ch1;
							i++;
							printf("*");
						}
					}
					printf("\npassword : %s\n",pwd);
				 start1=head1;
				 while(start1!=NULL)
					{
						if((strcmp(strlwr(usr),start1->usr)==0)&&(strcmp(strlwr(pwd),start1->pss)==0))
							{
								printf("Login is successfull \n");
								printf("%s\t%s\n",start1->usr,start1->pss);
							select_3 : printf("\n1.Booking\n2.Cancelling\n3.View booking history\n4.Exit\n");
								printf("Enter : \n");
				 				scanf("%d",&ch);
			  	 				switch(ch)
									{
										case 1 : book();
												 goto select_3;
												 break;
										case 2 : cancel();
												goto select_3;
												 break;
								//		case 3 : history();
				 				//				 break;
				 						case 4 : goto select_1;
				 								 break;
										default : printf("Please check your option\n");
								 				  goto select_3;
									}
							}
							if(start1->next1==NULL)
							{
							printf("Entered username or password is incorrect\n");
							goto select_4;
							}
					start1=start1->next1;	
					}
				 break;
						
		case 3 : new_user();
				 break;
		case 4 : exit(0);
				 break;
		default : printf("Please check your option\n");
				  goto select_1;
	}
}
					//end of main program//
					//start 0f new_user function//
void new_user()
{
	struct user st;
	int i=0,k=1;
	char ch;
	printf("Create username and password\n");
	usercheck();
	s1 :printf("\nEnter username : \n");
	scanf("%s",&st.usr);
	start1=head1;
	while(start1->next1!=NULL)
	{
		if(strcmp(start1->usr,st.usr)==0)
		{
			printf("This %s username is already existing\nPlese try some other username",st.usr);
			goto s1;
		}
		else
		{
			if(start1->next1==NULL)
			break;
		}
		start1=start1->next1;
	}
	printf("Enter password : \n");
	//scanf("%s",&st.pss);
	while(k>0)
	{
		ch=getch();
		if(ch==ENTER)
		{
			st.pss[i]='\0';
			break;
		}
		else if(ch==BKSP)
		{
			if(i>0)
			{
				i--;
				printf("\b \b");
			}
		}
		else if(ch==TAB||ch==SPACE)
			continue;
		else
		{
			st.pss[i]=ch;
			i++;
			printf("*");
		}
	}
	printf("\npassword : %s\n",st.pss);
	s2 : printf("\nEnter usercode : \n");
	scanf("%d",&st.code);
	start1=head1;
	while(start1->next1!=NULL)
	{
		if(start1->code==st.code)
		{
			printf("This %d usercode is already existing\nPlese try some other usercode",st.code);
			goto s2;
		}
		else
		{
			if(start1->next1==NULL)
			break;
		}
		start1=start1->next1;
	}
		fp1=fopen("users.txt","a+");
		fprintf(fp1,"%s\t%s\t%d\n",st.usr,st.pss,st.code);
		printf("Username : %s\tPassword : %s\tUsercode : %d",st.usr,st.pss,st.code);
		fclose(fp1);
}
					 //end of  0f new_user function//
					//start of username and password  checking function//
void usercheck()
{
	int code;
	fp1=fopen("users.txt","r");
	if(fp1==NULL)
	{
		printf("No data available\n");
		exit(0);
	}
	while(!feof(fp1))
	{
		new1=(node1*)malloc(sizeof(node1));
		fscanf(fp1,"%s%s",&usr,&pwd);
		strcpy(new1->usr,usr);
		strcpy(new1->pss,pwd);	
		fscanf(fp1,"%d",&code);
		new1->code=code;
		if(head1==NULL)
			{
				head1=new1;
				new1->next1=NULL;
				end1=new1;
			}
		else
			{
				new1->next1=NULL;
				end1->next1=new1;
				end1=new1;
			}
	}
	
	fclose(fp1);
	start1=head1;
	while(start1->next1!=NULL)
	{
		printf("%s\t%s\t%d\n",start1->usr,start1->pss,start1->code);
		start1=start1->next1;
	}
}
						//end of username and password  checking function//
						//start of function for storing bus data  in file//
void add()
{
	int i=1;
	int a[40],n=30,cout=30,book=0;
	struct bus_data sd;
	printf("Enter source place : \n");
	scanf("%s",&sd.sou);
	printf("Enter destination place : \n");
	scanf("%s",&sd.dest);
	printf("Enter bus code : \n");
	scanf("%s",&sd.bc);
	printf("Enter bus fare : \n");
	scanf("%d",&sd.fare);
	fp2=fopen("busdata2.txt","a+");
	fprintf(fp2,"%s\t%s\t%s\t%d\t",sd.sou,sd.dest,sd.bc,sd.fare);
	do
	{
				boarding_point(i);
				i++;
	}while(i<=3);
	i=1;
	do
	{
			dropping_point(i);
				i++;
	}while(i<=3);
	fprintf(fp2,"\n");
					//displaying no. of seats in bus(storing)
	fp3=fopen("displayseats.txt","a+");
	fprintf(fp3,"%s\t",sd.bc);
	fprintf(fp3,"%d\t",sd.fare);
	fprintf(fp3,"%d\t%d\t%d\t",n,cout,book);//n=total number of ticket
	for(i=1;i<=n;i++)
			a[i]=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]==0)
		fprintf(fp3,"%d\t",a[i]);//0=empty,1=booked,-1=cancel//
		else
		fprintf(fp3,"%d\t",a[i]);
		//if(i==4|i==8|i==16|i==12|i==20|i==24|i==28|i==32)
		if(i==30)
		fprintf(fp3,"\n");
	}
	fclose(fp3);
	fclose(fp2);
}
					//end of function for storing bus data  in file//
					//start of function storing boarding  point and dropping point//
void boarding_point(int i)
{ 
	char str[20];
	printf("Enter the boarding point [%d]: \n",i);
	scanf("%s",&str);
	printf("[%d].%s\n",i,str);
	fprintf(fp2,"%s\t",str);	
}
void dropping_point(int i)
{
	char str[20];
	printf("Enter the dropping point [%d] : \n",i);
	scanf("%s",&str);
	printf("[%d].%s\n",i,str);
	fprintf(fp2,"%s\t",str);	
}										
					//end of function storing boarding  point and dropping point//
					//start of function for storing busdata from file into linked list//
void data_check()
{
	fp2=fopen("busdata2.txt","r+");
	if(fp2==NULL)
	{
		printf("No data available\n");
		exit(0);
	}
	while(!feof(fp2))
	{
		new2=(node2*)malloc(sizeof(node2));
		fscanf(fp2,"%s%s%s",&sou,&dest,&code);
		fscanf(fp2,"%d",&fare);
		fscanf(fp2,"%s%s%s",&brd1,&brd2,&brd3);
		fscanf(fp2,"%s%s%s",&drp1,&drp2,&drp3);
		strcpy(new2->sou,sou);
		strcpy(new2->dest,dest);
		strcpy(new2->bc,code);
		strcpy(new2->brd1,brd1);
		strcpy(new2->brd2,brd2);
		strcpy(new2->brd3,brd3);
		strcpy(new2->drp1,drp1);
		strcpy(new2->drp2,drp2);
		strcpy(new2->drp3,drp3);
		//strcpy(new2->st4,st4);//
		//strcpy(new2->st5,st5);//
		new2->fare=fare;
		//new2->bc=code;//
		if(head2==NULL)
		{
			head2=new2;
			new2->next2=NULL;
			end2=new2;
		}
			
		else
		{
			new2->next2=NULL;
			end2->next2=new2;
			end2=new2;
		}	
	}
	fclose(fp2);
}
void del()
{
	
	int i=0;
	char key[5];
	data_check();
	check1();
	start2=head2;
	start3=head3;
	select_5 : while(start2->next2!=NULL)
		{
			printf("source_place : %s\ndestination_place : %s\nbus_code : %s\nbus_fare : %d\nbroading_point[1] : %s\nbroading_point[2] : %s\nbroading_point[3] : %s\ndropping_point[1] : %s\ndropping_point[2] : %s\ndropping_point[3] : %s\n\n",start2->sou,start2->dest,start2->bc,start2->fare,start2->brd1,start2->brd2,start2->brd3,start2->drp1,start2->drp2,start2->drp3);
			start2=start2->next2;
		}
	printf("Enter the bus code which you what to delete : \n");
	scanf("%s",&key);
	start2=head2;
	start3=head3;
	while(start2!=NULL&&start3!=NULL)
		{
			if(strcmp(start2->bc,key)==0&&strcmp(start3->bc,key)==0)
			{
				if(start2==head2&&start3==head3)
				{
					head2=start2->next2;
					head3=start3->next3;
				}
				else if(start2->next2==NULL&&start3->next3==NULL)
				{
					prev2->next2=NULL;
					prev3->next3=NULL;	
				}	
				else
				{
						prev2->next2=start2->next2;
						prev3->next3=start3->next3;
				}
				free(start2);
				free(start3);
				i=1;
				break;
			}
			prev2=start2;
			start2=start2->next2;
			prev3=start3;
			start3=start3->next3;
		}
		if(i==0)
		{
			printf("Enter correct bus code\n");
			goto select_5;
		}
		fp2=fopen("busdata2.txt","w");
		start2=head2;
		while(start2->next2!=NULL)
		{
			printf("source_place : %s\ndestination_place : %s\nbus_code : %s\nbus_fare : %d\nbroading_point[1] : %s\nbroading_point[2] : %s\nbroading_point[3] : %s\ndropping_point[1] : %s\ndropping_point[2] : %s\ndropping_point[3] : %s\n\n",start2->sou,start2->dest,start2->bc,start2->fare,start2->brd1,start2->brd2,start2->brd3,start2->drp1,start2->drp2,start2->drp3);
			fprintf(fp2,"%s\t%s\t%s\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",start2->sou,start2->dest,start2->bc,start2->fare,start2->brd1,start2->brd2,start2->brd3,start2->drp1,start2->drp2,start2->drp3);
			start2=start2->next2;
		}
		fclose(fp2);
		ticket();
}	
void check1()
{
	char num[10];
	int i,b[30],m,c,t;
	fp3=fopen("displayseats.txt","r");
	if(fp3==NULL)
	{
		printf("No data available\n");
		exit(0);
	}
	while(!feof(fp3))
	{
		new3=(node3*)malloc(sizeof(node3));
		fscanf(fp3,"%s",&num);
		strcpy(new3->bc,num);
		fscanf(fp3,"%d",&fare);
		fscanf(fp3,"%d",&m);//m=total no. of ticket 
		fscanf(fp3,"%d",&c);//no. of ticket available
		fscanf(fp3,"%d",&t);//no.of booked tickets
		new3->fare=fare;
		new3->no_tic=m;
		new3->b_tic=t;
		new3->count=c;
		for(i=1;i<=(new3->no_tic);i++)
		{
			fscanf(fp3,"%d",&b[i]);
			new3->a[i]=b[i];	
		}	
		if(head3==NULL)
		{
			head3=new3;
			new3->next3=NULL;
			end3=new3;
		}
		else
		{
			new3->next3=NULL;
			end3->next3=new3;
			end3=new3;
		}
	}
	fclose(fp3);
}
void ticket()
{
	int i;
	fp3=fopen("displayseats.txt","w");
			start3=head3;
			while(start3->next3!=NULL)
			{
				fprintf(fp3,"%s\t",start3->bc);
				fprintf(fp3,"%d\t",start3->fare);
				fprintf(fp3,"%d\t",start3->no_tic);
				fprintf(fp3,"%d\t%d\t",start3->count,start3->b_tic);
				for(i=1;i<=(start3->no_tic);i++)
				{
					if(start3->a[i]==0)
					fprintf(fp3,"%d\t",start3->a[i]);
					else if(start3->a[i]==-1)
					fprintf(fp3,"%d\t",start3->a[i]);
					else
					fprintf(fp3,"%d\t",start3->a[i]);
					if(i==30)
					fprintf(fp3,"\n");
				}
				start3=start3->next3;
			}
			fclose(fp3);
}
//void check2()
//{
//}
void book()
{
	char code[10];
	int ucode;
	int i,n,s,c;
	int fare;
	data_check();
	printf("The buses available are\n");
	select_6 :start2=head2;
	while(start2->next2!=NULL)
	{
		printf("Source place : %s\tDestination place : %s\tBus_code : %s\n",start2->sou,start2->dest,start2->bc);
		start2=start2->next2;
	}
	check1();
	printf("Enter the Bus Code : \n");
	scanf("%s",&code);
	start3=head3;
	while(start3!=NULL)
	{
		if(strcmp(start3->bc,code)==0)
		{
			printf("The available seats are \n");
			for(i=1;i<=(start3->no_tic);i++)
				{
					if(start3->a[i]==0||start3->a[i]==-1)
					printf("%d . Empty\t",i);
					else
					printf("%d . booked\t",i);
					if(i==4|i==8|i==16|i==12|i==20|i==24|i==28|i==32)
					printf("\n");
				}
				printf("\nAvailable seats : %d ",start3->count);
			if((start3->count)>0)
				{
				fp4=fopen("history.txt","a+");
				printf("\nEnter number of tickets : ");
				scanf("%d",&n);
				select_8 : printf("Enter usercode : \n");
				scanf("%d",&ucode);
				if(start1->code==ucode)
				{
					for(i=1;i<=n;i++)
						{
							select_7 :	printf("Enter seat number : ");
							scanf("%d",&s);
							if(start3->a[s]==0||start3->a[i]==-1)
							{
								start3->a[s]=ucode;
								fprintf(fp4,"The user %s booked a ticket in bus of bus code %s for seat number %d\n",start1->usr,start3->bc,s);
							}
							else
							{
							printf("This ticket is already booked\nPlease select any other seat\n");
							goto select_7;
							}
						}
						//	printf("Available seats : %d\tBooked seats : %d\n",start3->count,start3->b_tic);
				printf("The total amount of booking is %d\n",(n*start3->fare));
				fprintf(fp4,"The total amount of booking is %d\n",(n*start3->fare));
				printf("Bus_code : %s\t",start3->bc);
				printf("Bus_fare : %d\n",start3->fare);
				start3->b_tic=((start3->b_tic)+n);
				c=start3->b_tic;
				start3->count=((start3->no_tic)-c);
				printf("Available seats : %d\tBooked seats : %d\n",start3->count,start3->b_tic);
				for(i=1;i<=(start3->no_tic);i++)
				{
					if(start3->a[i]==0)
					printf("%d . Empty\t",i);
					else
					printf("%d . booked\t",i);
					if(i==4|i==8|i==16|i==12|i==20|i==24|i==28|i==32)
					printf("\n");
				}
				fclose(fp4);
				ticket();	
				}
				else
				{
					printf("Enter correct usercode\n");
					goto select_8;
				}
			}
			else
			{
				printf("All tickets/seats are booked\n");
				break;
			}
		}
		else
		{
			if(start3->next3==NULL)
			{
			printf("Enter correct Bus Code \n");
			goto select_6;
			}
		}
		start3=start3->next3;
	}	
}
void cancel()
{
	int i=0,u,s,n,c,j=0;
	char code[10];
	data_check();
	printf("The buses available are\n");
	select_11 :start2=head2;
	while(start2->next2!=NULL)
	{
		printf("Source place : %s\tDestination place : %s\tBus_code : %s\n",start2->sou,start2->dest,start2->bc);
		start2=start2->next2;
	}
	check1();
	printf("Enter bus code : \n");
	scanf("%s",&code);
	start3=head3;
	while(start3!=NULL)
	{
		if(strcmp(start3->bc,code)==0)
		{
			for(i=1;i<=(start3->no_tic);i++)
			{
					if(start3->a[i]==0||start3->a[i]==-1)
					printf("%d . Empty\t",i);
					else
					printf("%d . booked\t",i);
					if(i==4|i==8|i==16|i==12|i==20|i==24|i==28|i==30)
					printf("\n");
			}
			printf("Booked seats : %d \n",start3->b_tic);
			if(start3->b_tic>0)
			{
				fp4=fopen("history.txt","a+");
				select_10 : printf("\nEnter user code : \n");
				scanf("%d",&u);
				if(start1->code==u)
				{
					for(i=1;i<=(start3->no_tic);i++)
					{
						if(start3->a[i]==start1->code)
						printf("%d . Booked\n",i);
						j++;	
					}
					select_12 : printf("\nEnter how many seats who want to cancel : ");
					scanf("%d",&n);
					if(n<=j)
					{
						for(i=1;i<=n;i++)
						{
							printf("\nSelect the seat number which you want to cancel : ");
							scanf("%d",&s);
							if(start3->a[s]==u)
							start3->a[s]=-1;
							fprintf(fp4,"The user %s cancelled a ticket in bus of bus code %s for seat number %d\n",start1->usr,start3->bc,s);
						}
					}
					else
					{
						printf("Cancellation of ticket is not possible\n");
						exit(0);
					}
				}
				else
					{
					printf("\nEnter available number seats to cancel");
					goto select_12;
					}
				start3->b_tic=((start3->b_tic)-n);
				c=start3->b_tic;
				start3->count=((start3->no_tic)-c);
				i=0;
				printf("The amount of booking is refunded %d\n",(n*start3->fare));
				fprintf(fp4,"The amount of booking is refunded %d\n",(n*start3->fare));
				printf("Bus_code : %s\t",start3->bc);
				printf("Bus_fare : %d\n",start3->fare);
				printf("Available seats : %d\tBooked seats : %d\n",start3->count,start3->b_tic);
				for(i=1;i<=(start3->no_tic);i++)
				{
					if(start3->a[i]==0||start3->a[i]==-1)
					printf("%d . Empty\t",i);
					else
					printf("%d . booked\t",i);
					if(i==4|i==8|i==16|i==12|i==20|i==24|i==28|i==32)
					printf("\n");
				}	
			}
			else
			{
				printf("Ticket is not booked\n");
				exit(0);
			}
			fclose(fp4);
			ticket();		
		}
		else
			{
				if(start3->next3==NULL)
				{
					printf("Enter correct Bus Code \n");
					goto select_11;
				}
			}
		start3=start3->next3;	
	}
}
void view()
{
	FILE *fp;
	char f;
	fp=fopen("history.txt","r");
	if(fp==NULL)
	{
		printf("File doesn't exist\n");
		exit(0);
	}
	else
	{
		f=fgetc(fp);
		while(f!=EOF)
		{
			printf("%c",f);
			f=fgetc(fp);			
		}	
	}
	fclose(fp);
}
