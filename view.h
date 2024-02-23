#include<iostream>
#include"employee_data.h"

#ifndef VIEW
#define VIEW
class View{
    public:
        void display_employee_data(int roll_number, std::string name, std::string specialization, double salary){
            std::cout << "=> Roll Number: " << roll_number<< ", Name: " << name << ", Specialization: " << specialization << ", Salary: " << salary << std::endl;
        }
        void display_not_found(auto vlaue){
            std::cout<<"employee "<<vlaue<<" Not Found\n";
        }
        EmpData add_new_employee(){
            int roll_number; 
            std::string name, specialization; 
            double salary;
            std::cout<<"\t Enter employee data\n";
            std::cout<<"Roll Number : ";std::cin>>roll_number;
            std::cout<<"Name : ";std::cin>>name;
            std::cout<<"Specialization : ";std::cin>>specialization;
            std::cout<<"Salary : ";std::cin>>salary;
            return EmpData(roll_number,name,specialization,salary);
        }
        std::string search_by_name(){
            std::string name;
            std::cout<<"Enter employee name : ";
            std::cin>>name;
            return name;
        }
        int search_by_roll_number(){
            int roll_number;
            std::cout<<"Enter employee roll number : ";
            std::cin>>roll_number;
            return roll_number;
        }

        int get_roll_number(){
            int emp_roll_number;
            std::cout<<"Enter employee roll number : ";
            std::cin>>emp_roll_number;
            return emp_roll_number;
        }

        std::string get_new_specialization(){
            std::string new_specialization;
            std::cout<<"Enter employee new specialization : ";
            std::cin>>new_specialization;
            return new_specialization;
        }

        double get_new_salary(){
            double new_salary;
            std::cout<<"Enter employee new salary : ";
            std::cin>>new_salary;
            return new_salary;
        }

        std::string get_new_name(){
            std::string new_name;
            std::cout<<"Enter employee new name : ";
            std::cin>>new_name;
            return new_name;
        }

        void updated_succesfully(){
            std::cout<<"updated succesfully\n";
        }
};

#endif