#include <iostream>
#include "Student.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>

using namespace std;

Student st;

int choice;

void showMenu();
void insertMenu();
void modifyMenu();
void deleteMenu();

void choices(){

        do {
            cout << "*******************************************************************" << endl;
            cout << " 1  - Xem du lieu." << endl;
            cout << " 2  - Them du lieu" << endl;
            cout << " 3  - Cap nhat du lieu" << endl;
            cout << " 4  - Xoa du lieu" << endl;
            cout << " 5  - Tinh diem tung binh cua sinh vien" << endl;
            cout << " 6  - Hien thi sinh vien chua dat" << endl;
            cout << " 7  - Hien thi sanh sach hoc phan chua dat" << endl;
            cout << " 8  - Hien thi diem trung binh tich luy" << endl;
            cout << " 0  - Thoat " << endl;
            cout << " Enter your choice: ";
            cin >> choice;
            cout << "*******************************************************************" << endl;

            switch (choice)
            {
                case 1:
                    cout << " 1  - Xem Du Lieu" << endl;
                    showMenu();
                    break;
                case 2:
                    cout << " 2  - Them Du Lieu" << endl;
                    insertMenu();
                    break;
                case 3:
                    cout << " 3  - Cap nhat du lieu" << endl;
                    modifyMenu();
                    break;
                case 4:
                    cout << " 4  - Xoa du lieu" << endl;
                    deleteMenu();
                    break;
                case 5:
                    cout << " 5  - Tinh diem tung binh cua sinh vien" << endl;

                    break;
                case 6:
                    cout << " 6  - Hien thi sinh vien chua dat" << endl;

                    break;
                case 7:
                    cout << " 7  - Hien thi sanh sach hoc phan chua dat" << endl;

                    break;
                case 8:
                    cout << " 8  - Hien thi diem trung binh tich luy" << endl;
                    break;
                case 0:
                    cout << "End of Program.\n";
                    exit(0);
                    break;
                default:
                    cout << "Not a Valid Choice. \n";
                    cout << "Choose again.\n";
                    cin >> choice;
                    break;
            }
            //system("cls");
        } while (choice != 0);
};

void showMenu(){
    while (choice != 0) {
        cout << "*******************************************************************" << endl;
        cout << " 1  - Xem thong tin Sinh Vien." << endl;
        cout << " 2  - Xem thong tin Hoc Phan." << endl;
        cout << " 3  - Xem thong tin Diem Thi." << endl;
        cout << " 4  - Tro Ve." << endl;
        cout << " 0  - Ket thuc chuong trinh. " << endl;
        cout << " Nhap lua chon: ";
        cin >> choice;
        cout << "*******************************************************************" << endl;
        switch (choice)
        {
            case 1:
                cout << " 1  - Xem thong tin Sinh Vien" << endl;
                st.displayAll();
                break;
            case 2:
                cout << " 2  - Xem thong tin Hoc Phan" << endl;

                break;
            case 3:
                cout << " 3  - Xem thong tin Diem Thi" << endl;

                break;
            case 4:
                choices();
            case 0:
                cout << "End of Program.\n";
                exit(0);
            default:
                cout << "Not a Valid Choice. \n";
                cout << "Choose again.\n";
                cin >> choice;
                break;
        }
        system("cls");
    }
}

void insertMenu() {

    while (choice != 0) {
        cout << "*******************************************************************" << endl;
        cout << " 1  - Nhap thong tin Sinh Vien." << endl;
        cout << " 2  - Nhap thong tin Hoc Phan." << endl;
        cout << " 3  - Nhap thong tin Diem Thi." << endl;
        cout << " 4  - Tro Ve." << endl;
        cout << " 0  - Ket thuc chuong trinh. " << endl;
        cout << " Nhap lua chon: ";
        cin >> choice;
        cout << "*******************************************************************" << endl;
        switch (choice)
        {
            case 1:
                cout << " 1  - Nhap thong tin Sinh Vien" << endl;
                st.writeData();
                break;
            case 2:
                cout << " 2  - Nhap thong tin Hoc Phan" << endl;

                break;
            case 3:
                cout << " 3  - Nhap thong tin Diem Thi" << endl;

                break;
            case 4:
                choices();
            case 0:
                cout << "End of Program.\n";
                exit(0);
            default:
                cout << "Not a Valid Choice. \n";
                cout << "Choose again.\n";
                cin >> choice;
                break;
        }
        system("cls");
    }
}

void modifyMenu(){

    while (choice != 0) {
        cout << "*******************************************************************" << endl;
        cout << " 1  - Sua Sinh Vien" << endl;
        cout << " 2  - Sua Hoc Phan" << endl;
        cout << " 3  - Sua Diem Thi" << endl;
        cout << " 4  - Tro Ve " << endl;
        cout << " 0  - Ket thuc chuong trinh " << endl;
        cout << "*******************************************************************" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
                st.modifyData();
                break;
            case 2:
                //SuaHocPhan();
                break;
            case 3:
                //SuaDiemThi();
                break;
            case 4:
                choices();
            case 0:
                cout << "End of Program.\n";
                exit(0);
            default:
                cout << "Not a Valid Choice. \n";
                cout << "Choose again.\n";
                cin >> choice;
                break;
        }
        system("cls");
    }
}

void deleteMenu(){

    while (choice != 0) {
        cout << "*******************************************************************" << endl;
        cout << " 1  - Xoa Sinh Vien" << endl;
        cout << " 2  - Xoa Hoc Phan" << endl;
        cout << " 3  - Xoa Diem Thi" << endl;
        cout << " 4  - Tro ve" << endl;
        cout << " 0  - Thoat chuong trinh " << endl;
        cout << "*******************************************************************" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
                st.deleteData();
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:
                choices();
                break;
            case 0:
                cout << "End of Program.\n";
                exit(0);
                break;
            default:
                cout << "Not a Valid Choice. \n";
                cout << "Choose again.\n";
                cin >> choice;
                break;
        }
        system("pause");
        system("cls");
    }
}



int main() {
    choices();


    return 0;
}
