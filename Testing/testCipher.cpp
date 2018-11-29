//! Unit Tests for MPAGSCipher Cipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector>
#include <memory>
#include <iostream>
#include <fstream>

#include "PlayfairCipher.hpp"
#include "CaesarCipher.hpp"
#include "VigenereCipher.hpp"
#include "CipherFactory.hpp"
#include "CipherMode.hpp"
#include "CipherType.hpp"

bool testCipher( std::unique_ptr<Cipher>& cipher, const CipherMode mode, 
                const std::string& inputText, const std::string& outputText)
{
    if(cipher->applyCipher(inputText, mode) == outputText) { return(true); }
    else { return(false); }
}

TEST_CASE("Cipher encryption", "[encrypt]")
{
  std::vector<std::unique_ptr<Cipher>> inventory;
  inventory.push_back( cipherFactory( CipherType::Caesar, "10" ) );
  inventory.push_back( cipherFactory( CipherType::Playfair, "hello" ) );
  inventory.push_back( cipherFactory( CipherType::Vigenere, "key" ) );

  std::vector<std::string> inputText;    
  inputText.push_back("HELLOWORLD");
  inputText.push_back("BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING");
  inputText.push_back("HELLOWORLD");

  std::vector<std::string> outputText;
  outputText.push_back("ROVVYGYBVN"); 
  outputText.push_back("FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA");
  outputText.push_back("RIJVSUYVJN");

  for ( size_t i=0; i<inventory.size(); i++ )
  {  
    REQUIRE( testCipher(inventory[i], CipherMode::Encrypt, inputText[i], outputText[i]));
  }
}

TEST_CASE("Cipher decryption", "[decrypt]")
{
  std::vector<std::unique_ptr<Cipher>> inventory;
  inventory.push_back( cipherFactory( CipherType::Caesar, "10" ) );
  inventory.push_back( cipherFactory( CipherType::Playfair, "hello" ) );
  inventory.push_back( cipherFactory( CipherType::Vigenere, "key" ) );

  std::vector<std::string> inputText;
  inputText.push_back("ROVVYGYBVN");
  inputText.push_back("FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA");
  inputText.push_back("RIJVSUYVJN");

  std::vector<std::string> outputText;
  outputText.push_back("HELLOWORLD");
  outputText.push_back("BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ");
  outputText.push_back("HELLOWORLD");

  for ( size_t i=0; i<inventory.size(); i++ )
  {  
    REQUIRE( testCipher(inventory[i], CipherMode::Decrypt, inputText[i], outputText[i]));
  }
}

