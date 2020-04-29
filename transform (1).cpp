#include<bits\stdc++.h>
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
string taken(string s)
{
	stringstream ss;
    string encoding="";
    int count;
    for(int i=0;s[i];i++)
    {
        count=1;
        while(s[i]==s[i+1])
            count++,i++;
            ss<<count;
            
        encoding+=ss.str()+s[i];
    }
    return encoding;
}
string change_case(string a)
{
	int l = a.length();

	for(int i = 0 ; i < l ; i++)
	{
		if(a[i] >= 'a' && a[i] <= 'z')
			a[i] = (char)(65 +
				(int)(a[i] - 'a'));
	else if(a[i] >= 'A' && a[i] <= 'Z')
			a[i] = (char)(97 +
				(int)(a[i] - 'A'));
	}
	return a;
}
string delete_vowels(string a)
{
	string temp = "";
	int l = a.length();
	for(int i = 0 ; i < l ; i++)
	{
		if(a[i] != 'a' && a[i] != 'e' &&
		a[i] != 'i' && a[i] != 'o' &&
		a[i] != 'u' && a[i] != 'A' &&
		a[i] != 'E' && a[i] != 'O' &&
		a[i] != 'U'&& a[i] != 'I')
			temp += a[i];
	}
	return temp;

}
string insert_hash(string a)
{
	string temp = "";
	int l = a.length();

	for(int i = 0 ; i < l ; i++)
	{
		if((a[i] >= 'a' && a[i] <= 'z') ||
		(a[i] >= 'A' && a[i] <= 'Z'))
			temp = temp + '#' + a[i];
		else
			temp = temp + a[i];
	}

	return temp;

}
void transformSting(string a)
{
	string b = delete_vowels(a);
	string c = change_case(b);
	string d = insert_hash(c);

	cout << d;
}
int main()
{
	string p = "SunshinE!!";
	transformSting(p);
    obj * temp=strToBinary(p);
    string    q=taken(p);
    obj* temp2=strToBinary(q);
    cout<<endl;
    print(temp2->data);
    print(temp->data);
    cout<<endl;
	return 0;
}

