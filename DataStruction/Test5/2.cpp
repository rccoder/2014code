struct node
{
  int data;
  node *left;
  node *right;
}BSTreeNode;


int Depth(BSTreeNode* p)
{
    if (p==NULL)
        return 0;
    else
    {
        int ld = Depth(p->left);
        int rd = Depth(p->right);
        return 1 + (ld >rd ? ld : rd);
    }
}
/**利用递归判断左右子树的深度是否相差1来判断是否是平衡二叉树**/
bool isBalance(BSTreeNode* pbs)
{
    if (pbs==NULL) 
        return true;
    int dis = Depth(pbs->left) - Depth(pbs->right);
    if (dis>1 || dis<-1 )
        return false;
    else
}        return isBalance(pbs->left) && isBalance(pbs->right);
