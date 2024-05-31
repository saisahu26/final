#include "bst.h"

bst::bst(){root = NULL;}

void bst::build() {
  srand((unsigned)time(0));
  int arrayLength = rand()%5+10;
  int values[arrayLength];
  for (int a = 0; a < arrayLength; a++){values[a] = -1;}
  for (int a = 0; a < arrayLength; a++) {
    bool duplicate = false;
    do {
      duplicate = false;
      values[a] = rand()%30+1;
      for (int b = 0; b < arrayLength; b++) {
        if ((a != b) && (values[a] == values[b])) {duplicate = true;}
      }
    } while (duplicate == true);
  }
  for (int a = 0; a < arrayLength; a++) {
    node* newnode = new node();
    newnode->data = values[a];
    node* current = root;
    if (root == NULL) {
      root = newnode;
    }
    else {
      while(current != NULL) {
        if (newnode->data < current->data) {
          if (current->left == NULL) {
            current->left = newnode;
	    break;
	  }
	  else {
            current = current->left;
	  }
	}
	else {
          if (current->right == NULL) {
            current->right = newnode;
	    break;
	  }
	  else {
            current = current->right;
	  }
	}
      }
    }
  }
}

void bst::display_tree(node* current, int level) {
  if (current->right != NULL) {display_tree(current->right, level+1);}
  for (int a = 0; a < level; a++) {cout << "\t";}
  cout << current->data << " (";
  if (current->left != NULL) cout << current->left->data << ",";
  else cout << ",";
  if (current->right != NULL) cout << current->right->data << ")" << endl;
  else cout << ")" << endl;
  if (current->left != NULL) {display_tree(current->left, level+1);}
}

void bst::display() {
  cout << "---------Tree Printout----------" << endl;
  display_tree(root, 0);
  cout << "--------------------------------" << endl;
}

void bst::pred(node* current){
  
  
  if (current->right != NULL) {
    pred(current->right);
  }
  else {
    cout << "the pred is" << current->data << endl;
  }
}

void bst::preddisplay(){
  if (root->left == NULL) {
    return;
  }
  else {
    pred(root->left);
  }
}


void bst::small(node* parent, node* child, int count) {
  if (child->left != NULL) { //traverse left
    cout << "child-> != null " << endl;
    small(child, child->left, count);
    return;
  }
  else if (child->left == NULL &&  child->right != NULL) { //if right child, set parent left to child right
    cout << "entered first loop" << endl;
    parent->left = child->right;
    cout << "deleting child" << child->data <<  endl;
    delete child;
    child = parent->left;
    cout << "parent is" << parent->data << endl;
    return;
  }
  else if (child->left == NULL && child->right == NULL) { //if there is no child, delete child and parent 
    cout << " inside child left && right == null " << endl;
    cout << "deleting" << child->data << endl;
    delete child;
    parent->left = NULL;
    cout << "parent is" << parent->data << endl;
    return;
  }
}

void bst::small_display(int count){
  node* temp = root;
  if (temp->left == NULL) {
    return;
  }
  else {
    small(temp, temp->left, count);

  cout << "---------Tree Printout after first delete ----------" << endl;
  display_tree(root, 0);
  cout << "--------------------------------" << endl;
    temp = root;
    if (temp->left == NULL){
      return;
    }
    else {
      small(temp, temp->left, count);
    }
    
  }
}

  

void bst::del_display(){
  node* temp = root;
  if (temp->right == NULL) {
    return;
  }
  else {
    cout << " entering into delete func " << (temp->right)->data << endl;
    del(temp->right);
    temp->right = NULL;

  }
  
}

void bst::del(node* child) {
  if (child == NULL) {
   return;
  }
  if (child != NULL ) del(child->left);
  if (child != NULL ) del(child->right);
  
  delete child;
  child = NULL;
  
  // return; 
}
