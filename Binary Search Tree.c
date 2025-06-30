#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_tree() {
    return NULL;
}

struct node* insertElement(struct node* tree, int val) {
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if (tree == NULL) {
        tree = ptr;
        return tree;
    } else {
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL) {
            parentptr = nodeptr;
            if (val < nodeptr->data)
                nodeptr = nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }
        if (val < parentptr->data)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
    }
    return tree;
}

void preorderTraversal(struct node* tree) {
    if (tree != NULL) {
        printf("%d ", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}

void inorderTraversal(struct node* tree) {
    if (tree != NULL) {
        inorderTraversal(tree->left);
        printf("%d ", tree->data);
        inorderTraversal(tree->right);
    }
}

void postorderTraversal(struct node* tree) {
    if (tree != NULL) {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d ", tree->data);
    }
}

struct node* findSmallestElement(struct node* tree) {
    if (tree == NULL || tree->left == NULL)
        return tree;
    return findSmallestElement(tree->left);
}

struct node* findLargestElement(struct node* tree) {
    if (tree == NULL || tree->right == NULL)
        return tree;
    return findLargestElement(tree->right);
}

struct node* deleteElement(struct node* tree, int val) {
    if (tree == NULL) return tree;
    if (val < tree->data)
        tree->left = deleteElement(tree->left, val);
    else if (val > tree->data)
        tree->right = deleteElement(tree->right, val);
    else {
        if (tree->left == NULL) {
            struct node* temp = tree->right;
            free(tree);
            return temp;
        } else if (tree->right == NULL) {
            struct node* temp = tree->left;
            free(tree);
            return temp;
        }
        struct node* temp = findSmallestElement(tree->right);
        tree->data = temp->data;
        tree->right = deleteElement(tree->right, temp->data);
    }
    return tree;
}

int totalNodes(struct node* tree) {
    if (tree == NULL) return 0;
    return 1 + totalNodes(tree->left) + totalNodes(tree->right);
}

int totalExternalNodes(struct node* tree) {
    if (tree == NULL) return 0;
    if (tree->left == NULL && tree->right == NULL) return 1;
    return totalExternalNodes(tree->left) + totalExternalNodes(tree->right);
}

int totalInternalNodes(struct node* tree) {
    if (tree == NULL || (tree->left == NULL && tree->right == NULL)) return 0;
    return 1 + totalInternalNodes(tree->left) + totalInternalNodes(tree->right);
}

int Height(struct node* tree) {
    if (tree == NULL) return -1;
    int leftHeight = Height(tree->left);
    int rightHeight = Height(tree->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

struct node* mirrorImage(struct node* tree) {
    if (tree == NULL) return tree;
    struct node* temp = tree->left;
    tree->left = mirrorImage(tree->right);
    tree->right = mirrorImage(temp);
    return tree;
}

struct node* deleteTree(struct node* tree) {
    if (tree == NULL) return tree;
    deleteTree(tree->left);
    deleteTree(tree->right);
    free(tree);
    return NULL;
}

int main() {
    struct node* tree = create_tree();
    int option, val;
    struct node* ptr;
    while (1) {
        printf("\n1. Insert an element");
        printf("\n2. Preorder Traversal");
        printf("\n3. Inorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Find the smallest element");
        printf("\n6. Find the largest element");
        printf("\n7. Delete an element");
        printf("\n8. Count the total number of nodes");
        printf("\n9. Count the total number of external nodes");
        printf("\n10. Count the total number of internal nodes");
        printf("\n11. Determine the height of the tree");
        printf("\n12. Find the mirror image of the tree");
        printf("\n13. Delete the tree");
        printf("\n14. Exit");
        printf("\n\nEnter your option : ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("\nEnter the value of the new node : ");
                scanf("%d", &val);
                tree = insertElement(tree, val);
                break;
            case 2:
                printf("\nThe elements of the tree are : \n");
                preorderTraversal(tree);
                break;
            case 3:
                printf("\nThe elements of the tree are : \n");
                inorderTraversal(tree);
                break;
            case 4:
                printf("\nThe elements of the tree are : \n");
                postorderTraversal(tree);
                break;
            case 5:
                ptr = findSmallestElement(tree);
                if (ptr != NULL)
                    printf("\nSmallest element is : %d", ptr->data);
                break;
            case 6:
                ptr = findLargestElement(tree);
                if (ptr != NULL)
                    printf("\nLargest element is : %d", ptr->data);
                break;
            case 7:
                printf("\nEnter the element to be deleted : ");
                scanf("%d", &val);
                tree = deleteElement(tree, val);
                break;
            case 8:
                printf("\nTotal no. of nodes = %d", totalNodes(tree));
                break;
            case 9:
                printf("\nTotal no. of external nodes = %d", totalExternalNodes(tree));
                break;
            case 10:
                printf("\nTotal no. of internal nodes = %d", totalInternalNodes(tree));
                break;
            case 11:
                printf("\nThe height of the tree = %d", Height(tree));
                break;
            case 12:
                tree = mirrorImage(tree);
                break;
            case 13:
                tree = deleteTree(tree);
                break;
            case 14:
                return 0;
        }
    }
}