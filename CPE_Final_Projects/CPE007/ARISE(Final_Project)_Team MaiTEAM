#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
};

const string INVENTORY_FILE = "inventory.csv";
const string USERS_FILE = "users.txt";

// Function declarations
bool login();
void registerUser();
void addProduct(vector<Product> &inventory);
void viewProducts(const vector<Product> &inventory);
void editProduct(vector<Product> &inventory);
void deleteProduct(vector<Product> &inventory);
void sellProduct(vector<Product> &inventory);
void saveToFile(const vector<Product> &inventory);
void loadFromFile(vector<Product> &inventory);
void inventoryMenu(vector<Product> &inventory);

// ================= MAIN =================
int main() {
    int choice;
    vector<Product> inventory;
    loadFromFile(inventory);

    cout << "=== Welcome to ARISE (Automated Retail Inventory System for Efficiency) ===\n";

    do {
        cout << "\n[1] Login\n";
        cout << "[2] Register\n";
        cout << "[3] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (login()) {
                inventoryMenu(inventory);
            }
        } 
        else if (choice == 2) {
            registerUser();
        } 
        else if (choice != 3) {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    cout << "Goodbye!\n";
    return 0;
}

// ================= LOGIN SYSTEM =================
bool login() {
    string username, password;
    cout << "\n=== Login ===\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream inFile(USERS_FILE);
    if (!inFile) {
        cout << "No users registered yet. Please register first.\n";
        return false;
    }

    string u, p;
    while (inFile >> u >> p) {
        if (u == username && p == password) {
            cout << "Login successful! Welcome, " << username << ".\n";
            return true;
        }
    }

    cout << "Invalid username or password.\n";
    return false;
}

void registerUser() {
    string username, password;
    cout << "\n=== Register ===\n";
    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;

    ofstream outFile(USERS_FILE, ios::app);
    if (!outFile) {
        cerr << "Error: Unable to open user file.\n";
        return;
    }

    outFile << username << " " << password << endl;
    outFile.close();
    cout << "Registration successful! You can now log in.\n";
}

// ================= INVENTORY MENU =================
void inventoryMenu(vector<Product> &inventory) {
    int choice;
    do {
        cout << "\n=== Automated Retail Inventory System for Efficiency (ARISE) ===\n";
        cout << "[1] Add Product\n";
        cout << "[2] View Products\n";
        cout << "[3] Edit Product\n";
        cout << "[4] Delete Product\n";
        cout << "[5] Sell Product\n"; 
        cout << "[6] Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(10000, '\n');

        switch (choice) {
            case 1: addProduct(inventory); saveToFile(inventory); break;
            case 2: viewProducts(inventory); break;
            case 3: editProduct(inventory); saveToFile(inventory); break;
            case 4: deleteProduct(inventory); saveToFile(inventory); break;
            case 5: sellProduct(inventory); break; 
            case 6:
                saveToFile(inventory);
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
}


// ================= INVENTORY FUNCTIONS =================
void addProduct(vector<Product> &inventory) {
    Product p;
    cout << "\nEnter Product Name: ";
    getline(cin, p.name);

    for (const auto &item : inventory) {
        if (item.name == p.name) {
            cout << "Product already exists. Try editing instead.\n";
            return;
        }
    }

    cout << "Enter Price: ";
    cin >> p.price;
    cout << "Enter Quantity: ";
    cin >> p.quantity;
    cin.ignore(10000, '\n');

    inventory.push_back(p);
    cout << "\nProduct added successfully!\n";
}

void viewProducts(const vector<Product> &inventory) {
    if (inventory.empty()) {
        cout << "\nNo products in inventory.\n";
        return;
    }

    cout << "\n=== Product List ===\n";
    cout << left << setw(20) << "Name"
         << setw(10) << "Price"
         << setw(10) << "Quantity" << endl;
    cout << "---------------------------------------------\n";

    for (const auto &p : inventory) {
        cout << left << setw(20) << p.name
             << setw(10) << fixed << setprecision(2) << p.price
             << setw(10) << p.quantity << endl;
    }
}

void editProduct(vector<Product> &inventory) {
    if (inventory.empty()) {
        cout << "\nNo products to edit.\n";
        return;
    }

    string name;
    cout << "\nEnter Product Name to edit: ";
    getline(cin, name);

    for (auto &p : inventory) {
        if (p.name == name) {
            cout << "Editing product: " << p.name << endl;
            cout << "Enter new name: ";
            getline(cin, p.name);
            cout << "Enter new price: ";
            cin >> p.price;
            cout << "Enter new quantity: ";
            cin >> p.quantity;
            cin.ignore(10000, '\n');
            cout << "\nProduct updated successfully!\n";
            return;
        }
    }

    cout << "Product not found.\n";
}

void deleteProduct(vector<Product> &inventory) {
    if (inventory.empty()) {
        cout << "\nNo products to delete.\n";
        return;
    }

    string name;
    cout << "\nEnter Product Name to delete: ";
    getline(cin, name);

    for (size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i].name == name) {
            cout << "Deleting product: " << inventory[i].name << endl;
            inventory.erase(inventory.begin() + i);
            cout << "\nProduct deleted successfully!\n";
            return;
        }
    }

    cout << "Product not found.\n";
}

void sellProduct(vector<Product> &inventory) {
    if (inventory.empty()) {
        cout << "\nNo products available for sale.\n";
        return;
    }

    string name;
    int qtyToBuy;
    double payment;

    cout << "\nEnter Product Name to sell: ";
    getline(cin, name);

    for (auto &p : inventory) {
        if (p.name == name) {
            cout << "Enter quantity to sell: ";
            cin >> qtyToBuy;

            if (qtyToBuy <= 0) {
                cout << "Invalid quantity.\n";
                return;
            }

            if (qtyToBuy > p.quantity) {
                cout << "Not enough stock available.\n";
                return;
            }

            double total = p.price * qtyToBuy;
            cout << "Total amount: P" << fixed << setprecision(2) << total << endl;
            cout << "Enter payment: P";
            cin >> payment;

            if (payment < total) {
                cout << "Insufficient payment.\n";
                return;
            }

            double change = payment - total;
            p.quantity -= qtyToBuy;

            saveToFile(inventory); // Real-time update
            cout << "\nTransaction successful!\n";
            cout << "Change: P" << fixed << setprecision(2) << change << endl;
            return;
        }
    }

    cout << "Product not found.\n";
}


void saveToFile(const vector<Product> &inventory) {
    ofstream outFile(INVENTORY_FILE);
    if (!outFile) {
        cerr << "Error saving file.\n";
        return;
    }

    // Header row
    outFile << "Name,Price,Quantity\n";

    // Write product data   
    for (const auto &p : inventory) {
        outFile << "\"" << p.name << "\"," << p.price << "," << p.quantity << "\n";
    }

    outFile.close();
}

void loadFromFile(vector<Product> &inventory) {
    ifstream inFile(INVENTORY_FILE);
    if (!inFile) {
        cout << "(No existing inventory file found — starting new.)\n";
        return;
    }

    inventory.clear();
    string line;
    while (getline(inFile, line)) {
        Product p;
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        if (pos1 != string::npos && pos2 != string::npos) {
            p.name = line.substr(0, pos1);
            p.price = stod(line.substr(pos1 + 1, pos2 - pos1 - 1));
            p.quantity = stoi(line.substr(pos2 + 1));
            inventory.push_back(p);
        }
    }

    inFile.close();
}
