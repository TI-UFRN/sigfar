#include "../encrypt.hpp"

std::string encrypt(std::string text, std::string key)
{
    std::string cryptedText = text;
    for (int i = 0; i < text.length(); i++)
    {
        cryptedText[i] = text[i] ^ key[i % key.length()];
    }
    return cryptedText;
}