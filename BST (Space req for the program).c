#include <stdio.h>
#include <stdlib.h>

// Data Segment
int global = 10;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

int main()
{
    struct Node *root = NULL;
    int n, value, i;      // Stack Segment

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        root = insert(root, value);
    }

    printf("\nMemory Segments\n");
    printf("Code Segment  : %p\n", main);
    printf("Data Segment  : %p\n", &global);
    printf("Stack Segment : %p\n", &n);
    printf("Extra(Heap) Segment : %p\n", root);

    printf("\nSpace Required\n");
    printf("Data Segment  = %lu bytes\n", sizeof(global));
    printf("Stack Segment = %lu bytes\n",
           sizeof(n) + sizeof(value) + sizeof(i) + sizeof(root));
    printf("Extra(Heap) Segment = %lu bytes\n",
           n * sizeof(struct Node));

    printf("Total Space Required = %lu bytes\n",
           sizeof(global) +
           sizeof(n) +
           sizeof(value) +
           sizeof(i) +
           sizeof(root) +
           (n * sizeof(struct Node)));

    return 0;
}
