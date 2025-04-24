
/*************************************************************************
** Author : Abueita Elias
** Program : hw5
** Date Created : April 24, 2025
** Date Last Modified : April 24, 2025

** Problem:
implements a linked list that holds profile object. it stores president info. opens text file, reads, searches, deletes and also displays the information.
*************************************************************************/


#include <iostream>
#include <fstream>
#include <sstream>
#include "classes.h"

using namespace std;

template<class T>
void MyList<T>::insertHead(const T& theData) {
    head = new Node<T>(theData, head);
}
template<class T>
T MyList<T>::deleteHead() {
  if (head == NULL) {
    cout << "Empty list!" << endl;
  }
  Node<T>*temp=head;
  T data = temp->getData();
  head = head->getLink();
  delete temp;
  return data;
}

template<class T>
bool MyList<T>::search(T& target){
    Node<T>* temp = head;
    while (temp != NULL) {
      if (temp->getData() == target) {
        return true;
      }
      temp = temp->getLink();
    }
return false;
  };
template<class T>
void MyList<T>::display() const{
    Node<T>* temp = head;
    while (temp != NULL) {
      cout << temp->getData() << endl;
      temp = temp->getLink();
    }
};



struct Profile
{
  string fullname;
  string state;
  bool operator==(const Profile& rhs) const
  {return fullname==rhs.fullname; }

  bool operator!=(const Profile& rhs) const
  {return fullname!=rhs.fullname; }

};

ostream& operator<< (ostream &out, const Profile &user)
{
  out << user.fullname<<"--" <<user.state;
  return out;
}


int main() {
  MyList<Profile> pMyList;
  Profile temp;
  string line;


  ifstream file("/Users/eliasabueita/CLionProjects/HW5/presidentsWstates.txt");
  if (file.is_open()) {

    while (getline(file, line)) {

      stringstream ss(line);
      getline(ss, temp.fullname, ',');
      getline(ss, temp.state);

      pMyList.insertHead(temp);
    }
  }

  cout<<"Printing the profiles in the list: "<<endl;
  pMyList.display();

  temp.fullname ="John Adams";
  if (pMyList.search(temp)) {
    cout<<"I was able to find: " <<temp<< "in the File"<<endl;}
  else {
    cout<<"I wasn't able to find: "<<temp<< "in the File"<<endl;
  }

  Profile deleted = pMyList.deleteHead();
  cout << "Deleted head: " << deleted << endl;
  cout << "List after deletion:" << endl;
  pMyList.display();

  return 0;
}

