//Gustavo J. Munoz
//November 15, 2014
//Assignment 6 - Student Hierarchy
//student.h

#include <iostream>		// for cin, cout
#include <fstream>
//#include <string>
#include <cstdlib>

#ifndef _STUDENT_H
#define _STUDENT_H

using namespace std;


class Student             
{
public:                        
    virtual double FinalAverage() = 0;		// a pure virtual function
    Student();
    Student(string first, string last, string courseType);
    string getName();
    virtual int getFinalExam() = 0;
    virtual char getLetterGrade() = 0;
    string getCourse();
    virtual ~Student() {};
protected:       
    string firstName;
    string lastName;
    string course;
};

class Biology: public Student //child class
{
public:
    Biology();
    Biology(string first, string last, string courseType, int lab, int t1, int t2, int t3, int FE);
    double FinalAverage();
    int getFinalExam();
    char getLetterGrade();

private:       
    //grades
    int labGrade;
    int termTest1;
    int termTest2;
    int termTest3;
    int finalExam;

};

class Theater: public Student //child class
{

public:                             
    Theater();
    Theater(string first, string last, string courseType, int part, int MT, int FE);
    double FinalAverage();
    int getFinalExam();
    char getLetterGrade();

private:
    //grades
    int participation;
    int midterm;
    int finalExam;

};	

class ComputerScience: public Student //child class
{

public:                             
    ComputerScience();
    ComputerScience(string first, string last, string courseType, int PA, int t1, int t2, int FE);
    double FinalAverage();
    int getFinalExam();
    char getLetterGrade();
    
private:
    //grades
    int programAverage;
    int test1;
    int test2;
    int finalExam;

};


#endif
