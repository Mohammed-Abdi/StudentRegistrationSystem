#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct student {
    string fullName, department, id;
    int age;
    struct student *next;
    struct student *pre;
};

struct student *start = NULL;


//Add student info at the start of the Linked list
void insertStudentInfoInFront(){
    string fName, mName, lName, departmentValue, idValue;
    int ageValue;

    cout << "Enter First Name: ";
    cin >> fName;
    cout << "Enter Middle Name: ";
    cin >> mName;
    cout << "Enter Last Name: ";
    cin >> lName;
    cout << "Enter Age: ";
    cin >> ageValue;
    cout << "Enter Student ID: ";
    cin >> idValue;
    cout << "Enter Department: ";
    cin.ignore();
    getline(cin, departmentValue);

    struct student *temp;
    temp = new student;
    temp -> fullName = fName + " " + mName + " " + lName;
    temp -> id = idValue;
    temp -> age = ageValue;
    temp -> department = departmentValue;

    if(start == NULL){
        start = temp;
        start -> next = NULL;
        start -> pre = NULL;
    } else {
        temp -> next = start;
        temp -> pre = NULL;
        start -> pre = temp;
        start = temp;
    }
    cout << "\nStudent Created Successfully\n";
}


//Adds more student info in the front
void addMoreInFront(){
    char response;
    do{
    cout << "Do you want to insert more? [y/n]: ";
    cin >> response;
    switch (response)
    {
    case 'y':
    case 'Y': insertStudentInfoInFront();
              break;
    case 'n':
    case 'N': cout << "Redirecting to homepage...\n";
              break;
    default: cout << "404: Wrong Input!\n";
    }
    } while(response != 'n' && response != 'N');
}


//Add student info at the end of the linked list
void insertStudentInfoInBack(){
    string fName, mName, lName, departmentValue, idValue;
    int ageValue;

    cout << "Enter First Name: ";
    cin >> fName;
    cout << "Enter Middle Name: ";
    cin >> mName;
    cout << "Enter Last Name: ";
    cin >> lName;
    cout << "Enter Age: ";
    cin >> ageValue;
    cout << "Enter Student ID: ";
    cin >> idValue;
    cout << "Enter Department: ";
    cin.ignore();
    getline(cin, departmentValue);

    struct student *temp;
    temp = new student;
    temp -> fullName = fName + " " + mName + " " + lName;
    temp -> id = idValue;
    temp -> age = ageValue;
    temp -> department = departmentValue;

    if(start == NULL){
        start = temp;
        start -> next = NULL;
        start -> pre = NULL;
    } else {
        struct student *newPointer;
        newPointer = start;
    
        while(newPointer -> next != NULL){
            newPointer = newPointer -> next;
        }
    
        newPointer -> next = temp;
        temp -> pre = newPointer;
        temp -> next = NULL; 
    }
    
}


//Adds more student info in the end
void addMoreInBack(){
    char response;
    do{
    cout << "Do you want to insert more? [y/n]: ";
    cin >> response;
    switch (response)
    {
    case 'y':
    case 'Y': insertStudentInfoInBack();
              break;
    case 'n':
    case 'N': cout << "Redirecting to homepage...\n";
              break;
    default: cout << "404: Wrong Input!\n";
    }
    } while(response != 'n' && response != 'N');
}


//inserts student record Before the targeted ID
void insertBeforeThisID() {
    if (start == NULL) {
        cout << "\n-----------------------\n\nThere is no student records to insert before!\n\n-----------------------\n";
        return;
    }

    string targetID;
    cout << "Enter the ID before which you want to insert a new student: ";
    cin >> targetID;

    struct student *current = start;
    while (current != NULL && current->id != targetID) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Student with ID \"" << targetID << "\" not found.\n";
        return;
    }

    string fName, mName, lName, departmentValue, idValue;
    int ageValue;

    cout << "Enter First Name: ";
    cin >> fName;
    cout << "Enter Middle Name: ";
    cin >> mName;
    cout << "Enter Last Name: ";
    cin >> lName;
    cout << "Enter Age: ";
    cin >> ageValue;
    cout << "Enter Student ID: ";
    cin >> idValue;
    cout << "Enter Department: ";
    cin.ignore();
    getline(cin, departmentValue);

    struct student *newStudent = new student;
    newStudent->fullName = fName + " " + mName + " " + lName;
    newStudent->id = idValue;
    newStudent->age = ageValue;
    newStudent->department = departmentValue;

    newStudent->next = current;
    newStudent->pre = current->pre;

    if (current->pre != NULL) {
        current->pre->next = newStudent;
    } else {
        start = newStudent;
    }

    current->pre = newStudent;

    cout << "Student inserted successfully before ID \"" << targetID << "\".\n";
}


//Adds more student info before the targeted ID
void addMoreBeforeThisId(){
    char response;
    do{
    cout << "Do you want to insert more? [y/n]: ";
    cin >> response;
    switch (response)
    {
    case 'y':
    case 'Y': insertBeforeThisID();
              break;
    case 'n':
    case 'N': cout << "Redirecting to homepage...\n";
              break;
    default: cout << "404: Wrong Input!\n";
    }
    } while(response != 'n' && response != 'N');
}


//inserts Student record after the targeted ID
void insertAfterThisID() {
    if (start == NULL) {
        cout << "\n-----------------------\n\nThere is no student records to insert after!\n\n-----------------------\n";
        return;
    }

    string targetID;
    cout << "Enter the ID after which you want to insert a new student: ";
    cin >> targetID;

    struct student *current = start;
    while (current != NULL && current->id != targetID) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Student with ID \"" << targetID << "\" not found.\n";
        return;
    }

    string fName, mName, lName, departmentValue, idValue;
    int ageValue;

    cout << "Enter First Name: ";
    cin >> fName;
    cout << "Enter Middle Name: ";
    cin >> mName;
    cout << "Enter Last Name: ";
    cin >> lName;
    cout << "Enter Age: ";
    cin >> ageValue;
    cout << "Enter Student ID: ";
    cin >> idValue;
    cout << "Enter Department: ";
    cin.ignore();
    getline(cin, departmentValue);

    struct student *newStudent = new student;
    newStudent->fullName = fName + " " + mName + " " + lName;
    newStudent->id = idValue;
    newStudent->age = ageValue;
    newStudent->department = departmentValue;

    newStudent->next = current->next;
    newStudent->pre = current;

    if (current->next != NULL) {
        current->next->pre = newStudent;
    }
    current->next = newStudent;

    cout << "Student inserted successfully after ID \"" << targetID << "\".\n";
}


//Adds more student info after the targeted ID
void addMoreAfterThisId(){
    char response;
    do{
    cout << "Do you want to insert more? [y/n]: ";
    cin >> response;
    switch (response)
    {
    case 'y':
    case 'Y': insertAfterThisID();
              break;
    case 'n':
    case 'N': cout << "Redirecting to homepage...\n";
              break;
    default: cout << "404: Wrong Input!\n";
    }
    } while(response != 'n' && response != 'N');
}



//insert info that gives three options
void insertStudentInfo(){
    int choice;
    cout << "\n1. Insert In Front\n2. Insert In Back\n3. Insert Before an ID\n4. Insert After an ID\n5. Back to HomePage\n\nchoose[1 - 3]: ";
    cin >> choice;
    switch(choice){
        case 1: cout << "Inserting In Front...\n";
                insertStudentInfoInFront();
                addMoreInFront();
                break;
        case 2: cout << "Inserting At The Back...\n";
                insertStudentInfoInBack();
                addMoreInBack();
                break;
        case 3: cout << "Inserting Before The ID...\n";
                insertBeforeThisID();
                addMoreBeforeThisId();
                break;
        case 4: cout << "Inserting After The ID...\n";
                insertAfterThisID();
                addMoreAfterThisId();
                break;
        case 5: cout << "Redirecting to homepage...\n";
                break;
        default: cout << "404: request not found!\n";
    }
}


//Delete the student found at the start of the linked list
void deleteFirst(){
    if(start == NULL){
        cout << "\n-----------------------\n\nThere is no any student record to delete!\n\n-----------------------\n";
    } else {
        struct student *df;
        df = start;
        start = start -> next;
        if (start != NULL)    
            start->pre = NULL;    
        delete df;
        cout << "\nFirst Student deleted Successfully\n";
    }
    
}


//Delete the student found at the end of the linked list
void deleteLast(){
    if(start == NULL){
        cout << "\n-----------------------\n\nThere is no any student record to delete!\n\n-----------------------\n";
    } else {
        if(start -> next == NULL){
            delete start;
            start = NULL;
        } else {
            struct student *newPointer, *newPointer1;
            newPointer = start;
    
            while(newPointer -> next != NULL){
                newPointer1 = newPointer;
                newPointer = newPointer -> next;
            }
    
            newPointer1 -> next = NULL;
            delete newPointer;
        }
        cout << "\nLast Student deleted Successfully\n";
    }
    
}

//Delete student id after getting by ID
void deleteById() {
    if (start == NULL) {
        cout << "\n-----------------------\n\nThere is no student records to delete!\n\n-----------------------\n";
    } else {
    string target;
    cout << "Enter the Student ID to delete: ";
    cin >> target;

    struct student *searched = start;

    while (searched != NULL) {
        if (searched->id == target) {
            if (searched == start) {
                start = searched->next;
                if (start != NULL) {
                    start->pre = NULL;
                }
            } else {
                searched->pre->next = searched->next;
                if (searched->next != NULL) {
                    searched->next->pre = searched->pre;
                }
            }

            delete searched;
            cout << "Student with ID \"" << target << "\" deleted successfully.\n";
            return;
        }
        searched = searched->next;
    }

    cout << "Student with ID \"" << target << "\" not found.\n";
    }

    
}


//Deletes all students record
void deleteAll() {
    if(start == NULL){
        cout << "\n-----------------------\nThere is no student records to delete!\n-----------------------\n";
    } else {
    while (start != NULL) {
        struct student *temp = start;
        start = start->next;
        delete temp;
    }
    cout << "All records deleted Successfully\n";
}
}


//Delete info that gives three options
void deleteStudentInfo(){
    int choice;
    cout << "\n1. Delete First\n2. Delete Last\n3. Delete by ID\n4. Delete all\n5. Back to HomePage\nchoose[1 - 3]: ";
    cin >> choice;
    switch(choice){
        case 1: deleteFirst();
                break;
        case 2: deleteLast();
                break;
        case 3: deleteById();
                break;
        case 4: deleteAll();
                break;
        case 5: cout << "Redirecting to homepage...\n";
                break;
        default: cout << "404: request not found!\n";
    }   
}


//Display all student records
void displayStudentInfo(){
    if(start == NULL){
        cout << "\n-----------------------\n\nThere is no any student record to display!\n\n-----------------------\n";
    } else {
        struct student *displayInfo;
        displayInfo = start;

        while(displayInfo != NULL){
            cout << "\n-----------------------\n";
            cout << "Name: " << displayInfo -> fullName 
                 << "\nAge: " << displayInfo -> age 
                 << "\nID: " << displayInfo -> id 
                 << "\nDepartment: " << displayInfo -> department;
            cout << "\n-----------------------\n";
            displayInfo = displayInfo -> next;
        }
    }
}


// Searchs a student record by ID and displays it
void searchStudent(){
    if(start == NULL){
        cout << "\n-----------------------\n\nThere is no any student record to Search!\n\n-----------------------\n";
    } else {
        struct student *search;
        search = start;

        bool isFound = false;
        string target;
        cout << "Enter the ID: ";
        cin >> target;

        while(search != NULL){
            if(search -> id == target){
                isFound = true;
                //Student Record
                cout << "\n-----------------------\n";
                cout << "Name: " << search -> fullName 
                << "\nAge: " << search -> age 
                << "\nID: " << search -> id 
                << "\nDepartment: " << search -> department;
                cout << "\n-----------------------\n"
                     << "\nStudent is Found Successfully\n";
        }
        search = search -> next;
        }

        if(isFound == false){
            cout << "Student with ID \"" << target << "\" is not found!\n";
        }
    }
}


void update() {

    if (start == NULL) {
        cout << "\n-----------------------\n\nThere is no any student record to Update!\n\n-----------------------\n";
    } else {
        bool isFound = false;
        string updateSt;
        cout << "Enter the ID: ";
        cin >> updateSt;
        struct student *search;
        search = start;

        while (search != NULL) {
            if (search -> id == updateSt) {

                int choice;
                isFound = true;

                do {
                    cout << "\nUpdating Student";
                    cout << "\n-----------------------\n";
                    cout << "Name: " << search -> fullName
                         << "\nAge: " << search -> age
                         << "\nID: " << search -> id
                         << "\nDepartment: " << search -> department;
                    cout << "\n-----------------------\n";
                    cout << "\n1. Change Name\n2. Change Age\n3. Change ID\n4. Change Department\n5. Exit\nchoose[1 - 5]: ";
                    cin >> choice;
                    string newFullName, newId, newDepartment;
                    int newAge;

                    switch (choice) {
                        case 1:
                            cout << "Current Student Name: \"" << search -> fullName << "\"\nEnter New FullName: ";
                            cin.ignore();
                            getline(cin, newFullName);
                            search -> fullName = newFullName;
                            cout << "Student name changed successfully\n\n";
                            break;
                        case 2:
                            cout << "Current Student Age: \"" << search -> age << "\"\nEnter new age: ";
                            cin >> newAge;
                            search -> age = newAge;
                            cout << "Student age changed successfully\n\n";
                            break;
                        case 3:
                            cout << "Current Student ID: \"" << search -> id << "\"\nEnter new ID: ";
                            cin >> newId;
                            search -> id = newId;
                            cout << "Student ID changed successfully\n\n";
                            break;
                        case 4:
                            cout << "Current Student Department: \"" << search -> department << "\"\nEnter new Department: ";
                            cin.ignore();
                            getline(cin, newDepartment);
                            search -> department = newDepartment;
                            cout << "Student department changed successfully\n\n";
                            break;
                        
                        case 5:
                            cout << "Exiting student settings...\n\n";
                            break;
                        default:
                            cout << "404: request not found\n\n";
                    }
                } while (choice != 5);

                break;
            }

            search = search -> next;
        }

        if (isFound == false) {
            cout << "student with ID \"" << updateSt << "\" was not found!\n\n";
        }
    }
}



//homepage containing all functionalities for admin
void adminHomePage(){
    int choice;
    cout << "Welcome To Student Registering System\n";
    do{
        cout << "\n1. Insert Student Info\n2. Display Students Info \n3. Delete Student Info\n4. Search Students Info\n5. Update Student\n6. Exit\n\nChoose[1 - 6]: ";
        cin >> choice;
        switch(choice){
            case 1: insertStudentInfo();
                    break;
            case 2: displayStudentInfo(); 
                    break;
            case 3: deleteStudentInfo();
                    break;
            case 4: searchStudent();
                    break;
            case 5: update();
                    break;
            case 6: cout << "Program Ended, Thank You!"
                         << "\n\nGroupMembers             ID\n"
                         << "------------            ----\n"
                         << "Mohammed Abdi          DDU1600554\n"
                         << "Samuel Solomon         DDU16000644\n"
                         << "Sena Alemayehu         DDU1600663\n"
                         << "Abdulfetah Ibrahim     DDU1600029\n"
                         << "Adnan Mohammed         DDU16001164\n\n";
                    break;
            default: cout << "404: request was not found\n";
        }
    }while(choice != 6);
}


//login page for admin to login
void login(){
    int attempt = 0;
    do{
    string userName, password;
    cout << "\n---- Login ----------\nEnter username: ";
    cin >> userName;
    cout << "Enter password: ";
    cin >> password;

    if(userName == "admin" && password == "admin"){
        cout << "-----------------------\nLogin Successful\n\n";
        adminHomePage();
        break;
    } else {
            cout << "-----------------------\nLogin failed: username or password incorrect!\n";
            attempt++;
            if(attempt == 3){
                cout << "System Locked: too many attempts!\n";
            }
        }
    } while(attempt != 3);
}


// Save students record to a file
void saveToFile() {
    ofstream outFile("students.txt");

    if (outFile.is_open()) {
        struct student *temp = start;
        while (temp != NULL) {
            outFile << temp->fullName << "\n"
                    << temp->age << "\n"
                    << temp->id << "\n"
                    << temp->department << "\n"
                    << "---\n";
            temp = temp->next;
        }
        outFile.close();
    } else {
        cout << "Error opening file for writing.\n";
    }
}

//Loads student records from the File
void loadFromFile() {
    ifstream inFile("students.txt");

    if (inFile.is_open()) {
        string fullName, id, department;
        int age;
        string delimiter;

        while (getline(inFile, fullName)) {
            inFile >> age;
            inFile.ignore();
            getline(inFile, id);
            getline(inFile, department);
            getline(inFile, delimiter);

            struct student *temp = new student;
            temp->fullName = fullName;
            temp->age = age;
            temp->id = id;
            temp->department = department;
            temp->next = NULL;
            temp->pre = NULL;

            if (start == NULL) {
                start = temp;
            } else {
                struct student *ptr = start;
                while (ptr->next != NULL) ptr = ptr->next;
                ptr->next = temp;
                temp->pre = ptr;
            }
        }
        inFile.close();
    } else {
        cout << "No saved records found to load.\n";
    }
}



int main(){
    loadFromFile();
    login();
    saveToFile();
    return 0;
}