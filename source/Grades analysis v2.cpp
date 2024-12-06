// Grades analysis v2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Student.h"

int main()
{
    std::cout << "GRADES ANALYSER V2\n";
    std::cout << "-----------------\n";
    std::cout << "------USAGE------\n";
    std::cout << "-----------------\n\n";
    std::cout << "This program will read from a file\ncontaining records of students\nwith Physics, Chemistry, Maths marks in CSV format\nand produce a results file\nand a folder containing\nindividual reports.\n";

    std::cout << "Enter filename for analysis:\n";
    std::string file;
    std::getline(std::cin, file);
    std::vector<Student> students = read(file);

    write(students);
    generate_reports(students);
    std::cout << "Results file and " << students.size() << " reports generated.";
    return 0;
}