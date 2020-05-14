/*双方向連結リスト*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct node
{
    unsigned int key;
    struct node *next;
    struct node *prev;
} Node;

typedef Node *NodePointer;

NodePointer nil; //番兵　基準となる(リストの先頭、末尾)　実データには含めない

NodePointer listSearch(int key)
{
    NodePointer cur = nil->next;
    while (cur->key != key && cur != nil)
    {
        cur = cur->next;
    }
    return cur;
}

void init()
{
    nil = new Node;
    nil->next = nil;
    nil->prev = nil;
}

void printList()
{
    NodePointer cur = nil->next;
    int isfirst = 1;
    while (cur != nil)
    {
        if (isfirst == 0)
        { //最初は空白を入れない
            printf(" ");
        }
        printf("%d", cur->key);
        cur = cur->next;
        isfirst = 0;
    }
    printf("\n");
}

void deleteNode(NodePointer t)
{
    if (t == nil)
    {
        return;
    }
    t->prev->next = t->next;
    t->next->prev = t->prev;
    delete t;
}

void deleteFirst()
{
    deleteNode(nil->next);
}

void deleteLast()
{
    deleteNode(nil->prev);
}

void deleteKey(int key)
{
    deleteNode(listSearch(key));
}

void insert(int key)
{
    NodePointer x;
    x = new Node;
    x->key = key;

    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

int main()
{
    int key, n, i;
    int size = 0;       //要素の大きさ
    char com[20];       //コマンド命令文字列
    int np = 0, nd = 0; //Insert回数とDelete回数

    scanf("%d", &n);
    init();
    for (i = 0; i < n; i++)
    {
        scanf("%s%d", com, &key);
        if (com[0] == 'i')
        { //Insert
            insert(key);
            np++;
            size++;
        }
        else if (com[0] == 'd')
        {
            if (strlen(com) > 6)
            {
                if (com[6] == 'F')
                {
                    deleteFirst();
                }
                else if (com[6] == 'L')
                {
                    deleteLast();
                }
            }
            else
            {
                deleteKey(key);
                nd++;
            }
            size--;
        }
    }

    printList();
    delete nil;

    return 0;
}
