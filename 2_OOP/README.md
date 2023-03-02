# Object-oriented

When we make some complex products, we always divide it into small and simple parts and assemble them finally. So does a complex program. This is what an object-oriented programming language can do, dividing a complex program into small submodule so that we can fix bug and reuse the program more easily.

# Class and Object

## Definition

Let's start with an example.

```c++
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

```c++
class Hello{
    public:
        void sayHello(){
            cout << "Hello!" << endl;
        }
}
```

When out of a class, we need to add the **scope resplution operator** `::` when we define the method.

```c++
class Hello{
    public:
        void sayHello();
}

void Hello::sayHello(){
    cout << "Hello!" << endl;
}
```

We can define an object by calling the class name and setting the object name.

```c++
Box box1;
box1.set(1, 2, 3);
Box box2;
box2.set(4, 5, 6);
```

Then we get an object named `box1` and `box2` and they belong to class `Box`. This means the `box1` and `box2` objects have all the attributes and methods that `Box` has. But the specific values can differ through different objects.

## Calling

An object's attributes and methods can be called by object's name with **dot operator** followed. In the original example, we have called the `box`'s attribute and method.

```c++
box.set(1, 2, 3);
box.height = 4;

cout << box.getVolume() << endl;
```

# Access Operator

**Data encapsulation** is one of the siginificant feature of OOP. That means we can encapulate important or private data in a class, so other programs can not access it directly.

We can change a member's access in a class by **access modifier**. There are three kinds of access modifier in C++: `public`, `private`, `protected`.

## public

A public member is accessible out of a class. For example

```c++
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

```c++
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
