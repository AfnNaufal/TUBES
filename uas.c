#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struct untuk menyimpan data kode pos
typedef struct {
    int kode_pos;
    char kota[50];
    char provinsi[50];
    char negara[50];
} KodePos;

// Definisi struct untuk node tree
typedef struct Node {
    KodePos data;
    struct Node* left;
    struct Node* right;
} Node;

// Fungsi untuk membuat node baru dengan parameter kode pos, kota, provinsi, dan negara
Node* createNode(int kode_pos, const char* kota, const char* provinsi, const char* negara) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data.kode_pos = kode_pos;
    strcpy(newNode->data.kota, kota);
    strcpy(newNode->data.provinsi, provinsi);
    strcpy(newNode->data.negara, negara);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Fungsi untuk memasukkan data ke dalam tree (sebelah kiri)
void insertLeft(Node* root, int kode_pos, const char* kota, const char* provinsi, const char* negara) {
    root->left = createNode(kode_pos, kota, provinsi, negara);
}

// Fungsi untuk memasukkan data ke dalam tree (sebelah kanan)
void insertRight(Node* root, int kode_pos, const char* kota, const char* provinsi, const char* negara) {
    root->right = createNode(kode_pos, kota, provinsi, negara);
}

// Fungsi untuk mencari data dalam tree
Node* search(Node* root, int kode_pos) {
    if (root == NULL || root->data.kode_pos == kode_pos) {
        return root;
    }
    if (kode_pos < root->data.kode_pos) {
        return search(root->left, kode_pos);
    }
    return search(root->right, kode_pos);
}

// Fungsi untuk traversal in-order
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("Kode Pos: %d, Kota: %s, Provinsi: %s, Negara: %s\n", root->data.kode_pos, root->data.kota, root->data.provinsi, root->data.negara);
        inOrder(root->right);
    }
}

// Fungsi untuk traversal pre-order
void preOrder(Node* root) {
    if (root != NULL) {
        printf("Kode Pos: %d, Kota: %s, Provinsi: %s, Negara: %s\n", root->data.kode_pos, root->data.kota, root->data.provinsi, root->data.negara);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Fungsi untuk traversal post-order
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("Kode Pos: %d, Kota: %s, Provinsi: %s, Negara: %s\n", root->data.kode_pos, root->data.kota, root->data.provinsi, root->data.negara);
    }
}

int main() {
    Node* root = NULL;

    // Mendeklarasikan Indonesia sebagai root
    root = createNode(10110, "Jakarta", "DKI Jakarta", "Indonesia");

    // Memasukkan data ke dalam tree
    insertLeft(root, 50125, "Semarang", "Jawa Tengah", "Indonesia");
    insertRight(root, 60293, "Surabaya", "Jawa Timur", "Indonesia");
    //insertLeft(root->right, 50125, "Semarang", "Jawa Tengah", "Indonesia");

    printf("In-order Traversal:\n");
    inOrder(root);

    printf("\nPre-order Traversal:\n");
    preOrder(root);

    printf("\nPost-order Traversal:\n");
    postOrder(root);

    int searchKodePos = 60293;
    Node* found = search(root, searchKodePos);
    if (found != NULL) {
        printf("\nData ditemukan:\nKode Pos: %d, Kota: %s, Provinsi: %s, Negara: %s\n", found->data.kode_pos, found->data.kota, found->data.provinsi, found->data.negara);
    } else {
        printf("\nData dengan Kode Pos %d tidak ditemukan.\n", searchKodePos);
    }

    return 0;
}
