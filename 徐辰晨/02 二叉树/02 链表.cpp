#include<iostream>
using namespace std;
//template<typename T>
class tree
{
public:
    int data;
    tree *lchild;
    tree *rchild;
};
void push(tree*H,int x)
{
    tree*s=new tree;
    tree*p=new tree;
    tree*t=H;
    s->data=x;
    s->lchild=NULL;
    s->rchild=NULL;
    if(H->data==NULL)
        H->data=x;
    else
    {
        tree *p=H;
        while(p)
        {
            if(x<p->data)
            {
                if(p->lchild==NULL)
                {
                    p->lchild=s;
                }
                else
                    p=p->lchild;
            }
            else
            {
                if(p->rchild==NULL)
                {
                    p->rchild=s;
                }
                else
                    p=p->rchild;
            }
        }
    }
}
void show(tree *H,int q)
{
    tree *p=H;
   if(p)
   {
       cout<<p->data;
       show(p->lchild,q);
       show(p->rchild,q);
   }
}
int main()
{
    tree*H=new tree;
    H->data=NULL;
    H->lchild=NULL;
    H->rchild=NULL;
    int n;
    int i;
    int a[1000];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        push(H,a[i]);
    }
    for(i=0;i<n;i++)
    {
        show(H,a[i]);
    }
}
