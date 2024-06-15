#include <stdio.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Insertion Sort
void insertionSort(int array[], int size)
{
    for (int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;

        while (j >= 0 && key < array[j])
        {
            array[j + 1] = array[j];
            --j;
        }

        array[j + 1] = key;
    }
}

// Bubble Sort
void bubbleSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
            {
                min_idx = j;
            }
        }

        int temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
    }
}

// Quick Sort
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pivot = array[(low + high) / 2];
        int i = low - 1;
        int j = high + 1;

        while (1)
        {
            do
            {
                i++;
            } while (array[i] < pivot);

            do
            {
                j--;
            } while (array[j] > pivot);

            if (i >= j)
            {
                break;
            }

            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }

        quickSort(array, low, j);
        quickSort(array, j + 1, high);
    }
}

// Merge Sort
void merge(int array[], int left[], int left_size, int right[], int right_size)
{
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            array[k++] = left[i++];
        }
        else
        {
            array[k++] = right[j++];
        }
    }

    while (i < left_size)
    {
        array[k++] = left[i++];
    }

    while (j < right_size)
    {
        array[k++] = right[j++];
    }
}

void mergeSort(int array[], int size)
{
    if (size <= 1)
    {
        return;
    }

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++)
    {
        left[i] = array[i];
    }

    for (int i = mid; i < size; i++)
    {
        right[i - mid] = array[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(array, left, mid, right, size - mid);
}

int main()
{
    int data[5] = {23,45,12,9,56};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Original array: ");
    printArray(data, size);

    printf("Insertion Sort: ");
    int data_copy1[5] = {9, 5, 1, 4, 3};
    insertionSort(data_copy1, size);
    printArray(data_copy1, size);

    printf("Bubble Sort: ");
    int data_copy2[5] = {9, 5, 1, 4, 3};
    bubbleSort(data_copy2, size);
    printArray(data_copy2, size);

    printf("Selection Sort: ");
    int data_copy3[5] = {9, 5, 1, 4, 3};
    selectionSort(data_copy3, size);
    printArray(data_copy3, size);

    printf("Quick Sort: ");
    int data_copy4[5] = {9, 5, 1, 4, 3};
    quickSort(data_copy4, 0, size - 1);
    printArray(data_copy4, size);

    printf("Merge Sort: ");
    int data_copy5[5] = {9, 5, 1, 4, 3};
    mergeSort(data_copy5, size);
    printArray(data_copy5, size);

    return 0;
}