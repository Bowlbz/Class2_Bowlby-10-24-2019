/*
	Input Validation with Ref Functions 
	A cleaner way to do input validation
	Validating input, an essential process.
	Source: http://stackoverflow.com/questions/514420/how-to-validate-numeric-input-c
	Keeping Dr. McMillan from breaking my code, defend against "dark side of the force",
	and/or legitimate user error. 
	//Try and Catch blocks are used in error checking
	Teacher: Dr. Tyson McMillan 
*/
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream>  // Provides cout, cerr, endl
#include "Input_Validation_Extended.h" // Provides getValidatedInput<T>(), a header File with a Template Class
                              // Extended 2-11-2016 by Dr. McMillan to add validation methods by datatype
#include<string> //for string manipulation
#include<sstream> //for string manipulation and comparison
using namespace std;



class GreenTea
{

    private:
      bool delicious;
      string nameTea;
    public:
      GreenTea() // default constructor = given intial values to member variables
      {
        delicious = true;
        nameTea = "DrT Brand Default";
        cout << "\nWhat's up, I was called -Default Constructor. " << endl;
      }
      void setDelicious(bool d) { delicious = d; } // Definition inside the Class on one line. Acceptable
      void setnameTea(string nt) { nameTea = nt; } //this sets the definition without writing it at the bottom.
      bool getdelicious() const { return delicious; }
      string getName() const { return nameTea; }
      void showGreenTea()
      {
        cout << "\nTEA INFORMATION: " << endl;
        cout << "Name: " << nameTea << endl;
        
        string face = " ";

        face = (delicious == true) ? " :-) " : " :'( "; // 1 line if statement
        cout << face << endl;
        
      }
      
};

class Student
{
    private:
      int id;
      string name;
      char letterGrade;
      GreenTea preference; //Must Declare and define before using inside another Class: "GreenTea"

    public:
      Student() //default constructor *****
      {
        id = 0;
        name = "Default Student Name";
        letterGrade = 'F';
        preference.setDelicious(false); //need "set" to access private "members"
        preference.setnameTea("Matcha"); //need "set" to access private "members"
        cout << "\nThe Student Default Constructor was called. " << endl;
      }

      void setID (int i) { id = i; }
      void setName (string n) { name = n; }
      void setletterGrade (char lg) { letterGrade = lg; }
      void setpreference(GreenTea p) { preference = p; }
      int getId() const { return id; }
      string getName() const { return name; }
      char getletterGrade() const { return letterGrade; }
      GreenTea getpreference() const { return preference; }
      void showStudent() //print the current data stored in the Student on-demand
      {
        cout << "STUDENT CURRENT DATA" << endl;
        cout << "NAME : " << name << endl;
        cout << "ID = " << id << endl;
        cout << "LETTER GRADE (currently): " << letterGrade;
        //DR T: a one liner to show both variable in preference ************
        preference.showGreenTea(); //print all preference details **********
        
      }
      void setGrade() //updating input in a class
      {
        char newGrade = '\0';
        cout << "\nPlease enter a new grade: ";
        cin >> newGrade; // asks on the screen **********
        setletterGrade (newGrade); //set the letter grade ********
        //print the latest results *****
        //showStudent(); *** commented out to avoid double outputs
      }
      
};




int main()
{
  GreenTea gt;
  Student undergrad;
  
  
  //showMenu();

  cout << gt.getName() << endl; //gets the default set information, located in "public"
  gt.showGreenTea(); //shows all data for GreenTea
  cout << "\n";

  undergrad.showStudent(); //shows all data for Student: .showStudent displays all this information *****!!!!!
  //using an object to populate the values of another object ********************
  cout << "\n" << endl;
  undergrad.setpreference(gt); // using another object to insert data *************
  undergrad.showStudent();
  /////
  undergrad.setGrade();
  undergrad.showStudent();


  //Dr.T Challenges to Expand this program
  //Keep everthing above: note it and "understand it"
  
  /*
  start creating a menu to update the student items
  do while option != 4
  print the undergrad latest details at the top of the loop
  clear the screen after update data (be careful) show latest data
  -Option 1 = setGrade() //call this
  -Option 2 = setStudentName()
  -Option 3 = setGreenTeaName()
  -Option 4 = setpreference() to from false to true or vice versa
  -Option 5 = Exit 
  */

  






    return 0;
}

void showMenu()
      {
        cout << "\nPlease Select the Option you would like to Update: ";
        cout << "1.) Grade " << endl;
        cout << "2.) Student Name " << endl;
        cout << "3.) Green Tea Name " << endl;
        cout << "4.) Preference " << endl;
        cout << "5.) Exit " << endl;
      }
