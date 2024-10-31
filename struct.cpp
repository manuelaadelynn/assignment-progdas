#include <iostream>
#include <iomanip>
#include <fstream> // For file handling
using namespace std;

struct studentType
{
    string studentFname;
    string studentLname;
    int testScore;
    char grade;
};

const int totalstudent = 20;

void readStudentDataFromFile(studentType student[], int totalstudent, const string &filename)
{
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }

    for (int i = 0; i < totalstudent; i++)
    {
        inputFile >> student[i].studentFname >> student[i].studentLname >> student[i].testScore;
    }

    inputFile.close();
}

void determineGrade(studentType student[], int totalstudent)
{
    for (int i = 0; i < totalstudent; i++)
    {
        if (student[i].testScore >= 90)
            student[i].grade = 'A';
        else if (student[i].testScore >= 80)
            student[i].grade = 'B';
        else if (student[i].testScore >= 70)
            student[i].grade = 'C';
        else if (student[i].testScore >= 60)
            student[i].grade = 'D';
        else
            student[i].grade = 'E';
    }
}

int determineHighestScore(studentType student[], int totalstudent)
{
    int max = student[0].testScore;
    for (int i = 1; i < totalstudent; i++)
    {
        if (student[i].testScore > max)
        {
            max = student[i].testScore;
        }
    }
    return max;
}

void displayHighestScoreStudents(studentType student[], int totalstudent)
{
    int max = determineHighestScore(student, totalstudent);
    cout << "\nThe student(s) with the highest score of " << max << ":\n";
    for (int i = 0; i < totalstudent; i++)
    {
        if (student[i].testScore == max)
        {
            cout << student[i].studentLname << ", " << student[i].studentFname << endl;
        }
    }
}

void writeStudents(studentType student[], int totalstudent)
{
    cout << left << setw(25) << "Name" << setw(10) << "Score" << "Grade" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < totalstudent; i++)
    {
        cout << setw(25) << student[i].studentLname + ", " + student[i].studentFname
             << setw(10) << student[i].testScore
             << student[i].grade << endl;
    }
    cout << endl;
}

int main()
{
    studentType student[totalstudent];
    string filename = "student_data.txt"; // Nama file yang akan dibaca

    readStudentDataFromFile(student, totalstudent, filename);
    determineGrade(student, totalstudent);
    cout << endl;
    writeStudents(student, totalstudent);
    displayHighestScoreStudents(student, totalstudent);

    return 0;
}