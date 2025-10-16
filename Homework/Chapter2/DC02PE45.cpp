#include "allinclude.h"  //DO NOT edit this line

void Union(SqList &La, SqList Lb)
{
    // 获取Lb的长度
    int Lb_len = ListLength_Sq(Lb);
    ElemType e; // 用于临时存储Lb中的元素

    // 遍历Lb中的每一个元素
    for (int i = 1; i <= Lb_len; i++) {
        // 获取Lb中的第i个元素
        GetElem_Sq(Lb, i, e);
        
        // 在La中查找该元素
        // 如果La中不存在该元素，则将其添加到La的末尾
        if (Search_Sq(La, e) == -1) {
            Append_Sq(La, e);
        }
    }
}