#ifndef DARRAY_H_GUARD
#define DARRAY_H_GUARD

namespace ds {

    template<typename ITEM> class DArray {

        public:

            DArray(size_t t_capacity=2) {
                assert(t_capacity >= 1);
                _size = 0;
                _capacity = t_capacity;
                items = new ITEM[_capacity];
            }

            ~DArray() {
                for(auto i=0; i<_size; i++)
                    items[i].~ITEM();
                delete [] items;
            }

            size_t size() { return _size; }

            size_t capacity() { return _capacity; }
            
            ITEM& operator[](size_t i) {
                assert ( i>=0 && i<_size);
                return items[i];
            }

            void append(ITEM const& item) {
                if (_size >= _capacity )
                    reallocate();
                new(&items[_size++])ITEM(item);
            }

            void insert(size_t index, ITEM const& item) {
                assert(index >= 0 && index < _size);
                if (_size >= _capacity)
                    reallocate();
                for(auto i=_size; i>index; --i) 
                    new(&items[i])ITEM(items[i-1]);
                new(&items[index])ITEM(item);
                ++_size;
            }

        private:
            static const int growth_rate = 2;
            enum{MIN_CAPACITY = 2};
            size_t _capacity;
            size_t _size;
            ITEM* items;

            void reallocate() {
                ITEM* old = items;
                _capacity = 2 * _capacity; 
                items = new ITEM[_capacity];
                for(auto i=0; i<_size; ++i)
                    new(&items[i])ITEM(old[i]);
                for(auto i=0; i<_size; ++i)
                    old[i].~ITEM();
                delete [] old;
            }
    };
}

#endif
