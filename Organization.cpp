//******************************************************************
// Name:    Organization.cpp
// Author:  Eric Fodel
// Date:    10/2/21
//
// Desc:    This file contains the definitions for the methods of
//          the Organization class. Overall, the class gathers
//          information for the organization and loads in the roster
//          from a text file. It will also be able to get a person
//          from m_roster.
//
//******************************************************************

#include "Organization.h"

// Name: Organization
// Desc - Default constructor for Organization
// Preconditions - None
// Postconditions - Organization is created (empty) with 0 people in the roster
Organization::Organization() {
  m_name = "";
  m_fileName = FILE_NAME;
  m_numRoster = 0;  

}

// Name: SetName
// Desc - Sets m_name by asking user for name
// Preconditions - m_name exists
// Postconditions - Asks user for the organization name and populates m_name
void Organization:: SetName() {
  cout << "What is the name of your organization?" << endl;
  cin >> m_name;
}

// Name: LoadRoster
// Desc - Sets m_fileName by asking user. Then populates all of the people loaded from file
// Preconditions - m_fileName exists. m_roster empty
// Postconditions - Asks user for m_fileName. Loads data from file and populates m_roster
void Organization::LoadRoster() {
  string personName;
  string firstName;
  string lastName;
  string stringAge;
  string stringID;
  int age;
  int personID;
  int numPeople = 0;

  cout << "Enter the file you would like to load:" << endl;
  cin >> m_fileName;

  // Declare and open file
  ifstream textFile (m_fileName);

  // Check if the file was able to be opened and ask for new file if it wasn't
  while (!textFile.is_open()) {
    cout << "Could not open file" << endl;
    cout << endl;
    cout << "Please enter a valid text file to load:" << endl;
    cin >> m_fileName;
  }
  
  for (int i = 0; i < MAX_PEOPLE; i++) {
    // Get all the details and store them in variables
    getline(textFile, firstName, ',');
    getline(textFile, lastName, ',');
    getline(textFile, stringAge, ',');
    getline(textFile, stringID);

    personName = firstName;
    age = stoi(stringAge);
    personID = stoi(stringID);
    
    // Create a person pointer to the person object made with the variables in the roster 
    Person personName(firstName, lastName, age, personID);

    // Add the person that was created to the m_roster array and increment to the number of people
    m_roster[i] = personName;
    numPeople++;
  }
  
  // Display how many people were loaded in
  m_numRoster = numPeople;
  
  cout << m_numRoster << " people loaded into the roster" << endl;
  cout << endl;

  textFile.close();
}

// Name: DisplayRoster
// Desc - Displays a numbered list of everyone in the roster (starts at 1)
// Preconditions - m_roster is populated
// Postconditions - Displays a numbered list of people
void Organization::DisplayRoster() {
  int listFormat = 1;

  // Format the name of the roster and the list of people properly
  cout << "****" << m_name << "****" << endl;
  
  for (int i = 0; i < MAX_PEOPLE; i++) {
    cout << (i + listFormat) << " ";
    m_roster[i].DisplayDetails();
  }

  cout << endl;
}

// Name: GetPerson
// Desc - Displays a list of people in m_roster and user enters number of desired person.
//        Returns pointer of that person in m_roster
// Preconditions - m_roster is populated
// Postconditions - Returns pointer for the person chosen from list
Person* Organization::GetPerson() {
  int listNum;
  int listFormat = 1;

  // Display the roster then ask who the user wants to friend
  DisplayRoster();

  cout << "Who would you like to friend?" << endl;
  cin >> listNum;

  // Validate input
  while ((listNum > MAX_PEOPLE) or (listNum < listFormat)) {
    cout << "That number is not on the list" << endl;
    cout << endl;
    cout << "Who would you like to friend?" << endl;
    cin >> listNum;
  }
  
  // Return the correct person in the roster accounting for the format of the list
  return &m_roster[listNum - listFormat];
}
