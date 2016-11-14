#include<iostream.h>
#include<conio.h>
#include<stdio.h>

int main()
{ clrscr();

  char s[100];
  int key[100], l=0, k;

  cout<<"Enter String : ";
  gets(s);

  for(int i=0; s[i]!='\0'; i++)
  {
    if(s[i]==' ')
      for(int j=i; s[j]!='\0'; j++)
	s[j]=s[j+1];
    l++;
  }
  cout<<"\nPlaintext: "<<s<<endl;

  again:
  cout<<"\nEnter Length of Key Stream: ";
  cin>>k;

  if(k>l)
  { cout<<"\n-- Key length must be less than the length of given string --\n";
    goto again;
  }

  cout<<"\nEnter Key Stream (in integer): ";
  for(i=0; i<k; i++){
    cout<<"\nk"<<i<<": ";
    cin>>key[i];
  }
  l=0;

  for(i=0; s[i]!='\0'; i++, l++)
  { if(l>k-1)
      l=0;
    if(s[i]>='a' && s[i]<='z')
    { //cout<<endl<<(int)s[i]<<"->";
      s[i]=(s[i]-97)+(key[l]%26);

      if(s[i]>=26)
	s[i]-=26;

      s[i]+=65;
      //cout<<(int)s[i];
    }
  }
  cout<<"\nCiphertext: "<<s;

  l=0;
  for(i=0; s[i]!='\0'; i++, l++)
  { if(l>k-1)
      l=0;
    if(s[i]>='A' && s[i]<='Z')
    {
      s[i]=(s[i]-65)-(key[l]%26);
      if(s[i]<0)
	s[i]+=26;
      s[i]+=97;
    }
  }
  cout<<"\n\nPlaintext: "<<s;

  getch();
  return 0;
}