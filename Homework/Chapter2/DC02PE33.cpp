#include "allinclude.h"  //DO NOT edit this line

char Compare(SqList A, SqList B) 
{ 
    // 初始化索引
    int i = 0;
    int j = 0;

    // 同时遍历两个列表，比较对应位置的元素
    while (i < A.length && j < B.length) {
        // 如果找到第一个不相等的元素
        if (A.elem[i] != B.elem[j]) {
            // A中元素较小，则A<B
            if (A.elem[i] < B.elem[j]) {
                return '<';
            } 
            // B中元素较小，则A>B
            else {
                return '>';
            }
        }
        // 如果元素相等，继续比较下一个
        i++;
        j++;
    }

    // 循环结束后，说明一个列表是另一个的前缀，或者两个列表完全相等
    // 通过比较它们的长度来确定关系
    
    // A是B的前缀，A<B
    if (A.length < B.length) {
        return '<';
    } 
    // B是A的前缀，A>B
    else if (A.length > B.length) {
        return '>';
    } 
    // 长度相等且所有元素都相等，A=B
    else {
        return '=';
    }
}