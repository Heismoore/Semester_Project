#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

class Appointment {
	private:
		int id,doc_id,pat_id;
		string time;
		string date;
	
	public:
		Appointment() {
			id = rand();
		}
		string getTime() {
			return time;
		} 
		
		int getDoc() {
			return doc_id;
		}
			int getPat() {
			return pat_id;
		}
			int getId() {
			return id;
		} 
		string getDate() {
			return date;
		}
		
		void setTime(string n) {
			time = n;
		}
		
		void setDoc(int n) {
			doc_id = n;
		}
			void setPat(int n) {
			pat_id = n;
		}
		
		void setDate(string n) {
			date = n;
		}
		
		void display() {
			cout << "|" << left << setw(10) << id << "|" << left << setw(20) << doc_id << "|" << left << setw(20) << pat_id << "|" << left << setw(12) << date << "|" << left << setw(8) << time
				 << "|" << endl;
		}
};

class Admissions {
	private:
		int id;
		int age;
		string nhis;
		string name;
		string time;
		string date;
	
	public:
		Admissions() {
			id = rand();
		}
		
		string getTime() {
			return time;
		} 
		
		string getName() {
			return name;
		}
		
		int getAge() {
			return age;
		}

		int getId() {
			return id;
		}

		string getNHIS() {
			return nhis;
		}
				
		string getDate() {
			return date;
		}
		
		void setTime(string n) {
			time = n;
		}
		
		void setName(string n) {
			name = n;
		}
		
		void setDate(string n) {
			date = n;
		}
		
		void setAge(int n) {
			age = n;
		}

		void setNHIS(string n) {
			nhis = n;
		}
		
		void display() {
			cout << "|" << left << setw(10) << id << "|" << left << setw(20) << name << "|" << left << setw(20) << nhis << "|" << left << setw(12) << date << "|" << left << setw(8) << time<< "|" << endl;
		}
};

class Staff {
	private:
		int id;
		int age;
		string name;
		string spec;
		float money;
	
	public:
		Staff() {
			id = rand();
		}
		
		string getName() {
			return name;
		}
		
		int getAge() {
			return age;
		}

		int getId() {
			return id;
		}

		string getSpec() {
			return spec;
		}
				
		float getSalary() {
			return money;
		}
		
		void setSalary(float n) {
			money = n;
		}
		
		void setName(string n) {
			name = n;
		}
		
		void setSpec(string n) {
			spec = n;
		}
		
		void setAge(int n) {
			age = n;
		}
		
		void display() {
			cout << "|" << left << setw(10) << id << "|" << left << setw(20) << name << "|" << left << setw(20) << age << "|" << left << setw(12) << spec << "|" << left << setw(8) << "GHS " << money<< "|" << endl;
		}
};
      
class Medical {
	private:
		int id,doc_id,pat_id;
		string time;
		string date, description;
	
	public:
		Medical() {
			id = rand();
		}
		string getTime() {
			return time;
		} 
		
		int getDoc() {
			return doc_id;
		}
			int getPat() {
			return pat_id;
		}
		  	string getDescription() {
			return description;
		} 
		
			int getId() {
			return id;
		} 
		string getDate() {
			return date;
		}
		
		void setTime(string n) {
			time = n;
		}
		
		void setDoc(int n) {
			doc_id = n;
		}
			void setPat(int n) {
			pat_id = n;
		}
		 	
		void setDescription(string n) {
			description = n;
		}
		
		void setDate(string n) {
			date = n;
		}
		
		void display() {
			cout << "|" << left << setw(20) << id << "|" << left << setw(10) << doc_id << "|" << left << setw(10) << pat_id <<  "|" << left << setw(14) << date <<"|" << left << setw(12) << time<< "|" << left << setw(28) << description
				 << "|" << endl;
		}
};


int main()
{
	Appointment app[100];
	Admissions adm[100];
	Staff staff[100];
	Medical med[100];
    bool authenticated = false;
    string defaultUsername = "@Heights"; // Default username
    string username;
    string pin = "Clinic"; // Default password
    string password, name, time, date, nhis, spec, description;
    float money;
    int age, id, n_app = 0, n_adm = 0, n_staff = 0,n_med=0,n_bill=0;
    bool run = true;
    int option;

    cout << "THE HEIGHTS HOSPITAL \n\n";


    while (run)
    {
        for (int x = 0; x < 3; x++)
        {
            cout << "Enter Username: " << endl;
            cin >> username;
            cout << "Enter Login password: " << endl;
            cin >> password;

            if (password == pin && username == defaultUsername)
            { // Compare username too
                authenticated = true;
                break;
            }
            else if (password == "0")
            {
                run = false;
                break;
            }
            else
            {
                if (x == 2)
                {
                    run = false;
                }
                else
                {
                    cout << "INCORRECT CREDENTIALS !!!\n\n"
                         << "Retry" << endl;
                }
            }
        }

        while (authenticated)
        {

            cout << "\n\n1. Patient Management\n";
            cout << "2. Staff Management\n";
            cout << "3. Appointment Management\n";
            cout << "4. Medical Records\n";
            cout << "0. Logout\n";
            cout << "\n\n";

            cin >> option;

            if (option == 0)
            {
                authenticated = false;
            }
            else if (option == 1)
            {
                cout << "\n1. ADMIT PATIENT\n";
                cout << "2. DISPLAY Patients\n";

                cin >> option;

                switch (option)
                {
                case 1:
                    cout << "\nPATIENT NAME: " << endl;
                    cin.ignore();       // To clear the newline left in the buffer
                    getline(cin, name); // Allowing spaces in patient name
                    adm[n_adm].setName(name);

                    cout << "\nAGE: " << endl;
                    cin >> age;
                    adm[n_adm].setAge(age);

                    cout << "\nREPORTED TIME: " << endl;
                    cin >> time;
                    adm[n_adm].setTime(time);
                    
                    cout << "\nREPORTED DATE: " << endl;
                    cin >> date;
                    adm[n_adm].setDate(date);

                    cout << "\nNHIS ID: " << endl;
                    cin >> nhis;
                    adm[n_adm].setNHIS(nhis);

                    cout << "\nPATIENT HAS BEEN ADDED SUCCESSFULLY\n";

                    cout << "PATIENT ID IS: " << adm[n_adm].getId() << endl;
                    n_adm++;
                    break;

                case 2:
                    cout << "|" << left << setw(10) << "ID" << "|" << left << setw(20) << "NAME" << "|" << left << setw(20) << "NHIS" << "|" << left << setw(12) << "DATE" << "|" << left << setw(8) << "TIME"
						 << "|" << endl << "|--------------------------------------------------------------------------|" << endl;
						 
					for (int i = 0; i < n_adm; i++) {
						adm[i].display();
					}
                    break;

                default:
                    cout << "Invalid option\n";
                }
            }
            else if (option == 2)
            {
                cout << "\n1. ADD STAFF\n";
                cout << "2. DISPLAY STAFF\n";

                cin >> option;

                switch (option)
                {
                case 1:
                    cout << "\nSTAFF NAME: ";
                    cin.ignore();       // To clear the newline left in the buffer
                    getline(cin, name); // Allowing spaces in staff name
                    staff[n_staff].setName(name);

                    cout << "\nAGE: ";
                    cin >> age;
                    staff[n_staff].setAge(age);
                    
                    cout << "\nSPECIALIZATION: \n";
                    cin >> spec;
                    staff[n_staff].setSpec(spec);

                    cout << "\nSALARY: \n";
                    cin >> money;
                    staff[n_staff].setSalary(money);
                    

                    cout << "\nSTAFF HAS BEEN ADDED SUCCESSFULLY\n";

                    cout << "YOUR ID IS: " << staff[n_staff].getId() << endl;
                    n_staff++;
                    break;

                case 2:
                	cout << "|" << left << setw(18) << "ID" << "|" << left << setw(10) << "NAME" << "|" << left << setw(20) << "AGE" << "|" << left << setw(12) << "SPECIALITY" << "|" << left << setw(8) << "SALARY"
						 << "|" << endl << "|-------------------------------------------------------------------------|" << endl;
						 
					for (int i = 0; i < n_staff; i++) {
						staff[i].display();
					}
                    break;

                default:
                    cout << "Invalid option\n";
                    break;
                }
            }
            else if (option == 3)
            {
                cout << "\n1. ADD APPOINTMENT\n";
                cout << "2. DISPLAY APPOINTMENTS\n";

                cin >> option;

                switch (option)
                {
                case 1:
                    cout << "Enter patient's ID: " << endl;
                    cin >> id;
                    app[n_app].setPat(id);
                     
                    cout << "Enter doctor's ID: " << endl;
                    cin >> id;
                    app[n_app].setDoc(id);

                    cout << "Enter appointment date: " << endl;
                    cin >> date;
                    app[n_app].setDate(date); 

                    cout << "Enter appointment time: " << endl;
                    cin >> time;
                    app[n_app].setTime(time); 

                    cout << "Appointment added successfully!" << endl;
                    cout<< "The id is "<<app[n_app].getId()<<endl;
					n_app++;
					break;
                    
         
                case 2:
                   	cout << "|" << left << setw(10) << "ID" << "|" << left << setw(20) << "DOC ID" << "|" << left << setw(20) << "PATIENT ID"<< "|" << left << setw(12) << "DATE" << "|" << left << setw(8) << "TIME"
						 << "|" << endl << "|--------------------------------------------------------------------------|" << endl;
						 
					for (int i = 0; i < n_app; i++) {
						app[i].display();
					}
                    break;

                    

                default:
                    cout << "Invalid option" << endl;
                }
            }

            else if (option == 4)
            {
                cout << "\n1. ADD MEDICAL RECORD\n";
                cout << "2. DISPLAY MEDICAL RECORDS\n";

                cin >> option;

                switch (option)
                {
                case 1:
                   cout << "Enter patient's ID: " << endl;
                    cin >> id;
                    med[n_med].setPat(id);
                     
                    cout << "Enter doctor's ID: " << endl;
                    cin >> id;
                    med[n_med].setDoc(id);

                    cout << "Enter date: " << endl;
                    cin >> date;
                    med[n_med].setDate(date); 

                    cout << "Enter time: " << endl;
                    cin >> time;
                    med[n_med].setTime(time); 

                    cout<< "Enter medical description: "<<endl;
                    cin.ignore();
				    getline(cin,description);
                    med[n_med].setDescription(description);
				
					
					cout << "Medical record added successfully!" << endl;
                    cout<< "The id is "<<med[n_med].getId()<<endl;
					n_med++;
					break;

                case 2:
                   
                    	cout << "|" << left << setw(20) << "MEDICAL RECORD ID" << "|" << left << setw(10) << "DOC ID" << "|" << left << setw(10) << "PATIENT ID"<< "|" << left << setw(14) << "DATE" << "|" << left << setw(12) << "TIME"<<"|" << left << setw(28) << "DESCRIPTION" 
						 << "|" << endl << "|---------------------------------------------------------------------------------------------------|" << endl;
						 
					for (int i = 0; i < n_med; i++) {
						med[i].display();
					}
                    break;
                   
                   
                default:
                    cout << "Invalid option";
                    break;
                }
            } else if (option == 0) {
            	authenticated = false;
			}
            
        }
    }

   
   
   
   
    return 0;
}
