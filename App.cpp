#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class Main;
class Employee
{
private:
    char fname[15], lname[15], id[5], position[30], department[30], hiredOn[12], email[30], phone[10];
    int choice;

public:
    void showDetails()
    {
        string dash_line(170, '-'), space(7, ' '), dashline(65, '-');
        char checkId[5];
        cout << dashline << endl;
        cout << space << "ENTER YOUR ID : ";
        cin >> checkId;
        FILE *file;
        file = fopen("data.txt", "r");
        cout << dash_line << endl
             << left << setw(7) << "ID" << left << setw(20) << "FIRST NAME" << left << setw(20) << "LAST NAME" << left << setw(35) << "DEPARTMENT" << left << setw(35) << "POSITION" << left << setw(35) << "EMAIL" << left << setw(15) << "CONTACT NO." << left << setw(15) << "HIRED ON" << endl
             << dash_line << endl;
        while (fscanf(file, "%s %s %s %s %s %s %s %s", &id[0], &fname[0], &lname[0], &department[0], &position[0], &email[0], &phone[0], &hiredOn[0]) != EOF)
            if (strcmp(checkId, id) == 0)
            {
                cout << left << setw(7) << id << left << setw(20) << fname << left << setw(20) << lname << left << setw(35) << department << left << setw(35) << position << left << setw(35) << email << left << setw(15) << phone << left << setw(15) << hiredOn << endl;
            }
        cout << dash_line << endl;
        fclose(file);
    }
    void sendMessage()
    {
        string dash_line(65, '-'), space(13, ' '), spaceforchoice(7, ' '), message;
        char checkid[5], messages[500];
        cout << dash_line << endl;
        cout << space << "ENTER YOUR ID : ";
        cin >> checkid;
        FILE *file;
        file = fopen("data.txt", "r");
        while (fscanf(file, "%s %s %s %s %s %s %s %s", &id[0], &fname[0], &lname[0], &department[0], &position[0], &email, &phone, &hiredOn[0]) != EOF)
        {
            if (strcmp(checkid, id) == 0)
            {
                cout << space << "NOTE :- YOUR MESSAGE SHOULD CONTAIN YOUR ID" << endl;
                cout << space << "ENTER YOUR MESSAGE (PLEASE BEGIN WITH YOUR ID): ";
                cin.ignore(500, '\n');
                cin.getline(messages, 500);
                FILE *file2;
                file2 = fopen("message.txt", "a");
                fprintf(file2, "%s\n", &messages);
                fclose(file2);
                cout << space << "\nMESSAGE SENT!" << endl;
            }
        }
        fclose(file);
    }
    Employee()
    {
        string dash_line(65, '-'), space(13, ' '), spaceforchoice(7, ' ');
        while (choice != 0)
        {
            cout << dash_line << endl;
            cout << space << "ENTER 1 : SHOW PERSONAL DETAILS" << endl;
            cout << space << "ENTER 2 : SEND A MESSAGE TO ADMIN" << endl;
            cout << space << "ENTER 0 : EXIT" << endl;
            cout << space << "ENTER YOUR CHOICE : ";
            cin >> choice;
            if (choice == 1)
            {
                showDetails();
            }
            else if (choice == 2)
            {
                sendMessage();
            }
            else if (choice == 0)
            {
                break;
            }
        }
    }
};

class Admin
{
private:
    string pswd, interedpswd;
    char fname[15], lname[15], id[5], position[30], department[30], email[30], phone[15], hiredOn[12];
    int choice;

public:
    void showAllDetails() // all data shown function
    {
        string dash_line(175, '-');
        cout << dash_line << endl;
        FILE *file;
        file = fopen("data.txt", "r");
        cout << left << setw(7) << "ID" << left << setw(20) << "FIRST NAME" << left << setw(20) << "LAST NAME" << left << setw(35) << "DEPARTMENT" << left << setw(30) << "POSITION" << left << setw(35) << "EMAIL" << left << setw(15) << "CONTACT NO." << left << setw(15) << "HIRED ON" << endl
             << dash_line << endl;
        while (fscanf(file, "%s %s %s %s %s %s %s %s", &id[0], &fname[0], &lname[0], &department[0], &position[0], &email, &phone, &hiredOn[0]) != EOF)
        {
            cout << left << setw(7) << id << left << setw(20) << fname << left << setw(20) << lname << left << setw(35) << department << left << setw(30) << position << left << setw(35) << email << left << setw(15) << phone << left << setw(15) << hiredOn << endl;
        }
        cout << dash_line << endl;
        fclose(file);
    }

    void showDetailByID() // data shown by ID function
    {
        string dash_line(65, '-'), space(7, ' ');
        FILE *file;
        char checkID[5];
        cout << dash_line << endl;
        cout << space << "ENTER ID    :  ";
        cin >> checkID;
        file = fopen("data.txt", "r");
        while (fscanf(file, "%s %s %s %s %s %s %s %s", &id[0], &fname[0], &lname[0], &department[0], &position[0], &email, &phone, &hiredOn[0]) != EOF)
            if (strcmp(checkID, id) == 0)
            {
                cout << space << "FIRST NAME  :  " << fname << endl;
                cout << space << "LAST NAME   :  " << lname << endl;
                cout << space << "DEPARTMENT  :  " << department << endl;
                cout << space << "POSITION    :  " << position << endl;
                cout << space << "EMAIL       :  " << email << endl;
                cout << space << "CONTACT NO. :  " << phone << endl;
                cout << space << "HIRED ON    :  " << hiredOn << endl;
                break;
            }
        fclose(file);
    }

    void addEmployeeDetails() // data adding function
    {
        bool found = false;
        string dash_line(65, '-'), space(7, ' ');
        cout << dash_line << endl;
        cout << space << "ENTER EMPLOYEE ID [4 DIGITS MAX]  :  ";
        cin >> id;
        cout << space << "ENTER FIRST NAME OF EMPLOYEE  :  ";
        cin >> fname;
        cout << space << "ENTER LAST NAME OF EMPLOYEE : ";
        cin >> lname;
        cout << space << "ENTER DEPARTMENT  :  ";
        cin >> department;
        cout << space << "ENTER POSITION  :  ";
        cin >> position;
        cout << space << "ENTER EMAIL  :  ";
        cin >> email;
        char target = '@';
        for (int i = 0; email[i] != '\0'; i++)
        {
            if (email[i] == target)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << space << "EMAIL DOES NOT CONTAIN @ SYMBOL" << endl;
            addEmployeeDetails();
        }

        cout << space << "ENTER PHONE NUMBER  :  ";
        cin >> phone;
        for (int i = 0; phone[i] != '\0'; i++)
        {
            if (isdigit(phone[i]))
            {
            }
            else
            {
                cout << space << "YOU ENTERED WRONG NUMBER" << endl;
                addEmployeeDetails();
            }
        }
        if (strlen(phone) == 10)
        {
        }
        else
        {
            cout << space << "PHONE NUMBER MUST BE OF 10 DIGITS" << endl;
            addEmployeeDetails();
        }

        cout << space << "ENTER HIRED ON DATE (DD/MM/YYYY)  :  ";
        cin >> hiredOn;
        char ch1;
        cout << space << "DO YOU WANT TO CHANGE ANY INFORMATION YOU HAVE ENTERED ABOVE (Y/N)  :  ";
        cin >> ch1;
        if (ch1 == 'n' || ch1 == 'N')
        {
            FILE *file;
            file = fopen("data.txt", "a");
            fprintf(file, "%s %s %s %s %s %s %s %s \n", id, fname, lname, department, position, email, phone, hiredOn);
            fclose(file);
            cout << endl
                 << space << "DATA ADDED SUCCESSFULLY!" << endl;
        }
        else
        {
            addEmployeeDetails();
        }
    }

    void deleteEmployeeDetail() // data deletion function
    {
        string dash_line(65, '-'), space(7, ' ');
        char checkID[5], ch;
        cout << dash_line << endl;
        cout << space << "ENTER EMPLOYEE ID  :  ";
        cin >> checkID;
        cout << space << "ENTER 'Y' TO CONFIRM DELETION  :  ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            FILE *file, *tempfile;
            file = fopen("data.txt", "r");
            tempfile = fopen("temp.txt", "w");
            while (fscanf(file, "%s %s %s %s %s %s %s %s", &id[0], &fname[0], &lname[0], &department[0], &position[0], &email, &phone, &hiredOn[0]) != EOF)
            {
                if (strcmp(checkID, id) != 0)
                {
                    fprintf(tempfile, "%s %s %s %s %s %s %s %s \n", id, fname, lname, department, position, email, phone, hiredOn);
                }
            }
            fclose(file);
            fclose(tempfile);
            int remove_file = remove("data.txt");
            int rename_file = rename("temp.txt", "data.txt");
            cout << endl
                 << space << "DATA REMOVED SUCCESSFULLY!" << endl;
        }
        else
        {
            deleteEmployeeDetail();
        }
    }

    void updateEmployeeDetails()
    {
        bool found = false;
        string dash_line(65, '-'), space(7, ' ');
        char checkID[5], newdepartment[10], newfname[15], newlname[15], newposition[30], newemail[30], newphone[15], newhiredon[12], input;
        cout << dash_line << endl;
        cout << space << "NOTE - EMPLOYEE ID CAN'T BE CHANGED" << endl;
        cout << space << "NOTE - REPLACE WHITESPACE WITH '_'" << endl;
        cout << space << "ENTER EMPLOYEE ID  :  ";
        cin >> checkID;
        cout << space << "ENTER NEW FIRST NAME  :  ";
        cin >> newfname;
        cout << space << "ENTER NEW LAST NAME  :  ";
        cin >> newlname;
        cout << space << "ENTER NEW DEPARTMENT  :  ";
        cin >> newdepartment;
        cout << space << "ENTER NEW POSITION  :  ";
        cin >> newposition;
        cout << space << "ENTER NEW EMAIL  :  ";
        cin >> newemail;
        char target = '@';
        for (int i = 0; email[i] != '\0'; i++)
        {
            if (email[i] == target)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << space << "EMAIL DOES NOT CONTAIN @ SYMBOL" << endl;
            updateEmployeeDetails();
        }

        cout << space << "ENTER NEW PHONE  :  ";
        cin >> newphone;
        for (int i = 0; phone[i] != '\0'; i++)
        {
            if (isdigit(phone[i]))
            {
            }
            else
            {
                cout << space << "YOU ENTERED WRONG NUMBER" << endl;
                updateEmployeeDetails();
            }
        }
        if (strlen(phone) == 10)
        {
        }
        else
        {
            cout << space << "PHONE NUMBER MUST BE OF 10 DIGITS" << endl;
            updateEmployeeDetails();
        }
        cout << space << "ENTER HIRED ON DATE (DD/MM/YYYY)  :  ";
        cin >> newhiredon;
        cout << space << "DO YOU WANT TO CHANGE ANY INFORMATION YOU ENTERED ABOVE (Y/N)  :  ";
        cin >> input;
        if (input == 'n' || input == 'N')
        {

            FILE *file, *tempfile;
            file = fopen("data.txt", "r");
            tempfile = fopen("temp.txt", "w");
            while (fscanf(file, "%s %s %s %s %s %s %s %s ", &id[0], &fname[0], &lname[0], &department[0], &position[0], &email, &phone, &hiredOn[0]) != EOF)
            {
                if ((strcmp(id, checkID)) == 0)
                {
                    fprintf(tempfile, "%s %s %s %s %s %s %s %s \n", id, newfname, newlname, newdepartment, newposition, newemail, newphone, newhiredon);
                }
                else
                {
                    fprintf(tempfile, "%s %s %s %s %s %s %s %s \n", id, fname, lname, department, position, email, phone, hiredOn);
                }
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved = remove("data.txt");
            int isRenamed = rename("temp.txt", "data.txt");
            cout << endl
                 << space << "DATA UPDATED SUCCESSFULLY!" << endl;
        }
        else
        {
            updateEmployeeDetails();
        }
    }

    void showMessages()
    {
        string dash_line(65, '-'), space(7, ' ');
        string message;
        int n = 1;
        ifstream file("message.txt");
        cout << dash_line << endl;
        cout << space << "MESSAGES FROM ALL EMPLOYEES\n" << endl;
        while (getline(file, message))
        {
            cout << space << n << ". " << message << endl;
            n++;
        }
        file.close();
    }
    Admin()
    {
        string dash_line(65, '-'), space(6, ' '), spaceforchoice(7, ' ');
        fstream file;
        file.open("password.txt", ios::in);
        if (file.is_open())
        {
            cout << dash_line << endl;
            cout << space << "ENTER THE PASSWORD  :  ";
            cin >> interedpswd;
            getline(file, pswd);
            if (interedpswd == pswd)
            {
                while (choice != 0)
                {
                    cout << dash_line << endl
                         << spaceforchoice << "ENTER 1  :  SHOW ALL EMPLOYEE DETAILS" << endl;
                    cout << spaceforchoice << "ENTER 2  :  SEARCH AN EMPLOYEE DETAILS" << endl;
                    cout << spaceforchoice << "ENTER 3  :  UPDATE EXISTING EMPLOYEE DETAILS" << endl;
                    cout << spaceforchoice << "ENTER 4  :  DELETE AN EMPLOYEE RECORD" << endl;
                    cout << spaceforchoice << "ENTER 5  :  ADD NEW EMPLOYEE DETAILS" << endl;
                    cout << spaceforchoice << "ENTER 6  :  SHOW EMPLOYEE MESSAGES" << endl;
                    // cout << spaceforchoice << "ENTER 7  :  SET A NEW PASSWORD" << endl;
                    cout << spaceforchoice << "ENTER 0  :  EXIT" << endl;
                    cout << spaceforchoice << "ENTER YOUR CHOICE  :  ";
                    cin >> choice;
                    if (choice == 1)
                    {
                        showAllDetails();
                    }
                    else if (choice == 2)
                    {
                        showDetailByID();
                    }
                    else if (choice == 3)
                    {
                        updateEmployeeDetails();
                    }

                    else if (choice == 4)
                    {
                        deleteEmployeeDetail();
                    }
                    else if (choice == 5)
                    {
                        addEmployeeDetails();
                    }
                    else if (choice == 6)
                    {
                        showMessages();
                    }

                    else if (choice == 0)
                    {
                        cout << dash_line << endl;
                        cout << spaceforchoice << "THANKS FOR USING EMPLOYEE MANAGEMENT SYSTEM!\n"
                             << dash_line << endl
                             << endl;
                        break;
                    }
                }
            }
        }
        else
        {
            cout << "FILE NOT FOUND!" << endl;
        }
    }
};

class Main
{
private:
    char choice;

public:
    Main()
    {
        string decor1(10, '>'), decor2(10, '<'), dash_line(65, '-'), space(17, ' '), spaceforkey(11, ' ');
        cout << endl
             << dash_line;
        cout << endl
             << decor1 << "   EMPLOYEE MANAGEMENT SYSTEM WELCOMES YOU   " << decor2 << endl;
        cout << dash_line << endl;
        cout << space << "ENTER 1  :   ADMINISTRATOR" << endl;
        cout << dash_line << endl;
        cout << space << "ENTER 2  :   EMPLOYEE" << endl;
        cout << dash_line << endl;
        cout << spaceforkey << "ENTER ANY KEY  :   EXIT" << endl;
        cout << dash_line << endl;
        cout << "       ENTER YOUR CHOICE  :   ";
        cin >> choice;
        if (choice == '1')
        {
            Admin admin;
        }
        else if (choice == '2')
        {
            Employee emp;
        }
        else
        {
            cout << dash_line << endl
                 << space << "THANKS FOR USING EMS\n"
                 << dash_line << endl
                 << endl;
        }
    }
};

int main()
{
    Main app;
    return 0;
}