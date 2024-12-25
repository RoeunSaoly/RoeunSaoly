#include <iostream>
#include <vector>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    double price;
    int stock;

    Book(std::string t, std::string a, double p, int s) : title(t), author(a), price(p), stock(s) {}
};

class BookShop {
private:
    std::vector<Book> inventory;

public:
    // Admin functions
    void addBook(const Book& book) {
        inventory.push_back(book);
        std::cout << "Book added successfully.\n";
    }

    void removeBook(const std::string& title) {
        for (auto it = inventory.begin(); it != inventory.end(); ++it) {
            if (it->title == title) {
                inventory.erase(it);
                std::cout << "Book removed successfully.\n";
                return;
            }
        }
        std::cout << "Book not found.\n";
    }

    void updateBookStock(const std::string& title, int newStock) {
        for (auto& book : inventory) {
            if (book.title == title) {
                book.stock = newStock;
                std::cout << "Stock updated successfully.\n";
                return;
            }
        }
        std::cout << "Book not found.\n";
    }

    // Client functions
    void viewBooks() const {
        std::cout << "Available books:\n";
        for (const auto& book : inventory) {
            std::cout << "Title: " << book.title << ", Author: " << book.author
                      << ", Price: $" << book.price << ", Stock: " << book.stock << "\n";
        }
    }

    void buyBook(const std::string& title) {
        for (auto& book : inventory) {
            if (book.title == title) {
                if (book.stock > 0) {
                    book.stock--;
                    std::cout << "Book purchased successfully.\n";
                } else {
                    std::cout << "Book out of stock.\n";
                }
                return;
            }
        }
        std::cout << "Book not found.\n";
    }
};
void displayMenu() {
    std::cout << "1. Add Book\n";
    std::cout << "2. Remove Book\n";
    std::cout << "3. Update Book Stock\n";
    std::cout << "4. View Books\n";
    std::cout << "5. Buy Book\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

void handleUserInput(BookShop& shop) {
    int choice;
    std::string title, author;
    double price;
    int stock;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter author: ";
                std::getline(std::cin, author);
                std::cout << "Enter price: ";
                std::cin >> price;
                std::cout << "Enter stock: ";
                std::cin >> stock;
                shop.addBook(Book(title, author, price, stock));
                break;
            case 2:
                std::cout << "Enter title of the book to remove: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                shop.removeBook(title);
                break;
            case 3:
                std::cout << "Enter title of the book to update stock: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter new stock: ";
                std::cin >> stock;
                shop.updateBookStock(title, stock);
                break;
            case 4:
                shop.viewBooks();
                break;
            case 5:
                std::cout << "Enter title of the book to buy: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                shop.buyBook(title);
                break;
            case 6:
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main() {
    BookShop shop;

    // Admin adds books
    shop.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 10.99, 5));
    shop.addBook(Book("1984", "George Orwell", 8.99, 3));

    // Handle user input
    handleUserInput(shop);

    return 0;
}