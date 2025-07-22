// File for testing the project

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_PEOPLE = 40;
const string m_fileName = "proj_data.txt";

class Person {
public:
  Person();
  void SetDetails(string firstName, string lastName, int age, int personID);
    
  string m_fName;
  string m_lName;
  int m_age;
  int m_ID;
};


int main() {
  string details;
  string firstName;
  string personName;
  string lastName;
  string stringAge;
  string stringID;
  int age;
  int personID;
  int numPeople = 0;
  //  Person* m_roster[MAX_PEOPLE];
  int m_numRoster;
  
  // Declare and open file
  ifstream textFile (m_fileName);
  
  // Check if the file was able to be opened and ask for new file if it wasn't
  while (!textFile.is_open()) {
    cout << "Could not open file" << endl;
    cout << endl;
  }
  
  for (int i = 0; i < MAX_PEOPLE; i++) {
    // Get all the details and store them in variables
    getline(textFile, firstName, ',');
    cout << "First Name: " << firstName << endl;
    
    getline(textFile, lastName, ',');
    cout << "Last Name: " << lastName << endl;
    
    getline(textFile, stringAge, ',');
    cout << "Age: " << stringAge << endl;
    
    getline(textFile, stringID);
    cout << "ID: " << stringID << endl;

    personName = firstName;
    age = stoi(stringAge);
    personID = stoi(stringID);

    // Create a person pointer to the person object made with the variables in the roster
    Person personName;

    personName.SetDetails(firstName, lastName, age, personID);

    //m_roster[i] = firstName;
    cout << "************************************" << endl;

    cout << "First Name: " << personName.m_fName << endl;
    cout << "Last Name: " << personName.m_lName << endl;
    cout << "Age: " << personName.m_age << endl;
    cout << "ID: " << personName.m_ID << endl;
    cout << endl;
    
    numPeople++;
  }
  
  m_numRoster = numPeople;

  cout << m_numRoster << " people loaded into the roster." << endl;

  //for (int j = 0; j < MAX_PEOPLE; j++) {
  //cout << "Name: " << m_roster[j]->m_fName << endl;
  //}
  
  textFile.close();

  return 0;
}

Person::Person() {
  m_fName = "";
  m_lName = "";
  m_age = 0;
  m_ID = 0;
}

void Person::SetDetails(string firstName, string lastName, int age, int personID) {
  m_fName = firstName;
  m_lName = lastName;
  m_age = age;
  m_ID = personID;
}

