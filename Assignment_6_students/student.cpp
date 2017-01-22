//Gustavo J. Munoz
//November 15, 2014
//Assignment 6 - Student Hierarchy
//student.cpp

// Creates Table of students with their respective grades, per Major.  Provides individual
// and total average statics of grades

#include <iostream>     //for cin, cout
#include <cstring>       //for strcmp
#include <string>
#include "student.h"     //for Student declarations

using namespace std;
// Student default constructor --not used---------------------------------------
Student::Student(){

};
// Student 5-param constructor
Student::Student(string first, string last, string courseType){
    firstName = first;
    lastName = last;
    course = courseType;
};
string Student::getName(){
    string fullName = firstName + " " + lastName;
    return(fullName);
};

string Student::getCourse(){
    return(course);
};


// Biology default constructor --not used---------------------------------------
Biology::Biology(){

};

// Biology 5-param constructor 
Biology::Biology(string first, string last, string courseType, int lab, int t1, int t2, int t3, int FE):
    Student(first, last, courseType)//this shows that the first 3 params are inherited
{
    labGrade = lab;
    termTest1 = t1;
    termTest2 = t2;
    termTest3 = t3;
    finalExam = FE;
};

double Biology::FinalAverage(){
    //Lab Grade = 30%, Three term tests = 15 % each, Final Exam = 25%
    return (.3*(labGrade) + .15*(termTest1) +
            .15*(termTest2) + .15*(termTest3) + .25*(finalExam));
};

int Biology::getFinalExam(){
    return(finalExam);
};

char Biology::getLetterGrade(){
    if(FinalAverage() >= 90)
	return('A');
    if(FinalAverage() >= 80)
	return('B');
    if(FinalAverage() >= 70)
	return('C');
    if(FinalAverage() >= 60)
	return('D');
    if(FinalAverage() < 60)
	return('F');
};


// Theater default constructor --not used---------------------------------------   
Theater::Theater(){

};

// Theater 5-param constructor 
Theater::Theater(string first, string last, string courseType, int part, int MT, int FE):
    Student(first, last, courseType)//this shows that the first 3 params are inherited
{
    participation = part;
    midterm = MT;
    finalExam = FE;
};

double Theater::FinalAverage(){
    //Participation (scene studies) = 40 %, Midterm = 25%, Final Exam = 35%
    return (0.4*(participation) + .25*(midterm) + .35*(finalExam));
};

int Theater::getFinalExam(){
    return(finalExam);
};

char Theater::getLetterGrade(){
    if(FinalAverage() >= 90)
	return('A');
    if(FinalAverage() >= 80)
	return('B');
    if(FinalAverage() >= 70)
	return('C');
    if(FinalAverage() >= 60)
	return('D');
    if(FinalAverage() < 60)
	return('F');
};

// Computer Science default constructor --not used------------------------------
ComputerScience::ComputerScience(){

};

// Computer Science 5-param constructor 
ComputerScience::ComputerScience(string first, string last, string courseType, int PA, int t1, int t2, int FE):
    Student(first, last, courseType)//this shows that the first 3 params are inherited
{
    programAverage = PA;
    test1 = t1;
    test2 = t2;
    finalExam = FE;
};

double ComputerScience::FinalAverage(){
    //Program Average = 30%, Test 1 = 20%, Test 2 = 20%, Final Exam = 30%
    return (0.3*(programAverage) + .20*(test1) + .20*(test2) + .30*(finalExam));
};

int ComputerScience::getFinalExam(){
    return(finalExam);
};

char ComputerScience::getLetterGrade(){
    if(FinalAverage() >= 90)
	return('A');
    if(FinalAverage() >= 80)
	return('B');
    if(FinalAverage() >= 70)
	return('C');
    if(FinalAverage() >= 60)
	return('D');
    if(FinalAverage() < 60)
	return('F');
};



