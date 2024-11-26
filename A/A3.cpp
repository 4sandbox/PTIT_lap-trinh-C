//A3. (Date Class) Tạo một lớp đối tượng có tên là Date bao gồm ba thành phần dữ liệu riêng: tháng, ngày và năm, tất cả đều có kiểu unsigned int. 
//Lớp Date nên có một hàm khởi tạo với ba tham số (tháng, ngày, năm) để khởi tạo ba thành phần dữ liệu của nó. 
//Lớp Date cũng phải cung cấp một hàm thành viên public gọi là StringDate() để trả về một chuỗi theo định dạng tháng/ngày/năm.
//Viết một hàm main() để kiểm tra các cài đặt của lớp Date.
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

int main() {
    Date today(11, 26, 2024);
    std::cout << "Today's date is: " << today.StringDate() << std::endl;
    return 0;
}