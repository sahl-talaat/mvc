#include<iostream>


#ifndef EMPDATA
#define EMPDATA
struct EmpData{
            int roll_number{};
            std::string name{};
            std::string specialization{};
            double salary{};
            EmpData(){}
            EmpData(int roll_number, std::string name, std::string specialization, double salary){
                this->roll_number = roll_number;
                this->name = name;
                this->specialization = specialization;
                this->salary = salary;
            }
    };
#endif