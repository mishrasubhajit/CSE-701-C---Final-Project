# CSE-701-C---Final-Project

1. This is a basic RSA encryption algorithm written for the purpose of CSE 701 project. This is by no means a program that can be commercially used.

2. The BigInt class I have used is taken from [here](https://github.com/srndic/rsa/blob/master/source/BigInt.cpp). A few changes were to made to accomodate my program and a few errors were resolved.

3. This is my first time programming. It is evident that the program is not sophisticated.

4. The program has been run with O2 optimization. There was a problem while running the program in debugging mode. It starting showing Breakpoint Trap in the descrutor of BigInt class. I tried but couldn't fix the issue. But somehow, running without debugging and with O2 optimization doesn't show any error.

5. The program takes a test.txt file as input, encrypts it in encrypt.bin file and decrypts in decrypt.bin file in one go.

6. To run the program, I used Ctrl+Shift+B and then bigint.

7. The reason I had to compile this in one go are the following: even though, the main program and the rsa.hpp, rsa.cpp are same, somehow while trying to separate encryption and decryption as two separate calls creates a problem in decryption. Somehow, it didn't read the encrypted file and started giving segmentation fault. Even with the optimization, there was no solution. I tried but didn't able to solve it. Hence, I had to go for the program at one go.

8. I checked the drMemory. There are some memory leaks in BigInt. I couldn't solve them.

9. The vector overload header file is the header file from the class, written by our Prof Barak Shoshany.

10. One other problem: I had to use to sizeof(uint8_t) while reading the file instead of bigger chunks. This is because the later one didn't gave the expected result. With larger chunks, the binary files were not even getting copied correctly. I belive this has something to do with the representation of BigInt.

11. I don't know hwhat more should I explain but I really tried to make encryption and decryption separately but it just didn't work.

12. I confess, the program can't be considered as a good program at all. But I hope to build on my first programming course and first programming project, and improve in the future.
