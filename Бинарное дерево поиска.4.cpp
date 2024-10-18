#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node {
    int data;
    struct Node* left, * right;
};

struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
    if (r == NULL)
    {
        r = (struct Node*)malloc(sizeof(struct Node));
        if (r == NULL)
        {
            printf("Ошибка выделения памяти");
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

// Функция для поиска элемента в дереве
struct Node* Find(struct Node* r, int data)
{
    if (r == NULL)
    {
        printf("Элемент не найден\n");
        return NULL;
    }

    if (data == r->data)
    {
        printf("Элемент %d найден\n", data);
        return r;
    }

    if (data > r->data)
        return Find(r->left, data);
    else
        return Find(r->right, data);
}

void print_tree(struct Node* r, int l)
{
    if (r == NULL) return;

    print_tree(r->right, l + 1);
    for (int i = 0; i < l; i++)
    {
        printf(" ");
    }
    printf("%d\n", r->data);
    print_tree(r->left, l + 1);
}

int main()
{
    setlocale(LC_ALL, ""); 
    int D, start = 1;
    struct Node* root = NULL;
    struct Node* found = NULL;

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
            root = CreateTree(root, root, D);
    }

    print_tree(root, 0);

    // Поиск элемента
    printf("Введите элемент для поиска: ");
    scanf_s("%d", &D);
    found = Find(root, D);

    printf("Нажмите любую клавишу для выхода...");
    getchar();
    getchar();
    return 0;
}
