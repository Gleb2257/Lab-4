#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
    if (r == NULL)
    {
        r = (struct Node*)malloc(sizeof(struct Node));
        if (r == NULL)
        {
            printf("Ошибка выделения памяти\n");
            exit(0);
        }

        r->left = NULL;
        r->right = NULL;
        r->data = data;
        if (root == NULL) return r;

        if (data > root->data) root->left = r;
        else root->right = r;
        return r;
    }

    if (data > r->data)
        CreateTree(r, r->left, data);
    else
        CreateTree(r, r->right, data);

    return root;
}

void print_tree(struct Node* r, int l)
{
    if (r == NULL)
    {
        return;
    }

    print_tree(r->right, l + 1);
    for (int i = 0; i < l; i++)
    {
        printf(" ");
    }

    printf("%d\n", r->data);
    print_tree(r->left, l + 1);
}

// Функция поиска элемента в дереве
struct Node* SearchTree(struct Node* r, int data)
{
    if (r == NULL || r->data == data)
        return r;

    if (data > r->data)
        return SearchTree(r->left, data); 
    else
        return SearchTree(r->right, data); 
}



int main()
{
    setlocale(LC_ALL, ""); 
    struct Node* root = NULL;
    int D, start = 1;

    printf("-1 - окончание построения дерева\n");
    while (start)
    {
        printf("Введите число: ");
        scanf_s("%d", &D);
        if (D == -1)
        {
            printf("Построение дерева окончено\n\n");
            start = 0;
        }
        else
        {
            root = CreateTree(root, root, D);
        }
    }

    printf("Ваше дерево:\n");
    print_tree(root, 0);

    // Поиск элемента
    printf("Введите число для поиска в дереве: ");
    scanf_s("%d", &D);
    struct Node* searchResult = SearchTree(root, D);
    if (searchResult != NULL)
        printf("Элемент %d найден в дереве.\n", D);
    else
        printf("Элемент %d не найден в дереве.\n", D);

   
    scanf_s("%d", &D);
   
   

    scanf_s("%d", &D); 
    return 0;
}
