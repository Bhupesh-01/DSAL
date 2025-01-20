/*
Question: A book consists of chapters, chapters consist of sections and 
sections consist of subsections. Construct a tree and print the nodes. 
Find the time and space requirements of your method.
*/

#include<iostream>
#include<string.h>
using namespace std;

struct node{
	string label;
	int ch_count;
	struct node* child[10];
}*root;

class Tree{
	public:
		Tree(){
			root = NULL;
		}
		string lbel;
		int count;
		
		void create(){
				root = new node;
				cout<<"Name of the book:\t";
				cin>>root->label;
				cout<<"Number of chapters:\t";
				cin>>root->ch_count;
				
				for(int i=0;i<root->ch_count;i++){
					root->child[i] = new node;
					cout<<"Name of chapter "<< i+1 <<":\t";
					cin>>root->child[i]->label;
					cout<<"Number of sections:\t";
					cin>>root->child[i]->ch_count;

					for(int j=0;j<root->child[i]->ch_count;j++){
						root->child[i]->child[j] = new node;
						cout<<"Name of section "<< i+1 <<" - "<< j+1<< ":\t";
						cin>>root->child[i]->child[j]->label;
						cout<<"Number of sub-sections:\t";
						cin>>root->child[i]->child[j]->ch_count;
						
						for(int k=0;k<root->child[i]->child[j]->ch_count;k++){
							root->child[i]->child[j]->child[k] = new node;
							cout<<"Name of sub-section "<< i+1 <<" - "<< j+1<< " - "<< k+1<< ":\t";
							cin>>root->child[i]->child[j]->label;

						}
					}
				}
		} 
		
		void display(node * r){
				cout<<endl<<"Name of book:\t";
				cout<<root->label<<endl;
				cout<<endl<<"Number of chapters:\t";
				cout<<root->ch_count<<endl;
			
				for(int i=0;i<root->ch_count;i++){
						cout<<endl<<"Name of chapter:\t";
						cout<<root->child[i]->label<<endl;
						cout<<endl<<"Number of sections:\t";
						cout<<root->child[i]->ch_count<<endl;

						for(int j=0;j<root->child[i]->ch_count;j++){
							cout<<"\t\t"<< i+1 <<" - "<< j+1<< " Name of sections: ";
							cout<<root->child[i]->child[j]->label<<endl;
							cout<<"\t\tNumber of sub-section: ";
							cout<<root->child[i]->child[j]->ch_count<<endl;
							
							for(int k=0;k<root->child[i]->child[j]->ch_count;k++){
								cout<<"\t\t\t"<< i+1 <<" - "<< j+1<< " - "<< k+1<< " Name of sub-section: ";
								cout<<root->child[i]->child[j]->label<<endl;
							}
						}
			}
		}
};


int main(){
	Tree obj;
	
	while(1){
		cout<<"--- MAIN MENU ---"<<endl;
		cout<<"1 -> Add book info"<<endl;
		cout<<"2 -> Display info"<<endl;
		cout<<"3 ->Exit"<<endl;
		cout<<"Choose an option (1-3):\t";
		int ch;
		cin>>ch;

		switch(ch){
			case 1:
				obj.create();
				break;
			case 2:
				obj.display(root);
				break;
			case 3:
			 	cout<<endl<<"// DONE CODE\n\n";
				exit(0);
				break;
			default:
				cout<<"Please choose a valid option (1-3).";
				break;
		}
	}
}

