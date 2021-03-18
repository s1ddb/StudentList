#include <iostream>
#include <vector>


/* 
Siddhartha Bobba
03/18/2021

A student list program to allow the user to keep track of all the students added, their gpas, and IDs. Student List allows the user to add new students to the list and print all of them out for a database and also delete when required. QUIT function to exit out of the program.

*/


using namespace std;

struct Student {//a struct object to hold data on every student

  char* firstname;
  char* lastname;
  int id; //ID of the student
  float gpa; //gpa of the student

};

void addStudent(vector<Student*>*vvv);
void printStudent(vector<Student*>*nowdefined);
  
 


int main() {



    bool IsRunning = true; //boolean to check if the program is running or not, used in loop
    char input[10]; //gets user input to see what command or action they want to perform
    int DELinput = 0; //gets user input for what student ID has to be deleted
    int num = 0; //used in DELETE
      
    vector<Student*>*list = new vector<Student*>();



    while (IsRunning == true) { // while the program / code is running

	  cout << "What would you like to do?" << endl;
	  cout << endl;
	  cout << "ADD" << endl << "PRINT" << endl << "DELETE" << endl << "QUIT" << endl; //gives user the options
	  cout <<endl; //space
	  cout << "Please select from the above commands and enter:" << endl; //asks to enter

	  cin.get(input, 10);
	  cin.ignore();


	  

	  if (input[0] == 'A' && input[1] == 'D' && input[2] == 'D') { //if the first input matches 'ADD', run add student function

	    addStudent(list);
   
	  }

	  if (input[0] == 'P' && input[1] == 'R' && input[2] == 'I' && input[3] == 'N' && input[4] == 'T') {
	    
	    //what to do here
	    for(vector<Student*>::iterator it = list->begin(); it != list->end(); ++it) {

		cout << (*it)->firstname << " " << (*it)->lastname << ", " << (*it)->id << ", "; // prints out the first name last name and ID
		cout.precision(2); //sets precision of the decimal float to 2
		cout << (*it)->gpa << endl; //prints gpa

	    }

	  }

   	  if (input[0] == 'D' && input[1] == 'E' && input[2] == 'L' && input[3] == 'E' && input[4] == 'T' && input[5] == 'E') {

	    cout << "Enter the ID of the student you'd like to delete: " << endl; /// asks for the student ID
	    cin >> DELinput; //gets input from user
	    cin.get();
	    num = 0;

	    for (vector<Student*>::iterator it = list->begin(); it != list->end(); ++it) {
	      if((*it)->id == DELinput) {

		delete(*it);
		list->erase(it); //delete, end of iterator
		break;
	      }
	    }
	  }
	  
	  if (input[0] == 'Q' && input[1] == 'U' && input[2] == 'I' && input[3] == 'T') {

	    cout << "Terminating program..." << endl;
	    IsRunning = false; // Ends code, ends while loop

	  }

	}






  return 0;
}







void addStudent(vector<Student*>*vvv) {


  Student*NewS= new Student(); //makes a memory location for all the variables inside of student

  //first name
  
  char*first = new char[20]; //allocates memory space for a new char to the memory location of first

  cout << "Enter a first name:" << endl;
  cin >> first;

  NewS->firstname = first; //sets the firstname to whatever is inside first after being read in by the cin in the previous line

  //last name

  char*last = new char[20]; //allocates memory space for a new char to the memory location of last
  
  cout << "Enter the last name:" << endl;
  cin >> last; //gets last name
  NewS->lastname = last;
				    

  // id

  cout << "What's the ID of the student? :" << endl;				    
  cin >> NewS->id; //read in user input for id into the memory location of id inside of the struct student

  //gpa

  cout << "Enter the gpa: " << endl;
  cin >> NewS->gpa; //read in the user input for gpa into the memory location of gpa inside the struct student
  cin.ignore();

  //----
  
  vvv->push_back(NewS); //adds vector
  
  


}



void printStudent(vector<Student*>*nowdefined) {


  for(vector<Student*>::iterator it= nowdefined -> begin(); it!= nowdefined -> end(); ++it) {

    cout << (*it)->firstname << endl; //takes the first name from memory location and prints
    cout << (*it)->lastname << endl; //take the last name from memory location and prints
    cout << (*it)->id << endl; //takes the id from the memory location and prints
    cout << (*it)->gpa << endl; //takes the gpa from the memory location and prints
  }

}
