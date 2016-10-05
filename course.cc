/***********************************************************************
	The implementation file for course.h, which describes a college
	course.
		John Dolan		School of EECS		Summer2013
**************************************************************************/

/**
* @file	course.cc
* @Author John Dolan
* @brief implementation file for course. Uses course.h. Contains overloaded
* operators, input/output, uppercase conversion, etc
*
*/


#include "course.h"
#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

course::course(){
    hours = 0.0;
}

/* input function that needs an instream. Will use user entered inputs or
 can read from a file. Takes Course Number, Grade, and Credit Hours.
 Also converts lowercase to uppercase */
void course::input(std::istream& ins){
    if(ins == cin){
	cout<<"Course Number: ";
	if(ins.peek() == '\n') ins.ignore();
    	getline(ins, course_number);
    	if(ins.eof()) return;
	cout<<"Grade received: ";
    	getline(ins, grade);
	grade[0] = toupper(grade[0]);
    	if(ins.eof()) return;
 	cout<<"Credit hours: ";
    	ins>>hours;
	upper_course();   // makes all lower case letters into caps
    }
    else{
    	if(ins.peek() == '\n') ins.ignore();
    	getline(ins, course_number);
    	if(ins.eof()) return;
    	getline(ins, grade);
	grade[0] = toupper(grade[0]);
    	if(ins.eof()) return;
    	ins>>hours;
    }
}
/* Output function that needs an outstream. Also, it is a const function.
 Will print out the Course Number, Grade, and Credit Hours to the screen
 or a file. */
void course::output(std::ostream& outs)const{
    if(outs == cout){
	outs<<"Course Number:"<<course_number<<endl;
	outs<<"Grade received:"<<grade<<endl;
	outs<<"Credit hours:"<<setprecision(2)<<hours<<endl;
      }
     else{
        outs<<course_number<<endl;
        outs<<grade<<endl;
        outs<<setprecision(2)<<hours<<endl;
      }
}

/* The get_number_grade funtion which takes a letter grade and will return
 the corresponding grade percentage as a double. Also, it is a const function.
 If an invalid grade, returns 0. */
double course::get_number_grade()const{
    if(grade == "A") return 4.0;
    if(grade == "A-") return 3.667;
    if(grade == "B+") return 3.333;
    if(grade == "B") return 3.0;
    if(grade == "B-") return 2.667;
    if(grade == "C+") return 2.333;
    if(grade == "C") return 2.0; 
    if(grade == "C-") return 1.667;
    if(grade == "D+") return 1.333; 
    if(grade == "D") return 1.0;
    if(grade == "D-") return 0.667; 
    if(grade == "F") return 0.0;
    else return 0;
}

void course::set_course(std::string num, std::string grad, double hrs){
	course_number = num;
	grade = grad;
	hours = hrs;
}

istream& operator >>(istream& ins, course& c){
    c.input(ins);
    return ins;
}

ostream& operator <<(ostream& outs, const course& c){
    c.output(outs);
    return outs;
}

void course::upper_course(){
    for(int i =0; i<course_number.length(); ++i)
	course_number[i] = toupper(course_number[i]);
}
