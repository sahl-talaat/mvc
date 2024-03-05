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
            void set_name(const std::string& new_name){
                this->name = new_name;
            }

            void set_salary(double new_salary){
                this->salary = new_salary;
            }

            void set_specialization(std::string new_specialization){
                this->specialization = new_specialization;
            }
    };
#endif