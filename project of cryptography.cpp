

///Encode and Decode software using C++



#include<bits/stdc++.h>
using namespace std;
int matrix[10][10], r, c, ret=0;
map<char,int>mp;
map<int,char>mp2;

void start();
void Encode();
void Decode();
void Menu();

main()
{
    cout<<"\n\n\n\n\n";
    cout<<"         ****************************"<<endl;
    cout<<"         *                          *"<<endl;
    cout<<"         *    Encode  &&  Decode    *"<<endl;
    cout<<"         *    Secrete Messages      *"<<endl;
    cout<<"         *                          *"<<endl;
    cout<<"         *                          *"<<endl;
    cout<<"         ****************************\n\n"<<endl;
    cout<<"         Project by Rashed Khan\n\n\n"<<endl;
    cout<<"Enter y to start or n to exit: ";
    char ch;
    cin>>ch;
    if(ch=='y'|| ch == 'Y')
        start();
    else
        exit(0);

}
void start()
{
    cout<<"\n       Enter the row and column of matrix: ";
    cin>>r>>c;
    cout<<"\n       Enter the matrix element \n"<<endl;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>matrix[i][j];

        }
    }

    cout<<"\n       The given secret matrix is:\n"<<endl;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout<<matrix[i][j]<<" ";
            ret+=matrix[i][j];
        }
        cout<<endl;
    }
    Menu();

}
void Menu()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n      1. Encode. \n      2.Decode\n"<<endl;
    cout<<"press 1/2: ";
    int n;
    cin>>n;
    if(n==1)
        Encode();
    else
        Decode();
}

void Encode()
{

  cout<<"\n\n\n\n\n\n\n\n\n\n      Encoding.....";
    cout<<"\n\n      Please write a message for encoding :";

    string str;
    getline(cin,str);
    getline(cin,str);
    int cnt=1;
    mp[' ']=0;
    mp2[0]=' ';
    for(char ch = 'a'; ch<='z'; ch++)
    {
        mp[ch]=cnt;
        cnt++;
    }

    int len = str.size();
    cout<<"\n\n    The encoded message is : ";
    for(int i=0; i<len; i++)
    {
        char ch = tolower(str[i]);
        cout<<mp[ch]+ret<<" ";
    }
    cout<<endl;
    cout<<"\n\n      1. Exit. \n    2. Menu."<<endl;
    cout<<"\n\n      Press 1/2: ";
    int ck;
    cin>>ck;
    if(ck==1)
        exit(0);
    else
        Menu();

}
void Decode()
{
    int cnt =1;
    for(char ch = 'a'; ch<='z'; ch++)
    {
        mp2[cnt]=ch;
        cnt++;
    }
    cout<<"\n\n\n\n\n\n\n\n\n\n      Decoding.....";
    cout<<"\n\n      Please write secreted/ encoded  numbers: ";

    string s, st= "";
    getline(cin,s);
    getline(cin,s);
    int tt;

    stringstream ss(s);
    while(ss>>tt)
    {
        int trn = tt-ret;
        st+=mp2[trn];
    }
    cout<<"\n\n        The decoded message is: "<< st<<endl;
    cout<<endl;
    cout<<"\n\n      1. Exit. \n    2. Menu."<<endl;
    cout<<"\n\n      Press 1/2: ";
    int ck;
    cin>>ck;
    if(ck==1)
        exit(0);
    else
        Menu();

}


