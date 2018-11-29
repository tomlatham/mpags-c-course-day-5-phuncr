#ifndef CIPHERFACTORY_HPP
#define CIPHERFACTORY_HPP

#include <memory>
#include "Cipher.hpp"
#include "CipherType.hpp"

/**
 * \file CipherFactory.hpp
 * \brief Contains the declaration of the factory function for creating Cipher objects
 */

/**
 * \brief Create a Cipher object of the concrete type specified, constructed from the supplied key
 *
 * \param type the concrete type of of cipher to be constructed
 * \param key the key with which to construct the cipher
 * \return the newly constructed cipher
 */
std::unique_ptr<Cipher> cipherFactory( const CipherType type,
                                       const std::string& key);

#endif // CIPHERFACTORY_HPP
