//============================================================================
// Ohjelmointiharjoitus 2 : Linkitetty lista
// Tekija      : Jonathan Soinio
//============================================================================
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Tulostaa listan sisallon
void printList(struct node *head) {
    struct node *n = head;

    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
    printf("\n");
    printf("\n");
}

// Luo uusia nodeja listalle
struct node *create_new_node(int value) {
    struct node *result = malloc(sizeof(struct node));
    result->data = value;
    result->next = NULL;
    result->prev = NULL;
    return result;
}

//Lisaa funktio; lisaa uusia luotuja nodeja listaan
struct node *insert_at_head(struct node **head, struct node *node_to_insert) {
    node_to_insert->next = *head;
    if (*head != NULL) {
        (*head)->prev = node_to_insert;
    }
    *head = node_to_insert;
    node_to_insert->prev = NULL;
    return node_to_insert;
}

//Poista funktio; poistaa nodeja listalta
void remove_node(struct node **head, struct node *node_to_remove) {
    if (*head == node_to_remove) {
        *head = node_to_remove->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
    }
    node_to_remove->next = NULL;
    node_to_remove->prev = NULL;
    return;
}

//============================================================================
// Paa funktio
    int main() {
        struct node *head = NULL;
        struct node *tmp;

        //for loop joka luo tietyn x maaran nodeja listaan
        for (int i=0; i < 10; i++) {
            tmp = create_new_node(i);
            insert_at_head(&head, tmp);

        }

        //Tulostaa listan terminaaliin
        printf("Lista: ");
        printList(head);

        //Tulostaa listan, johon on lisatty 10 numeroa, terminaaliin
        printf("Uusi lista, johon on lisatty 10 numeroa: ");
        for (int i=20; i < 30; i++) {
            tmp = create_new_node(i);
            insert_at_head(&head, tmp);
        }
        printList(head);

        //Tulostaa listan, josta on poistettu 5 numeroa, terminaaliin
        printf("Uusi lista josta on poistettu 5 numeroa: ");
        remove_node(&head, tmp);
        for (int i = 5; --i >= 1;) {
            remove_node(&head, head);
        }
        printList(head);

        return 0;
    }
//============================================================================

