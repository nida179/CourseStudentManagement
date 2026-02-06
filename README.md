## Course-Student-Management
A **multi-linked list** implementation in C++ for managing university courses and students enrollments.

## 🗂 Project Overview

This project implements a course registration system using a multi-level linked list data structure where:
- Each **course** is a node in the primary linked list
- Each course contains a secondarylinked list of **students** enrolled in that course

## 🏗 Data Structure
**example
CourseList(Primary Linked List):
[Course 101] -> [Course 202] -> [Course 303] -> NULL
|                |              |
StudentList      StudentList    StudentList 
|                |               |
v                v               v
[S-001]          [S-002]         [S-001]
|                |               |
v                v               v
[S-003]          [S-005]         [S-004]
|                |               |
v                v               v
NULL            NULL             NULL

##✨ Features
### Course Management
- ➕ Enroll students in courses
- 🚮 Remove students from specific courses
- 🚮 Remove a student from all courses
- 🔎 Search for students across all courses
- 📊 Display all courses a student is enrolled in
- ✅ Check if a student is enrolled in a specific course

## 🔗 Technology Used 
- **Language** : C++
- **Data Structure** : Multi-Linked list
- **Memory Management** : Dynamic allocation with malloc and free()

 ## 👩‍💻 Author
 [Nida Hafeez]

 ## 🤝 Contributions
 Feel free to fork this project and submit pull requests for any improvements!
