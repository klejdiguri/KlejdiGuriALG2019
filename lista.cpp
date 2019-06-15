#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

struct node{
	string vl;
	node *next;
};

class Liste{
	private:
	 node *head;
	public:
		Liste(){
			head=NULL;
		}
		
		void shto(string k){
			node *cursor=head;
			
			while(cursor!=NULL){
				if(cursor->vl==k)
				return;
				cursor=cursor->next;
			}
		    node *tmp=new node;
			tmp->vl=k;
			tmp->next=NULL;
		    if(head==NULL)
		    	head=tmp;
		    else {
			    tmp->next=head;
			    head=tmp;
			}
		    
			
			
		}
	
		
		void print(){
			node *cursor=head;
			int c=0;
			if(cursor==NULL)
			cout<<"lista bosh\n";
			while(cursor!=NULL){
			cout<<cursor->vl<<" ";
			c++;
			cursor=cursor->next;
		    }
		    cout<<c;
		}
		
};

string strip(string in) 
  {
  in.erase(remove_if(in.begin(), in.end(), [] (string::value_type ch)
      { return !isalpha(ch); }
    ), in.end());
  return in;
  }

int main(){
	Liste l;
	string x;
	
	ifstream inFile;
	inFile.open("data.txt");
	if (!inFile) {
    cout << "gabim";
    exit(1);
    }
    while (inFile >> x)
         l.shto(strip(x));
         
    inFile.close();
	l.print();
	return 0;
}
