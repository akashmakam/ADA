// GCD of two non-negative integers using the Sieve of Eratosthenes algorithm and Middle School Procedure algorithm.

// Include necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define node structure for linked list
typedef struct node {
    int data;
    struct node *next;
} node;

// Define structure for list
typedef struct list {
    int size;
    node *head;
} list;

// Function to create an empty list
list *createList() {
    list *newList = (list *) malloc(sizeof(list));
    if (newList == NULL) {
        printf("\nMemory could not be dynamically allocated for the new list!\n");
        exit(1);
    }
    newList -> head = NULL;
    newList -> size = 0;
    return newList;
}

// Function to create a new node with given data
node *createNode(int data) {
    node *newNode = (node *) malloc(sizeof(node));
    if (newNode == NULL) {
        printf("\nMemory could not be dynamically allocated for the new node!\n");
        exit(1);
    }
    newNode -> next = NULL;
    newNode -> data = data;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(list *list, int data) {
    node *newNode = createNode(data);
    if (list -> size == 0 || list -> head == NULL) {
        list -> head = newNode;
    } else {
        node *current = list -> head;
        while (current -> next != NULL) {
            current = current -> next;
        }
        current -> next = newNode;
    }
    (list -> size)++;
}

// Function to display the elements of the list
void display(list *list) {
    if (list -> head == NULL) {
        printf("\nThe list is empty, cannot display the list!\n");
        return;
    }
    node *current = list -> head;
    while (current != NULL) {
        printf("%d\t", current -> data);
        current = current -> next;
    }
    printf("\n");
}

// Function to free the memory allocated to the list
void freeList(list *list) {
    if (list -> head != NULL) {
        node *current = list -> head, *nextNode;
        while (current != NULL) {
            nextNode = current -> next;
            free(current);
            current = nextNode;
        }
    }
    free(list);
}

// Sieve of Erathosthenes - Function to generate the list of prime numbers from 2 to 'n'.
list *sieveOfEratosthenes(int n) {
    int *array = malloc((n + 1) * sizeof(int));
    if (array == NULL) {
        printf("\nMemory could not be dynamically allocated for the array!\n");
        exit(1);
    }
    for(int i = 2; i <= n; i++)
        array[i] = i;

    for (int i = 2; i <= sqrt(n); i++) {
        if(array[i] != 0) {
            for (int j = i*i; j <= n; j += i) {
                array[j] = 0;
            }
        }
    }
    list *list = createList();
    for (int i = 2; i <= n; i++) {
        if (array[i] != 0)
            insertAtEnd(list, array[i]);
    }
    free(array);
    return list;
}

// Function to perform prime factorization of a number using the provided prime number list
list *primeFactorization(int num, list *primeNumberList) {
    node *current = primeNumberList -> head;
    list *primeFactorsList = createList();
    while (current != NULL && num != 1) {
        if (num % (current -> data) == 0) {
            num /= (current -> data);
            insertAtEnd(primeFactorsList, current -> data);
        } else {
            current = current -> next;
        }
    }
    return primeFactorsList;
}

// Function to calculate the greatest common divisor (GCD) of a list of prime factors
int greatestCommonDivisor(list *list) {
    int HCF = 1;
    node *current = list -> head;
    while (current != NULL) {
        HCF *= current -> data;
        current = current -> next;
    }
    return HCF;
}

// Function to find the common prime factors between two lists of prime factors
list *findCommonPrimeFactors(list *list1, list *list2) {
    list *commonFactorsList = createList();
    node *current1 = list1->head;
    node *current2 = list2->head;
    while (current1 != NULL && current2 != NULL) {
        if (current1->data == current2->data) {
            insertAtEnd(commonFactorsList, current1->data);
            current1 = current1->next;
            current2 = current2->next;
        } else if (current1->data < current2->data) {
            current1 = current1->next;
        } else {
            current2 = current2->next;
        }
    }
    return commonFactorsList;
}

// Driver code
int main() {
    int m, n, HCF;
    list *mList, *nList, *commonFactorsList;
    // Input first number
    printf("\nEnter a number: ");
    scanf("%d", &m);
    // Validate input
    while(m < 2) {
        printf("\nInvalid range! Enter a number greater than or equal to 2: ");
        scanf("%d", &m);
    }
    // Input second number
    printf("Enter another number: ");
    scanf("%d", &n);
    // Validate input
    while(n < 2) {
        printf("\nInvalid range! Enter a number greater than or equal to 2: ");
        scanf("%d", &n);
    }
    // Generate lists of prime factors for both numbers
    mList = sieveOfEratosthenes(m);
    nList = sieveOfEratosthenes(n);
    mList = primeFactorization(m, mList);
    nList = primeFactorization(n, nList);
    // Find common prime factors between the two lists
    commonFactorsList = findCommonPrimeFactors(mList, nList);
    // Calculate greatest common divisor (GCD) using the common prime factors
    HCF = greatestCommonDivisor(commonFactorsList);
    // Output the result
    printf("\nThe greatest common divisor of %d and %d is %d.\n", m, n, HCF);
    // Free memory allocated for lists
    freeList(mList);
    freeList(nList);
    freeList(commonFactorsList);
    return 0;
}
