#include<iostream.h>
#include<conio.h>
#include<stdio.h>

int main()
{ clrscr();

  char s[100], k[100];
  int l=0, kl=0, i, j;

  cout<<"Enter characters of a stream: ";
  gets(s);

  for(i=0; s[i]!='\0'; i++)
    l++;

  again:
  cout<<"Enter key stream: ";
  gets(k);

  for(i=0; k[i]!='\0'; i++)
    kl++;

  if(l!=kl)
  { cout<<"\n\nBoth stream lengths must be equal\n\n"; kl=0;
    goto again;
  }

  for(i=0; i<l; i++)
  { if((s[i]=='0' && k[i]=='0') || (s[i]=='1' && k[i]=='1'))
      s[i]='0';
    else
      s[i]='1';
  }

  cout<<"\nCiphertext: "<<s;

  for(i=0; i<l; i++)
  { if((s[i]=='0' && k[i]=='0') || (s[i]=='1' && k[i]=='1'))
      s[i]='0';
    else
      s[i]='1';
  }

  cout<<"\n\nPlaintext: "<<s;

  getch();
  return 0;
}