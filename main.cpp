#include<iostream>
#include"employee_model.h"
#include"controller.h"
#include"view.h"

int main(){
    std::string file_name = "employee.txt";
    Employee employee(file_name);
    View view;
    Controller controller(employee, view);
    controller.access_all_data();
    controller.create_employee(120,"sahl","enginerr",2050.20);
    controller.create_employee(150,"sami","developper",3020.20);
    controller.create_employee(80,"rami","security",1080.20);
    controller.create_employee(99,"hani","manager",8040.20);
    controller.search_by_roll_number(120);
    controller.remove_employee(120);
    controller.search_by_roll_number(120);
    controller.search_by_name("hani");


    return 0;
}