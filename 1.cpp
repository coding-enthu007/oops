#include<iostream> // Include the input-output stream library for using cout and endl
#include<string>   // Include the string library for using string objects
using namespace std;  // Use the standard namespace to avoid prefixing std:: before standard library names

// Define a class named Student
class Student{
private:  // Private section: members here are only accessible within this class
    string* name; // Pointer to a string object for the student's name
    int* age;    // Pointer to an int object for the student's age

public:  // Public section: members here are accessible from outside the class

    // Default constructor
    Student(){
        cout << "Default Constructor called" << endl;
        name = new string; // Allocate memory for a string object and assign it to name
        *name = "Student"; // Initialize the string object to "Student"

        age = new int; // Allocate memory for an int object and assign it to age
        *age = 0; // Initialize the int object to 0
    }

    // Parameterized constructor: initializes a Student object with specific values
    Student(string sname, int sage){
        cout << "Parameterized constructor called" << endl;
        name = new string; // Allocate memory for a string object and assign it to name
        age = new int; // Allocate memory for an int object and assign it to age
        *name = sname; // Initialize the string object with the provided name
        *age = sage; // Initialize the int object with the provided age
    }

    // Copy constructor: initializes a new object as a copy of an existing object
    Student(Student& t){
        cout << "Copy constructor called" << endl;
        age = new int; // Allocate memory for an int object and assign it to age
        name = new string; // Allocate memory for a string object and assign it to name
        *name = *t.name; // Copy the value of the string object from t's name to this object's name
        *age = *t.age; // Copy the value of the int object from t's age to this object's age
    }

    // Move constructor: transfers resources from an existing object to a new object
    Student(Student&& other) noexcept{
        cout << "Move constructor called" << endl;
        age = other.age; // Transfer ownership of age pointer from other to this object
        name = other.name; // Transfer ownership of name pointer from other to this object
        other.name = nullptr; // Set other’s name pointer to nullptr to prevent accidental use or deletion
        other.age = nullptr; // Set other’s age pointer to nullptr to prevent accidental use or deletion
    }

    // Destructor: deallocates memory when an object is destroyed
    ~Student(){
        delete name; // Free the memory allocated for the name string
        delete age; // Free the memory allocated for the age int
    }

    // Function to display the student's details
    void display(){
        cout << "This is the object of " << *name << " whose age is " << *age << endl;
    }
};

int main(){
    // Create Student objects using different constructors
    Student s("Abhay", 19); // Parameterized constructor
    Student s2("Anish", 20); // Parameterized constructor
    Student s3; // Default constructor

    // Create a new Student object as a copy of s2
    Student Anish(s2); // Copy constructor

    // Display details of each Student object
    s.display(); // Display details of the Student s
    Anish.display(); // Display details of the Student Anish 
    s3.display(); // Display details of the Student s3

    // Create a new Student object by moving resources from s
    Student newS(move(s)); // Move constructor

    // Display details of the newly created Student object
    newS.display(); // Display details of the Student newS
}
