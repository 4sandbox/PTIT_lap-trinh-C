//A4. Trong việc định vị, vị trí được đo bằng độ và phút của cặp vĩ độ và kinh độ; ví dụ 149 độ 34,8 phút kinh độ tây và 17 độ 31,5 phút vĩ độ nam, 
//được viết là 149°34.8’ Tây, 17°31.5’ Nam. Có 60 phút trong một độ. Kinh độ được đo từ 0 đến 180 độ, về phía đông hoặc tây bắt đầu từ kinh tuyến Greenwich, Anh.
//Vĩ độ được đo từ 0 đến 90 độ, về phía bắc hoặc nam tính từ xích đạo đến các cực.
//Tạo một lớp góc (Angle) bao gồm ba biến thành viên: một số nguyên cho độ, một số thực cho phút, và một ký tự cho chữ cái chỉ hướng (N, S, E, hoặc W). 
//Lớp này chỉ chứa một biến vĩ độ hoặc một biến kinh độ. Viết một hàm thành viên để cập nhật giá trị của góc (độ và phút) cùng với hướng, 
//và một hàm thứ hai để lấy giá trị góc hiển thị theo định dạng 179°59.9’ E. Cũng hãy viết một hàm khởi tạo cho lớp Angle với ba tham số.
#include <iostream>
#include <string>

class Angle {
private:
    int degrees;
    float minutes;
    char direction;

public:
    Angle(int degrees, float minutes, char direction) 
        : degrees(degrees), minutes(minutes), direction(direction) {}

    std::string display() const {
        return std::to_string(degrees) + "°" + std::to_string(minutes) + "'" + direction;
    }
};

int main() {
    Angle angle(149, 34.8, 'W');
    std::cout << "Angle: " << angle.display() << std::endl;

    int deg;
    float min;
    char dir;

    while (true) {
        std::cout << "Enter angle (degrees minutes direction): ";
        std::cin >> deg >> min >> dir;
        Angle userAngle(deg, min, dir);
        std::cout << "You entered: " << userAngle.display() << std::endl;
    }

    return 0;
}