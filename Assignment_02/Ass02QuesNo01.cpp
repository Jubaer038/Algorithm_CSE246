#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod,
                  char aux_rod)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod
         << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int num;
    cout << "Enter the number of disks : ";
    cin >> num;
    cout << "The sequence of moves involved in the Tower of Hanoi are :\n";

    towerOfHanoi(num, 'A', 'C', 'B');
    return 0;
}


