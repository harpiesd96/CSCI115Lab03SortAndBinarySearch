#include <iostream>
#include <random>
#include <chrono>
#include <math.h>

static constexpr size_t ARRAY_SIZE = 128;

//swaps 2 integers
void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

//print array
void PrintArray(int* array)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

//bubble sort
void BubbleSort(int* array)
{
    bool sorted;
    do
    {
        sorted = true;
        for (int i = 0; i < ARRAY_SIZE-1; i++)
        {
            if (array[i] > array[i + 1])
            {
                sorted = false;
                swap(array[i], array[i+1]);
            }
        }
    } while (sorted == false);
}

//selection sort
void SelectionSort(int* array)
{
    int i, j, imin;
    for (i = 0; i < ARRAY_SIZE-1; i++)
    {
        imin = i;
        for (j = i+1; j < ARRAY_SIZE; j++)
        {
            if (array[j] < array[imin])
            {
                imin = j;
            }
        }
        if (imin != j)
        {
            swap(array[i], array[imin]);
        }
    }
}

//insertion sort
void InsertionSort(int* array)
{
    int i, j;
    for (i = 1; i < ARRAY_SIZE - 1; i++)
    {
        j = i;
        while ((j > 0) && (array[j - 1] > array[j]))
        {
            swap(array[j], array[j - 1]);
            j--;
        }
    }
}

//iterative binary search (returns index of query in array, returns -1 if nothing has been found)
int IBinarySearch(int* array, int query)
{
    int low = 0;
    int high = ARRAY_SIZE - 1;
    int mid = (int)floor((low + high) / 2);

    do
    {
        if (query == array[mid])
        {
            return mid;
        }
        else if(query > array[mid])
        {
            low = mid;
            mid = (int)floor((low + high) / 2);
            if (low == mid && array[high] != query) { return -1; }
            else if (array[high] == query) { return high; }
        }
        else // query < array[mid]
        {
            high = mid;
            mid = (int)floor((low + high) / 2);
            if (low == mid && array[mid] != query) { return -1; }
        }
    } while (true);
}

//recursive binary search (returns index of query in array, returns -1 if nothing has been found)
int RBinarySearch(int* array, int query, int low, int high)
{
    int mid = (int)floor((low + high) / 2);
    if (query == array[mid])
    {
        return mid;
    }
    else if (query > array[mid])
    {
        if (low == mid && array[high] != query){ return -1; }
        else if (array[high] == query) { return high; }
        low = mid;
        RBinarySearch(array, query, low, high);
    }
    else // query < array[mid]
    {
        if (low == mid && array[mid] != query) { return -1; }
        high = mid;
        RBinarySearch(array, query, low, high);
    }
}


int main()
{
    std::cout << "Hello World!\n" << std::endl;

    char input;
    int user_query, result;

    do
    {
        //create arrays to be sorted
        int container0[ARRAY_SIZE];
        int container1[ARRAY_SIZE];
        int container2[ARRAY_SIZE];
        //populate arrays randomly
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            int j = rand() % 100;
            container0[i] = j;
            container1[i] = j;
            container2[i] = j;
        }


        //show container
        std::cout << "bubble sort:" << std::endl;
        PrintArray(container0);
        //record start time
        auto start = std::chrono::high_resolution_clock::now();
        //insertion sort array
        BubbleSort(container0);
        //record end time
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<long double> delta_time = end - start;
        //show results of bubble sort
        PrintArray(container0);
        std::cout << "sort time: " << delta_time.count() << "s\n" << std::endl;


        //show container
        std::cout << "selection sort:" << std::endl;
        PrintArray(container1);
        //record start time
        start = std::chrono::high_resolution_clock::now();
        //selection sort array
        SelectionSort(container1);
        //record end time
        end = std::chrono::high_resolution_clock::now();
        delta_time = end - start;
        //show results of bubble sort
        PrintArray(container1);
        std::cout << "sort time: " << delta_time.count() << "s\n" << std::endl;


        //show container
        std::cout << "insertion sort:" << std::endl;
        PrintArray(container2);
        //record start time
        start = std::chrono::high_resolution_clock::now();
        //insertion sort array
        InsertionSort(container2);
        //record end time
        end = std::chrono::high_resolution_clock::now();
        delta_time = end - start;
        //show results of bubble sort
        PrintArray(container2);
        std::cout << "sort time: " << delta_time.count() << "s\n" << std::endl;


        std::cout << "enter number to find:" << std::endl;
        std::cin >> user_query;
        std::cout << std::endl;

        
        //test IBianarySearch
        //record start time
        start = std::chrono::high_resolution_clock::now();
        result = IBinarySearch(container0, user_query);
        //record end time
        end = std::chrono::high_resolution_clock::now();
        delta_time = end - start;
        if (result != -1)
        {
            std::cout << "query found at index " << result << std::endl;
        }
        else
        {
            std::cout << "query not found" << std::endl;
        }
        std::cout << "sort time: " << delta_time.count() << "s\n" << std::endl;

        //test RBinarySearch
        //record start time
        start = std::chrono::high_resolution_clock::now();
        result = RBinarySearch(container0, user_query, 0, ARRAY_SIZE-1);
        //record end time
        end = std::chrono::high_resolution_clock::now();
        if (result != -1)
        {
            std::cout << "query found at index " << result << std::endl;
        }
        else
        {
            std::cout << "query not found" << std::endl;
        }
        std::cout << "sort time: " << delta_time.count() << "s\n" << std::endl;


        std::cout << "continue? y/n" << std::endl;
        std::cin >> input;
    } while (input == 'y');
}