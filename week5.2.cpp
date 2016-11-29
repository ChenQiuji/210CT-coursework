#include<iostream>
using namespace std;
class Node{
public:
    int value;
    Node*next;
    Node*prev;
    Node(int val){
       cout << "Node constructr!" <<endl;
       this->value=val;
       this->next=(Node*)0;
       this->prev=(Node*)0;
      }
   ~Node(){
      //delete Node
     }
};
class List{
public:
    Node*head;
    Node*tail;
List(){
    this->head=0;
    this->tail=0;
    }
~ List(){}

  void insert (Node*n,Node*x){
	if(n!=0){
		x->next=n->next;
		n->next=x;
		x->prev=n;
		if(x->next!=0){
			x->next->prev=x;
		}
	}
	if(this->head==0){
		this->head=x;
		this->tail=x;
		x->prev=0;
		x->next=0;
	}
	else if(this->tail=n)
	      this->tail=x; 
}
  void remove (Node*n){
    if(n->prev!=0)
        n->prev->next=n->next;
    else this->head=n->next;
    if(n->next!=0)
        n->next->prev=n->prev;
    else this->tail=n->prev;

}
  void display(){
    Node* i=this->head;
    cout << "List: " ;
    while(i!=0){
    cout << i->value << ",";
    i=i->next;
    }
 }
};
int main(){
   List*a=new List();
   a->insert(0,new Node(4));
   a->insert(a->head,new Node(3));
   a->insert(a->head,new Node(2));
   a->remove(a->head->next);
   a->display();
   return 0;

}

