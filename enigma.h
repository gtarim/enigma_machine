#ifndef ENIGMA_H
#define ENIGMA_H

#include <iostream>
#include <cctype>
#include <array>

template <int rotorCount>
class Enigma
{
    std::array<std::string, 5> rotors
    {
	    "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
	    "AJDKSIRUXBLHWTMCQGZNPYFVOE",
	    "BDFHJLCPRTXVZNYEIWGAKMUSQO",
	    "ESOVPZJAYQUIRHXLNFTGKDCMWB",
	    "VZBRGITYUPSDNHLXAWMJQOFECK"  
    };
    std::array<uint8_t, 5> rotorPos {'A', 'A', 'A', 'A', 'A'};

    std::string reflector {"YRUHQSLDPXNGOKMIEBFZCWVJAT"};

public:
    Enigma() { };
    ~Enigma() = default;

    std::string run( std::string&& text )
    {
        std::string rval;
        for( auto chr : text )
            rval += crypt(chr);
        return rval;
    }
    
private:
    const uint8_t crypt (const uint8_t chr)
    {
        if( !std::isalpha(chr) )
            return 0;

        uint8_t data = std::toupper(chr);
        
        for (int index = 0; index < rotorCount; ++index)
        {
            ++rotorPos[0];
            if (rotorPos[0] > 'Z')
                rotorPos[0] -= 26;

            data = crypt (data, rotorPos[index], index);
        }

        data = reflect (data);

        for (int index = rotorCount; index > 0; --index)
        {
            ++rotorPos[index];
            if (rotorPos[index] > 'Z')
                rotorPos[index] -= 26;

            data = crypt (data, rotorPos[index], index);
        }

        return data;
    }

    uint8_t reflect (uint8_t data)
    {
        return reflector[data-'A'];
    }
    uint8_t crypt (uint8_t data, uint8_t val, int index)
    {
        data += val - 'A' ;
        if(data >= 26)
        {
            data -= 26;
        }
        return rotors[index][data];
    }
};

#endif // ENIGMA_H