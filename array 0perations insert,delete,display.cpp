#include <stdio.h>

#define MAX_SIZE 100


int insert(int arr[], int size, int index, int value) {
    if (index < 0 || index > size || size == MAX_SIZE) {
        return -1;  
    }

    
    for (int i = size; i > index; --i) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    return size + 1; 
}

int deleteElement(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        return -1;  
    }

    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    return size - 1; 
}

void display(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0, choice, index, value;

    while (1) {
        printf("\nArray Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter index and value to insert: ");
                scanf("%d %d", &index, &value);
                size = insert(arr, size, index, value);
                if (size == -1) {
                    printf("Insertion failed. Invalid index or array is full.\n");
                } else {
                    printf("Element inserted successfully.\n");
                }
                break;
            case 2:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                size = deleteElement(arr, size, index);
                if (size == -1) {
                    printf("Deletion failed. Invalid index.\n");
                } else {
                    printf("Element deleted successfully.\n");
                }
                break;
            case 3:
                display(arr, size);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
