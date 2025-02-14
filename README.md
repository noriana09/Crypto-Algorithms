# 🔐 KeyValue Algorithms

## 📜 Description  
This project implements cryptographic algorithms and a secure key-value storage system using encryption.  

## 🛠️ Part A: Cryptographic Algorithms  
The following encryption methods are implemented:  

- **📝 One-Time Pad**: Uses a randomly generated key of the same length as the plaintext and applies XOR encryption.  
- **🔢 Affine Cipher**: Uses a mathematical formula for letter substitution:  
  - Encryption: `(5x + 8) mod 26`  
  - Decryption: `21(y - 8) mod 26`  
- **🔎 Substitution Cipher Decryption**: Attempts to break a substitution cipher without knowing the key by analyzing letter frequency.  
- **📜 Trithemius Cipher**: Uses a tabular shifting alphabet for polyalphabetic encryption.  
- **🔄 Scytale Cipher**: Encrypts text by wrapping it around a rod of a specific diameter.  
- **⚡ Rail Fence Cipher**: Rearranges letters in a zigzag pattern based on a given number of rails.  

### 📂 Files  
- **cs457_crypto.h**: Function declarations for cryptographic algorithms.  
- **cs457_crypto.c**: Implementation of cryptographic algorithms.  
- **demo.c**: Contains the `main()` function to test encryption and decryption functions.  

## 🔑 Part B: Encrypted Key-Value Storage  
A simple key-value database with AES encryption is implemented, supporting:  
- **➕ Add (`kv add`)**: Encrypts and stores key-value pairs in a file.  
- **🔍 Read (`kv read`)**: Decrypts and retrieves values based on the key.  
- **📊 Range Query (`kv range-read`)**: Retrieves multiple values in a specified range.  
- **🛡️ Security**: Uses **AES encryption** with OpenSSL to protect stored data.  

### 📂 Files  
- **ask7.c**: Implements the key-value storage system (Task 7).  

## 🏗️ Compilation & Execution  

### 🔧 Compile  
make
- Part A :
            ./crypto

- Part B : 

          # Add a key-value pair
          ./ask7 add db.txt <num1> <num2>  

          # Retrieve a value
          ./ask7 read db.txt <num>  

          # Retrieve values in a range
          ./ask7 range-read db.txt <num1> <num2>

