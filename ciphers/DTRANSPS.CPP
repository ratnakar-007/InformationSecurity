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

  char temp[100][9], temp2[100][9];
  int p=0;

  for(i=0; i<n; i++)
  { for(j=0; j<d; j++)
    { temp[i][j] = s[p];
      p++;
      cout<<temp[i][j]<<" ";
    }
    cout<<endl;
  }

  int key[9], k=0;
  cout<<"\nEnter Locations to be Changed\n";
  for(i=0; i<d; i++)
  { cout<<" column "<<i+1<<" with: ";
    cin>>key[i];
  }

  for(i=0; i<n; i++){
    for(j=0; j<d; j++){
      temp2[i][j]=temp[i][ key[k]-1 ];
      cout<<temp2[i][j]<<" ";
      k++;
    }
    k=0;
    cout<<endl;
  }

	   p=0;
  for(i=0; i<d; i++)
  { for(j=0; j<n; j++)
    { if(temp2[j][i]>='a' && temp2[j][i]<='z'){
	s[p]=temp2[j][i]-32;
	p++;
      }
    }
  }

  cout<<"\nCiphertext: "<<s<<"\n\n";
	  /*
  for(i=0; i<d; i++)
  { for(j=0; j<n; j++)
    { temp[j][i] = 0;
      temp2[j][i] = 0;
    }
  }     */

  p=0;
  for(i=0; i<d; i++)
  { for(j=0; j<n; j++)
    { temp2[j][i] = s[p];
      p++;
      //cout<<temp2[j][i]<<" ";
    }
    //cout<<endl;
  }
  //cout<<endl;

      k=0;
  for(i=0; i<n; i++)
  {
    for(j=0; j<d; j++)
    {
      temp[i][ key[k]-1 ]=temp2[i][j];
      cout<<temp2[i][j]<<" ";
      k++;
    }
    k=0;
    cout<<endl;
  }
	  cout<<endl;
	   p=0;
  for(i=0; i<n; i++)
  { for(j=0; j<d; j++)
    { if(temp[i][j]>='A' && temp[i][j]<='Z'){
	s[p]=temp[i][j]+32;
	p++;
      }
      cout<<temp[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<"\nPlaintext: "<<s;

  getch();
  return 0;
}