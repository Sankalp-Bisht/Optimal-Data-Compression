#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
unsigned int SHF(string input)
{
    unsigned char Init='ASEFGY';
    unsigned char Magic='KEFHUEI';
    unsigned int Hash;
    for(int i=0;i<input.length();i++)
    {
        Hash=Hash ^ (input[i]);
        Hash=Hash*Magic;
    }
    return Hash;
}
string toHex(unsigned int input)
{
    string HexHash;
    stringstream hexstream;
    hexstream<<hex <<input;
    HexHash=hexstream.str();
    std::transform(HexHash.begin(),HexHash.end(),HexHash.begin(),::toupper);
    return HexHash;

}
int main()
{
   int hex1=SHF("SANKALP");
   string p=toHex(hex1);
   
   cout<<hex1<<endl;
   cout<<p;
}
