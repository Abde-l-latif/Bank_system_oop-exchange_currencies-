🏦 Bank System with Currency Exchange

A C++ console-based Bank Management System built using Object-Oriented Programming (OOP) principles.
This project simulates real-world banking operations such as managing users and clients, handling transactions, and performing currency exchanges.

✨ Features
🔑 Authentication & Users

Secure login system with username/password.

User management (add, update, delete, list).

Access control through permissions.

👤 Clients

Add new bank clients.

Update client information.

Delete clients safely.

Search/find clients by ID or name.

View all clients in the system.

💰 Transactions

Deposit money into accounts.

Withdraw funds (with balance checks).

Transfer between accounts (with logs).

Check total balance for all clients.

💱 Currency Exchange

Built-in currency database.

Currency calculator.

List available currencies.

📁 Data Persistence

Stores data in text files (Users.txt, bank_clients.txt).

Keeps a transaction log.

🏗️ Project Structure
📂 Bank_system_oop-exchange_currencies-
 ┣ 📄 bank_system(oop).cpp         # Main entry point
 ┣ 📄 cls_user.h                   # User class (login, permissions)
 ┣ 📄 cls_bank_client.h            # Bank client class
 ┣ 📄 cls_currency.h               # Currency entity
 ┣ 📄 cls_currency_calculator.h    # Currency conversion logic
 ┣ 📄 cls_login.h / cls_login_screen.h
 ┣ 📄 cls_transaction_menu.h
 ┣ 📄 cls_transfer_screen.h
 ┣ 📄 cls_util.h                   # Helper utilities
 ┣ 📄 Users.txt                    # User data storage
 ┣ 📄 bank_clients.txt             # Client data storage
 ┗ ... (many screen classes for menus & UI)

🎮 Usage Example

Start the program.

Log in with a valid username/password.

Choose from the main menu:

Manage clients

Manage users

Transactions (deposit, withdraw, transfer)

Currency exchange

Data is automatically saved in text files.

📚 Concepts Practiced

Object-Oriented Programming (OOP)

Class design and modularity

File handling (read/write)

Input validation

Menu-driven console apps

Separation of concerns

🔮 Future Improvements

Switch from text files → database (SQLite/MySQL).

Add proper error handling & input validation.

Implement unit tests.

GUI version with Qt or web-based frontend.
