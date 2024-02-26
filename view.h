#include<iostream>
#include"employee_data.h"

#ifndef VIEW
#define VIEW
class View{
    public:
        int index_view(){
            int choice{};
            std::cout<<"\t\tmain page\n";
            std::cout<<"\t1. add new employee\n";
            std::cout<<"\t2. search by employee roll number\n";
            std::cout<<"\t3. search by employee name\n";
            std::cout<<"\t4. update employee name\n";
            std::cout<<"\t5. update employee specialization\n";
            std::cout<<"\t6. update employee salary\n";
            std::cout<<"\t7. delete employee\n";
            std::cin>>choice;
            return choice;
        }
        void display_employee_data(int roll_number, std::string name, std::string specialization, double salary){
            std::cout << "=> Roll Number: " << roll_number<< ", Name: " << name << ", Specialization: " << specialization << ", Salary: " << salary << std::endl;
        }
        void display_not_found(std::string name, int roll_number){
            if (name.length() < 1)
                std::cout<<"employee "<<roll_number<<" Not Found\n";
            else
                std::cout<<"employee "<<name<<" Not Found\n";
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