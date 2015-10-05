

#ifndef WASMINT_FLOAT64_H
#define WASMINT_FLOAT64_H


#include <types/Type.h>
#include <Variable.h>

class Float64 : public Type {

protected:
    Float64() {
    }


public:
    static Float64* instance() {
        static Float64 instance;
        return &instance;
    }


    virtual std::string name() {
        return "float64";
    }

    virtual void parse(ByteStream& stream, void* data, std::size_t dataLength) {
        ((uint8_t*) data)[0] = stream.popChar();
        ((uint8_t*) data)[1] = stream.popChar();
        ((uint8_t*) data)[2] = stream.popChar();
        ((uint8_t*) data)[3] = stream.popChar();
        ((uint8_t*) data)[4] = stream.popChar();
        ((uint8_t*) data)[5] = stream.popChar();
        ((uint8_t*) data)[6] = stream.popChar();
        ((uint8_t*) data)[7] = stream.popChar();
    }

    static double getValue(Variable variable) {
        if (variable.type() == *instance()) {
            double result = 0;
            double* data = (double*) variable.value();
            result = *data;
            return result;
        } else {
            throw IncompatibleType();
        }
    }

    static void setValue(Variable variable, double value) {
        if (variable.type() == *instance()) {
            double* data = (double*) variable.value();
            (*data) = value;
        } else {
            throw IncompatibleType();
        }
    }

    virtual std::size_t size() {
        return 8;
    }
};


#endif //WASMINT_FLOAT64_H