#include <iostream>
#include <string>

using namespace std;

void assignCourseGrade(int numCourses, string courseLetterGrades[], double* courseGrades );
double calculateGPA(int numCourses, double* courseGrades);

int main(int argc, char* argv[])
{
  // not enough information, so please try again
  // this checks to see if you have an even number of entries
  // btw, the "./buggy" counts in argc, so we need to account for that
  if(argc < 2 || argc % 2 == 0) {
    cerr << "Usage: ./gpa course letterGrade" << endl;
    exit(1);
  }
  // initialize the string arrays for course names and their grades
  // grades will be doubles for the GPAs you get for that course
  // and strings when we input the letter grades
  // there'll be two entries per course, so course count is entries/2
  string courseNames[5];
  double courseGrades[5];
  string courseLetterGrades[5];
  int numCourses = int(argc/2);
  //cout << "done init 1" << endl;
  // this for loop will go through all of the entries' inputted letter grades
  // and fill the courseNames and courseLetterGrades arrays
  for (int i = 0; i< argc / 2; i+=1){
    //cout << "for loop: i = " << i << endl;
    courseNames[i] = string(argv[2*i+1]);
    //cout << "courseNames[i] = " << courseNames[i] << endl;
    courseLetterGrades[i] = string(argv[2*i+2]);
    //cout << "courseLetterGrades[i] = " << courseLetterGrades[i] << endl;
    // display all of the courses & their letter grades
    cout << courseNames[i] << "   " << courseLetterGrades[i] << endl;
  }
  //cout << "done init 2" << endl;
  // at this point we are changing the courseGrades array to display
  // the appropriate GPA values on a 4.00 scale
  assignCourseGrade(numCourses, courseLetterGrades, courseGrades);
  // change the default output settings such that GPA is rounded
  // to 3 decimal places
  //cout << "done init 3" << endl;
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(3);
  //cout << "done init 4" << endl;
  // calculate the GPA based on the courseGrades array that was edited in the
  // assignCourseGrade function
  double result = calculateGPA(numCourses, courseGrades);
  cout<<"GPA: "<< result <<endl;

  return 0;
}

// function that essentially converts every letter grade into a GPA point
// value
// int numCourses tells the number of courses from which to calculate the
// GPA from
// courseLetterGrades is pointer to array so that has the inputted letter
// grades
// courseGrades is the pointer to the array that we edit to display points
// from each course based on letter grade
void assignCourseGrade(int numCourses, string courseLetterGrades[], double* courseGrades){
  // for loop to go through and assign points
  for(int i = 0; i < numCourses; i++){
    //cout << courseLetterGrades[i] << endl;
    if(courseLetterGrades[i]=="A" || courseLetterGrades[i]=="A+"){ // > A
      courseGrades[i] = 4.0;
    }else if(courseLetterGrades[i]=="A-"){
      courseGrades[i] = 3.7;
    }else if(courseLetterGrades[i]=="B+"){
      courseGrades[i] = 3.3;
    }else if(courseLetterGrades[i]=="B"){
      courseGrades[i] = 3.0;
    }else if(courseLetterGrades[i]=="B-"){
      courseGrades[i] = 2.7;
    }else if(courseLetterGrades[i]=="C+"){
      courseGrades[i] = 2.3;
    }else if(courseLetterGrades[i]=="C"){
      courseGrades[i] = 2.0;
    }else if(courseLetterGrades[i]=="C-"){
      courseGrades[i] = 1.7;
    }else if(courseLetterGrades[i]=="D+"){
      courseGrades[i] = 1.3;
    }else if(courseLetterGrades[i]=="D"){
      courseGrades[i] = 1.0;
    }else { // if unrecognized letter grade
      courseGrades[i] = 0.0;
    }
  }
}

// calculate the GPA by averaging all of the values in courseGrades array
double calculateGPA(int numCourses, double* courseGrades){
  //cout << "calculating avg GPA" << endl;
  double sum = 0;
  for (int i = 0; i < numCourses; i++){
    sum+=courseGrades[i];
  }
  return sum/numCourses;
}
