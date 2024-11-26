//A2b. Mở rộng lớp nhân viên (Employee) của bài tập A2a để thêm một lớp Date (xem bài tập A3) và một biến etype (loại nhân viên) là một biến kiểu int. 
//Một đối tượng của lớp Date được sử dụng để lưu trữ ngày bắt đầu làm việc; tức là, ngày mà nhân viên được tuyển dụng. 
//Biến etype được sử dụng để lưu trữ loại nhân viên gồm: công nhân (1), thư ký (2), quản lý (3), và các loại khác. 
//Hai mục này là dữ liệu thành viên riêng tư trong lớp, giống như số nhân viên và lương. 
//Bạn sẽ cần cập nhật các hàm setemploy() và getemploy() để khai báo thêm thông tin và lấy dữ liệu. Các hàm này có thể sẽ cần các câu lệnh switch để xử lý biến etype.
//Viết hàm main() để tạo ra ba đối tượng nhân viên và sau đó hiển thị dữ liệu của các đối tượng này.
#include <iostream>
#include <string>

class Date {
private:
    unsigned int month, day, year;

public:
    Date(unsigned int month, unsigned int day, unsigned int year) 
        : month(month), day(day), year(year) {}

    std::string StringDate() const {
        return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
    }
};

class Employee {
private:
    unsigned int id;
    std::string name;
    float salary;
    Date startDate;
    int etype; // 1: Worker, 2: Secretary, 3: Manager

public:
    Employee(unsigned int id, const std::string& name, float salary, Date startDate, int etype) 
        : id(id), name(name), salary(salary), startDate(startDate), etype(etype) {}

    void getEmploy() const {
        std::cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary 
                  << ", Start Date: " << startDate.StringDate() << ", Type: " << etype << "\n";
    }
};

int main() {
    Employee emp1(1, "Alice", 50000, Date(1, 1, 2020), 1);
    Employee emp2(2, "Bob", 60000, Date(2, 1, 2020), 2);
    Employee emp3(3, "Charlie", 70000, Date(3, 1, 2020), 3);

    emp1.getEmploy();
    emp2.getEmploy();
    emp3.getEmploy();

    return 0;
}