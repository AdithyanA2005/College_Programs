#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_null.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

  if (newNode == NULL) {
    printf("Error: Memory allocation failed\n");
    exit(1);
  }

  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

void insertAtFront(int data) {
  struct Node *newNode = createNode(data);
  newNode->next = head;
  head = newNode;
}

void insertAtEnd(int data) {
  struct Node *newNode = createNode(data);
  if (head == NULL) {
    head = newNode;
    return;
  }

  // Finding the lastNode
  struct Node *temp = head;
  while (temp->next != NULL)
    temp = temp->next;

  // Connect newNode to lastNode
  temp->next = newNode;
}

int insertAfter(int nextTo, int data) {
  // Finding the nextTo node
  struct Node *prev = head;
  while (prev != NULL && prev->data != nextTo)
    prev = prev->next;

  // If the nextTo node is not found element cant be inserted next to it
  if (prev == NULL) {
    return 0;
  }

  // Creating a new node and inserting it in between
  struct Node *newNode = createNode(data);
  newNode->next = prev->next;
  prev->next = newNode;
  return 1;
}

int deleteAtFront() {
  // Can't delete if head is NULL
  if (head == NULL)
    return 0;

  struct Node *temp = head; // Keep temp as a reference to the currentHead
  head = head->next;        // Point temp to the nextNode or NULL
  free(temp);               // Free the previous headNode
  return 1;
}

int deleteAtEnd() {
  // Can't delete if head is NULL
  if (head == NULL)
    return 0;

  // If the last element is the head itself
  if (head->next == NULL) {
    free(head);
    head = NULL;
    return 1;
  }

  // Pointer to denote the second last node to be deleted
  struct Node *temp = head;

  // Finding the second last node
  while (temp->next->next != NULL)
    temp = temp->next;

  free(temp->next);  // Free the last Node
  temp->next = NULL; // Set second last Node pointer to NULL

  return 1;
}

int delete(int data) {
  // Can't delete if head is NULL
  if (head == NULL)
    return 0;

  // If the element to delete is head
  if (head->data == data) {
    deleteAtFront();
    return 1;
  }

  // Pointer to the node before the node to be deleted
  struct Node *prev = NULL;
  struct Node *curr = head;

  // Finding the node to be deleted
  while (curr != NULL && curr->data != data) {
    prev = curr;
    curr = curr->next;
  }

  // If the element to be deleted is not found
  if (curr == NULL)
    return 0;

  // Delete the current Node
  prev->next = curr->next;
  free(curr);

  return 1;
}

void display() {
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  int doRun = 1, choice, temp, temp1;

  printf("LINKED LIST\n------ ----\n");
  printf("1 - Insert at front\n");
  printf("2 - Insert at end\n");
  printf("3 - Insert after\n");
  printf("4 - Delete at front\n");
  printf("5 - Delete at end\n");
  printf("6 - Delete a element\n");
  printf("7 - Display\n");

  while (doRun) {
    printf("\nEnter a choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter value: ");
      scanf("%d", &temp);
      insertAtFront(temp);
      printf("List: ");
      display();
      break;
    case 2:
      printf("Enter value: ");
      scanf("%d", &temp);
      insertAtEnd(temp);
      printf("List: ");
      display();
      break;
    case 3:
      printf("Enter value to insert after: ");
      scanf("%d", &temp1);
      printf("Enter value to insert: ");
      scanf("%d", &temp);
      if (insertAfter(temp1, temp)) {
        printf("List: ");
        display();
      } else {
        printf("Error: Element not found\n");
      }
      break;
    case 4:
      if (deleteAtFront()) {
        printf("List: ");
        display();
      } else {
        printf("Error: Element to be delete not found\n");
      }
      break;
    case 5:
      if (deleteAtEnd()) {
        printf("List: ");
        display();
      } else {
        printf("Error: Element to be delete not found\n");
      }
      break;
    case 6:
      printf("Enter value of element to be deleted: ");
      scanf("%d", &temp);
      if (delete (temp)) {
        printf("List: ");
        display();
      } else {
        printf("Error: Element to be delete not found\n");
      }
      break;
    case 7:
      printf("List: ");
      display();
      break;
    default:
      doRun = 0;
    }
  }
}
