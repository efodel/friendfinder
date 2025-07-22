//******************************************************************
// Name:    Person.cpp
// Author:  Eric Fodel
// Date:    10/2/21
//
// Desc:    This file contains the driver code for the methods of
//          the Person class. Overall, this file will be used to
//          display details about the person and manage their
//          friend list.
//
//******************************************************************

#include "Person.h" 

// Name: Person
// Desc - Default Constructor for a Person
// Preconditions - Creates a Person with no data associated with it
// Postconditions - a Person is created
Person::Person() {
  m_fName = "";
  m_lName = "";
  m_age = 0;
  m_ID = 0;
  m_friendCount = 0;
}

// Name: Person
// Desc - Overloaded Constructor for a Person
// Preconditions - Creates a Person with passed data
// Postconditions - a Person is created
Person::Person(string firstName, string lastName, int age, int personID) {
  SetDetails(firstName, lastName, age, personID);
}

// Name: AddFriend
// Desc - A person pointer is stored from the roster of people in an organization
// Preconditions - A person pointer is passed
// Postconditions - A person pointer is added to this person's m_friend's array
//                  if not at maximum and not already in the array
void Person::AddFriend(Person* newFriend) {
  bool existingID = false;
  string friendName;

  // Check if ID of passed person is equal to any ID in the list by calling CheckID
  for (int i = 0; i < m_friendCount; i++) {
    if (m_friends[i] != NULL) {

      // Set the boolean to true if CheckID returns true
      if (CheckID(newFriend->m_ID)) {
	existingID = true;
      }
    }
  }

  // If ID wasn't in the list and there are not max friends, add the friean to m_friends
  if ((!existingID) && (m_friendCount < MAX_FRIENDS)) {
    m_friends[m_friendCount] = newFriend;
    m_friendCount++;
    cout << "You are now friends with " << newFriend->m_fName << "!" << endl;
  }

  // Check if the max number of friends caused it to not add the friend
  else if (m_friendCount == MAX_FRIENDS) {
    cout << "You have reached the max number of friends (" << MAX_FRIENDS << ")" << endl;
  }

  // Check if the friend was already in m_friends
  else if (existingID) {
    cout << "You are already friends with " << newFriend->m_fName << endl;
  }

  cout << endl;
}

// Name: RemoveFriend
// Desc - Removes a person pointer from this person's m_friend array
// Preconditions - Person pointer exists in m_friend
// Postconditions - Person is removed from m_friend and all pointers are moved towards front
void Person::RemoveFriend() {
  int removeFriend;
  int friendIndex;
  int listFormat = 1;

  // Display friends list and ask who is being removed
  DisplayFriends();

  cout << "Who would you like to remove?" << endl;
  cin >> removeFriend;

  // Validate input
  while ((removeFriend > m_friendCount) or (removeFriend < listFormat)) {
    cout << "That number is not in the list of friends" << endl;
    cout << endl;
    cout << "Who would you like to remove?" << endl;
    cin >> removeFriend;
  }

  // Use friendIndex to store the real index of the friend from the formatted list number
  friendIndex = removeFriend - listFormat;

  cout << "You have removed " << m_friends[friendIndex]->m_fName << " from your friends" << endl;

  // Starting at the given index, shift every element in the list until the next element is 'NULL'
  for (int i = friendIndex; i < m_friendCount; i++) {
    if (m_friends[i + listFormat] != NULL) {
      m_friends[i] = m_friends[i + listFormat];
    }
    // When the final element of the list is reached set it to 'NULL'
    else {
      m_friends[i] = NULL;
    }
  }

  // Extra whitespace and remove from m_friendCount
  cout << endl;
  m_friendCount--;
}

// Name: CheckID
// Desc - Checks to see if a specific person ID exists in m_friends - Note: IDs will always be unique in proj2
// Preconditions - m_friends is populated
// Postconditions - Returns true if id exists in m_friends else false
bool Person::CheckID(int personID) {
  bool correctID = false;

  // Check if the passed ID is equal to any in the list and set the boolean accordingly
  for (int j = 0; j < m_friendCount; j++) {
    if (m_friends[j] != NULL) {
      if (m_friends[j]->m_ID == personID) {
	correctID = true;
      }
    }
  }

  // Return the boolean that was either changed or not
  return correctID;
}

// Name: DisplayFriends
// Desc - Displays information about each friend in the m_friend array
// Preconditions - People are in the m_friend array
// Postconditions - Displays information about person object in array
void Person::DisplayFriends() {
  int noFriends = MAX_FRIENDS;
  int listFormat = 1;

  cout << "Friend List for " << m_fName << ":" << endl;

  // Format the list properly and display each friend with DisplayDetails() and subract from noFriends
  for (int i = 0; i < m_friendCount; i++) {
    if (m_friends[i] != NULL) {
      cout << (i + listFormat) << ".";
      m_friends[i]->DisplayDetails();
      noFriends--;
    }  
  }

  // Check if there are no friends using the noFriends counter
  if (noFriends == MAX_FRIENDS) {
    cout << "You don't have any friends yet." << endl;
  }

  cout << endl;
}

// Name: DisplayDetails
// Desc - Displays information about this person
// Preconditions - Person data is populated
// Postconditions - Displays information about person object
void Person::DisplayDetails() {
  cout << " " << m_fName << " " << m_lName << " ";
  cout << "(" << m_age << " yrs) " << m_ID << endl;
}

// Name: SetDetails
// Desc - Used as a setter for first name, last name, age, and id
// Preconditions - Person already created
// Postconditions - Member variables populated
void Person::SetDetails(string firstName, string lastName, int age, int personID) {
  m_fName = firstName;
  m_lName = lastName;

  if (age > 0) {
    m_age = age;
  }

  if (personID >= 0) {
    m_ID = personID;
  }
}
