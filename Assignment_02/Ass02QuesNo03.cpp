#include <iostream>
using namespace std;

void printArray(char arr[], int size)
{
    cout << "\n";
    for(int i = 0; i < size; i++)
    {
        cout << " " << arr[i];
    }
    cout << "\n";
}

int partition(char arr[], int low, int high, char pivot)
{
    int i = low;
    char temp1, temp2;

    for(int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            temp1 = arr[i];
            arr[i] = arr[j];
            arr[j] = temp1;
            i++;
        }
        else if(arr[j] == pivot)
        {
            temp1 = arr[j];
            arr[j] = arr[high];
            arr[high] = temp1;
            j--;
        }
    }
    temp2 = arr[i];
    arr[i] = arr[high];
    arr[high] = temp2;


    return i;
}

void matchPairs(char nuts[], char bolts[], int low, int high)
{
    if (low < high)
    {


        int pivot = partition(nuts, low, high, bolts[high]);


        partition(bolts, low, high, nuts[pivot]);


        matchPairs(nuts, bolts, low, pivot - 1);
        matchPairs(nuts, bolts, pivot + 1, high);
    }
}

int main()
{
    int i, n;
    cout << "Enter the value of n: ";
    cin >> n;

    char nuts[100];
    cout << "Input array of nuts:\n";
    for (i = 0; i < n; ++i){
        cin >> nuts[i];
    }

    char bolts[100];
    cout << "Input array of bolts:\n";
    for (i = 0; i < n; ++i){
        cin >> bolts[i];
    }

    matchPairs(nuts, bolts, 0, n - 1);

    cout << "Matched nuts and bolts are:\n";
    printArray(nuts, n);
    printArray(bolts, n);

    return 0;
}
