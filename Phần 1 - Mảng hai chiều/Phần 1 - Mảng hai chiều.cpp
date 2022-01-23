/*
 - BT Nhóm : Phần - 02
 - Project 1 : Mảng 2 chiều
 - Group : 1
	+ 2001216199 - Nguyễn Minh Thư (Nhóm trưởng)
	+ 2001215790 - Nguyễn Huy Hoàng
	+ 2001215664 - Nguyễn Công Dũng
	+ 2001216306 - Lê Thị Khánh Vân
 - Last modify : 23:00 - 22/01/2022
*/
//Declare Library
#include <iostream>
//
using std::cout;
using std::cin;
using std::endl;
//

//Declare Constant
#define MAX 100

//Declare Function Prototype

//
void Menu();
void createRandomMatrix(int arr[][MAX], int& n);
void displayTheMatrix(int arr[][MAX], int n);
void displayTheEvenValuesOnTheMainDiagonal(int arr[][MAX], int n);
void displayTheOddValuesOnTheAuxiliaryDiagonal(int arr[][MAX], int n);
void displayThePositiveValuesOnTheBorderline(int arr[][MAX], int n);
bool isPrimeNumber(int a);
int sumThePrimeNumbersOnUpperTriangle(int arr[][MAX], int n);
bool isPerfectSquareNumber(int a);
int sumPerfectSquareNumberLowerTriangleMainDiagonal(int arr[][MAX], int n);
int getTheMinValueInMatrix(int arr[][MAX], int n);
int getTheMinPositiveValueInMatrix(int arr[][MAX], int n);
int getTheMaxNegativeValueInMatrix(int arr[][MAX], int n);
int countTwoDigitNumbersOnUpperTriangleMainDiagonal(int arr[][MAX], int n);
int countPrimeNumbersOnUpperTriangleAuxiliaryDiagonal(int arr[][MAX], int n);
bool isMatrixHavingAllPositiveValue(int arr[][MAX], int n);
bool isPerfectNumber(int n);
bool isTheMatrixHavingThePerfectNumber(int arr[][MAX], int n);
void swap(int& a, int& b);
void sortAscendingRow(int arr[][MAX], int n, int r);
void sortAscendingFromLeftToRight(int arr[][MAX], int n);
void sortAscendingColumn(int arr[][MAX], int n, int c);
void sortAscendingFromUpToDown(int arr[][MAX], int n);
void sortPositiveValuesDescendingOnRow(int arr[][MAX], int n, int r);
void sortNegativeValuesAscendingOnRow(int arr[][MAX], int n, int r);
void sortMatrixHavingNegativeValuesAscendingAndPositiveValuesDescendingFromLeftToRight(int arr[][MAX], int n);
void sortPositiveValuesDescendingOnColumn(int arr[][MAX], int n, int c);
void sortNegativeValuesAscendingOnColumn(int arr[][MAX], int n, int c);
void sortMatrixHavingNegativeValuesAscendingAndPositiveValuesDescendingFromUpToDown(int arr[][MAX], int n);
//

int main() {
	int arr[MAX][MAX];
	int n = 0;
	int option = 0;
	do {
		system("cls");
		Menu();
		cout << "Hay chon phuong thuc : "; cin >> option;
		system("cls");
		if (option > 2 && option <= 17) {
			displayTheMatrix(arr, n);
			cout << endl;
		}
		switch (option) {
		case 0:cout << "Goodbye  !:<" << endl;
			break;
		case 1:
			createRandomMatrix(arr, n);
			cout << "Khoi tao gia tri ngau nhien hoan tat !" << endl;
			break;
		case 2:
			displayTheMatrix(arr, n);
			break;
		case 3:
			cout << "Cac phan tu chan thuoc duong cheo chinh cua ma tran la : ";
			displayTheEvenValuesOnTheMainDiagonal(arr, n);
			break;
		case 4:
			cout << "Cac phan tu le thuoc duong cheo phu cua ma tran la : ";
			displayTheOddValuesOnTheAuxiliaryDiagonal(arr, n);
			break;
		case 5:
			cout << "Cac phan tu la so duong thuoc duong bien cua ma tran la : ";
			displayThePositiveValuesOnTheBorderline(arr, n);
			break;
		case 6:
			cout << "Tong cac gia tri la so nguyen to thuoc tam giac tren duong cheo chinh la : " << sumThePrimeNumbersOnUpperTriangle(arr, n) << endl;
			break;
		case 7:
			cout << "Tong cac phan tu la so chinh phuong thuoc tam giac duoi cua duong cheo chinh la : " << sumPerfectSquareNumberLowerTriangleMainDiagonal(arr, n) << endl;
			break;
		case 8:
			cout << "Phan tu co gia tri nho nhat tren ma tran la : " << getTheMinValueInMatrix(arr, n) << endl;
			break;
		case 9:
			cout << "Phan tu duong nho nhat tren ma tran la : " << getTheMinPositiveValueInMatrix(arr, n) << endl;
			break;
		case 10:
			cout << "Phan tu am lon nhat tren ma tran la : " << getTheMaxNegativeValueInMatrix(arr, n) << endl;
			break;
		case 11:
			cout << "So cac so co 2 chu so thuoc tam giac tren cua duong cheo chinh trong ma tran la : " << countTwoDigitNumbersOnUpperTriangleMainDiagonal(arr, n) << endl;
			break;
		case 12:
			cout << "So cac so nguyen to thuoc tam giac tren cua duong cheo phu trong ma tran la : " << countPrimeNumbersOnUpperTriangleAuxiliaryDiagonal(arr, n) << endl;
			break;
		case 13:
			if (isMatrixHavingAllPositiveValue(arr, n)) {
				cout << "Ma tran co cac gia tri toan duong" << endl;
			}
			else {
				cout << "Ma tran khong toan la cac gia tri duong" << endl;
			}
			break;
		case 14:
			if (isTheMatrixHavingThePerfectNumber(arr, n)) {
				cout << "Ma tran co ton tai so hoan hao (so hoan thien)" << endl;
			}
			else {
				cout << "Ma tran khong ton tai so hoan hao (so hoan thien)" << endl;
			}
			break;
		case 15:
			sortAscendingFromLeftToRight(arr, n);
			sortAscendingFromUpToDown(arr, n);
			cout << "Sap xep hoan tat!" << endl;
			displayTheMatrix(arr, n);
			break;
		case 16:
			sortAscendingFromUpToDown(arr, n);
			sortAscendingFromLeftToRight(arr, n);
			cout << "Sap xep hoan tat!" << endl;
			displayTheMatrix(arr, n);
			break;
		case 17:
			sortMatrixHavingNegativeValuesAscendingAndPositiveValuesDescendingFromLeftToRight(arr, n);
			sortMatrixHavingNegativeValuesAscendingAndPositiveValuesDescendingFromUpToDown(arr, n);
			cout << "Sap xep hoan tat!" << endl;
			displayTheMatrix(arr, n);
			break;
		default:cout << "Phuong thuc khong hop le !! :<" << endl;
		}
		system("pause>0");
	} while (option != 0);
	return 0;
}

void Menu() {
	cout << "Welcome to Menu!" << endl;
	cout << "1.\tTao ma tran bang cach phat sinh cac phan tu, cac phan tu thuoc doan [ -60 , 80 ] ." << endl;
	cout << "2.\tXuat cac phan tu trong ma tran." << endl;
	cout << "3.\tXuat cac phan tu chan thuoc duong cheo chinh cua ma tran." << endl;
	cout << "4.\tXuat cac phan tu le thuoc duong cheo phu cua ma tran." << endl;
	cout << "5.\tXuat cac phan tu la so duong thuoc duong bien cua ma tran." << endl;
	cout << "6.\tTinh tong cac gia tri la so nguyen to thuoc tam giac tren duong cheo chinh." << endl;
	cout << "7.\tTinh tong cac phan tu la so chinh phuong thuoc tam giac duoi cua duong cheo chinh." << endl;
	cout << "8.\tTim phan tu co gia tri nho nhat tren ma tran." << endl;
	cout << "9.\tTim phan tu duong nho nhat tren ma tran" << endl;
	cout << "10.\tTim phan tu am lon nhat tren ma tran" << endl;
	cout << "11.\tDem cac so co 2 chu so thuoc tam giac tren cua duong cheo chinh trong ma tran." << endl;
	cout << "12.\tDem cac so nguyen to thuoc tam giac tren cua duong cheo phu trong ma tran." << endl;
	cout << "13.\tKiem tra ma tran co toan duong." << endl;
	cout << "14.\tKiem tra ma tran co ton tai so hoan hao (so hoan thien) hay khong." << endl;
	cout << "15.\tSap xep ma tran tang dan tu trai sang phai tu tren xuong duoi" << endl;
	cout << "16.\tSap xep ma tran tang dan tu tren xuong duoi tu trai sang phai" << endl;
	cout << "17.\tSap xep ma tran tu trai sang phai tu tren xuong duoi cac so am tang dan va cac so duong giam dan" << endl;
}

//1.a
//Ham tao ma tran voi gia tri ngau nhien
void createRandomMatrix(int arr[][MAX], int& n) {
	cout << "Tao ma tran !" << endl;
	cout << "Hay nhap canh(cot hoac hang) cua ma tran : "; cin >> n;
	//pseudo-random numbers
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = rand() % 141 - 60;//%141 => (0->140), %141 - 60 => [-60,80]
		}
	}
}
//1.b
//Ham xuat ma tran
void displayTheMatrix(int arr[][MAX], int n) {
	cout << "Xuat ma tran: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << "\t ";
		}
		cout << endl;
	}
}
//1.c
//Ham hien thi cac gia tri chan tren duong cheo chinh
void displayTheEvenValuesOnTheMainDiagonal(int arr[][MAX], int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i][i] % 2 == 0) {
			cout << arr[i][i] << " ";
		}
	}
}
//1.d
//Ham hien thi cac gia tri le tren duong cheo phu
void displayTheOddValuesOnTheAuxiliaryDiagonal(int arr[][MAX], int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i][n - 1 - i] % 2 != 0) {
			cout << arr[i][n - 1 - i] << " ";
		}
	}
}
//1.e
//Ham hien thi cac gia tri duong tren 4 bien
void displayThePositiveValuesOnTheBorderline(int arr[][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
				if (arr[i][j] % 2 == 0) {
					cout << arr[i][j] << " ";
				}
			}
		}
	}
}
//1.f
//Ham check so nguyen to
bool isPrimeNumber(int a) {
	if (a < 2) return false;
	if (a == 2) return true;
	if (a % 2 == 0) return false;
	for (int i = 3; i * i <= a; ++i) {
		if (a % i == 0) return false;
	}
	return true;
}
//Ham tinh tong cac so nguyen to thuoc tam giac tren
int sumThePrimeNumbersOnUpperTriangle(int arr[][MAX], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= i; j--) {
			if (isPrimeNumber(arr[i][j])) {
				sum += arr[i][j];
			}
		}
	}
	return sum;
}
//1.g
//Ham check so chinh phuong
bool isPerfectSquareNumber(int a) {
	if (a < 0)return false;
	int n = sqrt(a);
	return n * n == a;
}
//Ham tinh tong cac so chinh phuong thuoc tam giac duoi
int sumPerfectSquareNumberLowerTriangleMainDiagonal(int arr[][MAX], int n) {
	int sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			if (isPerfectSquareNumber(arr[i][j])) {
				sum += arr[i][j];
			}
		}
	}
	return sum;
}
//1.h
//Ham tim gia tri nho nhat tren ma tran
int getTheMinValueInMatrix(int arr[][MAX], int n) {
	int min = arr[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (min > arr[i][j]) {
				min = arr[i][j];
			}
		}
	}
	return min;
}
//1.i
//Ham tim gia tri duong nho nhat tren ma tran
int getTheMinPositiveValueInMatrix(int arr[][MAX], int n) {
	bool flag = false;
	int min = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > 0) {
				if (flag == false) {
					min = arr[i][j];
					flag = true;
				}
				else {
					if (arr[i][j] < min) {
						min = arr[i][j];
					}
				}
			}
		}
	}
	return min;
}
//1.j
//Ham tim gia tri am lon nhat tren ma tran
int getTheMaxNegativeValueInMatrix(int arr[][MAX], int n) {
	bool flag = false;
	int max = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] < 0) {
				if (flag == false) {
					max = arr[i][j];
					flag = true;
				}
				else {
					if (arr[i][j] > max) {
						max = arr[i][j];
					}
				}
			}
		}
	}
	return max;
}
//1.k
//Ham tim gia tri co hai chu so tren tam giac tren duong cheo chinh
int countTwoDigitNumbersOnUpperTriangleMainDiagonal(int arr[][MAX], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= i; j--) {
			if ((arr[i][j] >= 10 && arr[i][j] < 100) || (arr[i][j] > -100 && arr[i][j] <= -10)) {
				count++;
			}
		}
	}
	return count;
}
//1.l
//Ham tim cac so nguyen to cua tam giac tren duong cheo phu
int countPrimeNumbersOnUpperTriangleAuxiliaryDiagonal(int arr[][MAX], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n - 1 - i; j++) {
			if (isPrimeNumber(arr[i][j])) {
				count++;
			}
		}
	}
	return count;
}
//1.m
//Ham check ma tran toan gia tri duong
bool isMatrixHavingAllPositiveValue(int arr[][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] <= 0) {
				return false;
			}
		}
	}
	return true;
}
//1.n
//Ham check so hoan thien
bool isPerfectNumber(int n) {
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}
	return sum == n;
}
//Ham check ma tran co ton tai so hoan thien
bool isTheMatrixHavingThePerfectNumber(int arr[][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (isPerfectNumber(arr[i][j])) {
				return true;
			}
		}
	}
	return false;
}
//_____________________________________________________________________________________________________________________________________
//1.o p q
//Ham swap
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
//Ham sap xep cac phan tu trong hang tang dan
void sortAscendingRow(int arr[][MAX], int n, int r) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[r][i] > arr[r][j]) {
				swap(arr[r][i], arr[r][j]);
			}
		}
	}
}
//Ham sap xep cac phan tu trong ma tran tang tu trai qua phai
void sortAscendingFromLeftToRight(int arr[][MAX], int n) {
	for (int i = 0; i < n; i++) {
		sortAscendingRow(arr, n, i);
	}
}
//Ham sap xep cac phan tu trong cot tang dan
void sortAscendingColumn(int arr[][MAX], int n, int c) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i][c] > arr[j][c]) {
				swap(arr[i][c], arr[j][c]);
			}
		}
	}
}
//Ham sap xep cac phan tu trong ma tran tang tu tren xuong duoi
void sortAscendingFromUpToDown(int arr[][MAX], int n) {
	for (int j = 0; j < n; j++) {
		sortAscendingColumn(arr, n, j);
	}
}
//q.
//Ham sap xep cac phan tu duong tren hang giam dan
void sortPositiveValuesDescendingOnRow(int arr[][MAX], int n, int r) {
	for (int i = 0; i < n - 1; i++) {
		if (arr[r][i] > 0) {
			for (int j = i + 1; j < n; j++) {
				if (arr[r][j] > 0) {
					if (arr[r][i] < arr[r][j]) {
						swap(arr[r][i], arr[r][j]);
					}
				}
			}
		}
	}
}
//Ham sap xep cac phan tu am tren hang tang dan
void sortNegativeValuesAscendingOnRow(int arr[][MAX], int n, int r) {
	for (int i = 0; i < n - 1; i++) {
		if (arr[r][i] < 0) {
			for (int j = i + 1; j < n; j++) {
				if (arr[r][j] < 0) {
					if (arr[r][i] > arr[r][j]) {
						swap(arr[r][i], arr[r][j]);
					}
				}
			}
		}
	}
}
//Ham sap xep ma tran voi cac phan tu am tang dan va cac phan tu duong giam dan tu trai qua phai
void sortMatrixHavingNegativeValuesAscendingAndPositiveValuesDescendingFromLeftToRight(int arr[][MAX], int n) {
	for (int i = 0; i < n; i++) {
		sortNegativeValuesAscendingOnRow(arr, n, i);
		sortPositiveValuesDescendingOnRow(arr, n, i);
	}
}
//Ham sap xep cac phan tu duong trong cot giam dan
void sortPositiveValuesDescendingOnColumn(int arr[][MAX], int n, int c) {
	for (int i = 0; i < n - 1; i++) {
		if (arr[i][c] > 0) {
			for (int j = i + 1; j < n; j++) {
				if (arr[j][c] > 0) {
					if (arr[i][c] < arr[j][c]) {
						swap(arr[i][c], arr[j][c]);
					}
				}
			}
		}
	}
}
//Ham sap xep cac phan tu am trong cot tang dan
void sortNegativeValuesAscendingOnColumn(int arr[][MAX], int n, int c) {
	for (int i = 0; i < n - 1; i++) {
		if (arr[i][c] < 0) {
			for (int j = i + 1; j < n; j++) {
				if (arr[j][c] < 0) {
					if (arr[i][c] > arr[j][c]) {
						swap(arr[i][c], arr[j][c]);
					}
				}
			}
		}
	}
}
//Ham sap xep ma tran voi cac phan tu am tang dan va cac phan tu duong giam dan tu tren xuong duoi
void sortMatrixHavingNegativeValuesAscendingAndPositiveValuesDescendingFromUpToDown(int arr[][MAX], int n) {
	for (int j = 0; j < n; j++) {
		sortNegativeValuesAscendingOnColumn(arr, n, j);
		sortPositiveValuesDescendingOnColumn(arr, n, j);
	}
}
//_____________________________________________________________________________________________________________________________________