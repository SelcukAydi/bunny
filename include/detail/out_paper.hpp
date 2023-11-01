#pragma once

#include "out_paper_interface.hpp"
#include "out_serializer.hpp"
#include <memory>
#include <unordered_map>

namespace bunny::detail
{
    class OutSerializer;

    // template<typename Derived>
    class OutPaper : public OutPaperInterface
    {
        std::unique_ptr<OutSerializer> m_out_serializer{ nullptr };
        std::ostream& m_stream;

    public:
        explicit OutPaper(std::ostream& stream) : m_stream(stream)
        {
            m_out_serializer = std::make_unique<OutSerializer>();
            m_stream << "bunny";
        }

        template <typename T>
        void save(const T& data, std::string& key, int id)
        {
            // Call the global save method.
            //
            std::cout << "OutPaper::save called\n";
            GlobalSave<T, typename ImplementationLevel<T>::type>::invoke(*this, data, key, id);
        }

        template <typename T>
        void saveObjectData(const std::unordered_map<int, T>& obj, std::string key, int id)
        {
            // This method will be called from out serializer.
            //
            std::cout << "OutPaper::saveObjectData called\n";
            key.append(".");
            key.append(std::to_string(id));
            // (static_cast<std::remove_const_t<T>>(obj)).serialize(*this, key);
            saveUnorderedMapData(obj, key, id);
        }

        template <typename T>
        void saveObjectData(T& obj, std::string key, int id)
        {
            // This method will be called from out serializer.
            //
            std::cout << "OutPaper::saveObjectData called\n";
            key.append(".");
            key.append(std::to_string(id));
            (static_cast<std::remove_const_t<T>>(obj)).serialize(*this, key);
        }

        template<typename T>
        void saveArrayData(ArrayWrapper<T>& data, std::string key, int id)
        {
            std::cout << "OutPaper::saveArrayData called\n";
            key.append(".");
            key.append(std::to_string(id) + "a");
            m_stream << "\n";
            m_stream << key << " " << data.count();

            auto count = 0;
            T* ptr = data.address();

            while (count < data.count())
            {
                // TODO: We need a meaningfull id for array elements. They must all have same base key
                // but different composite keys.
                //
                GlobalSave<T, typename ImplementationLevel<T>::type>::invoke(*this, *(ptr + count++), key, id);
            }
        }

        template<typename U>
        void saveUnorderedMapData(const std::unordered_map<int, U>& data, std::string key, int id)
        {
            std::cout << "OutPaper::saveUnorderedMapData called\n";
            key.append(".");
            key.append(std::to_string(id) + "um");
            m_stream << "\n";
            m_stream << key << " " << data.size();

            for(auto itr = data.begin(); itr != data.end(); ++itr)
            {
                GlobalSave<int, typename ImplementationLevel<int>::type>::invoke(*this, itr->first, key, id);
                GlobalSave<U, typename ImplementationLevel<U>::type>::invoke(*this, itr->second, key, id);
            }
        }

        template <typename T>
        void savePointerData(T* ptr)
        {
            // This method will be called from out serializer.
            //

            // throw exeption here.
            //
            std::cout << "OutPaper::savePointerData called\n";

            // Down cast to the most derived class.

            // Start the serialization process.
        }

        void savePrimitiveData(const std::string& data, std::string key, int id)
        {
            std::cout << "OutPaper::savePrimitiveData for string called\n";
            key.append(".");
            key.append(std::to_string(id));
            m_stream << "\n";
            m_stream << key << " " << data.size() << " " << data;
        }

        void savePrimitiveData(const int& data, std::string key, int id)
        {
            std::cout << "OutPaper::savePrimitiveData for int called\n";
            key.append(".");
            key.append(std::to_string(id));
            m_stream << "\n";
            m_stream << key << " " << data;
        }

        void savePrimitiveData(const unsigned int& data, std::string key, int id)
        {
            std::cout << "OutPaper::savePrimitiveData for unsigned int called\n";
            key.append(".");
            key.append(std::to_string(id));
            m_stream << "\n";
            m_stream << key << " " << data;
        }
    };
}