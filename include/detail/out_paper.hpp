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
        std::unique_ptr<OutSerializer> m_out_serializer{nullptr};
        std::ostream &m_stream;

    public:
        explicit OutPaper(std::ostream &stream) : m_stream(stream)
        {
            m_out_serializer = std::make_unique<OutSerializer>();
            m_stream << "bunny";
        }

        template <typename T>
        void save(const T &data, std::string &key, int id)
        {
            // Call the global save method.
            //
            std::cout << "OutPaper::save called\n";
            GlobalSave<T, typename ImplementationLevel<std::remove_reference_t<T>>::type>::invoke(*this, data, key, id);
        }

        template <typename T>
        void saveObjectData(const std::unordered_map<int, T> &obj, std::string key, int id)
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
        void saveObjectData(std::shared_ptr<T> ptr, std::string key, int id)
        {
            // This method will be called from out serializer.
            //
            std::cout << "OutPaper::saveObjectData called\n";
            key.append(".");
            key.append(std::to_string(id));
            // (static_cast<std::remove_const_t<T>>(obj)).serialize(*this, key);
            saveSharedPointerData(ptr, key, id);
        }

        template <typename T>
        void saveObjectData(T &obj, std::string key, int id)
        {
            // This method will be called from out serializer.
            //
            std::cout << "OutPaper::saveObjectData called\n";
            key.append(".");
            key.append(std::to_string(id));
            (static_cast<std::remove_const_t<T>>(obj)).serialize(*this, key);
        }

        template <typename T>
        void saveArrayData(ArrayWrapper<T> &data, std::string key, int id)
        {
            std::cout << "OutPaper::saveArrayData called\n";
            key.append(".");
            key.append(std::to_string(id) + "a");
            m_stream << "\n";
            m_stream << key << " " << data.count();

            std::size_t count = 0;
            T *ptr = data.address();
            using ValT = std::remove_all_extents_t<std::remove_const_t<T>>;

            while (count < data.count())
            {
                // TODO: We need a meaningfull id for array elements. They must all have same base key
                // but different composite keys.
                //
                std::string tmp_key{key};
                tmp_key.append(".item.").append(std::to_string(count));
                GlobalSave<T, typename ImplementationLevel<ValT>::type>::invoke(*this, *(ptr + count++), tmp_key, id);
            }
        }

        template <typename U>
        void saveUnorderedMapData(const std::unordered_map<int, U> &data, std::string key, int id)
        {
            std::cout << "OutPaper::saveUnorderedMapData called\n";
            key.append(".");
            key.append(std::to_string(id) + "um");
            m_stream << "\n";
            m_stream << key << " " << data.size();
            std::size_t count = 0;

            for (auto itr = data.begin(); itr != data.end(); ++itr)
            {
                std::string tmp_key{key};
                tmp_key.append(".key.").append(std::to_string(count));

                std::string tmp_val{key};
                tmp_val.append(".val.").append(std::to_string(count));
                ++count;

                GlobalSave<int, typename ImplementationLevel<int>::type>::invoke(*this, itr->first, tmp_key, id);
                GlobalSave<U, typename ImplementationLevel<U>::type>::invoke(*this, itr->second, tmp_val, id);
            }
        }

        template <typename T>
        void saveSharedPointerData(const std::shared_ptr<T> &ptr, std::string key, int id)
        {
            std::cout << "OutPaper::saveSharedPointerData called\n";

            key.append(".");
            key.append(std::to_string(id));

            if (ptr.get() == nullptr)
            {
                m_stream << "\n";
                m_stream << key << " "
                         << "invalid";
                return;
            }

            m_stream << "\n";
            m_stream << key << " "
                     << "valid";

            // saveObjectData(*ptr, key, id);
            GlobalSave<T, typename ImplementationLevel<T>::type>::invoke(*this, *ptr, key, id);
        }

        template <typename T>
        void savePointerData(T *ptr)
        {
            // This method will be called from out serializer.
            //

            // throw exeption here.
            //
            std::cout << "OutPaper::savePointerData called\n";

            // Down cast to the most derived class.

            // Start the serialization process.
        }

        void savePrimitiveData(const std::string &data, std::string key, int id)
        {
            std::cout << "OutPaper::savePrimitiveData for string called\n";
            key.append(".");
            key.append(std::to_string(id));
            m_stream << "\n";
            m_stream << key << " " << data.size() << " " << data;
        }

        void savePrimitiveData(const int &data, std::string key, int id)
        {
            std::cout << "OutPaper::savePrimitiveData for int called\n";
            key.append(".");
            key.append(std::to_string(id));
            m_stream << "\n";
            m_stream << key << " " << data;
        }

        void savePrimitiveData(const unsigned int &data, std::string key, int id)
        {
            std::cout << "OutPaper::savePrimitiveData for unsigned int called\n";
            key.append(".");
            key.append(std::to_string(id));
            m_stream << "\n";
            m_stream << key << " " << data;
        }
    };
}