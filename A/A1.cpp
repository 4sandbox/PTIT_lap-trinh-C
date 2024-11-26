//A1. Hãy xem một trạm thu phí ở một cây cầu. Các xe đi qua trạm thu phí được kỳ vọng sẽ trả 50 xu tiền phí. 
//Hầu hết thì họ đều làm vậy, nhưng đôi khi có một chiếc xe đi qua mà không trả tiền. Trạm thu phí theo dõi số lượng xe đã đi qua và tổng số tiền đã thu được. 
//Mô hình trạm thu phí này được cài đặt chỉ với một lớp gọi là tollBooth. 
//Dữ liệu thành viên của lớp là tổng số xe kiểu unsigned int, và 2) tổng số tiền thu được kiểu double. 
//Một hàm khởi tạo gán cả hai giá trị này thành 0. Một hàm thành viên có tên là payingCar() sẽ tăng tổng số xe lên 1 và cộng thêm 0.50 vào tổng số tiền mặt. 
//Một hàm khác, gọi là nopayCar(), tăng tổng số xe lên 1 nhưng không thêm gì vào tổng tiền mặt. Các hàm thành viên getters dùng để đọc tổng số xe và tổng số tiền.
//Xây dựng một hàm main() để kiểm tra lớp này. Hàm này dùng vòng lặp cho phép người dùng nhấn một phím để đếm xe trả phí và một phím khác để đếm xe không trả phí.
//Nhấn phím Esc sẽ khiến chương trình in ra tổng số xe đi qua, tổng số tiền thu được, và thoát chương trình.
#include <iostream>

class TollBooth {
private:
    unsigned int totalCars;
    double totalMoney;

public:
    TollBooth() : totalCars(0), totalMoney(0.0) {}

    void payingCar() {
        totalCars++;
        totalMoney += 0.50;
    }

    void nopayCar() {
        totalCars++;
    }

    unsigned int getTotalCars() const {
        return totalCars;
    }

    double getTotalMoney() const {
        return totalMoney;
    }
};

int main() {
    TollBooth booth;
    char choice;

    while (true) {
        std::cout << "Nhấn 'p' để trả tiền thu phí, 'n' không trả tiền thu phú, 'Esc' để thoát chương trình: ";
        choice = std::cin.get(); // Use get() to capture single character input

        if (choice == 'p') {
            booth.payingCar();
        } else if (choice == 'n') {
            booth.nopayCar();
        } else if (choice == 27) { // Check for ESC key
            std::cout << "Tổng xe: " << booth.getTotalCars() << "\n";
            std::cout << "Tổng tiền: $" << booth.getTotalMoney() << "\n";
            break;
        }
        std::cin.ignore(); // Ignore the newline character left in the input buffer
    }

    return 0;
}