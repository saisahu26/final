#include "bst.h"

int main()
{
    bst object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */
    //    int count = 0;
    //    object.preddisplay();
    int count = 0;
    //    object.small_display(count);
    object.del_display();
    object.display();	//displays again after!
   
    return 0;
}
