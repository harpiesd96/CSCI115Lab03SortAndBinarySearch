#include <iostream>
#include <random>
#include <chrono>

static constexpr size_t ARRAY_SIZE = 256;

//bubble sort
void BubbleSort(int* array)
{
    bool sorted;
    int temp;
    do
    {
        sorted = true;
        for (int i = 0; i < ARRAY_SIZE-1; i++)
        {
            if (array[i] > array[i + 1])
            {
                sorted = false;
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    } while (sorted == false);
}

//insertion sort


//selection sort


//iterative binary search


//recursive binary search


//print array
void PrintArray(int* array)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::cout << "Hello World!\n" << std::endl;

    char input;

    do
    {
        int container[ARRAY_SIZE];
        //populate array randomly
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            container[i] = rand() % 100;
        }
        PrintArray(container);
        auto start = std::chrono::high_resolution_clock::now();
        BubbleSort(container);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<long double> delta_time = end - start;
        PrintArray(container);
        std::cout << "sort time: " << delta_time.count() << "s\n" << std::endl;

        std::cout << "continue? y/n" << std::endl;
        std::cin >> input;
    } while (input == 'y');

}