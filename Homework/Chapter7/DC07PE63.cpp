#include "allinclude.h"  //DO NOT edit this line
int find(MFSet S, int i) 
{
    int root, tmp;
    root = i;
    
    while (S.parent[root] != -1) 
      root = S.parent[root];
    
    while (S.parent[i] != -1) //遍历查找路径
    {    
        tmp = S.parent[i];  
        S.parent[i] = root;//置查找路径上的每个结点的双亲位标值为根结点
        i = tmp;
    }  
    
    return root;
}