#include <iostream>
#include <string>

using namespace std;

const string alphabet = "abcdefghijklmnopqrstuvwxyz";

/**
 * @brief Encrypts a message using the substitution cipher method
 * @param message_buf The message to encrypt
 * @param key_buf The key to use for encryption
 * @return The encrypted message
 */
static string encrypt_message(const string& message_buf, const string& key_buf)
{
    string enc_out;
    size_t pos = 0;

    for (char c: message_buf)
    {
        pos = alphabet.find(c);
        if(pos != string::npos)
        {
            enc_out += key_buf.at(pos);
        }
        else
        {
            enc_out += c; // Non-alphabetic characters remain unchanged
        }
    }

    return enc_out;
}

/**
 * @brief Decrypts a message using the substitution cipher method
 * @param cipher_buf The encrypted message to decrypt
 * @param key_buf The key to use for decryption
 * @return The decrypted message
 */
static string decrypt_message(const string& cipher_buf, const string& key_buf)
{
    string dec_out;
    size_t pos = 0;

    for(char c: cipher_buf)
    {
        pos = key_buf.find(c);
        if(pos != string::npos)
        {
            dec_out += alphabet.at(pos);
        }
        else
        {
            dec_out += c; // Non-alphabetic characters remain unchanged
        }
    }

    return dec_out;
}

/** 
* @brief Verifies if the key is valid. A valid key should have the same length as the alphabet and should contain all the letters in the alphabet without any duplicates.
* @param key_buf The key to verify
* @return true if the key is valid, false otherwise
*/
static bool verify_key(const string& key_buf)
{
    size_t pos = 0;

     // check if all letters are covered in key (no multipple occurens)
    for( char c: alphabet)
    {
        pos = key_buf.find(c);
        if(pos == std::string::npos)
        {
            cout << "Key is missing letter: " << c << endl;
            return false;
        }
    }

    // check if key equals the alphabet
    size_t key_len = key_buf.length();
    size_t alphabet_len = alphabet.length();
    if (key_len != alphabet_len)
    {
        cout << "Key length of " << key_len << " does not match alphabet length of " << alphabet_len << endl;
        return false;
    }

    return true;
}

/** @brief Main function for the cipher challenge */
void cipher_challenge()
{
    const string key = "cudqmagxewptvsbfzrnholkjiy";

    bool key_is_correct = verify_key(key);

    if (key_is_correct)
    {
        cout << "Key verifed!" << endl;


        cout << "Enter a secret message: ";
        string message;
        getline(cin, message);

        // Encrypt the message using the substitution cipher method
        string message_encrypted = encrypt_message(message, key);

        cout << "Encrypted msg: " << message_encrypted << endl;

        // Decrypt the original message to verify encryption
        string original_msg = decrypt_message(message_encrypted, key);

        cout << "Original msg: " << original_msg << endl;

        if ( message == original_msg)
        {
            cout << "SUCCESS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }
    }
    else
    {
        cout << "ERROR: incorrect key" << endl;
    }
}

// Copilot suggestion
// static void encrypt_message(const string& message)
// {
//     string encrypted_message;
//     for (char c : message) {
//         if (isalpha(c)) {
//             char lower_c = tolower(c);
//             size_t index = alphabet.find(lower_c);
//             if (index != string::npos) {
//                 char encrypted_char = key.at(index);
//                 encrypted_message += isupper(c) ? toupper(encrypted_char) : encrypted_char;
//             } else {
//                 encrypted_message += c; // Non-alphabetic characters remain unchanged
//             }
//         } else {
//             encrypted_message += c; // Non-alphabetic characters remain unchanged
//         }
//     }

//     cout << "Encrypted message: " << encrypted_message << endl;

//     // Decrypt the message and display the original message
//     decrypt_message(encrypted_message);
// }