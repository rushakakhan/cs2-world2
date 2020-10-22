#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Defining a time of day
struct course
{
  int number;
  string title;
  string department;
};

course courses[10] = {
  {1010, "Introduction to Computer Science I", "COMP"},
  {1020, "Introduction to Computer Sciennce II", "COMP"},
  {1030, "Software Design", "COMP"},
  {1401, "Sustainability", "ENVE"},
  {1501, "Linear Algebra", "MATH"},
  {1502, "Calculus I", "MATH"},
  {1502, "Calculus II", "MATH"},
  {2502, "Dynamics", "MECH"},
  {2403, "Thermodynamics", "MECH"},
  {3201, "Structural Design", "CIVL"}
};

int numCoursesInDepartment(course courseArray[], int numCourses, string department)
{
  int count = 0;
  for (int i = 0; i < numCourses; i++) {
    if (courseArray[i].department.compare(department) == 0) {
      count++;
    }
  }
  return count;
}

int main() 
{
  cout << "Number of courses in COMP department: " << numCoursesInDepartment(courses, 10, "COMP") << endl;
  cout << "Number of courses in MECH department: " << numCoursesInDepartment(courses, 10, "MECH") << endl;
  return 0;
}
