#include <iostream>
#include <fstream>
using namespace std;

class LeaveApprove {
public:
    virtual void approveLeave() = 0; // Pure virtual function
    virtual ~LeaveApprove() {}
};

class Leave {
protected:
    LeaveApprove* approver;
    int totalLeaves;
    string employeeID;

public:
    Leave(int leaves, const string& empID) : totalLeaves(leaves), employeeID(empID) {}
    virtual void applyForLeave() = 0;
    virtual void updateStatus() = 0;
    virtual ~Leave() {}
};

class CasualLeave : public Leave {
public:
    CasualLeave(const string& empID) : Leave(15, empID) {}
    void applyForLeave() override {
       
    }
    void updateStatus() override {
        
    }
};

class EarnedLeave : public Leave {
public:
    EarnedLeave(const string& empID) : Leave(21, empID) {}
    void applyForLeave() override {
       
    }
    void updateStatus() override {
        
    }
};

class OfficialLeave : public Leave {
public:
    OfficialLeave(const string& empID) : Leave(0, empID) {}

    void applyForLeave() override {
        ofstream outFile("leaveApplications.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Employee ID: " << employeeID << ", Leave Type: Official Leave, Status: Applied\n";
            cout << "Official leave application submitted for Employee ID: " << employeeID << endl;
        } else {
            cerr << "Error opening leave applications file!" << endl;
        }
        outFile.close();
    }

    void updateStatus() override {
        cout << "Official leave auto-approved for Employee ID: " << employeeID << endl;
    }
};

class UnpaidLeave : public Leave {
public:
    UnpaidLeave(const string& empID) : Leave(0, empID) {}

    void applyForLeave() override {
        ofstream outFile("leaveApplications.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Employee ID: " << employeeID << ", Leave Type: Unpaid Leave, Status: Applied\n";
            cout << "Unpaid leave application submitted for Employee ID: " << employeeID << endl;
        } else {
            cerr << "Error opening leave applications file!" << endl;
        }
        outFile.close();
    }

    void updateStatus() override {
        cout << "Unpaid leave requires manual approval for Employee ID: " << employeeID << endl;
    }
};

class Person {
protected:
    string name;

public:
    Person(const string& personName) : name(personName) {}
    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
    }
    virtual ~Person() {}
};

class Employee : public Person {
private:
    string empID;
    int leaveBalance;

public:
    Employee(const string& name, const string& id) : Person(name), empID(id), leaveBalance(36) {}
    
    void viewAttendance() {
      
    }

    void viewLeaves() {
       
    }

    void applyLeave(Leave* leave) {
        leave->applyForLeave();
    }
};

class Supervisor : public Person, public LeaveApprove {
private:
    string supervisorID;

public:
    Supervisor(const string& name, const string& id) : Person(name), supervisorID(id) {}

    void approveLeave() override {
        cout << "Leave approved by Supervisor: " << name << endl;
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Supervisor ID: " << supervisorID << endl;
    }
};

class Director : public Person, public LeaveApprove {
private:
    string directorID;

public:
    Director(const string& name, const string& id) : Person(name), directorID(id) {}

    void approveLeave() override {
        cout << "Leave approved by Director: " << name << endl;
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Director ID: " << directorID << endl;
    }
};

class Guard : public Person {
private:
    string guardID;

public:
    Guard(const string& name, const string& id) : Person(name), guardID(id) {}

    void markAttendance(const string& empID, const string& date) {
        ofstream outFile("attendance.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Employee ID: " << empID << ", Date: " << date << ", Hours: 8" << endl;
            cout << "Attendance marked for Employee ID: " << empID << " on " << date << endl;
        } else {
            cerr << "Error opening attendance file!" << endl;
        }
        outFile.close();
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Guard ID: " << guardID << endl;
    }
};

void Leave::applyForLeave() {
    ofstream outFile("leaveApplications.txt", ios::app);
    outFile << "EmployeeID: " << employeeID << ", LeaveType: " << typeid(*this).name() << "\n";
    outFile.close();
}

int main() {
   
    return 0;
}
