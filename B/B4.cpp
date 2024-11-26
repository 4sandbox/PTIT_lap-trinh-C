#include <iostream>
#include <stdexcept>
#include <limits> // cho std::numeric_limits

// B4. Tạo một lớp mô phỏng một phần chức năng của kiểu dữ liệu cơ bản int, gọi là lớp Int.
// Dữ liệu duy nhất trong lớp này là một biến kiểu int. Lớp Int có các hàm thành viên để khởi tạo một Int thành 0,
// để khởi tạo nó thành một giá trị int, để hiển thị nó, và để cộng hai giá trị Int.
// Overload bốn toán tử số nguyên (+, -, *, /) để chúng hoạt động trên các đối tượng kiểu Int.
class Int {
private:
    int value;

public:
    // Khởi tạo Int thành 0
    Int() : value(0) {}

    // Khởi tạo Int với giá trị int
    Int(int val) : value(val) {}

    // Hiển thị giá trị
    void display() const {
        std::cout << value;
    }

    // Hàm cộng hai Int
    Int operator+(const Int& other) const {
        long double result = static_cast<long double>(value) + other.value;
        if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Overflow detected in addition.");
        }
        return Int(static_cast<int>(result));
    }

    // Overload các toán tử số nguyên khác
    Int operator-(const Int& other) const {
        long double result = static_cast<long double>(value) - other.value;
        if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Overflow detected in subtraction.");
        }
        return Int(static_cast<int>(result));
    }

    Int operator*(const Int& other) const {
        long double result = static_cast<long double>(value) * other.value;
        if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Overflow detected in multiplication.");
        }
        return Int(static_cast<int>(result));
    }

    Int operator/(const Int& other) const {
        if (other.value == 0) {
            throw std::runtime_error("Division by zero.");
        }
        long double result = static_cast<long double>(value) / other.value;
        if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Overflow detected in division.");
        }
        return Int(static_cast<int>(result));
    }
};

// Hàm main để kiểm tra lớp Int
int main() {
    Int a(5), b(10);
    Int c; // Int chưa được khởi tạo
    c = a + b; // Cộng hai Int đã khởi tạo
    std::cout << "Kết quả của a + b: ";
    c.display();
    std::cout << std::endl;

    return 0;
}