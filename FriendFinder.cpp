//******************************************************************
// Name:    FriendFinder.cpp
// Author:  Eric Fodel
// Date:    10/2/21
//
// Desc:    This file contains the definitions for the FriendFinder
//          class methods. Overall, contains the driver code for
//          the FriendFinder program using the Person and
//          Organization classes.
//
//******************************************************************


#include "FriendFinder.h"


// Name: FriendFinder
// Desc - Default constructor for application for finding friends
// Preconditions - Creates a Person and an organization
// Postconditions - Welcomes user and calls Start()
FriendFinder::FriendFinder() {
  Person m_me;
  Organization m_organization;
  Start();
}

// Name: GetDetails
// Desc - Asks user for their first name, last name, age, and ID to populate m_me
// Preconditions - None
// Postconditions - Populates information related to m_me
void FriendFinder::GetDetails() {
  string firstName;
  string lastName;
  int age;
  int personID;

  // Ask for all the person details and validate each input that can be validated
  cout << "What is your first name?" << endl;
  cin >> firstName;

  cout << "What is your last name?" << endl;
  cin >> lastName;

  cout << "What is your age?" << endl;
  cin >> age;
  
  while (age <= 0) {
    cout << "Please enter your age:" << endl;
    cin >> age;
  }

  cout << "What is your ID?" << endl;
  cin >> personID;

  while (personID < 0) {
    cout << "Please enter your ID:" << endl;
    cin >> personID;
  }

  // Set the details of m_me using the given inputs
  m_me.SetDetails(firstName, lastName, age, personID);

  cout << endl;
}

// Name: DisplayMenu
// Desc - Displays main menu for application
// Preconditions - None
// Postconditions - Called from Start updates integer passed
void FriendFinder::DisplayMenu(int &choice) {
  int currentChoice;
  
  cout << "What would you like to do?" << endl;
  
  cout << "1. Display Entire Organization" << endl;
  cout << "2. Display Friend List" << endl;
  cout << "3. Search for a Friend" << endl;
  cout << "4. Remove Friend" << endl;
  cout << "5. Exit" << endl;

  cin >> currentChoice;
  choice = currentChoice;

  cout << endl;
}

// Name: Start
// Desc - Main function running FriendFinder
//        Calls GetDetails
//        Populates data for organization
//        Continually calls DisplayMenu until someone enters 5 (exit)
// Preconditions - m_me and m_organization are created but not populated
// Postconditions - Runs until user enters 5. Thanks user for usage. Ends application
void FriendFinder::Start() {
  int choice = 0;
  const int END_CHOICE = 5;

  // Format the program
  cout << endl;
  cout << "*****************************" << endl;
  cout << "Welcome to UMBC Friend Finder" << endl;
  cout << "*****************************" << endl;
  cout << endl << endl;

  // Get details of person and organization
  GetDetails();
  m_organization.SetName();
  m_organization.LoadRoster();
  
  // Run a switch statement for the menu and use a do-while loop to repeat
  do {
    switch (choice) {
    case 1:
      m_organization.DisplayRoster();

      break;

    case 2:
      m_me.DisplayFriends();

      break;

    case 3:
      m_me.AddFriend(m_organization.GetPerson());

      break;

    case 4:
      m_me.RemoveFriend();

      break;

    default:
      break;
    }

    DisplayMenu(choice);

  } while (choice != END_CHOICE);

  cout << "Thank you for using UMBC Friend Finder!" << endl;
}
