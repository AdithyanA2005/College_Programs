#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

  if (newNode == NULL) {
    printf("ERROR: Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

void display() {
  if (head == NULL) {
    printf("Linked List is empty\n");
    return;
  }

  struct Node *ptr = head;
  printf("List: ");
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

void insertAtFront(int data) {
  struct Node *newNode = createNode(data);
  newNode->next = head;
  head = newNode;
  display();
}

void insertAtEnd(int data) {
  struct Node *newNode = createNode(data);

  if (head == NULL) {
    head = newNode;
  } else {
    struct Node *ptr = head;
    while (ptr->next != NULL)
      ptr = ptr->next;
    ptr->next = newNode;
  }

  display();
}

void insertNextTo(int data, int nextTo) {
  struct Node *ptr = head;

  while (ptr != NULL && ptr->data == nextTo)
    ptr = ptr->next;

  if (ptr == NULL) {
    printf("ERROR: Element not found\n");
    return;
  }

  struct Node *newNode = createNode(data);
  newNode->next = ptr->next;
  ptr->next = newNode;

  display();
}

void deleteAtFront() {
  if (head != NULL) {
    struct Node *temp = head;
    head = head->next;
    free(temp);
  }
  display();
}

void deleteAtEnd() {
  if (head != NULL) {
    if (head->next == NULL) {
      free(head);
      head = NULL;
    } else {
      struct Node *ptr = head;
      while (ptr->next->next != NULL)
        ptr = ptr->next;
      free(ptr->next);
      ptr->next = NULL;
    }
  }
  display();
}

void deleteSpecificNode(int data) {
  if (head != NULL) {
    if (head->data == data) {
      struct Node *temp = head;
      head = head->next;
      free(temp);
    } else {
      struct Node *prev = NULL;
      struct Node *curr = head;

      while (curr != NULL && curr->data != data) {
        prev = curr;
        curr = curr->next;
      }

      if (curr != NULL) {
        prev->next = curr->next;
        free(curr);
      }
    }
  }
  display();
}

int main() {
  printf("LINKED LIST\n------ ----\n");
  printf("1 - Insert at front\n");
  printf("2 - Insert at end\n");
  printf("3 - Insert next to\n");
  printf("4 - Delete at front\n");
  printf("5 - Delete at end\n");
  printf("6 - Delete specific node\n");
  printf("7 - Display\n");

  int doRun = 1, choice, temp;

  while (doRun) {
    printf("\nEnter a choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter value: ");
      scanf("%d", &temp);
      insertAtFront(temp);
      break;
    case 2:
      printf("Enter value: ");
      scanf("%d", &temp);
      insertAtEnd(temp);
      break;
    case 3:
      printf("Enter value to insert nextTo: ");
      scanf("%d", &choice);
      printf("Enter value: ");
      scanf("%d", &temp);
      insertNextTo(temp, choice);
      break;
    case 4:
      deleteAtFront();
      break;
    case 5:
      deleteAtEnd();
      break;
    case 6:
      printf("Enter value to delete: ");
      scanf("%d", &temp);
      deleteSpecificNode(temp);
      break;
    case 7:
      display();
      break;
    default:
      printf("Program ended\n");
      doRun = 0;
    }
  }
}
