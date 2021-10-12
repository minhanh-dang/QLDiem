#include "Student.h"
#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>
#include <regex>

int nsv = 0;

int Student:: getIDNum(){
    stringstream num(id_num);
    int x = 0;
    num >> x;
    return x;
}

bool checkValidIDNum(char id_num[]){
    const regex pattern ("^[0-9]{8}$");
    if (regex_match(id_num, pattern))
        return 1;

    return 0;
}

bool checkValidDate(char date_of_birth[]){
    //const regex pattern("^(?:(?:31(\/|-|\.)(?:0?[13578]|1[02]))\1|(?:(?:29|30)(\/|-|\.)(?:0?[13-9]|1[0-2])\2))(?:(?:1[6-9]|[2-9]\d)?\d{2})$|^(?:29(\/|-|\.)0?2\3(?:(?:(?:1[6-9]|[2-9]\d)?(?:0[48]|[2468][048]|[13579][26])|(?:(?:16|[2468][048]|[3579][26])00))))$|^(?:0?[1-9]|1\d|2[0-8])(\/|-|\.)(?:(?:0?[1-9])|(?:1[0-2]))\4(?:(?:1[6-9]|[2-9]\d)?\d{2})$");
    //if (regex_match(date_of_birth, pattern ))
        return 1;
    return 0;
}

void Student::save(ofstream &of) {
    of.write(id_num, sizeof(id_num));
    of.write(name, sizeof(name));
    of.write(gender, sizeof(gender) );
    of.write(date_of_birth, sizeof(date_of_birth));
    //of.write(&gpa, sizeof(gpa));
}

void Student::load(ifstream &inf) {
    inf.read(id_num, sizeof(id_num));
    cout << id_num << endl;
    inf.read(name, sizeof(name));
    cout << name << endl;
    inf.read(gender, sizeof(gender));
    cout << gender << endl;
    inf.read(date_of_birth, sizeof(date_of_birth));
    cout << date_of_birth << endl;
}

void Student::getData(){

    Student st;

    cout << "Nhap Ma sinh vien. Vi du: 20202020." << endl;
    cin >> id_num;
    cin.ignore();
    int isvalid = checkValidIDNum(id_num);
    while(isvalid != 1){
        cout << "ID not Valid. Try again: " << endl;
        cin >> id_num;
        cin.ignore();
    }

    stringstream num(id_num);
    int x = 0;
    num >> x;

    ifstream inFile;
    inFile.open("SV.BIN",ios::binary | ios::in);
    if(!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }

    st.load(inFile);

        if(st.getIDNum() == x)
        {
            cout << "Record already exist.";
            return;
        }

    inFile.close();

    cout << "Name:" << endl;
    cin.getline(name,30);
    cout << "Gender:" << endl;
    cin.ignore();
    cin.getline(gender,10);
    cout << "Date of Birth:" << endl;
    while (cin >> date_of_birth)
    {
        isvalid = checkValidDate(date_of_birth);
        if(isvalid){
            break;
        }
        else{
            cout << "Input is not valid. Try again: " << endl;
        }
    }
    gpa = 0;
}

void Student:: writeData(){
    // can't initialize at the top or else you will get error "Multiple definition"
    Student st;
    getData();
    ofstream outFile;
    outFile.open("SV.BIN",ios::binary|ios::out);
    outFile.seekp(0, ios::end);
    save(outFile);
    outFile.close();
    cout<<"\n\nStudent record Has Been Created.\n ";
    nsv++;
    outFile.close();
}


void Student::displaySP()
{
    Student st;
    int n;

    cout << "Nhap MSSV: " << endl;
    cin >> n;

    ifstream inFile;
    inFile.open("SV.BIN",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag = false;

    while(inFile.read((char *) &st, sizeof(Student)))
    {
        if(st.getIDNum() == n)
        {
            showData();
            flag = true;
        }
    }
    inFile.close();
    if(flag == false)
        cout<<"\n\nRecord not exist";
    cin.ignore();
    cin.get();
}

void Student::showData(){
    cout << "\nID Number: " << id_num;
    cout << "\nName: " << name;
    cout << "\nGender: " << gender;
    cout << "\nDate of birth:  " << date_of_birth;

}

void Student:: displayAll()
{
    Student st;
    ifstream inFile;
    inFile.open("SV.BIN",ios::binary|ios::in);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    load(inFile);
    /*while(inFile.read((char *) (&st), sizeof(Student)))
    {
        st.showData();
        cout<<"\n\n====================================\n";
    }*/
    inFile.close();
    cin.ignore();
    cin.get();
}

void Student:: modifyData(){
    Student st;
    int n;

    cout << "Nhap MSSV: " << endl;
    cin >> n;

    bool found = false;
    fstream File;
    File.open("SV.BIN",ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    while(!File.eof() && found==false)
    {

        File.read(reinterpret_cast<char *> (&st), sizeof(Student));
        if(st.getIDNum() == n)
        {
            showData();
            cout << "\n\nPlease Enter The New Details of student:" << endl;
            getData();
            int pos = (-1) * static_cast<int>(sizeof(st));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&st), sizeof(Student));
            cout<<"\n\n\t Record Updated";
            found = true;
        }
    }
    File.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
    cin.ignore();
    cin.get();
}

void Student::deleteData()
{
    Student st;
    int n;

    cout << "Nhap MSSV: " << endl;
    cin >> n;

    bool found = false;
    ifstream inFile;
    inFile.open("SV.BIN",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TEMP.BIN",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&st), sizeof(Student)))
    {
        if(getIDNum()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&st), sizeof(Student));
        }
        else{
            found = true;
        }
    }
    outFile.close();
    inFile.close();
    remove("SV.BIN");
    rename("TEMP.BIN","SV.BIN");
    if(!found)
        cout << "Record not Exist.";
    else
        cout<<"\n\n\tRecord Deleted ..";
    cin.ignore();
    cin.get();
}