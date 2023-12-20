#include <iostream>
#include <vector>
#include <chrono>
#include <random>

void bubbleSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}

void selectionSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        if (minIndex != i)
            std::swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    // Generate a large random array
    const int SIZE = 5000;
    std::vector<int> arr(SIZE);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10000);

    for (int &i : arr)
    {
        i = dis(gen);
    }

    // Measure execution time for Bubble Sort
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(arr);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Bubble Sort execution time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds\n";

    // Measure execution time for Selection Sort
    start = std::chrono::high_resolution_clock::now();
    selectionSort(arr);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Selection Sort execution time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds\n";

    // Measure execution time for Insertion Sort
    start = std::chrono::high_resolution_clock::now();
    insertionSort(arr);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Insertion Sort execution time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds\n";

    return 0;
}
