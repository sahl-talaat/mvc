#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include"employee_data.h"

#ifndef EMPLOYEE
#define EMPLOYEE

class Employee{
    private:
    // emp = employee
    
    std::string data_base;
    std::vector<EmpData> emp_table;
    public:
        Employee(){}
        Employee(std::string data_file){
            this->data_base = data_file;
        }
        void get_all_employee(){
            std::ifstream file(data_base);
            if (file.is_open()){
                int roll_number{};
                std::string name{}, specialization{};
                double salary{};
                //emp_table.clear();
                while (file >> roll_number >> name >> specialization >> salary){
                    /* EmpData emp;
                    emp.roll_number=roll_number */
                    emp_table.emplace_back(roll_number, name, specialization, salary);
                }
                file.close();
            }
            
        }
        void save_new_data(){
            std::ofstream file(data_base);
            if (file.is_open()){
                file.clear();
                for (auto employee : emp_table){
                    file << employee.roll_number << " " << employee.name << " " << employee.specialization << " " << employee.salary << std::endl;
                }
            }
            file.close();
        }
        ~Employee(){
            emp_table.clear();
        }
        // create
        void create_new_employee(int roll_number, std::string name, std::string specialization, double salary){
            emp_table.emplace_back(roll_number, name, specialization, salary);
            save_new_data();
        }
        // delete
        void delete_employee(int emp_roll_number){
            auto it = std::find_if(emp_table.begin(), emp_table.end(), [emp_roll_number](const EmpData& employee){
                return employee.roll_number == emp_roll_number;
            });
            if (it != emp_table.end()){
                emp_table.erase(it);
            }
            save_new_data();
        }
        // read
       /*  EmpData display_by_roll_number(int emp_roll_number){
            for (auto employee : emp_table){
                if (employee.roll_number == emp_roll_number)
                    return employee;
            }
            //return NULL;
        }
        EmpData display_by_name(std::string name){
            for (auto employee : emp_table){
                if (employee.name == name)
                return employee;
            }
        } */

        // search
        EmpData search_by_roll_number(int emp_roll_number){
            auto it = std::find_if(emp_table.begin(), emp_table.end(), [emp_roll_number](const EmpData& employee){
                return employee.roll_number == emp_roll_number;
            });
            if (it != emp_table.end())
                return *it;
            return EmpData{};
        }

        EmpData search_by_name(std::string emp_name){
            auto it = std::find_if(emp_table.begin(), emp_table.end(), [emp_name](const EmpData& employee){
                return employee.name == emp_name;
            });
            if (it != emp_table.end())
                return *it;
            return EmpData{};
        }

        // update
        bool update_name_by_roll_number(int emp_roll_number, std::string& new_name){
            bool found = false;
            for (auto employee : emp_table){
                if(employee.roll_number == emp_roll_number){
                    employee.set_name(new_name);
                    save_new_data();
                    found = true;
                    break;
                }    
            }
            return found;
        }
        bool update_salary_by_roll_number(int emp_roll_number, double new_salary){
            bool found = false;
            for (auto employee : emp_table){
                if(employee.roll_number == emp_roll_number){
                    employee.set_salary(new_salary);
                    save_new_data();
                    found = true;
                    break;
                }    
            }
            return found;
        }
        bool update_specialization_by_roll_number(int emp_roll_number, std::string new_specialization){
            bool found = false;
            for (auto employee : emp_table){
                if(employee.roll_number == emp_roll_number){
                    employee.set_specialization(new_specialization);
                    save_new_data();
                    found = true;
                    break;
                }    
            }
            return found;
        }
};

#endif