#pragma once

#include "in_serializer.hpp"
#include <istream>
#include <unordered_map>
#include <vector>

namespace bunny::detail
{
    class InPaper
    {
    public:
        explicit InPaper(std::istream& stream) : m_stream(stream)
        {
            std::string input_key;
            m_stream >> input_key;

            parse();
        }

        template <typename T>
        void load(T& data, std::string& key, int id)
        {
            // Call the global load method.
            //
            std::cout << "InPaper::load called\n";
            GlobalLoad<T, typename ImplementationLevel<T>::type>::invoke(*this, data, key, id);
        }

        void loadPrimitiveData(int& data, std::string key, int id)
        {
            key.append(".");
            key.append(std::to_string(id));

            auto itr = m_data.find(key);

            if (itr == m_data.end())
            {
                std::cerr << "Could not find the key: " << key << '\n';
                return;
            }

            std::istringstream input_stream{ itr->second[0] };

            input_stream.get();
            input_stream >> data;

            if (input_stream.fail())
            {
                std::cerr << "Input stream error: Could not load integer data!\n";
                return;
            }
        }

        void loadPrimitiveData(unsigned int& data, std::string key, int id)
        {
            key.append(".");
            key.append(std::to_string(id));

            auto itr = m_data.find(key);

            if (itr == m_data.end())
            {
                std::cerr << "Could not find the key: " << key << '\n';
                return;
            }

            std::istringstream input_stream{ itr->second[0] };

            input_stream.get();
            input_stream >> data;

            if (input_stream.fail())
            {
                std::cerr << "Input stream error: Could not load integer data!\n";
                return;
            }
        }

        void loadPrimitiveData(std::string& data, std::string key, int id)
        {
            key.append(".");
            key.append(std::to_string(id));

            auto itr = m_data.find(key);

            if (itr == m_data.end())
            {
                std::cerr << "Could not find the key: " << key << '\n';
                return;
            }

            std::istringstream input_stream{ itr->second[0] };

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

        template<typename T>
        void loadArrayData(ArrayWrapper<T>& data, std::string key, int id)
        {

        }

        template <typename T>
        void loadObjectData(T& t, std::string key, int id)
        {
            key.append(".");
            key.append(std::to_string(id));
            t.deserialize(*this, key);
        }

    private:
        void parse()
        {
            while (m_stream)
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

                // m_data.insert({ input_key, input_data });
                m_data[input_key].push_back(input_data);
            }
        }

        std::istream& m_stream;
        std::unordered_map<std::string, std::vector<std::string>> m_data;
    };
}