//A5a. Tạo một lớp bao gồm một thành viên dữ liệu giữ một “số sê-ri” cho mỗi đối tượng được tạo ra từ lớp đó. 
//Tức là, đối tượng đầu tiên được tạo ra sẽ được đánh số sê-ri là 1, đối tượng thứ hai là 2, và cứ như vậy. 
//Để làm điều này, bạn sẽ cần một thành viên dữ liệu khác để ghi lại số lượng đối tượng đã được tạo ra cho đến bây giờ. 
//(dữ liệu thành viên này nên áp dụng cho toàn bộ lớp; không phải cho từng đối tượng riêng lẻ.). 
//Khi mỗi đối tượng được tạo ra, hàm khởi tạo của nó có thể kiểm tra biến thành viên này để xác định số sê-ri phù hợp cho đối tượng mới. 
//Viết thêm một hàm thành viên cho phép một đối tượng báo cáo số sê-ri của chính nó. 
//Sau đó, hãy viết một hàm main() tạo ra ba đối tượng và hiển thị số sê-ri của mỗi đối tượng.
#include <iostream>

class Serial {
private:
    static int count; // Static member to keep track of serial numbers
    int serialNumber;

public:
    Serial() {
        serialNumber = ++count;
    }

    int getSerialNumber() const {
        return serialNumber;
    }
};

int Serial::count = 0;

int main() {
    Serial obj1, obj2, obj3;
    std::cout << "Object 1 serial: " << obj1.getSerialNumber() << std::endl;
    std::cout << "Object 2 serial: " << obj2.getSerialNumber() << std::endl;
    std::cout << "Object 3 serial: " << obj3.getSerialNumber() << std::endl;
    return 0;
}