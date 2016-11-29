#include<iostream>
#include<stack>
using namespace std;
class BinTreeNode{
public:
    BinTreeNode(int value){
      this->value=value;
      this->left=NULL;
      this->right=NULL;
      }
      int value;
      BinTreeNode*left;
      BinTreeNode*right;
    };

BinTreeNode*tree_insert(BinTreeNode*tree,int item){
                  if(tree==NULL)
                    tree=new BinTreeNode(item);
                  else
                    if(item<tree->value)
                       if(tree->left==NULL)
                          tree->left=new BinTreeNode(item);
                       else
                         tree_insert(tree->left,item);
                    else
                        if(tree->right==NULL)
                            tree->right=new BinTreeNode(item);
                        else
                            tree_insert(tree->right,item);
                    return tree;
                  }
void postorder(BinTreeNode* tree){
  if(tree->left!=NULL)
    postorder(tree->left);
  if(tree->right!=NULL)
    postorder(tree->right);
  std::cout << tree->value << std::endl;
}

BinTreeNode* inorder(BinTreeNode*tree){
	stack<BinTreeNode*>s; 
    BinTreeNode*p=tree;//point at root
	while(!s.empty() || p!= NULL){//push into stack
      if(p!=NULL){
      s.push(p);
	  p=p->left;
	  }
	  //point at left of current node
      else{
	     if(!s.empty()){//current node have no left child &stack is not empty
    	    p = s.top();
		    s.pop();//pop current node
            cout<<p->value<<endl;
		    p=p->right;
      }
	  }
      
    }
    return tree; 
}
/*void in_order(BinTreeNode* tree){
  if(tree->left!=NULL)
    in_order(tree->left);
  std::cout << tree->value << std::endl;
  if(tree->right!=NULL)
    in_order(tree->right);    
}*/
int main(){
BinTreeNode* t=tree_insert(0,6);
 tree_insert(t,10);
 tree_insert(t,5);
 tree_insert(t,2);
 tree_insert(t,3);
 tree_insert(t,4);
 tree_insert(t,11);
 inorder(t);
 /*in_order(t);*/
 return 0; 
}
