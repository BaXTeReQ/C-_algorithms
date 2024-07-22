#include <iostream>

using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) cout << arr[i] << " ";

    cout << endl;
}

void buildHeap(int arr[], int size, int i) {
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left < size && arr[left] > arr[largest]) swap(arr[left], arr[largest]);

    if (right < size && arr[right] > arr[largest]) swap(arr[right], arr[largest]);

    if (largest < size) buildHeap(arr, size, i + 1);

}

void heapsort(int arr[], int size) {
    for (int i = 0; i <= size / 2 - 1; i++) buildHeap(arr, size, i);
    for (int i = size / 2 - 1; i >= 0; i--) buildHeap(arr, size, i);

    for (int i = size - 1; i > 0; i--) {
        printArray(arr, i + 1);
        swap(arr[0], arr[i]);
        buildHeap(arr, i, 0);
    }
}

int main()
{
    int counter = 0, size = 0;
    cin >> counter;
    while (counter > 0)
    {
        cin >> size;
        int* arr = new int[size];

        for (int i = 0; i < size; i++) cin >> arr[i];

        heapsort(arr, size);

        printArray(arr, size);

        if (counter > 1) cout << endl;

        delete[] arr;
        counter--;
    }

    return 0;
}