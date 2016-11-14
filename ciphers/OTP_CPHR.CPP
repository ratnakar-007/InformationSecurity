#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{ clrscr();

  char s[100];
  int key[100];

  cout<<"Enter String : ";
  gets(s);

  for(int i=0; s[i]!='\0'; i++)
    if(s[i]==' ')
      for(int j=i; s[j]!='\0'; j++)
	s[j]=s[j+1];

  cout<<"\nPlaintext: "<<s;

  for(i=0; s[i]!='\0'; i++)
  { srand(time(NULL));
    key[i]=rand()%26;

    if(s[i]>='a' && s[i]<='z')
    { //cout<<endl<<(int)s[i]<<"->";
      s[i]=(s[i]-97)+(key[i]%26);

      if(s[i]>=26)
	s[i]-=26;

      s[i]+=65;
      //cout<<(int)s[i];
    }
  }
  cout<<"\n\nCiphertext: "<<s;

  for(i=0; s[i]!='\0'; i++)
  { if(s[i]>='A' && s[i]<='Z')
    {
      s[i]=(s[i]-65)-(key[i]%26);
      if(s[i]<0)
	s[i]+=26;
      s[i]+=97;
    }
  }
  cout<<"\n\nPlaintext: "<<s;

  getch();
  return 0;
}