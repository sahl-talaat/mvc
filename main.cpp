#include<iostream>
#include<functional>
#include<map>

#include "httplib.h"

#include"employee_model.h"
#include"controller.h"
#include"view.h"


int main(){
    std::string file_name = "employee.txt";
    Employee *employee;
    employee->get_all_employee();
    View view;
    Controller controller(employee, view);
  
    httplib::Server server ;
    server.listen("localhost",8000);

    // add new employee
    /* server.Post("/employees/add",  [&controller](const httplib::Request& req, httplib::Response& res) {
    controller.create_new(req, res);}); */

    // search
    /* server.Get("/employees/search",  [&controller](const httplib::Request& req, httplib::Response& res) {
    controller.search(req, res);}); */

    // update
    /* server.Put("/employees/update",  [&controller](const httplib::Request& req, httplib::Response& res) {
    controller.update(req, res);}); */

    // delete
    /* server.Put("/employees/remove",  [&controller](const httplib::Request& req, httplib::Response& res) {
    controller.remove(req, res);}); */


    
   
    


    return 0;
}