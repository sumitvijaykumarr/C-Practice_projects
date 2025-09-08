#include <SQLiteCpp/SQLiteCpp.h>
#include <iostream>

int main() {
    try {
        // Open a database file
        SQLite::Database db("/home/winner/C-Practice_projects/sqlite_cpp/example_cpp.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

        // Create a new table if not exists
        db.exec("CREATE TABLE IF NOT EXISTS PERSON ("
                "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                "NAME TEXT NOT NULL, "
                "AGE INT NOT NULL)");

        // Insert values using prepared statements
        {
            SQLite::Statement query(db, "INSERT INTO PERSON (NAME, AGE) VALUES (?, ?)");
            query.bind(1, "Alice");
            query.bind(2, 25);
            query.exec();

            query.reset();
            query.bind(1, "Bob");
            query.bind(2, 30);
            query.exec();
        }

        // Select values
        SQLite::Statement query(db, "SELECT ID, NAME, AGE FROM PERSON");

        while (query.executeStep()) {
            int id   = query.getColumn(0);
            std::string name = query.getColumn(1).getText();
            int age   = query.getColumn(2);

            std::cout << "ID=" << id
                      << ", Name=" << name
                      << ", Age=" << age << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "SQLite exception: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
