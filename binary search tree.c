#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in Binary search tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

// Function to perform mahi_inorder traversal
void inorderTraversal(Node* root, FILE* fp) {
    if (root != NULL) {
        inorderTraversal(root->left, fp);
        fprintf(fp, "%d ", root->data);
        inorderTraversal(root->right, fp);
    }
}

// Function to perform mahi_preorder traversal
void preorderTraversal(Node* root, FILE* fp) {
    if (root != NULL) {
        fprintf(fp, "%d ", root->data);
        preorderTraversal(root->left, fp);
        preorderTraversal(root->right, fp);
    }
}

// Function to perform mahi_postorder traversal
void postorderTraversal(Node* root, FILE* fp) {
    if (root != NULL) {
        postorderTraversal(root->left, fp);
        postorderTraversal(root->right, fp);
        fprintf(fp, "%d ", root->data);
    }
}

int main() {
    // Generating random numbers and storing them in a file
    FILE* inputFile = fopen("mahati.txt", "w");
    if (inputFile == NULL) {
        printf("cannot open the file.\n");
        return 1;
    }

    int i, num;
    srand(time(NULL));  // Seed the random number generator

    for (i = 0; i < 10; i++) {
        num = rand() % 100;
        fprintf(inputFile, "%d ", num);
    }

    fclose(inputFile);

    // Inserting numbers from the file into the binary search tree
    FILE* inputFileRead = fopen("mahati.txt", "r");
    if (inputFileRead == NULL) {
        printf("cannot open the file.\n");
        return 1;
    }

    Node* root = NULL;
    while (fscanf(inputFileRead, "%d", &num) != EOF) {
        root = insertNode(root, num);
    }

    fclose(inputFileRead);

    // Opening output files for writing
    FILE* inorderFile = fopen("mahi_inorder.txt", "w");
    FILE* preorderFile = fopen("mahi_preorder.txt", "w");
    FILE* postorderFile = fopen("mahi_postorder.txt", "w");

    // Traversing the binary search tree and writing the results to output files
    if (inorderFile == NULL || preorderFile == NULL || postorderFile == NULL) {
        printf("cannot open the file.\n");
        return 1;
    }

    inorderTraversal(root, inorderFile);
    preorderTraversal(root, preorderFile);
    postorderTraversal(root, postorderFile);

    fclose(inorderFile);
    fclose(preorderFile);
    fclose(postorderFile);

    printf("results are in the output file.\n");

    return 0;
}

