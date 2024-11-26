#include <iostream>
#include <iomanip> // cho std::setw

// B5. Tạo một lớp có tên là Time với các dữ liệu thành viên kiểu int riêng biệt cho giờ, phút và giây.
// Một hàm khởi tạo nên khởi tạo dữ liệu này thành 0, và một hàm khởi tạo khác nên khởi tạo nó với các giá trị cố định.
// Một hàm thành viên khác nên hiển thị nó theo định dạng 11:59:59.
// Hàm thành viên cuối cùng nên cộng hai đối tượng kiểu Time được truyền vào như các tham số.
class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Khởi tạo Time thành 0
    Time() : hours(0), minutes(0), seconds(0) {}

    // Khởi tạo Time với giá trị cố định
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    // Hiển thị thời gian theo định dạng 11:59:59
    void display() const {
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << ":"
                  << std::setw(2) << std::setfill('0') << seconds << std::endl;
    }

    // Cộng hai đối tượng Time
    Time operator+(const Time& other) const {
        Time result;
        result.seconds = seconds + other.seconds;
        result.minutes = minutes + other.minutes + result.seconds / 60;
        result.hours = hours + other.hours + result.minutes / 60;
        result.seconds %= 60;
        result.minutes %= 60;
        result.hours %= 24; // giả sử không vượt qua 24 giờ
        return result;
    }

    // Normalize thời gian
    void normalize() {
        if (seconds < 0) {
            minutes--;
            seconds += 60;
        }
        if (minutes < 0) {
            hours--;
            minutes += 60;
        }
        if (hours < 0) {
            hours += 24;
        }
    }
};

// Hàm main để kiểm tra lớp Time
int main() {
    Time t1(1, 30, 45);
    Time t2(2, 45, 30);
    Time t3; // Time chưa được khởi tạo
    t3 = t1 + t2; // Cộng hai Time
    std::cout << "Kết quả của t1 + t2: ";
    t3.display();

    return 0;
}