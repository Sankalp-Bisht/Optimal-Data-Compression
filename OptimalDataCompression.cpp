#include<bits\stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include <cstdlib>
#include <cstring>


using namespace std;

long long int stack_i[1000],top_i=-1,count=1;

COORD coord={0,0};
void gotoxy(int x,int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void delay(int number_of_seconds)
{

    int milli_seconds = 15* number_of_seconds;

        clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
        ;
}
void drawbox(int x1, int y1, int x2, int y2, int d)
{
    gotoxy(x1,y1);
    printf("+");
    delay(d);
    gotoxy(x2,y2);
    printf("+");
    delay(d);
    for(int i=1;i<x2-x1;i++)
    {   gotoxy(x1+i,y1);
        printf("-");
        printf("\a");
        delay(d);
        gotoxy(x2-i,y2);
        printf("-");
        delay(d/2);
    }
    gotoxy(x1,y2);
    printf("+");
    gotoxy(x2,y1);
    printf("+");
    for(int j=1;j<y2-y1;j++)
        {
            gotoxy(x2,y1+j);
            printf("|");
            delay(d);
            gotoxy(x1,y2-j);
            printf("|");
            delay(d/2);
        }
}
void credits()
{
    gotoxy(50,6);
    printf("PRESENTED TO YOU BY:-");
    delay(30);
    gotoxy(54,8);

    printf("SANKALP SINGH BISHT");
    delay(30);
    gotoxy(54,9);


    printf("PUNIT JAIN");
    delay(30);
    gotoxy(54,10);

    printf("SHIVAM SINGHAL");
    delay(30);

    cout<<endl<<endl<<endl<<endl;


}

class obj
{
public:

    int data;
    string bitstring;

};
void print(int k,string comtech)
{
    cout<<k<<" - "<<comtech<<endl<<"   "<<" X     ";
    for(int i=1;i<=k/10;i++)
    {
        cout<<"* ";
        delay(1);

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
        delay(1);
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

    delay(5);

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
    temp->bitstring=binT;
    return temp;

}
string gen_compressed_str(string str)
{
    int len = str.length();
    string str1="";
    stringstream ss;
    vector<int>Hash;

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
            Hash.push_back(count);
          str1=str1+str[i]+ss.str();
        }

    }
    return str1;
}

string getRoman(string input)
{
    long long int number;
    stringstream num1(input);
    num1<<number;
	int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
	string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
long i=12;

string p="";
	while(number>0)
	{
	long div = number/num[i];
	number = number%num[i];
	while(div--)
	{
		p=p+sym[i];
	}
	i--;
	}
	return p;
}

string Simple_Log_Conversion(string k)
{
    int i=0;
    long long int k2=0;
    while(i<k.length())
    {
       k2=k2*10+k[i];
       i++;
       } double p=log(k2);

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
		if(a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u' && a[i] != 'A' && a[i] != 'E' && a[i] != 'O' &&a[i] != 'U'&& a[i] != 'I')
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
string transformSting(string a)
{
	string b = delete_vowels(a);
	string c = change_case(b);
	string d = insert_hash(c);

	return d;
}





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

int checkMin(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;
}



bool isInteger(string s)
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		if(int(s[i])<48 || int(s[i])>57)
		{
			return false;
		}
	}
	return true;

}
bool isInTens(string s)
{
	int flag=0;
	if(isInteger(s))
	{

		for(int i=1;s[i]!='\0';i++)
		{
			if(int(s[i])==48)
			{
				flag=1;
			}
			else
			{
				flag=0;
				break;
			}
		}
		if(flag==0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	return false;
}



#define MAX_TREE_HT 100

struct MinHeapNode {


    char data;


    unsigned freq;


    struct MinHeapNode *left, *right;
};

struct MinHeap {


    unsigned size;


    unsigned capacity;


    struct MinHeapNode** array;
};

struct MinHeapNode* newNode(char data, unsigned freq)
{
    struct MinHeapNode* temp
        = (struct MinHeapNode*)malloc
(sizeof(struct MinHeapNode));

    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}

struct MinHeap* createMinHeap(unsigned capacity)

{

    struct MinHeap* minHeap
        = (struct MinHeap*)malloc(sizeof(struct MinHeap));

    minHeap->size = 0;

    minHeap->capacity = capacity;

    minHeap->array
        = (struct MinHeapNode**)malloc(minHeap->
capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a,
                    struct MinHeapNode** b)

{

    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx)

{

    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->
freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->
freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest],
                        &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct MinHeap* minHeap)
{

    return (minHeap->size == 1);
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap)

{

    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0]
        = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

void insertMinHeap(struct MinHeap* minHeap,
                struct MinHeapNode* minHeapNode)

{

    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {

        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap)

{

    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout<< arr[i];

    cout<<"\n";
}

int isLeaf(struct MinHeapNode* root)

{

    return !(root->left) && !(root->right);
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)

{

    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)

{
    struct MinHeapNode *left, *right, *top;

    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

void printCodes(struct MinHeapNode* root, int arr[], int top)

{

    if (root->left) {

        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {

        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {

        cout<< root->data <<": ";
        printArr(arr, top);
    }
}

void HuffmanCodes(char data[], int freq[], int size)

{
    struct MinHeapNode* root
        = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;

    printCodes(root, arr, top);
}

int* getCharWithFreq(string str)
{
    int n = str.size();

   int* freq;

    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < n; i++)
        freq[str[i] - 'a']++;

    for (int i = 0; i < n; i++) {

        if (freq[str[i] - 'a'] != 0) {



            freq[str[i] - 'a'] = 0;
        }
    }
	return freq;
}

char *removeDuplicate(char str[], int n)
{

   int index = 0;


   for (int i=0; i<n; i++) {


     int j;
     for (j=0; j<i; j++)
        if (str[i] == str[j])
           break;


     if (j == i)
        str[index++] = str[i];
   }

   return str;
}



int main()
{


	credits();
	delay(50);


    string p;
    cout<<"Enter string you want to compress ";
    cin>>p;


    obj * temp3=strToBinary(p);
  string   q=gen_compressed_str(p);



    obj* temp4=strToBinary(q);
    cout<<endl;




    print(temp3->data,"Original String");
    print(temp4->data,"String Generated After Run Length Encoding");

    cout<<endl;

    int Min=temp3->data;

    Min=checkMin(Min,temp4->data);


    cout<<endl;

    char input_text[p.length()+2];
        strcpy(input_text,p.c_str());
        input_text[p.length()+1]='$';
     int len_text = strlen(input_text);


     int* suffix_arr = computeSuffixArray(input_text, len_text);
     char* bwt_arr   = findLastChar(input_text, suffix_arr, len_text);
     string    t=gen_compressed_str(bwt_arr);

     obj* temp5=strToBinary(t);
     print(temp5->data,"String generated after Conversion by rotating variable ");

    Min=checkMin(Min,temp5->data);


     string transfor=transformSting(p);



     obj* temp6=strToBinary(transfor);

     print(temp6->data,"String generated after Changing variable into different languages");

    Min=checkMin(Min,temp6->data);

     int hexValue=SHF(p);

     stringstream getValue;
     getValue<<hexValue;

     string finalHex=toHex(hexValue);

     obj* temp7=strToBinary(finalHex);

     print(temp7->data,"One Way Hex Function");
     Min=checkMin(Min,temp7->data);

     obj* temp8=strToBinary(getValue.str());

     print(temp8->data,"Second type of Hex Function");
     obj* temp9;

     if(isInteger(p)&&isInTens(p))
      {
        temp9=strToBinary(Simple_Log_Conversion(p));
        print(temp9->data,"Simple log Conversion");
        Min=checkMin(Min,temp9->data);

     }
     obj* temp10;
     if(isInteger(p))
     {
         string get_roman=getRoman(p);
         string get_roman_final=gen_compressed_str(get_roman);
         temp10=strToBinary(get_roman_final);

         print(temp10->data,"Changing To Roman Number");
         Min=checkMin(Min,temp10->data);
     }



     Min=checkMin(Min,temp8->data);


     cout<<endl<<endl<<endl<<endl;
     delay(50);

     cout<<"Minimum number of BITS used are: "<<Min;

     cout<<endl<<endl<<endl<<endl;
     delay(50);
     cout<<"To read BINARY STRING generated by compression choose from option"<<endl;
     delay(30);
     cout<<"Press 1: Original String"<<endl<<endl;
     cout<<"Press 2: RLE compression"<<endl<<endl;
     cout<<"Press 3: Borrower's Wheel Transformation"<<endl<<endl;
     cout<<"Press 4: Transformation String"<<endl<<endl;
     cout<<"Press 5: OneWayHashFunction"<<endl<<endl;
     cout<<"Press 6: StringHshFunction"<<endl<<endl;
     cout<<"Press 7: If number is integer and multiple of 10"<<endl<<endl;
     cout<<"Press 8: If number is integer and Roman Conversion"<<endl<<endl;
     cout<<"Press 9: To Exit"<<endl<<endl;

     int n;

     do{

     cin>>n;

     switch(n)
     {
     case 1:
        cout<<temp3->bitstring<<endl;
        break;
     case 2:
        cout<<temp4->bitstring<<endl;
        break;
     case 3:
        cout<<temp5->bitstring<<endl;
        break;
     case 4:
         cout<<temp6->bitstring<<endl;
        break;
     case 5:
         cout<<temp7->bitstring<<endl;
        break;
     case 6:
         cout<<temp8->bitstring<<endl;
        break;
     case 7:
        cout<<temp9->bitstring<<endl;
        break;
     case 8:
        cout<<temp10->bitstring<<endl;
        break;
     }
     }while(n!=9);



    cout<<"Demonstration of Working of Huffman tree using a Min Heap"<<endl;

    cout<<"enter variable and frequency for building the tree"<<endl;
    char arr[5];
    int freq[5];

    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<5;i++)
    {
        cin >>freq[i];
    }

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);



     cout<<endl;
     cout<<endl;
     cout<<endl;
     cout<<endl;
     cout<<endl;



}

