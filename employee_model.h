#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include "sqlite_orm.h"
#include"employee_data.h"

using namespace sqlite_orm;

#ifndef EMPLOYEE
#define EMPLOYEE

class Employee{
    private:
    
    std::string data_base;

    decltype(make_storage({},
    make_table("employees",
    make_column("roll_number", &EmpData::roll_number, primary_key()),
    make_column("name", &EmpData::name),
    make_column("specialization", &EmpData::specialization),
    make_column("salary", &EmpData::salary)))) storage;

    std::vector<EmpData> emp_table;
    public:
        Employee() : storage(make_storage("employee.db",
            make_table("employees",
                make_column("roll_number", &EmpData::roll_number, primary_key()),
                make_column("name", &EmpData::name),
                make_column("specialization", &EmpData::specialization),
                make_column("salary", &EmpData::salary)
            )
        )) {
            storage.sync_schema();
            get_all_employee();
        }
        void get_all_employee(){
            emp_table = storage.get_all<EmpData>();
        }
        void save_new_data(){
            storage.replace(emp_table.begin(), emp_table.end());
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
        bool delete_employee(int roll_number) {
            auto deleted = storage.remove_all<EmpData>(where(c(&EmpData::roll_number) == roll_number));
            get_all_employee(); // Refresh employee data after deletion
            return deleted > 0;
        }

        // search
        EmpData search_by_roll_number(int roll_number) {
            return storage.get_all<EmpData>(where(c(&EmpData::roll_number) == roll_number)).front_or(EmpData{});
        }

        // update
        bool update_name_by_roll_number(int roll_number, const std::string& new_name){
            auto updated = storage.update<EmpData>(
                set(c(&EmpData::name) = new_name),
                where(c(&EmpData::roll_number) == roll_number)
            );
            get_all_employee(); // Refresh employee data after update
            return updated > 0;
        }

        bool update_salary_by_roll_number(int roll_number, double new_salary){
             auto updated = storage.update<EmpData>(
                set(c(&EmpData::salary) = new_salary),
                where(c(&EmpData::roll_number) == roll_number)
            );
            get_all_employee(); // Refresh employee data after update
            return updated > 0;
        }

        bool update_specialization_by_roll_number(int roll_number, const std::string& new_specialization){
             auto updated = storage.update<EmpData>(
                set(c(&EmpData::specialization) = new_specialization),
                where(c(&EmpData::roll_number) == roll_number)
            );
            get_all_employee(); // Refresh employee data after update
            return updated > 0;
        }


       /*  void delete_employee(int emp_roll_number){
            auto it = std::find_if(emp_table.begin(), emp_table.end(), [emp_roll_number](const EmpData& employee){
                return employee.roll_number == emp_roll_number;
            });
            if (it != emp_table.end()){
                emp_table.erase(it);
            }
            save_new_data();
        } */

        /* EmpData search_by_roll_number(int emp_roll_number){
            auto it = std::find_if(emp_table.begin(), emp_table.end(), [emp_roll_number](const EmpData& employee){
                return employee.roll_number == emp_roll_number;
            });
            if (it != emp_table.end())
                return *it;
            return EmpData{};
        } */

        /* EmpData search_by_name(std::string emp_name){
            auto it = std::find_if(emp_table.begin(), emp_table.end(), [emp_name](const EmpData& employee){
                return employee.name == emp_name;
            });
            if (it != emp_table.end())
                return *it;
            return EmpData{};
        } */

       /*  bool update_name_by_roll_number(int emp_roll_number, std::string& new_name){
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
        } */

         /* bool update_salary_by_roll_number(int emp_roll_number, double new_salary){
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
        } */

        /* bool update_specialization_by_roll_number(int emp_roll_number, std::string new_specialization){
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
        } */
};

#endif