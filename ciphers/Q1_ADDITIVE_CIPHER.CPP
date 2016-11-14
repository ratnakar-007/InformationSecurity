

#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<iomanip.h>
#include<stdio.h>
int key;

/*Function to Encrypt Data*/
void encryptData(char *data);
/*Function to decrypt data*/
void decryptData(char *data);

void main()
{
   clrscr();
   char *sender={"MESSAGE SENT:"};
   char *receiver={"MESSAGE RECEIVED:"};
   char *data=new char[100];
   char ans='y';
   cout<<"Please enter a valid key :";
   cin>>key;
   cout<<"Please type message \n";
   while(ans=='y'||ans=='Y')
   {
	/*Starting a communication*/
	cout<<sender<<setw(8);
	gets(data);
	cout<<"Encrypting message..."<<endl;
	delay(1500);
	encryptData(data);
	cout<<"Encrypted message:"<<data<<endl;
	cout<<"Decrypting message..."<<endl;
	decryptData(data);
	delay(1500);
	cout<<receiver<<setw(8);
	puts(data);
	cout<<"Do you want to continue?(y/n)"<<endl;
	cin>>ans;
   }
   getch();
}
void encryptData(char *data)
{
	int len=strlen(data);
	char *copy=new char[len];
	for(int i=0;i<len;i++)
	{
		copy[i]=(char)(data[i]+key);
		data[i]=copy[i];
	}
}
void decryptData(char *data)
{

	int len=strlen(data);
	char *copy=new char[len];
	for(int i=0;i<len;i++)
	{
		copy[i]=(char)(data[i]-key);
		data[i]=copy[i];
	}
}