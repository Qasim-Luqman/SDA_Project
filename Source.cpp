#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
public:
    void set_hours(int h) {
        hours = h;
    }
    void set_minutes(int m) {
        minutes = m;
    }
    void set_time(int h, int m) {
        hours = h;
        minutes = m;
    }
    int get_hours() {
        return this->hours;
    }
    int get_minutes() {
        return this->minutes;
    }
};

class Date {

private:
    int date;
    int month;
    int year;

public:
    void setdate(int d) {
        this->date = d;
    }
    void setmonth(int m) {
        this->month = m;
    }
    void setyear(int y) {
        this->year = y;
    }
    void set_date(int d, int m, int y) {
        this->date = d;
        this->month = m;
        this->year = y;
    }
    int getday() {
        return date;
    }
    int getmonth() {
        return month;
    }
    int getyear() {
        return year;
    }
};


class Service {
protected:
    string service_name;
    int service_charges;

public:
    Service() {
        service_charges = 50;
    }
    void set_name(string name) {
        service_name = name;
    }

    void set_price(int price) {
        service_charges = price;
    }

    string get_name() {
        return service_name;
    }

    int get_price() {
        return service_charges;
    }
};

class Buy_parts_service : public Service {
public:
    Buy_parts_service() : Service() {
        service_name = "parts";
    }
    string get_name() {
        return service_name;
    }
};

class Paint_service : public Service {
public:
    Paint_service() : Service() {
        service_name = "paint";
    }
    string get_name() {
        return service_name;
    }
};





class Stock_inv  {
private:
    string name;
    int avail_inv;
    int daily_demand;
public:
    Stock_inv(int a, int d) {
        avail_inv = a;
        daily_demand = d;
    }
    void change_available_amount(int a_i) {
        this->avail_inv = a_i;
    }
    void change_daily_demand(int d_d) {
        this->daily_demand = d_d;
    }
    int get_available_amount() {
        return avail_inv;
    }
    int get_daily_demand() {
        return daily_demand;
    }
};

class Booking {
private:
    Service* ps;
    Date* date;
    Time* time;
    string cust_name;
public:
    Booking() {
        //bps = nullptr;
        //ps = nullptr;
        ps = nullptr;
        date = nullptr;
        time = nullptr;
    }

    void set_ps(Service* p) {
        ps = p;
    }

    void set_date(Date* d) {
        date = d;
    }

    void set_time(Time* t) {
        time = t;
    }

    void set_name(string n) {
        cust_name = n;
    }

    string get_name() {
        return cust_name;
    }

    int get_date() {
        return date->getday();
    }

    int get_month() {
        return date->getmonth();
    }

    int get_year() {
        return date->getyear();
    }

    int get_hour() {
        return time->get_hours();
    }

    int get_minutes() {
        return time->get_minutes();
    }

    string get_service_name() {
        return ps->get_name();
    }

    string get_cust_name() {
        return cust_name;
    }

    Booking* make_booking(string name) {
        Booking* cust_booking = nullptr;
        cust_booking = new Booking;
        int day, month, year, hour, minute;

        int choice = 0;

        cout << "Services Available: " << endl;
        cout << "1. Buy Parts Service" << endl;
        cout << "2. Paint Service" << endl;
        cout << "Enter Option (1/2): ";
        do {
            cin >> choice;
            if (choice != 1 && choice != 2) {
                cout << "Invalid Option, Try Again: ";
            }
        } while (choice != 1 && choice != 2);

        if (choice == 1) {
            Service* b;
            b = new Buy_parts_service;
            cust_booking->set_ps(b);
            //b = nullptr;
        }
        else {
            Service* b;
            b = new Paint_service;
            cust_booking->set_ps(b);
            //p = nullptr;
        }

        do {
            cout << "\nEnter Year of Booking: ";
            cin >> year;
            if (year < 2022 || year > 2026) {
                cout << "Enter Valid Year. (Till 2026)." << endl;
            }
        } while (year < 2022 || year > 2026);
        do {
            cout << "\nEnter Month of Booking: ";
            cin >> month;
            if ((year == 2022 && month < 12) || (month < 1 || month > 12)) {
                cout << "Enter Valid Month." << endl;
            }
        } while ((year == 2022 && month < 12) || (month < 1 || month > 12));
        do {
            cout << "\nEnter Day of Booking: ";
            cin >> day;
            if (day < 1 || day > 31) {
                cout << "Enter Valid Hour." << endl;
            }
        } while (day < 1 || day > 31);
        do {
            cout << "\nEnter Booking Hour: ";
            cin >> hour;
            if (hour < 12 || hour > 20) {
                cout << "Enter Valid Hour. (12-20)" << endl;
            }
        } while (hour < 12 || hour > 20);
        do {
            cout << "\nEnter Booking Minutes: ";
            cin >> minute;
            if (minute < 0 || minute > 60) {
                cout << "Enter Valid Minutes. (0-60)" << endl;
            }
        } while (minute < 0 || minute > 60);

        Date* d = new Date;
        Time* t = new Time;
        d->set_date(day, month, year);
        t->set_time(hour, minute);

        cust_booking->set_date(d);
        cust_booking->set_time(t);
        cust_booking->set_name(name);

        d = nullptr;
        t = nullptr;

        return cust_booking;
    }

    ~Booking() {
      
        if (date != nullptr) {
            delete date;
        }
        if (time != nullptr) {
            delete time;
        }
    }

    int pay_bill(int n,string p) {
        int amount = 0;
        amount = ps->get_price();
        cout << "Your Total Bill = " << amount << endl;
        cout << "Do you want to use award points " << endl;
        cout << "Press 1 : For Yes" << endl;
        cout << "Press 2 : For No" << endl;
        int ch = 0;
        cin >> ch;
        if (ch == 1) {
            cout << "Your Total Award Points = " << n << endl;
            cout << "How many you want Award Points you want to use? " << endl;
            int temp = 0;
            cin >> temp;
            while (temp > n) {
                cout << "Amount unavailable" << endl;
                cin >> temp;
            }

            cout << "Your Final Total Bill = " << amount - n << endl;
            n = temp - n;
            ifstream filein("customers.txt"); //File to read from
            ofstream fileout("new_customer.txt"); //Temporary file
            if (!filein || !fileout) {
                cout << "Error opening files!" << endl;
                return 1;
            }
            string tempphonenum, tempname, tempcnic, tempemail, tempap;
            while (filein.eof() == false) {
                filein >> tempphonenum >> tempname >> tempcnic >> tempemail >> tempap;
                if (tempphonenum == p) {
                    tempap = to_string(n);
                }
                fileout << tempphonenum << " " << tempname << " " << tempcnic << " " << tempemail << " " << tempap << "\n";
            }
            filein.close();
            fileout.close();
            remove("customers.txt");
            rename("new_customer.txt", "customers.txt");
            return n;
        }
        else {
            cout << "Your Final Total Bill = " << amount << endl;
            return n;
        }
    }
};

class Person {
protected:
    string Person_Name;
    string CNIC;
    string Ph_Num;
    string email;
public:
    Person() {
        Person_Name = " ";
        CNIC = " ";
        Ph_Num = " ";
        email = " ";
    }
    Person(string pname, string cnic, string pn, string em) {
        Person_Name = pname;
        CNIC = cnic;
        Ph_Num = pn;
        email = em;
    }
    void update_name(string name) {
        Person_Name = name;
    }
    void Change_Ph_Num(string n) {
        Ph_Num = (n);
    }
    string get_Ph_Num() {
        return Ph_Num;
    }
    void Update_email(string n) {
        email = n;
    }
    void Update_cnic(string n) {
        CNIC = n;
    }
    string get_name() {
        return Person_Name;
    }
    string get_email() {
        return email;
    }
    string get_cnic() {
        return CNIC;
    }
};

class Staff :public Person {
    bool available_status;
    string provided_service;
public:
    Staff() : Person() {
        available_status = false;
        provided_service = " ";
    }
    string get_name() {
        return Person_Name;
    }
    void set_service(string s) {
        provided_service = s;
    }
    string get_service() {
        return provided_service;
    }
    bool get_status() {
        return available_status;
    }
    void set_status(bool s) {
        available_status = s;
    }
    void display_info() {
        cout << "Name: " << Person_Name << endl;
        cout << "Service: " << provided_service << endl;
        cout << "Availability: " << available_status << endl;
    }
};

class Customer :public Person {

    int award_points;
    Booking* bookings;
    
public:

    Customer() {
        award_points = 0;
        bookings = nullptr;
    }

    Customer(string pname, string cnic, string pn, string em, int ap) :Person(pname, cnic, pn, em) {
        award_points = ap;
        bookings = new Booking();
    }
    Booking* make_booking() {
        return bookings->make_booking(this->Person_Name);
    }
    void set_award_Points(int n) {
        award_points = n;
    }

    void get_appointments() {
        int day, month, year, hour, minute;
        string name;
        string service;
        int count = 0;

        ifstream r_b("bookings.txt");
        while (!r_b.eof()) {
            r_b >> name;
            r_b >> service;
            r_b >> day;
            r_b >> month;
            r_b >> year;
            r_b >> hour;
            r_b >> minute;

            if (name == Person_Name) {
                cout << "\nName: " << name << endl;
                cout << "Service: " << service << endl;
                cout << "Date of Booking: " << day << " - " << month << " - " << year << endl;
                cout << "Time of Booking: " << hour << " : " << minute << endl;
                count++;
            }
        }
            if (count == 0) {
                cout << "\nYou have no Bookings." << endl;
            }
        
    }
    int get_award_points() {
        return award_points;
    }
};


class OuRDatabase {
public:
    virtual Person* Load_Ph_records(string id, int temp) = 0;
    virtual int LoadAwardPoints(string pn) = 0;
    virtual void  Load_Staff_status() = 0;
    virtual bool check_staff_status(string) = 0;
    virtual void Load_Stock_report(string n) = 0;
};
class Database :public OuRDatabase {
    Staff* Staff_status;
public:
    Database() {
        Staff_status = nullptr;
    }
    Person* Load_Ph_records(string id, int temp) {
        Person* temp1 = new Person();
        ifstream fin;
        if (temp == 1) {
            fin.open("customers.txt");

            if (fin.is_open() == false) {
                cout << "\n\n File not found\n\n";
            }
        }
        else if (temp == 2) {
            fin.open("managers.txt");
            if (fin.is_open() == false) {
                cout << "\n\n File not found\n\n";
            }
        }
        string tempphonenum, tempname, tempcnic, tempemail;

        bool status = false;;
        while (fin.eof() == false) {
            fin >> tempphonenum >> tempname >> tempcnic >> tempemail;
            if (id == tempphonenum) {
                temp1->update_name(tempname);
                temp1->Change_Ph_Num(tempphonenum);
                temp1->Update_email(tempemail);
                temp1->Update_cnic(tempcnic);
                status = true;
                break;
            }
            else {
                temp1->Change_Ph_Num("-1");
                status = false;
            }
        }
        return temp1;
    }
    int LoadAwardPoints(string pn) {
        ifstream fin;
        fin.open("awardPoints.txt");
        if (fin.is_open() == false) {
            cout << "\n\n File not found\n\n";
        }
        string tempphonenum, tempap;
        fin >> tempphonenum >> tempap;
        if (pn == (tempphonenum)) {
            return stoi(tempap);
        }
        else {
            return 0;
        }
    }
    void Load_Staff_status() {
        int i = 0;
        string buffer;
        ifstream read_info("staff.txt");
        Staff_status = new Staff[5];

        while (!read_info.eof()&&i<5) {
            getline(read_info, buffer);
            Staff_status[i].update_name(buffer);
            getline(read_info, buffer);
            if (buffer == "true") {
                Staff_status[i].set_status(true);
            }
            getline(read_info, buffer);
            Staff_status[i].set_service(buffer);
            read_info.ignore(5, '\n');
            i++;
        }
    }
    bool check_staff_status(string s) {
        string service;
        string name;
        for (int i = 0; i < 5; i++) {
            service = Staff_status[i].get_service();
            if (service == s) {
                if (Staff_status[i].get_status() == true) {
                    Staff_status[i].set_status(false);
                    name = Staff_status[i].get_name();
                    ifstream filein("staff.txt"); //File to read from
                    ofstream fileout("new_staff.txt"); //Temporary file
                    if (!filein || !fileout) {
                        cout << "Error opening files!" << endl;
                        return 1;
                    }

                    string strTemp;
                    int i = 0;
                    int j = 1;
                    //bool found = false;
                    while (filein >> strTemp) {
                        if (i == 1) {
                            strTemp = "false";
                            i = 0;
                        }
                        if (strTemp == name) {
                            strTemp = name;
                            i = 1;
                        }
                        strTemp += "\n";
                        fileout << strTemp;
                        if (j % 3 == 0) {
                            fileout << "\n";
                        }
                        j++;
                    }
                    filein.close();
                    fileout.close();
                    remove("staff.txt");
                    rename("new_staff.txt", "staff.txt");
                    return true;
                }
            }
        }
        return false;
    }
    void Load_Stock_report(string n) {
        ifstream fin;
        char ch;
        fin.open(n);

        while (fin.eof() == false) {
            fin.get(ch);
            cout << ch;
        }
        cout << endl << endl;
    }
    ~Database() {
        //delete Staff_status;
    }
};
class OuRServer {
public:
    virtual Person* Sign_In_page(int type) = 0;
    virtual bool Send_OTP() = 0;
    virtual int get_award_points_of_customer(string pn) = 0;
    virtual bool Confirm_appointment(Booking* cust_booking) = 0;
    virtual void Fetch_report(string n) = 0;
};


class server :public OuRServer {
    Database* information;
public:
    server() {
        information = new Database();
        information->Load_Staff_status();
    }
    Person* Sign_In_page(int type) {
        string phonenum;
        int x = 1;
        Person* obj;
        do {
            x = 1;
            cout << "\t\t\tInput Phone # (XXXX-XXXXXXX):\t";
            cin >> phonenum;

            obj = information->Load_Ph_records(phonenum, type);
            if (obj->get_Ph_Num() != "-1") {
                while (x == 1) {
                    cout << "\n\n\t\t\t\tEnter OTP sent\n\n";
                    bool getotp = Send_OTP();
                    if (getotp == true) {
                        cout << "Successful Login" << endl;
                        return obj;
                    }
                    else {
                        cout << "Unsuccessful Login" << endl;
                        cout << "Do you want otp to be resent or go to LogIn:" << endl;
                        cout << "Press 1 : for otp" << endl;
                        cout << "Press 2 : for log in" << endl;
                        cout << "Press 3 : for exit" << endl;
                        cin >> x;
                    }
                }
            }
            else {
                cout << "\n\n\t\t\t\tIncorrect Phone # \n\n";
                cout << "Unsuccessful Login" << endl;
                cout << "Do you want to LogIn again:" << endl;
                cout << "Press 2 : for log in" << endl;
                cout << "Press 3 : for exit" << endl;
                cin >> x;
            }
        } while (obj->get_Ph_Num() == "-1" && x == 2);
        if (x == 3) {
            return obj;
        }
        return nullptr;
    }
    bool Send_OTP() {
        int number = 0;
        number = (rand() % 9000 + 1000);
        srand(time(NULL));
        cout << "\t\t\tYour OTP for registeartion is\t" << number << "\t. Kindly reeneter the OTP to validate your login\n\n";
        int n;
        cin >> n;
        if (n == number) {
            cout << "\n\t\t\tVerifiaction complete.\n\n";
            return true;
        }
        else {
            cout << "\n\t\t\tVerification failed.\n\n";
            return false;
        }
    }
    int get_award_points_of_customer(string pn) {
        return information->LoadAwardPoints(pn);
    }
    bool Confirm_appointment(Booking* cust_booking) {
        int day, month, year, hour, minute;
        string name;
        string service;

        ifstream r_b("bookings.txt");
        while (!r_b.eof()) {
            r_b >> name;
            r_b >> service;
            r_b >> day;
            r_b >> month;
            r_b >> year;
            r_b >> hour;
            r_b >> minute;

            if (day == cust_booking->get_date() && month == cust_booking->get_month()) {
                if (hour == cust_booking->get_hour()) {
                    cout << "This Time Slot is Already Booked." << endl;
                    return false;
                }
            }
        }
        ofstream w_b("bookings.txt", ios::app);

        if (information->check_staff_status(cust_booking->get_service_name()) == true) {
            w_b << cust_booking->get_cust_name() << " " << cust_booking->get_service_name() << " " << cust_booking->get_date() << " " << cust_booking->get_month() << " " << cust_booking->get_year() << " " << cust_booking->get_hour() << " " << cust_booking->get_minutes() << endl;
            cout << "Your Bookings has been Completed.";
            cout << "\nService: " << cust_booking->get_service_name() << endl;
            cout << "Date: " << cust_booking->get_date() << " - " << cust_booking->get_month() << " - " << cust_booking->get_year() << endl;
            cout << "Time: " << cust_booking->get_hour() << " : " << cust_booking->get_minutes() << endl;
        }
        else {
            cout << "There was no Available Staff." << endl;
            return false;
        }

        w_b.close();
        r_b.close();
        return true;
    }
    void Fetch_report(string n) {
        information->Load_Stock_report(n);
    }
    ~server() {
        delete information;
    }
};

class Inventory_manager :public Person {
public:
    Inventory_manager() {
        ;
    }
    Inventory_manager(string pname, string cnic, string pn, string em) :Person(pname, cnic, pn, em) {

    }
    void allocate_stock() {
        string item;
        cout << "Input Item Name:\t";
        cin >> item;
        cout << "Input Allocated Quantity:\t";
        string q;
        cin >> q;
        ifstream filein("stockreport.txt"); //File to read from
        ofstream fileout("tempSR.txt"); //Temporary file

        if (!filein || !fileout) {
            cout << "Error opening files!" << endl;
        }

        else {

            string strTemp;
            int i = 0;
            int j = 1;

            while (filein >> strTemp) {
                if (i == 1) {
                    strTemp = q;
                    i = 0;
                }
                if (strTemp == item) {
                    strTemp = item;
                    i = 1;
                }

                strTemp += "\t";
                fileout << strTemp;
                if (j % 3 == 0) {
                    fileout << "\n";
                }
                j++;
            }
            filein.close();
            fileout.close();
            remove("stockreport.txt");
            rename("tempSR.txt", "stockreport.txt");

            fileout.close();
        }
    }
    string view_stocks_report() {
        string temp = "stockreport.txt";
        return temp;
    }
};



int welcome() {
    int type;
    cout << "------------------------------------------------" << endl;
    for (int i = 0; i < 3; i++) {
        if (i == 1)
            cout << "-             " << "WELCOME TO S&J MOTORS" << "            - " << endl;
        else
            cout << "-                                              -" << endl;
    }
    cout << "------------------------------------------------" << endl << endl;
    cout << "How would you like to proceed as:" << endl << endl;
    cout << "Press 1 for CUSTOMER" << endl;
    cout << "Press 2 for INVENTORY MANAGER" << endl;
    cin >> type;
    return type;
}
int main() {
    int type = welcome(); //shows screen. returns person;s type
    server obj;
    Person* verify;
    verify = obj.Sign_In_page(type); // goes for verification
    if (verify->get_Ph_Num() != "-1" && type == 1) {
        int ap = obj.get_award_points_of_customer(verify->get_Ph_Num());
        Customer p1(verify->get_name(), verify->get_cnic(), verify->get_Ph_Num(), verify->get_email(), ap);
        cout << "Press 1: For BOOKING" << endl;
        cout << "Press 2: For viewing all bookings " << endl;
        cout << "Press 3: To see your award points" << endl;
        cout << "Press 4: To exit" << endl;
        int ch = 0;
        cin >> ch;
        while (ch != 4) {
            if (ch == 1) {
                Booking* new_booking;
                new_booking = new Booking;
                new_booking = p1.make_booking();
               bool booked= obj.Confirm_appointment(new_booking);
               if (booked) {
                   cout << "Want to pay bill now?" << endl;
                   cout << "Press 1 : For Yes" << endl;
                   cout << "Press 2 : For No" << endl;
                   int m = 0;
                   cin >> m;
                   if (m == 1) {
                       int x=new_booking->pay_bill(p1.get_award_points(),p1.get_Ph_Num());
                       p1.set_award_Points(x);
                   }
               }
            }
            else if (ch == 2) {
                p1.get_appointments();
            }
            else if (ch == 3) {
                cout << "Award Points = " << p1.get_award_points() << endl;
            }
            cout << endl << endl;
            cout << "Press 1: For BOOKING" << endl;
            cout << "Press 2: For viewing all bookings " << endl;
            cout << "Press 3: To see your award points" << endl;
            cout << "Press 4: To exit" << endl;
            cin >> ch;
            if (ch == 4) {
                cout << "Logging Out" << endl;
            }
        }
    }
    else if (verify->get_Ph_Num() != "-1" && type == 2) {
        Inventory_manager p1(verify->get_name(), verify->get_cnic(), verify->get_Ph_Num(), verify->get_email());
        cout << "Press 1: For viewing stock report" << endl;
        cout << "Press 2: For allocating stocks " << endl;
        cout << "Press 3: To exit" << endl;
        int ch;
        cin >> ch;
        while (ch != 3) {
            if (ch == 1) {
                string n;
                n = p1.view_stocks_report();
                obj.Fetch_report(n);
            }
            else if (ch == 2) {
                string n;
                n = p1.view_stocks_report();
                obj.Fetch_report(n);
                p1.allocate_stock();
            }
            cout << "Press 1: For viewing stock report" << endl;
            cout << "Press 2: For allocating stocks " << endl;
            cout << "Press 3: To exit" << endl;
            cin >> ch;
            if (ch == 3) {
                cout<<"Logging Out" << endl;
            }
        }
    }
    else {
        cout << "Logging Out" << endl;
    }
    return 0;
}
