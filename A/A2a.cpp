//A2a. Hãy tạo một lớp Nhân viên (Employee), có 3 dữ liệu thành viên: mã số nhân viên, tên nhân viên và mức lương của nhân viên. 
//Dữ liệu nên là một số nguyên (unsigned int) để lưu trữ mã số nhân viên, một chuỗi (string) để lưu tên nhân viên và một số thực (float) để lưu mức lương của nhân viên. 
//Các hàm thành viên setemploy(..) và getemploy(..) dùng để khai báo và đọc các loại dữ liệu của đối tượng. Viết hàm main() để khai báo dữ liệu cho ba nhân viên,
// và sau đó hiển thị chúng ra màn hình.
#include <iostream>
#include <string>

class Employee {
private:
    unsigned int id;
    std::string name;
    float salary;

public:
    void setEmploy(unsigned int id, const std::string& name, float salary) {
        this->id = id;
        this->name = name;
        this->salary = salary;
    }

    void getEmploy() const {
        std::cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << "\n";
    }
};

int main() {
    Employee emp1, emp2, emp3;

    emp1.setEmploy(1, "Alice", 50000);
    emp2.setEmploy(2, "Bob", 60000);
    emp3.setEmploy(3, "Charlie", 70000);

    emp1.getEmploy();
    emp2.getEmploy();
    emp3.getEmploy();

    return 0;
}