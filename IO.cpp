/* Dependencies */
#include "IO.h"

__IO__::__IO__()
{
    /* Empty */
}

__IO__::~__IO__()
{
    /* Empty */
}

uint8_t __IO__::setMode(volatile uint8_t* ddr, const uint8_t bit, const uint8_t mode)
{
    if (ddr == NULL)
        return (0);

    switch (mode)
    {
        case INPUT:
            *ddr = *ddr & ~(1 << bit);
            break;
        case OUTPUT:
            *ddr = *ddr | (1 << bit);
            break;
        default:
            break;
    }

    return (1);
}

uint8_t __IO__::setMode(volatile uint8_t* ddr, const uint8_t mode)
{
    if (ddr == NULL)
        return (0);

    *ddr = mode;
}

uint8_t __IO__::write(volatile uint8_t* dor, const uint8_t bit, const uint8_t state)
{
    if (dor == NULL)
        return (0);

    switch (state)
    {
        case LOW:
            *dor = *dor & ~(1 << bit);
            break;
        case HIGH:
            *dor = *dor | (1 << bit);
            break;
        case TOGGLE:
            *dor = *dor ^ (1 << bit);
            break;
        default:
            break;
    }

    return (1);
}

uint8_t __IO__::write(volatile uint8_t* dor, const uint8_t state)
{
    if (dor == NULL)
        return (0);

    *dor = state;
}

uint8_t __IO__::read(volatile uint8_t* dir, const uint8_t bit)
{
    if (dir == NULL)
        return (0);

    return ((*dir >> bit) & 1);
}

uint8_t __IO__::read(volatile uint8_t* dir)
{
    if (dir == NULL)
        return (0);

    return (*dir);
}

__IO__ IO = __IO__();
