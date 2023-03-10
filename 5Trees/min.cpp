#include<iostream>
#include<string>
#include"queue.h"
using namespace std;

class Tree{
    Node * Root;
    public:
    Tree(){
        Root =NULL;
    }

    void create_tree(){
        Queue q(20);
        int x;
        Node *t,*p;
        
            cout<<"Enter root value"<<endl;
            cin>>x;
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            Root = t;
            q.enqueue(t);

            while (!q.isEmpty())
            {
                p = q.dequeue();
                cout<< "Enter left child of", p->data;
                cin>>x;
                if(x != -1){
                    t = new Node;
                    t->data = x;
                    t->lchild = t->rchild =NULL;
                    p->lchild = t;
                    q.enqueue(t);
                }
                cout<< "Enter right child of", p->data;
                cin>>x;
                if(x != -1){
                    t = new Node;
                    t->data = x;
                    t->lchild = t->rchild =NULL;
                    p->rchild = t;
                    q.enqueue(t);
                }

            }
            
        }
    void preorder(){preorder(Root);};
    void preorder(Node* p){
        if(p){
            cout<<p->data;
            preorder(p->lchild);
            preorder(p->rchild);
        }

    }
    
    void postorder(){postorder(Root);};
    void postorder(Node* p){
        if(p){
            postorder(p->lchild);
            postorder(p->rchild);
            cout<<p->data;
            }

    }
    void inorder(){inorder(Root);};
    void inorder(Node* p){
        if(p){
            inorder(p->lchild);
            cout<<p->data;
            inorder(p->rchild);
            
            }

    }
    
    void levelorder(){levelorder(Root);}
    void levelorder(Node* Root){
        Queue m(50);
        Node *p;
        cout<<Root->data;
        m.enqueue(Root);
        while(!m.isEmpty()){
            p = m.dequeue();
            if(p->lchild){
                cout<<p->lchild->data;
                m.enqueue(p->lchild);
            }
            if (p->rchild){
                cout<<p->rchild->data;
                m.enqueue(p->rchild);

            }
            
            
        }


    }




void IPreorder(Node *p)
{
  Stack stk;
 while(p || !stk.isEmpty())
 {
 if(p)
 {
 cout<<p->data;
 stk.push(p);
 p=p->lchild;
 }
 else
 {
 p=stk.pop();
 p=p->rchild;
 }
 }
}
void IInorder( Node *p)
{
  Stack stk;
 
 while(p || !stk.isEmpty())
 {
 if(p)
 {
 stk.push(p);
 p=p->lchild;
 }
 else
 {
 p=stk.pop();
 cout<<p->data;
 p=p->rchild;
 }
 }
}

int count(){return count(Root);}
int count(Node *p){
    if (p)
    {
        return count(p->lchild)+count(p->rchild)+1;
    }
    return 0;

}



int height(){return height(Root);}
int height(Node *p){
    int x,y;
    if (p)
    {   x=height(p->lchild);
        y=height(p->rchild);
        if(x>y){ 
            if(p!=Root)
            {   return x+1;
            }
           else
            return x;
            }
        else{ 
            if(p!=Root)
            {   return y+1;
            }
           else
            return y;
            }

    }
    return 0;

}

};


int main(){
    Tree t;
    t.create_tree();
    t.inorder();
    cout<<"\n";
    t.levelorder();
    cout<<"\n"<<t.count();
    cout<<"\n"<<t.height();
}