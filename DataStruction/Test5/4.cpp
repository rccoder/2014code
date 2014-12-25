#define t 2
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    int leaf;
    int keys[2*t-1];
    struct node *children[2*t];
};
struct node *root;
int index;
void b_tree_create(void);
void b_tree_spilt_child(struct node *,int,struct node *);
void b_tree_insert(int);
void b_tree_walk(struct node *);
struct node *b_tree_search(struct node *,int);
int b_tree_delete(struct node *,int);
#include <stdio.h>
main()
{
    int i;
    struct node *m;
    clrscr();
    b_tree_create();
    b_tree_insert(2);
    b_tree_insert(8);
    b_tree_insert(7);
    b_tree_insert(1);

    b_tree_insert(3);
    b_tree_insert(5);
    b_tree_insert(6);
    b_tree_insert(4);

    b_tree_walk(root);

    if(b_tree_delete(root,8)==1) printf("ok");
    else printf("no");

    b_tree_walk(root);
}
int b_tree_delete(struct node *x,int k)
{
    int i;
    int j;
    i=0;
    while(i<=x->num-1&&k>x->keys[i])
    {
        i++;
    }

    if(i<=x->num-1&&k==x->keys[i])
    {
        if(x->leaf)
        {
            for(j=i+1; j<=x->num-1; j++)
            {
                x->keys[j-1]=x->keys[j];
            }
            x->num--;
            return 1;
        }
        else
        {
            struct node *y;
            struct node *z;
            y=x->children[i];
            z=x->children[i+1];
            if(y->num>=t)
            {
                x->keys[i]=y->keys[y->num-1];
                b_tree_delete(y,y->keys[y->num-1]);
            }
            else if(z->num>=t)
            {
                x->keys[i]=z->keys[0];
                b_tree_delete(z,z->keys[0]);
            }
            else
            {
                y->keys[y->num]=x->keys[i];
                y->num++;
                for(j=0; j<=t-2; j++)
                {
                    y->keys[y->num+j]=z->keys[j];
                }
                y->num=y->num+t-1;
                for(j=i+1; j<=x->num-1; j++)
                {
                    x->keys[j-1]=x->keys[j];
                    x->children[j]=x->children[j+1];
                }
                x->num--;
                b_tree_delete(y,k);
            }
        }
    }
    else if(!x->leaf)
    {
        struct node *c;
        struct node *l;
        struct node *r;

        c=x->children[i];
        if(i>=1) l=x->children[i-1];
        else l=NULL;
        if(i<=x->num-1) r=x->children[i+1];
        else r=NULL;

        if(c->num==t-1)
        {
            if(l!=NULL&&l->num>=t)
            {
                for(j=t-1; j>=1; j--)
                {
                    c->keys[j]=c->keys[j-1];
                }
                c->keys[0]=x->keys[i-1];
                if(!c->leaf)
                {
                    for(j=t; j>=1; j--)
                    {
                        c->children[j]=c->children[j-1];
                    }
                }
                c->children[0]=l->children[l->num];
                c->num++;
                x->keys[i-1]=l->keys[l->num-1];
                l->num--;
                b_tree_delete(c,k);
            }
            else if(r!=NULL&&r->num>=t)
            {
                c->keys[t-1]=x->keys[i];
                if(!c->leaf)
                {
                    c->children[t]=r->children[0];
                }
                c->num++;
                x->keys[i]=r->keys[0];
                for(j=0; j<=r->num-2; j++)
                {
                    r->keys[j]=r->keys[j+1];
                }

                if(!r->leaf)
                {
                    for(j=0; j<=r->num-1; j++)
                    {
                        r->children[j]=r->children[j+1];
                    }
                }
                r->num--;
                b_tree_delete(c,k);
            }
            else
            {
                if(l!=NULL)
                {
                    for(j=2*t-2; j>=t; j--)
                    {
                        c->keys[j]=c->keys[j-t];
                    }

                    c->keys[t-1]=x->keys[i-1];
                    for(j=0; j<=t-2; j++)
                    {
                        c->keys[j]=l->keys[j];
                    }
                    if(!c->leaf)
                    {
                        for(j=2*t-1; j>=t; j--)
                        {
                            c->children[j]=c->children[j-t];
                        }
                        for(j=0; j<=t-1; j++)
                        {
                            c->children[j]=c->children[j];
                        }
                    }
                    c->num=2*t-1;
                    for(j=i-1; j<=x->num-2; j++)
                    {
                        x->keys[j]=x->keys[j+1];
                        x->children[j]=x->children[j+1];
                    }
                    x->children[x->num-1]=x->children[x->num];
                    x->num--;
                    b_tree_delete(c,k);
                }
                else
                {
                    c->keys[t-1]=x->keys[i];
                    for(j=t; j<=2*t-2; j++)
                    {
                        c->keys[j]=r->keys[j-t];
                    }
                    if(!c->leaf)
                    {
                        for(j=t; j<=2*t-1; j++)
                        {
                            c->children[j]=r->children[j-t];
                        }
                    }
                    c->num=2*t-1;
                    for(j=i; j<=x->num-2; j++)
                    {
                        x->keys[j]=x->keys[j+1];
                        x->children[j+1]=x->children[j+2];
                    }
                    x->children[x->num-1]=x->children[x->num];
                    b_tree_delete(c,k);
                }
            }
        }
        else
        {
            b_tree_delete(c,k);
        }
    }
    else
    {
        return 0;
    }
}
struct node *b_tree_search(struct node *x,int k)
{
    int i;
    i=0;
    while(i<=x->num-1&&k>x->keys[i])
    {
        i++;
    }
    if(i<=x->num-1&&k==x->keys[i])
    {
        index=i;
        return x;
    }
    if(x->leaf) return NULL;
    else
    {
        return b_tree_search(x->children[i],k);
    }
}
void b_tree_walk(struct node *x)
{
    int i;
    if(x->leaf)
    {
        for(i=0; i<=x->num-1; i++)
            printf("%d ",x->keys[i]);
    }
    else
    {
        for(i=0; i<=x->num-1; i++)
        {
            b_tree_walk(x->children[i]);
            printf("%d ",x->keys[i]);
        }
        b_tree_walk(x->children[i]);
    }
}
void b_tree_insert_nonfull(struct node *x,int k)
{
    int i;
    i=x->num-1;
    if(x->leaf)
    {
        while(i>=0&&k<x->keys[i])
        {
            x->keys[i+1]=x->keys[i];
            i--;
        }
        x->keys[i+1]=k;
        x->num++;
    }
    else
    {
        while(i>=0&&k<x->keys[i])
        {
            i--;
        }
        i++;
        if(x->children[i]->num==2*t-1)
        {
            b_tree_spilt_child(x,i,x->children[i]);
            if(k>x->keys[i]) i++;
        }
        b_tree_insert_nonfull(x->children[i],k);
    }
}
void b_tree_insert(int k)
{
    struct node *s;
    struct node *r;
    r=root;
    if(r->num==2*t-1)
    {
        s=(struct node *)malloc(sizeof(struct node));
        root=s;
        s->leaf=0;
        s->num=0;
        s->children[0]=r;
        b_tree_spilt_child(s,0,r);
        b_tree_insert_nonfull(s,k);
    }
    else b_tree_insert_nonfull(r,k);
}
void b_tree_spilt_child(struct node *x,int i,struct node *y)
{
    int j;
    struct node *z;
    z=(struct node *)malloc(sizeof(struct node));
    z->leaf=y->leaf;
    z->num=t-1;
    for(j=0; j<=t-2; j++)
    {
        z->keys[j]=y->keys[j+t];
    }
    if(!y->leaf)
    {
        for(j=0; j<=t-1; j++)
        {
            z->children[j]=y->children[j+t];
        }
    }
    y->num=t-1;
    for(j=x->num; j>=i+1; j--)
    {
        x->children[j+1]=x->children[j];
    }
    x->children[i+1]=z;
    for(j=x->num-1; j>=i; j--)
    {
        x->keys[j+1]=x->keys[j];
    }
    x->keys[i]=y->keys[t-1];
    x->num++;
}
void b_tree_create(void)
{
    root=(struct node *)malloc(sizeof(struct node));
    root->num=0;
    root->leaf=1;
}
