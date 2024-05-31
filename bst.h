//bst.h
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

struct node
{
    int data;   //some questions use char * data;
    node * left;
    node * right;
};

class bst
{
    public:
    	//These functions are supplied already
    	bst();			//supplied
        void build(); 		//supplied
        void display();
  void preddisplay();
  void small_display(int count);
  void del_display();
  //supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
 
 
 	private:
 		node * root;
		void display_tree(node*, int);
  void pred(node* current);
  void small(node* parent, node* child, int count);
  void del( node* child);
};
  

