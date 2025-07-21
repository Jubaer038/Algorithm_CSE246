#include <iostream>
using namespace std;


void towerOfHanoi(int n, char first,
				char middle, char last)
{
	if (n == 1) {

		cout << "Move disk " << n
			<< " from rod " << first
			<< " to " << middle
			<< " and then to "
			<< last << endl;

		return;
	}

	towerOfHanoi(n - 1, first, middle, last);


	cout << "Move disk " << n
		<< " from rod " << first
		<< " to " << middle << endl;

	towerOfHanoi(n - 1, last, middle, first);

	cout << "Move disk " << n
		<< " from rod " << middle
		<< " to " << last << endl;

	towerOfHanoi(n - 1, first, middle, last);
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
