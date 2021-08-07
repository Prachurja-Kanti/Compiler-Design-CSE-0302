// Prachurja Kanti//
// UG02-49-18-002//
#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int isKeyword(string buffer)
{
    string keywords[32] = {"auto","break","case","char","const","continue","default",
                           "do","double","else","enum","extern","float","for","goto",
                           "if","int","long","register","return","short","signed",
                           "sizeof","static","struct","switch","typedef","union",
                           "unsigned","void","volatile","while"};

    int i, flag = 0;
    for(i = 0; i < 32; ++i)
    {
        if(keywords[i] == buffer)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main()
{
    optimize();
    string buffer;
    string operators = {"+-*%=/"};
    string num = {"0123456789"};
    char ch;
    FILE *fp;
    int i,j=0;
    fp = fopen("output.txt","r");
    if(fp == NULL)
    {
        printf("error while opening the file\n");
        return 0;
    }
    FILE *input;
    string s, head;
    char p;
    input = fopen("output.txt","r");

    while(!feof(input))
    {
        p = fgetc(input);
        s+=p;
    }

    for(int j=0; j<s.size(); j++)
    {
        ch = s[i];
        for(int i = j, m=0; m < 4; m++) head[m] = s[i];

        if(head == "main") cout<<"[fun "<<head<<"]";

        for(int i = j, m=0; m < 6; m++)
        {
            head[m] = s[i];
            if(ch == operators[i])
                cout<<"[op "<<ch<<"]";
        }

        if(head == "printf" || head == "return") cout<<"[kw "<<head<<"]";

        for(int i = j, m=0; m < 10; m++)
        {
            if(ch == num[i])
                cout<<"[num "<<ch<<"]";
        }
        for(int i = j, m=0; m < 17; m++) head[i] = s[i];

        if(head == "#include<stdio.h>") cout<<"[hdr "<<head<<"]";

        if(s[i] == ';') cout<<"[sep "<<s[i]<<"]";

    }

    fclose(input);
    return 0;
}
