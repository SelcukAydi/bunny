#pragma once

#include <cstdint>

namespace bunny::detail
{
    enum class SerializationLevel : std::uint8_t
    {
        kDoNotSerialize = 0,
        kPrimitive,
        kObject,
        kPointer,
        kArray
    };
}