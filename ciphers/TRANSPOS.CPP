#include<iostream.h>
#include<conio.h>
#include<stdio.h>

int main()
{ clrscr();

  char s[100];
  int l=0,d,n,i,j;

  cout<<"Enter String : ";
  gets(s);

  for(i=0; s[i]!='\0'; i++)
  { //cout<<s[i];
    if(s[i]==' ')
      for(j=i; s[j]!='\0'; j++)
	s[j]=s[j+1];
    l++;
  }

  cout<<"\nDivison by (max 9): ";
  cin>>d;

  if(l%d!=0)
  {
    while(l%d!=0)
    { s[l]='x';
      s[l+1]='\0';
      l++;
    }
  }
  n=(l/d);

  char temp[100][9];
  int p=0;

  for(i=0; i<n; i++)
  { for(j=0; j<d; j++)
    { temp[i][j] = s[p];
      p++;
      cout<<temp[i][j]<<" ";
    }
    cout<<endl;
  }
	   p=0;
  for(i=0; i<d; i++)
  { for(j=0; j<n; j++)
    { if(temp[j][i]>='a' && temp[j][i]<='z'){
	s[p]=temp[j][i]-32;
	p++;
      }
    }
  }

  cout<<"\nCiphertext: "<<s<<"\n\n";

  p=0;
  for(i=0; i<d; i++)
  { for(j=0; j<n; j++)
    { temp[j][i] = s[p];
      p++;
      cout<<temp[j][i]<<" ";
    }
    cout<<endl;
  }
	   p=0;
  for(i=0; i<n; i++)
  { for(j=0; j<d; j++)
    { if(temp[i][j]>='A' && temp[i][j]<='Z'){
	s[p]=temp[i][j]+32;
	p++;
      }
    }
  }

  cout<<"\nPlaintext: "<<s;

  getch();
  return 0;
}