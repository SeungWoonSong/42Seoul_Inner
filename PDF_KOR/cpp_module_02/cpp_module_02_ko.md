# page 0

## C++ - Module 02
## C++ - 모듈 02

### Ad-hoc polymorphism, operators overload and canonical classes

Summary: This document contains the subject for Module 02 of the C++ modules.  
요약: 이 문서에는 C ++ 모듈의 모듈 02에 대한 주제가 포함되어 있습니다.  

# page 1

## Contents

| Chapter | Contents | Page |
|:---:|:---|:---:|
| I | [__General rules__]() | 2 |
| II | [__Bonus rules__]() | 4 |
| III | [__Exercise 00: My First Canonical Class__]() |  5 |
| IV | [__Exercise 01: Towards a more useful fixed point class__]() |  8 |
| V | [__Exercise 02: Now we’re talking__]() |  10 |
| VI | [__Exercise 03: Fixed point expressions__]() |  13 |

# page 2

## Chapter I
## 챕터 I
## General rules
## 일반적인 규칙

- Any function implemented in a header (except in the case of templates), and any unprotected header, means 0 to the exercise.

- 헤더에 구현된 어떤 기능 (템플릿의 경우 제외) 및 보호되지 않은 헤더는 평가 과정에서 0을 의미합니다.

- Every output goes to the standard output, and will be ended by a newline, unless specified otherwise.

- 모든 출력은 표준 출력으로 전달되며 달리 지정하지 않는 한 개행으로 끝납니다.

- The imposed filenames must be followed to the letter, as well as class names, function names and method names.

- 부과된 파일 이름 뒤에는 클래스 이름, 함수 이름 및 메소드 이름뿐만 아니라 문자가 와야합니다.

- Remember: You are coding in C++ now, not in C anymore. Therefore:
  - The following functions are FORBIDDEN, and their use will be punished by a 0, no questions asked: *alloc, *printf and free.
  - You are allowed to use basically everything in the standard library. HOWEVER, it would be smart to try and use the C++-ish versions of the functions you are used to in C, instead of just keeping to what you know, this is a new language after all. And NO, you are not allowed to use the STL until you actually are supposed to (that is, until module 08). That means no vectors/lists/maps/etc... or anything that requires an include \<algorithm> until then.

- 기억하세요: 이제 당신은 더 이상 C가 아닌 C++로 코딩하고 있습니다. 따라서:
  - \*alloc, \*printf 및 free와 같은 함수는 금지되어 있으며 사용시 0으로 처벌됩니다.
  - 기본적으로 표준 라이브러리의 모든 것을 사용할 수 있습니다. 그러나 알고 있는 내용을 그대로 유지하는 대신 이것은 결국 새로운 언어이기 때문에, C에서 익숙한 함수의 C++ 버전을 사용하는 것이 현명할 것입니다. STL을 사용하기로 되어있는 모듈(cpp module 08) 전 까지는 STL 을 사용하실 수 없습니다. 즉, 그때까지 벡터/리스트/맵/등등 또는 \<algorithm> 헤더에 포함된 어떤 것도 쓸 수 없음을 의미합니다.

- Actually, the use of any explicitly forbidden function or mechanic will be punished by a 0, no questions asked.

- 실제로, 명시적으로 금지된 기능이나 방법은 가차없이 0점으로 처벌됩니다.

- Also note that unless otherwise stated, the C++ keywords "using namespace" and "friend" are forbidden. Their use will be punished by a -42, no questions asked.

- 또한 달리 명시되지 않는 한 C++ 키워드 "using namespace" 및 "friend"는 금지됩니다. 그들의 사용은 가차없이 -42로 처벌될 것입니다.

- Files associated with a class will always be ClassName.hpp and ClassName.cpp, unless specified otherwise.

- 클래스와 연관된 파일은 달리 지정하지 않는 한 항상 ClassName.hpp 및 ClassName.cpp입니다.

- Turn-in directories are ex00/, ex01/, . . . , exn/.

- 제출 디렉토리는 ex00 /, ex01 /,. . . , exn/ 입니다.

- You must read the examples thoroughly. They can contain requirements that are not obvious in the exercise’s description. If something seems ambiguous, you don’t understand C++ enough.

- 예제를 철저히 읽어야합니다. 여기에는 연습 설명에서 명확하지 않은 요구 사항이 포함될 수 있습니다. 모호해 보이는 것이 있으면 C++를 충분히 이해하지 못하는 것입니다.

- Since you are allowed to use the C++ tools you learned about since the beginning, you are not allowed to use any external library. And before you ask, that also means no C++11 and derivates, nor Boost or anything your awesomely skilled friend told you C++ can’t exist without.

- 처음부터 배운 C++ 도구를 사용할 수 있으므로 외부 라이브러리를 사용할 수 없습니다. 미리 말씀드리지만, C++11, Boost, 프로그래밍을 잘하는 친구가 c++은 이거 없으면 시체라고 추천한 툴들을 포함한 그 어떤 외부 라이브러리도 사용할 수 없습니다

# page 3

- You may be required to turn in an important number of classes. This can seem tedious, unless you’re able to script your favorite text editor.

- 상당한 수의 클라스들을 제출해야 할 수도 있습니다. 좋아하는 텍스트 편집기를 스크립팅 할 수 없다면 지루해 보일 수 있습니다.

- Read each exercise FULLY before starting it! Really, do it.

- 시작하기 전에 각 연습 문제를 완전히 읽으십시오! 정말로, 하세요.

- The compiler to use is clang++.

- 사용할 컴파일러는 clang ++입니다.

-  Your code has to be compiled with the following flags : -Wall -Wextra -Werror.

- 다음 플래그를 사용하여 코드를 컴파일해야합니다: -Wall -Wextra -Werror.

- Each of your includes must be able to be included independently from others. Includes must contains every other includes they are depending on, obviously.

- 각 includes는 다른 것들과 독립적으로 포함될 수 있어야합니다. Includes는 분명히 그들이 의존하는 다른 모든 include를 포함해야합니다.

- In case you’re wondering, no coding style is enforced during in C++. You can use any style you like, no restrictions. But remember that a code your peer-evaluator can’t read is a code she or he can’t grade.

- 혹시 궁굼할까봐 말씀드리지만, C++에서는 코딩 스타일이 강제되지 않습니다. 제한없이 원하는 스타일을 사용할 수 있습니다. 하지만 동료 평가자가 읽을 수 없는 코드는 점수를 매길 수 없는 코드라는 점을 기억하세요.

- Important stuff now : You will NOT be graded by a program, unless explictly stated in the subject. Therefore, you are afforded a certain amount of freedom in how you choose to do the exercises. However, be mindful of the constraints of each exercise, and DO NOT be lazy, you would miss a LOT of what they have to offer !

- 지금 중요한 사항 : 서브젝트에 명시적으로 언급되지 않는 한 프로그램에 의해 평가되지 않습니다. 따라서 연습 문제를 선택하는 방법에 있어 어느 정도의 자유가 주어집니다. 그러나 각 연습 문제의 제약을 염두에 두고 게을러지지 마세요, 그들이 제공해야하는 많은 것을 놓칠 것입니다 !

- It’s not a problem to have some extraneous files in what you turn in, you may choose to separate your code in more files than what’s asked of you. Feel free, as long as the result is not graded by a program.

- 제출한 파일에 관련없는 파일이 있는 것은 문제가 되지 않습니다. 요청한 것보다 더 많은 파일에서 코드를 분리하도록 선택할 수 있습니다. 결과가 프로그램에 의해 평가되지 않는한 자유롭게 평가하시면 됩니다.

- Even if the subject of an exercise is short, it’s worth spending some time on it to be absolutely sure you understand what’s expected of you, and that you did it in the best possible way.

- 연습 문제의 주제가 짧더라도 자신에게 기대되는 바를 이해하고 가능한 최선의 방법으로 수행했는지 확인하기 위해 시간을 할애 할 가치가 있습니다.

- By Odin, by Thor! Use your brain!!!

- 오딘, 토르! 머리를 써라!!!

# page 4

## Chapter II
## 챕터 II
## Bonus rules

- From now on, each class you write MUST be in canonical (Coplien) form: At least
one default constructor, a copy contructor, an assignation operator overload and a
destructor. We won’t ask again.

# page 5

## Chapter III
## 챕터 III
## Exercise 00: My First Canonical Class

```
Exercise : 00
Exercise 00: My First Canonical Class
Turn-in directory : ex00/
Files to turn in : Fixed.class.hpp and Fixed.class.cpp, or Fixed.hpp and
Fixed.cpp, or Fixed.h and Fixed.cc. Pick one, I don’t care unless it’s
stupid.
Forbidden functions : None
```

You know integers and you also know floating point numbers. How cute.  

Please read this 3-page article (1, 2, 3) to discover that you don’t. Go on, read it.  

Until today, any numbers you used in your programs were basically integers or floating
point numbers, or any of their variants (short, char, long, double, etc). From your previous reading, it’s safe to assume that integers and floating point numbers have opposite
caracteristics.  

But today, this will change. You are going to discover a new and awesome number
type: fixed point numbers! Always missing from most languages scalar types, fixed point
numbers offer a valuable balance between performance, accuracy, range and precision that
explains why these numbers are widely used in graphics, sound or scientific programming
to name a few.  

As C++ lacks fixed point numbers, you’re going to add them yourself today. I’d recommend this article from Berkeley as a start. If it’s good for them, it’s good for you. If
you have no idea what Berkeley is, read this section of their wikipedia page.  

# page 6

Write a canonical class to represent fixed point numbers:  

- Private members:
  - An integer to store the fixed point value.
  - A static constant integer to store the number of fractional bits. This constant will always be the litteral 8.
- Public members:
  - A default constructor that initializes the fixed point value to 0.
  - A destructor.
  - A copy constructor.
  - An assignation operator overload.
  - A member function int getRawBits( void ) const; that returns the raw value of the fixed point value.
  - A member function void setRawBits( int const raw ); that sets the raw value of the fixed point value.

The code:  

```c++
#include <iostream>

int main( void ) {
  Fixed a;
  Fixed b( a );
  Fixed c;
  c = b;
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
  return 0;
}
```

Should output something like:  

```sh
$> clang++ -Wall -Wextra -Werror Fixed.class.cpp main.cpp
$> ./a.out
Default constructor called
Copy constructor called
Assignation operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Assignation operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
```

# page 7

```sh
Destructor called
Destructor called
$>
```

# page 8

## Chapter IV
## 챕터 IV
## Exercise 01: Towards a more useful fixed point class

```
Exercise : 01
Exercise 01: Towards a more useful fixed point class
Turn-in directory : ex01/
Files to turn in : Fixed.class.hpp and Fixed.class.cpp, or Fixed.hpp and
Fixed.cpp, or Fixed.h and Fixed.cc. Pick one, I don’t care unless it’s
stupid.
Allowed functions : roundf (from <cmath>)
```

Ok, ex00 was a good start, but our class is still pretty useless, being only able to
represent the fixed point value 0.0. Add the following public constructors and public
member functions to your class:  

- A constructor that takes a constant integer as a parameter and that converts it to
the correspondant fixed(8) point value. The fractional bits value is initialized like
in ex00.

- A constructor that takes a constant floating point as a parameter and that converts
it to the correspondant fixed(8) point value. The fractional bits value is initialized
like in ex00.

- A member function float toFloat( void ) const; that converts the fixed point
value to a floating point value.

- A member function int toInt( void ) const; that converts the fixed point value
to an integer value.

You will also add the following function overload to your header (declaration) and
source (definition) files:

- An overload to the « operator that inserts a floating point representation of the
fixed point value into the parameter output stream.

# page 9

```c++
#include <iostream>

int main( void ) {
  Fixed a;
  Fixed const b( 10 );
  Fixed const c( 42.42f );
  Fixed const d( b );

  a = Fixed( 1234.4321f );

  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;

  std::cout << "a is " << a.toInt() << " as integer" << std::endl;
  std::cout << "b is " << b.toInt() << " as integer" << std::endl;
  std::cout << "c is " << c.toInt() << " as integer" << std::endl;
  std::cout << "d is " << d.toInt() << " as integer" << std::endl;

  return 0;
}
```

The code:  
Should output something like:  

```sh
$> clang++ -Wall -Wextra -Werror Fixed.class.cpp main.cpp
$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Assignation operator called
Float constructor called
Assignation operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
$>
```

# page 10

## Chapter V
## 챕터 V
## Exercise 02: Now we’re talking

```
Exercise : 02
Exercise 02: Now we’re talking
Turn-in directory : ex02/
Files to turn in : Fixed.class.hpp and Fixed.class.cpp, or Fixed.hpp and
Fixed.cpp, or Fixed.h and Fixed.cc. Pick one, I don’t care unless it’s
stupid.
Allowed functions : roundf (from <cmath>)
```

```diff
- This exercise does not offer any points but is still useful. You can
- do it, or not.
```

We’re getting closer. Add the following public member operator overloads to your
class:  

- Six comparison operators: >, <, >=, <=, == and !=.
- Four arithmetic operators: +, -, *, and /.
- The pre-increment, post-increment, pre-decrement and post-decrement operators, that will increment or decrement the fixed point value from the smallest representable  such as 1 +  > 1.  

Add the following public non member functions overloads to your class :  

- The non-member function min that takes references on two fixed point values and
returns a reference to the smallest value, and an overload that takes references on
two constant fixed point values and returns a reference to the smallest constant
value.

# page 11

- The non-member function max that takes references on two fixed point values and
returns a reference to the biggest value, and an overload that takes references on two
constant fixed point values and returns a reference to the biggest constant value.

# page 12

It’s up to you to test every feature of your class, but the short code:  

```c++
#include <iostream>

int main( void ) {
  Fixed a;
  Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;

  std::cout << b << std::endl;

  std::cout << Fixed::max( a, b ) << std::endl;

  return 0;
}
```

Should output something like (I deleted the ctors/dtor logs):  

```sh
$> clang++ -Wall -Wextra -Werror Fixed.class.cpp main.cpp
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
```

# page 13

## Chapter VI
## 챕터 VI
## Exercise 03: Fixed point expressions

```
Exercise : 03
Exercise 03: Fixed point expressions
Turn-in directory : ex03/
Files to turn in : Fixed.class.hpp and Fixed.class.cpp, plus any additionnal
files you need, and a Makefile. The naming convention is up to you.
Allowed functions : roundf (from <cmath>)
```

```diff
- This exercise does not offer any points but is still useful. You can do it, or not.
```

Write a program named eval_expr that evaluates simple arithmetic expressions as fixed point values.  

```
노랭이
Please use strings, istreams, ostreams, istringstreams and
ostringstreams as much as you can. These will save you a LOT of
time.
```

For instance:

```sh
$> clang++ -Wall -Wextra -Werror -o eval_expr Fixed.class.cpp {your files}
$> ./eval_expr "( 18.18 + 3.03 ) * 2"
42.4219
$>
```