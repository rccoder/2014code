void insert_keys_to_AVL(AVLTree &tree, int keys[], int n)  
{  
    int taller = FALSE; // 此初值无影响  
    for(int i=0; i < n; i++)  
    {  
        insert_key_to_AVL(tree, keys[i], taller);  
    }  
}  
  
int insert_key_to_AVL(AVLTree &tree, int key, int &taller)  
{  
    if(!tree)  
    { // 插入新结点,如插入根结点，或叶子结点时（p->left = tree == null)，且长高~  
        tree = (AVLTree)malloc(TNODE_SIZE);  
        tree->key = key;  
        tree->left = tree->right = NULL;  
        tree->bf = EH;  
        taller = TRUE;  
    }  
    else  
    { // 当插入新结点之后，对于tree进行平衡处理  
        if(EQ(key, tree->key))  
        { // 存在相同关键字，不需要进行插入  
            taller = FALSE;  
            return 0;  
        }  
        else if(LT(key, tree->key))    
        { // 插入到左子树当中  
            // 如果由于已经存在相同关键字而没有成功插入到树当中~  
            if(!insert_key_to_AVL(tree->left, key, taller))  
                return 0;  
            if(taller) // 如果左子树变高了  
            {   
                switch(tree->bf)  
                {  
                    // 如果左子树已经高1~，则需将左子树平衡~  
                    case LH:  
                        left_ballance(tree);taller = FALSE; break;  
                    case EH:  
                        tree->bf = LH; taller = TRUE; break;  
                    case RH:  
                        tree->bf = EH; taller = FALSE; break;  
                } // switch(tree->bf)  
            }  
        }  
        else  
        {// 右子树增高  
            // 如果由于已经存在相同关键字而没有成功插入到树当中~  
            if(!insert_key_to_AVL(tree->right, key, taller))  
                return 0;  
            if(taller) // 如果右子树变高了  
            {  
                switch(tree->bf)  
                {  
                    case LH:  
                        tree->bf = EH; taller = FALSE; break;  
                    case EH: // 如果原左右子树相等，则左子树增加1，使得树“长高”  
                        tree->bf = RH; taller = TRUE; break;  
                    case RH: // 如果右子树已经高1~，现在又高1，则需将右子树平衡~  
                        right_ballance(tree);taller = FALSE; break;  
                } // switch(tree->bf)  
            }             
        }  
    }  
      
    return 1;  
}  
  
void left_ballance(AVLTree &tree)  
{  
    PTNode lc, lrc;  
    lc = tree->left;  
    switch(lc->bf)  
    {  
        case EH:  
            tree->bf = LH; lc->bf = RH; R_Rote(tree);break;  
        case LH:  
            tree->bf = lc->bf = EH; R_Rote(tree); break;  
        case RH:  
            lrc = tree->left->right;  
            switch(lrc->bf)  
            {  
                case LH:  
                    lc->bf = EH; tree->bf = RH;break;  
                case EH:  
                    lc->bf =tree->bf = EH; break;  
                case RH:  
                    tree->bf = EH; lc->bf = LH; break;  
            } // switch(lrc->bf)  
            lrc->bf = EH;  
            L_Rote(tree->left); // 不可以写成 L_Rote(lrc);为什么？因为若为此，则改变的是lrc指针变量的值，而非tree->left.   
            R_Rote(tree);  
            break;  
              
    } // switch(left->bf)  
}  
  
void right_ballance(AVLTree &tree)  
{  
    PTNode rc, rlc; // rc为tree的右结点，rlc为rc的左结点  
    rc = tree->right;  
    switch(rc->bf)  
    {  
        case EH:  
            tree->bf = RH; rc->bf = LH; L_Rote(tree);break;  
        case RH:  
            tree->bf = rc->bf = EH; L_Rote(tree); break;  
        case LH:  
            rlc = rc->left;  
            switch(rlc->bf)  
            {  
                case LH:  
                    tree->bf = EH; rc->bf = RH;break;  
                case EH:  
                    tree->bf = rc->bf = EH; break;  
                case RH:  
                    tree->bf = LH; rc = EH; break;  
            }  
            rlc->bf = EH;  
            R_Rote(tree->right);  
            L_Rote(tree);  
            break;  
    }  
}  
  
void R_Rote(AVLTree &tree)  
{     
    PTNode lc;  
    lc = tree->left;   
    tree->left = lc->right;  
    lc->right = tree;  
    tree = lc;  
}  
  
void L_Rote(AVLTree &tree)  
{  
    PTNode rc;    
    rc = tree->right;  
    tree->right = rc->left;  
    rc->left = tree;  
    tree = rc;  
}  
  
int delete_key_from_AVL(AVLTree &tree, int key,int &lower)  
{  
    PTNode p, q = NULL; // 删除结点~  
    int targ = 0; // 标志位，即删除左结点或右结点~  
    int return_flag = 0;  
    if(!tree)  
    {// 可能出现删除叶子为空的情况不？  
        return 0;  
    }  
    if(EQ(key, tree->key))  
    {// 如果为要删除结点，~  
        lower = TRUE; // 即找到所要删除结点，致标识为TRUE~  
        if(NULL==tree->right)  
        { // 如果没有右节点  
            p = tree;  
            tree = tree->left;  
            free(p);  
            return 1; // 原tree左子树平衡，无需调整~   
        }  
        else  
        {  
            p = tree->right;  
            while(p->left != NULL)  
            { // 找到tree的右子树的最左结点~  
                p = p->left;  
            }  
            tree->key = p->key;  
            return_flag = delete_key_from_AVL(tree->right, p->key, lower);  
            targ = RH;  
        }     
    }  
    else if(LT(key, tree->key))  
    {  
        return_flag = delete_key_from_AVL(tree->left, key, lower);  
        targ = LH;  
    }  
    else   
    {  
        return_flag = delete_key_from_AVL(tree->right, key, lower);  
        targ = RH;  
    }  
      
    // 保证存在过为key的结点~  
    if(TRUE == lower)  
    {  
        if(targ==LH)  
        {// 删除的是左子树  
            switch(tree->bf)  
                {                     
                    case LH: // 由于原来左右高度分别为h、h-1,现在左子树删除，则  
                        tree->bf = EH; lower = TRUE; break;  
                    case EH:  
                        tree->bf = RH; lower = FALSE;break;  
                    case RH: // 如果原右子树已比左子树高1~，现在又删左子树，将导致不平衡~  
                        right_ballance(tree); lower=TRUE; break;  
                } // switch(tree->bf)  
        }  
        else  
        {// 删除的是右子树  
            switch(tree->bf)  
                {                     
                    case LH:  
                        left_ballance(tree); lower = TRUE; break;  
                    case EH:  
                        tree->bf = LH; lower = FALSE; break;  
                    case RH:  
                        tree->bf = EH; lower = TRUE; break;  
                } // switch(tree->bf)  
        }         
    }// if(TRUE == lower)  
      
    return return_flag;  
} 
void vist_tree_in_first(const AVLTree tree)  
{  
    if(NULL==tree)  
        return;  
        printf("%-4d", tree->key);  
    vist_tree_in_first(tree->left);  
    vist_tree_in_first(tree->right);  
}  
void destroy_tree(AVLTree tree)  
{  
    if(!tree)  
        return;  
    destroy_tree(tree->left);  
    destroy_tree(tree->right);  
    free(tree);  
    tree = NULL;  
}  

