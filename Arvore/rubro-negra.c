#include <stdio.h>
#include <stdlib.h>
#define BLACK 0
#define RED 1

typedef struct N{
    int chave;
    int color; // 0=Black & 1=RED
    struct N * left;
    struct N * right;
    struct N * parent;
} Node;


void add(Node ** arvore,Node *novo);
Node * createNode();
void imprimir(Node **arvore,int b);

Node *grandeparent(Node *arvore);
Node *uncle(Node *arvore);

void insert_case1(Node *arvore);
void insert_case2(Node *arvore);
void insert_case3(Node *arvore);
void insert_case4(Node *arvore);
void insert_case5(Node *arvore);
void rotate_left(Node *arvore);
void rotate_right(Node *arvore);

int main(){
    Node *arvore;
    int escolha;
    arvore = NULL;

    do{ 
        printf("1- Adicionar\n2-Imprimir\n3-Remover\n4-Sair\n---> ");
        scanf("%d",&escolha);
        switch(escolha){
            case 1:
                add(&arvore,createNode());
                // if(arvore->left == NULL && arvore->right == NULL){
                //     arvore->color = BLACK;
                // }
                // if(arvore->left != NULL){
                //     insert_case1(arvore->left);
                // }
                // if(arvore->right != NULL){
                //     insert_case1(arvore->right);
                // }
            break;
            case 2:
                imprimir(&arvore,1);
            break;
            case 3:
            break;
        }
    }while(escolha != 0);

}

void rotate_left(Node *arvore){
    Node *aux;

    aux = arvore->right;
    arvore->right = arvore->left;
    arvore->left = arvore;
    arvore = aux;
}

void rotate_right(Node *arvore){
    Node *aux;

    aux = arvore->left;
    arvore->left = arvore->right;
    arvore->right = arvore;
    arvore = aux;
}

void insert_case1(Node *arvore){
    if(arvore->parent == NULL){
        arvore->color = BLACK;
    }else{
        insert_case2(arvore);
    }
}
void insert_case2(Node *arvore){
    if(arvore->parent->color == BLACK) return;
    insert_case3(arvore);
}
void insert_case3(Node *arvore){
    Node *u = uncle(arvore),*g;
    if(u != NULL && u->color == RED){
        arvore->parent->color = BLACK;
        u->color = BLACK;
        g = grandeparent(arvore);
        g->color = RED;
        insert_case1(g);
    }else{
        insert_case4(arvore);
    }
}
void insert_case4(Node *arvore){
    Node *g = grandeparent(arvore);

    if(arvore == arvore->parent->right && arvore->parent == g->left){
        rotate_left(arvore->left);
        arvore = arvore->left;
    }else
    if(arvore == arvore->parent->left && arvore->parent == g->right){
        rotate_right(arvore->parent);
        arvore = arvore->right;
    }
    insert_case5(arvore);
}

void insert_case5(Node *arvore){
    Node *g = grandeparent(arvore);

    arvore->parent->color = BLACK;
    g->color = RED;

    if(arvore == arvore->parent->left && arvore->parent == g->left){
        rotate_right(g);
    }else{
        rotate_left(g);
    }
}


Node *grandeparent(Node *arvore){
    if(arvore != NULL && arvore->parent != NULL) return arvore->parent->parent;
    return NULL;
}
Node *uncle(Node *arvore){
    Node *g = grandeparent(arvore);
    if(g == NULL) return NULL;

    if(arvore->parent == g->left) return g->right;
    return g->left;
}

void imprimir(Node **arvore,int b){
    int i;
    if(*arvore == NULL){
        for(i=0;i<b;i++){
            printf("    ");
        }
        printf("*\n");
        return;
    }
    
    imprimir(&(*arvore)->left,b+1);
    for(i=0;i<b;i++){
        printf("    ");
    }
    printf("%d (%s)\n",(*arvore)->chave, (*arvore)->color == BLACK ? "BLACK" : "RED");
    imprimir(&(*arvore)->right,b+1);
}

Node* createNode(){
    Node *novo = malloc(sizeof(Node));
    scanf("%d",&novo->chave);
    novo->color = 3;
    novo->left = NULL;
    novo->left = NULL;
    novo->parent = NULL;
    return novo;
}

void add(Node ** arvore, Node *novo){
    if(*arvore == NULL){
        *arvore = novo;
        return;
    }

    if((*arvore)->chave < novo->chave){
        if((*arvore)->left != NULL){
            add(&(*arvore)->left,novo);
        }else{
            novo->parent = *arvore;
            (*arvore)->left = novo;
            return;
        }
    }

    if((*arvore)->chave > novo->chave){
        if((*arvore)->right != NULL){
            add(&(*arvore)->right,novo);
        }else{
            novo->parent = *arvore;
            (*arvore)->right = novo;
            return;
        }
    }
    if(*arvore != NULL && (*arvore)->parent !=  NULL && (*arvore)->parent->parent !=  NULL ) insert_case1(*arvore);
}  