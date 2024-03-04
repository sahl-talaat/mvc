#include <sqlite_orm/sqlite_orm.h>
#include <string>
#include <memory>

using namespace sqlite_orm;

struct User {
    int id;
    std::string firstName;
    std::string lastName;
    int birthDate;
    std::unique_ptr<std::string> imageUrl;
    int typeId;
};

struct UserType {
    int id;
    std::string name;
};

auto make_connection(std::string database_name) {
    auto storage=make_storage(database_name,
                        make_table("users",
                                   make_column("id", &User::id, primary_key().autoincrement()),
                                   make_column("first_name", &User::firstName),
                                   make_column("last_name", &User::lastName),
                                   make_column("birth_date", &User::birthDate),
                                   make_column("image_url", &User::imageUrl),
                                   make_column("type_id", &User::typeId)));
                                   storage.sync_schema();
    return storage;
}

template<class T>
class code {
public:
    T storage;

    code(T storage) : storage(storage) {}
    void insert_user(User element) {
        storage.insert(element);
    }
};

int main() {
    // in main 
    auto storage = make_connection("ddd.sqlite");
    code<decltype(storage)> model(storage);
    // call in controller
    model.insert_user(User{5, "John", "Doe", 1980, nullptr, 2});
}
