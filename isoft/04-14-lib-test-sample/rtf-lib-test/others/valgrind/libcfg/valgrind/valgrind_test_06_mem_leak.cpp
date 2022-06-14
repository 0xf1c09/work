#include <stdlib.h>
#include <iostream>

typedef struct _node{
    struct _node *l;
    struct _node *r;
    char v;
}node;

node *mk(node *l,node *r,char val);
void nodefr(node *n);

int main()
{
    node *tree1,*tree2,*tree3;
    tree1=mk(mk(mk(0,0,'3'),0,'2'),0,'1');
    tree2=mk(0,mk(0,mk(0,0,'6'),'5'),'4');
    tree3=mk(mk(tree1,tree2,'8'),0,'7');
    return 0;
}

node *mk(node *l,node *r,char val)
{
    node *f=(node *)malloc(sizeof(*f));
    f->l=l;
    f->r=r;
    f->v=val;
    return f;
}

void nodefr(node *n)
{
    if(n){
        nodefr(n->l);
        nodefr(n->r);
        free(n);
    }
}
