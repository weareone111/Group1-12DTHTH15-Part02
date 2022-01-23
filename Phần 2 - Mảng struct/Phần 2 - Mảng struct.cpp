/*
 - BT Nhóm : Phần - 02
 - Project 2 : Mảng struct
 - Group : 1
	+ 2001216199 - Nguyễn Minh Thư (Nhóm trưởng)
	+ 2001215790 - Nguyễn Huy Hoàng
	+ 2001215664 - Nguyễn Công Dũng
	+ 2001216306 - Lê Thị Khánh Vân
 - Last modify : 23:00 - 22/01/2022
*/
//Declare Library
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

//
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::ios;
using std::setw;
using std::setfill;
using std::left;
using std::right;
//

//Declare Constant
#define MAX 21
//Declare Struct
struct Book{
	int ID;
	string Name;
	int PublishingYear;
	float Price;
	string Author;
	float RatingStars;
};



//Declare Function Prototype
void displayABook(Book book);
void displayAllBooksInList(Book book[], int n);
void enterBooksListFromFileHavingN(Book book[], int& n, string directory);
void enterBooksListFromFileWithoutN(Book book[], int& n, string directory);
void enterABook(Book& book);
void addABookAtK(Book book[], int& n, int k, Book temp);

//Main function
int main() {
	Book A[MAX];
	Book temp;
	int n;
    int option = 0;
    string directory = "dsSQ1.txt";
    int k;
    do {
        system("cls");
        Menu();//Them ham Menu
        cout << "Hay chon phuong thuc : "; cin >> option;
        system("cls");
        if (option > 3 && option <= 19 && option != 13 && n != 0) {
			displayAllBooksInList(A, n);
			cout << setfill('-');
			cout << setw(110) << "-" << endl;

			// reset fill to ' '
			cout << setfill(' ');
        }
        switch (option) {
        case 0:cout << "Goodbye  !:<" << endl;
            break;
        case 1:
			//cin.ignore();
			//cout << "Nhap duong dan : "; getline(cin, directory);

			directory = "dsSQ1.txt";
			cout << "Lay thong tin thanh cong !" << endl;
			enterBooksListFromFileHavingN(A, n, directory);
            break;
        case 2:
            //cin.ignore();
            //cout << "Nhap duong dan : "; getline(cin, directory);

			directory = "dsSQ2.txt";
			enterBooksListFromFileWithoutN(A, n, directory);
            cout << "Lay thong tin thanh cong !" << endl;
            break;
        case 3:
			displayAllBooksInList(A, n);
            break;
        case 4:
			k = 0;
			cout << "Nhap thong tin sach !" << endl;
			enterABook(temp);
			addABookAtK(A, n, k, temp);
            break;
        case 5:
			k = n;
			cout << "Nhap thong tin sach !" << endl;
			enterABook(temp);
			addABookAtK(A, n, k, temp);
            break;
        case 6:
            
            break;
        case 7:
            
            break;
        case 8:
            
            break;
        case 9:
            
            break;
        case 10:
            
            break;
        case 11:
            
            break;
        case 12:
            
            break;
        case 13:
            
            break;
        case 14:
            
            break;
        case 15:
            
            break;
        case 16:
            
            break;
        case 17:
            
            break;
        case 18:
            
            break;
        case 19:
            
            break;
        default:cout << "Phuong thuc khong hop le !! :<" << endl;
        }
		cout << setfill('-');
		cout << setw(110) << "-" << endl;

		// reset fill to ' '
		cout << setfill(' ');
        system("pause>0");
    } while (option != 0);
    return 0;
}

//Writing Function Part
//a.
//Ham hien thi 1 cuon sach
void displayABook(Book book) {
	cout << setw(10) << left << book.ID;
	cout << setw(30) << left << book.Name;
	cout << setw(10) << left << book.PublishingYear;
	cout << setw(15) << left << book.Price;
	cout << setw(30) << left << book.Author;
	cout << setw(15) << right << book.RatingStars << endl;
}
//Ham hien thi danh sach cac cuon sach
void displayAllBooksInList(Book book[], int n) {
	cout << setw(5) << left << "STT";
	cout << setw(10) << left << "Ma Sach";
	cout << setw(30) << left << "Ten Sach";
	cout << setw(10) << left << "Nam Xuat Ban";
	cout << setw(15) << left << "Gia Ban";
	cout << setw(30) << left << "Tac Gia";
	cout << setw(10) << right << "So Sao Danh Gia" << endl;
	cout << setfill('-');
	cout << setw(110) << "-" << endl;

	// reset fill to ' '
	cout << setfill(' ');
	for (int i = 0; i < n; i++) {
		cout << setw(5) << left << i + 1;
		displayABook(book[i]);
	}
}
//c.
//Ham lay thong tin cac cuon sach tu file co cho truoc n
void enterBooksListFromFileHavingN(Book book[], int& n, string directory) {
	fstream file;
	file.open(directory, ios::in);//Read mode
	if (file.is_open()) {
		file >> n;
		file.ignore();
		for (int i = 0; i < n; i++) {
			file.ignore();
			file >> book[i].ID;
			file.ignore();
			getline(file, book[i].Name);
			file >> book[i].PublishingYear;
			file >> book[i].Price;
			file.ignore();
			getline(file, book[i].Author);
			file >> book[i].RatingStars;
			file.ignore();
		}
		file.close();
	}
	else {
		cout << "Khong tim thay file !" << endl;
	}
}
//d.
//Ham lay thong tin cac cuon sach tu file khong cho truoc n
//cac thong tin sach cach nhau boi dau #
//va moi cuon sach la moi dong
void enterBooksListFromFileWithoutN(Book book[], int& n, string directory) {
	fstream file;
	file.open(directory, ios::in);//Read mode
	int id;
	if (file.is_open()) {
		while (file >> id) {
			book[n].ID = id;
			file.ignore();
			getline(file, book[n].Name, '#');
			file.ignore();
			file >> book[n].PublishingYear;
			file.ignore();
			file >> book[n].Price;
			file.ignore();
			getline(file, book[n].Author, '#');
			file.ignore();
			file >> book[n].RatingStars;
			n++;
		}
		file.close();
	}
	else {
		cout << "Khong tim thay file !" << endl;
	}
}
//e - f
//Ham nhap 1 cuon sach 
void enterABook(Book& book) {
	cout << setw(20) << left << "Ma sach: ";
	cin >> book.ID;
	cin.ignore();
	cout << setw(20) << left << "Ten sach : "; getline(cin, book.Name);
	cout << setw(20) << left << "Nam san xuat : "; cin >> book.PublishingYear;
	cout << setw(20) << left << "Don gia : "; cin >> book.Price;
	cin.ignore();
	cout << setw(20) << left << "Tac gia : "; getline(cin, book.Author);
	cout << setw(20) << left << "So sao danh gia : "; cin >> book.RatingStars;
}
//Ham them 1 cuon sach tai vi tri k
void addABookAtK(Book book[], int& n, int k, Book temp) {
	for (int i = n; i > k; i--) {
		book[i] = book[i - 1];
	}
	book[k] = temp;
	n++;
}
