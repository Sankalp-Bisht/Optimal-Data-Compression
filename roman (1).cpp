#include<bits\stdc++.h>
#include <sstream>
using namespace std;
class obj
{
public:

    int data;
    string da;
};
void print(int k)
{
    cout<<k<<"   "<<"X     ";
    for(int i=1;i<=k/10;i++)
    {
        cout<<"* ";
    }

    cout<<endl;
    cout<<"    X     ";

    for(int i=1;i<=k/10;i++)
    {
        cout<<"* ";
    }

    cout<<endl;
    cout<<"    X";
    cout<<endl;
    cout<<"    X";
    cout<<endl;

}
obj* strToBinary(string s)
{
    int n = s.length();
    int sum=0;
    string binT="";
    for (int i = 0; i <= n; i++)
    {
        int val = int(s[i]);
        string bin = "";
        while (val > 0)
        {
            (val % 2)? bin.push_back('1') :
                       bin.push_back('0');
            val /= 2;
        }
        reverse(bin.begin(), bin.end());
        sum=sum+bin.length();
        binT=binT+bin;
    }
    obj* temp=new obj();
    temp->data=sum;
    temp->da=binT;
    return temp;
}
/*string taken(string s)
{
    string encoding="";
    int count;
    for(int i=0;s[i];i++)
    {
        count=1;
        while(s[i]==s[i+1])
            count++,i++;
        encoding+=to_string(count)+s[i];
    }
    return encoding;
}*/
int printRoman(int number)
{
	int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
	string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	int i=12;
	while(number>0)
	{
	int div = number/num[i];
	number = number%num[i];
	while(div--)
	{
		cout<<sym[i];
	}
	i--;
	}
	cout<<endl;
}

int main()
{
	int number = 35;
   
   int r= printRoman(number);
   
   cout<<r;

/*
   ss<<r<<endl;

   string newstring=ss.str();

	string p=newstring ;
    string t=newstring;
    string z=taken(t);
    cout<<z;
    obj * temp=strToBinary(p);
    string    q=taken(p);
    obj* temp2=strToBinary(q);
    cout<<endl;
    print(temp2->data);
    print(temp->data);
    cout<<endl;

	return 0;*/
}

