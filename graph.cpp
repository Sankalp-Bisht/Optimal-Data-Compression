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

        if(i>40)
        {
            cout<<"      +"<<k-i*10;
            break;
        }
    }

    cout<<endl;
    cout<<"    X     ";

    for(int i=1;i<=k/10;i++)
    {
        cout<<"* ";
        if(i>40)
        {

            break;
        }
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
            // convert each char to
           // ASCII value
          // Convert ASCII value to binary
         // cout << bin ;
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



   /* for(int i=0;i<bin.length();i++)
    {
        string p=bin[i];
        sum=sum+p.length();
    }
    cout<<sum;*/
}

vector<int> LZWencoding(string s1)
{
   // cout << "Encoding\n";
    map<string, int> table;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);
        table[ch] = i;
    }

    string p = "", c = "";
    p += s1[0];
    int code = 256;
    vector<int> output_code;
   // cout << "String\tOutput_Code\tAddition\n";
    for (int i = 0; i < s1.length(); i++) {
        if (i != s1.length() - 1)
            c += s1[i + 1];
        if (table.find(p + c) != table.end()) {
            p = p + c;
        }
        else {
         //   cout << p << "\t" << table[p] << "\t\t"
          //       << p + c << "\t" << code << endl;
            output_code.push_back(table[p]);
            table[p + c] = code;
            code++;
            p = c;
        }
        c = "";
    }
   // cout << p << "\t" << table[p] << endl;
    output_code.push_back(table[p]);
    return output_code;
}
/*
void decoding(vector<int> op)
{
    cout << "\nDecoding\n";
    map<int, string> table;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);
        table[i] = ch;
    }
    int old = op[0], n;
    string s = table[old];
    string c = "";
    c += s[0];
    cout << s;
    int count = 256;
    for (int i = 0; i < op.size() - 1; i++) {
        n = op[i + 1];
        if (table.find(n) == table.end()) {
            s = table[old];
            s = s + c;
        }
        else {
            s = table[n];
        }
        cout << s;
        c = "";
        c += s[0];
        table[count] = table[old] + c;
        count++;
        old = n;
    }
}
*/


string gen_compressed_str(string str)
{
    int len = str.length();
    string str1="";
    stringstream ss;

    for (int i = 0; i < len; i++) {


        int count = 1;
        while (i < len - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }

        if (count == 1)
        {
          str1=str1+str[i];
        }
        else
        {
            ss<<count;
          str1=str1+str[i]+ss.str();
        }

    }
    return str1;
}

string Integer_Converion_If_Number_is_Multiple_of_10(int k)
{

    double p=log(k);

    stringstream ss;
    ss<<p;
    return ss.str();
}



struct rotation {
    int index;
    char* suffix;
};

int cmpfunc(const void* x, const void* y)
{
    struct rotation* rx = (struct rotation*)x;
    struct rotation* ry = (struct rotation*)y;
    return strcmp(rx->suffix, ry->suffix);
}

int* computeSuffixArray(char* input_text, int len_text)
{

    struct rotation suff[len_text];


    for (int i = 0; i < len_text; i++) {
        suff[i].index = i;
        suff[i].suffix = (input_text + i);
    }

    qsort(suff, len_text, sizeof(struct rotation),
          cmpfunc);

    int* suffix_arr
        = (int*)malloc(len_text * sizeof(int));
    for (int i = 0; i < len_text; i++)
        suffix_arr[i] = suff[i].index;

    return suffix_arr;
}

char* findLastChar(char* input_text,
                   int* suffix_arr, int n)
{
    char* bwt_arr = (char*)malloc(n * sizeof(char));
    int i;
    for (i = 0; i < n; i++) {
        int j = suffix_arr[i] - 1;
        if (j < 0)
            j = j + n;

        bwt_arr[i] = input_text[j];
    }

    bwt_arr[i] = '\0';
    return bwt_arr;
}



/*
void printRLE(string str)
{
    int n = str.length();
    for (int i = 0; i < n; i++) {

        // Count occurrences of current character
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }

        // Print character and its count
        cout << str[i] << count;

    }
}


*/


int main()
{


    string p="Sankalp likes to dance with his batchmates";
    obj * temp3=strToBinary(p);
string    q=gen_compressed_str(p);
    obj* temp4=strToBinary(q);
    cout<<endl;



   /* int k=1000000000000000000;
    stringstream ss;
    ss<<k;
    obj* temp3=strToBinary(ss.str());
    string z=Integer_Converion_If_Number_is_Multiple_of_10(k);
    obj* temp4=strToBinary(z);*/




    print(temp3->data);
    print(temp4->data);

    cout<<endl;


  //  printRLE(temp->da);

    cout<<endl;

    char input_text[] = "aaaabbbbbaaaaacccccaaaaa$";
     int len_text = strlen(input_text);


     int* suffix_arr = computeSuffixArray(input_text, len_text);
     char* bwt_arr   = findLastChar(input_text, suffix_arr, len_text);
     string    t=gen_compressed_str(bwt_arr);

     obj* temp5=strToBinary(t);

     print(temp5->data);

     vector<int> neww=LZWencoding(p);
     stringstream ss;
     string str="";
     for(int i=0;i<neww.size();i++)
     {
         ss<<neww[i];
         str=str+ss.str();
     }

     obj *temp6=strToBinary(str);
     print(temp6->data);








   // strToBinary("Thats My Spot");

  /*print(4);
    print(1);
    print(2);
    print(6);
    print(7);
    print(9);
    print(4);*/
}

