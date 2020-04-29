#include <bits/stdc++.h>
#include <conio.h>

using namespace std;
map<char, int> freq;
map<char, string> codes;

struct MinHeapNode
 {
	char data;
	unsigned freq;
	MinHeapNode *left, *right;
	MinHeapNode(char data, unsigned freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};
struct compare
{
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};
void printCodes(struct MinHeapNode* root, string str)
{
	if (!root)
		return;
	if (root->data != '$')
		cout << root->data << ": " << str << "\n";
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}
void storeCodes(struct MinHeapNode* root, string str)
{
	if (root==NULL)
		return;

	if (root->data != '$')
		codes[root->data]=str;
	storeCodes(root->left, str + "0");
	storeCodes(root->right, str + "1");
}
void HuffmanCodes(char data[], int freq[], int size)
{
	struct MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
	for (int i = 0; i < size; ++i)
		minHeap.push(new MinHeapNode(data[i], freq[i]));
	while (minHeap.size() != 1) {
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	printCodes(minHeap.top(), "");
	storeCodes(minHeap.top(), "");
}



int main()
{

    string  decodedString,encodedString;
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    string str="abacadbcbdcd";
	int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size=sizeof(arr)/sizeof(arr[0]);

    int n,i,j,k;

    cout<<"n:";
    cin>>n;
    cout<<endl;
    cout<<"output:";
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            cout<<arr[i]<<arr[j]<<" ";

        }
    }

  cout<<endl;
    HuffmanCodes(arr, freq,size );

        for (  auto i: str)
		encodedString+=codes[i];
        cout << "\nEncoded Huffman data:\n" << encodedString << endl;


    return 0;
}
