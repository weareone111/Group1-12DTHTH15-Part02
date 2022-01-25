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
//
void Menu();
void displayABook(Book book);
void displayAllBooksInList(Book book[], int n);
void enterBooksListFromFileHavingN(Book book[], int& n, string directory);
void enterBooksListFromFileWithoutN(Book book[], int& n, string directory);
void enterABook(Book& book);
void addABookAtK(Book book[], int& n, int k, Book temp);
void deleteABoookAtK(Book book[], int& n, int k);
void deleteABookByID(Book book[], int& n, int id);
void deleteBooksHavingRatingStarLessThanRatingStarX(Book book[], int& n, float ratingstarsX);
void deledetBooksHavingAuthorX(Book book[], int& n, string authorX);
void updateABookByID(Book book[], int& n, int id);
void searchforTheInfomationOfABookByBookName(Book book[], int n, string Bookname);
void displayBooksHavingPriceGreaterThanOrEqualPriceX(Book book[], int n, float priceX);
void displayBooksHavingAuthorX(Book book[], int n, string authorX);
void displayBooksAccordingToPublishingYearAndPriceGreaterThanPriceX(Book book[], int n, int year, float priceX);
float totalThePricesOfBooksInList(Book book[], int n);
int countTheNumberOfTheBooksHavingRatingStarsGreaterThanRatingStarsX(Book book[], int n, float ratingstarsX);
int countTheNumberOfTheBooksOfAuthorX(Book book[], int n, string authorX);
void sortTheListOfBooksByBookName(Book book[], int n);
void sortTheListOfBooksByTheNewPublishingYear(Book book[], int n);
//string getName(string FullName);
void sortAllBooksAscendingByAuthorName(Book book[], int n);
//

//Main function
int main() {
	Book A[MAX];
	Book temp;
	int n = 0;
    int option = 0;
    string directory = "dsSQ1.txt";
    int k;
	int id;
	int year;
	float ratingstarsX;
	float priceX;
	string authorX;
	string bookname;
    do {
        system("cls");
        Menu();
        cout << "Hay chon phuong thuc : "; cin >> option;
        system("cls");
        if (option > 3 && option <= 19) {
			displayAllBooksInList(A, n);
			cout << setfill('-');
			cout << setw(100) << "-" << endl;

			// reset fill to ' '
			cout << setfill(' ');
        }
        switch (option) {
        case 0:cout << "Goodbye  !:<" << endl;
            break;
        case 1:
			//cin.ignore();
			//cout << "Nhap duong dan : "; getline(cin, directory);

			directory = "dsQS1.txt";
			enterBooksListFromFileHavingN(A, n, directory);
			cout << "Lay thong tin thanh cong !" << endl;
            break;
        case 2:
            //cin.ignore();
            //cout << "Nhap duong dan : "; getline(cin, directory);
			n = 0;
			directory = "dsQS2.txt";
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
			cout << "Them thanh cong !" << endl;
            break;
        case 5:
			k = n;
			cout << "Nhap thong tin sach !" << endl;
			enterABook(temp);
			addABookAtK(A, n, k, temp);
			cout << "Them thanh cong !" << endl;
            break;
        case 6:
			cout << "Nhap ID : "; cin >> id;
			deleteABookByID(A, n, id);
            break;
        case 7:
			cout << "Xoa cac quyen sach co so sao danh gia nho hon so sao danh gia X !" << endl;
			cout << "Nhap so sao X : "; cin >> ratingstarsX;
			deleteBooksHavingRatingStarLessThanRatingStarX(A, n, ratingstarsX);
            break;
        case 8:
			cin.ignore();
			cout << "Xoa cac quyen sach cua tac gia X !" << endl;
			cout << "Nhap ten tac gia X : "; getline(cin, authorX);
			deledetBooksHavingAuthorX(A, n, authorX);
            break;
        case 9:
			cout << "Cap nhat thong tin cua mot quyen sach co ID X !" << endl;
			cout << "Nhap ID X : "; cin >> id;
			updateABookByID(A, n, id);
            break;
        case 10:
			cin.ignore();
			cout << "Tra cuu thong tin cua mot quyen sach dua tren ten sach !" << endl;
			cout << "Nhap ten sach : "; getline(cin, bookname);
			searchforTheInfomationOfABookByBookName(A, n, bookname);
            break;
        case 11:
			cout << "Liet ke tat ca quyen sach co gia lon hon hoac bang gia X !" << endl;
			cout << "Nhap gia X : "; cin >> priceX;
			displayBooksHavingPriceGreaterThanOrEqualPriceX(A, n, priceX);
            break;
        case 12:
			cin.ignore();
			cout << "Liet ke cac quyen sach cua Tac gia X !" << endl;
			cout << "Nhap ten tac gia X : "; getline(cin, authorX);
			displayBooksHavingAuthorX(A, n, authorX);
            break;
        case 13:
			cout << "Liet ke cac quyen sach co nam xuat ban tu Nam XB va so sao lon hon so sao X !" << endl;
			cout << "Nhap nam XB : "; cin >> year;
			cout << "Nhap so sao X : "; cin >> ratingstarsX;
			displayBooksAccordingToPublishingYearAndPriceGreaterThanPriceX(A, n, year, ratingstarsX);
            break;
        case 14:
			cout << "Tong tien cac quyen sach trong danh sach la : "<< totalThePricesOfBooksInList(A, n) <<endl;
            break;
        case 15:
			cout << "Nhap so sao X : "; cin >> ratingstarsX;
			cout << "So quyen sach co sao lon hon so sao X la : ";
			cout << countTheNumberOfTheBooksHavingRatingStarsGreaterThanRatingStarsX(A, n, ratingstarsX) << endl;
            break;
        case 16:
			cin.ignore();
			cout << "Nhap ten tac gia X : "; getline(cin, authorX);
			cout << "So quyen sach cua Tac gia X la : "<< countTheNumberOfTheBooksOfAuthorX(A, n, authorX) << endl;
            break;
        case 17:
			sortTheListOfBooksByBookName(A, n);
			cout << "Sap xep thanh cong !" << endl;
            break;
        case 18:
			sortTheListOfBooksByTheNewPublishingYear(A, n);
			cout << "Sap xep thanh cong !" << endl;
            break;
        case 19:
			sortAllBooksAscendingByAuthorName(A, n);
			cout << "Sap xep thanh cong !" << endl;
            break;
        default:cout << "Phuong thuc khong hop le !! :<" << endl;
        }
		cout << setfill('-');
		cout << setw(100) << "-" << endl;

		// reset fill to ' '
		cout << setfill(' ');
        system("pause>0");
    } while (option != 0);
    return 0;
}

//Writing Function Part
void Menu() {
	cout << "1.\tLay thong tin tu file dsQS1" << endl;
	cout << "2.\tLay thong tin tu file dsQS2" << endl;
	cout << "3.\tXuat cac quyen sach trong danh sach" << endl;
	cout << "4.\tThem mot quyen sach moi vao dau danh sach " << endl;
	cout << "5.\tThem mot quyen sach moi vao cuoi danh sach " << endl;
	cout << "6.\tXoa mot quyen sach co Ma sach X " << endl;
	cout << "7.\tXoa cac quyen sach co so sao nho hon So sao X" << endl;
	cout << "8.\tXoa cac quyen sach cua tac gia X" << endl;
	cout << "9.\tCap nhat thong tin mot quyen sach " << endl;
	cout << "10.\tTra cuu thong tin cua mot quyen sach theo ten sach" << endl;
	cout << "11.\tLiet ke tat ca quyen sach co gia lon hon hoac bang Gia X" << endl;
	cout << "12.\tLiet ke cac quyen sach cua Tac gia X" << endl;
	cout << "13.\tLiet ke cac quyen sach co nam xuat ban tu Nam XB va so sao lon hon Sao X" << endl;
	cout << "14.\tTong tien cac quyen sach trong danh sach" << endl;
	cout << "15.\tDem so sach co sao lon hon Sao X" << endl;
	cout << "16.\tDem so sach cua Tac gia X" << endl;
	cout << "17.\tSap xep cac quyen sach theo ten gia ban" << endl;
	cout << "18.\tSap xep cac quyen sach theo nam xuat ban moi nhat neu cung nam thi sap xep theo so sao Z -> A " << endl;
	cout << "19.\tSap xep cac quyen sach theo ten tac gia(Full name) neu cung tac gia thi giam dan theo nam xuat ban" << endl;
}
//a.
//Ham hien thi 1 cuon sach
void displayABook(Book book) {
	cout << setw(10) << left << book.ID;
	cout << setw(20) << left << book.Name;
	cout << setw(15) << right << book.PublishingYear;
	cout << setw(15) << right << book.Price;
	cout << setw(20) << right << book.Author;
	cout << setw(15) << right << book.RatingStars << endl;
}
//Ham hien thi danh sach cac cuon sach
void displayAllBooksInList(Book book[], int n) {
	cout << setw(5) << left << "STT";
	cout << setw(10) << left << "Ma Sach";
	cout << setw(20) << left << "Ten Sach";
	cout << setw(15) << right << "Nam Xuat Ban";
	cout << setw(15) << right << "Gia Ban";
	cout << setw(20) << right << "Tac Gia";
	cout << setw(15) << right << "So Sao" << endl;
	cout << setfill('-');
	cout << setw(100) << "-" << endl;

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
			file >> book[n].PublishingYear;
			file.ignore();
			file >> book[n].Price;
			file.ignore();
			getline(file, book[n].Author, '#');
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
//g.
//Ham xoa quyen sach tai vi tri k
void deleteABoookAtK(Book book[], int& n, int k) {
	if (k >= 0 && k < n) {
		for (int i = k; i < n - 1; i++) {
			book[i] = book[i + 1];
		}
		n--;
	}
}
//Ham xoa quyen sach = id
void deleteABookByID(Book book[], int& n, int id) {
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (book[i].ID == id) {
			flag = true;
			deleteABoookAtK(book, n, i);
			break;
		}
	}
	if (!flag) {
		cout << "Khong tim thay ID " << id << " trong danh sach" << endl;
	}
	else {
		cout << "Xoa thanh cong" << endl;
	}
}
//h. 
//Hàm xóa các quyển sách có số sao nhỏ hơn sosaoX
void deleteBooksHavingRatingStarLessThanRatingStarX(Book book[], int& n, float ratingstarsX) {
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (book[i].RatingStars < ratingstarsX) {
			flag = true;
			deleteABoookAtK(book, n, i);
			i--;
		}
	}
	if (!flag) {
		cout << "Khong co quyen sach nao trong danh sach co sao < "<< ratingstarsX << endl;
	}
	else {
		cout << "Xoa thanh cong" << endl;
	}
}
//i. 
//Hàm xóa các quyển sách của tác giả X
void deledetBooksHavingAuthorX(Book book[], int& n, string authorX) {
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (book[i].Author == authorX) {
			flag = true;
			deleteABoookAtK(book, n, i);
			i--;
		}
	}
	if (!flag) {
		cout << "Khong co quyen sach nao trong danh sach co tac gia la " << authorX << endl;
	}
	else {
		cout << "Xoa thanh cong" << endl;
	}
}
//j. 
//Ham cập nhật thông tin của một quyển sách
void updateABookByID(Book book[], int& n, int id) {
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (book[i].ID == id) {
			flag = true;
			cin.ignore();
			cout << "Ten sach : "; getline(cin, book[i].Name);
			cout << "Nam san xuat : "; cin >> book[i].PublishingYear;
			cout << "Don gia : "; cin >> book[i].Price;
			cin.ignore();
			cout << "Tac gia : "; getline(cin, book[i].Author);
			cout << "So sao danh gia : "; cin >> book[i].RatingStars;
			break;
		}
	}
	if (!flag) {
		cout << "Khong tim thay ID " << id << " trong danh sach" << endl;
	}
	else {
		cout << "Cap nhat thanh cong" << endl;
	}
}
//k. 
//Hàm tra cứu thông tin chi tiết của một Quyển Sách dựa trên tên sách.
void searchforTheInfomationOfABookByBookName(Book book[], int n, string Bookname) {
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (book[i].Name == Bookname) {
			if (flag == false) {
				flag = true;
				displayAllBooksInList(book, 0);
			}
			cout << setw(5) << left << i + 1;
			displayABook(book[i]);
		}
	}
	if (!flag) {
		cout << "Khong co quyen sach nao trong danh sach co ten la " << Bookname << endl;
	}
}
//l. 
//Hàm in thông tin tất cả các quyển sách có giá lớn hơn hoặc bằng giaX
void displayBooksHavingPriceGreaterThanOrEqualPriceX(Book book[], int n, float priceX){
	bool flag = false;
	for (int i = 0; i < n; i++){
		if (book[i].Price >= priceX){
			if (flag == false) {
				flag = true;
				displayAllBooksInList(book, 0);
			}
			cout << setw(5) << left << i + 1;
			displayABook(book[i]);
		}
	}
	if (!flag) {
		cout << "Khong co quyen sach nao trong danh sach co gia >= " << priceX << endl;
	}
}
//m. 
//Hàm in thông tin các quyển sách có tên tác giả X
void displayBooksHavingAuthorX(Book book[], int n, string authorX){
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (book[i].Author == authorX) {
			if (flag == false) {
				flag = true;
				displayAllBooksInList(book, 0);
			}
			cout << setw(5) << left << i + 1;
			displayABook(book[i]);
		}
	}
	if (!flag) {
		cout << "Khong co quyen sach nao trong danh sach cua tac gia " << authorX << endl;
	}
}
//n. 
//Hàm in thông tin các quyển sách có năm xuất bản từ namXB, và có số sao lớn hơn saoX
void displayBooksAccordingToPublishingYearAndPriceGreaterThanPriceX(Book book[], int n, int year, float ratingstarsX){
	bool flag = false;
	for (int i = 0; i < n; i++){
		if (book[i].PublishingYear >= year && book[i].RatingStars> ratingstarsX){
			if (flag == false) {
				flag = true;
				displayAllBooksInList(book, 0);
			}
			cout << setw(5) << left << i + 1;
			displayABook(book[i]);
		}
	}
	if (!flag) {
		cout << "Khong co quyen sach nao trong danh sach phu hop yeu cau "<< endl;
	}
}
//o. 
//Hàm tính tổng số tiền của các quyển sách có trong danh sách.
float totalThePricesOfBooksInList(Book book[], int n){
	float sum = 0;
	for (int i = 0; i < n; i++){
		sum += book[i].Price;

	}
	return sum;
}
//p. 
//Hàm đếm số sách có số sao lớn hơn saoX
int countTheNumberOfTheBooksHavingRatingStarsGreaterThanRatingStarsX(Book book[], int n, float ratingstarsX){
	int dem = 0;
	for (int i = 0; i < n; i++){
		if (book[i].RatingStars > ratingstarsX) {
			dem++;
		}
	}
	return dem;
}
//q. 
//Hàm đếm số sách của tác giả tacgiaX
int countTheNumberOfTheBooksOfAuthorX(Book book[], int n, string authorX){
	int dem = 0;
	for (int i = 0; i < n; i++){
		if (book[i].Author == authorX) {
			dem++;
		}
	}
	return dem;
}
//r. 
//Ham chuyen doi
void swap(Book& a, Book& b){
	Book t = a;
	a = b;
	b = t;
}
//Hàm sắp xếp các quyển sách theo tên giá bán
void sortTheListOfBooksByBookName(Book book[], int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (book[i].Name > book[j].Name){
				swap(book[i], book[j]);
			}
		}
	}
}
//s.
//Hàm sắp xếp các quyển sách theo năm xuất bản mới nhất. Nếu cùng năm xuất bản thì sắp xếp theo
//số sao đánh giá từ cao xuống thấp.
void sortTheListOfBooksByTheNewPublishingYear(Book book[], int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (book[i].PublishingYear < book[j].PublishingYear){
				swap(book[i], book[j]);
			}
			else if (book[i].PublishingYear == book[j].PublishingYear){
				if (book[i].RatingStars < book[j].RatingStars) {
					swap(book[i], book[j]);
				}
			}
		}
	}
}
//t. Sắp xếp các quyển sách trong danh sách theo tên tác giả (tăng dần theo alphabet). Nếu cùng
//tác giả thì sắp xếp theo năm xuất bản giảm dần.
//Hàm lay ten 
//string getName(string FullName) {
//	string lastname = "";
//	int i = 0;
//	for (int j = FullName.rfind(' ') + 1; j <= FullName.length(); j++) {
//		lastname += FullName[j];
//	}
//	return lastname;
//}
//Ham sap xep cac quyen sach theo ten(Full name)
void sortAllBooksAscendingByAuthorName(Book book[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (book[i].Author > book[j].Author) {
				swap(book[i], book[j]);
			}
			else if(book[i].Author == book[j].Author){
				if (book[i].PublishingYear < book[j].PublishingYear) {
					swap(book[i], book[j]);
				}
			}
		}
	}
}