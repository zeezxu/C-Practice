//
// Created by Ziyan Xu on 10/24/24.
//

#include <iomanip>
#include<iostream>
using namespace std;
#define Max 1000

struct Person {
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Address;
};

struct AddressBooks {
    struct Person personArray[Max];

    int m_Size;
};

void addPerson(AddressBooks * abs) {
    if(abs->m_Size == Max) {
        cout << "AddressBook is full. Cannot add more."<< endl;
        return;
    }
    {
        string name;
        cout<< "Please enter contact name:"<< endl;
        cin>> name;
        abs->personArray[abs->m_Size].m_Name = name;

        cout<<"Please enter contact gender:"<< endl;
        cout<< "1--Male"<<endl;
        cout<< "2--Female"<<endl;
        int sex = 0;

        // while(true) {
        //     cin>>sex;
        //     if(sex == 1 || sex == 2) {
        //         abs->personArray[abs->m_Size].m_Sex = sex;
        //         break;
        //     }
        //     cout << "Invalid input. Please choose again."<<endl;
        // }
        while (true) {
            cin >> sex;
            if (cin.fail() || (sex != 1 && sex != 2)) {
                cin.clear(); // Clear the error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid input. Please choose again." << endl;
            } else {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
        }

        cout<<"Please enter contact age:"<<endl;
        int age = 0;

        while(true) {
            cin>>age;
            if(age >= 0 && age <= 135) {
                abs->personArray[abs->m_Size].m_Age = age;
                break;
            }
            cout << "Invalid input. Please enter again."<<endl;
        }
        cout<<"Please enter contact phone number:"<<endl;
        string phone;
        cin>>phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        cout<<"Please enter contact address:"<<endl;
        string address;
        cin>>address;
        abs->personArray[abs->m_Size].m_Address = address;

        abs->m_Size++;

        cout<<"Contact is added successfully."<<endl;
        cout << "Press any key to clear the screen..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any remaining input
        getchar(); // Wait for a key press

        system("clear");

    }
}

void showPerson(AddressBooks * abs) {
    if(abs->m_Size == 0) {
        cout<<"No record."<<endl;
    }
    {
        for(int i = 0; i < abs->m_Size; i++) {
            cout<<"Contact name: "<< abs->personArray[i].m_Name<<"\t";
            cout<<"Contact gender: "<< (abs->personArray[i].m_Sex == 1? "Male": "Female")<<"\t";
            cout<<"Contact age: "<< abs->personArray[i].m_Age<<"\t";
            cout<<"Contact phone number: "<< abs->personArray[i].m_Phone<<"\t";
            cout<<"Contact address: "<< abs->personArray[i].m_Address<<endl;
        }
    }

    cout << "Press any key to clear the screen..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any remaining input
    getchar(); // Wait for a key press

    system("clear");
}

int isExist(AddressBooks *abs, string name) {
    for(int i = 0; i < abs->m_Size; i++) {
        if(abs->personArray[i].m_Name == name) {
        return i;
        }
    }
    return -1;
}

void deletePerson(AddressBooks *abs) {
    cout << "Please enter the contact name you would like to delete:"<< endl;

    string name;
    cin >> name;

    int res = isExist(abs, name);

    if(res != -1) {
        for(int i = res; i < abs->m_Size; i++) {
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_Size--;
        cout << "Delete successfully."<<endl;

    }else{
        cout<<"No record."<<endl;
    }
    cout << "Press any key to clear the screen..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any remaining input
    getchar(); // Wait for a key press

    system("clear");
}

void findPerson(AddressBooks *abs) {
    cout<< "Please enter the contact name you would like to find:"<< endl;
    string name;
    cin>>name;

    int res = isExist(abs, name);

    if(res != -1) {
        cout<<"Contact name: "<< abs->personArray[res].m_Name<<"\t";
        cout<<"Contact gender: "<< (abs->personArray[res].m_Sex == 1? "Male": "Female")<<"\t";
        cout<<"Contact age: "<< abs->personArray[res].m_Age<<"\t";
        cout<<"Contact phone number: "<< abs->personArray[res].m_Phone<<"\t";
        cout<<"Contact address: "<< abs->personArray[res].m_Address<<endl;
    }
    else {
        cout<< "No record."<<endl;
    }
    cout << "Press any key to clear the screen..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any remaining input
    getchar(); // Wait for a key press

    system("clear");

}

void modifyperson(AddressBooks *abs) {
    cout<<"Please enter the contact name that you would like to modify:"<<endl;
    string name;
    cin>>name;

    int res = isExist(abs, name);

    if(res != -1) {
        string name;
        cout<< "Please enter contact name:"<< endl;
        cin >> name;
        abs->personArray[res].m_Name = name;

        cout<< "Please enter contact gender:"<< endl;
        cout<< "1--Male"<<endl;
        cout<< "2--Female"<<endl;
        int sex = 0;

        while (true) {
            cin >> sex;
            if (cin.fail() || (sex != 1 && sex != 2)) {
                cin.clear(); // Clear the error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid input. Please choose again." << endl;
            } else {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
        }

        cout<<"Please enter contact age:"<<endl;
        int age = 0;
        cin>>age;
        abs->personArray[res].m_Age=age;

        cout<<"Please enter contact phone number:"<<endl;
        string phone;
        cin>>phone;
        abs->personArray[res].m_Phone = phone;

        cout<<"Please enter contact address:"<<endl;
        string address;
        cin>>address;
        abs->personArray[res].m_Address = address;

        cout<<"Contact information edited successfully."<<endl;
    }
    else {
        cout<< "No record."<<endl;
    }

    cout << "Press any key to clear the screen..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any remaining input
    getchar(); // Wait for a key press

    system("clear");
}

void clearAllPerson(AddressBooks *abs) {
    abs->m_Size = 0;
    cout<<"Contact list has been cleaned." <<endl;
    cout << "Press any key to clear the screen..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any remaining input
    getchar(); // Wait for a key press

    system("clear");
}

void showMenu() {

    cout<< "************************************"<<endl;
    cout<< "****** 1. Add Contacts        ******"<<endl;
    cout<< "****** 2. Show Contacts       ******"<<endl;
    cout<< "****** 3. Delete Contacts     ******"<<endl;
    cout<< "****** 4. Search Contacts     ******"<<endl;
    cout<< "****** 5. Edit Contacts       ******"<<endl;
    cout<< "****** 6. Clear All Contacts  ******"<<endl;
    cout<< "****** 0. Exit Menu           ******"<<endl;
    cout<< "Please choose the number:"<<endl;

}

int main() {
    AddressBooks abs;

    abs.m_Size = 0;

    int select = 0;

    while(true) {
        showMenu();

        if (!(cin >> select)) {
            // Invalid input, clear the error and ignore the rest of the input
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid option. Please try again." << endl;
            continue; // Go back to the menu
        }

        switch (select){
            case 1:
                addPerson(&abs);
            break;
            case 2:
                showPerson(&abs);
            break;
            case 3:
                deletePerson(&abs);
            break;
            case 4:
                findPerson(&abs);
                break;
            case 5:
                modifyperson(&abs);
                break;
            case 6:
                clearAllPerson(&abs);
                break;
            case 0:
                cout << "Thank you for using Contact Management System."<< endl;
                cin.get();
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }
}

