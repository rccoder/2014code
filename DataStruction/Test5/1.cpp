struct node
{
    int data;
    node *left;
    node *right;
};
int flag = 1;
void dfs(node *po)
{
    if(po==NULL)
        return ;
    if(po->left!=NULL && po->left->data>=po->data)
    {
        flag=0;
        return ;
    }
    if(po->right!=NULL&&po->right->data<=po->data)
    {
        flag=0;
        return ;
    }
    dfs(po->left);
    dfs(po->right);
    return ;
}
