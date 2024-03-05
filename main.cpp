#include<iostream>
#include<map>
#include"employee_model.h"
#include"controller.h"
#include"view.h"
#include<functional>
std::map<int, std::function<void()>> registery;

int main(){
    std::string file_name = "employee.txt";
    Employee employee(file_name);
    View view;
    Controller controller(employee, view);
    registery.insert({1, std::bind(&Controller::create_new_employee, &controller)});
    registery.insert({2, std::bind(&Controller::search_by_roll_number, &controller)});
    registery.insert({3, std::bind(&Controller::search_by_name, &controller)});
    registery.insert({4, std::bind(&Controller::update_name_by_roll, &controller)});
    registery.insert({5, std::bind(&Controller::update_specialization_by_roll, &controller)});
    registery.insert({6, std::bind(&Controller::update_salary_by_roll, &controller)});
    registery.insert({7, std::bind(&Controller::remove_employee, &controller)});

    
    while (true)
    {
        int choice = view.index_view();
        registery[choice]();
    }
    


    return 0;
}
