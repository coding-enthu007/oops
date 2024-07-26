#include<iostream> //preprocessor directive for input output stream library
#include<string>   //another preprocessor for including string library
using namespace std;  //The std namespace includes all the standard C++ library names. 
                      // By including this line, you don't need to prefix standard library names with std::.

class Student{  // This line defines a class named Student.
               // A class is a user-defined data type in C++ that can contain variables (attributes) and functions (methods).
private:        //This access specifier means that the members declared under it are only accessible within the class itself.
string* name;   //This line declares a private pointer to a string object named name.

int* age;    //This line declares a private pointer to an int object named age.
             //Similar to the name pointer, it stores the memory address of an int object.
public:      //This access specifier means that the members declared under it are accessible from outside the class.

Student(){      //default constructor  (no arguments)
   cout<< "Default Constructor called"<<endl; //this line allocates memory for a string object and assigns the address of this memory to the name pointer.
                                                //new string dynamically allocates memory for a string object
   name = new string;   //This line allocates memory for a string object and assigns the address of this memory to the name pointer
   *name = "Student";  //This line assigns the value "Student" to the string object that name points to.

   age = new int;   //This line allocates memory for an int object and assigns the address of this memory to the age pointer.

   *age = 00;   //This line assigns the value 0 to the int object that age points to.

}
 Student(string sname, int sage){     // parameterized constructor(The purpose of this constructor is to initialize a Student object with specific values for name and age.)
    cout<<"Paramertised constructor called"<< endl;
    name = new string;  //this line allocates memory for a string object and assigns the address of this memory to the name pointer.
    age = new int;  //This line allocates memory for an int object and assigns the address of this memory to the age pointer.
    *name = sname;  //This line assigns the value of the parameter sname to the string object that name points to.

    *age = sage;   //This line assigns the value of the parameter sage to the int object that age points to.

 };

 Student(Student& t){       // copy constructor(This defines a copy constructor for the Student class.)
                            //A copy constructor initializes a new object as a copy of an existing object
    cout<<"Copy constructor called"<< endl;
    age = new int;   //This line allocates memory for an int object and assigns the address of this memory to the age pointer.

    name = new string;   //This line allocates memory for a string object and assigns the address of this memory to the name pointer.

    *name = *t.name;      //This line copies the value of the string object pointed to by t.name into the string object pointed to by name.

    *age = *t.age;       //This line copies the value of the int object pointed to by t.age into the int object pointed to by age.

 };

 Student(Student&& other) noexcept{   //move constructor(A move constructor initializes a new object by transferring the resources from an existing object (other) to the new object.)
   cout<<"Move constructor called"<< endl;
   age = other.age;   //This line transfers the ownership of the age pointer from other to the new object.

   name = other.name;   // This line transfers the ownership of the name pointer from other to the new object.

   other.name = nullptr;  //This line sets other's name pointer to nullptr.
                          //This indicates that other no longer owns the string object, preventing other from accidentally deleting or modifying the string object.

   other.age = nullptr;  //This line sets other's age pointer to nullptr.
                          //This indicates that other no longer owns the int object, preventing other from accidentally deleting or modifying the int object
   }

   ~Student(){ //This defines the destructor for the Student class.
              //A destructor is a special member function that is called when an object of the class is destroyed.
              //The tilde (~) before the class name indicates that this is a destructor.
      delete name;  //This line deallocates the memory that was previously allocated for the name pointer.

      delete age;//This line deallocates the memory that was previously allocated for the age pointer.

   }


 void display(){   //The purpose of this function is to print the details of the Student object.

    cout<<"This is the object of "<< *name << " whose age is "<< *age<<endl;
 }
};

int main(){
    Student s("Sumaanyu",19), s2("Shreyash",20), s3;
    Student shreyash(s2);
    s.display(); // calling parameterized constructor
    shreyash.display(); // calling copy constructor
    s3.display(); // calling default constructor
    Student newS(move(s));
    newS.display();

}