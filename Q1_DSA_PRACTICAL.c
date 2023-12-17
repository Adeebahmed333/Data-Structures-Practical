
#include <stdio.h>

// Function to display the elements of an array
void traverse(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

// Function to insert an element at a specific index in the array
int insertAtIndex(int arr[], int size, int element, int index) {
    if (size >= 100 || index < 0 || index > size) {   
        printf("Cannot Insert Please Enter Correct Size Or Index.\n");
        return size;//returning the unchanged size
    }

    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];//shifting the elements forward by 1 position
    }

    arr[index] = element;//inserting the element at position
    size++;//increasing the size of the array by 1
    printf("Element Inserted !\n");
    return size;//returning the increased size
}

// Function to delete an element at a specific index in the array
int deleteAtIndex(int arr[], int size, int index) {
    if (size == 0 || index < 0 || index >= size) {
        printf("Cannot Insert Please Enter Correct Size Or Index.\n");
        return size;//returning the unchanged size as input is invalid
    }

    printf("Element Deleted!\n");

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];//shifting the elements backward by 1 position
    }

    size--;//reducing the size by 1 
    return size;//returning decreased size
}

// Function to perform a linear search and find the position of an element in the array
int linearSearch(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;//Returning the Index On which Element Is found
        }
    }
    return -1; // Element not found
}



int main() {
    int arr[100];
    int size ;
    printf("Enter The Size Of The Array(Size must be <=100):\n");
    scanf("%d",&size);
    printf("Enter The Elements In Array:\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Traverse the array\n");
        printf("2. Insert an element at an index\n");
        printf("3. Delete an element at an index\n");
        printf("4. Linear search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse(arr, size);
                break;
            case 2:
                int element, index;
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the index to insert: ");
                scanf("%d", &index);
                size = insertAtIndex(arr, size, element, index);
                break;
            case 3:
                printf("Enter the index to delete: ");
                scanf("%d", &index);
                size = deleteAtIndex(arr, size, index);
                break;
            case 4:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                int result = linearSearch(arr, size, element);
                if (result != -1) {
                    printf("Element %d found at index %d.\n", element, result);
                } else {
                    printf("Element %d not found in the array.\n", element);
                }
                break;
           
            case 5:
                printf("Thank You ! \nExiting the program.\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (choice != 6);

    return 0;
}
