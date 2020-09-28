#include<iostream>
#include<cstring>
#include<fstream>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include <stdlib.h> 

using namespace std;

int rec_flag=0,no=0;
char rec_ind[5];
int fl=0;
int totalbill;
struct record
{
  char cost[5],ind[5];
  char  uid[20],name[20],dealer[15];
  char stock[5],expd[10];
  
}rec[200],bufe[500],bufee[500];

struct tb
{
	char cost[5];
}bt[100];
struct index
{
    char uid[20],ind[20];
}in[200],temp,tep[200];


void sort_index()
{
    int i,j;
    for(i=0;i<no-1;i++)
    for(j=0;j<no-i-1;j++)
    if(strcmp(in[j].uid,in[j+1].uid)>0)
    {
       temp=in[j];
       in[j]=in[j+1];
       in[j+1]=temp;
    }

}
void modi(char *uid)
{
	int j=0;
	int flg=0;
	fstream file1,f2;
	
	file1.open("record1.txt",ios::in);
	       while(!file1.eof()){
		   
		  file1.getline(bufe[j].ind,5,'|');
		  file1.getline(bufe[j].uid,20,'|');
		  file1.getline(bufe[j].name,20,'|');
		  file1.getline(bufe[j].cost,15,'|');
		  file1.getline(bufe[j].stock,15,'|');
		  file1.getline(bufe[j].dealer,15,'|');
		  file1.getline(bufe[j].expd,15,'\n');
	       j++;
		   }
	j--;
	file1.close();
	    for(int i=0;i<j;i++)
       {
          if(strcmp(bufe[i].uid,uid)==0)
         {
          cout<<"\nenter the name to be modified     :        ";
          cin>>bufe[i].name;
          cout<<"\nenter the cost to be modified     :        ";
          cin>>bufe[i].cost;
          cout<<"\nenter the stock to be modified     :        ";
          cin>>bufe[i].stock;
          cout<<"\nenter the dealer to be modified     :        ";
          cin>>bufe[i].dealer;
          cout<<"\nenter the expdate to be modified     :        ";
          cin>>bufe[i].expd;
          
          flg=1;
          
		  }
       }
                 if(flg==0)
                 {
				 cout<<"uid not found\n";
				 return;
				 }
				 
				 else
				 {
				 f2.open("record1.txt",ios::out);	
			for(int i=0;i<j;i++)
			{
			
				 
				 
				 f2<<bufe[i].ind<<"|"<<bufe[i].uid<<"|"<<bufe[i].name<<"|"<<bufe[i].cost<<"|"<<bufe[i].stock<<"|"<<bufe[i].dealer<<"|"<<bufe[i].expd<<"\n";
				 
			}
			
			f2.close();
				 }
				
			
			return;	 
				 
	 }	
	 
	 
	
void bilmodi(char *uid,int remstck)
{
	char rmst[15];
	sprintf(rmst, "%d", remstck);

int j=0;
	int flg=0;
	fstream file1,f2;
	
	file1.open("record1.txt",ios::in);
	       while(!file1.eof()){
		   
		  file1.getline(bufe[j].ind,5,'|');
		  file1.getline(bufe[j].uid,20,'|');
		  file1.getline(bufe[j].name,20,'|');
		  file1.getline(bufe[j].cost,15,'|');
		  file1.getline(bufe[j].stock,15,'|');
		  file1.getline(bufe[j].dealer,15,'|');
		  file1.getline(bufe[j].expd,15,'\n');
	       j++;
		   }
	j--;
	file1.close();
	    for(int i=0;i<j;i++)
       {
          if(strcmp(bufe[i].uid,uid)==0)
         {
          sprintf(bufe[i].stock, "%d", remstck);
          flg=1;
          
		  }
       }
                 if(flg==0)
                 {
				 cout<<"usn not found\n";
				 return;
				 }
				 
				 else
				 {
				 f2.open("record1.txt",ios::out);	
			for(int i=0;i<j;i++)
			{
			
				 
				 
				 f2<<bufe[i].ind<<"|"<<bufe[i].uid<<"|"<<bufe[i].name<<"|"<<bufe[i].cost<<"|"<<bufe[i].stock<<"|"<<bufe[i].dealer<<"|"<<bufe[i].expd<<"\n";
				 
			}
			
			f2.close();
				 }
				
			
			return;	 
			
	
	
}

void retrive_record(char *ind)
{
    for(int i=0;i<no;i++)
    {
      if(strcmp(rec[i].ind,ind)==0)
      {
          strcpy(rec_ind,ind);
          rec_flag=1;
          cout<<"\nrecord found:";
          if(fl==0)
         {
	        cout<<rec[i].uid<<"|"<<rec[i].name<<"|"<<rec[i].cost<<"|"<<rec[i].stock<<"|"<<rec[i].dealer<<"|"<<rec[i].expd<<"\n";
         }
         else if (fl==1)
          {
               cout<<rec[i].uid<<"  :  "<<rec[i].stock<<"\n";
           }
           
           else if(fl==2) 
           {
		   cout<<rec[i].uid<<"  :  "<<rec[i].expd<<"\n";
		   }
		   
		   else
		   {  int l,m,n,v,total,rmstock;
		      cout<<"Enter the total no of tabs required\n";
		      cin>>l;
		      			
		      m= atoi(rec[i].stock);
		      v= atoi(rec[i].cost);
		      if(l<m)
		      {  rmstock=m-l;
		         totalbill=totalbill+l*v;
		        //cout<<"the total amount is : "<<total<<"\n";
		        bilmodi(rec[i].uid,rmstock);
		       }
		     else
		         {cout<<"out of stock: ";}
		   }
		
		   }
		}
		 
		   
          
          
          
	 
          
	 fl=0;
	  return;
      
   }
    



int search_index(char *uid)
{
      int flag=0;
      for(int i=0;i<no;i++)
      {
	  if(strcmp (in[i].uid,uid)==0)
	  {
 	     retrive_record(in[i].ind);
	     flag=1;
	  }
      }
      if(flag)
	  return 1;
      else
	  return -1;
}

int search_uid(char *uid,int j)
{
      int flag=0;
      for(int i=0;i<j;i++)
      {
	  if(strcmp (rec[i].uid,uid)==0)
	  {
	     flag=1;break;
	  }
      }
      if(flag)
	  return 1;
      else
	  return -1;
}

void stock1(char *st_uid)
        {   fl=1;
	int q=search_index(st_uid);
		if(q==1)
		   cout<<"\nSearch successful, Results found\n";
		else
		   cout<<"\nSearch not successful, Results not found\n";
       
       
}

void expiredate(char *st_uid)
        {   fl=2;
	int q=search_index(st_uid);
		if(q==1)
		   cout<<"\nSearch successful, Results found\n";
		else
		   cout<<"\nSearch not successful, Results not found\n";
       
       
}

void bill(char *st_uid)
        {   fl=3;
	int q=search_index(st_uid);
		if(q==1)
		   cout<<"\nbill successful and amount paid\n";
		else
		   cout<<"\nbill  not successful and amount not paid\n";
       
       
}

void cbill()
{ int r=0,j=0;
totalbill=0;

	
char pid[5];
	cout<<"enter the no of prducts to be billed\n";
cin>>r;
for(int i=0;i<r;i++)
{
	fl=3;
	cout<<"enter the Pid \n";
	cin>>pid;
	
	int q=search_index(pid);
	
		
	}	
	
	cout<<"total bill is :"<<totalbill;
	
	
}

void delet(char *st_uid)
{
      rec_flag=0;
      int fr=0;
      search_index(st_uid);
      if(!rec_flag)
      {
	 cout<<"\ndeletion failed\nrecord not found";
	 return;
      }
      for(int i=0;i<no;i++)
      {
	 if(strcmp(rec[i].ind,rec_ind)==0)
	  {   fr=i; break;}
      }
      for(int i=fr;i<no-1;i++)
      {
	 rec[i]=rec[i+1];
	 char str[3];
	 //itoa(i,str,10);
	sprintf(str,"%d",i);
	 strcpy(rec[i].ind,str);
      }
      no--;
      fstream f1,f2;
      f1.open("record1.txt",ios::out);
      f2.open("index1.txt",ios::out);
      for(int i=0;i<no;i++)
      {
      strcpy(in[i].uid,rec[i].uid);
      strcpy(in[i].ind,rec[i].ind);
      }
      sort_index();
      for(int i=0;i<no;i++)
      {
      f1<<rec[i].ind<<"|"<<rec[i].uid<<"|"<<rec[i].name<<"|"<<rec[i].cost<<"|"<<rec[i].stock<<"|"<<rec[i].dealer<<"|"<<rec[i].expd<<"\n";
      f2<<in[i].uid<<"|"<<in[i].ind<<"\n";
      }
      f1.close();
      f2.close();
      cout<<"\n deletion successful\n";
}

int main()
{
      fstream file1,file2;
      int choice;
      char ind[5],st_uid[20],name[20],cost[5],stock[5],dealer[5],uid[20],expd[10];
      int z=0,x=0,w=0;
      string username,Name,ch,iN;
      string password,cpassword,newpassword;
      file2.open("index1.txt",ios::out|ios::app);
      file1.open("record1.txt",ios::out|ios::app);
      file1.close();
      file2.close();
      
      
      
      
      
      file2.open("index1.txt",ios::in);
      while(!file2.eof())
      {
      	file2.getline(tep[z].uid,20,'|');
      	file2.getline(tep[z].ind,5,'\n');
		  z++;
      	
	  }
      z--;
      no=z;
      //cout<<no;
      file2.close();
      file2.open("index1.txt",ios::in);
      	file1.open("record1.txt",ios::in);
      if(no!=0)
      {
      while(!file2.eof())
      {
      	file2.getline(in[x].uid,20,'|');
      	file2.getline(in[x].ind,5,'\n');
		  x++;
      	
	  }	
      	
       while(!file1.eof())
      {
      	file1.getline(rec[w].ind,5,'|');
		  file1.getline(rec[w].uid,20,'|');
		  file1.getline(rec[w].name,20,'|');
		  file1.getline(rec[w].cost,15,'|');
		  file1.getline(rec[w].stock,15,'|');
		  file1.getline(rec[w].dealer,15,'|');
		  file1.getline(rec[w].expd,15,'\n');
      	w++;
	  }	
      	
      	x--;
      	w--;
      	
      	
      	
	  }
      file1.close();
      	file2.close();
      
      
      
      
      
       cout<<"\n\n\n\t\t\t#############################################"<<endl;
	  cout<<"\n\t\t\t#   Welcome to Pharmacy management  System   #"<<endl;
	  cout<<"\n\t\t\t##############################################";
	  do
	
	  {
	  
                     cout<<"\n\t\t\t\tPlease Login to Continue\t"<<endl;	
	        cout << "\n\t\t\t\tUser Name: ";
		cin>>username;
		if (username == "fs") {
			cout << "\n\t\t\t\tPassword: ";
			cin>>password;
			cout<<"\n\n\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
			cout<<endl;
			if (password != "fs") {
				system("cls");
		
				cout << "\n\n\t\t\t\tinvalid password. try again." <<endl;
	
					}
				}
				
				
				
				 else {
				system("cls");
		
					cout << "\n\n\t\t\t\tinvalid username. try again." <<endl;
	
						}								
		if(password == "fs"){


			system("cls");	
 
      
      
      
      int i;
         
      for(;;)
      {
      cout<<"\n\n\n\n\n\t\t\t\t\tMENU\n\t\t\t\t1:Add new product\n\t\t\t\t2:Search for product\n\t\t\t\t3:Delete product\n\t\t\t\t4:Display report\n\t\t\t\t5:Stock of the product\n\t\t\t\t6:Expdate of product\n\t\t\t\t7:Stock report\n\t\t\t\t8:Expdate report\n\t\t\t\t9:Modify\n\t\t\t\t10:Billing\n\t\t\t\t11:Exit\n";
      cin>>choice;
      switch(choice)
      {
	 case 1:{ 
	 system("cls");	
		file1.open("record1.txt",ios::app|ios::out);
		if(!file1)
		{
		  cout<<"File creation error\n";
		  exit(0);
		}
		int n;
		cout<<"Enter number of products to added\n";
		cin>>n;
		cout<<"enter the details\n";
		
		  for(i=no;i<no+n;i++)
		  {
		  cout<<"\nenter "<<i+1<<" product:";

		  cout<<"\nuid: ";
		  cin>>rec[i].uid;
		  cout<<"\nname: ";
		  cin>>rec[i].name;
		  cout<<"\ncost: ";
		  cin>>rec[i].cost;
		  cout<<"\nstock: ";
		  cin>>rec[i].stock;
		  cout<<"\ndealer: ";
		  cin>>rec[i].dealer;
		   cout<<"\nexpdate: ";
		  cin>>rec[i].expd;
    	
    
		    
		file1<<i<<"|"<<rec[i].uid<<"|"<<rec[i].name<<"|"<<rec[i].cost<<"|"<<rec[i].stock<<"|"<<rec[i].dealer<<"|"<<rec[i].expd<<"\n";
	   }
	       file1.close();
	       no=no+n;
	       
	       file2.open("index1.txt",ios::out);
	       file1.open("record1.txt",ios::in);
	       for(i=0;i<no;i++)
	       {
		  file1.getline(ind,5,'|');
		  file1.getline(uid,20,'|');
		  file1.getline(name,20,'|');
		  file1.getline(cost,15,'|');
		  file1.getline(stock,15,'|');
		  file1.getline(dealer,15,'|');
		  file1.getline(expd,15,'\n');
		  
		  strcpy(rec[i].ind,ind);
		  strcpy(in[i].uid,uid);
		  strcpy(in[i].ind,ind);
	       }
	       sort_index();
	       
	       /*cout<<"\nafter sorting index file contents are\n";
	       for(i=0;i<no;i++)
	       cout<<in[i].uid<<" "<<in[i].ind<<endl;*/
	       for(i=0;i<no;i++)
	       {
		   file2<<in[i].uid<<"|"<<in[i].ind<<"\n";
	       }
	       file1.close();
	       file2.close();
	       break;
		}
	 case 2:{
	 	system("cls");	
		cout<<"\nEnter uid of product whose result is to be displayed\n";
		cin>>st_uid;
		int q=search_index(st_uid);
		if(q==1)
		   cout<<"\nSearch successful, Results found\n";
		else
		   cout<<"\nSearch not successful, Results not found\n";
		break;
		}
	 case 3:{ system("cls");	
		cout<<"Enter uid of product whose record is to be deleted\n";
		cin>>st_uid;
		delet(st_uid);
		break;
		}
	 case 4:{
	 	system("cls");	
	      fstream f1;
	      f1.open("record1.txt",ios::in);
	      if(!f1)
	      {
	      cout<<"err\\\\\\\\\\\\\\\\n";
	      exit(0);
	      }
	      
	      int i=0;
	      while(i!=no)

	       {
		  f1.getline(ind,5,'|');
		  f1.getline(uid,20,'|');
		  f1.getline(name,20,'|');
		  f1.getline(cost,15,'|');
		  f1.getline(stock,15,'|');
		  f1.getline(dealer,15,'|');
		  f1.getline(expd,10,'\n');
		  cout<<"uid:"<<uid<<"\t"<<"name:"<<name<<"\t"<<"stock:"<<stock<<"\t"<<"dealer:"<<dealer<<"\t"<<"cost:"<<cost<<"\t"<<"expd:"<<expd<<endl;
		  i++;
	       }
		  break;
		}
	case 5:{
		system("cls");	
		cout<<"Enter product uid whose stock is to be displayed\n";
		cin>>st_uid;
		stock1(st_uid);
		break;
	}	
	case 6:{
		 system("cls");	
		cout<<"enter product uid whose expdate is to be displayed\n";
		cin>>st_uid;
		expiredate(st_uid);
		break;
		}
		
		case 7:{
			system("cls");	
	      fstream f1;
	      f1.open("record1.txt",ios::in);
	      if(!f1)
	      {
	      cout<<"err\\\\\\\\\\\\\\\\n";
	      exit(0);
	      }
	      cout<<"\n\tUID   |    Stock\n";
	      int i=0;
	      while(i!=no)

	       {
		  f1.getline(ind,5,'|');
		  f1.getline(uid,20,'|');
		  f1.getline(name,20,'|');
		  f1.getline(cost,15,'|');
		  f1.getline(stock,15,'|');
		  f1.getline(dealer,15,'|');
		  f1.getline(expd,10,'\n');
		  cout<<"\t"<<ind<<"    :  "<<stock<<endl;
		  i++;
	       }
		  break;
		}
		case 8:{
			system("cls");	
	      fstream f1;
	      f1.open("record1.txt",ios::in);
	      if(!f1)
	      {
	      cout<<"err\\\\\\\\\\\\\\\\n";
	      exit(0);
	      }
	      cout<<"\n\tUID   |    ExpDate\n";
	      int i=0;
	      while(i!=no)

	       {
		  f1.getline(ind,5,'|');
		  f1.getline(uid,20,'|');
		  f1.getline(name,20,'|');
		  f1.getline(cost,15,'|');
		  f1.getline(stock,15,'|');
		  f1.getline(dealer,15,'|');
		  f1.getline(expd,10,'\n');
		  cout<<"\t"<<ind<<"     :   "<<expd<<endl;
		  i++;
	       }
		  break;
		}
		case 9:{
			system("cls");	
			char a[20];
		 cout<<"\enter the Uid to be modified";
		cin>>a;
		modi(a);
		break;
		 
		}
		case 10:{system("cls");	
		 //cout<<"enter product uid \n";
		//cin>>st_uid;
		//bill(st_uid);
		cbill();
		break;
		}
		case 11:{
		 cout<<"\nending program";
		
		 exit(0);
		}
	 default:
		 cout<<"\nInvalid\n";
		 break;
	 }
     }
}}while(password!="fs");





return 0;
}

