#pragma once

#include <cstdint>
#include <memory>

namespace PddBy
{

// Some early TrashCart PRNG implementation (v0.1), as found on torry.net
// http://www.torry.net/apps/security/passwords/trashcartprng.zip
// Latest version at http://amsoftware.narod.ru/ looks a bit different
// (c) 2008 Alexander Myasnikov

// ** TCCartman.Pas by Alexander Myasnikov
// ** Fixed Cartman Tiny block cipher 1.1mk for TrashCart PRNG
// ** Cartman encrypts 128 bit block with 256..1024 bit key
// ** Gives much better transforming with new key schedule
// ** Freeware for any use, non-patented, opensource cipher

// ** TrashCart.Pas by Alexander Myasnikov
// ** TrashCart PRNG based on Cartman block cipher
// ** Freeware for any use, non-patented, opensource cipher

class TrashCartPrngRandom
{
    typedef std::uint32_t KeyStreamType[4];

    class Impl;

public:
    TrashCartPrngRandom(std::uint32_t seed);
    ~TrashCartPrngRandom();

    std::uint8_t GetNext();

private:
    std::unique_ptr<Impl> m_impl;
    KeyStreamType m_keyStream;
};

} // namespace PddBy
