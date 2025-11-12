#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

int findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int height(struct Node* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

void swapTree(struct Node* root) {
    if (root == NULL) return;
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    swapTree(root->left);
    swapTree(root->right);
}

int search(struct Node* root, int key) {
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, data, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Inorder traversal: ");
    inorder(root);
    printf("\nHeight of tree: %d\n", height(root));
    printf("Minimum value: %d\n", findMin(root));

    swapTree(root);
    printf("After swapping left and right pointers (Inorder): ");
    inorder(root);

    printf("\nEnter value to search: ");
    scanf("%d", &key);
    if (search(root, key))
        printf("Value found in tree.\n");
    else
        printf("Value not found.\n");
}
