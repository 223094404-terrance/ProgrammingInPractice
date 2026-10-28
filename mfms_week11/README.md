# Week 10 Laboratory – Persistent MFMS Storage

## 1. Introduction

This laboratory extends the Municipal Financial Management System (MFMS) by implementing persistent storage using text files and binary files. The system can save data to files and load it again after the program has been closed and restarted.

## 2. Objectives

- Create a data directory for storing application files.
- Save and load employee IDs using text files.
- Save and load budget information using text files.
- Save and load supplier records using text files.
- Save and load asset records using text files.
- Handle file-opening errors.
- Integrate Save Data and Load Data options into the main menu.
- Demonstrate binary-file storage for employee IDs.
- Compare text-file and binary-file storage.

## 3. Project Files

- `main.c` – Main menu and program control.
- `employees.c` and `employees.h` – Employee functions.
- `budget.c` and `budget.h` – Budget calculations.
- `utilities.c` and `utilities.h` – Input utilities.
- `reports.c` and `reports.h` – System reporting.
- `storage.c` and `storage.h` – Employee and budget file storage, including binary employee storage.
- `suppliers.c` and `suppliers.h` – Supplier text-file storage.
- `assets.c` and `assets.h` – Asset text-file storage.
- `data/` – Directory containing saved data files.

## 4. Data Files

The application uses the following files:

- `data/employees.txt` – Stores employee IDs in readable text format.
- `data/budget.txt` – Stores revenue and expenses.
- `data/suppliers.txt` – Stores supplier IDs, names, and prices.
- `data/assets.txt` – Stores asset IDs, names, and values.
- `data/employees.dat` – Stores employee IDs in binary format.

## 5. File Handling and Error Checking

The program uses `fopen()` to open files, `fprintf()` and `fscanf()` to write and read text data, and `fwrite()` and `fread()` to write and read binary data.

The program checks whether files open successfully. If a file cannot be opened, `perror()` displays an error message. File-closing and binary read/write results are also checked in the relevant functions.

## 6. Compilation

Compile the program from the Week10 directory using:

```bash
gcc -std=c99 -Wall -Wextra -pedantic main.c employees.c budget.c utilities.c reports.c storage.c suppliers.c assets.c -o mfms.exe
```

Run the program using:

```bash
./mfms.exe
```

## 7. Testing

The following tests were performed:

1. Compiled the program without compiler errors.
2. Entered budget revenue of 10000 and expenses of 7000.
3. Saved employee IDs and budget information to text files.
4. Loaded and displayed the saved employee IDs and budget information.
5. Saved and loaded supplier records.
6. Saved and loaded asset records.
7. Saved employee IDs in a binary file and loaded them successfully.
8. Exited the program, restarted it, and loaded the saved text data again.

The records appeared after restarting the program, demonstrating persistent file storage.

## 8. Text Files Versus Binary Files

### Text files

Text files store information as readable characters. They can be opened in a text editor, making it easy to inspect and manually edit the contents. However, text data often requires conversion when read by a program and may use more storage for some data types.

### Binary files

Binary files store data as bytes in a representation suitable for the program. They can be compact and efficient to read and write, but their contents are not normally human-readable in a text editor. Binary files can also depend on data type sizes, byte order, and the structure used by the program.

### Practical differences

Text files are useful when data needs to be inspected or exchanged easily. Binary files can be useful when programs need efficient storage and retrieval. Binary storage is not automatically smaller or more portable; the result depends on the data and implementation.

## 9. Conclusion

The Week 10 laboratory demonstrates persistent storage using text files and binary files. The system saves and loads employee, budget, supplier, and asset data. Testing confirmed that saved text data remained available after the application was restarted. The laboratory also demonstrates file error handling and the practical differences between text and binary storage.
