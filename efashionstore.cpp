#include <iostream>
#include <string>
using namespace std;

const int items = 5;

class Product {
public:
    int productID;
    string name;
    float price;

    Product() {
        productID = 0;
        name = "Not Set";
        price = 0;
    }
    Product(int id, string n, float p) {
        productID = id;
        name = n;
        price = p;
    }
    Product(const Product &p) {
        productID = p.productID;
        name = p.name;
        price = p.price;
    }

    void setProduct() {
        cout << "\nEnter Product ID: ";
        cin >> productID;
        cin.ignore();
        cout << "Enter Product Name: ";
        getline(cin, name);
        cout << "Enter Product Price: ";
        cin >> price;
    }

    void displayProduct() const {
        cout << "Product ID: " << productID
             << "\nName: " << name
             << "\nPrice: " << price << endl;
    }
};

class Customer {
public:
    int customerID;
    string name;

    void setCustomer() {
        cout << "\nEnter Customer ID: ";
        cin >> customerID;
        cin.ignore();
        cout << "Enter Customer Name: ";
        getline(cin, name);
    }

    void displayCustomer() const {
        cout << "\nCustomer ID: " << customerID
             << "\nName: " << name << endl;
    }
};

class Shipping {
public:
    string address;

    void setShipping() {
        cin.ignore();
        cout << "Enter Shipping Address: ";
        getline(cin, address);
    }

    void displayShipping() const {
        cout << "Shipping Address: " << address << endl;
    }
};

class Order : public Product {
private:
    Customer customer;
    Product products[items];
    int quantities[items];
    int itemCount;
    static int totalOrders;

public:
    Order() : itemCount(0) {}

    static int getOrderCount() {
        return totalOrders;
    }

    void greeting(string msg = "Welcome to Snatch E-Fashion Store!") {
        cout << msg << endl;
    }

    void createOrder() {
        customer.setCustomer();
        cout << "\nHow many products do you want to buy? (Max " << items << "): ";
        cin >> itemCount;
        if (itemCount > items || itemCount <= 0) {
            cout << "Invalid choice. Setting to 1 item.\n";
            itemCount = 1;
        }
        for (int i = 0; i < itemCount; i++) {
            cout << "\nEnter details for Product " << i + 1;
            products[i].setProduct();
            cout << "Enter Quantity: ";
            cin >> quantities[i];
        }
        totalOrders++;
        cout << "\nOrder Created Successfully!\n";
    }

    void displayOrder() const {
        customer.displayCustomer();
        float total = 0;
        cout << "\nORDER DETAILS (Without Discount)" << endl;
        for (int i = 0; i < itemCount; i++) {
            float subtotal = products[i].price * quantities[i];
            products[i].displayProduct();
            cout << "Quantity: " << quantities[i]
                 << " | Subtotal: " << subtotal << "\n\n";
            total += subtotal;
        }
        cout << "Final Total: " << total << endl;
    }

    void displayOrder(float discount) const {
        customer.displayCustomer();
        float total = 0;
        cout << "\nORDER DETAILS (With Discount)" << endl;
        for (int i = 0; i < itemCount; i++) {
            float subtotal = products[i].price * quantities[i];
            products[i].displayProduct();
            cout << "Quantity: " << quantities[i]
                 << " | Subtotal: " << subtotal << "\n\n";
            total += subtotal;
        }
        float disamt = total * (discount / 100);
        float fintotal = total - disamt;
        cout << "Discount applied: " << discount << "%" << endl;
        cout << "Total amount with discount applied: " << fintotal << endl;
    }

    friend void onlytotal(const Order &o);

    Order operator+(const Order &o2) {
        Order newOrder;
        newOrder.customer = this->customer;
        newOrder.itemCount = this->itemCount + o2.itemCount;
        if (newOrder.itemCount > items) {
            cout << "Maximum items reached." << endl;
            newOrder.itemCount = items;
        }
        int idx = 0;
        for (int i = 0; i < this->itemCount && idx < items; i++, idx++) {
            newOrder.products[idx] = this->products[i];
            newOrder.quantities[idx] = this->quantities[i];
        }
        for (int i = 0; i < o2.itemCount && idx < items; i++, idx++) {
            newOrder.products[idx] = o2.products[i];
            newOrder.quantities[idx] = o2.quantities[i];
        }
        return newOrder;
    }
};

int Order::totalOrders = 0;

void onlytotal(const Order &o) {
    float ttl = 0;
    for (int i = 0; i < o.itemCount; i++) {
        ttl += o.products[i].price * o.quantities[i];
    }
    cout << "\nFinal price without discount (Friend Function): " << ttl << endl;
}

class Discount {
    float discount;
public:
    Discount(float d = 0) : discount(d) {}

    void operator++() { ++discount; }
    void operator--() { --discount; }

    void showDiscount() {
        cout << "Current Discount = " << discount << "%" << endl;
    }
};

class FullOrder : public Order, public Shipping {
public:
    void createFullOrder() {
        Order::createOrder();
        setShipping();
    }
    void displayFullOrder() const {
        Order::displayOrder();
        displayShipping();
    }
};

class OnlineOrder : public FullOrder {
    string paymentMode;
public:
    void setPayment() {
        cout << "Enter Payment Mode (UPI/Credit Card/COD): ";
        cin >> paymentMode;
    }
    void displayPayment() const {
        cout << "Payment Mode: " << paymentMode << endl;
    }
};

int main() {
    FullOrder fullOrder;
    OnlineOrder onlineOrder;
    int choice;

    do {
        cout << "\n==== E-Fashion Store Menu ====";
        cout << "\n1. Create Full Order with Shipping";
        cout << "\n2. View Full Order Summary";
        cout << "\n3. Show Default Arguments Example";
        cout << "\n4. Demonstrate Constructors";
        cout << "\n5. Static Function Example";
        cout << "\n6. Unary Operator Overloading Example";
        cout << "\n7. Binary Operator Overloading Example";
        cout << "\n8. Multilevel Inheritance Example (Online Order)";
        cout << "\n9. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                fullOrder.createFullOrder();
                break;
            case 2:
                fullOrder.displayFullOrder();
                break;
            case 3: {
                Order o;
                o.greeting();
                o.greeting("Hello Customer, Enjoy Shopping!");
                break;
            }
            case 4: {
                Product p1;
                Product p2(101, "Shirt", 499);
                Product p3(p2);
                cout << "\nConstructors Demonstration:" << endl;
                p1.displayProduct();
                p2.displayProduct();
                p3.displayProduct();
                break;
            }
            case 5:
                cout << "Total Orders so far = " << Order::getOrderCount() << endl;
                break;
            case 6: {
                Discount d(5);
                d.showDiscount();
                ++d;
                d.showDiscount();
                --d;
                d.showDiscount();
                break;
            }
            case 7: {
                Order o1, o2, o3;
                cout << "Create First Order:" << endl;
                o1.createOrder();
                cout << "Create Second Order:" << endl;
                o2.createOrder();
                o3 = o1 + o2;
                cout << "\nCombined Order Summary:" << endl;
                o3.displayOrder();
                break;
            }
            case 8:
                onlineOrder.createFullOrder();
                onlineOrder.setPayment();
                onlineOrder.displayFullOrder();
                onlineOrder.displayPayment();
                break;
            case 9:
                cout << "\nThank you for shopping with us!!!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 9);

    return 0;
}

