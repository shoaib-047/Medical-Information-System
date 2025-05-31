#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Signup function
void signup(string &name, string &password, string &confPassword, string &dish) {
    cout << "Enter the admin detail for signup:\n";
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your password: ";
    cin >> password;
    do {
        cout << "Now enter your confirm password:";
        cin >> confPassword;
        if (password == confPassword) {
            cout << "What is your favourite dish:";
            cin >> dish;
            cout << "Sign-up successfully\n";
            break;
        } else {
            cout << "Entered confirm password is wrong. Please try again later\n";
        }
    } while (true);
}
void addNursingStaff(){
	int numberOfNurses;
	string nName,nDutyShift;
	cout<<"Enter the number of nurses in hospital you want to add:";
	cin>> numberOfNurses;
	ofstream outFile("nurses.txt", ios::app);
	 if (!outFile) {
        cout << "Error occurred while adding the doctors details\n";
        return;
    }
     
     for (int i = 0; i < numberOfNurses; i++) {
    cout<<" Add detail for nurse number:"<< i+1 <<endl;
        cout << "Enter the nurse's name: ";
        cin >> nName;
        cout << "Enter the nurse's shift time: ";
        cin >> nDutyShift;
                 }
    outFile.close();
    cout << "Patient details saved to file successfully.\n";
}
void addDoctor(){
	int numberOfDoctors;
	string dName,dSpecialization,dTimeDuration,dSalary;
	int dPatientHandle;
	cout<<"Enter the number of doctors in hospital you want to add:";
	cin>> numberOfDoctors;
	ofstream outFile("doctors.txt", ios::app);
	 if (!outFile) {
        cout << "Error occurred while adding the doctors details\n";
        return;
    }
    
    for (int i = 0; i < numberOfDoctors; i++) {
    cout<<" Add detail for doctor number:"<< i+1 <<endl;
        cout << "Enter the doctor's name: ";
        cin >> dName;
        cout << "Enter the doctor's specialization: ";
        cin >> dSpecialization;
        cout << "Enter the doctor's time duration in hospital: ";
        cin >> dTimeDuration;
        cout << "Enter the doctor's salary: ";
        cin >> dSalary;
        cout << "How many patients doctor handle in a day: ";
        cin >> dPatientHandle; 
		outFile << dName << "\n"
                << dSpecialization << "\n"
                << dTimeDuration << "\n"
                << dSalary << "\n"
                << dPatientHandle << "\n";
    }
    outFile.close();
    cout << "Patient details saved to file successfully.\n";
} 
           
void addAppointment() {
    int numberOfPatients;
    string pName, pFatherName, pGender, pMedicalHistory, pConsultDoc, pTest, pPhoneNumber, pAppointmentDate;
    int pAge, pTokenNumber, pTime;
    double pDob, pCNIC;
    const int lengthPN = 11; 
    char choice;

    cout << "Enter the number of patients you want to add: ";
    cin >> numberOfPatients;m

    ofstream outFile("patients.txt", ios::app); 
    if (!outFile) {
        cout << "Error occurred while adding the patient details\n";
        return;
    }

    for (int i = 0; i < numberOfPatients; i++) {
        cout << "Add details for patient number: " << i + 1 << endl;
        cout << "Enter the patient's name: ";
        cin >> pName;
        cout << "Enter the patient's father's name: ";
        cin >> pFatherName;
        cout << "Enter the patient's date of birth: ";
        cin >> pDob;
        cout << "Enter the patient's gender: ";
        cin >> pGender;
        cout << "Enter the patient's age: ";
        cin >> pAge;
        cout << "Enter the patient's CNIC: ";
        cin >> pCNIC;

        do {
            cout << "Please enter the PHONE number with dash(-): ";
            cin >> pPhoneNumber;
            if (pPhoneNumber.length() == lengthPN) {
                cout << "Your phone number is correct.\n";
                break;
            } else if (pPhoneNumber.length() > lengthPN) {
                cout << "Your phone number has more digits than required.\n";
            } else {
                cout << "Your phone number has fewer digits than required.\n";
            }
            cout << "Would you like to re-enter the phone number? (Y/y for yes, any other key for no): ";
            cin >> choice;
        } while (choice == 'Y' || choice == 'y');

        cout << "Enter the patient's appointment date: ";
        cin >> pAppointmentDate;
        cout << "Enter the patient's medical history: ";
        cin >> pMedicalHistory;
        cout << "Enter the patient's consultant doctor: ";
        cin >> pConsultDoc;
        cout << "Enter the patient's test name: ";
        cin >> pTest;
        cout << "Enter the patient's token number: ";
        cin >> pTokenNumber;
        cout << "Enter the patient's approaching time: ";
        cin >> pTime;

        // Save details to the file
        outFile << pName << "\n"
                << pFatherName << "\n"
                << pDob << "\n"
                << pGender << "\n"
                << pAge << "\n"
                << pCNIC << "\n"
                << pPhoneNumber << "\n"
                << pAppointmentDate << "\n"
                << pMedicalHistory << "\n"
                << pConsultDoc << "\n"
                << pTest << "\n"
                << pTokenNumber << "\n"
                << pTime << "\n";
    }

    outFile.close();
    cout << "Patient details saved to file successfully.\n";
}

void viewNursingStaff(){
		ifstream inFile("Nurse.txt");
	if (!inFile) {
        cout << "Error: Unable to open the file or no nurse records found.\n";
        return;
    }
    cout << "Nurse Records:\n";
    cout << "====================\n";
     
    int numberOfNurses;
	string nName,nDutyShift;
	bool recordsExist = false;
while (inFile >> nName >> nDutyShift){
	recordsExist = true;
        cout << "Nurse Name: " << nName << "\n";
        cout << "Nurse duty shift: " << nDutyShift << "\n";
        cout << "------------------------\n";
    }
    
    if (!recordsExist) {
        cout << "No nurse records found in the file.\n";
    }
    
    inFile.close();	
}
void viewDoctor(){
	ifstream inFile("Doctor.txt");
	if (!inFile) {
        cout << "Error: Unable to open the file or no doctor records found.\n";
        return;
    }
     cout << "Doctor Records:\n";
    cout << "====================\n";
    
    int numberOfDoctors;
	string dName,dSpecialization,dTimeDuration,dSalary;
	int dPatientHandle;
	bool recordsExist = false;
while (inFile >> dName >> dSpecialization >> dTimeDuration >> dSalary >> dPatientHandle){
	   recordsExist = true;
        cout << "Doctor Name: " << dName << "\n";
        cout << "Doctor specialization: " << dSpecialization << "\n";
        cout << "Doctor time duration: " << dSpecialization << "\n";
        cout << "Doctor total salary: " <<  dSalary << "\n";
        cout << "Doctor handle patient in a day: " << dPatientHandle << "\n"; 
        cout << "------------------------\n";
    }
    
    if (!recordsExist) {
        cout << "No doctor records found in the file.\n";
    }
    
    inFile.close();	
}
void viewAppointments() {
    ifstream inFile("Appointment.txt");
	if (!inFile) {
        cout << "Error: Unable to open the file or no appointment records found.\n";
        return;
    }
     cout << "Appointment Records:\n";
    cout << "====================\n";
    
    int numberOfPatients;
	string pName, pFatherName,pGender, pAppointmentDate,pMedicalHistory,pConsultDoc,pTest,pPhoneNumber;
    int pAge,pTokenNumber,pTime;
    double pDob,pCNIC; 
    bool recordsExist = false;
    
while (inFile >> pName >> pFatherName >> pDob >> pGender >> pAge >> pTokenNumber >> pCNIC >> pTime >> pPhoneNumber >>  pAppointmentDate >> pMedicalHistory >> pConsultDoc >> pTest){
        recordsExist = true;
        cout << "Patient Name: " << pName << "\n";
        cout << "Father's Name: " << pFatherName << "\n";
        cout << "Date of birth: " << pDob << "\n";
        cout << "Gender: " << pGender << "\n";
        cout << "Age: " << pAge << "\n";
        cout << "CNIC: " << pCNIC << "\n";
        cout << "Phone Number: " << pPhoneNumber << "\n";
        cout << " Patient Appointment Date " <<  pAppointmentDate << "\n";
        cout << "Consultant Doctor: " << pConsultDoc << "\n";
        cout << "patient medical Test: " << pTest << "\n";
        cout << "------------------------\n";
    }
    
    if (!recordsExist) {
        cout << "No patient records found in the file.\n";
    }
    
    inFile.close();
}
void viewPatients() {
    ifstream inFile("Patients.txt"); // Open the file for reading
    if (!inFile) {
        cout << "Error: Unable to open the file or no patient records found.\n";
        return;
    }

    cout << "Patient Records:\n";
    cout << "====================\n";

    string pName, pFatherName,pGender,pMedicalHistory,pConsultDoc,pTest;
    int pAge;
    double pDob,pCNIC, pPhoneNumber;
    bool recordsExist = false;

    while (inFile >> pName >> pFatherName >> pDob >> pGender >> pAge >> pCNIC >> pPhoneNumber >> pMedicalHistory >> pConsultDoc >> pTest) {
        recordsExist = true;
        cout << "Patient Name: " << pName << "\n";
        cout << "Father's Name: " << pFatherName << "\n";
        cout << "Date of birth: " << pDob << "\n";
        cout << "Gender: " << pGender << "\n";
        cout << "Age: " << pAge << "\n";
        cout << "CNIC: " << pCNIC << "\n";
        cout << "Phone Number: " << pPhoneNumber << "\n";
        cout << "Consultant Doctor: " << pConsultDoc << "\n";
        cout << "patient medical Test: " << pTest << "\n";
        cout << "------------------------\n";
    }

    if (!recordsExist) {
        cout << "No patient records found in the file.\n";
    }

    inFile.close();
}

// Add patient details
void addPatient() {
    int numberOfPatients;
    string pName, pFatherName,pGender,pMedicalHistory,pConsultDoc,pTest;
    int pAge;
    double pDob;
	string pCNIC,pPhoneNumber;
    const int lengthPN = 12; 
    const int lengthCNIC = 15;
    char choice;

    cout << "Enter the number of patients you want to add:";
    cin >> numberOfPatients;

    ofstream outFile("patients.txt", ios::app); // Open in append mode
    if (!outFile) {
        cout << "Error occurred while adding the patient details\n";
        return;
    }

    for (int i = 0; i < numberOfPatients; i++) {
    	cout<<" Add detail for patient number:"<< i+1 <<endl;
        cout << "Enter the patient's name: ";
        cin >> pName;
        cout << "Enter the patient's father's name: ";
        cin >> pFatherName;
        cout << "Enter the patient's date of birth with coma and space,: ";
        cin >> pDob;
         cout << "Enter the patient's gender: ";
        cin >> pGender;
        cout << "Enter the patient's age: ";
        cin >> pAge;
        do {
            cout << "Please Enter the CNIC of patient with dashes(-): ";
            cin >> pCNIC;
            if (pCNIC.length() == lengthCNIC) {
                cout << "Your CNIC ID is correct.\n";
                break;
            }
            if (pCNIC.length() < lengthCNIC) {
                cout << "Your CNIC has fewer digits than required (13 digits including dashes).\n";
            } else {
                cout << "Your CNIC has more digits than required (13 digits including dashes).\n";
            }
            cout << "Would you like to re-enter the CNIC? (Y/y for yes, any other key for no): ";
            cin >> choice;
            cin.ignore();  // clear the newline character left by previous input
        } while (choice == 'Y' || choice == 'y');
        do {
            cout << "Please enter the PHONE number with dash(-): ";
            cin >> pPhoneNumber;
            if (pPhoneNumber.length() == lengthPN) {
                cout << "Your phone number is correct.\n";
                break;
            } else if (pPhoneNumber.length() > lengthPN) {
                cout << "Your phone number has more digits than required.\n";
            } else {
                cout << "Your phone number has fewer digits than required.\n";
            }
            cout << "Would you like to re-enter the phone number? (Y/y for yes, any other key for no): ";
            cin >> choice;
        } while (choice == 'Y' || choice == 'y');
        cout << "Enter the patient's Medical History: ";
        cin >> pMedicalHistory;
        cout << "Enter the patient's consultant doctor: ";
        cin >> pConsultDoc;
        cout << "Enter the patient's test name: ";
        cin >> pTest;



        // Save patient details to file
        outFile << pName << "\n"
                << pFatherName << "\n"
                << pDob << "\n"
                << pGender << "\n"
                << pAge << "\n"
                << pCNIC << "\n"
                << pPhoneNumber << "\n"
				<< pMedicalHistory << "\n"
				<< pConsultDoc << "\n"
				<< pTest << "\n";
    }
    outFile.close();
    cout << "Patient details saved to file successfully.\n";
}
// Provide choices
void provideChoice() {
    int choice;
    do{
    cout << "If you want to perform an operation, press a number:\n";
    cout << "1. Add patients detail\n";
    cout << "2. view patient detail\n";
    cout << "3. Add doctors detail\n";
    cout << "4. view doctor detail\n";
    cout << "5. add nursing detail\n";
    cout << "6. view nursing detail\n";
    cout << "7. Add patients appointment detail\n";
    cout << "8. view patient appointment detail\n";
    cout << "9. Exit\n";
    cin >> choice;

    switch (choice) {
    case 1:
        addPatient();
        break;
    case 2:
        viewPatients();
        break;
    case 3:
        addDoctor();
        break;
    case 4:
        viewDoctor();
        break;
    case 5:
        addNursingStaff();
        break;
    case 6:
        viewNursingStaff();
        break;
    case 7:
        addAppointment();
        break;
    case 8:
        viewAppointments();
        break;
    case 9:
    cout << "Exiting...\n";
        break;
    default:
        cout << "Invalid choice!\n";
    }
       } while (true);
}

// Login function
void login(const string &name, const string &password) {
    string logName, logPassword;
    do {
        cout << "To login, enter your name:";
        cin >> logName;
        cout << "Enter your password:";
        cin >> logPassword;
        if (logName == name && logPassword == password) {
            cout << "Login successfully\n";
            cout<<"============= WELCOME TO MEDICAL INFORMATON SYSTEN =============="<<endl;
            provideChoice(); // Call the choice menu
            break;
        } else {
            cout << "Entered name or password is incorrect. Try again\n";
        }
    } while (true);
}

// Forget password
void forgPassword(string &password, const string &dish, string &confPassword) {
    string dish2;
    cout << "Now enter your favourite dish:";
    cin >> dish2;
    while (dish2 == dish) {
        cout << "Enter your new password:";
        cin >> password;
        cout << "Confirm your new password:";
        cin >> confPassword;
        if (confPassword == password) {
            cout << "Password is updated successfully\n";
            break;
        } else {
            cout << "Entered password or confirm password is wrong. Try again\n";
        }
    }
}

// Main function
int main() {
    int choice;
    string name, password, confPassword, dish;

    do {
        cout << "Enter a number you want to perform between 1 to 4:\n";
        cout << "1. Signup\n";
        cout << "2. Login\n";
        cout << "3. Forget Password\n";
        cout << "4. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            signup(name, password, confPassword, dish);
            break;
        case 2:
            login(name, password);
            break;
        case 3:
            forgPassword(password, dish, confPassword);
            break;
        case 4:
            exit(0); // Exit the program
        default:
            cout << "Invalid choice! Please try again\n";
        }
    } while (choice != 4);

    return 0;
}

