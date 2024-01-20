#include <iostream>
#include<fstream>
using namespace std;
 
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}
 
void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
int main()
{
  //  int arr[] = { 12, 11, 13, 5, 6, 7 };
 //   int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
 
  //  cout << "Sorted array is \n";
  //  printArray(arr, N);
    ifstream fi("randno.txt");
    int arr[10000], x;
    for(int i=0; !fi.eof()&&i<10000; arr[i++]=x){
        fi>>x; 
    }
    fi.close();

    heapSort(arr, 10000);
	
    ofstream fo;
    fo.open("ascending.txt");
	for(int i=0; i<10000; i++) fo<<arr[i]<<'\t';
    fo.close();
}
