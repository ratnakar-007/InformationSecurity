

#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<iomanip.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
char *data=new char[10];
char *decodedData=new char[10];
char *key=new char[26];
char *msg=new char[10];
 char keyTable[5][5];

 int keyLength;
 int dataLength;
 int msgLength;
 int count=0;
 int alpha=0;
 int alphaFlag[26]={0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
/*Function to prepare the key table */
void setKeyTable();
/*Function to Encrypt Data*/
void encryptData();
/*Function to decrypt data*/


class indices
{
	public:
		int i,j;
};

void setKeyTable()
{
   keyLength=strlen(key);
   for(int i=0;i<5;i++)
   {
	for(int j=0;j<5;j++)
	{

		if(count<keyLength)
		{
			if(islower(key[count]))
				key[count]=toupper(key[count]);

			if(alphaFlag[int(key[count]-65)]!=1&&key[count]!='J')
			{
				keyTable[i][j]=key[count];
				alphaFlag[int(key[count]-65)]=1;
			}
			else
			j--;
			count++;
		}
		else
		{
			if(alphaFlag[alpha]!=1&&alpha!=9)
			{
			      keyTable[i][j]=char(alpha+65);
			      alphaFlag[alpha]=1;

			}
			else
			j--;
			alpha++;
		}
	  }
   }
   for(i=0;i<5;i++)
   {
	for(int j=0;j<5;j++)
	{
		cout<<keyTable[i][j]<<" ";
	}
	cout<<endl;
   }
}
indices search(char ch)
{
	indices point;
	point.i=0;
	point.j=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(keyTable[i][j]==ch)
			{
			     point.i=i;
			     point.j=j;
			     //cout<<i<<" "<<j<<endl;
			     return point;
			}

		}

	}
	return point;
}

void encryptData()
{
     indices point1,point2;
    int indexFlag=0;
     point1.i=0;
     point1.j=0;
     point2.i=0;
     point2.j=0;
     int flag=0;
     int j=0;
     for(int k=0;k<strlen(data);k++)
     {
	if(data[k]==' ')
	{       int l=k;
		while(l<strlen(data))
		{
			data[l]=data[l+1];
			l++;
		}
	}
     }
     dataLength=strlen(data);
      if(dataLength%2!=0)
      flag=1;
     for(int i=0;i<dataLength;i++)
     {
	   indexFlag=0;
	   if(data[i]==' ')
	   i++;
	   data[i]=toupper(data[i]);
	   if(data[i]=='J')
	   {
		data[i]='I';
	   }
	   point1=search(data[i]);
	   if(data[i+1]==' ')
	   i++;
	   if(i+1==dataLength&&((flag%2)!=0)&&(dataLength%2!=0))
	   data[i+1]='X';
	   data[i+1]=toupper(data[i+1]);
	   if(data[i+1]=='J')
	   {
		data[i+1]='I';
	   }

	   if(data[i]==data[i+1])
	   {
		point2=search('X');
		indexFlag=1;//to get the correct i+1 value from data
		flag++;
	   }
	   else
	   {
		 point2=search(data[i+1]);

	   }
	   if(point1.j==point2.j)
	   {
		if(point1.i==4)
		msg[j]=keyTable[0][point1.j];
		else
		msg[j]=keyTable[point1.i+1][point1.j];
		if(point2.i==4)
		msg[j+1]=keyTable[0][point2.j];
		else
		msg[j+1]=keyTable[point2.i+1][point2.j];

	   }
	   else if(point1.i==point2.i)
	   {
		if(point1.j==4)
		msg[j]=keyTable[point1.i][0];
		else
		msg[j]=keyTable[point1.i][point1.j+1];
		if(point2.j==4)
		msg[j+1]=keyTable[point2.i][0];
		else
		msg[j+1]=keyTable[point2.i][point2.j+1];

	   }
	   else
	   {
		msg[j]=keyTable[point1.i][point2.j];
		msg[j+1]=keyTable[point2.i][point1.j];
	   }
	   //cout<<data[i]<<msg[i+1]<<endl;
	   cout<<msg[i]<<msg[i+1]<<" ";
	   delay(1000);
	   if(indexFlag==0)
	   i++;
	   j+=2;
     }

}
void decryptData()
{

     indices point1,point2;
     point1.i=0;
     point1.j=0;
     point2.i=0;
     point2.j=0;
     int flag=0;
     msgLength=strlen(msg);
	int j=0;
     for(int i=0;i<msgLength,j<dataLength;i++)
     {
	   point1=search(msg[i]);
	   point2=search(msg[i+1]);

	   if(point1.j==point2.j)
	   {
		if(point1.i==0)
		decodedData[j]=keyTable[4][point1.j];
		else
		decodedData[j]=keyTable[point1.i-1][point1.j];
		if(point2.i==0)
		decodedData[j+1]=keyTable[4][point2.j];
		else
		decodedData[j+1]=keyTable[point2.i-1][point2.j];
	   }
	   else if(point1.i==point2.i)
	   {
		if(point1.j==0)
		decodedData[j]=keyTable[point1.i][4];
		else
		decodedData[j]=keyTable[point1.i][point1.j-1];
		if(point2.j==0)
		decodedData[j+1]=keyTable[point2.i][4];
		else
		decodedData[j+1]=keyTable[point2.i][point2.j-1];
	   }
	   else
	   {
		decodedData[j]=keyTable[point1.i][point2.j];
		decodedData[j+1]=keyTable[point2.i][point1.j];
	   }
	  if(decodedData[j+1]=='X')
		j--;
	  // cout<<decodedData[i]<<decodedData[i+1]<<endl;
	   i++;
	   j+=2;
     }
     j=-2;
}
void main()
{
   clrscr();
   char *sender={"MESSAGE SENT:"};
   char *receiver={"MESSAGE RECEIVED:"};

   char ans='y';
   cout<<"\nPlease enter a valid alpha key: ";
   gets(key);
   setKeyTable();
   cout<<"Please type message \n";

  while(ans=='y'||ans=='Y')
   {
	/*Starting a communication*/
	cout<<sender<<setw(8);
	gets(data);
	cout<<"Encrypting message..."<<endl;

	encryptData();
	//cout<<"Encrypted message:";
       //	puts(msg);
	cout<<endl;
	cout<<"Decrypting message..."<<endl;
	decryptData();
	delay(1500);
	cout<<receiver<<setw(8);
	for(int i=0;i<strlen(decodedData);i++)
		cout<<decodedData[i];
	cout<<endl<<"Do you want to continue?(y/n)"<<endl;
	cin>>ans;

   }

   getch();
}
