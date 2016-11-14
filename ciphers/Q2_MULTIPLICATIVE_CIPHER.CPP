

#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<iomanip.h>
#include<stdio.h>
int key;
int *msg=new int[100];
char *data=new char[100];

/*Function to Encrypt Data*/
void encryptData(char *data);
/*Function to Decrypt data*/
void decryptData(int *data);

void main()
{
   clrscr();
   char *sender={"MESSAGE SENT:"};
   char *receiver={"MESSAGE RECEIVED:"};

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
	decryptData(msg);
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

	for(int i=0;i<len;i++)
	{
		int j=(int)(data[i]);
		msg[i]=j*key;
		data[i]=(char)msg[i];
	}
}
void decryptData(int *msg)
{

	int len=strlen(data);

	for(int i=0;i<len;i++)
	{

		msg[i]=msg[i]/key;
		data[i]=(char)msg[i];


	}
}