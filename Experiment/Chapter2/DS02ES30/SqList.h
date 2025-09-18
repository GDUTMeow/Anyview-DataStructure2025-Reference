#define OVERFLOW -1
#define OK 1
#define ERROR 0    
#define TRUE 2
#define FALSE -2

typedef int ElemType;
typedef struct {
    ElemType* elem;  // 存储空间的基址
    int length;       // 表长
    int size;         // 存储容量
    int increment;    // 存储增量
} SqList;



typedef int Status;

SqList createList_Sq(int a[], int n);
Status InitList_Sq(SqList& S, int size, int inc);
Status GetElem_Sq(SqList L, int i, ElemType& e);
Status Append_Sq(SqList& L, ElemType e);




