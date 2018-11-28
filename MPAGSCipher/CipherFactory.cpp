#include <memory>
#include "CipherFactory.hpp"
#include "PlayfairCipher.hpp"
#include "CaesarCipher.hpp"
#include "VigenereCipher.hpp"

std::unique_ptr<Cipher> cipherFactory( const CipherType type,
                                       std::string const key )
{
  switch (type)
  {
    case CipherType::Caesar :
      return std::make_unique<CaesarCipher>( key );
      break;

    case CipherType::Playfair :
      return std::make_unique<PlayfairCipher>( key );
      break;

    case CipherType::Vigenere :
      return std::make_unique<VigenereCipher>( key );
      break;

    default:
      return(NULL);
      break;
  }
}
