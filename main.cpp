#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <cstdlib>

using namespace std;
int partition (int quick_number[10], int low, int high, int n);
void heapify(int number[10], int i, int n);
void heapsort(int number[10], int n);
void quicksort(int quick_number[10], int low, int high, int n);
void print_array(int number[10], int n);
void swap(int *a, int *b);

int main()
{
    int quick_number[10];
    int i = 0;
    int number[10];
    ifstream input;
    input.open("a5.txt");
    if (!input.is_open())
    {
        cout << "sorry can't open file." << endl;
    }
    while (input.good())
    {
        input >> number[i];
        i++;
    }
    int n = sizeof(number)/sizeof(number[0]);
    for (int i=0; i<n; i++)
    {
        quick_number[i] = number[i];
    }
    cout << "Here is the current set of numbers: " << endl;
    for (int i=0; i<n; i++)
    {
        cout << i << ". " << number[i] << endl;
    }
    cout << "Here are the steps to making the array with heapsort. " << endl;
    system("pause");
    heapsort(number, n);
    cout << "Here is the sorted heap. " << endl << endl;
    print_array(number, n);
    cout << endl << endl;
    system("pause");
    cout << "Here are the step with quick sorting the array. " << endl;
    quicksort(quick_number, 0, n-1, n);
    cout << "Here is the array after quicksort. " << endl << endl;
    print_array(quick_number, n);
    return 0;
}
void heapify(int number[10], int i, int n)
{
    int largest = i;
    int l = 2*i +1;
    int r = 2*i+2;
    if (l < n && number[l] > number[largest])
    {
        largest = l;
    }
    if (r < n && number[r] > number[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(number[i], number[largest]);
        heapify(number, i, n);
    }
}

void heapsort(int number[10], int n)
{
    for (int i = n/2-1; i>=0; i--)
    {
        heapify(number, i, n);
    }
    for (int i=n-1; i>=0; i--)
    {
        swap(number[0], number[i]);
        heapify(number, 0, i);
        print_array(number, n);
    }
}

void print_array(int number[10], int n)
{
    for (int i=0; i<n; i++)
    {
        cout << number[i] << " ";
    }
    cout << endl;
}

void quicksort(int quick_number[10], int low, int high, int n)
{
    if (low < high)
    {
        int pi = partition(quick_number, low, high, n);
        quicksort(quick_number, low, pi-1, n);
        quicksort(quick_number, pi+1, high, n);
    }

}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int quick_number[10], int low, int high, int n)
{
    int pivot = quick_number[high];
    int i = (low -1);
    for (int j=low; j<= high - 1; j++)
    {
        if (quick_number[j] <= pivot)
        {
            i++;
            swap(&quick_number[i], &quick_number[j]);
        }

    }
    swap(&quick_number[i + 1], &quick_number[high]);
    print_array(quick_number, n);
    return (i+1);
}
