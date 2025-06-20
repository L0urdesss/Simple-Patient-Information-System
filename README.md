# 🏥 Simple Patient Information System

The **Simple Patient Information System** is a C-based application designed to manage and secure basic patient records using file operations and a simple menu interface. 🩺🔐

This system demonstrates essential programming concepts in C such as:

- 📁 File Handling (`fopen`, `fwrite`, etc.)
- 🧍 Structs for patient records
- 🔒 Basic encryption logic
- 🖥️ Console menu navigation using `switch-case`

### 🧩 Menu Options:

1️⃣ **Add Patient** – Input and save a new patient’s information  
🔍 **Search Patient’s Data** – Look up stored patient data  
🚪 **Exit** – Terminate the program

---

### 🔐 Encryption Rules

The system applies **encryption logic** based on the patient’s record number (entry order):

- **🟢 Odd-numbered entries:**  
  ➤ Encrypts both the **data** and the **folder** where it's stored

- **🔵 Even-numbered entries:**  
  ➤ Encrypts the **data** and the **file** only

This rule-based encryption ensures varying levels of protection depending on the sequence of the entry.

---

🎯 This program is ideal for beginners exploring:

- File I/O in C  
- Struct and string handling  
- Conditional logic and menu control  
- Introductory file encryption concepts  
