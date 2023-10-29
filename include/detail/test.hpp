#include <iostream>
#include <sstream>
#include <unordered_map>
#include <ostream>

struct Serializer
{
    explicit Serializer(std::ostream& stream)
    {
        m_out_stream = &stream;
        *m_out_stream << "serialization";
    }

    void save(int data, std::string key, int id)
    {
        key.append(".");
        key.append(std::to_string(id));

        *m_out_stream << "\n";
        *m_out_stream << key << " " << data;
    }

    void save(std::string& data, std::string key, int id)
    {
        key.append(".");
        key.append(std::to_string(id));

        *m_out_stream << "\n";
        *m_out_stream << key << " " << data.size() << " " << data;
    }

    template <typename T>
    void save(T& t, std::string key, int id)
    {
        key.append(".");
        key.append(std::to_string(id));
        t.serialize(this, key);
    }

    // private:
    std::ostream* m_out_stream;
};

struct Deserializer
{
    explicit Deserializer(std::istream& stream) : m_stream{ stream }
    {
        std::string input_key;
        m_stream >> input_key;

        parse();
    }

    void parse()
    {
        while (true)
        {
            std::string input_key;
            m_stream >> input_key;

            if (m_stream.fail())
            {
                std::cerr << "Input stream error: Could not load key!\n";
                return;
            }

            std::string input_data;
            std::getline(m_stream, input_data, '\n');

            if (m_stream.fail())
            {
                std::cerr << "Input stream error: Could not load data with key: " << input_key << '\n';
                return;
            }

            m_data.insert({ input_key, input_data });
        }
    }

    void load(int& data, std::string key, int id)
    {
        key.append(".");
        key.append(std::to_string(id));

        auto itr = m_data.find(key);

        if (itr == m_data.end())
        {
            std::cerr << "Could not find the key: " << key << '\n';
            return;
        }

        std::istringstream input_stream{ itr->second };

        input_stream.get();
        input_stream >> data;

        if (input_stream.fail())
        {
            std::cerr << "Input stream error: Could not load integer data!\n";
            return;
        }
    }

    void load(std::string& data, std::string key, int id)
    {
        key.append(".");
        key.append(std::to_string(id));

        auto itr = m_data.find(key);

        if (itr == m_data.end())
        {
            std::cerr << "Could not find the key: " << key << '\n';
            return;
        }

        std::istringstream input_stream{ itr->second };

        input_stream.get();
        int size;
        input_stream >> size;
        input_stream >> data;

        if (input_stream.fail())
        {
            std::cerr << "Input stream error: Could not load integer data!\n";
            return;
        }
    }

    template <typename T>
    void load(T& t, std::string key, int id)
    {
        key.append(".");
        key.append(std::to_string(id));
        t.deserialize(this, key);
    }

    std::istream& m_stream;
    std::unordered_map<std::string, std::string> m_data;
};

struct Developer
{
    void serialize(Serializer* serializer, std::string key = "")
    {
        serializer->save(m_score, key, 1);
        serializer->save(m_name, key, 5);
    }

    void deserialize(Deserializer* deserializer, std::string key = "")
    {
        deserializer->load(m_score, key, 1);
        deserializer->load(m_name, key, 5);
    }

    friend std::ostream& operator<<(std::ostream& os, const Developer& dt);

    int m_score{ 100 };
    std::string m_name{ "sia" };
};

std::ostream& operator<<(std::ostream& os, const Developer& data)
{
    os << "Name:" << data.m_name << ' ' << "Score:" << data.m_score;
    return os;
}

struct Manager
{
    void serialize(Serializer* serializer, std::string key = "")
    {
        serializer->save(m_number, key, 1);
        serializer->save(m_size, key, 2);
        serializer->save(m_developer, key, 3);
        serializer->save(m_type, key, 4);
    }

    void deserialize(Deserializer* deserializer, std::string key = "")
    {
        deserializer->load(m_number, key, 1);
        deserializer->load(m_size, key, 2);
        deserializer->load(m_type, key, 4);
        deserializer->load(m_developer, key, 3);
    }

    friend std::ostream& operator<<(std::ostream& os, const Manager& dt);

    int m_number{ 123 };
    int m_size{ 543545 };
    std::string m_type{ "notype" };
    Developer m_developer;
};

std::ostream& operator<<(std::ostream& os, const Manager& data)
{
    os << "Number:" << data.m_number << ' ' << "Size:" << data.m_size << ' ' << "Type:" << data.m_type << ' ' << "Developer:" << data.m_developer;
    return os;
}

// int main()
// {
//     std::stringstream stream;
//     Serializer serializer(stream);

//     Manager manager;
//     manager.m_type = "extension";
//     manager.serialize(&serializer);

//     std::cout << stream.str() << '\n';

//     std::cout << "Before deserialization:\n";
//     std::cout << manager << '\n';

//     Deserializer deserializer(stream);

//     Manager manager1;
//     manager1.m_number = 9090909;
//     manager1.deserialize(&deserializer);

//     std::cout << "After deserialization:\n";
//     std::cout << manager1 << '\n';

//     return 0;
// }