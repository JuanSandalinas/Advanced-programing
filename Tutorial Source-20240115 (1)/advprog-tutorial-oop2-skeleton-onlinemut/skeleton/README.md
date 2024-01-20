# OnlineMUT: An online system to manage university tables

Version 0.2.0.

Put an end to paper-based exam registrations and grades lists, with OnlineMUT!

## Building

Build OnlineMUT in your terminal with:

```shell
mkdir build
cd build
cmake ..
make
```

## Running

Run OnlineMUT in your terminal with:

```shell
./onlinemut
```

## Example output

```shell
$ ./onlinemut 
Constructing the course IN1503
Constructing the lecture IN1503
Constructing the course IN2186
Constructing the practical IN2186
Our university now offers a new curriculum with the following courses:
Available courses (id, type):
IN1503, Lecture
IN2186, Practical
Only the aforementioned courses are officially approved.

Hi! My name is Eve and my registration number is 12345.
Issued a card for Eve.
This card belongs to Eve.
Available courses (id, type):
IN1503, Lecture
IN2186, Practical
Only the aforementioned courses are officially approved.

Hi! I am Clippy and I am here to help you! The course description of IN1503 is:
This is a must-take lecture. Don't miss it!
The final exam is on stardate 3025.3.
Hope I helped. Have a nice day!

I am so excited to be taking IN1503 this semester! :-D
Eve is taking these courses this semester: IN1503 
It looks like the program coordinators did not like your request:
Course with id Magic4dummies not found in available courses.
Eve is taking these courses this semester: IN1503 
```

## Notes

When building the skeleton, you will notice that the linker cannot find an implementation for the `Curriculum::print_courses()` method. Well, maybe that's a first clue!
