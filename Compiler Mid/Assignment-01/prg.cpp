#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int main()
{
    optimize();
    string p;
    char a;

    FILE *input;
    FILE *output;

    input = fopen("input.txt","r");
    output = fopen("output.txt","w");

    while(!feof(input))
    {
        a = fgetc(input);
        p+=a;
    }
    cout<<p;
    cout<<endl;

    for(int i=0; i<p.size(); i++)
    {
        if(p[i] == '/' && p[i+1] == '/') //checking the singns and space
            while(p[i] != '\n') i++;

        else if(p[i] == '*')
            while(p[i] != '/') i++;

        else if(p[i]!=32 && p[i]!=9 && p[i]!='\n' && p[i]!='/' && p[i]!='*')
        {
            if(p[i-1] == '}') continue;
           cout<<p[i];
           fputc(p[i],output);
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}
