#ifndef VECTOR_H
#define VECTOR_H

namespace cjr {
    template<typename T>
    class vector {
    private:
        int m_size{ 0 };
        int m_capacity{ 0 };
        T* m_array = nullptr;

    public:
        vector(int capacity) : m_size(capacity), m_capacity(capacity) {
            m_array = new T[capacity];
            if (m_array) {
                std::cout << "vector was successfully allocated with capacity: " << m_capacity << std::endl;
            }
            this->initialize();
        }

        vector(void) {
            std::cout << "a simple vector was created" << std::endl;
        }

        ~vector() {
            this->deAllocate();
        }

        void initialize() {
            for (int ii = 0; ii < (int)this->m_size; ++ii) {
                m_array[ii] = 1;
            }
        }

        void print() {
            std::cout << "vector values are:" << std::endl;
            for (int ii = 0; ii < (int)this->m_size; ++ii) {
                std::cout << m_array[ii] << ' ';
            }
            std::cout << std::endl;
        }

        void reAllocate(int newCapacity) {
            T* m_temp_array = new T[newCapacity];

            if (newCapacity < m_size) { m_size = newCapacity; }
            
            for (int ii = 0; ii < (int)this->m_size; ++ii) {
                m_temp_array[ii] = std::move(this->m_array[ii]);
            }

            m_array = m_temp_array;
            m_capacity = newCapacity;
        }

        const T& operator[](int index) const {
            return m_array[index];
        }

        T& operator[](int index) {
            return m_array[index];
        }

        int Size() const { return m_size; }

        int Capacity() const { return m_capacity; }

        void push_back(const T& newItem) {
            if (m_size > m_capacity) {
                reAllocate(m_capacity + m_capacity / 2);
            }

            m_array[m_size] = newItem;
            ++m_size;
        }

        void deAllocate() {
            delete[] m_array;
            m_array = nullptr;
            if (!m_array) {
                std::cout << "vector was successfully deallocated!";
            }
        }
    };
};

#endif
