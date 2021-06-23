#pragma once
#include <string>

class IWritable
{
public:
    virtual void write() = 0;

    // write on console or in a file
    virtual std::string mode() const = 0;

    
};