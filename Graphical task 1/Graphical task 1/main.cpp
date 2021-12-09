#include<iostream>
#include<ctime>
#include<cmath>
#include<iomanip>
#include <chrono>
#define M 100
using namespace std;



int Gnome_sort(int arr[], int size){
    int index = 0;
    while (index < size) {
        if (index == 0) {
            index++;
        }
        if (arr[index] >= arr[index - 1]) {
            index++;
        }
        else{
            int t = arr[index];
            arr[index] = arr[index-1];
            arr[index-1]=t;
            index--;
        }
    }
    return arr[size];
}
void heapify(int arr[], int n, int i)
{
    int curr = arr[i];
    int index = i;
    for (; ; ) {
        int left = index + index + 1;
        int right = left +1;
        if (left < n && arr[left] > curr) {
            index = left;
        }
        if (right < n && arr[right] > curr) {
            index = right;
        }
        if (index == i) {
            break;
        }
        arr[i] = arr[index];
        arr[index] = curr;
        i = index;
    }
}

int heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;

        
        heapify(arr, i, 0);
    }
    return arr[n];
}
int main()
{
    while (true) {

        cout.setf(ios::fixed);
        cout.precision(7);

        
        int size;
        cout << "Введите размер массива: ";
        cin >> size;

        int arr[1000];

        cout << "Несортированный массив: " << endl;
        for (int i = 0; i < size; i++) {

            arr[i] = rand() % 10 + 1;
            cout << setw(3) << arr[i];

        }
        
        char ans;
        cout<< endl <<"Какую сортировку вы хотите использовать гномью или пирамидальную?(g/h)";
        cin>>ans;
        char gnome;
        gnome = 'g';
        char heap;
        heap = 'h';
        
        
        int prep_arr[100];
            for (int i = 0; i < size; ++i) {
                prep_arr[i] = arr[i];
                    // cout << setw(3) << arr[i];
        }
        
        
        
        double dur_arr[M];
        double average = 0;
        if (ans == gnome) {
            for (int i = 0; i < M; i++)
            {

                auto t1 = chrono::high_resolution_clock::now();

                Gnome_sort(arr, size);

                auto t2 = chrono::high_resolution_clock::now();
                chrono::duration<double> duration = t2 - t1;

                dur_arr[i] = duration.count();

                cout << endl <<"Сортированный массив:" << endl;
                for (int i = 0; i < size; i++) {
                    cout << setw(3) << arr[i];
                }
                
                cout << endl;
                
                for (int i = 0; i < size; ++i) {
                    arr[i] = prep_arr[i];
                    cout << setw(3) << arr[i];
                }

            }
        }
        
        else if (ans == heap) {
            for (int i = 0; i < M; i++)
            {

                auto t1 = chrono::high_resolution_clock::now();

                heapSort(arr, size);

                auto t2 = chrono::high_resolution_clock::now();
                chrono::duration<double> duration = t2 - t1;

                dur_arr[i] = duration.count();

                cout << endl << "Сортированный массив:" << endl;
                for (int i = 0; i < size; i++) {
                    cout << setw(3) << arr[i];
                }
                
                cout << endl;
                for (int i = 0; i < size; ++i) {
                    arr[i] = prep_arr[i];
                    cout << setw(3) << arr[i];
                }

            }
        }

        for (int i = 0; i < M; i++) {
            cout << endl <<"Время выполнения " << i + 1 << " = " << dur_arr[i] << "сек." << endl;
        }

        double temp = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M - i - 1; j++) {
                if (dur_arr[j] > dur_arr[j + 1]) {
                    temp = dur_arr[j];
                    dur_arr[j] = dur_arr[j + 1];
                    dur_arr[j + 1] = temp;
                }
            }
       }


        for (int i = ((M / 100) * 40); i < M - ((M / 100) * 40); ++i) {
            average += dur_arr[i];
        }
        
        average = average / ((M / 100) * 20);

        cout << endl <<"Время:" << average << "сек." << endl;


    }

    return 0;
    
}
