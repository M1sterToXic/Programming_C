#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data; // Пусть в качестве данных у нас будут числа
    struct node *next; // Указатель на следующий узел, если нет узла = NULL
};

void append(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

void printList(struct node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int input;

    printf("Введите элементы списка (0 для завершения):\n");

    while (1) {
        scanf("%d", &input);
        if (input == 0) {
            break;
        }
        append(&head, input);
    }

    printf("Список: ");
    printList(head);

    return 0;
}
