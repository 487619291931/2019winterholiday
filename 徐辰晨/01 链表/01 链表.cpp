#include<iostream>
#include<string>
using namespace std;
class A
{
public:
    int data;
    string xingming;
    A *next;
    //H->next=NULL;
};
void push(A *H,int t,string o)
{
    A *p=H;
    A *s=new A;
    while(p->next)
    {
        p=p->next;
    }
    p->next=s;
    s->data=t;
    s->xingming=o;
    s->next=NULL;
}
void show(A *H)
{
    A *p=H;
    while(p)
    {
        cout<<p->data<<p->xingming;
        p=p->next;
    }

}
A* pop(A*H)
{
     H=H->next;
     show(H);
}
A*zhengjia(A*H,int m,string o)
{
    A *p=H;
    A *x=new A;
    //p=p->next;
    x->next=p->next;
    p->next=x;
    x->data=m;
    x->xingming=o;
    show(H);
}
void search(A*H,int n,string o)
{
    A *p=H;
    for(int i=1;i<n;i++)
    {
        p=p->next;
    }
    cout<<p->data<<p->xingming<<endl;
}
void gai(A*H,int q,int w,string o)
{
    A*p=H;
    for(int i=1;i<q;i++)
    {
        p=p->next;
    }
    p->data=w;
    p->xingming=o;
    show(H);
}
int main()
{
    int n;
   // string Q,W,E,R,T,U;
    A*H=new A;
    H->data=1;
    H->xingming="zhangsan";
    H->next=NULL;
    push(H,2,"lisi");
    push(H,3,"xiaoming");
    show(H);
    zhengjia(H,9,"xiaohong");
    cin>>n;
    search(H,n,"lixiaoming");
    gai(H,2,8,"lihua");
    H=pop(H);
    pop(H);
}
