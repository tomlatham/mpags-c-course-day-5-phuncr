
// Standard library includes
#include <string>
#include <algorithm>
#include <iostream>

// Out project headers
#include "Alphabet.hpp"
#include "VigenereCipher.hpp"

VigenereCipher::VigenereCipher( const std::string& key )
{
  // Set the given key
  setKey( key );
}

void VigenereCipher::setKey( const std::string& key )
{
  // Store the original key
  key_ = key;

  // Make sure the key is upper case
  std::transform( std::begin(key_), std::end(key_), std::begin(key_), ::toupper );

  // Remove non-alphabet characters
  key_.erase( std::remove_if( std::begin(key_), std::end(key_), [](char c){ return !std::isalpha(c); } ),
              std::end(key_) );

  // Check if the key is empty and replace with default if so
  if(key_.empty())
  { 
      key_="A";
      std::cout << "Key has been set to " << key_ << std::endl;
  }

  // loop over the key
  for(size_t i=0; i<key_.size(); i++)
  {
      // Find the letter position in the alphabet
      // Create a CaesarCipher using this position as a key
      CaesarCipher cipher { Alphabet::alphabet.find(key_[i]) };

      // Insert a std::pair of the letter and CaesarCipher into the lookup
      charLookup_.insert( std::make_pair(key_[i], cipher) );           
  }
}

std::string VigenereCipher::applyCipher( const std::string& inputText, 
const CipherMode cipherMode ) const
{
  // Create the output string, initially a copy of the input text
  std::string outputText {inputText};

  // For each letter in input
  for(size_t i=0; i<outputText.size(); i++)
  {
      // Find the corresponding letter in the key
      auto iter = charLookup_.find(key_[i%key_.size()]);
      std::string temp{outputText[i]};
      outputText[i] = ((*iter).second.applyCipher(temp, cipherMode))[0];
  }

  // Return the output text
  return outputText;
}
