# C++ Grammar

- [C++ Grammar](#c-grammar)
- [1 Foreword](#1-foreword)

# 1 Foreword

C++ is an object-oriented programming (OOP) language, whereas C is a procedure-oriented programming (POP) language, which makes C++ easiler to realize some complex projects. Since C++ is designed to try its best to be compatible with C's grammar meanwhile add new characteristics to work as as an OPP language, C++ is usually recognized as a **superset** of C.

Also, with the plenty of similarilies in grammar between C and C++, in this tutorial, I will only notice the differences and new characteristics in C++ from C. So, I recommand you read my [C tutorial](https://github.com/EnkiduGilgamesh/C-Tutorial) before you read this.

# 2 Example

```cpp
#include <iostream>

using namespace std;

int main(){
    cout << "Hello World!" << endl;

    return 0;
}
```

The head file which is different from C language, countains the standard input and output stream. In C++, when using standard, we should remove the ".h" suffix. We can still use the library in C, just removing the ".h" suffix and add "c" at the beginning of the file name.

TODO: The namespace means

# 3 cin and cout

In C++, there is an easier way to input and output, which is `cin` and `cout` functions. They can be used like this

```cpp
#include <iostream>

using namespace std;

int main(){
    int a;
    cin >> a;
    string b = "number";
    cout << a << " is a " << b << endl;

    return 0;
}
```

The functions `cin` and `cout` can automatically recognize the variable's type. Function `cin` need to use with the `>>` which is called stream input operator; and `cout` need to use with the `<<` which is called stream output operator. By the way, C++ provides `string` type to help us handle strings.

The `cin` will terminate when it meets the `space`, `tab` and `wrapping around`. Furthermore, the `cin` is more slower than the `scanf` in C language, the same as the `cout` and `printf`.

To get `space` character, we can use `getline` function. There are tow kinds of getline

```cpp
getline(cin, string s);             //include string.h firstly
cin.getline(char* s, int length);
```

The first function in `string.h` will input a whole line string. The second function will get a maximum equal to $length - 1$(the other one for `null` terminator) `char` array.

By the way, the `endl` means "end the line", which behaves like a wrapping around. But it will meanwhile empty the buffer, which is different from the placeholder `\n`.

# 4 Data type

C++ adds some new data type to help programmer code easier.

## 4.1 bool

One of the most important data type is boolean. C++ finally defines this data type.

```cpp
bool sys = true;
```

The value of a bool variable can be only `true` and `false`, in other word `1` and `0`. And a bool variable only places **1 byte** which is more less than an integer.

## 4.2 string

C++ not only supports the C style string, but also provides a built-in `string` type.

A strinhg also ends with `\0`. In C++, we can easily get a string's length like this

```cpp
string s = "David";
cout << "The length of s is " << s.length() << endl;
```

And the string is easily to assign value, too.

```cpp
string s1 = "Sam";
string s2 = s1;
s1 = "David";
```

Two strings can be simply catenated by operator `+`.

```cpp
string s3 = s1 + s1;
```

# 5 Function

The usage of function in C++ is very similar with C. But there are some important and useful characteristics in C++.

## 5.1 Reloading

In C, we cannot define two functions with a same name. Whereas, in C++, a function is identified not only by its name, but also by its parameters. For instance

```cpp
#include <iostream>

using namespace std;

int add(int a);
int add(int a, int b);
int add(int a, int b, int c);

int main(){
    int a, b, c, res;
    cin >> a >> b >> c;
    res = add(a);
    cout << "The result of a+1 is " << res << endl;
    res = add(a, b);
    cout << "The result of a+1 is " << res << endl;
    res = add(a, b, c);
    cout << "The result of a+1 is " << res << endl;

    return 0;
}

int add(int a){
    return ++a;
}

int add(int a, int b){
    return a + b;
}

int add(int a, int b, int c){
    return a + b + c;
}
```

## 5.2 Quotation

In C, if we need to modify a variable in function and use the modified one, we need to pass the argument's address to it, which makes us watch out when defining function and passing arguments. In C++, we can simply define a function using arguments's quotation. For instance

```cpp
#include <iostream>

using namespace std;

void increasing(int& a);                // add a & before the parameter

int main(){
    int a = 0;
    for(int i = 0; i < 10; i++){
        increasing(a);
        cout << a << endl;
    }

    return 0;
}

void increasing(int& a){
    a++;
}
```

TODO: object-oriented programming (OOP)

# 9 new and delete

In C, we use `malloc` and `free` to dynamically distribute and free space. In C++, we can more easily do it through `new` and `delete`.

We can use `new` and `delete` to distribute space and free space for an array.

```cpp
int * a = new int[5];
delete []a;
```

We can also use `new` and `delete` to distribute space and free space for an object.

```cpp
class A {...}
A *obj = new A();
delete obj;
```

When we use `new` to create a class, the constructor of the class will be called **after** the space is distributed, whereas when we use `free`to free a class, the destructor of the class will be called **before** the space is freed.
