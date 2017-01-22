// Main program to test class Student
// and its derived classes.

#include <iostream>		// for cin, cout
#include <fstream>
#include <string>
#include <cstdlib>
#include "student.h"		// for Student classes

using namespace std;


void output(ofstream& outputFile, string className, int numStudents, Student** studentList){

    outputFile << className+" CLASS" << '\n';
    outputFile << '\n';
    outputFile << "Student \t\t\tFinal\tFinal\tLetter" << '\n';
    outputFile << "Name    \t\t\tExam \tAvg  \tGrade " << '\n';
    outputFile << "---------------------------------------------------------" << '\n';
    int i = 0;
//     for(int i = 0; i < numStudents; i++){
        while((i<numStudents) && studentList[i]->getCourse() == className){

            outputFile << studentList[i]->getName() << studentList[i]->getFinalExam() << studentList[i]->FinalAverage() << '\n';
        cout << "while loop is running." << endl;
	i++;

	}
//     }
    outputFile << '\n';
    outputFile << '\n';
}


int main()
{
    cout << "Please enter the name of the input file." << '\n';
    cout << "Filename: ";
    string inputFileName;		//name of text file
    cin >> inputFileName;
    
    ifstream inputFile;
    inputFile.open(inputFileName.c_str());
    if(!inputFile){
        cout << "Incompatible file. Check file extension." << endl;
        exit(0);
    }
    else{
        string whiteSpace = "";
        int numStudents = -1;
        inputFile >> numStudents;
        getline(inputFile, whiteSpace);

        if (numStudents <= 0) {
            //nothing to do
            //return;
        }

        Student** studentList = new (nothrow) Student*[numStudents];

        //for(int i = 0; i <numStudents; i++){
            //main loop reads 2 lines representing student each iteration
        	 int i = 0;    
	while (!inputFile.eof()) {


                string line1 = "";
                string line2 = "";
                string firstName, lastName, subject;
                getline(inputFile, line1);
                getline(inputFile, line2);

                // 	      cout << "1st line: " << line1 << endl;
                // 	      cout << "2nd line: " << line2 << endl;

                // check that the line being read is not empty in order to successfully
                // locate a ',' or a B,C,T
                if((!line1.empty()) || (!line2.empty())){
                    //comma delimited names (line 1)
                    size_t pos = line1.find(",");

                    firstName = line1.substr(pos+2);
                    // 		  cout << "FirstName: " << firstName << endl;

                    lastName = line1.substr(0, pos);
                    // 		  cout << "LastName: " << lastName << endl;

                    int numGrades = 0;
                    //subject (line 2)
                    if(line2[0] == 'B'){
                        subject = "Biology";
                        numGrades = 5;
                        line2.erase(0, 8);	//remove subject from line2
                    }
                    if(line2[0] == 'C'){
                        subject = "Computer Science";
                        numGrades = 9;
                        line2.erase(0, 17);
                    }
                    if(line2[0] == 'T'){
                        subject = "Theater";
                        numGrades = 3;
                        line2.erase(0, 8);
                    }

                    //remove trailing spaces from line2 by looking at
                    //last character and if spacce, erase it until non-space
                    //character reached
                    while(line2.find(" ", line2.length() -1) != std::string::npos) {
                        line2.erase(line2.length() - 1, 1);
                    }
                    // 		  cout << "Subject: " << subject << endl;
                    int gradesArray[numGrades];

                    //parse grades into gradesArray by starting at beg of line2,
                    //looking for a space
                    int j = 0;
                    int startPos = 0;
                    int spacePos = line2.find(" ", 0);
                    while(spacePos != std::string::npos) {
                        //startPos == 0 on first run
                        if (j > 0) {
                            startPos = spacePos + 1;
                        }
                        int grade = atoi(line2.substr(startPos, spacePos).c_str());
                        gradesArray[j++] = grade;

                        //determine if next grade in the input
                        spacePos = line2.find(" ", startPos);
                    }

                    //now that read in grades, instantiate appropiate obj
                    if (subject == "Biology")
                        studentList[i] = new Biology(firstName, lastName, subject, gradesArray[0], gradesArray[1], gradesArray[2], gradesArray[3], gradesArray[4]);
                    else if(subject == "Computer Science"){
                        int programAvg = ((gradesArray[0]+gradesArray[1]+gradesArray[2]+gradesArray[3]+gradesArray[4]+gradesArray[5])/6);
                        studentList[i] = new ComputerScience(firstName, lastName, subject, programAvg, gradesArray[6], gradesArray[7], gradesArray[8]);
                    }
                    else if (subject == "Theater")
                        studentList[i] = new Theater(firstName, lastName, subject, gradesArray[0], gradesArray[1], gradesArray[2]);

                }
	    cout << "i: " << i << endl;

	    i++;
            }

            inputFile.close();

        //}

        cout << "Please enter the name of the output file." << '\n';
        cout << "Filename: ";
        string outputFileName;		//name of text file
        cin >> outputFileName;

        ofstream outputFile;
        outputFile.open(outputFileName.c_str());
        if(!outputFile){
            cout << "Incompatible file. Check file extension." << endl;
            exit(0);
        }
        else{
            // write some data to the file
	    outputFile << "Student Grade Summary" << '\n';
	    outputFile << "------------------------" << '\n';
	    outputFile << '\n';
            
            output(outputFile, "Biology", numStudents,studentList);
            output(outputFile, "Theater", numStudents,studentList);
            output(outputFile, "Computer Science", numStudents,studentList);

            outputFile.close();

            cout << "Processing Complete." << '\n';
        }
    }

}


