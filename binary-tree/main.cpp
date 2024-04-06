#include <stdio.h>
#include <stdlib.h>

char* spaces(int n){
    char* str = (char*)malloc(n*sizeof(char));
    int i;
    for(i=0; i<n; i++){
        str[i] = ' ';
    }
    return str;
}

class Node {
    public:
        int val;
        Node *left;
        Node *right;
        Node(int x) {
            val = x;
            left = NULL;
            right = NULL;
        }    
        void invert(){
            Node *temp_left = left;
            left = right;
            right = temp_left;
        }
};

class Tree{
    public:
        Node *root = NULL;
        Tree(Node *node){
            root = node;
        }
        Tree(){
        }
        void fill_tree(){
            int n, i;
            printf("What is the amount of nodes? \n");
            scanf("%d", &n);
            for(i=0; i<n; i++){
                int val;
                printf("Value %d? \n", i+1);
                scanf("%d", &val);
                Node *node = new Node(val);
                insert_node(node);
            }
        }
        void insert_node(Node *node){
            if(!root){
                root = node;
                return;
            }
            Node *temp = root;
            while(temp){
                if(node->val < temp->val){
                    if(temp->left){
                        temp = temp->left;
                    }else{
                        temp->left = node;
                        break;
                    }
                }
                else{
                    if(temp->right){
                        temp = temp->right;
                    }else{
                        temp->right = node;
                        break;
                    }
                }
            }
        }
        void invert_tree(Node *node){
            if(node->left || node->right){
                return;
            }
            invert_tree(node->left);
            invert_tree(node->right);
            node->invert();
        }
        void print_tree(Node *node){
            static int spaceAmount = 1;
            if(!node){
                return;
            }
            if(node == root){
                printf("%s", spaces(spaceAmount + 1));
                printf("%d", node->val);
            }
            printf("\n");

            if(node->left){
                printf("%s", spaces(spaceAmount));
                printf("%d", node->left->val);
            }
            
            if(node -> right){
                printf("%s", spaces(spaceAmount + 2));
                printf("%d", node->right->val);
            }
            spaceAmount += 1;
            print_tree(node->left);
            print_tree(node->right);
        }
};

class Test{
    int pablo;
    public:
        Test(){
            printf("Test constructor\n");
        }
        ~Test(){
            printf("Test destructor\n");
        }
};
int main(){
    Tree* tree = new Tree();

    tree->fill_tree();
    tree->print_tree(tree->root);
    return 0;
}
