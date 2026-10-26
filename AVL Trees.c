#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node *stack[MAX];
int top = -1;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct Node *node)
{
    if (node == NULL)
        return 0;

    return node->height;
}

struct Node *createNode(int data)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void updateHeight(struct Node *node)
{
    node->height = 1 + max(height(node->left), height(node->right));
}

int getBalance(struct Node *node)
{
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

void insert(int data)
{
    struct Node *newNode = createNode(data);
    struct Node *current = root;
    struct Node *parent = NULL;

    top = -1;

    if (root == NULL)
    {
        root = newNode;
        return;
    }

    while (current != NULL)
    {
        stack[++top] = current;
        parent = current;

        if (data < current->data)
            current = current->left;

        else if (data > current->data)
            current = current->right;

        else
        {
            printf("Duplicate value not allowed\n");
            free(newNode);
            return;
        }
    }

    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    while (top >= 0)
    {
        struct Node *node = stack[top--];

        updateHeight(node);

        int balance = getBalance(node);
        struct Node *newRoot = node;

        /* LL Case */
        if (balance > 1 && data < node->left->data)
        {
            newRoot = rightRotate(node);
        }

        /* RR Case */
        else if (balance < -1 && data > node->right->data)
        {
            newRoot = leftRotate(node);
        }

        /* LR Case */
        else if (balance > 1 && data > node->left->data)
        {
            node->left = leftRotate(node->left);
            newRoot = rightRotate(node);
        }

        /* RL Case */
        else if (balance < -1 && data < node->right->data)
        {
            node->right = rightRotate(node->right);
            newRoot = leftRotate(node);
        }

        if (top >= 0)
        {
            struct Node *parentNode = stack[top];

            if (parentNode->left == node)
                parentNode->left = newRoot;
            else
                parentNode->right = newRoot;
        }
        else
        {
            root = newRoot;
        }
    }
}

void display()
{
    struct Node *tempStack[MAX];
    int tempTop = -1;
    struct Node *current = root;

    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    printf("Inorder Traversal: ");

    while (current != NULL || tempTop != -1)
    {
        while (current != NULL)
        {
            tempStack[++tempTop] = current;
            current = current->left;
        }

        current = tempStack[tempTop--];

        printf("%d ", current->data);

        current = current->right;
    }

    printf("\n");
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);

                insert(data);
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Thank You!");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
