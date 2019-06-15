#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

struct node{
string vl;
node *next;
};

node *shtoElement(node *koka, string vl)
{
node* cursor=koka;
while(cursor!=NULL){
	if(cursor->vl==vl)
	return koka;
	cursor=cursor->next;
}
node * tmp = new node;
tmp->vl = vl;
tmp->next = koka;

return tmp;
}

int llogaritHash(string celes)
{
	if((int)celes[0]<=90&&(int)celes[0]>=65)
	return (int)celes[0]%65;
	else if((int)celes[0]>=97&&(int)celes[0]<=122)
    return (int)celes[0]%97;
    else return -1;
}

string strip(string in) 
  {
  in.erase(remove_if(in.begin(), in.end(), [] (string::value_type ch)
      { return !isalpha(ch); }
    ), in.end());
  return in;
  }

int main() {
    int nrElementesh = 26; 
    node *tabelaHash[nrElementesh];
    string celes;
    for(int i=0; i<nrElementesh; i++)
    tabelaHash[i]=NULL;
	
	ifstream inFile;
	inFile.open("data.txt");
	if (!inFile) {
    cout << "gabim";
    exit(1);
    }
    while (inFile >> celes)
    {
    	celes=strip(celes);
    	int vlHash = llogaritHash(celes);
    	if (vlHash==-1)
    	continue;
        tabelaHash[vlHash] = shtoElement(tabelaHash[vlHash],celes);
	}
         
    inFile.close();


    for(int i=0; i<nrElementesh; i++)
    {
    node *l = tabelaHash[i];
    cout<<"elementet ne pozicionin "<<i<<" jane:";
    while(l!=NULL)
    {
    cout<<l->vl<<" ";
    l = l->next;
    }
    cout<<"\n";
    }
    return 0;
}
