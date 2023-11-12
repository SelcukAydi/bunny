#pragma once

#include "in_serializer.hpp"
#include <istream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <memory>

namespace bunny::detail
{
    class InPaper
    {
    public:
        explicit InPaper(std::istream &stream) : m_stream(stream)
        {
            std::string input_key;
            m_stream >> input_key;

            parse();
        }

        template <typename T>
        void load(T &data, std::string &key, int id, std::size_t index = 0)
        {
            // Call the global load method.
            //
            std::cout << "InPaper::load called\n";
            GlobalLoad<T, typename ImplementationLevel<T>::type>::invoke(*this, data, key, id, index);
        }

        void loadPrimitiveData(int &data, std::string key, int id, std::size_t index = 0)
        {
            index = 0;
            key.append(".");
            key.append(std::to_string(id));

            auto itr = m_data.find(key);

            if (itr == m_data.end())
            {
                std::cerr << "Could not find the key: " << key << '\n';
                return;
            }

            if (index >= itr->second.size())
            {
                std::cerr << "ERROR: loadPrimitiveData int\n";
                return;
            }

            std::istringstream input_stream{itr->second[index]};

            input_stream.get();
            input_stream >> data;

            if (input_stream.fail())
            {
                std::cerr << "Input stream error: Could not load integer data!\n";
                return;
            }
        }

        void loadPrimitiveData(unsigned int &data, std::string key, int id, std::size_t index = 0)
        {
            index = 0;
            key.append(".");
            key.append(std::to_string(id));

            auto itr = m_data.find(key);

            if (itr == m_data.end())
            {
                std::cerr << "Could not find the key: " << key << '\n';
                return;
            }

            if (index >= itr->second.size())
            {
                std::cerr << "ERROR: loadPrimitiveData unsigned int\n";
                return;
            }

            std::istringstream input_stream{itr->second[index]};

            input_stream.get();
            input_stream >> data;

            if (input_stream.fail())
            {
                std::cerr << "Input stream error: Could not load unsigned integer data!\n";
                return;
            }
        }

        void loadPrimitiveData(std::string &data, std::string key, int id, std::size_t index = 0)
        {
            index = 0;
            key.append(".");
            key.append(std::to_string(id));

            auto itr = m_data.find(key);

            if (itr == m_data.end())
            {
                std::cerr << "Could not find the key: " << key << '\n';
                return;
            }

            if (index >= itr->second.size())
            {
                std::cerr << "ERROR: loadPrimitiveData string\n";
                return;
            }

            std::istringstream input_stream{itr->second[index]};

            input_stream.get();
            int size;
            input_stream >> size;
            // input_stream >> data;

            input_stream.get();

            char tmp[size + 1];
            input_stream.readsome(tmp, size);
            tmp[size] = '\0';
            data.assign(tmp);

            if (input_stream.fail())
            {
                std::cerr << "Input stream error: Could not load string data!\n";
                return;
            }
        }

        template <typename T>
        void loadArrayData(ArrayWrapper<T> &data, std::string key, int id, std::size_t index = 0)
        {
            index = 0;
            key.append(".");
            key.append(std::to_string(id) + "a");

            auto itr = m_data.find(key);

            if (itr == m_data.end())
            {
                std::cerr << "Could not find the key: " << key << '\n';
                return;
            }

            if (index >= itr->second.size())
            {
                std::cerr << "ERROR: loadPrimitiveData array data\n";
                return;
            }

            std::istringstream input_stream{itr->second[index]};
            input_stream.get();
            std::size_t size;
            input_stream >> size;

            auto ptr = data.address();

            for (std::size_t i = 0; i < size; ++i)
            {
                std::string tmp_key{key};
                tmp_key.append(".item.").append(std::to_string(i));
                GlobalLoad<T, typename ImplementationLevel<T>::type>::invoke(*this, *(ptr + i), tmp_key, id, (index * size) + i);
            }
        }

        template <typename U>
        void loadUnorderedMapData(std::unordered_map<int, U> &data, std::string key, int id, std::size_t index = 0)
        {
            index = 0;
            key.append(".");
            key.append(std::to_string(id) + "um");

            auto itr = m_data.find(key);

            if (itr == m_data.end())
            {
                std::cerr << "Could not find the key: " << key << '\n';
                return;
            }

            if (index >= itr->second.size())
            {
                std::cerr << "ERROR: loadPrimitiveData map\n";
                return;
            }

            std::istringstream input_stream{itr->second[index]};
            input_stream.get();
            std::size_t size;
            input_stream >> size;

            for (std::size_t i = 0; i < size; ++i)
            {
                int entry_key{};
                U entry_data{};
                std::string tmp_key{key};
                tmp_key.append(".key.").append(std::to_string(i));

                std::string tmp_val{key};
                tmp_val.append(".val.").append(std::to_string(i));

                GlobalLoad<int, typename ImplementationLevel<int>::type>::invoke(*this, entry_key, tmp_key, id, (index * size) + i);
                GlobalLoad<U, typename ImplementationLevel<U>::type>::invoke(*this, entry_data, tmp_val, id, (index * size) + i);
                data[entry_key] = entry_data;
            }
        }

        template <typename U>
        void loadSharedPtrData(std::shared_ptr<U> &data, std::string key, int id, std::size_t index = 0)
        {
            index = 0;
            key.append(".");
            key.append(std::to_string(id));

            auto itr = m_data.find(key);

            if (itr == m_data.end())
            {
                std::cerr << "Could not find the key: " << key << '\n';
                return;
            }

            std::istringstream input_stream{itr->second[index]};
            input_stream.get();

            std::string is_valid;
            input_stream >> is_valid;

            if (is_valid == "invalid")
            {
                data.reset();
                return;
            }

            U *obj = new U{};
            // loadObjectData(*obj, key, id, index);
            GlobalLoad<U, typename ImplementationLevel<U>::type>::invoke(*this, *obj, key, id, index);

            // TODO: If this object is not available in the
            // paper then we need to set pointer to nullptr.
            //

            data.reset(obj);
        }

        template <typename T>
        void loadVectorData(std::vector<T> &data, std::string key, int id, std::size_t index = 0)
        {
            index = 0;
            key.append(".");
            key.append(std::to_string(id));

            auto itr = m_data.find(key);

            if (itr == m_data.end())
            {
                std::cerr << "Could not find the key: " << key << '\n';
                return;
            }

            if (index >= itr->second.size())
            {
                std::cerr << "ERROR: loadPrimitiveData array data\n";
                return;
            }

            std::istringstream input_stream{itr->second[index]};
            input_stream.get();
            std::size_t size;
            input_stream >> size;

            for (std::size_t i = 0; i < size; ++i)
            {
                std::string tmp_key{key};
                tmp_key.append(".item.").append(std::to_string(i));
                T obj;
                GlobalLoad<T, typename ImplementationLevel<T>::type>::invoke(*this, obj, tmp_key, id, (index * size) + i);
                data.push_back(obj);
            }
        }

        template <typename T>
        void loadObjectData(std::unordered_map<int, T> &obj, std::string key, int id, std::size_t index = 0)
        {
            // This method will be called from out serializer.
            //
            key.append(".");
            key.append(std::to_string(id));
            // (static_cast<std::remove_const_t<T>>(obj)).serialize(*this, key);
            loadUnorderedMapData(obj, key, id, index);
        }

        template <typename T>
        void loadObjectData(std::shared_ptr<T> &obj, std::string key, int id, std::size_t index = 0)
        {
            // This method will be called from out serializer.
            //
            key.append(".");
            key.append(std::to_string(id));
            // (static_cast<std::remove_const_t<T>>(obj)).serialize(*this, key);
            loadSharedPtrData(obj, key, id, index);
        }

        template <typename T>
        void loadObjectData(std::vector<T> &obj, std::string key, int id, std::size_t index = 0)
        {
            // This method will be called from out serializer.
            //
            key.append(".");
            key.append(std::to_string(id));
            // (static_cast<std::remove_const_t<T>>(obj)).serialize(*this, key);
            loadVectorData(obj, key, id, index);
        }

        template <typename T>
        void loadObjectData(T &t, std::string key, int id, std::size_t index = 0)
        {
            key.append(".");
            key.append(std::to_string(id));
            t.deserialize(*this, key, index);
        }

    private:
        void parse()
        {
            while (!m_stream.eof())
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

        std::istream &m_stream;
        std::unordered_map<std::string, std::vector<std::string>> m_data;
    };
}