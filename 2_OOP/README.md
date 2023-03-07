# Object-oriented

TODO: inline function

When we make some complex products, we always divide it into small and simple parts and assemble them finally. So does a complex program. This is what an object-oriented programming language can do, dividing a complex program into small submodule so that we can fix bug and reuse the program more easily.

# Class and Object

## Definition

Let's start with an example.

```cpp
class Box{
    public:
        // attribute
        double length;
        double breadth;
        double height; 
        // methods
        double getVolume(void);
        void set( double l, double b, double h);
};

// definition of Box's methods
double Box::get(void)
{
    return length * breadth * height;
}
 
void Box::set(double l = 1, double b = 1, double h = 1)
{
    length = l;
    breadth = b;
    height = h;
}

int main(){
    Box box;
    box.set(1, 2, 3);
    box.height = 4;

    cout << box.getVolume() << endl;

    return 0;
}
```

In the real world, if we need to define an object, we usually classify it in one class according to its characteristc firstly. So does the programming. We need to declare one class before we get an object which we want to classify it into that class.

In C++, we use `class` statement to define a class. One class consists of **name**, **attributes** and **methods**. An attribute is actually a variable and method is actually a function which are both belong to the class. In the former example, we declare a class named `Box` which has three attributes `length`, `breadth`, and `height` and two methods `getVolume` and `set`. By the way, the `public` is named **access modifier** which we will discuss later. We can define the methods in the class of out of class. In the class, we can define a method like this

```cpp
class Hello{
    public:
        void sayHello(){
            cout << "Hello!" << endl;
        }
}
```

When out of a class, we need to add the **scope resplution operator** `::` when we define the method.

```cpp
class Hello{
    public:
        void sayHello();
}

void Hello::sayHello(){
    cout << "Hello!" << endl;
}
```

We can define an object by calling the class name and setting the object name.

```cup
Box box1;
box1.set(1, 2, 3);
Box box2;
box2.set(4, 5, 6);
```

Then we get an object named `box1` and `box2` and they belong to class `Box`. This means the `box1` and `box2` objects have all the attributes and methods that `Box` has. But the specific values can differ through different objects.

## Calling

An object's attributes and methods can be called by object's name with **dot operator** followed. In the original example, we have called the `box`'s attribute and method.

```cpp
box.set(1, 2, 3);
box.height = 4;

cout << box.getVolume() << endl;
```

# Access Operator

**Data encapsulation** is one of the siginificant feature of OOP. That means we can encapulate important or private data in a class, so other programs can not access it directly.

We can change a member's access in a class by **access modifier**. There are three kinds of access modifier in C++: `public`, `private`, `protected`.

## public

A public member is accessible out of a class. For example

```cpp
class Line{
    public:
        double length;
        void setLength(double l){
            length = l;
        }
}

int main(){
    Line line;
    line.setLength(1.0);
    cout << "The line's length is " << line.length << endl;
    line.length = 2.0;
    cout << "The line's length is " << line.length << endl;

    return 0;
}
```

This program will get this result after compiled.

```
The line's length is 1.0
The line's length is 2.0
```

This means we can directly access the public member out of a class and modify it.

## private

A private member is not accessible out of a class. Only the class's methods or **friend function** can access it. If one class member is defined without any **access modifier**, it will be **defaultly regarded private**. For example

```cpp
class Line{
    private:
        double length;
    public:
        void setLength(double l){
            length = l;
        }
        double getLength(){
            return length;
        }
}

int main(){
    Line line;
    line.setLength(1.0);
    cout << "The line's length is " << line.getLength() << endl;

    return 0;
}
```

In the former example, if we try to access `line.length` directly, an error will appear.

## protected

The access modifier `protected` is mainly used in **inheritting** which we will discuss later.

# Constructor and Destructor

## Constructor

**Constructor** is a special method of a class. Whenever an object is created, the constructor will be called. For instance

```cpp
#include <iostream>
 
using namespace std;
 
class Line{
   public:
      void setLength( double len );
      double getLength( void );
      Line();  // Constructor
 
   private:
      double length;
};
 
// The definition of the constructor.
Line::Line(void){
    cout << "Object is being created" << endl;
}
 
void Line::setLength( double len ){
    length = len;
}
 
double Line::getLength( void ){
    return length;
}

int main( ){
   Line line;
 
   line.setLength(6.0); 
   cout << "Length of line : " << line.getLength() <<endl;
 
   return 0;
}
```

**Notice the constructor has no type**.The above program will get this result after compiled.

```
Object is being created
Length of line : 6
```

The constructor can be defined with parameters. That means if you create an object, you need to give the parameters the constructor needs. For instance

```cpp
class Line{
   public:
      void setLength( double len );
      double getLength( void );
      Line(double len);  // Constructor
 
   private:
      double length;
};

// The definition of the constructor
Line::Line( double len){
    cout << "Object is being created, length = " << len << endl;
    length = len;       // Use the parameter to initialize
}
 
void Line::setLength( double len ){
    length = len;
}
 
double Line::getLength( void ){
    return length;
}

int main( ){
   Line line(10.0);
   
   cout << "Length of line : " << line.getLength() <<endl;
   line.setLength(6.0); 
   cout << "Length of line : " << line.getLength() <<endl;
 
   return 0;
}
```

The above program will get this result after compiled.

```
Object is being created, length = 10
Length of line : 10
Length of line : 6
```

Also, we can use **initialization list** to declare a constructor.

```cpp
C::C( double a, double b, double c): X(a), Y(b), Z(c){
  …
}
```

The above program is equal to:

```cpp
C::C(double a, double b, double c){
    X = a;
    Y = b;
    Z = c;
    …
}
```

### Polymorphic Constructor

The constructor could be polymorphic just like other functions or methods. For instance

```cpp
class Line{
   public:
      void setLength( double len );
      double getLength( void );
      Line(double len);  // Constructor
      Line(int len);
 
   private:
      double length;
};

// The definition of the constructor
Line::Line( double len){
    cout << "Object is being created, length = " << len << endl;
    length = len;
}

// Reloading the constructor
Line::Line( int len){
    cout << "Object is being created, length = " << len << endl;
    length = (double)len;
}
…
```

By reloading the constructor, we can create an object by transmitting an integer.

### Copy Constructor

One of the useful situation for polymorphic constructor is **copy constructor**. For instance

```cpp
class Line{
   public:
      void setLength( double len );
      double getLength( void );
      Line(double len);  // Constructor
      Line(Line &l);
 
   private:
      double length;
};

Line::Line( double len){
    length = len;
}

Line::Line( Line &l){
    cout << “Copy constructor is called. ” << endl;
    length = l.length;
}

void func(Line a){
    return;
}

int main(){
    Line a(5.0);
    Line b(a);
    Line c = a;
    
    func(a);
    
    return 0;
}
```

The above program will get this result after compiled.

```
Copy constructor is called.
Copy constructor is called.
Copy constructor is called.
```

The line `Line b(a)` and `Line c = a` are two ways to call the copy constructor. **Notice that only when we initializing an object, we can use `=` to call the copy constructor**. Otherwise, we need to reload the `=` operator.

The last situation is that if we transmit an object as a **formal parameter** to a function, the copy constructor will be called, too. And **if we haven’t defined a copy constructor, the compiler will define it automatically**.

## Destructor

**Destructor** is another special method, which will be called whenever an object is deleted or the program ends. For instance

```cpp
#include <iostream>
 
using namespace std;
 
class Line{
   public:
      void setLength( double len );
      double getLength( void );
      Line();
      ~Line();  // Destructor
 
   private:
      double length;
};

Line::Line(void){
    cout << "Object is being created" << endl;
}
// The definition of the destructor
Line::~Line(void){
    cout << "Object is being deleted" << endl;
}
 
void Line::setLength( double len ){
    length = len;
}
 
double Line::getLength( void ){
    return length;
}

int main( ){
   Line line;
   
   line.setLength(6.0); 
   cout << "Length of line : " << line.getLength() <<endl;
 
   return 0;
}
```

The above program will get this result after compiled.

```
Object is being created
Length of line : 6
Object is being deleted
```

# Friend Function

A friend function is a function **declared in a class** but **defined out of the class**, and a friend function **can access the class’s private member**. For instance

```cpp
#include <iostream>
 
using namespace std;
 
class Line{
   public:
      void setLength( double len );
      friend void printLength(Line l);
 
   private:
      double length;
};

void Line::setLength(double len){
    length = len;
}

void printLength(Line l){
    // access the private member of l
    cout << “The length of the line is: ” << l.length << endl;
}

int main(){
    Line a;
    
    a.setLength(10.0);
    
    printLength(a);
    
    return 0;
}
```