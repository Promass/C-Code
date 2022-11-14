#include <stdio.h>
#include <stdlib.h>

struct node {
    int key_value;
    struct node *left;
    struct node *right;
};

void insert(int key, struct node ** leaf) {
    if (*leaf == 0) {
        *leaf = (struct node*) malloc(sizeof(struct node));
        (*leaf)->key_value = key;
        (*leaf)->left = 0;
        (*leaf)->right = 0;
    }
    else if (key < (*leaf)->key_value) {
        insert(key, &(*leaf)->left);
    }
    else if (key >= (*leaf)->key_value) {
        insert(key, &(*leaf)->left);
    }
}

struct node *search(int key, struct node *leaf) {
    if  (leaf != 0) {
        if (key == leaf->key_value) {
            return leaf;
        }
    else if 
    }
}


int main() {

    struct node *tree;
    tree = 0;
    insert(2, &tree);
    insert(4, &tree);
    insert(5, &tree);
    insert(7, &tree);
    //struct node k = *search(5, tree);
    //printf("%d", k.key_value);

    return 0;

}