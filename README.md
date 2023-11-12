**Table of Contents**

[TOCM]

[TOC]

# Bunny Serialization Library
Bunny is a header only, fast and easy-use seriliazation library that supports field taggin hence backward compatibility is totally supported in a compile-time safe manner. Bunny has a boost-like code style and its usage is very similar to boost serialization library. Most of the features provided in boost are implemented in Bunny with a modern approach and design.

## Current Features and TODOs
1. Bunny does not prevent loops in the serialization chain. This will be implemented in the next releases.
2. Object tracking feature is not implemented.
3. Virtual inheritance is not supported in the current version. We have a plan to provide this unique ability soon.
4. Not all containers and types are supported in the standart library. However, almost all of them will be supported in the upcoming releases.

### Supported Types
Bunny currently or will support the below list. In addition to that, all the user-defined class types are supported as ususal.
#### Primitive Types
- char
- signed char
- unsigned char
- unsigned short int
- signed short int
- signed int
- unsigned int
- long unsigned int
- long signed int
- std::string (counted as primitive)
- raw pointers
#### Containers and Standart Types
- C-style arrays
- std::vector
- std::list
- std::array
- std::unordered_map
- std::map
- std::unordered_set (next release)
- std::set (next release)
- std::shared_ptr
- std::unique_ptr (next release)

## How To Use
```cpp
#include "ComposerPaper.hpp"
#include "DecomposerPaper.hpp"
#include <string>
#include <UnorderedMap.hpp> // Bunny support header for this type.

using bunny::FieldTag;

struct PlainClass
{
    std::string m_name;
    std::unordered_map<int, std::string> m_map;

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper(m_name, key, FieldTag{1});
        paper(m_map, key, FieldTag{2});
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "")
    {
        paper(m_name, key, FieldTag{1});
        paper(m_map, key, FieldTag{2});
    }
};

struct ComplexTestClass
{
    unsigned int m_id{};
    int m_count{};
    std::string m_name;
    std::unordered_map<int, std::unordered_map<int, int>> m_int_map;
    std::unordered_map<int, std::unordered_map<int, PlainClass>> m_plain_map[3];

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper(m_id, key, FieldTag{1});
        paper(m_name, key, FieldTag{2});
        paper(m_count, key, FieldTag{3});
        paper(m_int_map, key, FieldTag{4});
        paper(m_plain_map, key, FieldTag{5});
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "")
    {
        paper(m_id, key, FieldTag{1});
        paper(m_name, key, FieldTag{2});
        paper(m_count, key, FieldTag{3});
        paper(m_int_map, key, FieldTag{4});
        paper(m_plain_map, key, FieldTag{5});
    }
};

int main()
{
	std::stringstream ss;
    bunny::ComposerPaper composer{ss};

    ComplexTestClass out_obj;
    
    PlainClass plain1;
    plain1.m_name = "plain1";
    plain1.m_map.insert({1, "left"});
    plain1.m_map.insert({2, "right"});
    plain1.m_map.insert({3, "forward"});
    plain1.m_map.insert({4, "backward"});

    PlainClass plain2;
    plain2.m_name = "plain2";
    plain2.m_map.insert({10, "left10"});
    plain2.m_map.insert({20, "right20"});
    plain2.m_map.insert({30, "forward30"});
    plain2.m_map.insert({40, "backward40"});

    std::unordered_map<int, PlainClass> map1;
    map1.insert({100, plain1});
    map1.insert({200, plain2});

    PlainClass plain3;
    plain3.m_name = "plain3";
    plain3.m_map.insert({11, "left"});
    plain3.m_map.insert({21, "right"});
    plain3.m_map.insert({31, "forward"});
    plain3.m_map.insert({41, "backward"});

    PlainClass plain4;
    plain4.m_name = "plain4";
    plain4.m_map.insert({105, "left10"});
    plain4.m_map.insert({205, "right20"});
    plain4.m_map.insert({305, "forward30"});
    plain4.m_map.insert({405, "backward40"});

    std::unordered_map<int, PlainClass> map2;
    map2.insert({100, plain3});
    map2.insert({200, plain4});

    out_obj.m_plain_map[0].insert({888, map1});
    out_obj.m_plain_map[2].insert({999, map2});

    out_obj.m_count = 7070;
    out_obj.m_id = 2323;
    
    std::unordered_map<int, int> map_int1;
    map_int1.insert({1, 10});

    std::unordered_map<int, int> map_int2;
    map_int2.insert({2, 20});

    out_obj.m_int_map.insert({7979, map_int1});
    out_obj.m_int_map.insert({9090, map_int2});

    composer << out_obj;

    bunny::DecomposerPaper decomposer{ss};
    ComplexTestClass in_obj;
    decomposer >> in_obj;
   
    return 0;
}
```