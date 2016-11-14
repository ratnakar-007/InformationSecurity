

#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<iomanip.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
//capital letters A,B,C...encoded to a,b,c...
//lowercase letters a,b,c....encoded to A,B,C....
int *msg=new int[100];
char *data=new char[100];

/*Function to Encrypt Data*/
void encryptData(char *data);
/*Function to decrypt data*/
void decryptData(char *data);

void main()
{
   clrscr();
   char *sender={"MESSAGE SENT:"};
   char *receiver={"MESSAGE RECEIVED:"};

   char ans='y';

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

	for(int i=0;i<len;i++)
	{
		if(isalpha(data[i]))
		{
			if(isupper(data[i]))
			{
				data[i]=tolower(data[i]);
			}
			else
			{
				data[i]=toupper(data[i]);
			}
		}


	}

}
void decryptData(char *data)
{

	int len=strlen(data);

	for(int i=0;i<len;i++)
	{
		if(isalpha(data[i]))
		{
			if(isupper(data[i]))
			{
				data[i]=tolower(data[i]);
			}
			else
			{
				data[i]=toupper(data[i]);
			}

		}
	}

}

