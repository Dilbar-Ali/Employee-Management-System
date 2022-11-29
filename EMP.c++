#include <iostream>
#include <conio.h>
using namespace std;
class Employee
{
    string name, id, address;
    int salary, contact, sy;
    friend class Employees;
};
class Employees
{
    Employee e[100];
    int total;
    public:
    Employees() : total (0){}
    void inputdata()
    {
        int user = 0;
        cout << "How many employees data do you want to enter??" << endl;
        cin >> user;
        for (int i = total; i < total + user; i++)
        {
            cout << "Enter data of employee " << i + 1 << endl
                 << endl;
            cout << "Enter employee name: ";
            cin >> e[i].name;
            cout << "Enter id: ";
            cin >> e[i].id;
            cout << "Enter address: ";
            cin >> e[i].address;
            cout << "Enter contact: ";
            cin >> e[i].contact;
            cout << "Enter salary: ";
            cin >> e[i].salary;
            cout << "Enter service year: ";
            cin >> e[i].sy;
        }
        total += user;
        cout << "Press Enter to continue...." << endl;
        cin.get();
        cin.ignore();
        system("CLS");
    }
    void show()
    {
        system("CLS");
        if (total != 0)
        {
            for (int i = 0; i < total; i++)
            {
                cout << "Data of employee " << i + 1 << endl;
                cout << "Name: " << e[i].name << endl;
                cout << "ID: " << e[i].id << endl;
                cout << "Address: " << e[i].address << endl;
                cout << "Contact: " << e[i].contact << endl;
                cout << "Salary: " << e[i].salary << endl;
                cout << "Service year: " << e[i].sy << endl;
            }
        }
        else
        {
            cout << "No data is entered" << endl;
        }
        cout << "Press Enter to continue...." << endl;
        cin.ignore();
        system("CLS");
    }
    void search()
    {
        if (total != 0)
        {
            string id;
            cout << "Enter id of employee which you want to search" << endl;
            cin >> id;
            bool found = false;
            for (int i = 0; i < total; i++)
            {
                if (e[i].id == id)
                {
                    found =true;
                    cout<<"--------------------------------------"<<endl;
                    cout << "Data of employee " << i + 1 << endl;
                    cout << "Name: " << e[i].name << endl;
                    cout << "ID: " << e[i].id << endl;
                    cout << "Address: " << e[i].address << endl;
                    cout << "Contact: " << e[i].contact << endl;
                    cout << "Salary: " << e[i].salary << endl;
                    cout << "Service year: " << e[i].sy << endl;
                }
            }
            if(found == false){
                cout << "No data is Found" << endl;
            }
        }
        else
        {

            cout << "No data is entered" << endl;
        }
        cout<<"--------------------------------------"<<endl;
        cout << "Press Enter to continue...." << endl;
        cin.get();
        cin.ignore();
        system("CLS");
    }
    void update()
    {
        if (total != 0)
        {
            string id;
            cout << "Enter id of employee which you want to update" << endl;
            cin >> id;
            bool found = false;
            for (int i = 0; i < total; i++)
            {
                if (e[i].id == id)
                {
                    found = true;
                    cout << "Old data of employee " << i + 1 << endl;
                    cout << "Name: " << e[i].name << endl;
                    cout << "ID: " << e[i].id << endl;
                    cout << "Address: " << e[i].address << endl;
                    cout << "Contact: " << e[i].contact << endl;
                    cout << "Salary: " << e[i].salary << endl;
                    cout << "Service year: " << e[i].sy << endl;
                    cout<<"--------------------------------------"<<endl;
                    cout << "\nEnter new data" << endl;
                    cout << "Enter employee name: ";
                    cin >> e[i].name;
                    cout << "Enter id: ";
                    cin >> e[i].id;
                    cout << "Enter address: ";
                    cin >> e[i].address;
                    cout << "Enter contact: ";
                    cin >> e[i].contact;
                    cout << "Enter salary: ";
                    cin >> e[i].salary;
                    cout << "Enter service year: ";
                    cin >> e[i].sy;
                    break;
                }
            }
            if(found ==false){
                cout << "No data is Found" << endl;
            }
        }
        else
        {
            cout << "No data is entered" << endl;
        }
        cout<<"--------------------------------------"<<endl;
        cout << "Press Enter to continue...." << endl;
        cin.ignore();
        system("CLS");
    }
    void del()
    {
        if (total != 0)
        {
            int press = 0;
            cout << "Press 1 to delete specific record" << endl;
            cout << "Press 2 to delete full record" << endl;
            cin >> press;
            if (press == 1)
            {
                string id; int delindex = -1;
                cout << "Enter id of employee which you want to delete" << endl;
                cin >> id;

                for (int i = 0; i < total; i++)
                {
                    if (e[i].id == id){
                        delindex = i;
                        break;
                    }
                }
                if(delindex == -1){
                        cout << "No such record found" << endl;
                }
                else{
                    for (int i = delindex; i < total-1; i++)
                        e[i] = e[i+1];
                    cout << "Your required record is deleted" << endl;
                    total--;                    
                }
            }
            else if (press == 2)
            {
                total = 0;
                cout << "All record is deleted" << endl;
            }
            else
            {
                cout << "Invalid Input" << endl;
            }
        }
        else
        {
            cout << "No data is entered" << endl;
        }
        cout << "Press Enter to continue...." << endl;
        cin.get();
        cin.ignore();
        system("CLS");
    }
};
void menu()
{
    cout << "\n\nPress 1 to enter data" << endl;
    cout << "Press 2 to show data" << endl;
    cout << "Press 3 to search data" << endl;
    cout << "Press 4 to update data" << endl;
    cout << "Press 5 to delete data" << endl;
    cout << "Press 6 to logout" << endl;
    cout << "Press 7 to exit" << endl;
}
main()
{
start:
    system("CLS");
    cout << "\n\n\t\tEmployee Management System" << endl;
    char ch;
    Employees r;
    while (1)
    {
        menu();
        ch = getch();
        system("CLS");
        switch (ch)
        {
        case '1':
            r.inputdata();
            break;
        case '2':
            r.show();
            break;
        case '3':
            r.search();
            break;
        case '4':
            r.update();
            break;
        case '5':
            r.del();
            break;
        case '6':
            goto start;
            break;
        case '7':
            exit(0);
            break;
        default:
            cout << "\aInvalid Input" << endl;
            break;
        }
    }
}