#include <iostream>
#include <cstring>

// Define CC as "clear" for clearing the screen
#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

using namespace std;

// Function prototypes
void showMainMenu(); // Displays the main menu
void showStudentMenu(); // Displays the student menu
void showStaffMenu(); // Displays the staff menu
void showAccountsMenu(); // Displays the accounts menu
void showRoomsMenu(); // Displays the rooms menu
void modStudent(); // Allows user to modify or add a student
void statStudent(); // Displays statistics of a student
void modStaff(); // Allows user to modify or add staff member
void statStaff(); // Displays statistics of a staff member
void modTeacher(); // Allows user to modify or add a teacher
void statTeacher(); // Displays statistics of a teacher
void clearScreen(); // Clears the screen
void getString(char *d, const char p[25]); // Gets a string input from user
void getInt(int &d, const char p[25]); // Gets an integer input from user
void statExpense(); // Displays expenses
void statProfit(); // Displays profit
void statRoom(); // Displays available rooms

// Staff structure
struct Staff {
    int id; // Staff ID
    char name[25]; // Staff name
    char duty[15]; // Staff duty
    int salary; // Staff salary
    int pDays; // Present days
    int aDays; // Absent days
};

static int staffCount = 0;
static Staff staffs[30];

// Student structure
struct Student {
    int id; // Student ID
    char name[25]; // Student name
    char fname[25]; // Father's name
    int _class; // Student class
    char section[5]; // Student section
    int fee; // Student fee
    int pDays; // Present days
    int aDays; // Absent days
};

static int studentCount = 0;
static Student students[200];

// Teacher structure
struct Teacher {
    int id; // Teacher ID
    char name[25]; // Teacher name
    char course[15]; // Course name
    int salary; // Teacher salary
    int pDays; // Present days
    int aDays; // Absent days
};

static int teacherCount = 0;
static Teacher teachers[30];

// Room structure
struct Room {
    int _class; // Class number
    char section[5]; // Section
};

static int roomCount = 0;
static Room rooms[200];

int main() {
    showMainMenu(); // Show the main menu
    return 0;
}

// Function definitions

void showStudentMenu() {
    clearScreen(); // Clear the screen
    cout << "\n=== Student Menu ===\n\n";
    cout << "1) Add/Edit Student\n";
    cout << "2) Show Stats of Student\n";
    cout << "0) Back\n";
    char c[2];
    getString(c, "\n\nEnter Your Choice: "); // Get user's choice
    if (strcmp(c, "1") == 0) {
        modStudent(); // Modify or add a student
    } else if (strcmp(c, "2") == 0) {
        statStudent(); // Display statistics of a student
    } else if (strcmp(c, "0") == 0) {
        return; // Return to the previous menu
    }
    showStudentMenu(); // Show the student menu again
}

void showStaffMenu() {
    clearScreen(); // Clear the screen
    cout << "\n=== Staff Menu ===\n\n";
    cout << "1) Add/Edit Teacher\n";
    cout << "2) Add/Edit Staff Member\n";
    cout << "3) Show Stats of Teacher\n";
    cout << "4) Show Stats of Staff Member\n";
    cout << "0) Back\n";
    char c[2];
    getString(c, "\n\nEnter Your Choice: "); // Get user's choice
    if (strcmp(c, "1") == 0) {
        modTeacher(); // Modify or add a teacher
    } else if (strcmp(c, "2") == 0) {
        modStaff(); // Modify or add a staff member
    } else if (strcmp(c, "3") == 0) {
        statTeacher(); // Display statistics of a teacher
    } else if (strcmp(c, "4") == 0) {
        statStaff(); // Display statistics of a staff member
    } else if (strcmp(c, "0") == 0) {
        return; // Return to the previous menu
    }
    showStaffMenu(); // Show the staff menu again
}

void showAccountsMenu() {
    clearScreen(); // Clear the screen
    cout << "\n=== Accounts Menu ===\n\n";
    cout << "1) Show Expenses\n";
    cout << "2) Show Profit\n";
    cout << "0) Back\n";
    char c[2];
    getString(c, "\n\nEnter Your Choice: "); // Get user's choice
    if (strcmp(c, "1") == 0) {
        statExpense(); // Display expenses
    } else if (strcmp(c, "2") == 0) {
        statProfit(); // Display profit
    } else if (strcmp(c, "0") == 0) {
        return; // Return to the previous menu
    }
    showAccountsMenu(); // Show the accounts menu again
}

void showRoomsMenu() {
    clearScreen(); // Clear the screen
    cout << "\n=== Rooms Menu ===\n\n";
    cout << "1) Show Available Rooms\n";
    cout << "0) Back\n";
    char c[2];
    getString(c, "\n\nEnter Your Choice: "); // Get user's choice
    if (strcmp(c, "1") == 0) {
        statRoom(); // Display available rooms
    } else if (strcmp(c, "0") == 0) {
        return; // Return to the previous menu
    }
    showRoomsMenu(); // Show the rooms menu again
}

void showMainMenu() {
    clearScreen(); // Clear the screen
    cout << "\n=== Student Management System ===\n\n";
    cout << "1) Student\n";
    cout << "2) Staff\n";
    cout << "3) Accounts\n";
    cout << "4) Rooms\n";
    cout << "0) Exit\n";
    char c[2];
    getString(c, "\n\nEnter Your Choice: "); // Get user's choice
    if (strcmp(c, "1") == 0) {
        showStudentMenu(); // Show the student menu
    } else if (strcmp(c, "2") == 0) {
        showStaffMenu(); // Show the staff menu
    } else if (strcmp(c, "3") == 0) {
        showAccountsMenu(); // Show the accounts menu
    } else if (strcmp(c, "4") == 0) {
        showRoomsMenu(); // Show the rooms menu
    } else if (strcmp(c, "0") == 0) {
        return; // Exit the program
    }
    showMainMenu(); // Show the main menu again
}

void modStaff() {
    int id = 0;
    getInt(id, "Enter ID or 0 for new: "); // Get staff ID or choose to add new
    if (id == 0) {
        char _name[25];
        char _duty[15];
        int _salary;
        getString(_name, "Enter Name: "); // Get staff name
        getString(_duty, "Enter Duty: "); // Get staff duty
        getInt(_salary, "Enter Salary: "); // Get staff salary
        Staff s;
        s.id = staffCount + 1;
        strcpy(s.name, _name);
        strcpy(s.duty, _duty);
        s.salary = _salary;
        s.pDays = 0;
        s.aDays = 0;
        staffs[staffCount] = s;
        staffCount++;
    } else {
        char _name[25];
        char _duty[15];
        int _salary;
        getString(_name, "Enter Name: "); // Get staff name
        getString(_duty, "Enter Duty: "); // Get staff duty
        getInt(_salary, "Enter Salary: "); // Get staff salary
        strcpy(staffs[id - 1].name, _name);
        strcpy(staffs[id - 1].duty, _duty);
        staffs[id - 1].salary = _salary;
        int pDays = 0;
        int aDays = 0;
        getInt(pDays, "Enter Present Days: "); // Get present days
        getInt(aDays, "Enter Absent Days: "); // Get absent days
        staffs[id - 1].pDays = pDays;
        staffs[id - 1].aDays = aDays;
    }
}

void statStaff() {
    int id = 0;
    getInt(id, "Enter ID: "); // Get staff ID
    cout << "Name: " << staffs[id - 1].name << endl;
    cout << "Duty: " << staffs[id - 1].duty << endl;
    cout << "Salary: " << staffs[id - 1].salary << endl;
    cout << "Days Present: " << staffs[id - 1].pDays << endl;
    cout << "Days absent: " << staffs[id - 1].aDays << endl;
    getInt(id, "Enter 0 to continue...");
}

void modStudent() {
    int id = 0;
    getInt(id, "Enter ID or 0 for new: "); // Get student ID or choose to add new
    if (id == 0) {
        // Add a new student
        Student s;
        s.id = studentCount + 1;
        char _name[25];
        char _fname[25];
        int _class;
        char _section[5];
        int _fee;
        getString(_name, "Enter Name: "); // Get student name
        getString(_fname, "Enter Father Name: "); // Get father's name
        getInt(_class, "Enter Class: "); // Get student class
        getString(_section, "Enter Section: "); // Get student section
        getInt(_fee, "Enter Fee: "); // Get student fee
        strcpy(s.name, _name);
        strcpy(s.fname, _fname);
        s._class = _class;
        strcpy(s.section, _section);
        s.fee = _fee;
        s.pDays = 0;
        s.aDays = 0;
        students[studentCount] = s;
        studentCount++;
    } else if (id > 0 && id <= studentCount) {
        // Modify existing student
        char _name[25];
        char _fname[25];
        int _class;
        char _section[5];
        int _fee;
        getString(_name, "Enter Name: "); // Get student name
        getString(_fname, "Enter Father Name: "); // Get father's name
        getInt(_class, "Enter Class: "); // Get student class
        getString(_section, "Enter Section: "); // Get student section
        getInt(_fee, "Enter Fee: "); // Get student fee
        strcpy(students[id - 1].name, _name);
        strcpy(students[id - 1].fname, _fname);
        students[id - 1]._class = _class;
        strcpy(students[id - 1].section, _section);
        students[id - 1].fee = _fee;
        int pDays = 0;
        int aDays = 0;
        getInt(pDays, "Enter Present Days: "); // Get present days
        getInt(aDays, "Enter Absent Days: "); // Get absent days
        students[id - 1].pDays = pDays;
        students[id - 1].aDays = aDays;
    } else {
        cout << "Invalid ID." << endl;
    }
}

void statStudent() {
    int id = 0;
    getInt(id, "\nEnter ID: "); // Get student ID
    if (id > 0 && id <= studentCount) {
        cout << "Name: " << students[id - 1].name << endl;
        cout << "Father Name: " << students[id - 1].fname << endl;
        cout << "Class: " << students[id - 1]._class << endl;
        cout << "Section: " << students[id - 1].section << endl;
        cout << "Fee: " << students[id - 1].fee << endl;
        cout << "Days Present: " << students[id - 1].pDays << endl;
        cout << "Days absent: " << students[id - 1].aDays << endl;
        int c;
        getInt(c, "Enter 0 to continue...");
    } else {
        cout << "Invalid ID." << endl;
    }
}


void modTeacher() {
    int id = 0;
    getInt(id, "Enter ID or 0 for new: "); // Get teacher ID or choose to add new
    if (id == 0) {
        char _name[25];
        char _course[15];
        int _salary;
        getString(_name, "Enter Name: "); // Get teacher name
        getString(_course, "Enter Course Name: "); // Get course name
        getInt(_salary, "Enter Salary: "); // Get teacher salary
        Teacher t;
        t.id = teacherCount + 1;
        strcpy(t.name, _name);
        strcpy(t.course, _course);
        t.salary = _salary;
        t.pDays = 0;
        t.aDays = 0;
        teachers[teacherCount] = t;
        teacherCount++;
    } else {
        char _name[25];
        char _course[15];
        int _salary;
        getString(_name, "Enter Name: "); // Get teacher name
        getString(_course, "Enter Course Name: "); // Get course name
        getInt(_salary, "Enter Salary: "); // Get teacher salary
        strcpy(teachers[id - 1].name, _name);
        strcpy(teachers[id - 1].course, _course);
        teachers[id - 1].salary = _salary;
        int pDays = 0;
        int aDays = 0;
        getInt(pDays, "Enter Present Days: "); // Get present days
        getInt(aDays, "Enter Absent Days: "); // Get absent days
        teachers[id - 1].pDays = pDays;
        teachers[id - 1].aDays = aDays;
    }
}

void statTeacher() {
    int id = 0;
    getInt(id, "\nEnter ID: "); // Get teacher ID
    cout << "Name: " << teachers[id - 1].name << endl;
    cout << "Course: " << teachers[id - 1].course << endl;
    cout << "Salary: " << teachers[id - 1].salary << endl;
    cout << "Days Present: " << teachers[id - 1].pDays << endl;
    cout << "Days absent: " << teachers[id - 1].aDays << endl;
    getInt(id, "Enter 0 to continue...");
}

void clearScreen() {
    system(CLEAR_SCREEN); // Clear the screen
}

void getString(char *d, const char p[25]) {
    cout << p;
    cin.getline(d, 25); // Get string input from user
}

void getInt(int &d, const char p[25]) {
    cout << p;
    cin >> d; // Get integer input from user
    cin.ignore(256, '\n');
}

void statExpense() {
    cout << "Expenses this month:\n\n";
    cout << "1) Lab Maintenance: 2000pkr\n";
    cout << "2) Library Expense: 3500pkr\n";
    cout << "3) LEDs: 10000pkr\n";
    cout << "4) Chairs: 15000pkr\n";
    cout << "5) Tables: 17000pkr\n";
    int c;
    getInt(c, "Enter 0 To Continue...");
}

void statProfit() {
    cout << "Profit this month:\n\n";
    cout << "1) Profit (School): 400000pkr\n";
    cout << "2) From Sells of Stationery: 55000pkr\n";
    cout << "3) External Profit From Coaching Centre: 60000pkr\n";
    int c;
    getInt(c, "Enter 0 To Continue...");
}

void statRoom() {
    cout << "Available Class Rooms:" << endl << endl;
    for (int i = 0; i < roomCount; i++) {
        cout << "Class: " << rooms[i]._class << endl;
        cout << "Section: " << rooms[i].section << endl << endl;
    }
    int c;
    getInt(c, "Enter 0 To Continue...");
}
