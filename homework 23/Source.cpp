#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

void showArr(int array[], int length);

void threeMax(int& refNum1, int& refNum2, int& refNum3);

int &firstNeg(int array[], int length);

void zerOut(int array1[], int length1, int array2[], int length2);


int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int a, b, c;

		//������ 1
	cout << "������ 1\n������� 3 �����: ";
	cin >> a >> b >> c;
	threeMax(a, b, c);
	cout << a << " " << b << " " << c << endl << endl;

		//������ 2
	cout << "������ 2\n��� ��������� ������, ��������� �� 10 ���������, � ���������� �� -10 �� 10" << endl;
	int arr[10];
	for (int i = 0; i < 10; i++)
		arr[i] = rand() % (10 - (-10) + 1) - 10;
	showArr(arr, 10);
	cout << "������ ������������� ������� �������: " << firstNeg(arr, 10) << endl << endl;

		//������ 3
	cout << "������ 3\n���� ��� �������: " << endl;
	int arr1[7] = { 3, 6, 4, 1, 4, 8, 2 };			//� ������� ������ �� �����, ���� � ������ ���������. �� ������� �������� ��� � �����������, ��� � ���.
	int arr2[6] = { 5, 3, 1, 5, 10, 8 };
	int* pArr1 = arr1;
	int* pArr2 = arr2;
	showArr(pArr1, 7);
	showArr(pArr2, 6);
	zerOut(pArr1, 7, pArr2, 6);
	cout << "������ 2 ����� ������ �������: " << endl;
	showArr(pArr2, 6);




	return 0;
}

			//������ 3
void zerOut(int array1[], int length1, int array2[], int length2) {
	for (int i = 0; i < length1; i++) {
		for (int j = 0; j < length2; j++)
			if (array1[i] == array2[j])
				array2[j] = 0;
	}
}

			//������ 2
int &firstNeg(int array[], int length) {
	int neg = 0;
	for (int i = 0; i < length; i++) {
		if (array[i] < 0) {
			neg = i;
			return array[neg];
		}
	}
	return array[0];
}

			//������ 1
void threeMax(int& refNum1, int& refNum2, int& refNum3) {
	if (refNum1 >= refNum2 && refNum1 >= refNum3) {
		refNum2 = refNum1;
		refNum3 = refNum1;
	}
	if (refNum2 >= refNum1 && refNum2 >= refNum3) {
		refNum1 = refNum2;
		refNum3 = refNum2;
	}
	if (refNum3 >= refNum1 && refNum3 >= refNum2) {
		refNum1 = refNum3;
		refNum2 = refNum3;
	}
}

void showArr(int array[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << array[i] << ", ";
	cout << "\b\b]\n\n";
}