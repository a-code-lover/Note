1.NULL:macro definition of a null pointer, in c++11 standard, we use nullptr.
  #define NULL 0 or #define NULL (void*)0 , in fact the 0 has different meanings depending on the context in which its used.

##2.class initialization
as soon as a class has some constructor taking any number of parameters explicitly declared, the compiler no longer provides an implicit default constructor, and no longer allows the declaration of new objects of that class without arguments.(http://www.cplusplus.com/doc/tutorial/classes2/)
![class initialization](Rsc/c++_class_initialize1)
![class initialization](Rsc/c++_class_initialize)
<!--what, why can't add an extension filename -->

##3.struct and union for class
>Classes can be defined not only with keyword class, but also with keywords struct and union.

>The keyword struct, generally used to declare plain data structures, can also be used to declare classes that have member functions, with the same syntax as with keyword class. The only difference between both is that members of classes declared with the keyword struct have public access by default, while members of classes declared with the keyword class have private access by default. For all other purposes both keywords are equivalent in this context.

>Conversely, the concept of unions is different from that of classes declared with struct and class, since unions only store one data member at a time, but nevertheless they are also classes and can thus also hold member functions. The default access in union classes is public.

##4.compilation error and runtime error 

##5.operator overload
Operators are overloaded by means of operator functions, which are regular functions with special names.

```c++

class CVector {
  public:
    int x,y;
    CVector () {};
    CVector (int a,int b) : x(a), y(b) {}
    CVector operator + (const CVector&);
};

CVector CVector::operator+ (const CVector& param) {
  CVector temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
  return temp;
}
//But some operators can also be overloaded as non-member functions.
CVector operator+ (const CVector& lhs, const CVector& rhs) {
  CVector temp;
  temp.x = lhs.x + rhs.x;
  temp.y = lhs.y + rhs.y;
  return temp;
}

c = a + b;
c = a.operator+ (b);

```

##6.static
In fact, static members have the same properties as non-member variables but they enjoy class scope. For that reason, and to avoid them to be declared several times, they cannot be initialized directly in the class, but need to be initialized somewhere outside it.
Because member functions are like non-member functions, they cannot access non-static members of the class (neither member variables nor member functions). They neither can use the keyword this.

##7.const object
>const objects are limited to access only member functions marked as const, but non-const objects are not restricted and thus can access both const and non-const member functions alike.

>When an object of a class is qualified as a const object:const MyClass myobject;
The access to its data members from outside the class is restricted to read-only, as if all its data members were const for those accessing them from outside the class. Note though, that the constructor is still called and is allowed to initialize and modify these data members:

```c++
int get() const {return x;}        // const member function
const int& get() {return x;}       // member function returning a const&
const int& get() const {return x;} // const member function returning a const& 
```

member overloaded as constness

```c++
// overloading members on constness
#include <iostream>
using namespace std;

class MyClass {
    int x;
  public:
    MyClass(int val) : x(val) {}
    const int& get() const {return x;}
    int& get() {return x;}
};

int main() {
  MyClass foo (10);
  const MyClass bar (20);
  foo.get() = 15;         // ok: get() returns int&
// bar.get() = 25;        // not valid: get() returns const int&
  cout << foo.get() << '\n';
  cout << bar.get() << '\n';

  return 0;
}
```

##8.explicit : converting constructor

##9.class template

```c++
template <class T> class mycontainer { ... }; //generic template
template <> class mycontainer <char> { ... }; //template specialization

template <class T>
T mypair<T>::getmax ()
// the third T (the one between angle brackets) is also a requirement: It specifies that this function's template parameter is also the class template parameter.
```

##10.copy constructor
[shallow copy vs deep copy](https://stackoverflow.com/questions/2657810/deep-copy-vs-shallow-copy)
http://www.cplusplus.com/doc/tutorial/classes2/
```c++
MyClass foo;
MyClass bar (foo);       // object initialization: copy constructor called
MyClass baz = foo;       // object initialization: copy constructor called
foo = bar;               // object already initialized: copy assignment called 
```

**Note that baz is initialized on construction using an equal sign, but this is not an assignment operation! (although it may look like one)**

```
MyClass fn();            // function returning a MyClass object
MyClass foo;             // default constructor
MyClass bar = foo;       // copy constructor
MyClass baz = fn();      // move constructor
foo = bar;               // copy assignment
baz = MyClass();         // move assignment
```

##11.leaky abstraction

##12.inline functions
>Calling a function generally causes a certain overhead (stacking arguments, jumps, etc...), and thus for very short functions, it may be more efficient to simply insert the code of the function where it is called, instead of performing the process of formally calling a function.

##13.inheritance
>Unless otherwise specified, the constructors of a derived class calls the default constructor of its base classes (i.e., the constructor taking no arguments). Calling a different constructor of a base class is possible, using the same syntax used to initialize member variables in the initialization list.

|             | public    | protected | private |
| ----------- | :-------: | :-------: | ------- |
| public inh  | public    | protected | no |
| protect inh | protected | protected | no |
| private inh | private   | private   | no |

##[14.polymorphism](http://www.cplusplus.com/doc/tutorial/polymorphism/)
>**One of the key features of class inheritance is that a pointer to a derived class is type-compatible with a pointer to its base class. Polymorphism is the art of taking advantage of this simple but powerful and versatile feature.**

>**A virtual member is a member function that can be redefined in a derived class, while preserving its calling properties through references.**

>**A class that declares or inherits a virtual function is called a polymorphic class. Classes that contain at least one pure virtual function are known as abstract base classes. Virtual members and abstract classes grant C++ polymorphic characteristics, most useful for object-oriented projects.**

>**An abstract base class is not totally useless. It can be used to create pointers to it, and take advantage of all its polymorphic abilities. And can actually be dereferenced when pointing to objects of derived (non-abstract) classes.**

##[15.type casting](http://www.cplusplus.com/doc/tutorial/typecasting/)    
**no_safe**
```c++
double x = 10.3;
int y;
y = int (x);    // functional notation
y = (int) x;    // c-like cast notation
```

##16.Exceptions
