## 103cipher

Cryptography is a very old science, whose goal is to secure communication, so that only its recipient could
read it.
There are a lot of methods to encrypt a message, from the simplest (such as the 2,000-year-old Caesar
cipher) to the most complex (such as the World War 2 Enigma code); they all need both encryption and
decryption keys (sometimes identical).
In some cases (such as the Hill cipher), the key is represented by a matrix.

You have to carry out such a matrix-based ciphering software, using the following process to encrypt:

• Transcript the key into numbers using the ASCII table,

• Convert the numbered key into a square matrix, the smallest possible size, and filling the lines first,

• Transcript the clear message into numbers using the ASCII table,

• Convert the numbered message into a matrix; its number of columns should fit the key matrix size, and its number of lines should be as small as possible,

• Multiply the 2 matrices, and write the answer linearly to get the encrypted message.

#### The decryption process logically follows from the previous encryption method, using the same key (be careful! You need to inverse the key matrix, which is not always possible).

Usage: 
./103cipher message key flag: 

• Message:   message, made of ASCII characters key

• Key:       the encryption key, made of ASCII characters flag

• Flag:      0 for the message to be encrypted, 1 to be decrypted

Example:

![image](https://user-images.githubusercontent.com/65818912/158445721-e8d32df9-1bee-4547-8806-1f7ed161ff8e.png)
