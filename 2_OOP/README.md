# Object-oriented

[TOC]

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

We can define an object by calling the class name and setting the object name. This step is called **instantiation**.

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

# This Pointer

Every object has a pointer named `this` which points itself. Through `this` pointer, we can access the object’s own methods. For instance

```cpp
#include <iostream>
 
using namespace std;
 
class Box
{
   public:
      Box(double l=2.0, double b=2.0, double h=2.0)
      {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
      }
      double Volume()
      {
         return length * breadth * height;
      }
      int compare(Box box)
      {
         // use this pointer to access the Volume() method
         return this->Volume() > box.Volume();
      }
   private:
      double length;            // Length of a box
      double breadth;           // Breadth of a box
      double height;            // Height of a box
};
 
int main(void)
{
   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2
 
   if(Box1.compare(Box2))
   {
      cout << "Box2 is smaller than Box1" <<endl;
   }
   else
   {
      cout << "Box2 is equal to or larger than Box1" <<endl;
   }
   return 0;
}
```

Notice that friend functions cannot be accessed through `this` pointer because they are not the classes’ methods.

# Static

## Static Member

If a class member is **static**, that means all the objects belong to this class share this member. In other words, a `static` member is unique which is different from common members. In addition, a `static` member can be called through not only objects’ name, but also the class’ name. For instance

```cpp
#include <iostream>
 
using namespace std;
 
class Line{
   static objCnt;
   public:
      Line(double l){
        objCnt++;
        length = l;
      }
      ~Line(){
        objCnt—-;
      }
   private:
      double length;
};

Line::objCnt = 0;

int main(){
    Line l1(1.0);
    Line l2(2.0);
    
    // call the objCnt by class name
    cout << “Total number of lines is: ” << Line::objCnt << endl;
    
    delete(l2);
    
    cout << “Total number of lines is: ” << l2.objCnt << endl;
    
    return 0;
}
```

Notice that `static` member can only be initialized out of the class. And it will **be initialized by `0` by default**.

## Static Function

A `static` function has no `this` pointer. It also **can be accessed by the class name**. Moreover, it can only access the `static` members of the class. For instance

```cpp
#include <iostream>
 
using namespace std;
 
class Line{
   static objCnt;
   static getObjCnt(){
      return objCnt;
   }
   public:
      Line(double l){
        objCnt++;
        length = l;
      }
      ~Line(){
        objCnt—-;
      }
   private:
      double length;
};

Line::objCnt = 0;

int main(){
    Line l1(1.0);
    Line l2(2.0);
    
    cout << “Total number of lines is: ” << Line::getObjCnt() << endl;
    
    delete l2;
    
    cout << “Total number of lines is: ” << l2.getObjCnt() << endl;
    
    return 0;
}
```

# Inheritance

**Inheritance** is an important characteristic of OOP which allows us define a class through another class, so the new class will have a part of the existing class’ members and methods. Let’s draw an analogy:

```cpp
// base class
class Animal {
    void eat();
    void sleep();
};

// derived class
class Dog : public Animal {
    void bark() 函数
};
```

In the above program, the class `Dog` inherits from class `Animal`, so a `Dog` can do eating and sleeping like all `Animal`. But not all `Animal` can bark. The `Dog` is called **subclass** or **derived class**, and the `Animal` is called **superclass** or **base class**.

## Access Operator

Now we can turn back to see what is the characteristic of **protected** members. A protected member is **accessible in the class or the class' subclass** but not accessible beyond the two situations.

When inheriting, we also need to confirm the **access operator**. Different kinds of inheritance can make the access properties of the superclass different. The members in superclass with different access properties may be changed in different inheritance way. The situations are showed in the latter table:

|  | superclass public | superclass protected |
| --- | --- | --- |
| inheritance public | public | protected |
| inheritance private | private | private |
| inheritance protected | protected | protected |

The **private** members in superclass cannot be directly accessed by subclass. But subclass can call the superclass' methods to indirectly access them.

A program is given to help understand inheritance

```cpp
#include <iostream>

using namespace std;
 
// base class
class Shape {
   public:
      void setWidth(int w){
         width = w;
      }
      void setHeight(int h){
         height = h;
      }
   protected:
      int width;
      int height;
};
 
// derived class
class Rectangle: public Shape{
   public:
      int getArea(){ 
         return (width * height); 
      }
};
 
int main(void){
   Rectangle Rect;
 
   Rect.setWidth(5);
   Rect.setHeight(7);
 
   // output the rectangle's area
   cout << "Total area: " << Rect.getArea() << endl;
 
   return 0;
}
```

In addition, the **constructor**, **destructor**, **friend function** and **reloaded operator** won't be inherited in any situations.

## Multiple Inheritance

Multiple inheritance allows one derived class inherits multiple base classes so that it can obtain all the base classes' characteristics. For instance

```cpp
#include <iostream>
 
using namespace std;
 
// Base Class Shape
class Shape 
{
   public:
      void setWidth(int w){
         width = w;
      }
      void setHeight(int h){
         height = h;
      }
   protected:
      int width;
      int height;
};
 
// Base Class PaintCost
class PaintCost 
{
   public:
      int getCost(int area){
         return area * 70;
      }
};
 
// Derived Class
class Rectangle: public Shape, public PaintCost{
   public:
      int getArea(){ 
         return (width * height); 
      }
};
 
int main(void){
   Rectangle Rect;
   int area;
 
   Rect.setWidth(5);
   Rect.setHeight(7);
 
   area = Rect.getArea();
   
   // Output the area
   cout << "Total area: " << Rect.getArea() << endl;
 
   // Output the cost
   cout << "Total paint cost: $" << Rect.getCost(area) << endl;
 
   return 0;
}
```

# Operator Reloading

In C++, we can redefine most of the operators. They are:

| Type | Operator |
| --- | --- |
| Unary | `+`, `-`, `*`, `&` |


TODO: operator reload

# Abstract Class

If a method in base class is meaningless whereas necessary in derived class. We can declare a **virtual function**. For instance

```cpp
class Shape{
   public:
      // virtual function
      virtual double getArea() = 0;
   protected:
      double width;
      double height;
};
```

A virtual function doesn't need to be defined in base class but **must be defined in derived class**, otherwise errors will appear. If a class has at least one virtual function, it is called **abstract class**. Abstract classes are often used to normalize the behavior of the derived class, and **cannot be directly instanced**. For instance

```cpp
class Rect : public Shape{
    public:
        Shape(double w, double h){
            width = w;
            height = h;
        }
        double getArea(){
            return width * height;
        }
}
```

Notice that the definition of a virtual function in subclass should be **the same with the superclass in return type, parameters list**.