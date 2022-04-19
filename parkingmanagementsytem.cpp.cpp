#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;
class parking
{
	private:
	  char type[20];
	  char number[10];
	  char modle[50];
	  char time[10];
    public:
	  parking() {
		strcpy(type,"Not Entered");
		strcpy(number,"Not Entered");
		strcpy(modle,"Not Entered");
		strcpy(time,"Not Entered");
	  }

       void entry(void);
       void storedata(void);
       void ShowParking(void);
       void Read(void);
       void search(char *);
       void del(char *);
       void modify(char *);
};
//--------------------------------------
int main()
 {
	display:
	system("cls");
 	parking a[20];
 	int c=0,b;
 	cout<<"\n\n\t\t1 -----> Enter a Veachle Data";
 	cout<<"\n\n\t\t2 -----> show a Record";
 	cout<<"\n\n\t\t3 -----> search a Record";
 	cout<<"\n\n\t\t4 -----> update a Record";
 	cout<<"\n\n\t\t5 -----> Exit";
 	
	 cout<<"\n\n\t\tEnter your choice\t";
		cin>>b;
		if((b==1)&&(c==0))
		{
			 a[1].entry();
			 a[1].storedata();
	   cout<<"\n\n\t\t\t\tPress any key";
			 getch ();	  
		 	goto display;
		}
		
		else if((b==2)&&(c==0))
		{
			 a[2].Read();
			 cout<<"\n\n\t\t\t\tPress any key";
				getch ();
		  goto display;
		}
		
		else if((b==3)&&(c==0))
		{
			 cin.ignore();
				cout<<"\n\tEnter a vehicle number to search\t";
				char e[30];
			 cin.getline(e,30);
			 a[3].search(e);
		  cout<<"\n\n\t\t\t\tPress any key";
				getch ();
				goto display;
		}
		
		else if((b==4)&&(c==0))
		{
			 cout<<"\n\tEnter a vehicle number to Update\t";
			 char g[30];
			 cin.ignore();
			 cin.getline(g,30);
			 a[4].modify(g);
		  cout<<"\n\n\t\t\t\tPress any key";
				getch ();
				goto display;
		} 
		
		else if((b==5)&&(c==0))
		{
			 cout<<"\n\n\n\t\t Thanks";
			 c==1;
			  cout<<"\n\n\t\t\t\tPress any key";
				getch ();
			
	
		}   

}


//------------------------ Working on classa is Starat------------------

 void parking::entry() 
	{
		cin.ignore();
		cout<<"\n\n\tEnter a vehcile Type\t";
	 	cin.getline(type,19);
		cout<<"\n\n\tEnter a vehcile Number\t";
		cin.getline(number,10);
		cout<<"\n\n\tEnter a vehcile Modle\t";
		cin.getline(modle,50);
		cout<<"\n\n\tEnter a Entry Time ---> i.e 00:00\t";
		cin.getline(time,10);
	}
	
void parking::ShowParking()
{
    cout<<"\n\n\t\t-------------------------------------\n\n";
	cout<<"\n\n\t\t\t\t\t"<<type<<"\n\n\n\t\t"<<number<<"\t\t\t"<<modle<<"\t\t"<<time;
}


 void parking::storedata()
 {
	ofstream datafile;
    datafile.open("parking data.doc",ios::app|ios::binary);
    datafile.write((char*)this,sizeof(*this));
    cout<<"\n\t\tDtat is Entered Successfully";
  };

  void parking::Read(){

  		ifstream read;
      read.open("parking data.doc",ios::in|ios::binary);
      if(!read){

        cout<<"\n\n\t\tFile not Found\n\n";

      }
       else
      {
        read.read((char*)this,sizeof(*this));
      while(!read.eof())
						{
       ShowParking();
      	read.read((char*)this,sizeof(*this));
						 }
       }
      read.close();
  }
  
  
  
  
void parking::search(char *ser)
{   
   int i=0;
   ifstream rec;
  rec.open("parking data.doc",ios::in|ios::binary);
			if (!rec)
   {
  		cout<<"\n\n\t\t\tFile Not Exist\n"; 	
  }
			else
   {
   		rec.read((char*)this,sizeof(*this));
   			display:
			while(!rec.eof())
   			{
   				if(!strcmp(ser,number))
				   {
   					ShowParking();
   					rec.read((char*)this,sizeof(*this));
   				    i++;
					  	
					   goto display;
				    }
   			break;
   			}
   	
   	}
   if(i==0)
   {
   	
   		cout<<"\n\n\t\t\t\tNo Record Found\n";
   	
   }
   rec.close();
   
}

void parking::del(char *nu)
{
	ofstream indata;

    ifstream view;
	 view.open("parking data.doc",ios::in|ios::binary);
	if(!view)
	{
		cout<<"\n\n\t\tFile not Exist\n";
	}
	else
	{
		
		view.read((char*)this,sizeof(*this));
		display:
		while(!view.eof())
		{
		   
		   if(strcmp(number,nu))
		   {
			  indata.open("parking.doc",ios::binary);
			  indata.write((char*)this,sizeof(*this));			
			}
	      view.read((char*)this,sizeof(*this));			
		  goto display;	 
		}
	}
	//       ---------------  error is here --------

	remove("parking data.doc");
	rename("parking.doc","parking data.doc");


	view.close();
}

void parking::modify(char *ud)
 {
  int i=0;
 	fstream file;
	file.open("parking data.doc",ios::ate|ios::in|ios::out|ios::binary);
	file.seekg(0);
	file.read((char*)this,sizeof(*this));
     display:
	 while(!file.eof())
     {
		if(!strcmp(ud,number))
		{
			ShowParking();
			cout<<"\n\n\t\t\t\tPress any key";
			entry();
			file.seekp(file.tellp()-sizeof(*this));
			file.write((char*)this,sizeof(*this));
			i++;
		}
	    file.read((char*)this,sizeof(*this));
	    goto display;
	}
	if(i==0)
	{
		cout<<"\n\n\t\tSory No Record Found\n";	
	}
}

