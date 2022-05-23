#include <iostream>
#include "Simulation.hpp"
using namespace std;

Simulation::Simulation(){
}

void Simulation::printMenu(){
    //lots of printing of menu options
    cout << '\n';
    cout << "1. Print all students and their information (sorted by ascending id #)." << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)." << endl;
    cout << "3. Find and display student information given the students id." << endl;
    cout << "4. Find and display faculty information given the faculty id." << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor." << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7. Add a new student." << endl;
    cout << "8. Delete a student given the id." << endl;
    cout << "9. Add a new faculty member." << endl;
    cout << "10. Delete a faculty member given the id." << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "12. Remove an advisee from a faculty member given the ids " << endl;
    cout << "13. Rollback." << endl;
    cout << "14. Exit." << endl;
    cout << "Enter Choice: ";
}

void Simulation::simulate(){
    Table records = Table();
    int choice;
    cout << '\n';
    cout << "Welcome To The The Database, To Make a choice please refer to the following options:" << '\n' << endl;
    do {
        printMenu();
        cin >> choice;
        switch (choice) {
            case 1:
            {
                //student print
                records.printStudents();
                break;
            }
            case 2:
            {
                records.printFaculty();
                break;
            }
            case 3:
            {
              cout << "Enter the ID of the student you would like to view: ";
                int id;
                cin >> id;
                if(cin.fail()){
                  cout << "Invalid ID entered, please try again." << endl;
                  cin.clear();
                  cin.ignore();
                  break;
                }
                else{
                  records.studentFindAndDisplay(id);
                  break;
                }
            }
            case 4:
            {
              cout << "Enter the ID of the Faculty you would like to view: ";
              int id;
              cin >> id;
              if(cin.fail()){
                cout << "Invalid ID entered, please try again." << endl;
                cin.clear();
                cin.ignore();
                break;
              }
              else{
                records.facultyFindAndDisplay(id);
                  break;
              }
            }
            case 5:
            {
              cout << "Enter the ID of Student to view their Faculty: ";
              int id;
              cin >> id;
              if(cin.fail()){
                cout << "Invalid ID entered, please try again." << endl;
                cin.clear();
                cin.ignore();
                break;
              }
              else{
                records.showAdvisor(id);
                  break;
              }
            }
            case 6:
            {
              cout << "Enter the ID of the Faculty to view a list of their Students: ";
              int id;
              cin >> id;
              if(cin.fail()){
                cout << "Invalid ID entered, please try again." << endl;
                cin.clear();
                cin.ignore();
                break;
              }
              else{
                records.printAllAdvisees(id);
                  break;
              }
            }
            case 7:
            {
              records.addStudent();
                break;
            }
            case 8:
            {
              cout << "Enter the ID of the Student you would like to delete: ";
              int id;
              cin >> id;
              if(cin.fail()){
                cout << "Invalid ID entered, please try again." << endl;
                cin.clear();
                cin.ignore();
                break;
              }
              else{
                records.deleteStudent(id);
                  break;
              }
            }
            case 9:
            {
              records.addFaculty();
                break;
            }
            case 10:
            {
              cout << "Enter the ID of the Faculty you would like to delete: ";
              int id;
              cin >> id;
              if(cin.fail()){
                cout << "Invalid ID entered, please try again." << endl;
                cin.clear();
                cin.ignore();
                break;
              }
              else{
                records.deleteFaculty(id);
                  break;
              }
          }
            case 11:
            {
              cout << "Enter the ID of the Student whose Advisor you would like to change: ";
              int id;
              cin >> id;
              if(cin.fail()){
                cout << "Invalid ID entered, please try again." << endl;
                cin.clear();
                cin.ignore();
                break;
              }
              else{
                cout << "Enter the ID of the new Advisor you would like to assign to the Student: ";
                int advisor;
                cin >> advisor;
                if(cin.fail()){
                  cout << "Invalid ID entered, please try again." << endl;
                  cin.clear();
                  cin.ignore();
                  break;
                  }
                else{
                  records.changeAdvisor(id, advisor);
                  break;
                }
              }
            }
            case 12:
            {
              cout << "Enter the ID of the Faculty you wish to remove an Advisee from: ";
              int FacId;
              cin >> FacId;
              if(cin.fail()){
                cout << "Invalid ID entered, please try again." << endl;
                cin.clear();
                cin.ignore();
                break;
              }
              else{
                cout << "Enter the ID of Advisee you would like to remove: ";
                int StuId;
                cin >> StuId;
                if(cin.fail()){
                  cout << "Invalid ID entered, please try again." << endl;
                  cin.clear();
                  cin.ignore();
                  break;
                  }
                else{
                  records.removeAdvisee(FacId, StuId);
                  break;
                }
              }
            }
            case 13:
            {
              //rollback
                break;
            }
            case 14:
            {
              //exit
                break;
            }
            default:
            {
                cout << "Invalid choice, please enter a number between 1 and 14." << endl;
                break;
            }
        }




    } while (choice != 14);

    //keep this at end of main:
    records.saveToFiles();
}
