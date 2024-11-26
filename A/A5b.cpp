//A5b(A4,A5a). Tạo một lớp gọi là Ship (tàu), gồm số hiệu và vị trí của tàu. 
//Sử dụng phương pháp của Bài Tập A5a để đánh số cho từng đối tượng tàu khi nó được tạo ra. 
//Sử dụng hai biến thuộc lớp góc từ Bài tập A4 để đại diện cho vĩ độ và kinh độ của con tàu. 
//Một hàm thành viên của lớp tàu nhận số hiệu và vị trí (vĩ độ, kinh độ) của con tàu để lưu trữ; một hàm khác lấy số hiệu và vị trí để hiển thị (dạng chuỗi).
//Viết một hàm main() khai báo ba con tàu và vị trí của từng con tàu, sau đó hiển thị số hiệu và vị trí của từng con tàu.
#include <iostream>
#include <string>
//class của A4
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
//class của A5a
class Serial {
private:
    static int count;
    int serialNumber;

public:
    Serial() {
        serialNumber = ++count;
    }

    int getSerialNumber() const {
        return serialNumber;
    }
};

class Ship : public Serial {
private:
    Angle latitude;
    Angle longitude;

public:
    Ship(Angle lat, Angle lon) : latitude(lat), longitude(lon) {}

    void display() const {
        std::cout << "Ship Serial: " << getSerialNumber() 
                  << ", Position: " << latitude.display() 
                  << ", " << longitude.display() << std::endl;
    }
};

int Serial::count = 0;

int main() {
    Ship ship1(Angle(17, 31.5, 'S'), Angle(149, 34.8, 'W'));
    Ship ship2(Angle(18, 15.0, 'N'), Angle(150, 45.5, 'E'));
    Ship ship3(Angle(19, 25.2, 'N'), Angle(151, 55.8, 'E'));

    ship1.display();
    ship2.display();
    ship3.display();

    return 0;
}